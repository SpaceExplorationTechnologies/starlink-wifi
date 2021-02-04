# cmd
CMD= setPcieConfigParams

# cmd parm
PARM_START:
UINT32:pcieAddr:1:u:0
UINT32:pcieValue:1:u:0
UINT8:operation:1:u:0
UINT32:size:1:u:0
PARM_END:

# rsp
RSP= setPcieConfigParamsRsp

# rsp parm
PARM_START:
PARM_END:


