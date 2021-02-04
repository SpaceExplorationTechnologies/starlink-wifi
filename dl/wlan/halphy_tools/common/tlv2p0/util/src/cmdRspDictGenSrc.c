// 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>
#ifdef WIN32
#include <windows.h>
#endif //WIN32

#include "tsCommon.h"
#include "wlantype.h"
#include "tcmdHostInternal.h"
#include "cmdRspParmsInternal.h"
#include "cmdRspParmsDict.h"

#ifdef Linux
#define _strnicmp   strncasecmp
#define Sleep(x)    sleep((x)/1000))
#define srand(x)    srandom(x)
#define rand()      random()
#endif //Linux

#define MAX_TEXT_LINES  1000
#define MAX_INPUT_LINE  512
#define MAX_CODE_LEN    64
#define MAX_VALUE_ELEM  256
#define MAX_STR_LEN     32
#define MAX_STR_ELEM    64
#define HASH_RANGE      36
#define MAX_BINDATA_LEN 2048
#define MAX_NUM_CODES   500
#define MAX_NUM_PARMS   2000

typedef struct {
    char         name[MAX_CODE_LEN];
    char         parm[MAX_CODE_LEN];
    A_UINT8      parmType;     // singular or array
    A_UINT8      valueType;    // U8, etc.
    A_UINT8      numValueLow;  // numOfArray elements, 1 for singular
    A_UINT8      numValueHigh; // total elements: high|low
    union {
        A_UINT32     valueU32[MAX_VALUE_ELEM];
        A_INT32      valueS32[MAX_VALUE_ELEM];
        A_UINT16     valueU16[MAX_VALUE_ELEM];
        A_INT16      valueS16[MAX_VALUE_ELEM];
        A_UINT8      valueU8[MAX_VALUE_ELEM];
        A_INT8       valueS8[MAX_VALUE_ELEM];
        A_UINT8      valueDataBin[MAX_BINDATA_LEN];
        char         valueStr[MAX_STR_LEN][MAX_STR_ELEM]; 
    } u;
    A_UINT32         numValue;       // number of values in the input file (should be less than number of elements)
	char             specifier;	     // d(ecimal), u(nsigned), (he)x, f(loat), t(text)
    A_BOOL           alreadyIn;
    A_BOOL           isNumValueInText;
    char             numValueInText[MAX_CODE_LEN];
} PARM_ONE;

typedef struct {
    char          code[MAX_CODE_LEN];
    PARM_ONE      parm[MAX_PARM_NUM];
    A_UINT32      numParm;
} CMD_RSP_BUF;
typedef enum {
    NON_PARM=0,
    CMD_PARM,
    RSP_PARM,
} CMD_RSP_PARSING_STAGE;
typedef struct {
    CMD_RSP_PARSING_STAGE stage;
    int                   numCmdParm; 
    int                   numRspParm;
    A_UINT8               valueType;
    A_UINT8               reserved[3];
} CMD_RSP_PARSING_STATE;

//--------------------------------------------------------------------
// Local Variables
//--------------------------------------------------------------------

static CMD_RSP_BUF cmdBuf, rspBuf, *pCmdRspBuf;
static A_UCHAR textBuf[MAX_TEXT_LINES][MAX_CODE_LEN];
static A_UINT32 nextText = 0;

// These falgs are set when cmd/rsp codes are already in the dictionary or there are no cmd/rsp in the input .s file
A_BOOL cmdCodeAlreadyIn, rspCodeAlreadyIn;

char CmdCodes[MAX_NUM_CODES][MAX_CODE_LEN] = {0};
A_UINT32 CmdRandom[MAX_NUM_CODES] = {0};
int NumCmdCodes;

char ParmCodes[MAX_NUM_PARMS][MAX_CODE_LEN] = {0};
A_UINT32 ParmRandom[MAX_NUM_PARMS] = {0};
int NumParmCodes;

char newCmdCodes[2][MAX_CODE_LEN];
A_UINT32 newCmdRandom[2];
int newCmdCnt = 0;

A_UINT32 newParmRandom[MAX_PARM_NUM] = {0};
char newParmValueStr[MAX_PARM_NUM][MAX_VALUE_ELEM]  = {0};
A_UINT32 newHashNum[MAX_PARM_NUM] = {0};
char newDataTypeStr[MAX_PARM_NUM][MAX_DATATYPE_LEN] = {0};
int newParmCnt = 0;
A_UINT32 allParmCnt;
A_BOOL isSysCmd = FALSE;
A_BOOL dictHRead = FALSE;

//--------------------------------------------------------------------
// Local function declarations
//--------------------------------------------------------------------

static A_BOOL parseInput(char *inFile);
static A_BOOL readCmdRspDictH();
static A_BOOL genData();
static A_BOOL genHandlerC(char *inFile);
static A_BOOL genHandlerH(char *inFile);
static A_BOOL genTlv2ApiH(char *cmdFile);
static A_BOOL genCmdHandlersH(char *cmdFile);
static A_BOOL genCmdHandlerTblC();
static A_BOOL genCmdRspDictH();
static A_BOOL genCmdRspDictC();

//--------------------------------------------------------------------
// Function Definitions
//--------------------------------------------------------------------

int main(int argc, char *argv[])
{
    char inFile[FILENAME_SIZE];

    if (2 != argc) 
    {
#ifdef Linux
        printf("Usage: cmdRspParmsGenSrc.out <input file>\n");
#else //WINDOW
        printf("Usage: cmdRspParmsGenSrc.exe <input file>\n");
#endif //Linux
        return(0);
    }

    cmdBuf.code[0] = '\0';
    rspBuf.code[0] = '\0';

    // parse the input file
    strcpy(inFile, argv[1]);
    if (parseInput(inFile) == FALSE)
    {
        return (-1);
    }

    // generate master cmd, parameter source
    if (genData() == TRUE)
    {
        if (genHandlerC(inFile) == TRUE)
        {
            if (genHandlerH(inFile) == TRUE)
            {
                if (genCmdHandlersH(inFile) == TRUE)
                {
                    if (genCmdHandlerTblC() == TRUE)
                    {
                        if (genTlv2ApiH(inFile) == TRUE)
                        {
                            if (genCmdRspDictH() == TRUE)
                            {
                                if (genCmdRspDictC() == TRUE)
                                {
                                    return 0;
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    return (-1);
}

static void scanValueU (char *pLine, char specifier, int *value)
{
    if (specifier == 'x')
    {
        sscanf(pLine, "%x", value);
    }
    else
    {
        sscanf(pLine, "%u", value);
    }
}

static void scanValueS (char *pLine, char specifier, int *value)
{
    if (specifier == 'x')
    {
        sscanf(pLine, "%x", value);
    }
    else
    {
        sscanf(pLine, "%d", value);
    }
}

static void sprintValueU8 (char *str, char specifier, A_UINT8 value, char *postfix)
{
    if (specifier == 'x')
    {
        sprintf(str, "0x%x", value);
    }
    else
    {
        sprintf(str, "%u", value);
    }
    if (postfix) strcat(str, postfix);
}

static void sprintValueU16 (char *str, char specifier, A_UINT16 value, char *postfix)
{
    if (specifier == 'x')
    {
        sprintf(str, "0x%x", value);
    }
    else
    {
        sprintf(str, "%u", value);
    }
    if (postfix) strcat(str, postfix);
}

static void sprintValueU32 (char *str, char specifier, A_UINT32 value, char *postfix)
{
    if (specifier == 'x')
    {
        sprintf(str, "0x%x", value);
    }
    else
    {
        sprintf(str, "%u", value);
    }
    if (postfix) strcat(str, postfix);
}

static void sprintValueS8 (char *str, char specifier, A_INT8 value, char *postfix)
{
    if (specifier == 'x')
    {
        sprintf(str, "0x%x", value);
    }
    else
    {
        sprintf(str, "%d", value);
    }
    if (postfix) strcat(str, postfix);
}

static void sprintValueS16 (char *str, char specifier, A_INT16 value, char *postfix)
{
    if (specifier == 'x')
    {
        sprintf(str, "0x%x", value);
    }
    else
    {
        sprintf(str, "%d", value);
    }
    if (postfix) strcat(str, postfix);
}

static void sprintValueS32 (char *str, char specifier, A_INT32 value, char *postfix)
{
    if (specifier == 'x')
    {
        sprintf(str, "0x%x", value);
    }
    else
    {
        sprintf(str, "%d", value);
    }
    if (postfix) strcat(str, postfix);
}

static char *str2Upper(char *str)
{   char *tmp=str;
    while (*tmp != '\0') {
        *tmp = toupper((unsigned char) *tmp);
        ++tmp;
    }
    return(str);
}

static char *str2Lower(char *str)
{   char *tmp=str;
    while (*tmp != '\0') {
        *tmp = tolower((unsigned char) *tmp);
        ++tmp;
    }
    return(str);
}

static A_BOOL parseInput(char *inFile)
{
    FILE *fStream;
    char lineBuf[MAX_INPUT_LINE], *pLine;
    CMD_RSP_PARSING_STATE parsingState;
    char delimiters[]   = " \t";
    char code[MAX_STR_LEN];
    char delimiters1[] = ": \t\n\r;=" ;
    char delimiters2[] = ": \t;" ;

    memset(textBuf, 0, sizeof(textBuf));
    parsingState.stage=NON_PARM;
    parsingState.numCmdParm=0; 
    parsingState.numRspParm=0;
    printf("\nReading %s\n", inFile);
    if( (fStream = fopen( inFile, "r")) == NULL ) {
        printf("Failed to open %s\n", inFile);
        return FALSE;
    }

    while(fgets(lineBuf, MAX_INPUT_LINE, fStream) != NULL) {
        pLine = lineBuf;
        while(isspace(*pLine)) pLine++;
        if(*pLine == '\n') {
            continue;
        }
        if(*pLine == '#') {
            if((_strnicmp("#if", pLine, strlen("#if")) == 0) ||
               (_strnicmp("#define", pLine, strlen("#define")) == 0) ||
               (_strnicmp("#endif", pLine, strlen("#endif")) == 0))
            {
                strncpy(textBuf[nextText++], pLine, MAX_CODE_LEN);
            }
            else
            {
                continue;
            }
        }
        else if(_strnicmp("CMD", pLine, strlen("CMD")) == 0) {
            isSysCmd = FALSE;
            if (readCmdRspDictH() == FALSE)
            {
                return FALSE;
            }
            parsingState.stage=CMD_PARM;
            pLine = strchr(pLine, '=');
            pLine++;
            pLine = strtok( pLine, delimiters ); //get past any white space etc
            pLine = strtok( pLine, delimiters1);

            if(!sscanf(pLine, "%s", code)) {
                printf("Unable to read CMD from %s\n", inFile);
                return FALSE;
            }
            sprintf(cmdBuf.code, "CMD_%s", str2Upper(code));
        }
        else if(_strnicmp("SYSCMD", pLine, strlen("SYSCMD")) == 0) {
            isSysCmd = TRUE;
            if (readCmdRspDictH() == FALSE)
            {
                return FALSE;
            }
            parsingState.stage=CMD_PARM;
            pLine = strchr(pLine, '=');
            pLine++;
            pLine = strtok( pLine, delimiters ); //get past any white space etc
            pLine = strtok( pLine, delimiters1);

            if(!sscanf(pLine, "%s", code)) {
                printf("Unable to read CMD from %s\n", inFile);
                return FALSE;
            }
            sprintf(cmdBuf.code, "SYSCMD_%s", str2Upper(code));
        }
        else if(_strnicmp("RSP", pLine, strlen("RSP")) == 0) {
            isSysCmd = FALSE;
            if (FALSE == dictHRead)
            {
                if (readCmdRspDictH() == FALSE)
                {
                    return FALSE;
                }
            }
            parsingState.stage=RSP_PARM;
            pLine = strchr(pLine, '=');
            pLine++;
            pLine = strtok( pLine, delimiters ); //get past any white space etc
            pLine = strtok( pLine, delimiters1);

            if(!sscanf(pLine, "%s", code)) {
                printf("Unable to read RSP from %s\n", inFile);
                return FALSE;
            }
            sprintf(rspBuf.code, "CMD_%s", str2Upper(code));
        }
        else if(_strnicmp("SYSRSP", pLine, strlen("SYSRSP")) == 0) {
            isSysCmd = TRUE;
            if (FALSE == dictHRead)
            {
                if (readCmdRspDictH() == FALSE)
                {
                    return FALSE;
                }
            }
            parsingState.stage=RSP_PARM;
            pLine = strchr(pLine, '=');
            pLine++;
            pLine = strtok( pLine, delimiters ); //get past any white space etc
            pLine = strtok( pLine, delimiters1);

            if(!sscanf(pLine, "%s", code)) {
                printf("Unable to read RSP from %s\n", inFile);
                return FALSE;
            }
            sprintf(rspBuf.code, "SYSCMD_%s", str2Upper(code));
        }
        else if(_strnicmp("PARM_START", pLine, strlen("PARM_START")) == 0) {
            if (CMD_PARM == parsingState.stage) { pCmdRspBuf = &cmdBuf; }
            else { pCmdRspBuf =&rspBuf; }
        } 
        else if(_strnicmp("PARM_END", pLine, strlen("PARM_END")) == 0) {
            if (CMD_PARM == parsingState.stage) {
                pCmdRspBuf->numParm=parsingState.numCmdParm; 
            } 
            else {
                pCmdRspBuf->numParm=parsingState.numRspParm; 
            }
            parsingState.stage=NON_PARM;
        } 
        else if(_strnicmp("void", pLine, strlen("void")) == 0) {
            parsingState.valueType=(A_UINT8)PARM_VOID;
            pCmdRspBuf->numParm=0; 
        }
        else if(_strnicmp("char", pLine, strlen("char")) == 0) {
            parsingState.valueType=(A_UINT8)PARM_CHAR;
            goto _parsingParm;
        }
        else if(_strnicmp("UINT8", pLine, strlen("UINT8")) == 0) {
            parsingState.valueType=(A_UINT8)PARM_U8;
            goto _parsingParm;
        }
        else if(_strnicmp("UINT16", pLine, strlen("UINT16")) == 0) {
            parsingState.valueType=(A_UINT8)PARM_U16;
            goto _parsingParm;
        }
        else if(_strnicmp("UINT32", pLine, strlen("UINT32")) == 0) {
            parsingState.valueType=(A_UINT8)PARM_U32;
            goto _parsingParm;
        }
        else if(_strnicmp("INT8", pLine, strlen("INT8")) == 0) {
            parsingState.valueType=(A_UINT8)PARM_S8;
            goto _parsingParm;
        }
        else if(_strnicmp("INT16", pLine, strlen("INT16")) == 0) {
            parsingState.valueType=(A_UINT8)PARM_S16;
            goto _parsingParm;
        }
        else if(_strnicmp("INT32", pLine, strlen("INT32")) == 0) {
            parsingState.valueType=(A_UINT8)PARM_S32;
            goto _parsingParm;
        }
        else if(_strnicmp("DATA64", pLine, strlen("DATA64")) == 0) {
            parsingState.valueType=(A_UINT8)PARM_DATA_64;
            goto _parsingParm;
        }
        else if(_strnicmp("DATA128", pLine, strlen("DATA128")) == 0) {
            parsingState.valueType=(A_UINT8)PARM_DATA_128;
            goto _parsingParm;
        }
        else if(_strnicmp("DATA256", pLine, strlen("DATA256")) == 0) {
            parsingState.valueType=(A_UINT8)PARM_DATA_256;
            goto _parsingParm;
        }
        else if(_strnicmp("DATA512", pLine, strlen("DATA512")) == 0) {
            parsingState.valueType=(A_UINT8)PARM_DATA_512;
            goto _parsingParm;
        }
        else if(_strnicmp("DATA1024", pLine, strlen("DATA1024")) == 0) {
            parsingState.valueType=(A_UINT8)PARM_DATA_1024;
            goto _parsingParm;
        }
        continue;  // go to next iteration

_parsingParm:
        {
            int valueIdx, numElem, parmIdx;
            PARM_ONE *pParm;

            if (parsingState.stage==CMD_PARM) { parmIdx = parsingState.numCmdParm++; }
            else { parmIdx = parsingState.numRspParm++; }
            pParm = &(pCmdRspBuf->parm[parmIdx]);

            pLine = strtok(pLine, delimiters2);   // value type
            pLine = strtok(NULL, delimiters2);    // parm
            strcpy(pParm->name, pLine);
            if (isSysCmd)
            {
                sprintf(pParm->parm, "SYSPARM_%s", str2Upper(pLine));
            }
            else
            {
                sprintf(pParm->parm, "PARM_%s", str2Upper(pLine));
            }
            pLine = strtok(NULL, delimiters2);    // numElem

            pParm->isNumValueInText = FALSE;
            // check if the number of array is in text
            if ((*pLine < '0') || (*pLine > '9'))
            {
                pParm->isNumValueInText = TRUE;
                sscanf(pLine, "%s", pParm->numValueInText);
                //next field should be number of elements in digit
                pLine = strtok(NULL, delimiters2);    // numElem
            }

            sscanf(pLine, "%d", &numElem);
            if ((1 == numElem) && (pParm->isNumValueInText == FALSE)) {
                pParm->parmType = TYPE_SINGULAR; 
            }
            else {
                pParm->parmType = TYPE_ARRAY; 
            }
            pParm->numValueLow = (numElem & 0xff);
            if (numElem >= 256) {
                pParm->numValueHigh = (numElem >> 8) &0xff; 
            }
            pLine = strtok(NULL, delimiters2);    // type
            pParm->specifier = pLine[0];

            pLine = strtok(NULL, delimiters1);    // 1st parameter
            if (PARM_CHAR == parsingState.valueType) {
                pParm->valueType = PARM_CHAR;
                valueIdx=0;
                while (pLine) {
                    strcpy(&(pParm->u.valueStr[valueIdx][0]), pLine);
                    valueIdx++;
                    pLine = strtok(NULL, delimiters1);
                }
            }
            else if (PARM_U8 == parsingState.valueType) {
                pParm->valueType = PARM_U8;
                valueIdx=0;
                while (pLine) {
                    scanValueU (pLine, pParm->specifier, (int *)&(pParm->u.valueU8[valueIdx]));
                    valueIdx++;
                    pLine = strtok(NULL, delimiters1);
                }
            }
            else if (PARM_S8 == parsingState.valueType) {
                pParm->valueType = PARM_S8;
                valueIdx=0;
                while (pLine) {
                    scanValueS (pLine, pParm->specifier, (int *)&(pParm->u.valueS8[valueIdx]));
                    valueIdx++;
                    pLine = strtok(NULL, delimiters1);
                }
            }
            else if (PARM_U16 == parsingState.valueType) {
                pParm->valueType = PARM_U16;
                valueIdx=0;
                while (pLine) {
                    scanValueU (pLine, pParm->specifier, (int *)&(pParm->u.valueU16[valueIdx]));
                    valueIdx++;
                    pLine = strtok(NULL, delimiters1);
                }
            }
            else if (PARM_S16 == parsingState.valueType) {
                pParm->valueType = PARM_S16;
                valueIdx=0;
                while (pLine) {
                    scanValueS (pLine, pParm->specifier, (int *)&(pParm->u.valueS16[valueIdx]));
                    valueIdx++;
                    pLine = strtok(NULL, delimiters1);
                }
            }
            else if (PARM_U32 == parsingState.valueType) {
                pParm->valueType = PARM_U32;
                valueIdx=0;
                while (pLine) {
                    scanValueU (pLine, pParm->specifier, (int *)&(pParm->u.valueU32[valueIdx]));
                    valueIdx++;
                    pLine = strtok(NULL, delimiters1);
                }
            }
            else if (PARM_S32 == parsingState.valueType) {
                pParm->valueType = PARM_S32;
                valueIdx=0;
                while (pLine) {
                    scanValueS (pLine, pParm->specifier, (int *)&(pParm->u.valueS32[valueIdx]));
                    valueIdx++;
                    pLine = strtok(NULL, delimiters1);
                }
            }
            else if ((PARM_DATA_64 <= parsingState.valueType) && (PARM_DATA_2048 >= parsingState.valueType)) {
                pParm->valueType = parsingState.valueType;
                pParm->parmType = TYPE_DATA; //adjust type
                valueIdx=0;
                while (pLine) {
                    scanValueU (pLine, pParm->specifier, (int *)&(pParm->u.valueU8[valueIdx]));
                    valueIdx++;
                    pLine = strtok(NULL, delimiters1);
                }
            }
            pParm->numValue = valueIdx;
            pParm->alreadyIn = FALSE;
        }
    }  // End while (get line)
    fclose(fStream);

    return TRUE;
}

static char parmTypeTemp[PARM_TYPE_MAX][16]={"TYPE_SINGULAR", "TYPE_ARRAY", "TYPE_DATA"};
static char valueTypeTemp[VALUE_TYPE_MAX][16]={"PARM_RES", "PARM_U8", "PARM_U16", "PARM_U32", "PARM_S8", "PARM_S16", "PARM_S32",
                                    "PARM_DATA_64", "PARM_DATA_128", "PARM_DATA_256", "PARM_DATA_512", "PARM_DATA_1024",
};
static char *makeDataTypeStr(PARM_ONE *parm, char *str)
{
    sprintf(str, "DATATYPE(%s, %s)", valueTypeTemp[parm->valueType], parmTypeTemp[parm->parmType]);
    return(str);
}

static int add2File(char *fileIn, char *valueStr, char *arrayName)
{
    FILE *fp;
    char fileSrc[FILENAME_SIZE];

    sprintf((void*)fileSrc, "output/%s", fileIn);

    if( (fp = fopen( fileSrc, "a")) == NULL ) {
        printf("Failed to open %s\n", fileSrc);
        return 0;
    }
    // write the new value string
    fputs(valueStr, fp);

    if (fp) fclose(fp);
    return(1);
}

static char *makeValueStr(PARM_ONE *parm, char *arrayName)
{
    char valueStr[MAX_STR_LEN];
    char arrayStr[MAX_INPUT_LINE];
    char commaStr[2] = ",";
    char *pPostFix;
    A_UINT32  i, numElem = ((parm->numValueHigh << 8) | parm->numValueLow);

    if (((TYPE_ARRAY == parm->parmType) || (TYPE_DATA == parm->parmType)) && (parm->numValue == 0))
    {
        strcpy(arrayName, "NULL");
        return(arrayName);
    }

    sprintf(arrayName, "%sArray", parm->parm);
    memset((void*)arrayStr, '\0', sizeof(arrayStr));

    switch (parm->valueType) {
        case PARM_U8:
            if (TYPE_SINGULAR == parm->parmType) {
                sprintValueU8(arrayName, parm->specifier, parm->u.valueU8[0], NULL);
            }
            else if (parm->numValue)
            {
                sprintf(arrayStr, "static A_UINT8 %s[%d] = {", arrayName, numElem);
                for (i = 0; i < parm->numValue; i++) {
                    pPostFix = (i < (parm->numValue - 1) ? commaStr : NULL);
                    sprintValueU8 (valueStr, parm->specifier, parm->u.valueU8[i], pPostFix);
                    strcat(arrayStr, valueStr);
                }
                strcat(arrayStr, "};\n");
                add2File("u8Array.s", arrayStr, arrayName);
            }
            break;
        case PARM_U16:
            if (TYPE_SINGULAR == parm->parmType) {
                sprintValueU16(arrayName, parm->specifier, parm->u.valueU16[0], NULL);
            }
            else if (parm->numValue)
            {
                sprintf(arrayStr, "static A_UINT16 %s[%d] = {", arrayName, numElem);
                for (i = 0; i < parm->numValue; i++) {
                    pPostFix = (i < (parm->numValue - 1) ? commaStr : NULL);
                    sprintValueU16 (valueStr, parm->specifier, parm->u.valueU16[i], pPostFix);
                    strcat(arrayStr, valueStr);
                }
                strcat(arrayStr, "};\n");
                add2File("u16Array.s", arrayStr, arrayName);
            }
            break;
        case PARM_U32:
            if (TYPE_SINGULAR == parm->parmType) {
                sprintValueU32(arrayName, parm->specifier, parm->u.valueU32[0], NULL);
            }
            else if (parm->numValue)
            {
                sprintf(arrayStr, "static A_UINT32 %s[%d] = {", arrayName, numElem);
                for (i = 0; i < parm->numValue; i++) {
                    pPostFix = (i < (parm->numValue - 1) ? commaStr : NULL);
                    sprintValueU32 (valueStr, parm->specifier, parm->u.valueU32[i], pPostFix);
                    strcat(arrayStr, valueStr);
                }
                strcat(arrayStr, "};\n");
                add2File("u32Array.s", arrayStr, arrayName);
            }
            break;
        case PARM_S8:
            if (TYPE_SINGULAR == parm->parmType) {
                sprintValueS8(arrayName, parm->specifier, parm->u.valueS8[0], NULL);
            }
            else if (parm->numValue)
            {
                sprintf(arrayStr, "static A_INT8 %s[%d] = {", arrayName, numElem);
                for (i = 0; i < parm->numValue; i++) {
                    pPostFix = (i < (parm->numValue - 1) ? commaStr : NULL);
                    sprintValueS8 (valueStr, parm->specifier, parm->u.valueS8[i], pPostFix);
                    strcat(arrayStr, valueStr);
                }
                strcat(arrayStr, "};\n");
                add2File("s8Array.s", arrayStr, arrayName);
            }
            break;
        case PARM_S16:
            if (TYPE_SINGULAR == parm->parmType) {
                sprintValueS16(arrayName, parm->specifier, parm->u.valueS16[0], NULL);
            }
            else if (parm->numValue)
            {
                sprintf(arrayStr, "static A_INT16 %s[%d] = {", arrayName, numElem);
                for (i = 0; i < parm->numValue; i++) {
                    pPostFix = (i < (parm->numValue - 1) ? commaStr : NULL);
                    sprintValueS16 (valueStr, parm->specifier, parm->u.valueS16[i], pPostFix);
                    strcat(arrayStr, valueStr);
                }
                strcat(arrayStr, "};\n");
                add2File("s16Array.s", arrayStr, arrayName);
            }
            break;
        case PARM_S32:
            if (TYPE_SINGULAR == parm->parmType) {
                sprintValueS32(arrayName, parm->specifier, parm->u.valueS32[0], NULL);
            }
            else if (parm->numValue)
            {
                sprintf(arrayStr, "static A_INT32 %s[%d] = {", arrayName, numElem);
                for (i = 0; i < parm->numValue; i++) {
                    pPostFix = (i < (parm->numValue - 1) ? commaStr : NULL);
                    sprintValueS32 (valueStr, parm->specifier, parm->u.valueS32[i], pPostFix);
                    strcat(arrayStr, valueStr);
                }
                strcat(arrayStr, "};\n");
                add2File("s32Array.s", arrayStr, arrayName);
            }
            break;
        case PARM_DATA_64:
        case PARM_DATA_128:
        case PARM_DATA_256:
        case PARM_DATA_512:
        case PARM_DATA_1024:
        case PARM_DATA_2048:
            if (parm->numValue)
            {
                sprintf(arrayStr, "static A_UINT8 %s[%d] = {", arrayName, numElem);
                for (i = 0; i < parm->numValue; i++) {
                    pPostFix = (i < (parm->numValue - 1) ? commaStr : NULL);
                    sprintValueU8 (valueStr, parm->specifier, parm->u.valueU8[i], pPostFix);
                    strcat(arrayStr, valueStr);
                }
                strcat(arrayStr, "};\n");
                add2File("u8Data.s", arrayStr, arrayName);
            }
            break;
        default:
            break;
    }
    return(arrayName);
}
A_BOOL CheckParmExist(PARM_ONE *pParm)
{
    int i;
    //char dataTypeStr[MAX_DATATYPE_LEN];


    for (i = 0; i < (int)allParmCnt; i++)
    {
        if (_strnicmp(ParmCodes[i], pParm->parm, MAX_CODE_LEN) == 0)
        {
            printf("WARNING: Parameter %s ALREADY EXISTS. Check the cmdRspParmsDict.c for reference.\n", pParm->parm);
            return TRUE;
        }
    }
    return FALSE;
}

static A_UINT32 genRandomNum(void)
{
    static int start = 0;
    A_UINT32 retRand;

    if (start == 0)
    {
        time_t timer;
        time(&timer);
        srand((int)timer);
        start = 1;
    }
    retRand = ((rand() % 0xffff) | ((rand() % 0xffff) << 16)) & 0x7fffffff;
    return(retRand);
}

static A_UINT32 genHash(char* str, A_UINT32 len, A_UINT32 range)
{
    A_UINT32 hash = 0;
    A_UINT32 k = 0;
    for (k=0;k<len;str++,k++) {
        hash = (*str) + (hash << 6) + (hash << 16) - hash;
    }
    return(hash%range);
}

char *GetFileNameOnly(char *pName)
{
    char *pLine;
    char delimiters[] = "/\\";
    char fileName[FILENAME_SIZE];

    strcpy(fileName, pName);
    pLine = strtok(fileName, delimiters);
    while(pLine != NULL)
    {
        strcpy(pName, pLine);
        pLine = strtok(NULL, delimiters);
    }
    return pName;
}

static char valueTypeSingularStr[][10] = 
{
    "", "valU8", "valU16", "valU32", "valS8", "valS16", "valS32"
};
static char valueTypeArrayStr[][10] =
{
    "", "ptU8", "ptU16", "ptU32", "ptS8", "ptS16", "ptS32", "ptChar",
};

static char *GetValueTypeStr(PARM_ONE *pParm)
{
    if (pParm->parmType == TYPE_SINGULAR)
    { 
        if (pParm->valueType > PARM_S32)
        {
            printf("Invalid singular valueType %d\n", pParm->valueType);
            return NULL;
        }
        return (valueTypeSingularStr[pParm->valueType]);
    }
    else 
    {
        // TYPE_DATA
        if ((pParm->valueType >= PARM_DATA_64) && (pParm->valueType <= PARM_DATA_2048))
        {
            return valueTypeArrayStr[PARM_U8]; 
        }
        else if (pParm->valueType > PARM_DATA_2048)
        {
            return valueTypeArrayStr[PARM_S32+1]; // return "ptChar for now
        }
        return (valueTypeArrayStr[pParm->valueType]);
    }
}

static char typeStr[][10] = 
{
    "", "A_UINT8", "A_UINT16", "A_UINT32", "A_INT8", "A_INT16", "A_INT32", "A_CHAR"
};

static char *GetTypeStr(PARM_ONE *pParm)
{
    if ((pParm->valueType >= PARM_DATA_64) && (pParm->valueType <= PARM_DATA_2048))
    {
        return typeStr[PARM_U8];
    }
    else if (pParm->valueType > PARM_DATA_2048)
    {
        return typeStr[PARM_S32+1];
    }
    return (typeStr[pParm->valueType]);
}

static A_UINT32 GetParmSize(PARM_ONE *pParm)
{
    A_UINT32 numElem;
    A_UINT32 parmSize[] = {0, 1, 2, 4, 1, 2, 4};

    if (pParm->parmType == TYPE_SINGULAR)
    {
        return (parmSize[pParm->valueType]);
    }
    numElem = ((pParm->numValueHigh << 8) | pParm->numValueLow);
    return (parmSize[pParm->valueType] * numElem);
}

static A_UINT32 NeedPad(A_UINT32 size)
{
    A_UINT32 padSize = 4 - (size % 4);
    return (padSize < 4 ? padSize : 0);
}

static A_BOOL readCmdRspDictH()
{
    FILE *fp;
    char lineBuf[MAX_INPUT_LINE], *pLine;
    char delimiters[]   = " \t=\n";
    int numCmd, numRand;
    A_BOOL firstHit;
    char cmdLast[MAX_CODE_LEN];
    char cmdDash[MAX_CODE_LEN];
    char parmLast[MAX_CODE_LEN];
    char parmDash[MAX_CODE_LEN];

    if (!isSysCmd)
    {
        strncpy(cmdLast, "CMD_LAST,", MAX_CODE_LEN);
        strncpy(cmdDash, "CMD_", MAX_CODE_LEN);
        strncpy(parmLast, "PARM_LAST,", MAX_CODE_LEN);
        strncpy(parmDash, "PARM_", MAX_CODE_LEN);
    }
    else
    {
        strncpy(cmdLast, "SYSCMD_LAST,", MAX_CODE_LEN);
        strncpy(cmdDash, "SYSCMD_", MAX_CODE_LEN);
        strncpy(parmLast, "SYSPARM_LAST,", MAX_CODE_LEN);
        strncpy(parmDash, "SYSPARM_", MAX_CODE_LEN);
    }

    if ((fp = fopen("../include/cmdRspParmsDict.h", "r")) == NULL ) 
    {
        printf("Error in opening cmdRspParmsDict.h file.\n");
        return FALSE;
    }

    // read/write command enum
    while(fgets(lineBuf, MAX_INPUT_LINE, fp) != NULL)
    {
        if (strstr(lineBuf, "typedef enum cmdCodeEnum {") == lineBuf)
        {
            numCmd = numRand = 0;
            firstHit = FALSE;

            while(fgets(lineBuf, MAX_INPUT_LINE, fp) != NULL)
            {
                pLine = lineBuf;
                pLine = strtok(pLine, delimiters); //CMD_....
                if (pLine == NULL)
                {
                    continue;
                }
                if (strstr(pLine, cmdLast) == pLine)
                {
                    break; // done commands
                }
                else if (strstr(pLine, cmdDash) == pLine)
                {
                    firstHit = TRUE;
                    strcpy (CmdCodes[numCmd++], pLine); 
                }
                else if ((TRUE == firstHit) && (strstr(pLine, "#define") == pLine))
                {
                    pLine = strtok(NULL, delimiters);   // CMD_xx_RAND
                    pLine = strtok(NULL, delimiters);   // random number
                    scanValueU (pLine, 'u', (int *)&CmdRandom[numRand++]);
                }
            }
            if (numCmd != numRand)
            {
                printf ("Error in cmdRspParmsDict.h/cmdCodeEnum: wrong format.\n");
                fclose (fp);
                return FALSE;
            }
            NumCmdCodes = numCmd;
        }
        else if (strstr(lineBuf, "typedef enum parmCodeEnum {") == lineBuf)
        {
            numCmd = numRand = 0;
            firstHit = FALSE;

            while(fgets(lineBuf, MAX_INPUT_LINE, fp) != NULL)
            {
                pLine = lineBuf;
                pLine = strtok(pLine, delimiters); //CMD_....
                if (pLine == NULL)
                {
                    continue;
                }
                if (strstr(pLine, parmLast) == pLine)
                {
                    break; // done parmeters
                }
                else if (strstr(pLine, parmDash) == pLine)
                {
                    firstHit = TRUE;
                    strcpy (ParmCodes[numCmd++], pLine); 
                }
                else if ((firstHit == TRUE) && (strstr(pLine, "#define") == pLine))
                {
                    pLine = strtok(NULL, delimiters);   // PARM_xx_RAND
                    pLine = strtok(NULL, delimiters);   // random number
                    scanValueU (pLine, 'u', (int *)&ParmRandom[numRand++]);
                }
            }
            if (numCmd != numRand)
            {
                printf ("Error in cmdRspParmsDict.h/parmCodeEnum: wrong format.\n");
                fclose (fp);
                return FALSE;
            }
            NumParmCodes = numCmd;
        }
    }

    if (fp) fclose(fp);
    dictHRead = TRUE;
    return TRUE;
}

static A_BOOL genData()
{
    int i, idx;
    char *pCmdCode;
    PARM_ONE *parm;
    char hashStr[MAX_DATATYPE_LEN];

    cmdCodeAlreadyIn = FALSE;
    rspCodeAlreadyIn = FALSE;

    /*
     * Handle command codes,
     *    Impact both cmdRspParmsDict.h and .c
     */
    // check cmd, rsp codes, if they exist, quit
    for (idx=0;idx<NumCmdCodes;idx++) { 
        pCmdCode=&(CmdCodes[idx][0]); 
        if (_strnicmp(pCmdCode, cmdBuf.code, MAX_CODE_LEN) == 0) {
            // cmd already present in the dictionary
            printf("cmd %s already exists!\n", cmdBuf.code);
            cmdCodeAlreadyIn=TRUE;
            break;
        }
    }

    for (idx=0; idx<NumCmdCodes;idx++) {
        pCmdCode=&(CmdCodes[idx][0]); 
        if (_strnicmp(pCmdCode, rspBuf.code, MAX_CODE_LEN) == 0) {
            // cmd already present in the dictionary
            printf("rsp cmd %s already exists!\n", rspBuf.code);
            rspCodeAlreadyIn=TRUE;
            break;
        }
    }

    // also set the flag if no new cmd or rsp
    //if (cmdBuf.code[0] == '\0') cmdCodeAlreadyIn = TRUE;
    //if (rspBuf.code[0] == '\0') rspCodeAlreadyIn = TRUE;

    if (!cmdCodeAlreadyIn && (cmdBuf.code[0] != '\0')) {
        printf("adding cmd %s\n", cmdBuf.code);
        strcpy(newCmdCodes[newCmdCnt++], cmdBuf.code);
        newCmdRandom[0] = genRandomNum();
    }
    if (!rspCodeAlreadyIn && (rspBuf.code[0] != '\0')) {
        printf("adding rsp %s\n", rspBuf.code);
        strcpy(newCmdCodes[newCmdCnt++], rspBuf.code);
        newCmdRandom[newCmdCnt-1] = genRandomNum();
    }

    allParmCnt = NumParmCodes;
    newParmCnt = 0;
    for (idx = 0; idx < 2; idx++)
    {
        pCmdRspBuf = (idx == 0) ? &cmdBuf : &rspBuf;

        for (i=0; i < (int)pCmdRspBuf->numParm; i++) 
        {
            // mark and skip if this parm already exists
            if (CheckParmExist(&(pCmdRspBuf->parm[i])))
            {
                pCmdRspBuf->parm[i].alreadyIn = TRUE;
                continue;
            }
            if (allParmCnt >= MAX_NUM_PARMS)
            {
                printf("Error: allParmCnt >= MAX_NUM_PARMS\n");
                return FALSE;
            }
            printf("adding parm %s\n", pCmdRspBuf->parm[i].parm);
            strcpy(ParmCodes[allParmCnt++], pCmdRspBuf->parm[i].parm);

            // new parm random number
            newParmRandom[newParmCnt] = genRandomNum();
            
            // new parm value, hashnumber, adn data type strings
            memset((void *)hashStr, '\0', MAX_DATATYPE_LEN);
            parm=&(pCmdRspBuf->parm[i]);

            makeValueStr(parm, newParmValueStr[newParmCnt]);
            sprintf(hashStr, "%s_%d",parm->parm, i);
            newHashNum[newParmCnt] = genHash(hashStr, strlen(hashStr), HASH_RANGE);
            makeDataTypeStr(parm, newDataTypeStr[newParmCnt]);

            newParmCnt++;
        }
    }
    return TRUE;
}

static A_BOOL genHandlerC(char *inFile)
{
    FILE *fp;
    char inFileName[FILENAME_SIZE];
    char fileName[FILENAME_SIZE] = "output/";
    CMD_RSP_BUF *pBuf;
    PARM_ONE *pParm;
    char *pCode;
    char ptrName[MAX_CODE_LEN+6];
    A_UINT32 i, n;
    A_UINT16 numElem;
    char cmdPrefix[7];
    int cmdPrefixLen;
    char parmIdxStr[MAX_STR_ELEM];

    if (isSysCmd)
    {
        strcpy(cmdPrefix, "SYSCMD");
    }
    else
    {
        strcpy(cmdPrefix, "CMD");
    }
    cmdPrefixLen = strlen(cmdPrefix) + 1; // + the _

    strcpy(inFileName, inFile);
    strcat(fileName, GetFileNameOnly(inFileName));
    fileName[strlen(fileName)-1] = 'c';
    if( (fp = fopen( fileName, "w")) == NULL ) 
    {
        printf("Failed to open %s\n", fileName);
        return FALSE;
    }
    fprintf(fp, "// This is an auto-generated file from %s\n", inFile);
    strcpy(fileName, inFileName);
    fileName[strlen(fileName)-1] = 'h';
    fprintf(fp, "#include \"tlv2Inc.h\"\n");
    fprintf(fp, "#include \"%s\"\n", fileName);
    
    for (i = 0; i < 2; i++)
    {
        // 1st iteration: cmd; 2nd iteration: rsp
        pBuf = (i == 0) ? &cmdBuf: &rspBuf;
        if (pBuf->code[0] == '\0') continue;

        pCode = &pBuf->code[cmdPrefixLen]; //pass the prefix "CMD_" or "SYSCMD_"
        sprintf (ptrName, "p%sParms", pCode);
        fprintf(fp, "\nvoid* init%sOpParms(A_UINT8 *pParmsCommon, PARM_OFFSET_TBL *pParmsOffset, PARM_DICT *pParmDict)\n", pCode);
        fprintf(fp, "{\n");
        if (pBuf->numParm == 0)
        {
            fprintf(fp, "    return(NULL);\n");
        }
        else
        {
            fprintf(fp, "    int i; \t//for initializing array parameter\n");
            fprintf(fp, "    %s_%s_PARMS  *%s = (%s_%s_PARMS *)pParmsCommon;\n\n", cmdPrefix, pCode, ptrName, cmdPrefix, pCode);
            fprintf(fp, "    if (pParmsCommon == NULL) return (NULL);\n\n");
            fprintf(fp, "    i = 0;\t//assign a number to avoid warning in case i is not used\n\n");
            fprintf(fp, "    // Populate the parm structure with initial values\n");

            pParm = &pBuf->parm[0];
            for (n = 0; n < pBuf->numParm; n++)
            {
                strncpy(parmIdxStr, pParm[n].parm, sizeof(parmIdxStr));
                if (isSysCmd)
                {
                    strncat(parmIdxStr, "-SYSPARM_FIRST_IDX", sizeof(parmIdxStr)-strlen(pParm[n].parm));
                }

                if (pParm[n].parmType == TYPE_SINGULAR)
                {
                    fprintf(fp, "    %s->%s = pParmDict[%s].v.%s;\n", ptrName, pParm[n].name, parmIdxStr, GetValueTypeStr(&pParm[n]));
                }
                else //TYPE_ARRAY
                {
                    numElem = ((pParm[n].numValueHigh << 8) | pParm[n].numValueLow);
                    if (numElem > pParm[n].numValue)
                    {
                        fprintf(fp, "    memset(%s->%s, 0, sizeof(%s->%s));\n", ptrName, pParm[n].name, ptrName, pParm[n].name);
                    }
                    if (pParm[n].numValue > 0)
                    {
                        fprintf(fp, "    for (i = 0; i < %d ; i++)\n", pParm[n].numValue);
                        fprintf(fp, "    {\n");
                        fprintf(fp, "        %s->%s[i] = pParmDict[%s].v.%s[i];\n", ptrName, pParm[n].name, parmIdxStr, GetValueTypeStr(&pParm[n]));
                        fprintf(fp, "    }\n");
                    }
                }
            }
            fprintf(fp, "\n    // Make up ParmOffsetTbl\n");
            fprintf(fp, "    resetParmOffsetFields();\n");
        
            pParm = &pBuf->parm[0];
            for (n = 0; n < pBuf->numParm; n++)
            {
                strncpy(parmIdxStr, pParm[n].parm, sizeof(parmIdxStr));
                if (isSysCmd)
                {
                    strncat(parmIdxStr, "-SYSPARM_FIRST_IDX", sizeof(parmIdxStr)-strlen(pParm[n].parm));
                }
                fprintf(fp, "    fillParmOffsetTbl((A_UINT32)%s, (A_UINT32)(((A_UINT32)&(%s->%s)) - (A_UINT32)%s), pParmsOffset);\n",
                            pParm[n].parm, ptrName, pParm[n].name, ptrName);
            }
            fprintf(fp, "    return((void*) %s);\n", ptrName);
        }
        fprintf(fp, "}\n");

        fprintf(fp, "\nstatic %s_OP_FUNC %sOpFunc = NULL;\n", pCode, pCode);
        fprintf(fp, "\nTLV2_API void register%sHandler(%s_OP_FUNC fp)\n", pCode, pCode);
        fprintf(fp, "{\n");
        fprintf(fp, "    %sOpFunc = fp;\n", pCode);
        fprintf(fp, "}\n");

        fprintf(fp, "\nA_BOOL %sOp(void *pParms)\n", pCode);
        fprintf(fp, "{\n");
        if (pBuf->numParm == 0)
        {
            fprintf(fp, "    if (NULL != %sOpFunc) {\n", pCode);
            fprintf(fp, "        (*%sOpFunc)(NULL);\n", pCode);
            fprintf(fp, "    }\n");
        }
        else
        {
            fprintf(fp, "    %s_%s_PARMS *%s = (%s_%s_PARMS *)pParms;\n\n", cmdPrefix, pCode, ptrName, cmdPrefix, pCode);

            fprintf(fp, "#if 0 //for debugging, comment out this line, and uncomment the line below\n");
            fprintf(fp, "//#ifdef _DEBUG\n");
            fprintf(fp, "    int i; \t//for initializing array parameter\n");
            fprintf(fp, "    i = 0;\t//assign a number to avoid warning in case i is not used\n\n");
            pParm = &pBuf->parm[0];
            for (n = 0; n < pBuf->numParm; n++)
            {
                if ((pParm[n].specifier == 't') || (pParm[n].specifier == 's'))
                {
                    fprintf(fp, "    A_PRINTF(\"%sOp: %s %%s\\n\", %s->%s);\n",
                                    pCode, pParm[n].name, ptrName, pParm[n].name);
                }
                else
                {
                    if (pParm[n].parmType == TYPE_SINGULAR)
                    {
                        if (pParm[n].specifier == 'd')
                        {
                            fprintf(fp, "    A_PRINTF(\"%sOp: %s %%d\\n\", %s->%s);\n", 
                                            pCode, pParm[n].name, ptrName, pParm[n].name);
                        }
                        else if (pParm[n].specifier == 'u')
                        {
                            fprintf(fp, "    A_PRINTF(\"%sOp: %s %%u\\n\", %s->%s);\n",
                                            pCode, pParm[n].name, ptrName, pParm[n].name);
                        }
                        else //(pParm[n].specifier == 'x')
                        {
                            fprintf(fp, "    A_PRINTF(\"%sOp: %s 0x%%x\\n\", %s->%s);\n",
                                            pCode, pParm[n].name, ptrName, pParm[n].name);
                        }
                    }
                    else //ARRAY
                    {
                        numElem = ((pParm[n].numValueHigh << 8) | pParm[n].numValueLow);
                        if (numElem > 8)
                        {
                            fprintf(fp, "    for (i = 0; i < %d ; i++) // can be modified to print up to %d entries\n", 
                                    ((numElem < 8) ? numElem : 8), numElem);
                        }
                        else
                        {
                            fprintf(fp, "    for (i = 0; i < %d ; i++)\n", 
                                    ((numElem < 8) ? numElem : 8));
                        }
                        fprintf(fp, "    {\n");
                        if (pParm[n].specifier == 'd')
                        {
                            fprintf(fp, "        A_PRINTF(\"%sOp: %s %%d\\n\", %s->%s[i]);\n", 
                                            pCode, pParm[n].name, ptrName, pParm[n].name);
                        }
                        else if (pParm[n].specifier == 'u')
                        {
                            fprintf(fp, "        A_PRINTF(\"%sOp: %s %%u\\n\", %s->%s[i]);\n",
                                            pCode, pParm[n].name, ptrName, pParm[n].name);
                        }
                        else //(pParm[n].specifier == 'x')
                        {
                            fprintf(fp, "        A_PRINTF(\"%sOp: %s 0x%%x\\n\", %s->%s[i]);\n",
                                            pCode, pParm[n].name, ptrName, pParm[n].name);
                        }
                        fprintf(fp, "    }\n");
                    }
                }
            }
            fprintf(fp, "#endif //_DEBUG\n\n");
            fprintf(fp, "    if (NULL != %sOpFunc) {\n", pCode);
            fprintf(fp, "        (*%sOpFunc)(%s);\n", pCode, ptrName);
            fprintf(fp, "    }\n");
        }
        fprintf(fp, "    return(TRUE);\n");
        fprintf(fp, "}\n");
    }
    if (fp) fclose(fp);
    return TRUE;
}

static A_BOOL genHandlerH(char *inFile)
{
    FILE *fp;
    char inFileName[FILENAME_SIZE];
    char fileName[FILENAME_SIZE] = "output/";
    CMD_RSP_BUF *pBuf;
    PARM_ONE *pParm;
    char *pCode;
    A_UINT32 i, n, numElem, sizeCnt, padSize;
    char cmdPrefix[7];
    int cmdPrefixLen;

    if (isSysCmd)
    {
        strcpy(cmdPrefix, "SYSCMD");
    }
    else
    {
        strcpy(cmdPrefix, "CMD");
    }
    cmdPrefixLen = strlen(cmdPrefix) + 1; // + the _

    strcpy(inFileName, inFile);
    strcat(fileName, GetFileNameOnly(inFileName));
    fileName[strlen(fileName)-1] = 'h';
    if( (fp = fopen( fileName, "w")) == NULL ) 
    {
        printf("Failed to open %s\n", fileName);
        return FALSE;
    }
    fprintf(fp, "// This is an auto-generated file from %s\n", inFile);
    inFileName[strlen(inFileName)-2] = '\0';
    fprintf(fp, "#ifndef _%s_H_\n", str2Upper(inFileName));
    fprintf(fp, "#define _%s_H_\n\n", inFileName);
    fprintf(fp, "#if defined(__cplusplus) || defined(__cplusplus__)\n");
    fprintf(fp, "extern \"C\" {\n");
    fprintf(fp, "#endif\n\n");
    fprintf(fp, "#if defined(WIN32) || defined(WIN64)\n");
    fprintf(fp, "#pragma pack (push, 1)\n");
    fprintf(fp, "#endif //WIN32 || WIN64\n\n");
    
    for (i = 0; i < nextText; i++)
    {
        fprintf(fp, "%s", textBuf[i]);
    }
    if (i > 1)
    {
        fprintf(fp, "\n");
    }

    for (i = 0; i < 2; i++)
    {
        // 1st iteration: cmd; 2nd iteration: rsp
        pBuf = (i == 0) ? &cmdBuf: &rspBuf;
        if ((pBuf->code[0] == '\0') || (pBuf->numParm == 0)) continue;

        pCode = &pBuf->code[cmdPrefixLen]; //pass the prefix "CMD_" or "SYSCMD_"
        str2Lower(pCode);

        fprintf(fp, "typedef struct %s_parms {\n", pCode);

        pParm = &pBuf->parm[0];
        sizeCnt = 0;
        for (n = 0; n < pBuf->numParm; n++)
        {
            if (pParm[n].parmType == TYPE_SINGULAR)
            {
                fprintf(fp, "    %s\t%s;\n", GetTypeStr(&pParm[n]), pParm[n].name);
            }
            else //TYPE_ARRAY
            {
                if (pParm[n].isNumValueInText)
                {
                    fprintf(fp, "    %s\t%s[%s];\n", GetTypeStr(&pParm[n]), pParm[n].name, pParm[n].numValueInText);
                }
                else
                {
                    numElem = ((pParm[n].numValueHigh << 8) | pParm[n].numValueLow);
                    fprintf(fp, "    %s\t%s[%d];\n", GetTypeStr(&pParm[n]), pParm[n].name, numElem);
                }
            }
            sizeCnt += GetParmSize(&pParm[n]);
        }
        if (padSize = NeedPad(sizeCnt))
        {
            fprintf(fp, "    A_UINT8\tpad[%d];\n", padSize);
        }
        fprintf(fp, "} __ATTRIB_PACK %s_%s_PARMS;\n\n", cmdPrefix, str2Upper(pCode));
    }

    if (cmdBuf.code[0] != '\0')
    {
        str2Upper(cmdBuf.code);
        //fprintf(fp, "typedef void (*%s_OP_FUNC)(%s_PARMS *pParms);\n", &cmdBuf.code[cmdPrefixLen], cmdBuf.code);
        // In case the cmd/rsp has no parameter, then theren is no CMD_xxx_PARMS created. Hence, use void pointer 
        fprintf(fp, "typedef void (*%s_OP_FUNC)(void *pParms);\n", &cmdBuf.code[cmdPrefixLen]);
    }
    if (rspBuf.code[0] != '\0')
    {
        str2Upper(rspBuf.code);
        fprintf(fp, "typedef void (*%s_OP_FUNC)(void *pParms);\n", &rspBuf.code[cmdPrefixLen]);
    }
    fprintf(fp, "\n");
    fprintf(fp, "// Exposed functions\n");
    for (i = 0; i < 2; i++)
    {
        // 1st iteration: cmd; 2nd iteration: rsp
        pBuf = (i == 0) ? &cmdBuf: &rspBuf;
        if (pBuf->code[0] == '\0') continue;

        pCode = &pBuf->code[cmdPrefixLen]; //pass the prefix "CMD_"
        fprintf(fp, "\nvoid* init%sOpParms(A_UINT8 *pParmsCommon, PARM_OFFSET_TBL *pParmsOffset, PARM_DICT *pParmDict);\n", pCode);
        fprintf(fp, "A_BOOL %sOp(void *pParms);\n", pCode);
    }
    fprintf(fp, "\n#if defined(WIN32) || defined(WIN64)\n");
    fprintf(fp, "#pragma pack(pop)\n");
    fprintf(fp, "#endif //WIN32 || WIN64\n\n");
    fprintf(fp, "\n#if defined(__cplusplus) || defined(__cplusplus__)\n");
    fprintf(fp, "}\n");
    fprintf(fp, "#endif\n\n");
    fprintf(fp, "#endif //_%s_H_\n", inFileName);

    if (fp) fclose(fp);
    return TRUE;
}

static A_BOOL genTlv2ApiH(char *cmdFile)
{
    FILE *fIn, *fOut;
    char cmdFileName[FILENAME_SIZE];
    char inFile[FILENAME_SIZE];
    char outFile[FILENAME_SIZE];
    char lineBuf[MAX_INPUT_LINE];
    char endLine[MAX_INPUT_LINE];
    int cmdPrefixLen;

    if (isSysCmd)
    {
        strncpy(inFile, "../include/tlv2SysApi.h", sizeof(inFile));
        strncpy(outFile, "output/tlv2SysApi.h", sizeof(outFile));
        strncpy(endLine, "#endif // _TLV2_SYS_API_H_", sizeof(endLine));
        cmdPrefixLen = strlen("SYSCMD_");
    }
    else
    {
        strncpy(inFile, "../include/tlv2Api.h", sizeof(inFile));
        strncpy(outFile, "output/tlv2Api.h", sizeof(outFile));
        strncpy(endLine, "#endif // _TLV2_API_H_", sizeof(endLine));
        cmdPrefixLen = strlen("CMD_");
    }

    strcpy(cmdFileName, cmdFile);
    GetFileNameOnly(cmdFileName);
    cmdFileName[strlen(cmdFileName)-1] = 'h';
    if( (fIn = fopen( inFile, "r")) == NULL ) 
    {
        printf("Failed to open %s\n", inFile);
        return FALSE;
    }
    if( (fOut = fopen( outFile, "w")) == NULL ) 
    {
        printf("Failed to open %s\n", outFile);
        if (fIn) fclose(fIn);
        return FALSE;
    }

    while(fgets(lineBuf, MAX_INPUT_LINE, fIn) != NULL)
    {
        if (strstr(lineBuf, endLine) == lineBuf)
        {
            if (!(cmdCodeAlreadyIn || rspCodeAlreadyIn))
            {
                fprintf(fOut, "#include \"%s\"\n", cmdFileName);
            }
            if (!cmdCodeAlreadyIn && (cmdBuf.code[0] != '\0'))
            {
                fprintf(fOut, "TLV2_API void register%sHandler(%s_OP_FUNC fp);\n", &(cmdBuf.code[cmdPrefixLen]), &(cmdBuf.code[cmdPrefixLen]));
            }
            if (!rspCodeAlreadyIn && (rspBuf.code[0] != '\0'))
            {
                fprintf(fOut, "TLV2_API void register%sHandler(%s_OP_FUNC fp);\n", &(rspBuf.code[cmdPrefixLen]), &(rspBuf.code[cmdPrefixLen]));
            }
            fprintf(fOut, "\n");
        }
        fputs(lineBuf, fOut);
    }
    if (fIn) fclose(fIn);
    if (fOut) fclose(fOut);
    return TRUE;
}

static A_BOOL genCmdHandlerTblC()
{
    FILE *fIn, *fOut;
    char inFile[FILENAME_SIZE] = "../cmdParser/cmdHandlerTbl.c";
    char outFile[FILENAME_SIZE] = "output/cmdHandlerTbl.c";
    char lineBuf[MAX_INPUT_LINE];
    char addLine[MAX_INPUT_LINE];
    char *pCode;
    int cmdPrefixLen;

    if (isSysCmd)
    {
        strncpy(inFile, "../cmdParser/sysCmdHandlerTbl.c", sizeof(inFile));
        strncpy(outFile, "output/sysCmdHandlerTbl.c", sizeof(outFile));
        cmdPrefixLen = strlen("SYSCMD_");
    }
    else
    {
        strncpy(inFile, "../cmdParser/cmdHandlerTbl.c", sizeof(inFile));
        strncpy(outFile, "output/cmdHandlerTbl.c", sizeof(outFile));
        cmdPrefixLen = strlen("CMD_");
    }

    if( (fIn = fopen( inFile, "r")) == NULL ) 
    {
        printf("Failed to open %s\n", inFile);
        return FALSE;
    }
    if( (fOut = fopen( outFile, "w")) == NULL ) 
    {
        printf("Failed to open %s\n", outFile);
        if (fIn) fclose(fIn);
        return FALSE;
    }

    while(fgets(lineBuf, MAX_INPUT_LINE, fIn) != NULL)
    {
        if (strstr(lineBuf, "//auto-updated marker"))
        {
            if (!cmdCodeAlreadyIn && (cmdBuf.code[0] != '\0'))
            {
                str2Upper(cmdBuf.code);
                pCode = &cmdBuf.code[cmdPrefixLen];
                sprintf(addLine, "    {init%sOpParms, %sOp, NULL},\n", pCode, pCode);
                fprintf(fOut, addLine);   
            }
            if (!rspCodeAlreadyIn && (rspBuf.code[0] != '\0'))
            {
                str2Upper(rspBuf.code);
                pCode = &rspBuf.code[cmdPrefixLen];
                sprintf(addLine, "    {init%sOpParms, %sOp, NULL},\n", pCode, pCode);
                fprintf(fOut, addLine);   
            }
        }
        fputs(lineBuf, fOut);
    }
    if (fIn) fclose(fIn);
    if (fOut) fclose(fOut);
    return TRUE;
}

static A_BOOL genCmdHandlersH(char *cmdFile)
{
    FILE *fIn, *fOut;
    char cmdFileName[FILENAME_SIZE];
    char inFile[FILENAME_SIZE] = "../include/cmdHandlers.h";
    char outFile[FILENAME_SIZE] = "output/cmdHandlers.h";
    char lineBuf[MAX_INPUT_LINE];
    char addLine[MAX_INPUT_LINE];
    A_BOOL fileIncluded = FALSE;
    char cmdPrefix[7], rspPrefix[7];
    int cmdPrefixLen;

    if (isSysCmd)
    {
        strcpy(cmdPrefix, "sysCmd");
        strcpy(rspPrefix, "sysRsp");
        cmdPrefixLen = strlen("SYSCMD_");
    }
    else
    {
        strcpy(cmdPrefix, "cmd");
        strcpy(rspPrefix, "rsp");
        cmdPrefixLen = strlen("CMD_");
    }

    if( (fIn = fopen( inFile, "r")) == NULL ) 
    {
        printf("Failed to open %s\n", inFile);
        return FALSE;
    }
    if( (fOut = fopen( outFile, "w")) == NULL ) 
    {
        printf("Failed to open %s\n", outFile);
        if (fIn) fclose(fIn);
        return FALSE;
    }

    strcpy(cmdFileName, cmdFile);
    GetFileNameOnly(cmdFileName);
    cmdFileName[strlen(cmdFileName)-1] = 'h';

    while(fgets(lineBuf, MAX_INPUT_LINE, fIn) != NULL)
    {
        if (strstr(lineBuf, cmdFileName))
        {
            fileIncluded = TRUE;
        }
        else if (strstr(lineBuf, "//auto-updated marker") && !fileIncluded)
        {
            sprintf(addLine, "#include \"%s\"\n", cmdFileName);
            fprintf(fOut, addLine);   
        }
        else if(strstr(lineBuf, "    } __ATTRIB_PACK cmdParmU;")) 
        {
            if (!cmdCodeAlreadyIn && cmdBuf.numParm)
            {
                sprintf(addLine, "        %s_PARMS\t\t %s%sParms;\n", str2Upper(cmdBuf.code), cmdPrefix, &(cmdBuf.code[cmdPrefixLen]));
                fprintf(fOut, addLine);   
            }
            if (!rspCodeAlreadyIn && rspBuf.numParm)
            {
                sprintf(addLine, "        %s_PARMS\t\t %s%sParms;\n", str2Upper(rspBuf.code), rspPrefix, &(rspBuf.code[cmdPrefixLen]));
                fprintf(fOut, addLine);   
            }
        }

        fputs(lineBuf, fOut);
    }
    if (fIn) fclose(fIn);
    if (fOut) fclose(fOut);
    return TRUE;
}

static A_BOOL genCmdRspDictC()
{
    FILE *fpIn, *fpOut;
    char lineBuf[MAX_INPUT_LINE];
    int idx;
    char delimiters[] = " \t=\n";
    char inFile[FILENAME_SIZE];
    char outFile[FILENAME_SIZE];

    if (isSysCmd)
    {
        strncpy(inFile, "../common/sysCmdRspParmsDict.c", sizeof(inFile));
        strncpy(outFile, "output/sysCmdRspParmsDict.c", sizeof(outFile));
    }
    else
    {
        strncpy(inFile, "../common/cmdRspParmsDict.c", sizeof(inFile));
        strncpy(outFile, "output/cmdRspParmsDict.c", sizeof(outFile));
    }

    if( (fpIn = fopen( inFile, "r")) == NULL ) 
    {
        printf("Error in opening the %s file.\n", inFile);
        return FALSE;
    }
    if( (fpOut = fopen( outFile, "w")) == NULL ) 
    {
        printf("Error in opening the %s file.\n", outFile);
        if (fpIn) fclose(fpIn);
        return FALSE;
    }

    while(fgets(lineBuf, MAX_INPUT_LINE, fpIn) != NULL)
    {
        //commands
        if (strncmp(lineBuf, "CMD_DICT", strlen("CMD_DICT")) == 0)
        {
            fputs(lineBuf, fpOut);
            while(fgets(lineBuf, MAX_INPUT_LINE, fpIn) != NULL)
            {
                if (strncmp(lineBuf, "};", strlen("};")) == 0)
                {
                    for (idx = 0; idx < newCmdCnt ; idx++) 
                    {
                        //fprintf(fp, "    [%s]\n", CmdCodes[idx]);
                        fprintf(fpOut, "    {%s_RAND},\n", newCmdCodes[idx]);
                    }
                    fputs(lineBuf, fpOut);
                    break;
                }
                fputs(lineBuf, fpOut);
            }
        }
        //parameters
        else if (strncmp(lineBuf, "PARM_DICT", strlen("PARM_DICT")) == 0)
        {
            fputs(lineBuf, fpOut);
            while(fgets(lineBuf, MAX_INPUT_LINE, fpIn) != NULL)
            {
                if (strncmp(lineBuf, "};", strlen("};")) == 0)
                {
                    for (idx = 0; idx < newParmCnt; idx++) 
                    {
                        fprintf(fpOut, "    {%s_RAND, {(A_UINT32)%s}, %d, %s},\n", ParmCodes[NumParmCodes+idx], newParmValueStr[idx], (int)newHashNum[idx], newDataTypeStr[idx]);
                    }
                    fputs(lineBuf, fpOut);
                    break;
                }
                fputs(lineBuf, fpOut);
            }
        }
        else
        {
            fputs(lineBuf, fpOut);
        }
    }

    fclose(fpIn);
    fclose(fpOut);
    return TRUE;
}

static A_BOOL genCmdRspDictH()
{
    FILE *fpIn, *fpOut;
    int idx, nextCmdIdx, nextParmIdx;
    char lineBuf[MAX_INPUT_LINE];
    char inFile[FILENAME_SIZE] = "../include/cmdRspParmsDict.h";
    char outFile[FILENAME_SIZE] = "output/cmdRspParmsDict.h";
    char cmdLast[MAX_STR_LEN];
    char parmLast[MAX_STR_LEN];
    
    if( (fpIn = fopen( inFile, "r")) == NULL ) 
    {
        printf("Error in opening the %s file.\n", inFile);
        return FALSE;
    }
    if( (fpOut = fopen( outFile, "w")) == NULL ) 
    {
        printf("Error: could not generate the %s file.\n", outFile);
        if (fpIn) fclose(fpIn);
        return FALSE;
    }
#if 0
    fprintf(fp, "// This is an auto-generated file.\n");
    fprintf(fp, "// DON'T manually modify the file but use cmdRspDictGenSrc.exe.\n\n");
    fprintf(fp, "#if !defined(__CMD_RSP_AND_PARMS_DIC_H)\n");
    fprintf(fp, "#define __CMD_RSP_AND_PARMS_DIC_H\n\n");

    // command codes
    fprintf(fp, "// commands\n");
    fprintf(fp, "typedef enum cmdCodeEnum {\n");
    for (idx=0;idx<NumCmdCodes;idx++) {
        fprintf(fp, "    %s = %d,\n", CmdCodes[idx], idx);
        fprintf(fp, "        #define %s_RAND  %d\n", CmdCodes[idx], (int)CmdRandom[idx]);
    }
    for (idx = 0; idx < newCmdCnt ;idx++) {
        fprintf(fp, "    %s = %d,\n", newCmdCodes[idx], (NumCmdCodes + idx));
        fprintf(fp, "        #define %s_RAND  %u\n", newCmdCodes[idx], newCmdRandom[idx]);
    }
    fprintf(fp, "\n    CMD_LAST,\n");
    fprintf(fp, "    CMD_MAX  = CMD_LAST,\n");
    fprintf(fp, "} CMD_CODE;\n");
 
     // parameters
    fprintf(fp, "\n// parameters\n");
    fprintf(fp, "typedef enum parmCodeEnum {\n");
    for (idx=0;idx<NumParmCodes;idx++) {
        fprintf(fp, "    %s = %d,\n", ParmCodes[idx], idx);
        fprintf(fp, "        #define %s_RAND  %d\n", ParmCodes[idx], (int)ParmRandom[idx]);
    }
    for (idx = 0; idx < newParmCnt; idx++) {
        fprintf(fp, "    %s = %d,\n", ParmCodes[NumParmCodes+idx], NumParmCodes+idx);
        fprintf(fp, "        #define %s_RAND  %u\n", ParmCodes[NumParmCodes+idx], newParmRandom[idx]);
    }
    fprintf(fp, "\n    PARM_LAST,\n");
    fprintf(fp, "    PARM_MAX = PARM_LAST,\n");
    fprintf(fp, "} PARM_CODE;\n");

    fprintf(fp, "\n#endif //#if !defined(__CMD_RSP_AND_PARMS_DIC_H)\n");
#endif //0

    if (isSysCmd)
    {
        strncpy(cmdLast, "    SYSCMD_LAST", sizeof(cmdLast));
        strncpy(parmLast, "    SYSPARM_LAST", sizeof(parmLast));
        nextCmdIdx = NumCmdCodes + SYSCMD_FIRST_IDX;
        nextParmIdx = NumParmCodes + SYSPARM_FIRST_IDX;
    }
    else
    {
        strncpy(cmdLast, "    CMD_LAST", sizeof(cmdLast));
        strncpy(parmLast, "    PARM_LAST", sizeof(parmLast));
        nextCmdIdx = NumCmdCodes;
        nextParmIdx = NumParmCodes;
    }

    while(fgets(lineBuf, MAX_INPUT_LINE, fpIn) != NULL)
    {
        //commands
        if (strstr(lineBuf, cmdLast) == lineBuf)
        {
            printf("Adding %d new commands to cmdRspParmsDict.h\n", newCmdCnt);
            for (idx = 0; idx < newCmdCnt ;idx++) 
            {
                fprintf(fpOut, "    %s = %d,\n", newCmdCodes[idx], (nextCmdIdx + idx));
                fprintf(fpOut, "        #define %s_RAND  %u\n", newCmdCodes[idx], newCmdRandom[idx]);
            }
        }
        //parameters
        if (strstr(lineBuf, parmLast) == lineBuf)
        {
            printf("Adding %d new parameters to cmdRspParmsDict.h\n", newParmCnt);
            for (idx = 0; idx < newParmCnt; idx++) 
            {
                fprintf(fpOut, "    %s = %d,\n", ParmCodes[NumParmCodes+idx], nextParmIdx+idx);
                fprintf(fpOut, "        #define %s_RAND  %u\n", ParmCodes[NumParmCodes+idx], newParmRandom[idx]);
            }
        }
        fputs(lineBuf, fpOut);
    }

    fclose(fpIn);
    fclose(fpOut);
    return TRUE;
}



