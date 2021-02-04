# cmd
CMD= MemWrite

# cmd parm
PARM_START:
UINT32:memaddress:1:x:0
UINT8:numbytes:1:u:0
UINT8:memvalue:255:x:0
UINT8:valuetype:1:u:1
PARM_END:

# rsp
RSP= MemWriteRsp

# rsp parm
PARM_START:
UINT32:memaddress:1:x:0
UINT8:numbytes:1:u:0
UINT8:valuetype:1:u:1
UINT8:status:1:u:0
PARM_END:

