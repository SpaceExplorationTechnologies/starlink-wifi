#if !defined(_CMD_OPCODE_TEMPLATE_H)
#define  _CMD_OPCODE_TEMPLATE_H

typedef struct _cmdOpCodeHandlers {
    _PARM_BIN_TEMPLATE * (*_CmdOpCodeTemplate)();
} __ATTRIB_PACK _CMD_OPCODE_HANDLERS;

A_UINT8 getCmdOpCodeTemplateSize();

#endif

