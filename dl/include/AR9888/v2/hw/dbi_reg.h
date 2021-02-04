// ------------------------------------------------------------------
// Copyright (c) 2004-2012 Qualcomm Atheros.  All rights reserved.
// $ATH_LICENSE_TARGET_C$
// ------------------------------------------------------------------
//===================================================================
// Author(s): ="Qualcomm Atheros"
//===================================================================



#ifndef _DBI_REG_H_
#define _DBI_REG_H_


/* macros for DBI_WINDOW_reg */
#define DBI_WINDOW_REG_ADDRESS                                                            0x00000000
#define DBI_WINDOW_REG_OFFSET                                                             0x00000000
#define DBI_WINDOW_REG_DATA_MSB                                                                   31
#define DBI_WINDOW_REG_DATA_LSB                                                                    0
#define DBI_WINDOW_REG_DATA_MASK                                                          0xffffffff
#define DBI_WINDOW_REG_DATA_GET(x)                                         (((x) & 0xffffffff) >> 0)
#define DBI_WINDOW_REG_DATA_SET(x)                                         (((x) << 0) & 0xffffffff)


#ifndef __ASSEMBLER__

typedef struct dbi_reg_reg_s {
  volatile unsigned int DBI_WINDOW_reg;                                /*        0x0 - 0x4        */
} dbi_reg_reg_t;

#endif /* __ASSEMBLER__ */

#endif /* _DBI_REG_H_ */
