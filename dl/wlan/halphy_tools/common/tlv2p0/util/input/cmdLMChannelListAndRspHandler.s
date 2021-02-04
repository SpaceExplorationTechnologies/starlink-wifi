# cmd
CMD= LMCHANNELLIST

# cmd parm
PARM_START:
UINT8:lm_flag:1:x:0x01
UINT8:lm_itemNum:1:u:1
UINT8:pad2:2:u
UINT8:lm_cbState:100:u
UINT8:lm_chainMask:100:x:0x01:repeat:99:1:0x0
UINT8:lm_txPower:100:u:22:repeat:99:1:0
UINT8:lm_phyId:100:u
UINT16:lm_freq:100:u:2412:repeat:99:1:0
UINT16:lm_freq2:100:u:2412:repeat:99:1:0
UINT16:lm_rateIndex:100:u:11:repeat:99:1:0
PARM_END:


# rsp
RSP= LMCHANNELLISTRsp

# rsp parm
PARM_START:
UINT8:status:1:u:1
UINT8:totalHWCalNum:1:u:1
UINT16:totalItemNum:1:u:1
UINT16:hwCalTime:1:u:600
UINT8:pad2:2:u
PARM_END:
