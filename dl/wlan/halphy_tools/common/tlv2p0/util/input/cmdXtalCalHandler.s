# cmd
CMD= XTALCALPROC

# cmd parm
PARM_START:
UINT8:capIn:1:u:45
UINT8:capOut:1:u:15
UINT8:ctrlFlag:1:u:0
UINT8:phyId:1:u:0
PARM_END:

# rsp
RSP= XTALCALPROCRSP

# rsp parm
PARM_START:
UINT8:status:1:u:0
UINT8:capValMin:1:u:0
UINT8:capValMax:1:u:0
UINT8:capIn:1:u:0
UINT8:capOut:1:u:0
UINT8:pllLocked:1:u:0
UINT8:phyId:1:u:0
PARM_END:


