#include <stdio.h>
#include "osapi.h"
#include "wlantype.h"
//#include "ar6000defs.h"
#include "utf.h"
#include "cmdRspParmsDict.h"
#include "cmdRspParmsInternal.h"
#include "cmdTPCCALHandler.h"
#include "cmdTPCCALPWRHandler.h"
#include "tpcCal.h"

extern void ar900BGenCalData4BrdData(void);
extern void ar900BApplyCalDataFromBrdData(void);
extern void ar900BGenRxGainCalData4BrdData(void);


SRAM_TEXT
void registerOneChip(void)
{
#if 1
    _CHIP_SPECIFIC_FUNC ar900BChipFunc={
        NULL, // attach
        NULL, // tx
        ar900BGenCalData4BrdData, // generate BrdCalData
        ar900BApplyCalDataFromBrdData, // apply BrdCalData
	ar900BGenRxGainCalData4BrdData,   // generate rxGainCal BrdCalData
    };
    bindChipSpecificFunc(&ar900BChipFunc);
#endif
    //A_PRINTF("..AR6320\n");
    return;
}

