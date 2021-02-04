# cmd
CMD= writeCustOtpSpace

# cmd parm
PARM_START:
UINT8:offsetAddr:1:u:0
UINT8:custData:24:u
UINT32:custDataSize:1:u:0
PARM_END:

# rsp
RSP= writeCustOtpSpaceRsp

# rsp parm
PARM_START:
UINT8:writeStatus:1:u:0
PARM_END:


