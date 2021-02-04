#if !defined(__CMD_RSP_PARMS_INTERNAL_H)
#define __CMD_RSP_PARMS_INTERNAL_H

#define _STATIC static

// Notes:
// Parm offset fields and table, used to overwrite values of a parm struct
typedef struct parm_offset_fields_struct {
    A_UINT32  parmCode;
    A_UINT32  offset;
    struct parm_offset_fields_struct *next;
} PARM_OFFSET_FIELDS;

typedef struct parm_offset_tbl_struct {
    struct parm_offset_fields_struct *pt;
} PARM_OFFSET_TBL;


// cmd/rsp stream defines
// ----------------------
// Note the cmdStream header v2 is a shorter version of version 1 (TS based)

typedef struct   parmArray {
            A_UINT32  numElem;
            A_UINT32  startPos;
            A_UINT32  arrayAddr;
} __ATTRIB_PACK  PARM_ARRAY;

typedef struct parmOneOf {
    A_UINT32     parmCode;
    A_UINT32     parmRand;
    union {
        A_UINT32   parmVal;
        PARM_ARRAY parmArr;
    } v;
} __ATTRIB_PACK  PARM_ONEOF;
#define PARM_ONEOF_SIZE_V2          sizeof(struct parmOneOf)  // decided to keep it the same as V1
#ifdef PARM_ONEOF_SIZE
#undef PARM_ONEOF_SIZE
#endif 
#define PARM_ONEOF_SIZE             PARM_ONEOF_SIZE_V2

// one cmd -----------
// command structure: cmdOpcode(1B) numOfParms(1B) parm1(8B) ... parmN(8B)
typedef struct oneCmdHeader {
    A_UINT32     opCode;
    A_UINT32     rand;
    A_UINT32     numOfParms;
} __ATTRIB_PACK ONE_CMD_HEADER;

#include "cmdStreamCommon.h"

#define TESTFLOW_CMD_STREAM_HEADER_V2 _TESTFLOW_CMD_STREAM_HEADER 
#define TESTFLOW_CMD_STREAM_V2        _TESTFLOW_CMD_STREAM

// cmdRspParmsDict defines
// -----------------------
// Command list, indexed by command code
typedef struct _cmd_dict_struct {
    A_UINT32    rand;
} CMD_DICT;
extern CMD_DICT CmdDict[];
extern int MaxCmdDictEntries; 

// Parameter list, indexed by parameter code
#define MAX_KEY_STRING                 6
#define DATATYPE_ARRAY_MASK            0x01
#define DATATYPE_DATA_MASK             0x02
#define DATATYPE_IS_ARRAY(x)           ((x) & DATATYPE_ARRAY_MASK)
#define DATATYPE_IS_DATA(x)            ((x) & DATATYPE_DATA_MASK)
#define DATATYPE_TYPE(x)               (((x) >> 4) & 0x0F)
#define FREQ2BYTE(freq, is2G)          ((is2G) ? ((freq) - 2300) : (((freq) - 4800) / 5))
#define FREQ2BYTE_2G(freq)             ((freq) - 2300)
#define FREQ2BYTE_5G(freq)             (((freq) - 4800) / 5)
#define BYTE2FREQ(byte, is2G)          ((is2G) ? ((byte) + 2300) : (((byte) * 5) + 4800))
#define BYTE2FREQ_2G(byte)             ((byte) + 2300)
#define BYTE2FREQ_5G(byte)             (((byte) * 5) + 4800)
typedef struct _parm_dict_struct {
    A_UINT32      rand;                      // 4B
    union {
        A_UINTL   valUL;
        A_UINT32  valU32;
        A_INT32   valS32;
        A_UINT16  valU16;
        A_INT16   valS16;
        A_UINT8   valU8;
        A_INT8    valS8;
        A_UINT32  *ptU32;
        A_INT32   *ptS32;
        A_UINT16  *ptU16;
        A_INT16   *ptS16;
        A_UINT8   *ptU8;
        A_INT8    *ptS8;
        char      *ptChar;
    } v;                                     // 4B
    //char          key[MAX_KEY_STRING +1];    
    A_UINT8       keyHash;                   // 1B
    A_UINT8       dataType;                  // 1B
} PARM_DICT;

extern PARM_DICT ParmDict[];
extern int MaxParmDictEntries; 

// -----------------------
// sysCmdRspParmsDict defines
// -----------------------


extern CMD_DICT SysCmdDict[];
extern int MaxSysCmdDictEntries; 

extern PARM_DICT SysParmDict[];
extern int MaxSysParmDictEntries; 


// called at the beginning to populate the ParmDict
extern void populateKeyHashs(void);

// Parameter offset table
//   1. Generated per command during runtime to save memory, 
//      intead of a template for every TLV cmd/parm struct.
//   2. The index into the offset table is a hash generated from parameter keys
//  
#define KEY_HASH_RANGE       36
#define KEY_HASH(str)        (SDBMHash((str), strlen((str))) % KEY_HASH_RANGE)

#define MAX_PARM_NUM         64

// Command handler defines

typedef struct cmdHandlerTbl {
    void*  (*initParms)(A_UINT8 *pParmsCommon, PARM_OFFSET_TBL *pParmsOffset, PARM_DICT *pParmDict);
    A_BOOL (*cmdProcessing)(void* pParms);
    A_BOOL (*rspGeneration)(A_UINT32 cmdCode, void* pParms);
} CMD_HANDLER_ENTRY;
extern CMD_HANDLER_ENTRY CmdHandlerTbl[];
extern A_UINT32 MaxCmdHandlers;

extern CMD_HANDLER_ENTRY SysCmdHandlerTbl[];
extern A_UINT32 MaxSysCmdHandlers;

// Func protytpes
void fillParmOffsetTbl(A_UINT32 parmCode, A_UINT32 offset, PARM_OFFSET_TBL *pParmsOffset);
void resetParmOffsetFields(void);


// for .s file
#define MAX_DATATYPE_LEN  64
#define MAX_VALUE_LEN     32
typedef struct {
    A_UINT32      rand;                      
    char          v[MAX_VALUE_LEN];
    A_UINT32      keyHash;                  
    char          dataType[MAX_DATATYPE_LEN];
} PARM_DICT_S;

// for cmdRspParmsDict.h

// Notes:
// 
// Used in cmdRspParmsDict.c
// -------------------------
#define DATATYPE(basicType, array)     ((((basicType) << 4) & 0xF0) | ((array) & 0x0F))
#define FREQ2BYTE(freq, is2G)          ((is2G) ? ((freq) - 2300) : (((freq) - 4800) / 5))
#define FREQ2BYTE_2G(freq)             ((freq) - 2300)
#define FREQ2BYTE_5G(freq)             (((freq) - 4800) / 5)

// requirements for paramter data types
// All parameter are 4B when transit in the pipe
typedef enum {
    TYPE_SINGULAR = 0,
    TYPE_ARRAY    = 1,
    TYPE_DATA     = 2,  // binary data stream

    TYPE_LAST,
    PARM_TYPE_MAX = TYPE_LAST, 
} PARM_TYPE;

typedef enum {
    PARM_TYPE_RESERVED = 0,
    PARM_U8,
    PARM_U16,
    PARM_U32,
    PARM_S8,
    PARM_S16, 
    PARM_S32,
    PARM_DATA_64,           // binary stream
    PARM_DATA_128,          // binary stream
    PARM_DATA_256,
    PARM_DATA_512,
    PARM_DATA_1024,
    PARM_DATA_2048,
    PARM_CHAR,              // TBD: ascii stream
    PARM_VOID,

    VALUE_TYPE_LAST,
    VALUE_TYPE_MAX  = (VALUE_TYPE_LAST +1),
} VALUE_TYPE;

typedef enum {
	HWCALOP_NONE				= 0,
	HWCALOP_FULL_WHAL_RESET_CAL,
	HWCALOP_WHAL_RESET_PART_1,
	HWCALOP_HW_RESET,
	HWCALOP_PROGRAM_INI_TABLES,
	HWCALOP_WHAL_RESET_PART_2,
	HWCALOP_FULL_CAL,
	HWCALOP_RXDCO,
	HWCALOP_RXFILT,
	HWCALOP_RXIQ,
	HWCALOP_TXIQ,
	HWCALOP_TXCL,
	HWCALOP_PKDET,
	HWCALOP_WHAL_RESET_PART_3,
    HWCALOP_NOISEFLOOR,
    HWCALOP_DPD,
    HWCALOP_LNA,
} HWCAL_OP;

typedef enum {
    PARM_LM_CMDID_TX = 0,
    PARM_LM_CMDID_HWCAL = 1,
    PARM_LM_CMDID_RX = 2,
    MAX_LM_HWCAL_NUM = 100,
    MAX_LM_CHANNEL_LIST_NUM = 1000,
} LISTMODE_PARAM;
#endif //#if !defined(__CMD_RSP_PARMS_INTERNAL_H)
