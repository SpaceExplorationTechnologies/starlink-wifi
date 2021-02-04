# cmd
CMD= LMGO

# cmd parm
PARM_START:
UINT8:lm_cmdId:1:u:0
UINT8:pad3:3:u
UINT16:timeOn:1:u:800
UINT16:timeOff:1:u:800
PARM_END:


# rsp
RSP= LMGORsp

# rsp parm
PARM_START:
UINT8:lm_cmdId:1:u:0
UINT8:status:1:u:0
UINT8:pad2:2:u
UINT16:timeOn:1:u:800
UINT16:timeOff:1:u:800
PARM_END:
