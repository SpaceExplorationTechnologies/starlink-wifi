# cmd
CMD= LMRXINIT

# cmd parm
PARM_START:
UINT8:rxMode:1:u:0
UINT8:bandwidth:1:u:0              
UINT8:antenna:1:u:0
UINT8:enANI:1:u:0
UINT8:ack:1:u:1
UINT8:broadcast:1:u:0
UINT8:lpl:1:u:0
UINT8:antswitch1:1:u:0
UINT8:antswitch2:1:u:0
UINT8:pad3:3:u
UINT16:spectralScan:1:u:0
INT16:noiseFloor:1:d:0
UINT16:regDmn:2:x:0x00:0x00    
UINT32:expectedPkts:1:u:1
UINT32:otpWriteFlag:1:x:0  
UINT32:flags:1:x:0
UINT8:bssid:6:x:0x01:0x00:0x00:0xCA:0xFF:0xEE
UINT8:staAddr:6:x:0x00:0x03:0x7F:0x11:0x12:0x13
UINT8:btAddr:6:x:0x00:0x00:0x00:0x00:0x00:0x00
PARM_END:

# rsp
RSP= LMRXINITRsp

# rsp parm
PARM_START:
# cmd parm
PARM_START:
UINT16:cmdId:1:u:0
UINT8:status:1:u:0
UINT8:pad1:1:u
PARM_END:


