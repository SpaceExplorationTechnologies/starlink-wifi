# cmd
CMD= TXStatus

# cmd parm
PARM_START:
UINT8:phyId:1:u:0
UINT8:stopTx:1:u:1
UINT8:needReport:1:u:1
PARM_END:

# rsp
RSP= TXStatusRsp

# rsp parm
PARM_START:
UINT8:phyId:1:u:0
UINT8:status:1:u:0
UINT8:numOfReports:1:u:0
UINT8:thermCal:1:u:0
UINT8:pdadc:1:u:0
UINT8:paCfg:1:u:0
UINT8:gainIdx:1:u:15
INT8:dacGain:1:d:0
UINT32:totalPackets:1:u:0
UINT32:goodPackets:1:u:0
UINT32:underruns:1:u:0
UINT32:otherError:1:u:0
UINT32:excessRetries:1:u:0
UINT32:rateBit:1:u:0
UINT32:shortRetry:1:u:0
UINT32:longRetry:1:u:0
UINT32:startTime:1:u:0
UINT32:endTime:1:u:0
UINT32:byteCount:1:u:0
UINT32:dontCount:1:u:0
INT32:rssi:1:d:0
INT32:rssic:4:d:0:0:0:0
INT32:rssie:4:d:0:0:0:0
PARM_END:

