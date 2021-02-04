#
# This is a sample .s file, not a real command
#

# cmd
CMD= TestArray

# cmd parm
PARM_START:
UINT16:value:1:x:0
INT8:retCode8:1:d:-2
INT16:retCode16:1:d:-22
INT32:retCode32:1:d:23
INT8:status8:3:d:-2:8:-6
INT16:status16:3:d:-22:82:-62
INT32:status32:3:d:-22:28:-26
UINT8:macAdd:6:x:0x1:0x2:0x3:0xee:0xd:0x7e
UINT8:uint8:6:d:1:2:3:4:5:6
UINT16:uint16:5:d:2:33:11
UINT16:uint16x:10:x:2:33:11:aa:bb
UINT32:uint32:5:d:22:33:11:22:33
PARM_END:

# rsp
RSP= TestArrayRsp

# rsp parm
PARM_START:
UINT32:status:1:u:0
PARM_END:

