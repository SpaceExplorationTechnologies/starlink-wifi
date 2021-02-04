//-----------------------------------------------------------------------------

#include "tlv2Inc.h"
#include "parseBinCmdStream.h"
#include "utf.h"
#include "utfInternal.h"
#include "whalExtensionGeneric.h"
#include "testcmd.h"
#include "tlvCmdRspInternal.h"
#include "tlvCmdRsp.h"

// defines

// function prototypes
extern A_BOOL addTLV1p0BinCmdParser(void);

// globals & static
// 
// -------------------------------------------------------------
//
// #include "utfHostIFConfig.h"  // auto-generated host interface config
#if 0  // thought about support of multiple chips or host I/F?
#define enum {
    HOSTIF_SDIO = 0,
    HOSTIF_TESTSCRIPT,
    HOSTIF_WMI,
    HOSTIF_SPI,
    HOSTIF_HOSTLESS,

    HOSTIF_LAST,
    HOSTIF_MAX = HOSTIF_LAST,
} _HOSTIF_CONFIG_TYPE;

typedef void (*pRegHostIF)(void);
extern void rawHTCIFRegister(void);
pRegHostIF HostIFRegFunc[HOSTIF_MAX] = {
    rawHTCIFRegister,
    NULL,
    NULL,
    NULL,
    NULL,
};
// #include "utfHostIFConfig.h"  // auto-generated host interface config
//
// -------------------------------------------------------------
//
// #include "chipConfig.h"  // auto-generated chip config 
//
#define enum {
    WIFI_CHIP=0,
    BT_CHIP,
    GPS_CHIP,
    FM_CHIP,

    LAST_CHIP,
    CHIP_MAX = LAST_CHIP,
} _CHIP_CONFIG_TYPE;

typedef void (*pRegChip)(void);
extern void wifiRegister(void);
pRegChip ChipRegFunc[CHIP_MAX] = {
    wifiRegister,
    NULL,
    NULL,
    NULL,
};
//
// #include "chipConfig.h"  // auto-generated chip config 
//
// -------------------------------------------------------------
#endif

SRAM_DATA
_CHIP_SPECIFIC_FUNC ChipFunc = {
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
};

SRAM_DATA
_HOSTIF_INFO HostIF = {
    NULL,  // hostIFAttach
    NULL,  // hostIFCmdStreamFetch
    NULL,  // hostIFProcessing
};

SRAM_TEXT
void bindHostIFFunc(_HOSTIF_INFO *hostFunc) {
    HostIF.hostIFAttach = hostFunc->hostIFAttach;
    HostIF.hostIFCmdStreamFetch = hostFunc->hostIFCmdStreamFetch;
    HostIF.hostIFProcessing = hostFunc->hostIFProcessing;
    return;
}

SRAM_TEXT
void bindChipSpecificFunc(_CHIP_SPECIFIC_FUNC *fns)
{
    ChipFunc.chipAttach = fns->chipAttach;
    ChipFunc.txFunc = fns->txFunc;
    ChipFunc.genCalData = fns->genCalData;
    ChipFunc.applyCalData = fns->genCalData;
    ChipFunc.genRxGainCalData = fns->genRxGainCalData;

    return;
}

SRAM_DATA
_VALUES_OF_INTEREST ValuesOfInterest;

//
// Architectural notes:
//    For callback triggered host I/F, such as rawHTC IF
//    call this function in that callback function.
//
SRAM_TEXT
A_INT32 hostIFProcessing(A_UINT8 *buf)
{
    //A_UINT8 cmdStreamBuf[CMD_PAYLOAD_LEN_MAX];  // 10312010 untested
    A_UINT32 cmdStreamLen;
    //A_UINT8 *pCmdStream = cmdStreamBuf;
    A_UINT8 *pCmdStream;  // 10312010 untested
    A_UINT8 *pPayload;
    A_UINT16 payloadLen;

    if (HostIF.hostIFCmdStreamFetch != NULL) {
        (HostIF.hostIFCmdStreamFetch)(buf, &pCmdStream, &cmdStreamLen);

        if (cmdStreamLen) {
        // parse the cmd stream by calling the standard parsingAnd Processing function
        cmdStreamParsingAndProcessing(pCmdStream, cmdStreamLen, &pPayload, &payloadLen);
        A_PRINTF("ThermValueEnd = %d\n", ValuesOfInterest.thermCAL);
        }

    }

    return(0);
}

//
// Architectural Note:
//   all host interface specific function needs to call this function with cmdStream and length
//
//   HostIF.hostIFProcessing(void) {
//      // host IF specific cmdStream fetch
//      // e.g. rawHTC, through call back htcRecvDone/htcReadCmd
//      //      testScript, by reading a memory location
//      // Outcome of this step is the cmdStreamBuf and cmdStreamLen
//      hostIFCmdStreamFetch(A_UINT8 **cmdStreamBuf, A_UINT32 *cmdStreamLen);
//
//      // parse the cmd stream by calling the standard parsingAnd Processing function
//      cmdStreamParsingAndProcessing(A_UINT8 *cmdStreamBuf, A_UINT32 cmdStreamLen)
//
//  If the host IF is the callback type like HTC, the HostIF.hostIFProcessing will be NULL,
//  but the actual function will be embedded in the callback.
//
//  pPayload and length are here for bypass, for example.
//
extern void cmdProcessingEntry(void);
extern void rxSyncNotifySim(void);
extern void rxNotify(void);

SRAM_TEXT
void utf_main(void)
{
    // display our startup message
    //printVersion();

    // setup: test configuration ----------
    // bind chip specific functions
    registerOneChip();

    // host I/F specific functions
    registerOneHostIF();

    // main firmware body
    utfMain();

    // attach the chip
    if (NULL != ChipFunc.chipAttach) {
        (ChipFunc.chipAttach)();
    }
 
    // host interface, cmd buf ------------
    // attach host I/F
    // For legacy mode of ART/tcmd, once host IF attached, the HTC callback takes over
    //   the 
    if (NULL != HostIF.hostIFAttach) {
        (HostIF.hostIFAttach)();
    }

#define  _START_RIGHT_AWAY
#if defined(_START_RIGHT_AWAY)
    // give it to the host i/f processing "thread"
    //hostIFProcessing(NULL);
    if (HostIF.hostIFProcessing != NULL) {
        (HostIF.hostIFProcessing)(NULL);
    }
#endif

    // UTF configuration
    addTLV1p0BinCmdParser();
    addTLV2p0BinCmdParser();
    addTLV2p0Encoder(); 
extern void fakeFetchCmdStream(A_UINT8 *buf, A_UINT8 **pCmdStream, A_UINT32 *cmdStreamLen);
    bindFetchCmdStream(fakeFetchCmdStream);

    // all done
    return;

}

#ifdef CONFIG_SMART_LOGGING
/* Temp stubs */
void _wmi_deliver_fatal_event(A_UINT32 num_errors, A_UINT8 *type_list, A_UINT8 *subtype_list, A_UINT32 *type_subtype_specific_data_list) {}
void _wmi_store_fatal_log(A_UINT8 type, A_UINT8 subtype, A_UINT32 type_subtype_specific_data) {}
void _wmi_deliver_fatal_single_event(A_UINT8 type, A_UINT8 subtype, A_UINT32 type_subtype_specific_data) {}
#endif /* CONFIG_SMART_LOGGING */
