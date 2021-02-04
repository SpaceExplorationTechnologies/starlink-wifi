######################################################################
# Copyright (c) 2017, 2019, The Linux Foundation. All rights reserved.
#
# This program is free software; you can redistribute it and/or modify
# it under the terms of the GNU General Public License version 2 and
# only version 2 as published by the Free Software Foundation.
#
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#####################################################################

"""
Script to create a U-Boot flashable multi-image blob.

This script creates a multi-image blob, from a bunch of images, and
adds a U-Boot shell script to the blob, that can flash the images from
within U-Boot. The procedure to use this script is listed below.

  1. Create an images folder. Ex: my-pack

  2. Copy all the images to be flashed into the folder.

  3. Copy the partition MBN file into the folder. The file should be
     named 'partition.mbn'. This is used to determine the offsets for
     each of the named partitions.

  4. Create a flash configuration file, specifying the images be
     flashed, and the partition in which the images is to be
     flashed. The flash configuration file can be specified using the
     -f option, default is flash.conf.

  5. Invoke 'pack' with the folder name as argument, pass flash
     parameters as arguments if required. A single image file will
     be created, out side the images folder, with .img suffix. Ex:
     my-pack.img

  6. Transfer the file into a valid SDRAM address and invoke the
     following U-Boot command to flash the images. Replace 0x41000000,
     with address location where the image has been loaded. The script
     expects the variable 'imgaddr' to be set.

     u-boot> imgaddr=0x88000000 source $imgaddr:script

Host-side Pre-req

  * Python >= 2.6
  * ordereddict >= 1.1 (for Python 2.6)
  * mkimage >= 2012.07
  * dtc >= 1.2.0

Target-side Pre-req

The following U-Boot config macros should be enabled, for the
generated flashing script to work.

  * CONFIG_FIT -- FIT image format support
  * CONFIG_SYS_HUSH_PARSER -- bash style scripting support
  * CONFIG_SYS_NULLDEV -- redirecting command output support
  * CONFIG_CMD_XIMG -- extracting sub-images support
  * CONFIG_CMD_NAND -- NAND Flash commands support
  * CONFIG_CMD_NAND_YAFFS -- NAND YAFFS2 write support
  * CONFIG_CMD_SF -- SPI Flash commands support
"""

from os.path import getsize
from getopt import getopt
from getopt import GetoptError
from collections import namedtuple
from string import Template
from shutil import copy
from shutil import rmtree

import os
import sys
import os.path
import subprocess
import struct
import hashlib
import xml.etree.ElementTree as ET

version = "1.1"
ARCH_NAME = ""
SRC_DIR = ""
MODE = ""
image_type = "all"
memory_size = "default"
lk = "false"

#
# Python 2.6 and earlier did not have OrderedDict use the backport
# from ordereddict package. If that is not available report error.
#
try:
    from collections import OrderedDict
except ImportError:
    try:
        from ordereddict import OrderedDict
    except ImportError:
        print "error: this script requires the 'ordereddict' class."
        print "Try 'pip install --user ordereddict'"
        print "Or  'easy_install --user ordereddict'"
        sys.exit(1)

def error(msg, ex=None):
    """Print an error message and exit.

    msg -- string, the message to print
    ex -- exception, the associate exception, if any
    """

    sys.stderr.write("pack: %s" % msg)
    if ex != None: sys.stderr.write(": %s" % str(ex))
    sys.stderr.write("\n")
    sys.exit(1)

FlashInfo = namedtuple("FlashInfo", "type pagesize blocksize chipsize")
ImageInfo = namedtuple("ProgInfo", "name filename type")
PartInfo = namedtuple("PartInfo", "name offset length which_flash")

def roundup(value, roundto):
    """Return the next largest multiple of 'roundto'."""

    return ((value + roundto - 1) // roundto) * roundto

class GPT(object):
    GPTheader = namedtuple("GPTheader", "signature revision header_size"
                            " crc32 current_lba backup_lba first_usable_lba"
                            " last_usable_lba disk_guid start_lba_part_entry"
                            " num_part_entry part_entry_size part_crc32")
    GPT_SIGNATURE = 'EFI PART'
    GPT_REVISION = '\x00\x00\x01\x00'
    GPT_HEADER_SIZE = 0x5C
    GPT_HEADER_FMT = "<8s4sLL4xQQQQ16sQLLL"

    GPTtable = namedtuple("GPTtable", "part_type unique_guid first_lba"
                           " last_lba attribute_flag part_name")
    GPT_TABLE_FMT = "<16s16sQQQ72s"

    def __init__(self, filename, pagesize, blocksize, chipsize):
        self.filename = filename
        self.pagesize = pagesize
        self.blocksize = blocksize
        self.chipsize = chipsize
        self.__partitions = OrderedDict()

    def __validate_and_read_parts(self, part_fp):
        """Validate the GPT and read the partition"""
        part_fp.seek(self.blocksize, os.SEEK_SET)
        gptheader_str = part_fp.read(struct.calcsize(GPT.GPT_HEADER_FMT))
        gptheader = struct.unpack(GPT.GPT_HEADER_FMT, gptheader_str)
        gptheader = GPT.GPTheader._make(gptheader)

        if gptheader.signature != GPT.GPT_SIGNATURE:
            error("Invalid signature")

        if gptheader.revision != GPT.GPT_REVISION:
            error("Unsupported GPT Revision")

        if gptheader.header_size != GPT.GPT_HEADER_SIZE:
            error("Invalid Header size")

        # Adding GPT partition info. This has to be flashed first.
        # GPT Header starts at LBA1 so (current_lba -1) will give the
        # starting of primary GPT.
        # blocksize will equal to gptheader.first_usuable_lba - current_lba + 1

        name = "0:GPT"
        block_start = gptheader.current_lba - 1
        block_count = gptheader.first_usable_lba - gptheader.current_lba + 1
        which_flash = 0
        part_info = PartInfo(name, block_start, block_count, which_flash)
        self.__partitions[name] = part_info

        part_fp.seek(2 * self.blocksize, os.SEEK_SET)

        for i in range(gptheader.num_part_entry):
            gpt_table_str = part_fp.read(struct.calcsize(GPT.GPT_TABLE_FMT))
            gpt_table = struct.unpack(GPT.GPT_TABLE_FMT, gpt_table_str)
            gpt_table = GPT.GPTtable._make(gpt_table)

            block_start = gpt_table.first_lba
            block_count = gpt_table.last_lba - gpt_table.first_lba + 1

            part_name = gpt_table.part_name.strip(chr(0))
            name = part_name.replace('\0','')
            part_info = PartInfo(name, block_start, block_count, which_flash)
            self.__partitions[name] = part_info

        # Adding the GPT Backup partition.
        # GPT header backup_lba gives block number where the GPT backup header will be.
        # GPT Backup header will start from offset of 32 blocks before
        # the GPTheader.backup_lba. Backup GPT size is 33 blocks.
        name = "0:GPTBACKUP"
        block_start = gptheader.backup_lba - 32
        block_count = 33
        part_info = PartInfo(name, block_start, block_count, which_flash)
        self.__partitions[name] = part_info

    def get_parts(self):
        """Returns a list of partitions present in the GPT."""

        try:
            with open(self.filename, "r") as part_fp:
                self.__validate_and_read_parts(part_fp)
        except IOError, e:
            error("error opening %s" % self.filename, e)

        return self.__partitions

class MIBIB(object):
    Header = namedtuple("Header", "magic1 magic2 version age")
    HEADER_FMT = "<LLLL"
    HEADER_MAGIC1 = 0xFE569FAC
    HEADER_MAGIC2 = 0xCD7F127A
    HEADER_VERSION = 4

    Table = namedtuple("Table", "magic1 magic2 version numparts")
    TABLE_FMT = "<LLLL"
    TABLE_MAGIC1 = 0x55EE73AA
    TABLE_MAGIC2 = 0xE35EBDDB
    TABLE_VERSION_IPQ806X = 3
    TABLE_VERSION_OTHERS = 4


    Entry = namedtuple("Entry", "name offset length"
                        " attr1 attr2 attr3 which_flash")
    ENTRY_FMT = "<16sLLBBBB"

    def __init__(self, filename, pagesize, blocksize, chipsize, nand_blocksize, nand_chipsize, root_part):
        self.filename = filename
        self.pagesize = pagesize
        self.blocksize = blocksize
        self.chipsize = chipsize
        self.nand_blocksize = nand_blocksize
        self.nand_chipsize = nand_chipsize
        self.__partitions = OrderedDict()

    def __validate(self, part_fp):
       """Validate the MIBIB by checking for magic bytes."""

       mheader_str = part_fp.read(struct.calcsize(MIBIB.HEADER_FMT))
       mheader = struct.unpack(MIBIB.HEADER_FMT, mheader_str)
       mheader = MIBIB.Header._make(mheader)

       if (mheader.magic1 != MIBIB.HEADER_MAGIC1
           or mheader.magic2 != MIBIB.HEADER_MAGIC2):
           """ mheader.magic1 = MIBIB.HEADER_MAGIC1
           mheader.magic2 = MIBIB.HEADER_MAGIC2 """
           error("invalid partition table, magic byte not present")

       if mheader.version != MIBIB.HEADER_VERSION:
           error("unsupport mibib version")

    def __read_parts(self, part_fp):
        """Read the partitions from the MIBIB."""
	global ARCH_NAME
        part_fp.seek(self.pagesize, os.SEEK_SET)
        mtable_str = part_fp.read(struct.calcsize(MIBIB.TABLE_FMT))
        mtable = struct.unpack(MIBIB.TABLE_FMT, mtable_str)
        mtable = MIBIB.Table._make(mtable)

        if (mtable.magic1 != MIBIB.TABLE_MAGIC1
            or mtable.magic2 != MIBIB.TABLE_MAGIC2):
            """ mtable.magic1 = MIBIB.TABLE_MAGIC1
            mtable.magic2 = MIBIB.TABLE_MAGIC2 """
            error("invalid sys part. table, magic byte not present")
        if ARCH_NAME == "ipq806x":
            if mtable.version != MIBIB.TABLE_VERSION_IPQ806X:
                error("unsupported partition table version")
        else:
            if mtable.version != MIBIB.TABLE_VERSION_OTHERS:
                error("unsupported partition table version")

        for i in range(mtable.numparts):
            mentry_str = part_fp.read(struct.calcsize(MIBIB.ENTRY_FMT))
            mentry = struct.unpack(MIBIB.ENTRY_FMT, mentry_str)
            mentry = MIBIB.Entry._make(mentry)
            self.flash_flag = self.blocksize
            self.chip_flag = self.chipsize

            if mentry.which_flash != 0:
                self.flash_flag = self.nand_blocksize
                self.chip_flag = self.nand_chipsize

            byte_offset = mentry.offset * self.flash_flag

            if mentry.length == 0xFFFFFFFF:
               byte_length = self.chip_flag - byte_offset
            else:
               byte_length = mentry.length * self.flash_flag

            part_name = mentry.name.strip(chr(0))
            part_info = PartInfo(part_name, byte_offset, byte_length, mentry.which_flash)
            self.__partitions[part_name] = part_info

    def get_parts(self):
        """Returns a list of partitions present in the MIBIB. CE """

        try:
            with open(self.filename, "r") as part_fp:
                self.__validate(part_fp)
                self.__read_parts(part_fp)
        except IOError, e:
            error("error opening %s" % self.filename, e)

        return self.__partitions

class FlashScript(object):
    """Base class for creating flash scripts."""

    def __init__(self, flinfo):
        self.pagesize = flinfo.pagesize
        self.blocksize = flinfo.blocksize
        self.script = []
        self.parts = []
        self.curr_stdout = "serial"
        self.activity = None
        self.flash_type = flinfo.type

        self.script.append('if test "x$verbose" = "x"; then\n')
        self.script.append("failedmsg='[failed]'\n")
        self.script.append('else\n')
        self.script.append("failedmsg='%s Failed'\n" % ("#" * 40))
        self.script.append('fi\n')

    def append(self, cmd, fatal=True):
        """Add a command to the script.

        Add additional code, to terminate on error. This can be
        supressed by passing 'fatal' as False.
        """

        if fatal:
            """Check cmd strings to display reason for failure."""

            if "imxtract" in cmd:
                self.script.append("failreason='error: failed on image extraction'\n")
            elif "erase" in cmd:
                self.script.append("failreason='error: failed on partition erase'\n")
            elif "write" in cmd:
                self.script.append("failreason='error: failed on partition write'\n")
            else:
                pass

            self.script.append(cmd
                               + ' || setenv stdout serial'
                               + ' && echo "$failedmsg"'
                               + ' && echo "$failreason"'
                               + ' && exit 1\n')
        else:
            self.script.append(cmd + "\n")

    def dumps(self):
        """Return the created script as a string."""
        return "".join(self.script)

    def redirect(self, dev):
        """Generate code, to redirect command output to a device."""

        if self.curr_stdout == dev:
            return

        self.append("setenv stdout %s" % dev, fatal=False)
        self.curr_stdout = dev

    def start_activity(self, activity):
        """Generate code, to indicate start of an activity."""

        self.script.append('if test "x$verbose" = "x"; then\n')
        self.echo("'%-40.40s'" % activity, nl=False)
        self.script.append('else\n')
        self.echo("'%s %s Started'" % ("#" * 40, activity), verbose=True)
        self.script.append('fi\n')
        self.activity = activity

    def finish_activity(self):
        """Generate code, to indicate end of an activity."""

        self.script.append('if test "x$verbose" = "x"; then\n')
        self.echo("'[ done ]'")
        self.redirect("serial")
        self.script.append('else\n')
        self.echo("'%s %s Done'" % ("#" * 40, self.activity), verbose=True)
        self.script.append('fi\n')

    def imxtract(self, part):
        """Generate code, to extract image location, from a multi-image blob.

        part -- string, name of the sub-image

        Sets the $fileaddr environment variable, to point to the
        location of the sub-image.
        """

        self.append("imxtract $imgaddr %s" % part)

    def echo(self, msg, nl=True, verbose=False):
        """Generate code, to print a message.

        nl -- bool, indicates whether newline is to be printed
        verbose -- bool, indicates whether printing in verbose mode
        """

        if not verbose:
            self.redirect("serial")

        if nl:
            self.append("echo %s" % msg, fatal=False)
        else:
            self.append("echo %s%s" % (r"\\c", msg), fatal=False)

        if not verbose:
            self.redirect("nulldev")

    def end(self):
        """Generate code, to indicate successful completion of script."""

        self.append("exit 0\n", fatal=False)

    def start_if(self, var, value):
        """Generate code, to check an environment variable.

        var -- string, variable to check
        value -- string, the value to compare with
        """

        self.append('if test "$%s" = "%s"; then\n' % (var, value),
                    fatal=False)

    def end_if(self):
        """Generate code, to end if statement."""

        self.append('fi\n', fatal=False)

class Flash_Script(FlashScript):
    """Class for creating NAND flash scripts."""

    def __init__(self, *args):
        FlashScript.__init__(self, args[0])
        if args[0].type == "nand":
            self.ipq_nand = args[1]
        elif args[0].type == "nor" or args[0].type == "norplusnand":
            self.nand_pagesize = args[1]

    def erase(self, offset, size):
        """Generate code, to erase the specified partition."""

        if self.flash_type != "emmc":
            size = roundup(size, self.blocksize)

        if self.flash_type == "nand":
                self.append("nand device 0 && nand erase 0x%08x 0x%08x" % (offset, size))
        elif self.flash_type == "nor":
            self.append("sf erase 0x%08x +0x%08x" % (offset, size))
        elif self.flash_type == "emmc":
            self.append("mmc erase 0x%08x %x" % (offset, size))

    def nand_write(self, offset, part_size, img_size, spi_nand):
       """Handle the NOR + NAND case
          All binaries upto HLOS will go to NOR and Root FS will go to NAND
          Assumed all nand page sizes are less than are equal to 8KB
          """

       if spi_nand == "true":
           self.append("nand device 1 && nand erase 0x%08x 0x%08x" % (offset, part_size))
       else:
           self.append("nand device 0 && nand erase 0x%08x 0x%08x" % (offset, part_size))

       if img_size > 0:
            self.append("nand write $fileaddr 0x%08x 0x%08x" % (offset, img_size))

    def write(self, offset, size):
        """Generate code, to write to a partition."""

        if self.flash_type == "nand":
            if size > 0:
                size = roundup(size, self.pagesize)
                self.append("nand write $fileaddr 0x%08x 0x%08x" % (offset, size))

        elif self.flash_type == "nor":
            if size > 0:
                self.append("sf write $fileaddr 0x%08x 0x%08x" % (offset, size))

        elif self.flash_type == "emmc":
            if size > 0:
               size = roundup(size, self.blocksize)
               blk_cnt = size / self.blocksize
               self.append("mmc write $fileaddr 0x%08x %x" % (offset, blk_cnt))

    def probe(self):
        if self.flash_type == "nand":
            pass
        elif self.flash_type == "nor":
            self.append("sf probe")
        else:
            pass

    def switch_layout(self, layout):
        if self.flash_type == "nand":
            self.append("ipq_nand %s" % layout)
        else:
            pass

its_tmpl = Template("""
/dts-v1/;

/ {
        description = "${desc}";
        images {
${images}
        };
};
""")

its_image_tmpl = Template("""
                ${name} {
                        description = "${desc}";
                        data = /incbin/("./${fname}");
                        type = "${imtype}";
                        arch = "arm";
                        compression = "none";
                        hash@1 { algo = "crc32"; };
                };
""")

def sha1(message):
    """Returns SHA1 digest in hex format of the message."""

    m = hashlib.sha1()
    m.update(message)
    return m.hexdigest()

class Pack(object):
    """Class to create a flashable, multi-image blob.

    Combine multiple images present in a directory, and generate a
    U-Boot script to flash the images.
    """
    # The maximum rootfs size is 64MB
    norplusnand_rootfs_img_size = (64 * 1024 * 1024)

    def __init__(self):
        self.flinfo = None
        self.images_dname = None
        self.ipq_nand = None
        self.partitions = {}

        self.fconf_fname = None
        self.scr_fname = None
        self.its_fname = None
        self.img_fname = None
        self.emmc_page_size = 512
        self.emmc_block_size = 512

    def __get_machid(self, section):
        """Get the machid for a section.

        info -- ConfigParser object, containing image flashing info
        section -- section to retreive the machid from
        """
        try:
            machid = int(section.find("./machid").text, 0)
            machid = "%x" % machid
        except ValueError, e:
            error("invalid value for machid, should be integer")

        return machid

    def __get_img_size(self, filename):
        """Get the size of the image to be flashed

        filaneme -- string, filename of the image to be flashed
        """

        if filename.lower() == "none":
            return 0
        try:
            return getsize(os.path.join(self.images_dname, filename))
        except OSError, e:
            error("error getting image size '%s'" % filename, e)

    def __get_part_info(self, partition):
        """Return partition info for the specified partition.

        partition -- string, partition name
        """
        try:
            return self.partitions[partition]
        except KeyError, e:
            return None

    def __gen_flash_script_cdt(self, entries, partition, flinfo, script):
	global ARCH_NAME
        for section in entries:

            machid = int(section.find(".//machid").text, 0)
            machid = "%x" % machid
            board = section.find(".//board").text
            spi_nand = section.find(".//spi_nand").text
            if ARCH_NAME != "ipq806x":
                try:
                    memory = section.find(".//memory").text
                except AttributeError, e:
                    memory = "128M16"
                if memory_size != "default":
                    filename = "cdt-" + board + "_" + memory + "_LM" + memory_size + ".bin"
                else:
                    filename = "cdt-" + board + "_" + memory + ".bin"
            else:
                filename = "cdt-" + board + ".bin"

            img_size = self.__get_img_size(filename)
            part_info = self.__get_part_info(partition)

            section_label = partition.split(":")
            if len(section_label) != 1:
                section_conf = section_label[1]
            else:
                section_conf = section_label[0]

            section_conf = section_conf.lower()

            if self.flinfo.type == 'nand':
                size = roundup(img_size, flinfo.pagesize)
                tr = ' | tr \"\\000\" \"\\377\"'

            if self.flinfo.type == 'emmc':
                size = roundup(img_size, flinfo.blocksize)
                tr = ''

            if ((self.flinfo.type == 'nand' or self.flinfo.type == 'emmc') and (size != img_size)):
                pad_size = size - img_size
                filename_abs = os.path.join(self.images_dname, filename)
                filename_abs_pad = filename_abs + ".padded"
                cmd = 'cat %s > %s' % (filename_abs, filename_abs_pad)
                ret = subprocess.call(cmd, shell=True)
                if ret != 0:
                    error("failed to copy image")
                cmd = 'dd if=/dev/zero count=1 bs=%s %s >> %s' % (pad_size, tr, filename_abs_pad)
                cmd = '(' + cmd + ') 1>/dev/null 2>/dev/null'
                ret = subprocess.call(cmd, shell=True)
                if ret != 0:
                    error("failed to create padded image from script")

            if self.flinfo.type != "emmc":
               if part_info == None:
                   if self.flinfo.type == 'norplusnand':
                       if count > 2:
                           error("More than 2 NAND images for NOR+NAND is not allowed")
               elif img_size > part_info.length:
                   print "img size is larger than part. len in '%s'" % section_conf
                   return 0
            else:
                if part_info != None:
                    if (img_size > 0):
                        if img_size > (part_info.length * self.flinfo.blocksize):
                            print "img size is larger than part. len in '%s'" % section_conf
                            return 0

            if part_info == None and self.flinfo.type != 'norplusnand':
                print "Flash type is norplusemmc"
                continue

            if machid:
                script.start_if("machid", machid)
            if ARCH_NAME != "ipq806x":
                script.start_activity("Flashing ddr-%s_%s:" % ( board, memory ))
                if img_size > 0:
                    filename_pad = filename + ".padded"
                    if ((self.flinfo.type == 'nand' or self.flinfo.type == 'emmc') and (size != img_size)):
                        script.imxtract("ddr-" + board + "_" + memory + "-" + sha1(filename_pad))
                    else:
                        script.imxtract("ddr-" + board + "_" + memory + "-" + sha1(filename))
                        """ script.imxtract("cdt-" + board + "_" + memory + ".bin-" + sha1(filename_pad))
                    else:
                        script.imxtract("cdt-" + board + "_" + memory + ".bin-" + sha1(filename)) """

            else:
                script.start_activity("Flashing ddr-%s:" % (board))
                script.switch_layout("sbl")
                if img_size > 0:
                    filename_pad = filename + ".padded"
                    if ((self.flinfo.type == 'nand' or self.flinfo.type == 'emmc') and (size != img_size)):
                        script.imxtract("ddr-" + board + "-" + sha1(filename_pad))
                    else:
                        script.imxtract("ddr-" + board + "-" + sha1(filename))
                        """ script.imxtract("cdt-" + board + ".bin-" + sha1(filename_pad))
                    else:
                        script.imxtract("cdt-" + board + ".bin-" + sha1(filename)) """

            part_size = Pack.norplusnand_rootfs_img_size
            if part_info == None:
                if self.flinfo.type == 'norplusnand':
                    offset = count * Pack.norplusnand_rootfs_img_size
                    script.nand_write(offset, part_size, img_size, spi_nand)
                    count = count + 1
            else:
                if part_info.which_flash == 0:
                    offset = part_info.offset
                    script.erase(offset, part_info.length)
                    script.write(offset, img_size)
                else:
                    offset = part_info.offset
                    script.nand_write(offset, part_info.length, img_size, spi_nand)

            script.finish_activity()

            if machid:
                script.end_if()

        return 1

    def __gen_flash_script_image(self, filename, soc_version, file_exists, machid, partition, flinfo, script):

	    img_size = 0
	    if file_exists == 1:
                img_size = self.__get_img_size(filename)
            part_info = self.__get_part_info(partition)

            section_label = partition.split(":")
            if len(section_label) != 1:
                section_conf = section_label[1]
            else:
                section_conf = section_label[0]

            section_conf = section_conf.lower()
            spi_nand = False

            if self.flinfo.type == 'nand':
                size = roundup(img_size, flinfo.pagesize)
                tr = ' | tr \"\\000\" \"\\377\"'

            if self.flinfo.type == 'emmc':
                size = roundup(img_size, flinfo.blocksize)
                tr = ''

            if ((self.flinfo.type == 'nand' or self.flinfo.type == 'emmc') and (size != img_size)):
                pad_size = size - img_size
                filename_abs = os.path.join(self.images_dname, filename)
                filename_abs_pad = filename_abs + ".padded"
                cmd = 'cat %s > %s' % (filename_abs, filename_abs_pad)
                ret = subprocess.call(cmd, shell=True)
                if ret != 0:
                    error("failed to copy image")
                cmd = 'dd if=/dev/zero count=1 bs=%s %s >> %s' % (pad_size, tr, filename_abs_pad)
                cmd = '(' + cmd + ') 1>/dev/null 2>/dev/null'
                ret = subprocess.call(cmd, shell=True)
                if ret != 0:
                    error("failed to create padded image from script")

            if self.flinfo.type != "emmc":
                if part_info == None:
                    if self.flinfo.type == 'norplusnand':
                        if count > 2:
                            error("More than 2 NAND images for NOR+NAND is not allowed")
                elif img_size > part_info.length:
                    print "img size is larger than part. len in '%s'" % section_conf
                    return 0
            else:
                if part_info != None:
                    if (img_size > 0):
                        if img_size > (part_info.length * self.flinfo.blocksize):
                            print "img size is larger than part. len in '%s'" % section_conf
                            return 0

	    if part_info == None and self.flinfo.type != 'norplusnand':
                print "Flash type is norplusemmc"
                return 1

	    if machid:
		script.start_if("machid", machid)

            if section_conf == "qsee":
                section_conf = "tz"
            elif section_conf == "appsbl":
                if lk == "true":
                    section_conf = "lkboot"
                else:
                    section_conf = "u-boot"
            elif section_conf == "rootfs" and self.flash_type in ["nand", "nand-4k", "nand-audio", "nand-audio-4k", "norplusnand", "norplusnand-4k"]:
                section_conf = "ubi"
            elif section_conf == "wififw" and self.flash_type in ["nand", "nand-4k", "nand-audio", "nand-audio-4k", "norplusnand", "norplusnand-4k"]:
                section_conf = "wififw_ubi"

	    if soc_version:
		section_conf = section_conf + "_v" + str(soc_version)
		if str(soc_version) == "1":
		    script.append('if test "$soc_version_major" = "1" || test "$soc_version_major" = ""; then\n', fatal=False)
		else:
		    script.start_if("soc_version_major", soc_version)

            script.start_activity("Flashing %s:" % section_conf)

	    if file_exists == 0:
		script.append('setenv stdout serial && echo "error: binary image not found" && exit 1', fatal=False)
		if soc_version:
		    script.end_if()
		return 1

            if ARCH_NAME == "ipq806x":
                script.switch_layout(layout)
            if img_size > 0:
                filename_pad = filename + ".padded"
                if ((self.flinfo.type == 'nand' or self.flinfo.type == 'emmc') and (size != img_size)):
                    script.imxtract(section_conf + "-" + sha1(filename_pad))
                else:
                    script.imxtract(section_conf + "-" + sha1(filename))

            part_size = Pack.norplusnand_rootfs_img_size
            if part_info == None:
                if self.flinfo.type == 'norplusnand':
                    offset = count * Pack.norplusnand_rootfs_img_size
                    img_size = Pack.norplusnand_rootfs_img_size
                    script.nand_write(offset, part_size, img_size, spi_nand)
                    count = count + 1
            else:
                if part_info.which_flash == 0:
                    offset = part_info.offset
                    script.erase(offset, part_info.length)
                    script.write(offset, img_size)
                else:
                    offset = part_info.offset
                    script.nand_write(offset, part_info.length, img_size, spi_nand)

            script.finish_activity()

	    if soc_version:
		script.end_if()

	    if machid:
		script.end_if()

            return 1

    def __gen_flash_script(self, script, flinfo, root):
        """Generate the script to flash the images.

        info -- ConfigParser object, containing image flashing info
        script -- Script object, to append commands to
        """
	global MODE
	global SRC_DIR
	global ARCH_NAME

	diff_files = ""
        count = 0
	soc_version = 0
	diff_soc_ver_files = 0
	file_exists = 1

        if self.flash_type == "norplusemmc" and flinfo.type == "emmc":
            srcDir_part = SRC_DIR + "/" + ARCH_NAME + "/flash_partition/" + flinfo.type + "-partition.xml"
        else:
            srcDir_part = SRC_DIR + "/" + ARCH_NAME + "/flash_partition/" + self.flash_type.lower() + "-partition.xml"

        root_part = ET.parse(srcDir_part)
        if self.flash_type != "emmc" and flinfo.type != "emmc":
            parts = root_part.findall(".//partitions/partition")
        elif self.flash_type != "emmc" and flinfo.type == "emmc":
            parts = root_part.findall(".//physical_partition[@ref='norplusemmc']/partition")
        else:
            parts = root_part.findall(".//physical_partition[@ref='emmc']/partition")
        if flinfo.type == "emmc" and image_type == "all":
            parts_length = len(parts) + 2
        else:
            parts_length = len(parts)
        entries = root.findall(".//data[@type='MACH_ID_BOARD_MAP']/entry")

        first = False
        section = None
        part_index = 0

        if flinfo.type == "emmc" and image_type == "all":
            first = True

        for index in range(parts_length):

            filename = ""
            partition = ""
            if first:
                if self.flash_type == "norplusemmc":
                    part_info = root.find(".//data[@type='NORPLUSEMMC_PARAMETER']")
                else:
                    part_info = root.find(".//data[@type='EMMC_PARAMETER']")
                part_fname = part_info.find(".//partition_mbn")
                filename = part_fname.text
                partition = "0:GPT"
                first = False

            elif index == (parts_length - 1) and flinfo.type == "emmc" and image_type == "all":
                if self.flash_type == "norplusemmc":
                    part_info = root.find(".//data[@type='NORPLUSEMMC_PARAMETER']")
                else:
                    part_info = root.find(".//data[@type='EMMC_PARAMETER']")
                part_fname = part_info.find(".//partition_mbn_backup")
                filename = part_fname.text
                partition = "0:GPTBACKUP"

            else:
                section = parts[part_index]
                part_index += 1
                if flinfo.type != "emmc":
                    try:
		        if image_type == "all" or section[8].attrib['image_type'] == image_type:
                            filename = section[8].text
		            try:
		               if section[8].attrib['mode'] != MODE:
		            	filename = section[9].text
		               else:
		            	pass
		            except AttributeError, e:
		               pass
		            except KeyError, e:
		               pass
			else:
			    continue
                    except IndexError, e:
                        if index == (parts_length - 1):
                            return
                        else:
                            continue
                    except KeyError, e:
			continue
                    partition = section[0].text
                else:
		    try:
			diff_files = section.attrib['diff_files']
		    except KeyError, e:
			try:
			    diff_soc_ver_files = section.attrib['diff_soc_ver_files']
			except KeyError, e:
			    try:
				if image_type == "all" or section.attrib['image_type'] == image_type:
                                	filename = section.attrib['filename']
                                        if lk == "true" and "u-boot" in filename:
                                            filename = filename.replace("u-boot", "lkboot")
                                	partition = section.attrib['label']
				if filename == "":
					continue
			    except KeyError, e:
                                print "Skipping partition '%s'" % section.attrib['label']
				pass

		    if diff_files == "true":
			try:
			      if image_type == "all" or section.attrib['image_type'] == image_type:
                                  filename = section.attrib['filename_' + MODE]
                                  if lk == "true" and "uImage" in filename:
                                      if MODE == "32":
                                          filename = 'openwrt-' + ARCH_NAME + '-kernelboot.img'
                                      if MODE == "64":
                                          filename = 'openwrt-' + ARCH_NAME + '_' + MODE + '-kernelboot.img'
                                  partition = section.attrib['label']
			      if filename == "":
					continue
                        except KeyError, e:
                               print "Skipping partition '%s'" % section.attrib['label']
			       pass
			diff_files = "" # Clear for next iteration

            # Get machID
            if partition != "0:CDT" and partition != "0:DDRCONFIG":
                machid = None
            else:
		try:
			if image_type == "all" or section.attrib['image_type'] == image_type:
		                ret = self.__gen_flash_script_cdt(entries, partition, flinfo, script)
				if ret == 0:
				    return 0
                                continue
		except KeyError, e:
			continue

            if ARCH_NAME == "ipq806x":
            # Get Layout
                try:
                    layout = section[9].text
		except:
		    layout  = None

                if layout not in ("sbl", "linux", None):
                    error("invalid layout in '%s'" % section)

            if flinfo.type != "emmc":

		img = section.find('img_name')
		if img != None and 'soc_version' in img.attrib:

		    imgs = section.findall('img_name')
		    try:
			for img in imgs:
				filename = img.text
				soc_version = img.get('soc_version')
				if 'optional' in img.attrib:
				     if not os.path.exists(os.path.join(self.images_dname, filename)):
					file_exists = 0
				ret = self.__gen_flash_script_image(filename, soc_version, file_exists, machid, partition, flinfo, script)
				if ret == 0:
                                    return 0
				file_exists = 1 # generating flash script is mandatory by default

			soc_version = 0 # Clear soc_version for next iteration
			continue
		    except KeyError, e:
			continue

	    else:
		if diff_soc_ver_files:
                   try:
                        for version in range(1, int(diff_soc_ver_files)+1):
                           if image_type == "all" or section.attrib['image_type'] == image_type:
                                filename = section.attrib['filename_v' + str(version)]
                                partition = section.attrib['label']
                           if filename == "":
                                continue
			   if section.attrib['optional']:
				if not os.path.exists(os.path.join(self.images_dname, filename)):
				     file_exists = 0
                           ret = self.__gen_flash_script_image(filename, version, file_exists, machid, partition, flinfo, script)
                           if ret == 0:
                                return 0
			   file_exists = 1
                        diff_soc_ver_files = 0 # Clear diff_soc_ver_files for next iteration
                        continue
                   except KeyError, e:
                        print "Skipping partition '%s'" % section.attrib['label']
                        pass

            if filename != "":
                ret = self.__gen_flash_script_image(filename, soc_version, file_exists, machid, partition, flinfo, script)
                if ret == 0:
                    return 0

        return 1

    def __gen_script_cdt(self, images, flinfo, root, section_conf, partition):
        global ARCH_NAME

        entries = root.findall(".//data[@type='MACH_ID_BOARD_MAP']/entry")

        for section in entries:

            board = section.find(".//board").text
            if ARCH_NAME != "ipq806x":
                try:
                    memory = section.find(".//memory").text
                except AttributeError, e:
                    memory = "128M16"

                if memory_size != "default":
                    filename = "cdt-" + board + "_" + memory + "_LM" + memory_size + ".bin"
                else:
                    filename = "cdt-" + board + "_" + memory + ".bin"
                file_info = "ddr-" + board + "_" + memory
            else:
                filename = "cdt-" + board + ".bin"
                file_info = "ddr-" + board

            part_info = self.__get_part_info(partition)

            if part_info == None and self.flinfo.type != 'norplusnand':
                continue

            if self.flinfo.type == 'nand':
                img_size = self.__get_img_size(filename)
                size = roundup(img_size, flinfo.pagesize)
                if ( size != img_size ):
                    filename = filename + ".padded"
            if self.flinfo.type == 'emmc':
                img_size = self.__get_img_size(filename)
                size = roundup(img_size, flinfo.blocksize)
                if ( size != img_size ):
                    filename = filename + ".padded"
            image_info = ImageInfo(file_info + "-" + sha1(filename),
                                   filename, "firmware")
            if filename.lower() != "none":
                if image_info not in images:
		    images.append(image_info)

    def __gen_script_append_images(self, filename, soc_version, images, flinfo, root, section_conf, partition):

	part_info = self.__get_part_info(partition)
	if part_info == None and self.flinfo.type != 'norplusnand':
	    return

	if self.flinfo.type == 'nand':
	    img_size = self.__get_img_size(filename)
	    size = roundup(img_size, flinfo.pagesize)
	    if ( size != img_size ):
		filename = filename + ".padded"
	if self.flinfo.type == 'emmc':
	    img_size = self.__get_img_size(filename)
	    size = roundup(img_size, flinfo.blocksize)
	    if ( size != img_size ):
		filename = filename + ".padded"
	if section_conf == "qsee":
	    section_conf = "tz"
	elif section_conf == "appsbl":
            if lk == "true":
                section_conf = "lkboot"
            else:
                print " Using u-boot..."
	        section_conf = "u-boot"
	elif section_conf == "rootfs" and self.flash_type in ["nand", "nand-4k", "nand-audio", "nand-audio-4k", "norplusnand", "norplusnand-4k"]:
	    section_conf = "ubi"
	elif section_conf == "wififw" and self.flash_type in ["nand", "nand-4k", "nand-audio", "nand-audio-4k", "norplusnand", "norplusnand-4k"]:
	    section_conf = "wififw_ubi"

	if soc_version:
	    section_conf = section_conf + "_v" + str(soc_version)

	image_info = ImageInfo(section_conf + "-" + sha1(filename),
				filename, "firmware")
	if filename.lower() != "none":
	    if image_info not in images:
		images.append(image_info)

    def __gen_script(self, script_fp, script, images, flinfo, root):
        """Generate the script to flash the multi-image blob.

        script_fp -- file object, to write script to
        info_fp -- file object, to read flashing information from
        script -- Script object, to append the commands to
        images -- list of ImageInfo, appended to, based on images in config
        """
	global MODE
	global SRC_DIR

	soc_version = 0
	diff_soc_ver_files = 0
	diff_files = ""
	file_exists = 1

        ret = self.__gen_flash_script(script, flinfo, root)
        if ret == 0:
            return 0 #Stop packing this single-image

        if (self.flash_type == "norplusemmc" and flinfo.type == "emmc") or (self.flash_type != "norplusemmc"):
            if flinfo.type == "emmc":
                script.start_activity("Flashing rootfs_data:")
                part_info = self.partitions["rootfs_data"]
                script.erase(part_info.offset, part_info.length)
                script.finish_activity()
            script.end()

        if self.flash_type == "norplusemmc" and flinfo.type == "emmc":
            srcDir_part = SRC_DIR + "/" + ARCH_NAME + "/flash_partition/" + flinfo.type + "-partition.xml"
        else:
            srcDir_part = SRC_DIR + "/" + ARCH_NAME + "/flash_partition/" + self.flash_type.lower() + "-partition.xml"
        root_part = ET.parse(srcDir_part)
        if self.flash_type != "emmc" and flinfo.type != "emmc":
            parts = root_part.findall(".//partitions/partition")
        elif self.flash_type != "emmc" and flinfo.type == "emmc":
            parts = root_part.findall(".//physical_partition[@ref='norplusemmc']/partition")
        else:
            parts = root_part.findall(".//physical_partition[@ref='emmc']/partition")
        if flinfo.type == "emmc" and image_type == "all":
            parts_length = len(parts) + 2
        else:
            parts_length = len(parts)

        first = False
        section = None
        part_index = 0

        if flinfo.type == "emmc" and image_type == "all":
            first = True

        for index in range(parts_length):

            filename = ""
            partition = ""
            if first:
                if self.flash_type == "norplusemmc":
                    part_info = root.find(".//data[@type='NORPLUSEMMC_PARAMETER']")
                else:
                    part_info = root.find(".//data[@type='EMMC_PARAMETER']")
                part_fname = part_info.find(".//partition_mbn")
                filename = part_fname.text
                partition = "0:GPT"
                first = False

            elif index == (parts_length - 1) and flinfo.type == "emmc" and image_type == "all":
                if self.flash_type == "norplusemmc":
                    part_info = root.find(".//data[@type='NORPLUSEMMC_PARAMETER']")
                else:
                    part_info = root.find(".//data[@type='EMMC_PARAMETER']")
                part_fname = part_info.find(".//partition_mbn_backup")
                filename = part_fname.text
                partition = "0:GPTBACKUP"

            else:
                section = parts[part_index]
                part_index += 1
                if flinfo.type != "emmc":
                    try:
			if image_type == "all" or section[8].attrib['image_type'] == image_type:
                            filename = section[8].text
			    try:
			        if section[8].attrib['mode'] != MODE:
				    filename = section[9].text
			    except AttributeError, e:
			 	pass
			    except KeyError, e:
			        pass
                    except IndexError, e:
                        if index == (parts_length - 1):
                            return
                        else:
                            continue
                    except KeyError, e:
			continue
                    partition = section[0].text
                else:

		    try:
			diff_files = section.attrib['diff_files']
		    except KeyError, e:
                        try:
			    diff_soc_ver_files = section.attrib['diff_soc_ver_files']
			    partition = section.attrib['label']
			except KeyError, e:
			    try:
			       if image_type == "all" or section.attrib['image_type'] == image_type:
				   filename = section.attrib['filename']
                                   if lk == "true" and "u-boot" in filename:
                                       filename = filename.replace("u-boot", "lkboot")
				   partition = section.attrib['label']
			       if filename == "":
				   continue
			    except KeyError, e:
			       print "Skipping partition '%s'" % section.attrib['label']
			       pass

		    if diff_files == "true":
			try:
			      if image_type == "all" or section.attrib['image_type'] == image_type:
                                  filename = section.attrib['filename_' + MODE]
                                  if lk == "true" and "uImage" in filename:
                                      if MODE == "32":
                                          filename = 'openwrt-' + ARCH_NAME + '-kernelboot.img'
                                      if MODE == "64":
                                          filename = 'openwrt-' + ARCH_NAME + '_' + MODE + '-kernelboot.img'
                                  partition = section.attrib['label']
			      if filename == "":
                                        continue

                        except KeyError, e:
                              print "Skipping partition '%s'" % section.attrib['label']
			      pass
			diff_files = "" # Clear for next iteration


            part_info = self.__get_part_info(partition)

            section_label = partition.split(":")
            if len(section_label) != 1:
                section_conf = section_label[1]
            else:
                section_conf = section_label[0]

            section_conf = section_conf.lower()

            if section_conf == "cdt" or section_conf == "ddrconfig":
		try:
		    if image_type == "all" or section[8].attrib['image_type'] == image_type:
	                self.__gen_script_cdt(images, flinfo, root, section_conf, partition)
                	continue
                except KeyError, e:
                    continue

            if flinfo.type != "emmc":

		img = section.find('img_name')
		if img != None and 'soc_version' in img.attrib:

		    imgs = section.findall('img_name')
		    try:
		        for img in imgs:
				soc_version = img.get('soc_version')
				filename = img.text
				if 'optional' in img.attrib:
				    if not os.path.exists(os.path.join(self.images_dname, filename)):
					file_exists = 0

				if file_exists == 1:
				    self.__gen_script_append_images(filename, soc_version, images, flinfo, root, section_conf, partition)
				file_exists = 1
			soc_version = 0 # Clear soc_version for next iteration
			continue
		    except KeyError, e:
			continue

            else:
		if diff_soc_ver_files:
		    try:
			for version in range(1, int(diff_soc_ver_files)+1):
			   if image_type == "all" or section.attrib['image_type'] == image_type:
				filename = section.attrib['filename_v' + str(version)]
				partition = section.attrib['label']
			   if filename == "":
				continue
			   if section.attrib['optional']:
				if not os.path.exists(os.path.join(self.images_dname, filename)):
					file_exists = 0

			   if file_exists == 1:
			        self.__gen_script_append_images(filename, version, images, flinfo, root, section_conf, partition)
			   file_exists = 1

			diff_soc_ver_files = 0 # Clear diff_soc_ver_files for next iteration
			continue
		    except KeyError, e:
			print "Skipping partition '%s'" % section.attrib['label']
			pass

            if filename != "":
                self.__gen_script_append_images(filename, soc_version, images, flinfo, root, section_conf, partition)
        return 1

    def __mkimage(self, images):
        """Create the multi-image blob.

        images -- list of ImageInfo, containing images to be part of the blob
        """
        try:
            its_fp = open(self.its_fname, "wb")
        except IOError, e:
            error("error opening its file '%s'" % self.its_fname, e)

        desc = "Flashing %s %x %x"
        desc = desc % (self.flinfo.type, self.flinfo.pagesize,
                       self.flinfo.blocksize)

        image_data = []
        for (section, fname, imtype) in images:
            fname = fname.replace("\\", "\\\\")
            subs = dict(name=section, desc=fname, fname=fname, imtype=imtype)
            image_data.append(its_image_tmpl.substitute(subs))

        image_data = "".join(image_data)
        its_data = its_tmpl.substitute(desc=desc, images=image_data)

        its_fp.write(its_data)
        its_fp.close()
	
        try:
            cmd = [SRC_DIR + "/mkimage", "-f", self.its_fname, self.img_fname]
            ret = subprocess.call(cmd)
            if ret != 0:
                print ret
                error("failed to create u-boot image from script")
        except OSError, e:
            error("error executing mkimage", e)

    def __create_fnames(self):
        """Populate the filenames."""

        self.scr_fname = os.path.join(self.images_dname, "flash.scr")
        self.its_fname = os.path.join(self.images_dname, "flash.its")

    def __gen_board_script(self, flinfo, part_fname, images, root):
	global SRC_DIR
	global ARCH_NAME

        """Generate the flashing script for one board.

        board_section -- string, board section in board config file
        machid -- string, board machine ID in hex format
        flinfo -- FlashInfo object, contains board specific flash params
        part_fname -- string, partition file specific to the board
        fconf_fname -- string, flash config file specific to the board
        images -- list of ImageInfo, append images used by the board here
        """
        script_fp = open(self.scr_fname, "a")

        if flinfo.type != "emmc":
            if root.find(".//data[@type='NAND_PARAMETER']/entry") != None:
                if self.flash_type == "nand-4k" or self.flash_type == "norplusnand-4k":
                    flash_param = root.find(".//data[@type='NAND_PARAMETER']/entry[@type='4k']")
                elif self.flash_type == "nand-audio":
                    flash_param = root.find(".//data[@type='NAND_PARAMETER']/entry[@type='audio-2k']")
                elif self.flash_type == "nand-audio-4k":
                    flash_param = root.find(".//data[@type='NAND_PARAMETER']/entry[@type='audio-4k']")
                else:
                    flash_param = root.find(".//data[@type='NAND_PARAMETER']/entry[@type='2k']")
            else:
                flash_param = root.find(".//data[@type='NAND_PARAMETER']")

            pagesize = int(flash_param.find(".//page_size").text)
            pages_per_block = int(flash_param.find(".//pages_per_block").text)
            blocksize = pages_per_block * pagesize
            blocks_per_chip = int(flash_param.find(".//total_block").text)
            chipsize = blocks_per_chip * blocksize

            srcDir_part = SRC_DIR + "/" + ARCH_NAME + "/flash_partition/" + flinfo.type + "-partition.xml"
            root_part = ET.parse(srcDir_part)
            mibib = MIBIB(part_fname, flinfo.pagesize, flinfo.blocksize,
                          flinfo.chipsize, blocksize, chipsize, root_part)
            self.partitions = mibib.get_parts()
            if flinfo.type == "nand":
                script = Flash_Script(flinfo, self.ipq_nand)
            elif flinfo.type == "nor":
                script = Flash_Script(flinfo, pagesize)
        else:
            gpt = GPT(part_fname, flinfo.pagesize, flinfo.blocksize, flinfo.chipsize)
            self.partitions = gpt.get_parts()
            script = Flash_Script(flinfo)

        self.flinfo = flinfo

        script.probe()
        ret = self.__gen_script(script_fp, script, images, flinfo, root)
	if ret == 0:
	    return 0

        try:
            script_fp.write(script.dumps())
        except IOError, e:
            error("error writing to script '%s'" % script_fp.name, e)

        script_fp.close()
        return 1

    def __process_board_flash_emmc(self, ftype, images, root):
        """Extract board info from config and generate the flash script.

        ftype -- string, flash type 'emmc'
        board_section -- string, board section in config file
        machid -- string, board machine ID in hex format
        images -- list of ImageInfo, append images used by the board here
        """

        try:
            part_info = root.find(".//data[@type='" + self.flash_type.upper() + "_PARAMETER']")
            part_fname = part_info.find(".//partition_mbn")
            part_fname = part_fname.text
            part_fname = os.path.join(self.images_dname, part_fname)
            if ftype == "norplusemmc":
                part_info = root.find(".//data[@type='NORPLUSEMMC_PARAMETER']")
                pagesize = int(part_info.find(".//page_size_flash").text)
                part_info = root.find(".//data[@type='EMMC_PARAMETER']")
            else:
                pagesize = self.emmc_page_size
            blocksize = self.emmc_block_size
            chipsize = int(part_info.find(".//total_block").text)
            if ftype.lower() == "norplusemmc":
                ftype = "emmc"

        except ValueError, e:
            error("invalid flash info in section '%s'" % board_section.find('machid').text, e)

        flinfo = FlashInfo(ftype, pagesize, blocksize, chipsize)

        ret = self.__gen_board_script(flinfo, part_fname, images, root)
	if ret == 0:
            return 0

        return 1

    def __process_board_flash(self, ftype, images, root):
	global SRC_DIR
	global ARCH_NAME
	global MODE

        try:
            if ftype == "tiny-nor":
                part_info = root.find(".//data[@type='" + "NOR_PARAMETER']")
            elif ftype in ["nand", "nand-4k", "nand-audio", "nand-audio-4k"]:
                if root.find(".//data[@type='NAND_PARAMETER']/entry") != None:
                    if ftype == "nand":
                        part_info = root.find(".//data[@type='NAND_PARAMETER']/entry[@type='2k']")
                    elif ftype == "nand-audio":
                        part_info = root.find(".//data[@type='NAND_PARAMETER']/entry[@type='audio-2k']")
                    elif ftype == "nand-audio-4k":
                        part_info = root.find(".//data[@type='NAND_PARAMETER']/entry[@type='audio-4k']")
                    else:
                        part_info = root.find(".//data[@type='NAND_PARAMETER']/entry[@type='4k']")
                else:
                    part_info = root.find(".//data[@type='" + "NAND_PARAMETER']")
            elif ftype == "norplusnand-4k":
                part_info = root.find(".//data[@type='" + "NORPLUSNAND_PARAMETER']")
            else:
                part_info = root.find(".//data[@type='" + ftype.upper() + "_PARAMETER']")

	    if ARCH_NAME == "ipq6018":
		if MODE == "64":
                    MODE_APPEND = "_64"
                else:
                    MODE_APPEND = ""

                if ftype in ["nand-audio", "nand-audio-4k"]:
                    UBINIZE_CFG_NAME = ARCH_NAME + "-ubinize" + MODE_APPEND + "-audio.cfg"
                else:
                    UBINIZE_CFG_NAME = ARCH_NAME + "-ubinize" + MODE_APPEND + ".cfg"

                f1 = open(SRC_DIR + "/" + ARCH_NAME + "/flash_partition/" + UBINIZE_CFG_NAME, 'r')
                UBINIZE_CFG_NAME = SRC_DIR + "/" + ARCH_NAME + "/flash_partition/tmp-" + UBINIZE_CFG_NAME
                f2 = open(UBINIZE_CFG_NAME, 'w')
                for line in f1:
                    f2.write(line.replace('image=', "image=" + SRC_DIR + "/"))
                f1.close()
                f2.close()

                if ftype in ["nand-4k", "nand-audio-4k", "norplusnand-4k"]:
                    UBI_IMG_NAME = "openwrt-ipq-ipq60xx" + MODE_APPEND + "-ubi-root-m4096-p256KiB.img"
                    cmd = '%s -m 4096 -p 256KiB -o root.ubi %s' % ((SRC_DIR + "/ubinize") ,UBINIZE_CFG_NAME)
                    ret = subprocess.call(cmd, shell=True)
                    if ret != 0:
                         error("ubinization got failed")
                    cmd = 'dd if=root.ubi of=%s bs=4k conv=sync' % (SRC_DIR + "/" + UBI_IMG_NAME)
                    ret = subprocess.call(cmd, shell=True)
                    if ret != 0:
                         error("ubi image copy operation failed")
                elif ftype in ["nand", "nand-audio", "norplusnand"]:
                    UBI_IMG_NAME = "openwrt-ipq-ipq60xx" + MODE_APPEND +"-ubi-root.img"
                    cmd = '%s -m 2048 -p 128KiB -o root.ubi %s' % ((SRC_DIR + "/ubinize") ,UBINIZE_CFG_NAME)
                    ret = subprocess.call(cmd, shell=True)
                    if ret != 0:
                         error("ubinization got failed")
                    cmd = 'dd if=root.ubi of=%s bs=2k conv=sync' % (SRC_DIR + "/" + UBI_IMG_NAME)
                    ret = subprocess.call(cmd, shell=True)
                    if ret != 0:
                         error("ubi image copy operation failed")

            part_file = SRC_DIR + "/" + ARCH_NAME + "/flash_partition/" + ftype + "-partition.xml"
            part_xml = ET.parse(part_file)
            partition = part_xml.find(".//partitions/partition[2]")
            part_fname = partition[8].text
            part_fname = os.path.join(self.images_dname, part_fname)
            pagesize = int(part_info.find(".//page_size").text)
            pages_per_block = int(part_info.find(".//pages_per_block").text)
            blocks_per_chip = int(part_info.find(".//total_block").text)

            if ftype in ["tiny-nor", "norplusnand", "norplusnand-4k", "norplusemmc"]:
                ftype = "nor"
            if ftype in ["nand-4k", "nand-audio", "nand-audio-4k"]:
                ftype = "nand"

        except ValueError, e:
            error("invalid flash info in section '%s'" % board_section.find('machid').text, e)

        blocksize = pages_per_block * pagesize
        chipsize = blocks_per_chip * blocksize

        flinfo = FlashInfo(ftype, pagesize, blocksize, chipsize)

        ret = self.__gen_board_script(flinfo, part_fname, images, root)
	return ret

    def __process_board(self, images, root):

        try:
            if self.flash_type in [ "nand", "nand-4k", "nand-audio", "nand-audio-4k", "nor", "tiny-nor", "norplusnand", "norplusnand-4k" ]:
                ret = self.__process_board_flash(self.flash_type, images, root)
            elif self.flash_type == "emmc":
                ret = self.__process_board_flash_emmc(self.flash_type, images, root)
            elif self.flash_type == "norplusemmc":
                ret = self.__process_board_flash("norplusemmc", images, root)
		if ret:
                    ret = self.__process_board_flash_emmc("norplusemmc", images, root)
            return ret
        except ValueError, e:
            error("error getting board info in section '%s'" % board_section.find('machid').text, e)

    def main_bconf(self, flash_type, images_dname, out_fname, root):
        """Start the packing process, using board config.

        flash_type -- string, indicates flash type, 'nand' or 'nor' or 'tiny-nor' or 'emmc' or 'norplusnand'
        images_dname -- string, name of images directory
        out_fname -- string, output file path
        """
        self.flash_type = flash_type
        self.images_dname = images_dname
        self.img_fname = out_fname

        self.__create_fnames()
        try:
            os.unlink(self.scr_fname)
        except OSError, e:
            pass

        images = []
        ret = self.__process_board(images, root)
        if ret != 0:
            images.insert(0, ImageInfo("script", "flash.scr", "script"))
            self.__mkimage(images)
        else:
	    fail_img = out_fname.split("/")
            print "Failed to pack %s" % fail_img[-1]

class UsageError(Exception):
    """Indicates error in command arguments."""
    pass

class ArgParser(object):
    """Class to parse command-line arguments."""

    DEFAULT_TYPE = "nor,tiny-nor,nand,norplusnand,emmc,norplusemmc"

    def __init__(self):
        self.flash_type = None
        self.images_dname = None
        self.out_dname = None
        self.scr_fname = None
        self.its_fname = None

    def parse(self, argv):
	global MODE
	global SRC_DIR
	global ARCH_NAME
	global image_type
	global memory_size
        global lk

        """Start the parsing process, and populate members with parsed value.

        argv -- list of string, the command line arguments
        """

	cdir = os.path.abspath(os.path.dirname(""))
        if len(sys.argv) > 1:
            try:
                opts, args = getopt(sys.argv[1:], "", ["arch=", "fltype=", "srcPath=", "inImage=", "outImage=", "image_type=", "memory=", "lk"])
            except GetoptError, e:
		raise UsageError(e.msg)

	    for option, value in opts:
		if option == "--arch":
		    ARCH_NAME = value

		elif option == "--fltype":
		    self.flash_type = value

		elif option == "--srcPath":
		    SRC_DIR = os.path.abspath(value)

		elif option == "--inImage":
		    self.images_dname = os.path.join(cdir, value)

		elif option == "--outImage":
		    self.out_dname = os.path.join(cdir, value)

		elif option == "--image_type":
		    image_type = value

                elif option == "--memory":
                    memory_size = value

                elif option =="--lk":
                    lk = "true"


#Verify Arguments passed by user

# Verify arch type
	    if ARCH_NAME not in ["ipq40xx", "ipq806x", "ipq807x", "ipq807x_64", "ipq6018", "ipq6018_64"]:
		raise UsageError("Invalid arch type '%s'" % arch)

	    if ARCH_NAME == "ipq807x":
		MODE = "32"
	    elif ARCH_NAME == "ipq807x_64":
		MODE = "64"
		ARCH_NAME = "ipq807x"

	    if ARCH_NAME == "ipq6018":
		MODE = "32"
	    elif ARCH_NAME == "ipq6018_64":
		MODE = "64"
		ARCH_NAME = "ipq6018"

# Set flash type to default type (nand) if not given by user
	    if self.flash_type == None:
                self.flash_type = ArgParser.DEFAULT_TYPE
	    for flash_type in self.flash_type.split(","):
                if flash_type not in [ "nand", "nor", "tiny-nor", "emmc", "norplusnand", "norplusemmc" ]:
                    raise UsageError("invalid flash type '%s'" % flash_type)

# Verify src Path
	    if SRC_DIR == "":
		raise UsageError("Source Path is not provided")

#Verify input image path
	    if self.images_dname == None:
		raise UsageError("input images' Path is not provided")

#Verify Output image path
	    if self.out_dname == None:
		raise UsageError("Output Path is not provided")

    def usage(self, msg):
        """Print error message and command usage information.

        msg -- string, the error message
        """
        print "pack: %s" % msg
        print
        print "Usage:"
	print "python pack_hk.py [options] [Value] ..."
	print
        print "options:"
        print "  --arch \tARCH_TYPE [ipq40xx/ipq806x/ipq807x/ipq807x_64/ipq6018/ipq6018_64]"
	print
	print "  --fltype \tFlash Type [nor/tiny-nor/nand/emmc/norplusnand/norplusemmc]"
        print " \t\tMultiple flashtypes can be passed by a comma separated string"
        print " \t\tDefault is all. i.e If \"--fltype\" is not passed image for all the flash-type will be created.\n"
        print "  --srcPath \tPath to the directory containg the meta scripts and configs"
	print
	print "  --inImage \tPath to the direcory containg binaries and images needed for singleimage"
	print
        print "  --outImage \tPath to the directory where single image will be generated"
        print
        print "  --memory \tMemory size for low memory profile"
        print " \t\tIf it is not specified CDTs with default memory size are taken for single-image packing.\n"
        print " \t\tIf specified, CDTs created with specified memory size will be used for single-image.\n"
        print
        print "  --lk \t\tReplace u-boot with lkboot for appsbl"
        print " \t\tThis Argument does not take any value"
        print "Pack Version: %s" % version

def gen_kernelboot_img(parser):
    """Generate kernelboot.img needed by LK bootloader"""

    SKALES_DIR = parser.images_dname
    TMP_DIR = parser.images_dname + "/tmp_dir"

    try:

        if os.path.exists(TMP_DIR):
            rmtree(TMP_DIR)
	os.makedirs(TMP_DIR)

        if MODE == "64":
            KERNEL_IMG_NAME = "openwrt-" + ARCH_NAME + "_" + MODE + "-kernelboot.img"
            BASE_ADDR = "0x41078000"
        else:
            KERNEL_IMG_NAME = "openwrt-" + ARCH_NAME + "-kernelboot.img"
            BASE_ADDR = "0x41200000"

        src = parser.images_dname + "/qcom-" + ARCH_NAME + "-hk01.dtb"
        if not os.path.exists(src):
            error("%s file not found" % src)
        copy(src, TMP_DIR)

        src = parser.images_dname + "/Image"
        if not os.path.exists(src):
	    error("%s file not found" % src)
        copy(src, TMP_DIR)

        cmd = [SKALES_DIR + "/dtbTool -o " + TMP_DIR + "/qcom-ipq807x-hk01-dt.img " + TMP_DIR]
        ret = subprocess.call(cmd, shell=True)
        if ret != 0:
            print ret
            error("Error executing dtbTools")

        cmd = ["gzip -9 " + TMP_DIR + "/Image"]
        ret = subprocess.call(cmd, shell=True)
        if ret != 0:
            print ret
            error("Error executing gzip")

        cmd = [SKALES_DIR + "/mkbootimg",
                "--kernel=" + TMP_DIR + "/Image.gz",
                "--dt=" + TMP_DIR + "/qcom-ipq807x-hk01-dt.img",
                "--cmdline=\'rootfsname=rootfs rootwait nosmp\'",
                "--output=" + parser.images_dname + "/" + KERNEL_IMG_NAME,
                "--base=" + BASE_ADDR]
        ret = subprocess.call(cmd)
        if ret != 0:
            print ret
            error("Error executing mkbootimg")

        rmtree(TMP_DIR)
    except OSError, e:
        error("error generating kernelboot.img", e)

def main():
    """Main script entry point.

    Created to avoid polluting the global namespace.
    """
    try:
        parser = ArgParser()
        parser.parse(sys.argv)
    except UsageError, e:
        parser.usage(e.args[0])
        sys.exit(1)

    pack = Pack()

    if not os.path.exists(parser.out_dname):
	os.makedirs(parser.out_dname)

    config = SRC_DIR + "/" + ARCH_NAME + "/config.xml"
    root = ET.parse(config)

# Add nand-4k flash type, if nand flash type is specified
    if "nand" in parser.flash_type.split(","):
        if root.find(".//data[@type='NAND_PARAMETER']/entry") != None:
            parser.flash_type = parser.flash_type + ",nand-4k"

# Add norplusnand-4k flash type, if norplusnand flash type is specified
    if "norplusnand" in parser.flash_type.split(","):
        if root.find(".//data[@type='NAND_PARAMETER']/entry") != None:
            parser.flash_type = parser.flash_type + ",norplusnand-4k"

# Format the output image name from Arch, flash type and mode
    for flash_type in parser.flash_type.split(","):
        if image_type == "hlos":
            if MODE == "64":
                parser.out_fname = flash_type + "-" + ARCH_NAME + "_" + MODE + "-apps.img"
            else:
                parser.out_fname = flash_type + "-" + ARCH_NAME + "-apps.img"
        else:
            if flash_type == "emmc" and lk == "true":
                suffix = "-single-lkboot.img"
                gen_kernelboot_img(parser)

            else:
                suffix = "-single.img"

            if MODE == "64":
                parser.out_fname = flash_type + "-" + ARCH_NAME + "_" + MODE + suffix
            else:
                parser.out_fname = flash_type + "-" + ARCH_NAME + suffix

        parser.out_fname = os.path.join(parser.out_dname, parser.out_fname)

        pack.main_bconf(flash_type, parser.images_dname,
                        parser.out_fname, root)

if __name__ == "__main__":
    main()
