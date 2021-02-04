/*
 * Please browse README_v1.txt for some background.
 * The main change is to auto-generate the cmdRspDict, and cmd/Rsp handlers.
 * The objective is to improve the user experience in TLV application.
 *
 * The user should only need to define the cmd/rsp and parameter "source file".
 * For example,
 * To add the TPC CAL cmd/rsp, here is the "source file", cmdRspCALHandler.s
 *
# cmd
CMD= TPCCal

# cmd parm
PARM_START:
UINT8:radioId:1:0
PARM_END:

# rsp
RSP= TPCCalRsp

# rsp parm
PARM_START:
UINT8:radioId:1:0
UINT8:numFreq2G:1:3
UINT8:freq2G:3:112:137:172
UINT8:numFreq5G:1:8
UINT8:freq5G:8:76:88:92:104:140:180:189:201
UINT8:numChain:1:2
UINT8:numCalPt:1:13
PARM_END:

 * A utility, genSrc4CmdRspDict and genCmdRspDict, will create cmdRspParmsDict.h and cmdRspParmsDict.c.
 * Another utility, genCmdRspHandler, will create the cmdCalHandler.c and .h
 *
 */
