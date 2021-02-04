# cmd
CMD= LMHWCAL

# cmd parm
PARM_START:
UINT8:phyId:1:u:0
UINT8:lm_resvd0:3:u
UINT16:lm_freq:36:u:2412:65535
UINT16:lm_freq2:36:u:2412:65535
UINT8:lm_chainMask:36:x:0x1f
UINT32:wlanModeMask:36:x:0x1
UINT32:wlanModeMaskExt:36:x
UINT8:lm_bandwidth:36:u
PARM_END:
