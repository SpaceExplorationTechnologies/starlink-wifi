# cmd
CMD= LMQUERY

# cmd parm
PARM_START:
UINT8:lm_cmdId:1:u:0
UINT8:pad3:3:u
PARM_END:


# rsp
RSP= LMQUERYRsp

# rsp parm
PARM_START:
UINT8:status:1:u:0
UINT8:lm_cmdId:1:u:0
UINT8:pad2:2:u
PARM_END:
