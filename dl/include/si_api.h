/*
 * Copyright (c) 2012 Qualcomm Atheros, Inc.
 * All Rights Reserved.
 * Qualcomm Atheros Confidential and Proprietary.
 */
//
// Copyright (c) 2010 Atheros Communications Inc.
// All rights reserved.
// $ATH_LICENSE_TARGET_C$
//

#ifndef __SI_API_H__
#define __SI_API_H__

#include <nvram_api.h>

/* Serial Interface API */

struct si_api_s {
    void (* _si_init)(void);
    void (* _si_fini)(void);
    A_UINT32 (* _si_wait_done)(void);
    void (* _si_request)(A_UINT32 *req, unsigned int rxcnt, unsigned int txcnt);
    void (* _si_response)(A_UINT8 *buf, unsigned int nbytes);
};

extern struct si_api_s *si_api;

#define si_init()                       si_api->_si_init()
#define si_fini()                       si_api->_si_fini()
#define si_wait_done()                  si_api->_si_wait_done()
#define si_request(req, rxcnt, txcnt)   si_api->_si_request((req), (rxcnt), (txcnt))
#define si_response(buf, nbytes)        si_api->_si_response((buf), (nbytes))

struct si_default_s {
    A_UINT32 sdio_value;
    struct {
        A_UINT8 num;
        A_UINT8 cfg;
    } pin[NVRAM_PINCOUNT_MAX];
};

#endif /* __SI_API_H__ */
