#if !defined(_CMDOPCODES_H)
#define _CMDOPCODES_H

// command structure: cmdOpcode(1B) cmdNumParms(1B) parm1(6B)
//
// command opcodes
typedef enum {
    _OP_TEST_CONFIG = 255,
    _OP_SYNC = 0,               // 0
    _OP_TX,                     // 1
    _OP_RX,                     // 2
    _OP_CAL,                    // 3
    _OP_CAL_DONE,               // 4
    _OP_PM,			// 5
    _OP_GENERIC_RSP,		// 
    _OP_SUBMIT_REPORT_RSP,	// 
    _OP_GENERIC_NART_CMD,
    _OP_GENERIC_NART_RSP,
    _OP_TX_STATUS,
    _OP_RX_STATUS,
    // ADD NEW opCode HERE...
    _OP_TESTSCRIPT_LAST,        // basically the size of testscript I/F cmds

    _OP_REMAINING = _OP_TESTSCRIPT_LAST,
    _OP_SLEEP,
    _OP_RESET,

    _OP_MAX,
} _CMD_OPCODES;


#endif // #if !defined(_CMDOPCODES_H)
