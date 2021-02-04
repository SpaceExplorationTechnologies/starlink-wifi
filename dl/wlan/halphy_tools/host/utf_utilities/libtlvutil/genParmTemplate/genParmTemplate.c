#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifdef _WINDOWS
#include <ctype.h>
#endif //_WINDOW

#include "wlantype.h"
#include "otaHostCommon.h"
#include "cmdStream.h"


typedef enum {
    PARM_NOTYET,
    PARM_BEGIN,
    PARM_DONE
} PARMH_PARSER_STATE;

#define OUTPUT_PATH		"outputTemplate"

A_BOOL parseParmHFile(char *fileName)
{
    FILE *fStream, *fpOut = NULL, *fpHeaderOut = NULL, *fpBinOut = NULL;
    char lineBuf[LINEBUF_SIZE], *pLine;
    char delimiters[] = " ;\t\n\r/*";
    char type[KEY_SIZE_MAX];
    char type2[KEY_SIZE_MAX];
    char parmStructName[KEY_SIZE_MAX];
    char parmName[KEY_SIZE_MAX];
    char tempParmName[DATA_SIZE_MAX] = {0};
    char outFile[DATA_SIZE_MAX] = {0};
    char outHeaderFile[DATA_SIZE_MAX] = {0};
    char outBinFile[DATA_SIZE_MAX] = {0};
    int cmdStreamPos=0;
    //A_UINT8 curCmdOpcode;
    PARMH_PARSER_STATE parserState= PARM_NOTYET;
    //A_UINT32 numOfTemplateParms;
    int size, offset;
    A_BOOL parmValid=FALSE;
    _PARM_TYPE parmType;
    char *ch;
    int i, numElem, newSize, numElem_temp;
    int totalNumParms;
    int digit=0;
	char *saveptr;
 
    if( (fStream = fopen( fileName, "r")) == NULL ) {
        printf("Failed to open %s \n", fileName);
        return(FALSE);
    }

    offset=0;
    totalNumParms=0;
    memset((void*)parmStructName, 0, sizeof(parmStructName));
    while(fgets(lineBuf, LINEBUF_SIZE-1, fStream) != NULL) {
        pLine = lineBuf;

        while(isspace(*pLine)) pLine++;

        if(*pLine == '#' || *pLine == '/') {
            continue;
        }
    
        pLine = strtok_r(pLine, delimiters, &saveptr);
        if (pLine == NULL) { continue; }

        memset((void*)type, 0, sizeof(type));
        memset((void*)type2, 0, sizeof(type2));
        memset((void*)parmName, 0, sizeof(parmName));
        if (!sscanf(pLine, "%s", type)) {
            printf("Error reading key out of %s\n", pLine);
            continue;
        }
        if (PARM_NOTYET == parserState) {
          if ( 0 == strcmp(type, "typedef")) {

            pLine = strtok_r(NULL, delimiters,&saveptr);
            if (pLine == NULL) { continue; }
            if (!sscanf(pLine, "%s", type2)) {
                printf("Error reading type2 out of %s\n", pLine);
                continue;
            }
            if (0 == strcmp(type2, "struct")) {
                pLine = strtok_r(NULL, delimiters,&saveptr);
                if (pLine == NULL) { continue; }
                if (!sscanf(pLine, "%s", parmStructName)) {
                    printf("Error reading parmStructName out of %s\n", pLine);
                    continue;
                }
                parserState = PARM_BEGIN;

                { // txt template file
                //outputTemplate the first line
                if( (strlen("%s/_cmd%sTxtTemplate.h") + strlen(OUTPUT_PATH) + strlen(parmStructName)) <= DATA_SIZE_MAX ) 
                {
     		    snprintf(outHeaderFile, sizeof(outHeaderFile),"%s/_cmd%sTxtTemplate.h", OUTPUT_PATH, parmStructName);
                }
                if( (fpHeaderOut = fopen( outHeaderFile, "w")) == NULL ) {
                    printf("Failed to open %s \n", outHeaderFile);
                    return(FALSE);
                }                
                if( (strlen("%s/_cmd%sTxtTemplate.c") + strlen(OUTPUT_PATH) + strlen(parmStructName)) <= DATA_SIZE_MAX ) 
                {
                    snprintf(outFile, sizeof(outFile),"%s/_cmd%sTxtTemplate.c", OUTPUT_PATH, parmStructName);
                }
                if( (fpOut = fopen( outFile, "w")) == NULL ) {
                    printf("Failed to open %s \n", outFile);
                    return(FALSE);
                }
                fprintf(fpOut, "//This is an auto-generated file, from the given header file %s\n", fileName);
                fprintf(fpOut, "#include \"parmTxtTemplate.h\"\n\n");
                fprintf(fpOut, "_TESTFLOW_TXT_PARM_TEMPLATE %s_txt_template[] = {\n", parmStructName);

                fprintf(fpHeaderOut, "//This is an auto-generated file, from the given header file %s\n", fileName);
                fprintf(fpHeaderOut, "#include \"parmTxtTemplate.h\"\n\n");
                //fprintf(fpHeaderOut, "extern _TESTFLOW_TXT_PARM_TEMPLATE %s_txt_template[];\n", parmStructName);
                }

                { // bin template file
                //outputTemplate the first line
                if( (strlen("%s/_cmd%sBinTemplate.c") + strlen(OUTPUT_PATH) + strlen(parmStructName)) <= DATA_SIZE_MAX )
                {
                	snprintf(outBinFile, sizeof(outBinFile),"%s/_cmd%sBinTemplate.c", OUTPUT_PATH, parmStructName);
                }
                if( (fpBinOut = fopen( outBinFile, "w")) == NULL ) {
                    printf("Failed to open %s \n", outBinFile);
                    return(FALSE);
                }
                fprintf(fpBinOut, "//This is an auto-generated file, from the given header file %s ", fileName);
                fprintf(fpBinOut, "//for parsing the tx cmd parms in the binary stream\n");
                fprintf(fpBinOut, "//The filename is basically the parm struct name with _cmd as prefix and BinTemplate appended, hence \"_cmd_txParmsBinTemplate.h\"\n");
                fprintf(fpBinOut, "//The template definition is the struct name appened with bin_template, thus _txParm_bin_template\n");
                fprintf(fpBinOut, "#if !defined(_FOR_HOST_TESTING)\n");
                fprintf(fpBinOut, "#include \"osapi.h\"\n");
                fprintf(fpBinOut, "#endif\n");
                fprintf(fpBinOut, "#include \"wlantype.h\"\n");
                fprintf(fpBinOut, "#include \"parmBinTemplate.h\"\n\n");
                fprintf(fpBinOut, "_PARM_BIN_TEMPLATE %s_bin_template[] = {\n", parmStructName);
                }

                continue;
            }
          }
        }
        if ( PARM_BEGIN == parserState) {
            parmValid = TRUE;
            if (0 == strcmp(type, "A_UINT32")) { size=4; parmType = _PARM_U32;}
            else if (0 == strcmp(type, "A_INT32")) { size=4; parmType = _PARM_S32;}
            else if (0 == strcmp(type, "A_UINT16")) { size=2; parmType = _PARM_U16;}
            else if (0 == strcmp(type, "A_INT16")) { size=2; parmType = _PARM_S16;}
            else if (0 == strcmp(type, "A_INT8")) { size=1; parmType = _PARM_S8;}
            else if (0 == strcmp(type, "}")) { parserState = PARM_DONE; parmValid = FALSE; }
            else if ((0 == strcmp(type, "A_UINT8")) || (0 == strcmp(type, "A_UCHAR")) ) { 
                parmType = _PARM_U8;
                size=1; 
            }
            else {
                parmValid = FALSE;
                printf("Parm data type %s not supported\n", type);
                continue;  // skip the rest, it's not one of the data type supported
            }
            if (parmValid) {
                pLine = strtok_r(NULL, delimiters,&saveptr);
                if (pLine == NULL) { continue; }
                if (!sscanf(pLine, "%s", parmName)) {
                    printf("Error reading parm name out of %s\n", pLine);
                    continue;
                }
                if ((_PARM_U8 == parmType) || (_PARM_S8 == parmType)) {
                    //strcpy(tempParmName, parmName);
                    if (NULL != (ch = strchr(parmName, '['))) {
                        *ch = '\0';
                        pLine = strtok_r(NULL, delimiters,&saveptr);
                        if (pLine == NULL) { continue; }
                        if (!sscanf(pLine,"%d", &newSize)) {
                            printf("Error reading numElem out of parm name out of %s\n", parmName);
                            continue;
                        }
                        size = newSize;
                    }
		    fprintf(fpOut, "    {\"%s\", %d, %d, %d},\n", parmName, parmType, offset, size);
		    fprintf(fpBinOut, "    {%d, %d},\n", offset, size);
		    offset += size;
                    totalNumParms++;
                }
                else {
                    numElem = 1;
                    if (NULL != (ch = strchr(parmName, '['))) {
                        *ch = '\0';
                        pLine = strtok_r(NULL, delimiters,&saveptr);
                        if (pLine == NULL) { continue; }
                        if (!sscanf(pLine,"%d", &numElem)) {
                            printf("Error reading numElem out of parm name out of %s\n", parmName);
                            continue;
                        }
                    }
                    numElem_temp = numElem;
                    while(numElem_temp!=0)
                    {
                         numElem_temp/=10;
                         ++digit;
                    }

                    for (i=0;i<numElem;i++) {
		        //outputTemplate to the file
		        if ((1 == numElem) && (strlen(parmName) <=  DATA_SIZE_MAX))
                            snprintf(tempParmName, sizeof(tempParmName),"%s", parmName);
                        else
                        {   
                            if((strlen(parmName)+ digit) <=  DATA_SIZE_MAX)
                            snprintf(tempParmName, sizeof(tempParmName),"%s%d", parmName, i);
                        }
		        fprintf(fpOut, "    {\"%s\", %d, %d, %d},\n", tempParmName, parmType, offset, size);
		        fprintf(fpBinOut, "    {%d, %d},\n", offset, size);
		        offset += size;
                        totalNumParms++;
                    }
                }
            }
	}
        if (PARM_DONE == parserState) {
            fprintf(fpOut, "};\n");
            fprintf(fpBinOut, "};\n");
            fprintf(fpHeaderOut, "#define NUM_OF_%s sizeof(%s_txt_template)/sizeof(_TESTFLOW_TXT_PARM_TEMPLATE)\n",
                parmStructName, parmStructName);
            //fprintf(fpHeaderOut, "extern _TESTFLOW_TXT_PARM_TEMPLATE %s_txt_template[NUM_OF_%s];\n", parmStructName, parmStructName);
            fprintf(fpHeaderOut, "extern _TESTFLOW_TXT_PARM_TEMPLATE %s_txt_template[%d/*NUM_OF_%s*/];\n", parmStructName, totalNumParms, parmStructName);
            //fprintf(fpBinOut, "#define NUM_OF_%s sizeof(%s_bin_template)/sizeof(_TESTFLOW_TXT_PARM_TEMPLATE)",
            //    parmStructName, parmStructName);
            break;
        }

    } // End of line parsing
    fclose(fStream);
    if (fpOut)
        fclose(fpOut);
    if (fpHeaderOut)
        fclose(fpHeaderOut);
    if (fpBinOut)
        fclose(fpBinOut);

    return(TRUE);
}

// Usage:
//    genParmTemplate.out cmdTxParms.h  => _cmd_txParmsTemplate.c
//    genParmTemplate.out cmdRxParms.h  => _cmd_rxParmsTemplate.c
//    
int main(int argc, char *argv[])
{
    if (2 != argc) {
        printf("Usage: genParmTemplate <parm.h>\n");
        return(0);
    }

    if (!parseParmHFile(argv[1])) {
        printf("Error: parsing parm h file %s\n", argv[1]);
        return(-1);
    }

    return(0);
}


