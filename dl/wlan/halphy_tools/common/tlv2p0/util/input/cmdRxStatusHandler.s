# cmd
CMD= RXStatus

# cmd parm
PARM_START:
UINT8:phyId:1:u:0
UINT8:stopRx:1:u:0
UINT16:freq:1:u:2412
UINT16:freq2:1:u:2412
PARM_END:

# rsp
RSP= RXStatusRsp

# rsp parm
PARM_START:
UINT8:phyId:1:u:0
UINT8:numOfReports:1:u:0
UINT8:pad2:2:u:0:0
UINT32:totalPackets:1:u:0
UINT32:goodPackets:1:u:0
UINT32:otherError:1:u:0
UINT32:crcPackets:1:u:0
UINT32:decrypErrors:1:u:0
UINT32:rateBit:1:u:0
UINT32:startTime:1:u:0
UINT32:endTime:1:u:0
UINT32:byteCount:1:u:0
UINT32:dontCount:1:u:0
INT32:rssi:1:d:0
INT32:rssic:4:d:0:0:0:0
INT32:rssie:4:d:0:0:0:0
INT32:badrssi:1:d:0
INT32:badrssic:4:d:0:0:0:0
INT32:badrssie:4:d:0:0:0:0
INT32:evm:4:d:0:0:0:0
INT32:badevm:4:d:0:0:0:0
PARM_END:
