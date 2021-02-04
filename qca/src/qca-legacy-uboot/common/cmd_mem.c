/*
 * (C) Copyright 2000
 * Wolfgang Denk, DENX Software Engineering, wd@denx.de.
 *
 * See file CREDITS for list of people who contributed to this
 * project.
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License as
 * published by the Free Software Foundation; either version 2 of
 * the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston,
 * MA 02111-1307 USA
 */

/*
 * Memory Functions
 *
 * Copied from FADS ROM, Dan Malek (dmalek@jlc.net)
 */

#include <common.h>
#include <command.h>
#if (CONFIG_COMMANDS & CFG_CMD_MMC)
#include <mmc.h>
#endif
#ifdef CONFIG_HAS_DATAFLASH
#include <dataflash.h>
#endif
#include "defines.h"

#if (CONFIG_COMMANDS & (CFG_CMD_MEMORY	| \
			CFG_CMD_I2C	| \
			CFG_CMD_ITEST	| \
			CFG_CMD_PCI	| \
			CMD_CMD_PORTIO	) )
int cmd_get_data_size(char* arg, int default_size)
{
	/* Check for a size specification .b, .w or .l.
	 */
	int len = strlen(arg);
	if (len > 2 && arg[len-2] == '.') {
		switch(arg[len-1]) {
		case 'b':
			return 1;
		case 'w':
			return 2;
		case 'l':
			return 4;
		case 's':
			return -2;
		default:
			return -1;
		}
	}
	return default_size;
}
#endif

#if (CONFIG_COMMANDS & CFG_CMD_MEMORY)

#ifdef	CMD_MEM_DEBUG
#define	PRINTF(fmt,args...)	printf (fmt ,##args)
#else
#define PRINTF(fmt,args...)
#endif

static int mod_mem(cmd_tbl_t *, int, int, int, char *[]);

/* Display values from last command.
 * Memory modify remembered values are different from display memory.
 */
uint	dp_last_addr, dp_last_size;
uint	dp_last_length = 0x40;
uint	mm_last_addr, mm_last_size;

static	ulong	base_address = 0;

/* Memory Display
 *
 * Syntax:
 *	md{.b, .w, .l} {addr} {len}
 */
#define DISP_LINE_LEN	16
int do_mem_md ( cmd_tbl_t *cmdtp, int flag, int argc, char *argv[])
{
	ulong	addr, length;
	ulong	i, nbytes, linebytes;
	u_char	*cp;
	int	size;
	int rc = 0;

	/* We use the last specified parameters, unless new ones are
	 * entered.
	 */
	addr = dp_last_addr;
	size = dp_last_size;
	length = dp_last_length;

	if (argc < 2) {
		printf ("Usage:\n%s\n", cmdtp->usage);
		return 1;
	}

	if ((flag & CMD_FLAG_REPEAT) == 0) {
		/* New command specified.  Check for a size specification.
		 * Defaults to long if no or incorrect specification.
		 */
		if ((size = cmd_get_data_size(argv[0], 4)) < 0)
			return 1;

		/* Address is specified since argc > 1
		*/
		addr = simple_strtoul(argv[1], NULL, 16);
		addr += base_address;

		/* If another parameter, it is the length to display.
		 * Length is the number of objects, not number of bytes.
		 */
		if (argc > 2)
			length = simple_strtoul(argv[2], NULL, 16);
	}

	/* Print the lines.
	 *
	 * We buffer all read data, so we can make sure data is read only
	 * once, and all accesses are with the specified bus width.
	 */
	nbytes = length * size;
	do {
		char	linebuf[DISP_LINE_LEN];
		uint	*uip = (uint   *)linebuf;
		ushort	*usp = (ushort *)linebuf;
		u_char	*ucp = (u_char *)linebuf;
#ifdef CONFIG_HAS_DATAFLASH
		int rc;
#endif
		printf("%08lx:", addr);
		linebytes = (nbytes>DISP_LINE_LEN)?DISP_LINE_LEN:nbytes;

#ifdef CONFIG_HAS_DATAFLASH
		if ((rc = read_dataflash(addr, (linebytes/size)*size, linebuf)) == DATAFLASH_OK){
			/* if outside dataflash */
			/*if (rc != 1) {
				dataflash_perror (rc);
				return (1);
			}*/
			for (i=0; i<linebytes; i+= size) {
				if (size == 4) {
					printf(" %08x", *uip++);
				} else if (size == 2) {
					printf(" %04x", *usp++);
				} else {
					printf(" %02x", *ucp++);
				}
				addr += size;
			}

		} else {	/* addr does not correspond to DataFlash */
#endif
		for (i=0; i<linebytes; i+= size) {
			if (size == 4) {
				printf(" %08x", (*uip++ = *((uint *)addr)));
			} else if (size == 2) {
				printf(" %04x", (*usp++ = *((ushort *)addr)));
			} else {
				printf(" %02x", (*ucp++ = *((u_char *)addr)));
			}
			addr += size;
		}
#ifdef CONFIG_HAS_DATAFLASH
		}
#endif
		puts ("    ");
		cp = (u_char *)linebuf;
		for (i=0; i<linebytes; i++) {
			if ((*cp < 0x20) || (*cp > 0x7e))
				putc ('.');
			else
				printf("%c", *cp);
			cp++;
		}
		putc ('\n');
		nbytes -= linebytes;
		if (ctrlc()) {
			rc = 1;
			break;
		}
	} while (nbytes > 0);

	dp_last_addr = addr;
	dp_last_length = length;
	dp_last_size = size;
	return (rc);
}

int do_mem_mm ( cmd_tbl_t *cmdtp, int flag, int argc, char *argv[])
{
	return mod_mem (cmdtp, 1, flag, argc, argv);
}
int do_mem_nm ( cmd_tbl_t *cmdtp, int flag, int argc, char *argv[])
{
	return mod_mem (cmdtp, 0, flag, argc, argv);
}

int do_mem_mw ( cmd_tbl_t *cmdtp, int flag, int argc, char *argv[])
{
	ulong	addr, writeval, count;
	int	size;

	if ((argc < 3) || (argc > 4)) {
		printf ("Usage:\n%s\n", cmdtp->usage);
		return 1;
	}

	/* Check for size specification.
	*/
	if ((size = cmd_get_data_size(argv[0], 4)) < 1)
		return 1;

	/* Address is specified since argc > 1
	*/
	addr = simple_strtoul(argv[1], NULL, 16);
	addr += base_address;

	/* Get the value to write.
	*/
	writeval = simple_strtoul(argv[2], NULL, 16);

	/* Count ? */
	if (argc == 4) {
		count = simple_strtoul(argv[3], NULL, 16);
	} else {
		count = 1;
	}

	while (count-- > 0) {
		if (size == 4)
			*((ulong  *)addr) = (ulong )writeval;
		else if (size == 2)
			*((ushort *)addr) = (ushort)writeval;
		else
			*((u_char *)addr) = (u_char)writeval;
		addr += size;
	}
	return 0;
}

#ifdef CONFIG_MX_CYCLIC
int do_mem_mdc ( cmd_tbl_t *cmdtp, int flag, int argc, char *argv[])
{
	int i;
	ulong count;

	if (argc < 4) {
		printf ("Usage:\n%s\n", cmdtp->usage);
		return 1;
	}

	count = simple_strtoul(argv[3], NULL, 10);

	for (;;) {
		do_mem_md (NULL, 0, 3, argv);

		/* delay for <count> ms... */
		for (i=0; i<count; i++)
			udelay (1000);

		/* check for ctrl-c to abort... */
		if (ctrlc()) {
			puts("Abort\n");
			return 0;
		}
	}

	return 0;
}

int do_mem_mwc ( cmd_tbl_t *cmdtp, int flag, int argc, char *argv[])
{
	int i;
	ulong count;

	if (argc < 4) {
		printf ("Usage:\n%s\n", cmdtp->usage);
		return 1;
	}

	count = simple_strtoul(argv[3], NULL, 10);

	for (;;) {
		do_mem_mw (NULL, 0, 3, argv);

		/* delay for <count> ms... */
		for (i=0; i<count; i++)
			udelay (1000);

		/* check for ctrl-c to abort... */
		if (ctrlc()) {
			puts("Abort\n");
			return 0;
		}
	}

	return 0;
}
#endif /* CONFIG_MX_CYCLIC */
#ifndef COMPRESSED_UBOOT
int do_mem_cmp (cmd_tbl_t *cmdtp, int flag, int argc, char *argv[])
{
	ulong	addr1, addr2, count, ngood;
	int	size;
	int     rcode = 0;

	if (argc != 4) {
		printf ("Usage:\n%s\n", cmdtp->usage);
		return 1;
	}

	/* Check for size specification.
	*/
	if ((size = cmd_get_data_size(argv[0], 4)) < 0)
		return 1;

	addr1 = simple_strtoul(argv[1], NULL, 16);
	addr1 += base_address;

	addr2 = simple_strtoul(argv[2], NULL, 16);
	addr2 += base_address;

	count = simple_strtoul(argv[3], NULL, 16);

#ifdef CONFIG_HAS_DATAFLASH
	if (addr_dataflash(addr1) | addr_dataflash(addr2)){
		puts ("Comparison with DataFlash space not supported.\n\r");
		return 0;
	}
#endif

	ngood = 0;

	while (count-- > 0) {
		if (size == 4) {
			ulong word1 = *(ulong *)addr1;
			ulong word2 = *(ulong *)addr2;
			if (word1 != word2) {
				printf("word at 0x%08lx (0x%08lx) "
					"!= word at 0x%08lx (0x%08lx)\n",
					addr1, word1, addr2, word2);
				rcode = 1;
				break;
			}
		}
		else if (size == 2) {
			ushort hword1 = *(ushort *)addr1;
			ushort hword2 = *(ushort *)addr2;
			if (hword1 != hword2) {
				printf("halfword at 0x%08lx (0x%04x) "
					"!= halfword at 0x%08lx (0x%04x)\n",
					addr1, hword1, addr2, hword2);
				rcode = 1;
				break;
			}
		}
		else {
			u_char byte1 = *(u_char *)addr1;
			u_char byte2 = *(u_char *)addr2;
			if (byte1 != byte2) {
				printf("byte at 0x%08lx (0x%02x) "
					"!= byte at 0x%08lx (0x%02x)\n",
					addr1, byte1, addr2, byte2);
				rcode = 1;
				break;
			}
		}
		ngood++;
		addr1 += size;
		addr2 += size;
	}

	printf("Total of %ld %s%s were the same\n",
		ngood, size == 4 ? "word" : size == 2 ? "halfword" : "byte",
		ngood == 1 ? "" : "s");
	return rcode;
}
#endif /* #ifndef COMPRESSED_UBOOT  */


int do_mem_cp ( cmd_tbl_t *cmdtp, int flag, int argc, char *argv[])
{
	ulong	addr, dest, count;
	int	size;

	if (argc != 4) {
		printf ("Usage:\n%s\n", cmdtp->usage);
		return 1;
	}

	/* Check for size specification.
	*/
	if ((size = cmd_get_data_size(argv[0], 4)) < 0)
		return 1;

	addr = simple_strtoul(argv[1], NULL, 16);
	addr += base_address;

	dest = simple_strtoul(argv[2], NULL, 16);
	dest += base_address;

	count = simple_strtoul(argv[3], NULL, 16);

	if (count == 0) {
		puts ("Zero length ???\n");
		return 1;
	}

#if !defined(CFG_NO_FLASH) && !defined(CONFIG_ATH_NAND_BR)
	/* check if we are copying to Flash */
	if ( (addr2info(dest) != NULL)
#ifdef CONFIG_HAS_DATAFLASH
	   && (!addr_dataflash(addr))
#endif
	   ) {
		int rc;

		puts ("Copy to Flash... ");

		rc = flash_write ((char *)addr, dest, count*size);
		if (rc != 0) {
			flash_perror (rc);
			return (1);
		}
		puts ("done\n");
		return 0;
	}
#endif

#if (CONFIG_COMMANDS & CFG_CMD_MMC)
	if (mmc2info(dest)) {
		int rc;

		puts ("Copy to MMC... ");
		switch (rc = mmc_write ((uchar *)addr, dest, count*size)) {
		case 0:
			putc ('\n');
			return 1;
		case -1:
			puts ("failed\n");
			return 1;
		default:
			printf ("%s[%d] FIXME: rc=%d\n",__FILE__,__LINE__,rc);
			return 1;
		}
		puts ("done\n");
		return 0;
	}

	if (mmc2info(addr)) {
		int rc;

		puts ("Copy from MMC... ");
		switch (rc = mmc_read (addr, (uchar *)dest, count*size)) {
		case 0:
			putc ('\n');
			return 1;
		case -1:
			puts ("failed\n");
			return 1;
		default:
			printf ("%s[%d] FIXME: rc=%d\n",__FILE__,__LINE__,rc);
			return 1;
		}
		puts ("done\n");
		return 0;
	}
#endif

#ifdef CONFIG_HAS_DATAFLASH
	/* Check if we are copying from RAM or Flash to DataFlash */
	if (addr_dataflash(dest) && !addr_dataflash(addr)){
		int rc;

		puts ("Copy to DataFlash... ");

		rc = write_dataflash (dest, addr, count*size);

		if (rc != 1) {
			dataflash_perror (rc);
			return (1);
		}
		puts ("done\n");
		return 0;
	}

	/* Check if we are copying from DataFlash to RAM */
	if (addr_dataflash(addr) && !addr_dataflash(dest) && (addr2info(dest)==NULL) ){
		int rc;
		rc = read_dataflash(addr, count * size, (char *) dest);
		if (rc != 1) {
			dataflash_perror (rc);
			return (1);
		}
		return 0;
	}

	if (addr_dataflash(addr) && addr_dataflash(dest)){
		puts ("Unsupported combination of source/destination.\n\r");
		return 1;
	}
#endif

	while (count-- > 0) {
		if (size == 4)
			*((ulong  *)dest) = *((ulong  *)addr);
		else if (size == 2)
			*((ushort *)dest) = *((ushort *)addr);
		else
			*((u_char *)dest) = *((u_char *)addr);
		addr += size;
		dest += size;
	}
	return 0;
}


#ifndef COMPRESSED_UBOOT
int do_mem_base (cmd_tbl_t *cmdtp, int flag, int argc, char *argv[])
{
	if (argc > 1) {
		/* Set new base address.
		*/
		base_address = simple_strtoul(argv[1], NULL, 16);
	}
	/* Print the current base address.
	*/
	printf("Base Address: 0x%08lx\n", base_address);
	return 0;
}

int do_mem_loop (cmd_tbl_t *cmdtp, int flag, int argc, char *argv[])
{
	ulong	addr, length, i, junk;
	int	size;
	volatile uint	*longp;
	volatile ushort *shortp;
	volatile u_char	*cp;

	if (argc < 3) {
		printf ("Usage:\n%s\n", cmdtp->usage);
		return 1;
	}

	/* Check for a size spefication.
	 * Defaults to long if no or incorrect specification.
	 */
	if ((size = cmd_get_data_size(argv[0], 4)) < 0)
		return 1;

	/* Address is always specified.
	*/
	addr = simple_strtoul(argv[1], NULL, 16);

	/* Length is the number of objects, not number of bytes.
	*/
	length = simple_strtoul(argv[2], NULL, 16);

	/* We want to optimize the loops to run as fast as possible.
	 * If we have only one object, just run infinite loops.
	 */
	if (length == 1) {
		if (size == 4) {
			longp = (uint *)addr;
			for (;;)
				i = *longp;
		}
		if (size == 2) {
			shortp = (ushort *)addr;
			for (;;)
				i = *shortp;
		}
		cp = (u_char *)addr;
		for (;;)
			i = *cp;
	}

	if (size == 4) {
		for (;;) {
			longp = (uint *)addr;
			i = length;
			while (i-- > 0)
				junk = *longp++;
		}
	}
	if (size == 2) {
		for (;;) {
			shortp = (ushort *)addr;
			i = length;
			while (i-- > 0)
				junk = *shortp++;
		}
	}
	for (;;) {
		cp = (u_char *)addr;
		i = length;
		while (i-- > 0)
			junk = *cp++;
	}
}

#ifdef CONFIG_LOOPW
int do_mem_loopw (cmd_tbl_t *cmdtp, int flag, int argc, char *argv[])
{
	ulong	addr, length, i, data;
	int	size;
	volatile uint	*longp;
	volatile ushort *shortp;
	volatile u_char	*cp;

	if (argc < 4) {
		printf ("Usage:\n%s\n", cmdtp->usage);
		return 1;
	}

	/* Check for a size spefication.
	 * Defaults to long if no or incorrect specification.
	 */
	if ((size = cmd_get_data_size(argv[0], 4)) < 0)
		return 1;

	/* Address is always specified.
	*/
	addr = simple_strtoul(argv[1], NULL, 16);

	/* Length is the number of objects, not number of bytes.
	*/
	length = simple_strtoul(argv[2], NULL, 16);

	/* data to write */
	data = simple_strtoul(argv[3], NULL, 16);

	/* We want to optimize the loops to run as fast as possible.
	 * If we have only one object, just run infinite loops.
	 */
	if (length == 1) {
		if (size == 4) {
			longp = (uint *)addr;
			for (;;)
				*longp = data;
					}
		if (size == 2) {
			shortp = (ushort *)addr;
			for (;;)
				*shortp = data;
		}
		cp = (u_char *)addr;
		for (;;)
			*cp = data;
	}

	if (size == 4) {
		for (;;) {
			longp = (uint *)addr;
			i = length;
			while (i-- > 0)
				*longp++ = data;
		}
	}
	if (size == 2) {
		for (;;) {
			shortp = (ushort *)addr;
			i = length;
			while (i-- > 0)
				*shortp++ = data;
		}
	}
	for (;;) {
		cp = (u_char *)addr;
		i = length;
		while (i-- > 0)
			*cp++ = data;
	}
}
#endif /* CONFIG_LOOPW */
#endif /* #ifndef COMPRESSED_UBOOT */

/*
 * Perform a memory test. A more complete alternative test can be
 * configured using CFG_ALT_MEMTEST. The complete test loops until
 * interrupted by ctrl-c or by a failure of one of the sub-tests.
 */
int do_mem_mtest (cmd_tbl_t *cmdtp, int flag, int argc, char *argv[])
{
	vu_long	*addr, *start, *end;
	ulong	val;
	ulong	readback;

#if defined(CFG_ALT_MEMTEST)
	vu_long	addr_mask;
	vu_long	offset;
	vu_long	test_offset;
	vu_long	pattern;
	vu_long	temp;
	vu_long	anti_pattern;
	vu_long	num_words;
#if defined(CFG_MEMTEST_SCRATCH)
	vu_long *dummy = (vu_long*)CFG_MEMTEST_SCRATCH;
#else
	vu_long *dummy = NULL;
#endif
	int	j;
	int iterations = 1;

	static const ulong bitpattern[] = {
		0x00000001,	/* single bit */
		0x00000003,	/* two adjacent bits */
		0x00000007,	/* three adjacent bits */
		0x0000000F,	/* four adjacent bits */
		0x00000005,	/* two non-adjacent bits */
		0x00000015,	/* three non-adjacent bits */
		0x00000055,	/* four non-adjacent bits */
		0xaaaaaaaa,	/* alternating 1/0 */
	};
#else
	ulong	incr;
	ulong	pattern;
	int     rcode = 0;
#endif

	if (argc > 1) {
		start = (ulong *)simple_strtoul(argv[1], NULL, 16);
	} else {
		start = (ulong *)CFG_MEMTEST_START;
	}

	if (argc > 2) {
		end = (ulong *)simple_strtoul(argv[2], NULL, 16);
	} else {
		end = (ulong *)(CFG_MEMTEST_END);
	}

	if (argc > 3) {
		pattern = (ulong)simple_strtoul(argv[3], NULL, 16);
	} else {
		pattern = 0;
	}

#if defined(CFG_ALT_MEMTEST)
	printf ("Testing %08x ... %08x:\n", (uint)start, (uint)end);
	PRINTF("%s:%d: start 0x%p end 0x%p\n",
		__FUNCTION__, __LINE__, start, end);

	for (;;) {
		if (ctrlc()) {
			putc ('\n');
			return 1;
		}

		printf("Iteration: %6d\r", iterations);
		PRINTF("Iteration: %6d\n", iterations);
		iterations++;

		/*
		 * Data line test: write a pattern to the first
		 * location, write the 1's complement to a 'parking'
		 * address (changes the state of the data bus so a
		 * floating bus doen't give a false OK), and then
		 * read the value back. Note that we read it back
		 * into a variable because the next time we read it,
		 * it might be right (been there, tough to explain to
		 * the quality guys why it prints a failure when the
		 * "is" and "should be" are obviously the same in the
		 * error message).
		 *
		 * Rather than exhaustively testing, we test some
		 * patterns by shifting '1' bits through a field of
		 * '0's and '0' bits through a field of '1's (i.e.
		 * pattern and ~pattern).
		 */
		addr = start;
		for (j = 0; j < sizeof(bitpattern)/sizeof(bitpattern[0]); j++) {
		    val = bitpattern[j];
		    for(; val != 0; val <<= 1) {
			*addr  = val;
			*dummy  = ~val; /* clear the test data off of the bus */
			readback = *addr;
			if(readback != val) {
			     printf ("FAILURE (data line): "
				"expected %08lx, actual %08lx\n",
					  val, readback);
			}
			*addr  = ~val;
			*dummy  = val;
			readback = *addr;
			if(readback != ~val) {
			    printf ("FAILURE (data line): "
				"Is %08lx, should be %08lx\n",
					readback, ~val);
			}
		    }
		}

		/*
		 * Based on code whose Original Author and Copyright
		 * information follows: Copyright (c) 1998 by Michael
		 * Barr. This software is placed into the public
		 * domain and may be used for any purpose. However,
		 * this notice must not be changed or removed and no
		 * warranty is either expressed or implied by its
		 * publication or distribution.
		 */

		/*
		 * Address line test
		 *
		 * Description: Test the address bus wiring in a
		 *              memory region by performing a walking
		 *              1's test on the relevant bits of the
		 *              address and checking for aliasing.
		 *              This test will find single-bit
		 *              address failures such as stuck -high,
		 *              stuck-low, and shorted pins. The base
		 *              address and size of the region are
		 *              selected by the caller.
		 *
		 * Notes:	For best results, the selected base
		 *              address should have enough LSB 0's to
		 *              guarantee single address bit changes.
		 *              For example, to test a 64-Kbyte
		 *              region, select a base address on a
		 *              64-Kbyte boundary. Also, select the
		 *              region size as a power-of-two if at
		 *              all possible.
		 *
		 * Returns:     0 if the test succeeds, 1 if the test fails.
		 *
		 * ## NOTE ##	Be sure to specify start and end
		 *              addresses such that addr_mask has
		 *              lots of bits set. For example an
		 *              address range of 01000000 02000000 is
		 *              bad while a range of 01000000
		 *              01ffffff is perfect.
		 */
		addr_mask = ((ulong)end - (ulong)start)/sizeof(vu_long);
		pattern = (vu_long) 0xaaaaaaaa;
		anti_pattern = (vu_long) 0x55555555;

		PRINTF("%s:%d: addr mask = 0x%.8lx\n",
			__FUNCTION__, __LINE__,
			addr_mask);
		/*
		 * Write the default pattern at each of the
		 * power-of-two offsets.
		 */
		for (offset = 1; (offset & addr_mask) != 0; offset <<= 1) {
			start[offset] = pattern;
		}

		/*
		 * Check for address bits stuck high.
		 */
		test_offset = 0;
		start[test_offset] = anti_pattern;

		for (offset = 1; (offset & addr_mask) != 0; offset <<= 1) {
		    temp = start[offset];
		    if (temp != pattern) {
			printf ("\nFAILURE: Address bit stuck high @ 0x%.8lx:"
				" expected 0x%.8lx, actual 0x%.8lx\n",
				(ulong)&start[offset], pattern, temp);
			return 1;
		    }
		}
		start[test_offset] = pattern;

		/*
		 * Check for addr bits stuck low or shorted.
		 */
		for (test_offset = 1; (test_offset & addr_mask) != 0; test_offset <<= 1) {
		    start[test_offset] = anti_pattern;

		    for (offset = 1; (offset & addr_mask) != 0; offset <<= 1) {
			temp = start[offset];
			if ((temp != pattern) && (offset != test_offset)) {
			    printf ("\nFAILURE: Address bit stuck low or shorted @"
				" 0x%.8lx: expected 0x%.8lx, actual 0x%.8lx\n",
				(ulong)&start[offset], pattern, temp);
			    return 1;
			}
		    }
		    start[test_offset] = pattern;
		}

		/*
		 * Description: Test the integrity of a physical
		 *		memory device by performing an
		 *		increment/decrement test over the
		 *		entire region. In the process every
		 *		storage bit in the device is tested
		 *		as a zero and a one. The base address
		 *		and the size of the region are
		 *		selected by the caller.
		 *
		 * Returns:     0 if the test succeeds, 1 if the test fails.
		 */
		num_words = ((ulong)end - (ulong)start)/sizeof(vu_long) + 1;

		/*
		 * Fill memory with a known pattern.
		 */
		for (pattern = 1, offset = 0; offset < num_words; pattern++, offset++) {
			start[offset] = pattern;
		}

		/*
		 * Check each location and invert it for the second pass.
		 */
		for (pattern = 1, offset = 0; offset < num_words; pattern++, offset++) {
		    temp = start[offset];
		    if (temp != pattern) {
			printf ("\nFAILURE (read/write) @ 0x%.8lx:"
				" expected 0x%.8lx, actual 0x%.8lx)\n",
				(ulong)&start[offset], pattern, temp);
			return 1;
		    }

		    anti_pattern = ~pattern;
		    start[offset] = anti_pattern;
		}

		/*
		 * Check each location for the inverted pattern and zero it.
		 */
		for (pattern = 1, offset = 0; offset < num_words; pattern++, offset++) {
		    anti_pattern = ~pattern;
		    temp = start[offset];
		    if (temp != anti_pattern) {
			printf ("\nFAILURE (read/write): @ 0x%.8lx:"
				" expected 0x%.8lx, actual 0x%.8lx)\n",
				(ulong)&start[offset], anti_pattern, temp);
			return 1;
		    }
		    start[offset] = 0;
		}
	}

#else /* The original, quickie test */
	incr = 1;
	for (;;) {
		if (ctrlc()) {
			putc ('\n');
			return 1;
		}

		printf ("\rPattern %08lX  Writing..."
			"%12s"
			"\b\b\b\b\b\b\b\b\b\b",
			pattern, "");

		for (addr=start,val=pattern; addr<end; addr++) {
			*addr = val;
			val  += incr;
		}

		puts ("Reading...");

		for (addr=start,val=pattern; addr<end; addr++) {
			readback = *addr;
			if (readback != val) {
				printf ("\nMem error @ 0x%08X: "
					"found %08lX, expected %08lX\n",
					(uint)addr, readback, val);
				rcode = 1;
			}
			val += incr;
		}

		/*
		 * Flip the pattern each time to make lots of zeros and
		 * then, the next time, lots of ones.  We decrement
		 * the "negative" patterns and increment the "positive"
		 * patterns to preserve this feature.
		 */
		if(pattern & 0x80000000) {
			pattern = -pattern;	/* complement & increment */
		}
		else {
			pattern = ~pattern;
		}
		incr = -incr;
	}
	return rcode;
#endif
}


/* Modify memory.
 *
 * Syntax:
 *	mm{.b, .w, .l} {addr}
 *	nm{.b, .w, .l} {addr}
 */
static int
mod_mem(cmd_tbl_t *cmdtp, int incrflag, int flag, int argc, char *argv[])
{
	ulong	addr, i;
	int	nbytes, size;
	extern char console_buffer[];

	if (argc != 2) {
		printf ("Usage:\n%s\n", cmdtp->usage);
		return 1;
	}

#ifdef CONFIG_BOOT_RETRY_TIME
	reset_cmd_timeout();	/* got a good command to get here */
#endif
	/* We use the last specified parameters, unless new ones are
	 * entered.
	 */
	addr = mm_last_addr;
	size = mm_last_size;

	if ((flag & CMD_FLAG_REPEAT) == 0) {
		/* New command specified.  Check for a size specification.
		 * Defaults to long if no or incorrect specification.
		 */
		if ((size = cmd_get_data_size(argv[0], 4)) < 0)
			return 1;

		/* Address is specified since argc > 1
		*/
		addr = simple_strtoul(argv[1], NULL, 16);
		addr += base_address;
	}

#ifdef CONFIG_HAS_DATAFLASH
	if (addr_dataflash(addr)){
		puts ("Can't modify DataFlash in place. Use cp instead.\n\r");
		return 0;
	}
#endif

	/* Print the address, followed by value.  Then accept input for
	 * the next value.  A non-converted value exits.
	 */
	do {
		printf("%08lx:", addr);
		if (size == 4)
			printf(" %08x", *((uint   *)addr));
		else if (size == 2)
			printf(" %04x", *((ushort *)addr));
		else
			printf(" %02x", *((u_char *)addr));

		nbytes = readline (" ? ");
		if (nbytes == 0 || (nbytes == 1 && console_buffer[0] == '-')) {
			/* <CR> pressed as only input, don't modify current
			 * location and move to next. "-" pressed will go back.
			 */
			if (incrflag)
				addr += nbytes ? -size : size;
			nbytes = 1;
#ifdef CONFIG_BOOT_RETRY_TIME
			reset_cmd_timeout(); /* good enough to not time out */
#endif
		}
#ifdef CONFIG_BOOT_RETRY_TIME
		else if (nbytes == -2) {
			break;	/* timed out, exit the command	*/
		}
#endif
		else {
			char *endp;
			i = simple_strtoul(console_buffer, &endp, 16);
			nbytes = endp - console_buffer;
			if (nbytes) {
#ifdef CONFIG_BOOT_RETRY_TIME
				/* good enough to not time out
				 */
				reset_cmd_timeout();
#endif
				if (size == 4)
					*((uint   *)addr) = i;
				else if (size == 2)
					*((ushort *)addr) = i;
				else
					*((u_char *)addr) = i;
				if (incrflag)
					addr += size;
			}
		}
	} while (nbytes);

	mm_last_addr = addr;
	mm_last_size = size;
	return 0;
}



#ifndef COMPRESSED_UBOOT
#ifndef CONFIG_CRC32_VERIFY

int do_mem_crc (cmd_tbl_t *cmdtp, int flag, int argc, char *argv[])
{
	ulong addr, length;
	ulong crc;
	ulong *ptr;

	if (argc < 3) {
		printf ("Usage:\n%s\n", cmdtp->usage);
		return 1;
	}

	addr = simple_strtoul (argv[1], NULL, 16);
	addr += base_address;

	length = simple_strtoul (argv[2], NULL, 16);

	crc = crc32 (0, (const uchar *) addr, length);

	printf ("CRC32 for %08lx ... %08lx ==> %08lx\n",
			addr, addr + length - 1, crc);

	if (argc > 3) {
		ptr = (ulong *) simple_strtoul (argv[3], NULL, 16);
		*ptr = crc;
	}

	return 0;
}

#else	/* CONFIG_CRC32_VERIFY */

int do_mem_crc (cmd_tbl_t *cmdtp, int flag, int argc, char *argv[])
{
	ulong addr, length;
	ulong crc;
	ulong *ptr;
	ulong vcrc;
	int verify;
	int ac;
	char **av;

	if (argc < 3) {
  usage:
		printf ("Usage:\n%s\n", cmdtp->usage);
		return 1;
	}

	av = argv + 1;
	ac = argc - 1;
	if (strcmp(*av, "-v") == 0) {
		verify = 1;
		av++;
		ac--;
		if (ac < 3)
			goto usage;
	} else
		verify = 0;

	addr = simple_strtoul(*av++, NULL, 16);
	addr += base_address;
	length = simple_strtoul(*av++, NULL, 16);

	crc = crc32(0, (const uchar *) addr, length);

	if (!verify) {
		printf ("CRC32 for %08lx ... %08lx ==> %08lx\n",
				addr, addr + length - 1, crc);
		if (ac > 2) {
			ptr = (ulong *) simple_strtoul (*av++, NULL, 16);
			*ptr = crc;
		}
	} else {
		vcrc = simple_strtoul(*av++, NULL, 16);
		if (vcrc != crc) {
			printf ("CRC32 for %08lx ... %08lx ==> %08lx != %08lx ** ERROR **\n",
					addr, addr + length - 1, crc, vcrc);
			return 1;
		}
	}

	return 0;

}
#endif	/* CONFIG_CRC32_VERIFY */

U_BOOT_CMD(
	cmp,    4,     1,     do_mem_cmp,
	"cmp     - memory compare\n",
	"[.b, .w, .l] addr1 addr2 count\n    - compare memory\n"
);

#ifndef CONFIG_CRC32_VERIFY

U_BOOT_CMD(
	crc32,    4,    1,     do_mem_crc,
	"crc32   - checksum calculation\n",
	"address count [addr]\n    - compute CRC32 checksum [save at addr]\n"
);

#else	/* CONFIG_CRC32_VERIFY */

U_BOOT_CMD(
	crc32,    5,    1,     do_mem_crc,
	"crc32   - checksum calculation\n",
	"address count [addr]\n    - compute CRC32 checksum [save at addr]\n"
	"-v address count crc\n    - verify crc of memory area\n"
);

#endif	/* CONFIG_CRC32_VERIFY */

U_BOOT_CMD(
	base,    2,    1,     do_mem_base,
	"base    - print or set address offset\n",
	"\n    - print address offset for memory commands\n"
	"base off\n    - set address offset for memory commands to 'off'\n"
);

U_BOOT_CMD(
	loop,    3,    1,    do_mem_loop,
	"loop    - infinite loop on address range\n",
	"[.b, .w, .l] address number_of_objects\n"
	"    - loop on a set of addresses\n"
);

#ifdef CONFIG_LOOPW
U_BOOT_CMD(
	loopw,    4,    1,    do_mem_loopw,
	"loopw   - infinite write loop on address range\n",
	"[.b, .w, .l] address number_of_objects data_to_write\n"
	"    - loop on a set of addresses\n"
);
#endif /* CONFIG_LOOPW */


#ifdef CONFIG_MX_CYCLIC
U_BOOT_CMD(
	mdc,     4,     1,      do_mem_mdc,
	"mdc     - memory display cyclic\n",
	"[.b, .w, .l] address count delay(ms)\n    - memory display cyclic\n"
);

U_BOOT_CMD(
	mwc,     4,     1,      do_mem_mwc,
	"mwc     - memory write cyclic\n",
	"[.b, .w, .l] address value delay(ms)\n    - memory write cyclic\n"
);
#endif /* CONFIG_MX_CYCLIC */

#endif /* #ifndef COMPRESSED_UBOOT */
#define AR7240_DDR_SIZE_INCR    (4*1024*1024)

/*
 * Function Prototype
 */
int test_algorithm_t   (unsigned int mem_type, unsigned int pattern);

/*
 * Local Variables in this file
 */
static unsigned int init_state = 1;

static unsigned int TEST_SIZE;
static unsigned int START_M_ADDR, START_C_ADDR;
static unsigned int END_M_ADDR,   END_C_ADDR;

/* Test Patterns */
static unsigned int base_pattern[DATA_PATTERN_NUM];

/* Variables for random pattern */
static unsigned int dword_random_seed, dword_random_inc, hword_random_seed, hword_random_inc, byte_random_seed, byte_random_inc;

/* Variables for statistics */
static unsigned int curr_round;
static unsigned int fail_round, mt_fail_round, ct_fail_round;

/* Variables Per round */
static unsigned int fail_status, mt_fail_status, ct_fail_status;

/* Temporary Variables */
static unsigned int START_ADDR, END_ADDR;

int do_mem_mct (cmd_tbl_t *cmdtp, int flag, int argc, char *argv[])
{                                     
	unsigned char   *p = (unsigned char *)KSEG1, pat = 0x77;
	unsigned int    i;
	unsigned long	*size;
	
	if (argc > 1) {
		size = simple_strtoul(argv[1], NULL, 16);
	} 
	else {
		printf ("Usage:\n%s\n", cmdtp->usage);
		return -1;
	}
	
	/* Clean all information memory locations */
	for (i = 0; i < 0xb0; i+=4) {
		*(unsigned int *)(INFO_BASE_ADDR +i) = 0x0;
	}

    /* Determine the size of DDR/DDR2/SDRAM */
    *p = pat;

    /*
     * For x32 mode(2 DDR devices on board), Scorpion can support 2 128MB DDR and maximum memory size is 256MB(Wasp can support 2 64MB DDR and maximum memory size is 128MB).
     * In chip design, only 256MB address space can be used by DDR
     * Therefore, max. size of DDR is 256MB
     */
    for (i = 1; i < 64; i++) {
        *(p + i * AR7240_DDR_SIZE_INCR) = (unsigned char)(i);
        if (*p != pat) {
            break;
        }
    }
	
    TEST_SIZE    = size;
    START_M_ADDR = KSEG1 + 0x50000;
    END_M_ADDR   = START_M_ADDR + TEST_SIZE;
    START_C_ADDR = KSEG0 + 0x50000;
    END_C_ADDR   = START_C_ADDR + TEST_SIZE;

    /* Record general information */
    *(unsigned int *)(INFO_SIZE_ADDR)       = TEST_SIZE;
    *(unsigned int *)(INFO_MEM_START_ADDR)  = START_M_ADDR;
    *(unsigned int *)(INFO_MEM_END_ADDR)    = END_M_ADDR;
    *(unsigned int *)(INFO_CACHE_START_ADDR)= START_C_ADDR;
    *(unsigned int *)(INFO_CACHE_END_ADDR)  = END_C_ADDR;

    /* Initialize variables before test begins */
    curr_round = 0;
    fail_round = mt_fail_round = ct_fail_round = 0;

    for (i = 0; i < DATA_PATTERN_NUM; i++)
        base_pattern[i] = 0x0;

    /* Pattern 1 : Random     */
    /* Pattern 2 : Address    */
    /* Pattern 3 : 0xffffffff */
    base_pattern[0] = 1; /* Random  */
    base_pattern[1] = 2; /* Address */
    base_pattern[2] = 0xffffffff;

    /* Initialize variables for random pattern */
    dword_random_seed   = 0xa83f0365;
    dword_random_inc    = 0x185fe2d1;

    hword_random_seed   = 0x4f9516e3;
    hword_random_inc    = 0x143c2b7d;

    byte_random_seed    = 0xa83f0365;
    byte_random_inc     = 0x185fe2d1;
	
    while (1) {
        /* Initialize variables before current round begins */
        mt_fail_status = ct_fail_status = 0;

        *(unsigned int *)(INFO_MT_ADDR)    = 0;
        *(unsigned int *)(INFO_CT_ADDR)    = 0;

        curr_round++;

        printf("***Round %d***\n", curr_round);

        /* +++ MT    +++ */
        printf("2. Memory Test <MT>\n");
		
        *(unsigned int *)(INFO_MT_ADDR) = 1;

        for (i = 0; i < DATA_PATTERN_NUM; i++) {
            if (base_pattern[i] == 0x0)
                break;

            if (base_pattern[i] == 0x1) {
                if (!DISABLE_UART) {
                    printf("~Pattern 1 : Random(seed 0x%08x)\n", dword_random_seed);
                }
            }
            else if (base_pattern[i] == 0x2) {
                if (!DISABLE_UART) {
                    printf("~Pattern 2 : Address\n");
                }
            }
            else {
                if (!DISABLE_UART) {
                    printf("~Pattern %d : 0x%08x\n", i+1, base_pattern[i]);
                }
            }
            *(unsigned int *)(INFO_MT_PAT_ADDR) = i+1;

            if(test_algorithm_t(0, base_pattern[i]))
			return 1;
        }
        /* --- MT    --- */

        /* +++ CT    +++ */
        printf("4. Cache Test <CT>\n");
		
        *(unsigned int *)(INFO_CT_ADDR) = 1;

        for (i = 0; i < DATA_PATTERN_NUM; i++) {
            if (base_pattern[i] == 0x0)
                break;

            if (base_pattern[i] == 0x1) {
                printf("~Pattern 1 : Random(seed 0x%08x)\n", dword_random_seed);
            }
            else if (base_pattern[i] == 0x2) {
                printf("~Pattern 2 : Address\n");
            }
            else {
                printf("~Pattern %d : 0x%08x\n", i+1, base_pattern[i]);
            }

            *(unsigned int *)(INFO_CT_PAT_ADDR) = i+1;

            if(test_algorithm_t(1, base_pattern[i]))
			return 1;
        }
        /* --- CT    --- */

        /* Update Statistics*/
        *(unsigned int *)(INFO_GEN_ADDR) = curr_round;

        if (mt_fail_status || ct_fail_status) {
            if (mt_fail_status) {
                mt_fail_round++;
                *(unsigned int *)(INFO_FAIL_MT_ADDR) = mt_fail_round;
            }
            if (ct_fail_status) {
                ct_fail_round++;
                *(unsigned int *)(INFO_FAIL_CT_ADDR) = ct_fail_round;
            }
            fail_round++;
            *(unsigned int *)(INFO_FAIL_ADDR) = fail_round;
        }
	flush_cache(START_C_ADDR, TEST_SIZE);
    } /* End of while (1) */
}

/*
 * mem_type : 0 for memory, 1 for cache
 */
int test_algorithm_t(unsigned int mem_type, unsigned int pattern)
{
    unsigned int i;
    unsigned int stride, offset;
    unsigned int check_addr, check_data, check_pattern;
    unsigned int add_as_data;

    fail_status = 0;

    if (!mem_type) {
        START_ADDR = START_M_ADDR;
        END_ADDR   = END_M_ADDR;
    }
    else {
        START_ADDR = START_C_ADDR;
        END_ADDR   = END_C_ADDR;
    }

    if (pattern == 2) {
        add_as_data = 1;
        pattern     = 0;
    }
    else {
        add_as_data = 0;
        if (pattern == 1) {
            pattern = dword_random_seed;
        }
    }

    for (i = 0; i < TEST_SIZE; i += 4) {
        *(unsigned int *)(START_ADDR+i) = add_as_data ? (pattern ^ (START_ADDR + i)) : pattern;
    }

    for (stride = 4; stride < TEST_SIZE; stride *= 2) {
        for (offset = 0; offset < stride; offset += 4) {
            for (i = offset; i < TEST_SIZE; i += stride) {
		if (ctrlc()) {
			puts ("Stop MCT\n");
			return 1;
		}
                check_addr = START_ADDR + i;
                check_data = *(unsigned int *)check_addr;
                check_pattern = (add_as_data ? (pattern ^ check_addr) : pattern);

                if (check_data != check_pattern) {
                    if (!mem_type)
                        mt_fail_status = 1;
                    else
                        ct_fail_status = 1;

                    fail_status = 1;

                    *(unsigned int *)(INFO_ERROR_T_ADDR)         = 1;
                    *(unsigned int *)(INFO_ERROR_T_INVERSE_ADDR) = 0;
                    *(unsigned int *)(INFO_ERROR_T_STRIDE_ADDR)  = stride;
                    *(unsigned int *)(INFO_ERROR_T_OFFSET_ADDR)  = offset;
                    *(unsigned int *)(INFO_ERROR_T_ADR_ADDR)     = check_addr;
                    *(unsigned int *)(INFO_ERROR_T_DATA_ADDR)    = check_data;
                    *(unsigned int *)(INFO_ERROR_T_EDATA_ADDR)   = check_pattern;

                    printf("Fail! --> addr 0x%08x, data 0x%08x(should be 0x%08x), stride 0x%08x\n", check_addr, check_data, check_pattern, stride);
                    
                    #if DISCARD_ERROR
                    *(unsigned int *)check_addr = check_pattern;
                    #else
                    while (1) {
				if (ctrlc()) {
					puts ("Stop MCT\n");
					return 1;
				}
                    }   //asm("nop");
                    #endif
                }

                *(unsigned int *)check_addr = ~check_pattern;
            } /* End of "for (i = offset; i < TEST_SIZE; i += stride)" */
        } /* End of "for (offset = 0; offset < stride; offset += 4)" */

        pattern = ~pattern;

        for (offset = 0; offset < stride; offset += 4) {
            for (i = offset; i < TEST_SIZE; i += stride) {
                check_addr = START_ADDR + i; //check_addr = START_ADDR + TEST_SIZE - i - 4;
                check_pattern = (add_as_data ? (pattern ^ check_addr) : pattern);
                check_data = *(unsigned int *)check_addr;

                if (check_data != check_pattern) {
                    if (!mem_type)
                        mt_fail_status = 1;
                    else
                        ct_fail_status = 1;

                    fail_status = 1;

                    *(unsigned int *)(INFO_ERROR_T_ADDR)         = 1;
                    *(unsigned int *)(INFO_ERROR_T_INVERSE_ADDR) = 1;
                    *(unsigned int *)(INFO_ERROR_T_STRIDE_ADDR)  = stride;
                    *(unsigned int *)(INFO_ERROR_T_OFFSET_ADDR)  = offset;
                    *(unsigned int *)(INFO_ERROR_T_ADR_ADDR)     = check_addr;
                    *(unsigned int *)(INFO_ERROR_T_DATA_ADDR)    = check_data;
                    *(unsigned int *)(INFO_ERROR_T_EDATA_ADDR)   = check_pattern;

                    printf("Inverse Fail! --> addr 0x%08x, data 0x%08x(should be 0x%08x), stride 0x%08x\n", check_addr, check_data, check_pattern, stride);
                    
                    #if DISCARD_ERROR
                    *(unsigned int *)check_addr = check_pattern;
                    #else
                    while (1) {
				if (ctrlc()) {
					puts ("Stop MCT\n");
					return 1;
				}
                    }   //asm("nop");
                    #endif
                }
                *(unsigned int *)check_addr = ~check_pattern;
            } /* End if "for (i = offset; i < TEST_SIZE; i += stride)" */
        } /* End of "for (offset = 0; offset < stride; offset += 4)" */

        pattern = ~pattern;
    } /* End of "for (stride = 4; stride < TEST_SIZE; stride *= 2)" */

    if (!fail_status) {
        printf("Pass\n");
    }

    /* Random seed changes */
    dword_random_seed += 0x01010101;
    dword_random_seed += dword_random_inc;
	return 0;
}

/**************************************************/
U_BOOT_CMD(
	md,     3,     1,      do_mem_md,
	"md      - memory display\n",
	"[.b, .w, .l] address [# of objects]\n    - memory display\n"
);


U_BOOT_CMD(
	mm,     2,      1,       do_mem_mm,
	"mm      - memory modify (auto-incrementing)\n",
	"[.b, .w, .l] address\n" "    - memory modify, auto increment address\n"
);


U_BOOT_CMD(
	nm,     2,	    1,     	do_mem_nm,
	"nm      - memory modify (constant address)\n",
	"[.b, .w, .l] address\n    - memory modify, read and keep address\n"
);

U_BOOT_CMD(
	mw,    4,    1,     do_mem_mw,
	"mw      - memory write (fill)\n",
	"[.b, .w, .l] address value [count]\n    - write memory\n"
);

U_BOOT_CMD(
	mtest,    4,    1,     do_mem_mtest,
	"mtest   - simple RAM test\n",
	"[start [end [pattern]]]\n"
	"    - simple RAM read/write test\n"
);

U_BOOT_CMD(
	cp,    4,    1,    do_mem_cp,
	"cp      - memory copy\n",
	"[.b, .w, .l] source target count\n    - copy memory\n"
);

U_BOOT_CMD(
	mct,    2,    1,     do_mem_mct,
	"mct   - simple RAM test\n",
	"\n"
	"\n"
);

#endif	/* CFG_CMD_MEMORY */
