/*
 * Copyright (c) 2012 Qualcomm Atheros, Inc.
 * All Rights Reserved.
 * Qualcomm Atheros Confidential and Proprietary.
 */
//------------------------------------------------------------------------------
// Copyright (c) 2011 Atheros Corporation.  All rights reserved.
// $ATH_LICENSE_HOSTSDK0_C$
//------------------------------------------------------------------------------
//==============================================================================
// Author(s): ="Atheros"
//==============================================================================


#ifndef _FRAG_DESC_H_
#define _FRAG_DESC_H_

#define FRAG_LEN_MASK 0xffff
#define FRAG_LEN_S    0

/**
 * @brief MSDU fragmentation descriptor
 *
 * @description MSDU fragmentation descriptor describes each fragmentation 
 *              buffer of a MSDU. This matches the HW definition of frags
 *              descriptor.
 *
 * @note this header file is for SW only. The reason to have this header file
 *      is because we would like to strictly know the position of subfields
 *      written in the 32 bit field; it would be difficult to handle the
 *      endianness issue if we write value to bit fields not 32 bits wide.
 */
struct MSDU_FRAG_DESC {
    A_UINT32 buf_ptr;
    A_UINT32 len_and_meta;
};

#endif
