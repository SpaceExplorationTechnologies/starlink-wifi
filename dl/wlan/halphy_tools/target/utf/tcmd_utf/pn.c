/*
 * Copyright (c) 2012 Qualcomm Atheros, Inc.
 * All Rights Reserved.
 * Qualcomm Atheros Confidential and Proprietary.
 */
// Copyright (c) 2010 Atheros Communications Inc.
// All rights reserved.
// $ATH_LICENSE_TARGET_C$

#include <osapi.h>
typedef struct _bit_byte{
    A_UINT8 b0:1;
    A_UINT8 b1:1;
    A_UINT8 b2:1;
    A_UINT8 b3:1;
    A_UINT8 b4:1;
    A_UINT8 b5:1;
    A_UINT8 b6:1;
    A_UINT8 b7:1;
}bit_byte;
typedef union{
    bit_byte b;
    A_UINT8 c;
}u;
A_UINT32 get_char_index(A_UINT32 bitIndex) 
{
   return (A_UINT32)(bitIndex/8);
}

A_UINT32 get_char_bit_index(A_UINT32 bitIndex) 
{
   return (A_UINT32)(bitIndex%8);
}
A_UINT32 get_bit(u *bb, A_UINT32 bitIndex) 
{
   A_UINT32 cIndex, bIndex, b;

   cIndex = get_char_index(bitIndex);
   bIndex = get_char_bit_index(bitIndex);
   switch(bIndex) {
      case 0: b = bb[cIndex].b.b0; break;
      case 1: b = bb[cIndex].b.b1; break;
      case 2: b = bb[cIndex].b.b2; break;
      case 3: b = bb[cIndex].b.b3; break;
      case 4: b = bb[cIndex].b.b4; break;
      case 5: b = bb[cIndex].b.b5; break;
      case 6: b = bb[cIndex].b.b6; break;
      case 7: 
      default:b = bb[cIndex].b.b7; break; }
   return (b&0x1);
}

void set_bit(u *bb, A_UINT32 bitIndex, A_UINT32 b) 
{
   A_UINT32 cIndex, bIndex;
   b = b & 0x1;
   cIndex = get_char_index(bitIndex);
   bIndex = get_char_bit_index(bitIndex);
   switch(bIndex) {
      case 0: bb[cIndex].b.b0 = b; break;
      case 1: bb[cIndex].b.b1 = b; break;
      case 2: bb[cIndex].b.b2 = b; break;
      case 3: bb[cIndex].b.b3 = b; break;
      case 4: bb[cIndex].b.b4 = b; break;
      case 5: bb[cIndex].b.b5 = b; break;
      case 6: bb[cIndex].b.b6 = b; break;
      case 7:
      default:bb[cIndex].b.b7 = b; break;
   }
}
void init_pn(A_UINT32 seed, A_UINT32 seed_len, A_UINT8 * buf, A_UINT32 seq_len)
{
    A_UINT32 bitIndex,b;
    A_UINT32 pn_seq_len;
    A_UINT32 len;
    A_UINT32 i=0;

    b = 0x1;
    while(seed){
        ((u*)buf)[i].c = (A_UINT8)(0xff & seed);
        seed >>=8;
        i ++;
    }
    pn_seq_len = 1<< seed_len;
    len = (pn_seq_len < seq_len)?pn_seq_len:seq_len;
    for( bitIndex = seed_len; bitIndex < len; bitIndex++)  {
        switch (seed_len){
            case 7:
                b = (get_bit((u *)buf, bitIndex -7) ^ get_bit((u* )buf, bitIndex-5)) & 0x1;
                break;
            case 9:
                b = (get_bit((u *)buf, bitIndex -5) ^ get_bit((u *)buf, bitIndex-9)) & 0x1;
                break;
            case 15:
                b = (get_bit((u *)buf, bitIndex-15) ^ get_bit((u *)buf, bitIndex-1)) & 0x1;
                break;
            default:
		break;
        }
        set_bit((u *)buf, bitIndex, b);
    }
}

