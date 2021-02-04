/* +++ Start of Common Definitions (Applied to both ASIC and FPGA emulation) +++ */ 
#define CONFIG_AR7240 1
/* --- End   of Common Definitions (Applied to both ASIC and FPGA emulation)--- */

/*********************************************
 * SRAM image build option                   *
 * 1 for ASIC, 0 for FPGA emulation          *
 *********************************************/ 
#define FORMAL_SRAM_RELEASE_BUILD    0

#if !FORMAL_SRAM_RELEASE_BUILD 
/* +++ Start of FPGA Emulation Definitions (Applied to FPGA emulation) +++ */ 
/* For all FPGA emulation bit files including that for WLAN */
#define CONFIG_HORNET_EMU 1

/* For WLAN FPGA emulation bit file only (For other FPGA FPGA emulation bit files, this definition should be commented out) */
//#define CONFIG_HORNET_EMU_HARDI_WLAN 1
/* --- End   of FPGA Emulation Definitions (Applied to FPGA emulation) --- */ 
#endif /* !FORMAL_SRAM_RELEASE_BUILD */
