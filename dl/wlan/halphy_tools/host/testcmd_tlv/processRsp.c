/*
 * Copyright (c) 2006 Atheros Communications Inc.
 * All rights reserved.
 *
 * $ATH_LICENSE_HOSTSDK0_C$
 *
 */
/*
 * Copyright (c) 2013 Qualcomm Atheros, Inc.
 * All Rights Reserved.
 * Qualcomm Atheros Confidential and Proprietary.
 */

#include <stdio.h>
#include <string.h>

#ifdef LINUX
#include <athdefs.h>
#include <athtypes_linux.h>
#else //WIN32
#include "wlantype.h"
#endif //LINUX

#include <testcmd.h>
#include "cmdOpcodes.h"
#include "tcmdHostInternal.h"
#include "maskRateCommon.h"
#include "art_utf_common.h"
#include "genTxBinCmdTlv.h"
#include "cmdStream.h"
#include "parseRxBinCmdTlv.h"
#include "dkCmdIds.h"
#include "cmdRspParmsInternal.h"
#include "cmdRspParmsDict.h"
#include "parseBinCmdStream.h"
#include "tlvCmdEncoder.h"
#include "tlv2Api.h"
#include "tlv2SysApi.h"
#include "processRsp.h"

#define FALSE       0
#define TRUE        1

RATE_STR  bgRateStrTbl[G_RATE_NUM] = {
    { "1   Mb" },
    { "2   Mb" },
    { "5.5 Mb" },
    { "11  Mb" },
    { "6   Mb" },
    { "9   Mb" },
    { "12  Mb" },
    { "18  Mb" },
    { "24  Mb" },
    { "36  Mb" },
    { "48  Mb" },
    { "54  Mb" },
    { "HT20 MCS0 6.5   Mb" },
    { "HT20 MCS1 13    Mb" },
    { "HT20 MCS2 19.5  Mb" },
    { "HT20 MCS3 26    Mb" },
    { "HT20 MCS4 39    Mb" },
    { "HT20 MCS5 52    Mb" },
    { "HT20 MCS6 58.5  Mb" },
    { "HT20 MCS7 65    Mb" },
    { "HT20 MCS8 13    Mb" },
    { "HT20 MCS9 26    Mb" },
    { "HT20 MCS10 39   Mb" },
    { "HT20 MCS11 52   Mb" },
    { "HT20 MCS12 78   Mb" },
    { "HT20 MCS13 104  Mb" },
    { "HT20 MCS14 117  Mb" },
    { "HT20 MCS15 130  Mb" },
    { "HT20 MCS16 19.5 Mb" },
    { "HT20 MCS17 39   Mb" },
    { "HT20 MCS18 58.5 Mb" },
    { "HT20 MCS19 78   Mb" },
    { "HT20 MCS20 117  Mb" },
    { "HT20 MCS21 156  Mb" },
    { "HT20 MCS22 175.5  Mb" },
    { "HT20 MCS23 195    Mb" },
    { "HT40 MCS0 13.5    Mb" },
    { "HT40 MCS1 27.0    Mb" },
    { "HT40 MCS2 40.5    Mb" },
    { "HT40 MCS3 54      Mb" },
    { "HT40 MCS4 81      Mb" },
    { "HT40 MCS5 108     Mb" },
    { "HT40 MCS6 121.5   Mb" },
    { "HT40 MCS7 135     Mb" },
    { "HT40 MCS8 27      Mb" },
    { "HT40 MCS9 54      Mb" },
    { "HT40 MCS10 81     Mb" },
    { "HT40 MCS11 108    Mb" },
    { "HT40 MCS12 162    Mb" },
    { "HT40 MCS13 216    Mb" },
    { "HT40 MCS14 243    Mb" },
    { "HT40 MCS15 270    Mb" },
    { "HT40 MCS16 40.5   Mb" },
    { "HT40 MCS17 81     Mb" },
    { "HT40 MCS18 121.5  Mb" },
    { "HT40 MCS19 162    Mb" },
    { "HT40 MCS20 243    Mb" },
    { "HT40 MCS21 324    Mb" },
    { "HT40 MCS22 364.5  Mb" },
    { "HT40 MCS23 405    Mb" },
    { "VHT20 MCS0 S1 6.5 Mb" }, //60
    { "VHT20 MCS1 S1 13 Mb" },
    { "VHT20 MCS2 S1 19.5 Mb" },
    { "VHT20 MCS3 S1 26 Mb" }, //63
    { "VHT20 MCS4 S1 39 Mb" },
    { "VHT20 MCS5 S1 52 Mb" },
    { "VHT20 MCS6 S1 58.5 Mb" },
    { "VHT20 MCS7 S1 65 Mb" },
    { "VHT20 MCS8 S1 78 Mb" },
    { "VHT20 MCS9 S1 86 Mb" },
    { "VHT20 MCS0 S2 13 Mb" },
    { "VHT20 MCS1 S2 26 Mb" },
    { "VHT20 MCS2 S2 39 Mb" },
    { "VHT20 MCS3 S2 52 Mb" },
    { "VHT20 MCS4 S2 78 Mb" },
    { "VHT20 MCS5 S2 104 Mb" },
    { "VHT20 MCS6 S2 117 Mb" },
    { "VHT20 MCS7 S2 130 Mb" },
    { "VHT20 MCS8 S2 156 Mb" },
    { "VHT20 MCS9 S2 173" },
    { "VHT20 MCS0 S3 19.5 Mb" },
    { "VHT20 MCS1 S3 39 Mb" },
    { "VHT20 MCS2 S3 58.5 Mb" },
    { "VHT20 MCS3 S3 78 Mb" },
    { "VHT20 MCS4 S3 117 Mb" },
    { "VHT20 MCS5 S3 156 Mb" },
    { "VHT20 MCS6 S3 175.5 Mb" },
    { "VHT20 MCS7 S3 195 Mb" },
    { "VHT20 MCS8 S3 234 Mb" },
    { "VHT20 MCS9 S3 260 Mb" },
    { "VHT40 MCS0 S1 13.5 Mb" },
    { "VHT40 MCS1 S1 27 Mb" },
    { "VHT40 MCS2 S1 40.5 Mb" },
    { "VHT40 MCS3 S1 54 Mb" },
    { "VHT40 MCS4 S1 81 Mb" },
    { "VHT40 MCS5 S1 108 Mb" },
    { "VHT40 MCS6 S1 121.5 Mb" },
    { "VHT40 MCS7 S1 135 Mb" },
    { "VHT40 MCS8 S1 162 Mb" },
    { "VHT40 MCS9 S1 180 Mb" },
    { "VHT40 MCS0 S2 27 Mb" },
    { "VHT40 MCS1 S2 54 Mb" },
    { "VHT40 MCS2 S2 81 Mb" },
    { "VHT40 MCS3 S2 108 Mb" },
    { "VHT40 MCS4 S2 162 Mb" },
    { "VHT40 MCS5 S2 216 Mb" },
    { "VHT40 MCS6 S2 243 Mb" },
    { "VHT40 MCS7 S2 270 Mb" },
    { "VHT40 MCS8 S2 324 Mb" },
    { "VHT40 MCS9 S2 360 Mb" },
    { "VHT40 MCS0 S3 40.5 Mb" },
    { "VHT40 MCS1 S3 81 Mb" },
    { "VHT40 MCS2 S3 121.5 Mb" },
    { "VHT40 MCS3 S3 162 Mb" },
    { "VHT40 MCS4 S3 243 Mb" },
    { "VHT40 MCS5 S3 324 Mb" },
    { "VHT40 MCS6 S3 364.5 Mb" },
    { "VHT40 MCS7 S3 405 Mb" },
    { "VHT40 MCS8 S3 486 Mb" },
    { "VHT40 MCS9 S3 540 Mb" },
    { "VHT80 MCS0 S1 29.3 Mb" },
    { "VHT80 MCS1 S1 58.5 Mb" },
    { "VHT80 MCS2 S1 87.8 Mb" },
    { "VHT80 MCS3 S1 117 Mb" },
    { "VHT80 MCS4 S1 175.5 Mb" },
    { "VHT80 MCS5 S1 234 Mb" },
    { "VHT80 MCS6 S1 263.3 Mb" },
    { "VHT80 MCS7 S1 292.5 Mb" },
    { "VHT80 MCS8 S1 351 Mb" },
    { "VHT80 MCS9 S1 390 Mb" },
    { "VHT80 MCS0 S2 58.5 Mb" },
    { "VHT80 MCS1 S2 117 Mb" },
    { "VHT80 MCS2 S2 175.5 Mb" },
    { "VHT80 MCS3 S2 234 Mb" },
    { "VHT80 MCS4 S2 351 Mb" },
    { "VHT80 MCS5 S2 468 Mb" },
    { "VHT80 MCS6 S2 526.5 Mb" },
    { "VHT80 MCS7 S2 585 Mb" },
    { "VHT80 MCS8 S2 702 Mb" },
    { "VHT80 MCS9 S2 780 Mb" },
    { "VHT80 MCS0 S3 87.8 Mb" },
    { "VHT80 MCS1 S3 175.5 Mb" },
    { "VHT80 MCS2 S3 263.3 Mb" },
    { "VHT80 MCS3 S3 351 Mb" },
    { "VHT80 MCS4 S3 526.5 Mb" },
    { "VHT80 MCS5 S3 702 Mb" },
    { "VHT80 MCS6 S3 789.8 Mb" },
    { "VHT80 MCS7 S3 877.5 Mb" },
    { "VHT80 MCS8 S3 1053 Mb" },
    { "VHT80 MCS9 S3 1170 Mb" },
/* below portion(CCK short preamble rates should always be placed to the end */
    { "2(S)   Mb" },
    { "5.5(S) Mb" },
    { "11(S)  Mb" },
/* Below rates are for 4x4 11ac */
    { "VHT20 MCS0 S4 26 Mb" }, //153
    { "VHT20 MCS1 S4 52 Mb" },
    { "VHT20 MCS2 S4 78 Mb" },
    { "VHT20 MCS3 S4 104 Mb" },
    { "VHT20 MCS4 S4 156 Mb" },
    { "VHT20 MCS5 S4 208 Mb" },
    { "VHT20 MCS6 S4 234 Mb" },
    { "VHT20 MCS7 S4 260 Mb" },
    { "VHT20 MCS8 S4 312 Mb" },
    { "VHT20 MCS9 S4 NA " },
    { "VHT40 MCS0 S4 54 Mb" }, //163
    { "VHT40 MCS1 S4 108 Mb" },
    { "VHT40 MCS2 S4 162 Mb" },
    { "VHT40 MCS3 S4 216 Mb" },
    { "VHT40 MCS4 S4 324 Mb" },
    { "VHT40 MCS5 S4 432 Mb" },
    { "VHT40 MCS6 S4 486 Mb" },
    { "VHT40 MCS7 S4 540 Mb" },
    { "VHT40 MCS8 S4 648 Mb" },
    { "VHT40 MCS9 S4 720 Mb" },
    { "VHT80 MCS0 S4 117 Mb" }, //173
    { "VHT80 MCS1 S4 234 Mb" },
    { "VHT80 MCS2 S4 351 Mb" },
    { "VHT80 MCS3 S4 468 Mb" },
    { "VHT80 MCS4 S4 702 Mb" },
    { "VHT80 MCS5 S4 936 Mb" },
    { "VHT80 MCS6 S4 1053 Mb" },
    { "VHT80 MCS7 S4 1170 Mb" },
    { "VHT80 MCS8 S4 1404 Mb" },
    { "VHT80 MCS9 S4 1560 Mb" }, // 182

    { "VHT160 MCS0 S1  Mb" },  // 183
    { "VHT160 MCS1 S1  Mb" },
	{ "VHT160 MCS2 S1  Mb" },
	{ "VHT160 MCS3 S1  Mb" },
	{ "VHT160 MCS4 S1  Mb" },
	{ "VHT160 MCS5 S1  Mb" },
	{ "VHT160 MCS6 S1  Mb" },
	{ "VHT160 MCS7 S1  Mb" },
	{ "VHT160 MCS8 S1  Mb" },
	{ "VHT160 MCS9 S1  Mb" },

    { "VHT160 MCS0 S2  Mb" },
    { "VHT160 MCS1 S2  Mb" },
	{ "VHT160 MCS2 S2  Mb" },
	{ "VHT160 MCS3 S2  Mb" },
	{ "VHT160 MCS4 S2  Mb" },
	{ "VHT160 MCS5 S2  Mb" },
	{ "VHT160 MCS6 S2  Mb" },
	{ "VHT160 MCS7 S2  Mb" },
	{ "VHT160 MCS8 S2  Mb" },
	{ "VHT160 MCS9 S2  Mb" },	// 202

};

A_BOOL replyReceived = FALSE;

void parseResponse()
{
    A_BOOL ret = TRUE;
    A_UINT8 *data;
    A_UINT32 status,len;

    ret = getParams((A_UINT8*)"status", &data, &len);

    if ( ret == TRUE )
    {
        memcpy(&status,data,len);
        printf("Response status %d\n",status);
    }
    else
        printf("In parseResponse status not found\n");
}

void parseTLVSubmitReport()
{
    A_BOOL ret = TRUE;
    A_UINT8 *data;
    A_UINT32 value,len,i,k;
    A_UINT32 totalpkt = 0;
    A_INT32 rssi;
    A_UINT8 rateCntBuf[25];
    A_UINT32 rateMask,rateMaskCnt[2],shortGuard,dataRate,index=0;
    A_UINT32 rate11ACMaskCnt[4];
    A_UINT32 bit0 = 0x00000001;
    A_UINT32 rcMaskac4x4=0;


    ret = getParams((A_UINT8*)"totalpkt", &data, &len);

    if ( ret == TRUE )
    {
        memcpy(&totalpkt,data,len);
        printf("totalpkt %d\n",totalpkt);
    }

    ret = getParams((A_UINT8*)"rssiInDBm", &data, &len);

    if ( ret == TRUE )
    {
        memcpy(&rssi,data,len);

        if(totalpkt)
            printf("rssiInDBm %d\n",rssi/(A_INT32)totalpkt);
        else
            printf("rssiInDBm %d\n",rssi);
    }

    ret = getParams((A_UINT8*)"crcErrPkt", &data, &len);

    if ( ret == TRUE )
    {
        memcpy(&value,data,len);
        printf("crcErrPkt %d\n",value);
    }

    ret = getParams((A_UINT8*)"secErrPkt", &data, &len);

    if ( ret == TRUE )
    {
        memcpy(&value,data,len);
        printf("secErrPkt %d\n",value);
    }

    ret = getParams((A_UINT8*)"rcMaskac4x4", &data, &len);

    if ( ret == TRUE )
    {
        memcpy(&rcMaskac4x4,data,len);
        printf("rcMask 4x4 %d\n",rcMaskac4x4);
    }


    for(i=0;i<2;i++)
    {
        memset(rateCntBuf,0,sizeof(rateCntBuf));
        snprintf((char*)rateCntBuf,sizeof(rateCntBuf),"%s%d","rcMask",i);
        ret = getParams((A_UINT8*)rateCntBuf,&data,&len);

        if ( ret == TRUE )
        {
            memcpy(&rateMaskCnt[i],data,len);
            //printf("%s %x\n",rateCntBuf,rateMaskCnt[i]);
        }
        else
        {
            rateMaskCnt[i] = 0;
        }
    }

    for(i=0;i<4;i++)
    {
        memset(rateCntBuf,0,sizeof(rateCntBuf));
        snprintf((char*)rateCntBuf,sizeof(rateCntBuf),"%s%d","rcMask11ac",i);
        ret = getParams((A_UINT8*)rateCntBuf,&data,&len);

        if ( ret == TRUE )
        {
            memcpy(&rate11ACMaskCnt[i],data,len);
            //printf("%s %x\n",rateCntBuf,rate11ACMaskCnt[i]);
        }
        else
        {
            rate11ACMaskCnt[i] = 0;
        }
    }

    ret = getParams((A_UINT8*)"shortGuard", &data, &len);

    if ( ret == TRUE )
    {
        memcpy(&shortGuard,data,len);

        if ( shortGuard )
            printf("<<<<SGI set >>>>\n");
    }

    //11n and below rates..
    for (k=0;k<2;k++)
    {
        rateMask = rateMaskCnt[k];
        i=0; bit0=0x00000001;
        while (rateMask)
        {
            if (bit0 & rateMask)
            {
                rateMask &= ~bit0;
                dataRate = Mask2Rate[k][i];

                if (dataRate == ATH_RATE_2M || dataRate == ATH_RATE_5_5M || dataRate == ATH_RATE_11M){ /* CCK rates */
                    if (!(i&1)) /* even number indicates short preamble, see Mask2Rate array for details */
                        dataRate += (TCMD_MAX_RATES_11AC_3x3 - 4);/* use last three rates in the rate table for shortPreamble */
                }

                //printf("RateCnt bit set %d dataRate %d %s\n",(k*32+i),dataRate,bgRateStrTbl[dataRate]);
                printf("%s .. ",bgRateStrTbl[dataRate]);

                index = (k*32+i)/2;

                memset(rateCntBuf,0,sizeof(rateCntBuf));
                snprintf((char*)rateCntBuf,sizeof(rateCntBuf),"%s%d","rateCnt",index);
                ret = getParams((A_UINT8*)rateCntBuf,&data,&len);

                if ( ret == TRUE )
                {
                    memcpy(&value,data,len);

                    if (i && !(i&1))
                        printf("rateCnt %d\n",(value & 0xFFFF));
                    else {
                        if (i && (i&1)) {
                            printf("rateCnt %d\n",(value >>16) & 0xFFFF);
                        }
                        else{
                            printf("rateCnt %d\n",(value & 0xFFFF));
                        }
                    }
                }
                else {
                    printf("rateCnt ..%d\n",0);
                }
	    }

            bit0 = bit0 << 1;i++;
        }
    }

    //11ac rates..
    for (k=0;k<4;k++)
    {
        rateMask = rate11ACMaskCnt[k];
        i=0; bit0=0x00000001;
        while (rateMask)
        {
            if (bit0 & rateMask)
            {
                rateMask &= ~bit0;
                index = k + 2;
                dataRate = Mask2Rate[index][i];
                //printf("11ac RateCnt bit set %d dataRate %d %s\n",(k*32+i),dataRate,bgRateStrTbl[dataRate]);
                printf("%s .. ",bgRateStrTbl[dataRate]);

                index = (k*32+i)/2;

                memset(rateCntBuf,0,sizeof(rateCntBuf));
                snprintf((char*)rateCntBuf,sizeof(rateCntBuf),"%s%d","rateCnt11ac",index);
                ret = getParams((A_UINT8*)rateCntBuf,&data,&len);

                if ( ret == TRUE )
                {
                    memcpy(&value,data,len);

                    if (i && !(i&1))
                        printf("rateCnt %d\n",(value & 0xFFFF));
                    else {
                        if (i && (i&1)) {
                            printf("rateCnt %d\n",(value >>16) & 0xFFFF);
                        }
                        else{
                            printf("rateCnt %d\n",(value & 0xFFFF));
                        }
                    }
                }
                else {
                    printf("\n");
                }
            }

            bit0 = bit0 << 1;i++;
        }
    }


    //4x4 11ac rates..
    for (k=0;k<1;k++)
    {
        rateMask = rcMaskac4x4;
        i=0; bit0=0x00000001;
        while (rateMask)
        {
            if (bit0 & rateMask)
            {
                rateMask &= ~bit0;
                index = 6; //4x4 11ac
                dataRate = Mask2Rate[index][i];
                printf("%s .. ",bgRateStrTbl[dataRate]);

                index = (k*32+i)/2;

                memset(rateCntBuf,0,sizeof(rateCntBuf));
                snprintf((char*)rateCntBuf,sizeof(rateCntBuf),"%s%d","rtCntac4x4",index);
                ret = getParams((A_UINT8*)rateCntBuf,&data,&len);

                if ( ret == TRUE )
                {
                    memcpy(&value,data,len);

                    if (i && !(i&1))
                        printf("rateCnt %d\n",(value & 0xFFFF));
                    else {
                        if (i && (i&1)) {
                            printf("rateCnt %d\n",(value >>16) & 0xFFFF);
                        }
                        else{
                            printf("rateCnt %d\n",(value & 0xFFFF));
                        }
                    }
                }
                else {
                    printf("\n");
                }
            }

            bit0 = bit0 << 1;i++;
        }
    }
}

void parseResTxStatus()
{
    A_BOOL ret = TRUE;
    A_UINT8 *data;
    A_UINT32 pdadc, paCfg, len;
    A_INT32  gainIdx, dacGain;
    A_UINT32 thermCal;
//    A_UINT8  buf[512];
//    A_UINT32 i;
    ret = getParams((A_UINT8*)"thermCal", &data, &len);
    if ( ret == TRUE )
    {
        memcpy(&thermCal,data,len);
        printf("Response thermCal0 %d, lthermCal1 %d, len %d\n", thermCal&0xff, (thermCal)>>8, len);
    }
    else
        printf("In parseResTxStatus thermal not found\n");

    ret = getParams((A_UINT8*)"pdadc", &data, &len);
    if ( ret == TRUE )
    {
        memcpy(&pdadc,data,len);
        printf("Response pdadc0 %d, pdadc1 %d len %d\n", pdadc&0xff, (pdadc)>>8 , len);
    }
    else
        printf("In parseResTxStatus pdadc not found\n");

    ret = getParams((A_UINT8*)"paCfg", &data, &len);
    if ( ret == TRUE )
    {
        memcpy(&paCfg,data,len);
        printf("Response paCfg %d, len %d\n", paCfg, len);
    }
    else
        printf("In parseResTxStatus paCfg not found\n");

    ret = getParams((A_UINT8*)"gainIdx", &data, &len);
    if ( ret == TRUE )
    {
        memcpy(&gainIdx,data,len);
        printf("Response gainIdx %d, len %d\n", gainIdx, len);
    }
    else
        printf("In parseResTxStatus gainIdx not found\n");

    ret = getParams((A_UINT8*)"dacGain", &data, &len);
    if ( ret == TRUE )
    {
        memcpy(&dacGain,data,len);
        printf("Response dacGain %d, len %d\n", dacGain, len);
    }
    else
        printf("In parseResTxStatus dacGain not found\n");

}

void parseResNart()
{
    A_BOOL ret = TRUE;
    A_UINT8 *data;
    A_UINT32 status, len, value;
    A_UINT32 commandId = 0;
    A_UINT8  buf[2048];
    A_UINT32 i;

    ret = getParams((A_UINT8*)"commandId", &data, &len);

    if ( ret == TRUE )
    {
        memcpy(&commandId,data,len);
        printf("Response commandId %d, len %d\n",commandId, len);
    }
    else
        printf("In parseResNart commandId not found\n");

    ret = getParams((A_UINT8*)"status", &data, &len);

    if ( ret == TRUE )
    {
        memcpy(&status,data,len);
        printf("Response status %d\n",status);
    }
    else
        printf("In parseResNart status not found\n");

    ret = getParams((A_UINT8*)"data", &data, &len);

    if ( ret == TRUE )
    {
        memcpy(buf,data,len);
        printf("Response buf len %d\n",len);
        if (commandId == REG_READ_CMD_ID)
        {
        	//value = (A_UINT32)buf[0] | ((A_UINT32)buf[1] << 8) | ((A_UINT32)buf[2] << 16) | ((A_UINT32)buf[3] << 24);
        	value = (A_UINT32)(buf[0] | (buf[1] << 8) | (buf[2] << 16) | (buf[3] << 24));
        	printf("0x%08x\n", value);
        	return;
        }
        for (i = 0; i <len; i++) {
            printf("0x%02x ",buf[i]);
            if (((i+1)%16) == 0) printf("\n");
        }
        printf("\n");
    }
    else
        printf("In parseResNart buf not found\n");

}

void cmdReplyFunc_v2(void *buf)
{
    A_UINT8 *reply = (A_UINT8*)buf;
    A_UINT32 length =0;
    A_UINT8 *pPayload = NULL;
    A_UINT16 payloadLen=0;

    length = *(A_UINT32 *)&(reply[0]);

    //printf("TLV length got %d\n",length);

    cmdStreamParsingAndProcessing((A_UINT8*)&reply[4], length, &pPayload, &payloadLen);

    replyReceived = TRUE;

    return;
}

void cmdReplyFunc(void *buf)
{
    A_UINT8 *reply = (A_UINT8*)buf;
    A_UINT32 length =0;
    A_UINT8 responseOpCode = _OP_GENERIC_RSP;
    A_BOOL ret = FALSE;

    length = *(A_UINT32 *)&(reply[0]);

    //printf("TLV length got %d\n",length);

    ret = initResponse((A_UINT8*)&reply[4], length,&responseOpCode);

    if ( ret == FALSE )
    {
        printf("Error in init Response\n");
        replyReceived = TRUE;
        return;
    }

    printf("Response code got %d\n",responseOpCode);

    if ( responseOpCode == _OP_SUBMIT_REPORT_RSP )
    {
        parseTLVSubmitReport();
    }
    else if ( responseOpCode == _OP_GENERIC_RSP )
    {
        parseResponse();
    }
    else if ( responseOpCode == _OP_GENERIC_NART_RSP)
    {
        //printf("TLV got nart cmd rsp\n");
        parseResNart();
    }
    else if ( responseOpCode == _OP_TX_STATUS)
    {
        //printf("TLV got Tx status cmd rsp\n");
        parseResTxStatus();
    }

    replyReceived = TRUE;
    return;
}

void handleTPCCALRsp(void *pParms)
{
    int i;
    CMD_TPCCALRSP_PARMS *lpParms = (CMD_TPCCALRSP_PARMS *)pParms;
    printf("radioID %d, numFreq2G %d, numFreq5G %d, numChain %d, numCalPt %d\n", lpParms->radioId,
        lpParms->numFreq2G, lpParms->numFreq5G, lpParms->numChain, lpParms->numCALPt2G);
    printf("freq2G: ");
    for (i=0;i<lpParms->numFreq2G;i++) {
        printf("%d ", lpParms->freq2G[i]);
    }
    printf("\n");
    printf("freq5G: ");
    for (i=0;i<lpParms->numFreq5G;i++) {
        printf("%d ", lpParms->freq5G[i]);
    }
    printf("\n");
}

void handleLMHWCALRsp(void *pParms)
{
    CMD_LMHWCALRSP_PARMS *lpParms = (CMD_LMHWCALRSP_PARMS *)pParms;
    printf("radioID %d status %d\n", lpParms->phyId,lpParms->status);
    printf("\n");
}

void handleLMGoRsp(void *pParms)
{
    CMD_LMGORSP_PARMS *pLMGORSPParms = (CMD_LMGORSP_PARMS *)pParms;
    printf("LMGORSPOp: lm_cmdId %u\n", pLMGORSPParms->lm_cmdId);
    printf("LMGORSPOp: status %u\n", pLMGORSPParms->status);
    printf("LMGORSPOp: timeOn %u\n", pLMGORSPParms->timeOn);
    printf("LMGORSPOp: timeOff %u\n", pLMGORSPParms->timeOff);
    printf("\n");
}
void handleLMTxInitRsp(void *pParms)
{
    CMD_LMTXINITRSP_PARMS *pLMTXINITRSPParms = (CMD_LMTXINITRSP_PARMS *)pParms;
    printf("LMTXINITRSPOp: cmdId %u\n", pLMTXINITRSPParms->cmdId);
    printf("LMTXINITRSPOp: status %u\n", pLMTXINITRSPParms->status);
    printf("\n");
}

void handleLMRxInitRsp(void *pParms)
{
    CMD_LMRXINITRSP_PARMS *pLMRXINITRSPParms = (CMD_LMRXINITRSP_PARMS *)pParms;
    printf("LMRXINITRSPOp: cmdId %u\n", pLMRXINITRSPParms->cmdId);
    printf("LMRXINITRSPOp: status %u\n", pLMRXINITRSPParms->status);
    printf("\n");
}

 void handleLMChannelListRsp (void *pParms)
{
    CMD_LMCHANNELLISTRSP_PARMS *pLMCHANNELLISTRSPParms = (CMD_LMCHANNELLISTRSP_PARMS *)pParms;
    printf("LMCHANNELLISTRSPOp: status %u\n", pLMCHANNELLISTRSPParms->status);
    printf("LMCHANNELLISTRSPOp: totalHWCalNum %u\n", pLMCHANNELLISTRSPParms->totalHWCalNum);
    printf("LMCHANNELLISTRSPOp: totalItemNum %u\n", pLMCHANNELLISTRSPParms->totalItemNum);
    printf("LMCHANNELLISTRSPOp: hwCalTime %u\n", pLMCHANNELLISTRSPParms->hwCalTime);
    printf("\n");
}
 void handleLMQueryRsp (void *pParms)
{
    CMD_LMQUERYRSP_PARMS *pLMQUERYRSPParms = (CMD_LMQUERYRSP_PARMS *)pParms;
    printf("LMQUERYRSPOp: status %u\n", pLMQUERYRSPParms->status);
    printf("LMQUERYRSPOp: lm_cmdId %u\n", pLMQUERYRSPParms->lm_cmdId);
    printf("\n");
}

void handleTPCCALDATA(void *lpParms)
{
CMD_TPCCALDATA_PARMS *pParms = (CMD_TPCCALDATA_PARMS *)lpParms;
#ifdef EEPROM_HEADER
    FILE *fp;
    size_t numBytes;
    AR6000_EEPROM eepromData, *pEepStruct=&eepromData;
    char fileName[]="fakeBoardData_AR6004.bin";
    char fileName_out[]="fakeBoardData_AR6004_out.bin";
    A_UINT16 sum, *pHalf;
    int i,length;

    printf("radioID %d, calData2G %d, calData2GOffset %d, calData2GLen %d, calData5G %d, calData5GOffset %d, calData5GLen %d\n", pParms->radioId,
        pParms->calData2G[0], pParms->calData2GOffset, pParms->calData2GLength, pParms->calData5G[0],
        pParms->calData5GOffset, pParms->calData5GLength);
    printf("calData2G_clpc %d, calData2GOffset_clpc %d, calData2GLen_clpc %d, calData5G_clpc %d, calData5GOffset_clpc %d, calData5GLen_clpc %d\n",
        pParms->calData2G_clpc[0], pParms->calData2GOffset_clpc, pParms->calData2GLength_clpc, pParms->calData5G_clpc[0],
        pParms->calData5GOffset_clpc, pParms->calData5GLength_clpc);

    // generate the board data file based on the current one
    if( (fp = fopen(fileName, "rb")) == NULL) {
        printf("Could not open %s to read\n", fileName);
        return;
    }

    if (numBytes = (fread((A_UCHAR *)&eepromData, 1, sizeof(eepromData), fp))) {
        printf("Read %d from %s\n", numBytes, fileName);
    }
    if (fp) fclose(fp);

    if (pParms->calData2GLength) {
        memcpy((void*) (((A_UCHAR *)&eepromData) + pParms->calData2GOffset), (void*)&(pParms->calData2G[0]), (size_t)(pParms->calData2GLength));
    }
    if (pParms->calData5GLength) {
        memcpy((void*) (((A_UCHAR *)&eepromData) + pParms->calData5GOffset), (void*)&(pParms->calData5G[0]), (size_t)(pParms->calData5GLength));
    }
    if (pParms->calData2GLength_clpc) {
        memcpy((void*) (((A_UCHAR *)&eepromData) + pParms->calData2GOffset_clpc), (void*)&(pParms->calData2G_clpc[0]), (size_t)(pParms->calData2GLength_clpc));
    }
    if (pParms->calData5GLength_clpc) {
        memcpy((void*) (((A_UCHAR *)&eepromData) + pParms->calData5GOffset_clpc), (void*)&(pParms->calData5G_clpc[0]), (size_t)(pParms->calData5GLength_clpc));
    }

    // re-computing checksum
    pEepStruct->baseEepHeader.checksum = 0x0000;
    pHalf = (A_UINT16 *)pEepStruct;
    sum = 0;
    length=sizeof(eepromData) ;
    for (i = 0; i < (length/2); i++) { sum ^= *pHalf++; }
    pEepStruct->baseEepHeader.checksum = 0xFFFF ^ sum;

    if ( (fp = fopen(fileName_out, "wb")) == NULL) {
        printf("Error: open to write eeprom bin %s \n", fileName);
    }
    if (length != fwrite((A_UCHAR *)pEepStruct, 1, length, fp)) {
        printf("Error: writing to %s\n", fileName);
    }
    if (fp) fclose(fp);
#endif

    return;
}

void handleMEMREADRSP(void *parms)
{
    CMD_MEMREADRSP_PARMS *pParms = (CMD_MEMREADRSP_PARMS *)parms;

    if (pParms->status == 0)
    {
        A_INT16 i, t;
        for (i = 0; i < pParms->numbytes; i++)
        {
            if (i % pParms->valuetype == 0)
                printf("mem[%x]=0x %02x", pParms->memaddress + i, pParms->memvalue[i]);
            else
                printf("%02x", pParms->memvalue[i]);
            if (i % pParms->valuetype == pParms->valuetype - 1) printf("\n");
        }

    }
    else
    {
        printf("Error in memory Read\n");
    }
}

void handleMEMWRITERSP(void *parms)
{
    CMD_MEMWRITERSP_PARMS *pParms = (CMD_MEMWRITERSP_PARMS *)parms;

    if (pParms->status == 0)
    {
        printf("memory write done\n");
    }
    else
    {
        printf("Error in memory Write\n");
    }
}


void handleREGREADRSP(void *parms)
{
    CMD_REGREADRSP_PARMS *pParms = (CMD_REGREADRSP_PARMS *)parms;

    if (pParms->status == 0)
    {
        printf("reg = 0x%x\n", pParms->regvalue);
    }
    else
    {
        printf("Error in register read\n");
    }
}




void handleREGWRITERSP(void *parms)
{
	CMD_REGWRITERSP_PARMS *pParms = (CMD_REGWRITERSP_PARMS *)parms;
	if (pParms->status != 0)
	{
		printf("Error in register write\n");
	}
}

void handleBASICRSP (void *parms)
{
	CMD_BASICRSP_PARMS *pParms = (CMD_BASICRSP_PARMS *)parms;

	//printf("cmdId %d; status %d", pParms->cmdId, pParms->status);
	if (pParms->status != 0)
	{
		printf(" Error");
	}
	printf("\n");
}

void handleTXSTATUSRSP (void *parms)
{
	CMD_TXSTATUSRSP_PARMS *pParms = (CMD_TXSTATUSRSP_PARMS *)parms;

	if (pParms->status != 0)
	{
		printf("TXSTATUS returns error %d\n", pParms->status);
		return;
	}
	printf("numOfReports = %u\n", pParms->numOfReports);
	printf("totalPackets = %u\n", pParms->totalPackets);
	printf("goodPackets = %u\n", pParms->goodPackets);
	printf("underruns = %u\n", pParms->underruns);
	printf("otherError = %u\n", pParms->otherError);
	printf("rateBit = %u\n", pParms->rateBit);
	printf("startTime = %u\n", pParms->startTime);
	printf("endTime = %u\n", pParms->endTime);
	printf("byteCount = %u\n", pParms->byteCount);
	printf("dontCount = %u\n", pParms->dontCount);
	printf("rssi = %d\n", pParms->rssi);
	printf("rssic = %d, %d, %d, %d\n", pParms->rssic[0], pParms->rssic[1], pParms->rssic[2], pParms->rssic[3] );
	printf("rssie = %d, %d, %d, %d\n", pParms->rssie[0], pParms->rssie[1], pParms->rssie[2], pParms->rssie[3]);
}

void handleRXSTATUSRSP (void *parms)
{
	CMD_RXSTATUSRSP_PARMS *pParms = (CMD_RXSTATUSRSP_PARMS *)parms;

	if (pParms->numOfReports == 0)
	{
		printf("RXSTATUS returns no report\n");
		return;
	}
	printf("numOfReports = %u\n", pParms->numOfReports);
	printf("totalPackets = %u\n", pParms->totalPackets);
	printf("goodPackets = %u\n", pParms->goodPackets);
	printf("crcPackets = %u\n", pParms->crcPackets);
	printf("decrypErrors = %u\n", pParms->decrypErrors);
	printf("otherError = %u\n", pParms->otherError);
	printf("rateBit = %u\n", pParms->rateBit);
	printf("startTime = %u\n", pParms->startTime);
	printf("endTime = %u\n", pParms->endTime);
	printf("byteCount = %u\n", pParms->byteCount);
	printf("dontCount = %u\n", pParms->dontCount);
	printf("rssi = %d\n", pParms->rssi);
	printf("rssic = %d, %d, %d, %d\n", pParms->rssic[0], pParms->rssic[1], pParms->rssic[2], pParms->rssic[3] );
	printf("rssie = %d, %d, %d, %d\n", pParms->rssie[0], pParms->rssie[1], pParms->rssie[2], pParms->rssie[3]);
	printf("badrssi = %d\n", pParms->badrssi);
	printf("badrssic = %d, %d, %d, %d\n", pParms->badrssic[0], pParms->badrssic[1], pParms->badrssic[2], pParms->badrssic[3] );
	printf("badrssie = %d, %d, %d, %d\n", pParms->badrssie[0], pParms->badrssie[1], pParms->badrssie[2], pParms->badrssie[3]);
	printf("evm = %d\n", pParms->evm);
	printf("badevm = %d, %d, %d, %d\n", pParms->badevm[0], pParms->badevm[1], pParms->badevm[2], pParms->badevm[3] );
}

void handleRXRSP (void *parms)
{
	CMD_RXRSP_PARMS *pParms = (CMD_RXRSP_PARMS *)parms;
    A_UINT32 i, k;
    A_UINT32 rateMask, dataRate, index;
    A_UINT32 bit0;

    printf("status %d\n", pParms->status);

    if (pParms->rxMode != TCMD_CONT_RX_REPORT)
    {
    	return;
    }

    printf("totalpkt %d\n", pParms->totalPackets);
    printf("rssiInDBm %d\n", (pParms->totalPackets ? (pParms->rssiInDBm/(A_INT32)pParms->totalPackets) : pParms->rssiInDBm));
    printf("crcErrPkt %d\n", pParms->crcPackets);
    printf("secErrPkt %d\n", pParms->secErrPkt);
    printf("rcMask 4x4 %d\n", pParms->rateMask11AC[4]);

    //11n and below rates..
    for (k=0;k<2;k++)
    {
        rateMask = pParms->rateMask[k];
        i=0; bit0=0x00000001;
        while (rateMask)
        {
            if (bit0 & rateMask)
            {
                rateMask &= ~bit0;
                dataRate = Mask2Rate[k][i];

                if (dataRate == ATH_RATE_2M || dataRate == ATH_RATE_5_5M || dataRate == ATH_RATE_11M){ /* CCK rates */
                    if (!(i&1)) /* even number indicates short preamble, see Mask2Rate array for details */
                        dataRate += (TCMD_MAX_RATES_11AC_3x3 - 4);/* use last three rates in the rate table for shortPreamble */
                }

                //printf("RateCnt bit set %d dataRate %d %s\n",(k*32+i),dataRate,bgRateStrTbl[dataRate]);
                printf("%s .. ",bgRateStrTbl[dataRate]);

                index = (k*32+i)/2;
				if ((i & 1) == 0 )
				{
					printf("rateCnt %d\n", (pParms->rateCnt[index] & 0xFFFF));
				}
				else
				{
					printf("rateCnt %d\n", (pParms->rateCnt[index] >>16) & 0xFFFF);
				}
                //if (pParms->rateShortG[k] & bit0) printf("<<<<SGI set >>>>\n");
            }
            bit0 = bit0 << 1;i++;
        }
    }

    //11ac rates..
    for (k=0;k<4;k++)
    {
        rateMask = pParms->rateMask11AC[k];
        i=0; bit0=0x00000001;
        while (rateMask)
        {
            if (bit0 & rateMask)
            {
                rateMask &= ~bit0;
                index = k + 2;
                dataRate = Mask2Rate[index][i];
                //printf("11ac RateCnt bit set %d dataRate %d %s\n",(k*32+i),dataRate,bgRateStrTbl[dataRate]);
                printf("%s .. ",bgRateStrTbl[dataRate]);

                index = (k*32+i)/2;
				if (i && !(i&1))
				{
					printf("rateCnt %d\n",(pParms->rateCnt11ac[index] & 0xFFFF));
				}
				else
				{
					printf("rateCnt %d\n",(pParms->rateCnt11ac[index] >>16) & 0xFFFF);
				}
                //if (pParms->rateShortG11ac[k] & bit0) printf("<<<<SGI set >>>>\n");
            }
            bit0 = bit0 << 1;i++;
        }
    }

    //4x4 11ac rates..
	rateMask = pParms->rateMask11AC[4];
	i=0; bit0=0x00000001;
	while (rateMask)
	{
		if (bit0 & rateMask)
		{
			rateMask &= ~bit0;
			index = 6; //4x4 11ac
			dataRate = Mask2Rate[index][i];
			printf("%s .. ",bgRateStrTbl[dataRate]);

			index = i >> 1;
			if ((i&1) == 0)
			{
				printf("rateCnt %d\n",(pParms->rateCnt11ac[54+index] & 0xFFFF));
			}
			else
			{
				printf("rateCnt %d\n",(pParms->rateCnt11ac[54+index] >>16) & 0xFFFF);
			}
            //if (pParms->rateShortG11ac[4] & bit0) printf("<<<<SGI set >>>>\n");
		}
		bit0 = bit0 << 1;i++;
	}

        /* needed late
        //Cascade BW 160 rates.
	rateMask = pParms->rateMask11AC[5];
	i=0; bit0=0x00000001;
	while (rateMask)
	{
		if (bit0 & rateMask)
		{
			rateMask &= ~bit0;
			index = 7; //Cascade
			dataRate = Mask2Rate[index][i];
			printf("%s .. ",bgRateStrTbl[dataRate]);

			index = i >> 1;
			if ((i&1) == 0)
			{
				printf("rateCnt %d\n",(pParms->rateCnt11ac[54+index] & 0xFFFF));                // TBD: need to increase the buffer to support Cascade
			}
			else
			{
				printf("rateCnt %d\n",(pParms->rateCnt11ac[54+index] >>16) & 0xFFFF);           // TBD: need to increase the buffer to support Cascade
			}
		}
		bit0 = bit0 << 1;i++;
	}
	*/
}
