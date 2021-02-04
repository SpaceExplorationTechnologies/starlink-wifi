# cmd
CMD= LMTXINIT

# cmd parm
PARM_START:
UINT8:txMode:1:u:2
UINT8:bandwidth:1:u:0
UINT8:gI:1:u:0
UINT8:antenna:1:u:0
UINT8:enANI:1:u:0
UINT8:scramblerOff:1:u:0
UINT8:aifsn:1:u:0
UINT8:broadcast:1:u:0
UINT8:agg:1:u:1
UINT8:shortGuard:1:u:0
UINT8:dutyCycle:1:u:0
UINT8:nPattern:1:u:0
UINT8:tpcm:1:u:0
UINT8:gainIdx:1:u:15
INT8:dacGain:1:d:0
INT8:dacGainEnd:1:d:0
INT8:dacGainStep:1:d:0
UINT8:paConfig:1:u:0
UINT8:paConfigEnd:1:u:0
UINT8:paConfigStep:1:u:1
UINT8:dataPattern:40:u
UINT8:bssid:6:x:0x01:0x00:0x00:0xCA:0xFF:0xEE
UINT8:txStation:6:x:0x00:0x03:0x7F:0x03:0x40:0x33
UINT8:rxStation:6:x:0xff:0xff:0xff:0xff:0xff:0xff
UINT8:pad2:2:u
UINT16:txNumPackets:1:u:0
UINT16:txPattern:1:u:0
UINT32:flags:1:x:0
UINT32:ir:1:u:0
UINT32:pktSz:1:u:0
PARM_END:

# rsp
RSP= LMTXINITRsp
# cmd parm
PARM_START:
UINT16:cmdId:1:u:0
UINT8:status:1:u:0
UINT8:pad1:1:u
PARM_END:
