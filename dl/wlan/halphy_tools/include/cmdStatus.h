#ifndef	 _CMD_STATUS_H_
#define	 _CMD_STATUS_H_


// Error/status codes for commands sent back to host 
#define CMD_OK                                  0x0
#define COMMS_ERR_BAD_LENGTH                    0x1
#define BAD_LENGTH_MSG "Length of command received from dk_perl does not match expected length for CmdID\n"
#define COMMS_ERR_DEV_INIT_FAIL                 0x2
#define DEV_INIT_FAIL_MSG "There was a failure in dk_c, somewhere in deviceInit() function\n"
#define	COMMS_ERR_INDEX_TOO_LARGE               0x3
#define INDEX_TOO_LARGE_MSG "Not able to create any more devInfo structures in dk_c. Too many F2's in system?\n"
#define COMMS_ERR_BAD_OFFSET                    0x4
#define BAD_OFFSET_MSG "An invalid offset was given for a register access\n"
#define COMMS_ERR_REGS_NOT_MAPPED               0x5
#define REGS_NOT_MAPPED_MSG "F2 registers have not been mapped in dk_c\n"
#define COMMS_ERR_NO_F2_TO_SELECT               0x6
#define NO_F2_TO_SELECT_MSG "Error in dk_c, incorrect F2 number specified in select_hw cmd\n"
#define COMMS_ERR_BAD_CFG_SIZE                  0x7
#define BAD_CFG_SIZE_MSG "Illegal PCI config access size sent to dk_c, must be 8, 16 or 32\n"
#define COMMS_ERR_ALLOC_FAIL                    0x8
#define ALLOC_FAIL_MSG "Unable to allocate memory in dk_c\n"
#define COMMS_ERR_BAD_MEM_SIZE                  0x9
#define BAD_MEM_SIZE_MSG "Illegal memory access size sent to dk_c, must be 8, 16 or 32\n"
#define COMMS_ERR_WRITE_BLOCK_FAIL              0xa
#define WRITE_BLOCK_FAIL_MSG "Failed in call to hwMemWriteBlock()\n"
#define COMMS_ERR_READ_BLOCK_FAIL               0xb
#define READ_BLOCK_FAIL_MSG "Failed in call to hwMemReadBlock()\n"
#define COMMS_ERR_REMAP_FAIL                    0xc
#define REMAP_FAIL_MSG "Failed in the call to hwRemapHardware()\n"
#define COMMS_ERR_EVENT_CREATE_FAIL             0xd
#define EVENT_CREATE_FAIL_MSG "Failed in call to hwCreateEvent()\n"
#define COMMS_ERR_NO_EVENTS                     0xe
#define NO_EVENTS_MSG "Triggered Q has not events to get\n"
#define COMMS_BAD_STAT_ID                       0xf
#define BAD_STAT_ID_MSG "Illegal statID, use get_all_stats cmds\n"
#define COMMS_ERR_EVENT_ENABLE_FEATURE_FAIL     0x10
#define COMMS_ERR_EVENT_DISABLE_FEATURE_FAIL    0x11
#define COMMS_ERR_MDK_ERROR                     0x12
#define MDK_ERROR_MSG "MDK Error: Check the mdkerrno"
#define COMMS_ERROR_FTPDOWNLOAD_FAIL            0x20

#define COMMS_ERROR_TLV_GET_PARAM_FAIL	        0x30
#define TLV_GET_PARAM_FAIL_MSG "TLV getParams failed\n"
#define CMD_TLV_MORE_SEGMENT                    0x32
#define TLV_MORE_SEGMENT_MSG   "TLV more segment needed\n"

#define CMD_TX_ERROR								0x3e
#define CMD_RX_ERROR								0x3f
#define CMD_HWCAL_ERROR_NOT_SUPPORTED				0x40
#define CMD_HWCAL_ERROR_FULL_WHAL_RESET_CAL			0x41
#define CMD_HWCAL_ERROR_WHAL_RESET_PART_1 			0x42
#define CMD_HWCAL_ERROR_RXDCO						0x43
#define CMD_HWCAL_ERROR_RXFILT						0x44
#define CMD_HWCAL_ERROR_RXIQ						0x45
#define CMD_HWCAL_ERROR_TXIQ						0x46
#define CMD_HWCAL_ERROR_TXCL						0x47
#define CMD_HWCAL_ERROR_PKDET						0x48

// Command status 32 bits 
// Lower 16 bits gives the Error Number.
// Upper 16 bits contains some more information for that Error.
#define COMMS_ERR_MASK                              0xffff
#define COMMS_ERR_SHIFT                             0
#define COMMS_ERR_INFO_MASK                         0xffff0000
#define COMMS_ERR_INFO_SHIFT                        16


#endif //_CMD_STATUS_H_
