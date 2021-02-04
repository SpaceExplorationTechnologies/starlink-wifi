#
# Set channel command
#

# cmd
SYSCMD= SetChannel

# cmd parm
PARM_START:
UINT8:phy_mask:1:u:0
UINT8:radio_mask:1:u:0
UINT8:crossing:1:u:0
UINT8:xconnection:1:u:0
UINT32:center_channel_R0:1:u:0
UINT32:center_channel_R1:1:u:0
UINT8:BW_R0:1:u:0
UINT8:BW_R1:1:u:0
UINT8:mode:1:u:0
UINT8:primary_location_R0:1:u:0
UINT8:primary_location_R1:1:u:0
UINT32:cal_mask:1:u:0
UINT32:force_cal_mask:1:u:0
PARM_END:

# rsp
SYSRSP= SetChannelRsp


# cmd parm
PARM_START:
UINT8:phy_mask:1:u:0
UINT8:radio_mask:1:u:0
UINT8:crossing:1:u:0
UINT8:xconnection:1:u:0
UINT32:center_channel_R0:1:u:0
UINT32:center_channel_R1:1:u:0
UINT8:BW_R0:1:u:0
UINT8:BW_R1:1:u:0
UINT8:mode:1:u:0
UINT8:primary_location_R0:1:u:0
UINT8:primary_location_R1:1:u:0
UINT32:cal_mask:1:u:0
UINT32:force_cal_mask:1:u:0
PARM_END: