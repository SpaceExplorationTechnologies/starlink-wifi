
#include "tlv2Inc.h"

// Parameter offset table
//   1. Indexed by the key hash
//   2. Each entry could be a linked list of ParmOffsetFields, due to hash collision
//A_UINT32  ParmOffsetTbl[MAX_PARM_NUM];

// Pool of ParmOffsetTble entries
static PARM_OFFSET_FIELDS ParmOffsetFields[MAX_PARM_NUM];
static A_UINT32 ParmOffsetFieldsPos=0;

static PARM_OFFSET_FIELDS *nextParmOffsetFields(void)
{
    if (ParmOffsetFieldsPos >= MAX_PARM_NUM ) { debug("Parm offset elem exceeds max, result in overwrite\n"); }
    memset((void*)&(ParmOffsetFields[ParmOffsetFieldsPos%MAX_PARM_NUM]), 0, sizeof(PARM_OFFSET_FIELDS));
    return(&(ParmOffsetFields[(ParmOffsetFieldsPos++)%MAX_PARM_NUM]));
}

void resetParmOffsetFields(void)
{
    ParmOffsetFieldsPos=0;
}

void fillParmOffsetTbl(A_UINT32 parmCode, A_UINT32 offset, PARM_OFFSET_TBL *pParmsOffset)
{
    int keyHash;
    PARM_OFFSET_FIELDS *pParmOffsetFields, *pt;
    PARM_DICT *pParmDict;
    A_UINT32 parmIdx;

    pParmOffsetFields = (PARM_OFFSET_FIELDS *)nextParmOffsetFields();
    pParmOffsetFields->parmCode = parmCode;
    pParmOffsetFields->offset   = offset;

    if (parmCode >= SYSPARM_FIRST_IDX)
    {
        parmIdx = parmCode - SYSPARM_FIRST_IDX;
        pParmDict = SysParmDict;
    }
    else
    {
        parmIdx = parmCode;
        pParmDict = ParmDict;
    }

    keyHash = pParmDict[parmIdx].keyHash;
    if (NULL == pParmsOffset[keyHash].pt) {
        pParmsOffset[keyHash].pt = pParmOffsetFields;
    }
    else {
        pt = pParmsOffset[keyHash].pt;
        while (NULL != pt->next) {
            pt = pt->next;
        }
        pt->next = pParmOffsetFields;
    }

    return;
}
#if 0
void fillParmOffsetTbl(A_UINT32 parmCode, A_UINT32 offset, PARM_OFFSET_TBL *pParmsOffset)
{
    int keyHash;
    PARM_OFFSET_FIELDS **pParmOffsetFields, **pParmOffsetFieldsPrev;

    printf("parmCode %d offset 0x%x parmOffsetTbl 0x%x\n", parmCode, offset, pParmsOffset);
    keyHash = ParmDict[parmCode].keyHash;
    pParmOffsetFieldsPrev = &(pParmsOffset[keyHash].pt);
    pParmOffsetFields = &(pParmsOffset[keyHash].pt);
    printf("keyhash %d parmOffset 0x%x\n", keyHash, (int)(*pParmOffsetFields));
    while (NULL != (*pParmOffsetFields)) {
        (*pParmOffsetFieldsPrev) = (*pParmOffsetFields);
        (*pParmOffsetFields) = (*pParmOffsetFields)->next;
    }
    (*pParmOffsetFields) = (PARM_OFFSET_FIELDS *)nextParmOffsetFields();
    (*pParmOffsetFields)->parmCode = parmCode;
    (*pParmOffsetFields)->offset   = offset;
    if (NULL != (*pParmOffsetFieldsPrev))
        (*pParmOffsetFieldsPrev)->next = (*pParmOffsetFields);

    return;
}
#endif
    
