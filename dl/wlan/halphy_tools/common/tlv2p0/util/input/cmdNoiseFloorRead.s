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
CMD= NOISEFLOORREAD

# cmd parm
PARM_START:
UINT16:freq:1:u:2412 
UINT16:chainMask:1:x:0x3
UINT8:phyId:1:u:0
PARM_END:

# rsp
RSP= NOISEFLOORREADRSP

# rsp parm
PARM_START:
UINT32:nfValues:16:u:0
UINT8:phyId:1:u:0
PARM_END:

 * A utility, genSrc4CmdRspDict and genCmdRspDict, will create cmdRspParmsDict.h and cmdRspParmsDict.c.
 * Another utility, genCmdRspHandler, will create the cmdCalHandler.c and .h
 *
 */

