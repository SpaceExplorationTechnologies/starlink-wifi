#!/usr/bin/python

#***************************************************************************************************************
#  File Name : parse_dbglog_id.py
#  Description: 
#   python script to extract enums defined in a .h file and
#   output to .h file as a char array with enum vaiables defined as char array of
#   strings.
#  Input: i_filename, o_filename  values (must be changed inside the
#  script)
#  Output: a new file created under 'pwd' with o_filename and
#  o_wlan_mod_id. o_filename consists char array with stripped module_id
#  strings and 2D array of dbglog msgs.
#  o_wlan_mod_id consists of global module_ids as enum.
#                
#  Notes : Execute the script where the input file dbglog_id.h is
#  located.  
#  Version : 1.0
#  Author : srk
#  skomirel@qca.qualcomm.com
#
#***************************************************************************************************************

import os
import sys
import string
ALPHA = string.ascii_letters

# output for wlan module ids enum
dbglog_module_str = "/*\n * Copyright (c) 2011 Qualcomm Atheros, Inc.\n * All Rights Reserved.\n * Qualcomm Atheros Confidential and Proprietary.\n"
dbglog_module_str += " * $ATH_LICENSE_TARGET_C$\n */\n\n#ifndef _WLAN_MODULE_IDS_H_\n#define _WLAN_MODULE_IDS_H_\n\n"
dbglog_module_str += "/* Wlan module ids , global across all the modules (auto generated using parse_dbglog_id.py) */\n"
dbglog_module_str += "typedef enum {\n    WLAN_MODULE_ID_MIN = 0,"


# output of char array with stripped wlan module ids
dbglog_char_str = "char * dbglog_get_module_str[WLAN_MODULE_ID_MAX] = {\n"

indent = 12 # the i_filename should have the enums defined with this indentation value
i_filename = "dbglog_id.h"
o_filename = "dbglog_host_gen.h"
o_wlan_mod_id = "wlan_module_ids.h"
ids_data = ""


def blocks(i_filename):
    global ids_data
    global dbglog_char_str
    count=0
    title, block = '', None
    with open(i_filename) as fp:
        for line in fp:
            if 'typedef enum {' in line:
                #block = line
                block = "    {\n"
            elif block is not None:
                if '}' in line:
                    block += '    },'

                    # Also populate the wlan_module_ids
                    count += 1
                    line_ids = line
                    line_ids_s = line_ids.split("}")
                    ids = line_ids_s[1].strip()
                    ids = ids.strip(';')
                    if count == 1:
                        #ids_strip = ids.strip("_T")
                        ids_strip = ids[:-2]
                        ids_data += "\n    " + ids_strip + " = WLAN_MODULE_ID_MIN," 
                        ids_strip = ids_strip[indent:]
                        dbglog_char_str += "    \"" + ids_strip + "\",\n"
                        #print ids_strip
                    else:
                        #ids_strip = ids.strip("_T")
                        ids_strip = ids[:-2]
                        ids_data += "\n    " + ids_strip + ","
                        ids_strip = ids_strip[indent:]
                        dbglog_char_str += "    \"" + ids_strip + "\",\n"
                        #print ids_strip
                    #print line_ids_s
                    #print ids
                else:
                    if '=' in line:
                        #line_s = line.split(' ')
                        line_s = line.split('=')
                        #str = line_s[indent]
                        str = line_s[0].strip()
                        #print str
                        #block += '"{}"'.format('", "'.join(str))
                        block += "        \""+str+"\""+",\n"
                    else:
                        if '/*' in line: # check for comments
                            continue
                        else:
                            line_s = line.split(',')
                            str = line_s[0].strip()
                            #print str
                            block += "        \""+str+"\""+",\n"
            else:
                title = line
            if '}' in line:
                yield title, block
                title, block = '', None



if __name__ == "__main__" :


    data_block = "/* This file is auto generated, please do not change any contents */ \n\n"
    data_block += "char * DBG_MSG_ARR[WLAN_MODULE_ID_MAX][MAX_DBG_MSGS] =\n{\n"
    for title, block in blocks(i_filename):
        if block != None:
            if 'solid' not in block:
                #print "***********"
                data_block += block+"\n\n"
    data_block +="};" 
    dbglog_module_str += ids_data
    dbglog_module_str += "\n    WLAN_MODULE_ID_MAX,\n    WLAN_MODULE_ID_INVALID = WLAN_MODULE_ID_MAX,"
    dbglog_module_str += "\n} WLAN_MODULE_ID;\n"
    dbglog_module_str += "\n#endif /* _WLAN_MODULE_IDS_H_ */"
    dbglog_module_str += "\n"
    print dbglog_module_str

    dbglog_char_str += "};" 
    print dbglog_char_str

    f = open(o_filename, 'w')
    f.write(data_block)

    # write the wlan module ids char array
    f.write("\n\n")
    f.write(dbglog_char_str)
    f.close()


    f1 = open(o_wlan_mod_id, 'w')
    f1.write(dbglog_module_str)
    f1.close()
                                
    print "END"
