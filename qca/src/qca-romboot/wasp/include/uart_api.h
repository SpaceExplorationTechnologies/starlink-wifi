/*
 * Copyright (c) 2013, The Linux Foundation. All rights reserved.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 and
 * only version 2 as published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 */

#ifndef _UART_API_H
#define _UART_API_H

#include <asm/types.h>

struct uart_api {
    void (*_uart_init)(void);
    u8 (*_uart_getc)(void);
    void (*_uart_putc)(u8 byte);
    void (*_uart_puts)(const char *s);
};

#endif

