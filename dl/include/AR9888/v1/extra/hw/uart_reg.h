/*
 * Copyright (c) 2012 Qualcomm Atheros, Inc.
 * All Rights Reserved.
 * Qualcomm Atheros Confidential and Proprietary.
 */
// ------------------------------------------------------------------
// Copyright (c) 2011 Atheros Corporation.  All rights reserved.
// $ATH_LICENSE_HOSTSDK0_C$
// ------------------------------------------------------------------
//===================================================================
// Author(s): ="Atheros"
//===================================================================


#ifndef _UART_REG_REG_H_
#define _UART_REG_REG_H_

#include  "hw/athrUartCsr.h"


#define UART_DATA_ADDRESS                       UARTDATA_ADDRESS
#define UART_CONTROL_ADDRESS                    UARTCS_ADDRESS
#define UART_CLKDIV_ADDRESS                     UARTCLOCK_ADDRESS
#define UART_INT_ADDRESS                        UARTINT_ADDRESS
#define UART_INT_EN_ADDRESS                     UARTINTEN_ADDRESS

#define UART_CLKDIV_CLK_SCALE_SET(x)            UARTCLOCK_UARTCLOCKSCALE_SET(x)
#define UART_CLKDIV_CLK_STEP_SET(x)             UARTCLOCK_UARTCLOCKSTEP_SET(x)

#define SOC_RESET_CONTROL_DEBUG_UART_RST_SET(x) SOC_RESET_CONTROL_UART2_RST_SET(x)
#define UART_CONTROL_HOST_INT_ENABLE_SET(x)     UARTCS_UARTHOSTINTEN_SET(x)
#define UART_CONTROL_TX_BREAK_SET(x)            UARTCS_UARTTXBREAK_SET(x)
#define UART_CONTROL_DMA_ENABLE_SET(x)          UARTCS_UARTDMAEN_SET(x)
#define UART_CONTROL_FLOW_ENABLE_SET(x)         UARTCS_UARTFLOWCONTROLMODE_SET(x)
#define UART_CONTROL_PARITY_ENABLE_SET(x)       UARTCS_UARTPARITYMODE_SET(x)
#define UART_CONTROL_TX_READY_ORIDE_SET(x)      UARTCS_UARTTXREADYORIDE_SET(x)
#define UART_CONTROL_RX_READY_ORIDE_SET(x)      UARTCS_UARTRXREADYORIDE_SET(x)

/* UARTCS_UARTINTERFACEMODE_SET */
#define UART_CONTROL_IFC_ENABLE_SET(x)          (((x) << 3) & 8)
#define UART_CONTROL_IFC_DCE_SET(x)             (((x) << 2) & 4)

#define UART_DATA_TX_CSR_MASK                   UARTDATA_UARTTXCSR_MASK
#define UART_CONTROL_TX_BUSY_MASK               UARTCS_UARTTXBUSY_MASK
#define UART_DATA_RX_CSR_MASK                   UARTDATA_UARTRXCSR_MASK
#define UART_DATA_TX_CSR_SET(x)                 UARTDATA_UARTTXCSR_SET(x)
#define UART_DATA_RX_CSR_SET(x)                 UARTDATA_UARTRXCSR_SET(x)
#define UART_INT_EN_TX_EMPTY_INT_EN_MASK        UARTINT_UARTTXEMPTYINT_MASK
#define UART_INT_EN_RX_VALID_INT_EN_MASK        UARTINTEN_UARTRXVALIDINTEN_MASK
#define UART_INT_RX_VALID_INT_MASK              UARTINT_UARTRXVALIDINT_MASK
#define UART_INT_TX_EMPTY_INT_MASK              UARTINT_UARTTXEMPTYINT_MASK
#define UART_INT_RX_OFLOW_ERR_INT_MASK          UARTINT_UARTRXOFLOWERRINT_MASK
#define UART_INT_RX_FRAMING_ERR_INT_MASK        UARTINT_UARTRXFRAMINGERRINT_MASK
#define UART_INT_RX_PARITY_ERR_INT_MASK         UARTINT_UARTRXPARITYERRINT_MASK
#define UART_INT_TX_OFLOW_ERR_INT_MASK          UARTINT_UARTTXOFLOWERRINT_MASK
#define UART_CONTROL_PARITY_EVEN_SET(x)         ((x) & 1)
#define UART_INT_EN_TX_OFLOW_ERR_INT_EN_MASK    UARTINTEN_UARTTXOFLOWERRINTEN_MASK
#define UART_INT_EN_RX_OFLOW_ERR_INT_EN_MASK    UARTINTEN_UARTRXOFLOWERRINTEN_MASK
#define UART_INT_EN_RX_FRAMING_ERR_INT_EN_MASK  UARTINTEN_UARTRXFRAMINGERRINTEN_MASK

#endif /* _UART_REG_H_ */
