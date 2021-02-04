/*
 * Copyright (c) 2012 Qualcomm Atheros, Inc.
 * All Rights Reserved.
 * Qualcomm Atheros Confidential and Proprietary.
 */
//------------------------------------------------------------------------------
// Copyright (c) 2004-2010 Atheros Corporation.  All rights reserved.
// $ATH_LICENSE_HOSTSDK0_C$
//------------------------------------------------------------------------------
//==============================================================================
// Author(s): ="Atheros"
//==============================================================================

#define __VER_MAJOR_ 1
#define __VER_MINOR_ 0 
#define __VER_RELEASE_ 0

/* The makear6ksdk script (used for release builds) modifies the following line. */
#define __BUILD_NUMBER_ 83


/* Format of the version number. */
/* 2 dwords:
 * 1st dword: Major/Minor
 * 2nd dword: Release/build
 */
#define VER_MAJOR_BIT_OFFSET        24
#define VER_MINOR_BIT_OFFSET        0
#define VER_RELEASE_BIT_OFFSET        16
#define VER_BUILD_NUM_BIT_OFFSET    0

#define VER_MAJOR_BIT_MASK          0xFF000000
#define VER_MINOR_BIT_MASK          0x00FFFFFF
#define VER_RELEASE_BIT_MASK          0xFFFF0000
#define VER_BUILD_NUM_BIT_MASK      0x0000FFFF

/* Macros to extract the sw_version components.
 */
#define VER_GET_MAJOR(x) (((x) & VER_MAJOR_BIT_MASK)>>VER_MAJOR_BIT_OFFSET)
#define VER_GET_MINOR(x) (((x) & VER_MINOR_BIT_MASK)>>VER_MINOR_BIT_OFFSET)
#define VER_GET_RELEASE(x) (((x) & VER_RELEASE_BIT_MASK)>>VER_RELEASE_BIT_OFFSET)
#define VER_GET_BUILD_NUM(x) (((x) & VER_BUILD_NUM_BIT_MASK)>>VER_BUILD_NUM_BIT_OFFSET)

/*
 * The version has the following format:
 * Bits 24-31: Major version
 * Bits 0-23: Minor version
 * Bits 16-23: Release version
 * Bits 0-15:  Build number (automatically generated during build process )
 * E.g. Build 1.1.3.7 would be represented as 0x01000001 for Major/Minor & 0x00030007 for Release/buildnum.
 *
 * DO NOT split the following macro into multiple lines as this may confuse the build scripts.
 */
#define SOC_SW_VERSION     ( ( __VER_MAJOR_ << VER_MAJOR_BIT_OFFSET ) + ( __VER_MINOR_ << VER_MINOR_BIT_OFFSET ) )

#define SOC_SW_VERSION_1     ( ( __VER_RELEASE_ << VER_RELEASE_BIT_OFFSET ) + ( __BUILD_NUMBER_ << VER_BUILD_NUM_BIT_OFFSET ) )

/* ABI Version. Reflects the version of binary interface exposed by Target firmware. Needs to be incremented by 1 for any change in the firmware that requires upgrade of the driver on the host side for the change to work correctly */
#define SOC_ABI_VERSION        3
