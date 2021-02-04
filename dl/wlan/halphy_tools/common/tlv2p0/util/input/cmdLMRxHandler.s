# cmd
CMD= LMRX

# cmd parm
PARM_START:
UINT8:phyId:1:u:0
UINT8:rxMode:1:u:1
UINT8:lm_resvd1:2:u
UINT16:lm_freq:36:u:2412:65535
UINT16:lm_freq2:36:u:2412:65535
UINT8:lm_chainMask:36:x:0x1f
UINT32:wlanModeMask:36:x:0x1
UINT32:wlanModeMaskExt:36:x
UINT8:lm_bandwidth:36:u
UINT8:antenna:1:u:0
UINT8:enANI:1:u:0
UINT8:ack:1:u:1
UINT8:broadcast:1:u:0
UINT8:lpl:1:u:0
UINT8:antswitch1:1:u:0
UINT8:antswitch2:1:u:0
UINT8:lm_resvd0:1:u:0
UINT16:spectralScan:1:u:0
INT16:noiseFloor:1:d:0
UINT16:regDmn:2:x
UINT32:expectedPkts:1:u:1
UINT32:otpWriteFlag:1:x:0
UINT32:flags:1:x:0
UINT32:rateMask:3:x:0x00008000:0:0
UINT32:rateMask11AC:5:x
UINT32:rateMaskAC160:1:x:0
UINT8:bssid:6:x:0x01:0x00:0x00:0xCA:0xFF:0xEE
UINT8:staAddr:6:x:0x00:0x03:0x7F:0x11:0x12:0x13
UINT8:btAddr:6:x
UINT8:pad2:2:u
PARM_END:
