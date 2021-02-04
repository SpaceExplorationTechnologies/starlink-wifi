# cmd
CMD= getDPDComplete

# cmd parm
PARM_START:
UINT8:phyId:1:u:0
PARM_END:

# rsp
RSP= getDPDCompleteRsp

# rsp parm
PARM_START:
UINT8:dpdComplete:1:u:0
UINT8:phyId:1:u:0
PARM_END:

