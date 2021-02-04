#
# Generic command to drive a simple manufacturing cal, or extract info from FW
#

# cmd
CMD= GenericUtfCmd

# cmd parm
PARM_START:
UINT32:Measurement:1:u:0
INT32:inParams:32:d
UINT16:GenericUtfCmdID:1:u:0
UINT8:phyId:1:u:0
PARM_END:

# rsp
RSP= GenericUtfCmdRsp

# rsp parm
PARM_START:
UINT8:GenericUtfCmdDone:1:u:0
UINT8:NumGenericUtfCmdRetData:1:u:0
UINT16:GenericUtfCmdStatus:1:u:0
INT32:GenericUtfCmdRetData:32:d
UINT8:phyId:1:u:0
PARM_END:

