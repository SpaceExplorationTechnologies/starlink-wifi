#
# This is a sample .s file, not a real command
#

# cmd
SYSCMD= TestData

# cmd parm
PARM_START:
DATA1024:data1:1024:x
DATA1024:data2:1024:x
DATA1024:data3:1024:x
DATA1024:data4:1024:x
PARM_END:

# rsp
SYSRSP= TestDataRsp

# rsp parm
PARM_START:
UINT32:status32:1:u:0
DATA1024:data1:1024:x
DATA1024:data2:1024:x
DATA1024:data3:1024:x
DATA1024:data4:1024:x
PARM_END:

