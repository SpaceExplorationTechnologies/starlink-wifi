# cmd
CMD= dpdAgc2Pwr

# cmd parm
PARM_START:
UINT8:phyId:1:u:0
PARM_END:

# rsp
RSP= dpdAgc2PwrRsp

# rsp parm
PARM_START:
UINT8:phyId:1:u:0
INT8:DPDAgc2Pwr:1:d:0
UINT8:status:1:u:0
PARM_END:


