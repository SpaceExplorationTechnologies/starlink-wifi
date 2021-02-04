# cmd
CMD= dpdLoopbackAttn

# cmd parm
PARM_START:
UINT8:phyId:1:u:0
INT8:DPDLoopbackAttn:1:d:0
UINT8:glutIdx:1:u:0
PARM_END:

# rsp
RSP= dpdLoopbackAttnRsp

# rsp parm
PARM_START:
UINT8:phyId:1:u:0
UINT8:status:1:u:0
PARM_END:


