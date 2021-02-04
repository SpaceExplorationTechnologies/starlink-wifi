//                                                                             
// File:       ./athrUartCsr.vrh                                               
// Creator:    chinghwa                                                        
// Time:       Monday Sep 17, 2012 [2:43:00 pm]                                
//                                                                             
// Path:       /trees/chinghwa/chinghwa_p2p0_1chn/chips/peregrine/2.0/dv/soc/src/ave/regs/blueprint
// Arguments:  /cad/denali/blueprint/3.7.4//Linux-64bit/blueprint -odir .      
//             -codegen ath_vrh.codegen -ath_vrh -Wdesc -I                     
//             /trees/chinghwa/chinghwa_p2p0_1chn/chips/peregrine/2.0/blueprint/sysconfig
//             athrUartCsr.rdl                                                 
//                                                                             
// Sources:    /trees/chinghwa/chinghwa_p2p0_1chn/chips/peregrine/2.0/ip/athr/uart/rtl/athrUartCsr.rdl
//             /trees/chinghwa/chinghwa_p2p0_1chn/chips/peregrine/2.0/env/blueprint/ath_vrh.pm
//                                                                             
// Blueprint:   3.7.4 (Fri Jan 9 05:41:17 PST 2009)                            
// Machine:    sjod-chinghwa                                                   
// OS:         Linux 2.6.18-308.8.2.el5                                        
// Description:                                                                
//                                                                             
// No Description Provided                                                     
/*
 * Copyright (c) 2012-14 Qualcomm Atheros, Inc.
 * All Rights Reserved.
 * Qualcomm Atheros Confidential and Proprietary.
 * $ATH_LICENSE_TARGET_C$
 */


#ifndef _ATHRUARTCSR_H_
#define _ATHRUARTCSR_H_
// 0x0000 (UARTDATA)
#define UARTDATA_UARTTXCSR_MSB                                       9
#define UARTDATA_UARTTXCSR_LSB                                       9
#define UARTDATA_UARTTXCSR_MASK                                      0x00000200
#define UARTDATA_UARTTXCSR_GET(x)                                    (((x) & UARTDATA_UARTTXCSR_MASK) >> UARTDATA_UARTTXCSR_LSB)
#define UARTDATA_UARTTXCSR_SET(x)                                    (((0 | (x)) << UARTDATA_UARTTXCSR_LSB) & UARTDATA_UARTTXCSR_MASK)
#define UARTDATA_UARTTXCSR_RESET                                     0
#define UARTDATA_UARTRXCSR_MSB                                       8
#define UARTDATA_UARTRXCSR_LSB                                       8
#define UARTDATA_UARTRXCSR_MASK                                      0x00000100
#define UARTDATA_UARTRXCSR_GET(x)                                    (((x) & UARTDATA_UARTRXCSR_MASK) >> UARTDATA_UARTRXCSR_LSB)
#define UARTDATA_UARTRXCSR_SET(x)                                    (((0 | (x)) << UARTDATA_UARTRXCSR_LSB) & UARTDATA_UARTRXCSR_MASK)
#define UARTDATA_UARTRXCSR_RESET                                     0
#define UARTDATA_UARTTXRXDATA_MSB                                    7
#define UARTDATA_UARTTXRXDATA_LSB                                    0
#define UARTDATA_UARTTXRXDATA_MASK                                   0x000000ff
#define UARTDATA_UARTTXRXDATA_GET(x)                                 (((x) & UARTDATA_UARTTXRXDATA_MASK) >> UARTDATA_UARTTXRXDATA_LSB)
#define UARTDATA_UARTTXRXDATA_SET(x)                                 (((0 | (x)) << UARTDATA_UARTTXRXDATA_LSB) & UARTDATA_UARTTXRXDATA_MASK)
#define UARTDATA_UARTTXRXDATA_RESET                                  0
#define UARTDATA_ADDRESS                                             0x0000
#define UARTDATA_HW_MASK                                             0x000003ff
#define UARTDATA_SW_MASK                                             0x000003ff
#define UARTDATA_HW_WRITE_MASK                                       0x000003ff
#define UARTDATA_SW_WRITE_MASK                                       0x000003ff
#define UARTDATA_RSTMASK                                             0xffffffff
#define UARTDATA_RESET                                               0x00000000

// 0x0004 (UARTCS)
#define UARTCS_UARTRXBUSY_MSB                                        15
#define UARTCS_UARTRXBUSY_LSB                                        15
#define UARTCS_UARTRXBUSY_MASK                                       0x00008000
#define UARTCS_UARTRXBUSY_GET(x)                                     (((x) & UARTCS_UARTRXBUSY_MASK) >> UARTCS_UARTRXBUSY_LSB)
#define UARTCS_UARTRXBUSY_SET(x)                                     (((0 | (x)) << UARTCS_UARTRXBUSY_LSB) & UARTCS_UARTRXBUSY_MASK)
#define UARTCS_UARTRXBUSY_RESET                                      0
#define UARTCS_UARTTXBUSY_MSB                                        14
#define UARTCS_UARTTXBUSY_LSB                                        14
#define UARTCS_UARTTXBUSY_MASK                                       0x00004000
#define UARTCS_UARTTXBUSY_GET(x)                                     (((x) & UARTCS_UARTTXBUSY_MASK) >> UARTCS_UARTTXBUSY_LSB)
#define UARTCS_UARTTXBUSY_SET(x)                                     (((0 | (x)) << UARTCS_UARTTXBUSY_LSB) & UARTCS_UARTTXBUSY_MASK)
#define UARTCS_UARTTXBUSY_RESET                                      0
#define UARTCS_UARTHOSTINTEN_MSB                                     13
#define UARTCS_UARTHOSTINTEN_LSB                                     13
#define UARTCS_UARTHOSTINTEN_MASK                                    0x00002000
#define UARTCS_UARTHOSTINTEN_GET(x)                                  (((x) & UARTCS_UARTHOSTINTEN_MASK) >> UARTCS_UARTHOSTINTEN_LSB)
#define UARTCS_UARTHOSTINTEN_SET(x)                                  (((0 | (x)) << UARTCS_UARTHOSTINTEN_LSB) & UARTCS_UARTHOSTINTEN_MASK)
#define UARTCS_UARTHOSTINTEN_RESET                                   0
#define UARTCS_UARTHOSTINT_MSB                                       12
#define UARTCS_UARTHOSTINT_LSB                                       12
#define UARTCS_UARTHOSTINT_MASK                                      0x00001000
#define UARTCS_UARTHOSTINT_GET(x)                                    (((x) & UARTCS_UARTHOSTINT_MASK) >> UARTCS_UARTHOSTINT_LSB)
#define UARTCS_UARTHOSTINT_SET(x)                                    (((0 | (x)) << UARTCS_UARTHOSTINT_LSB) & UARTCS_UARTHOSTINT_MASK)
#define UARTCS_UARTHOSTINT_RESET                                     0
#define UARTCS_UARTTXBREAK_MSB                                       11
#define UARTCS_UARTTXBREAK_LSB                                       11
#define UARTCS_UARTTXBREAK_MASK                                      0x00000800
#define UARTCS_UARTTXBREAK_GET(x)                                    (((x) & UARTCS_UARTTXBREAK_MASK) >> UARTCS_UARTTXBREAK_LSB)
#define UARTCS_UARTTXBREAK_SET(x)                                    (((0 | (x)) << UARTCS_UARTTXBREAK_LSB) & UARTCS_UARTTXBREAK_MASK)
#define UARTCS_UARTTXBREAK_RESET                                     0
#define UARTCS_UARTRXBREAK_MSB                                       10
#define UARTCS_UARTRXBREAK_LSB                                       10
#define UARTCS_UARTRXBREAK_MASK                                      0x00000400
#define UARTCS_UARTRXBREAK_GET(x)                                    (((x) & UARTCS_UARTRXBREAK_MASK) >> UARTCS_UARTRXBREAK_LSB)
#define UARTCS_UARTRXBREAK_SET(x)                                    (((0 | (x)) << UARTCS_UARTRXBREAK_LSB) & UARTCS_UARTRXBREAK_MASK)
#define UARTCS_UARTRXBREAK_RESET                                     0
#define UARTCS_UARTSERIATXREADY_MSB                                  9
#define UARTCS_UARTSERIATXREADY_LSB                                  9
#define UARTCS_UARTSERIATXREADY_MASK                                 0x00000200
#define UARTCS_UARTSERIATXREADY_GET(x)                               (((x) & UARTCS_UARTSERIATXREADY_MASK) >> UARTCS_UARTSERIATXREADY_LSB)
#define UARTCS_UARTSERIATXREADY_SET(x)                               (((0 | (x)) << UARTCS_UARTSERIATXREADY_LSB) & UARTCS_UARTSERIATXREADY_MASK)
#define UARTCS_UARTSERIATXREADY_RESET                                0
#define UARTCS_UARTTXREADYORIDE_MSB                                  8
#define UARTCS_UARTTXREADYORIDE_LSB                                  8
#define UARTCS_UARTTXREADYORIDE_MASK                                 0x00000100
#define UARTCS_UARTTXREADYORIDE_GET(x)                               (((x) & UARTCS_UARTTXREADYORIDE_MASK) >> UARTCS_UARTTXREADYORIDE_LSB)
#define UARTCS_UARTTXREADYORIDE_SET(x)                               (((0 | (x)) << UARTCS_UARTTXREADYORIDE_LSB) & UARTCS_UARTTXREADYORIDE_MASK)
#define UARTCS_UARTTXREADYORIDE_RESET                                0
#define UARTCS_UARTRXREADYORIDE_MSB                                  7
#define UARTCS_UARTRXREADYORIDE_LSB                                  7
#define UARTCS_UARTRXREADYORIDE_MASK                                 0x00000080
#define UARTCS_UARTRXREADYORIDE_GET(x)                               (((x) & UARTCS_UARTRXREADYORIDE_MASK) >> UARTCS_UARTRXREADYORIDE_LSB)
#define UARTCS_UARTRXREADYORIDE_SET(x)                               (((0 | (x)) << UARTCS_UARTRXREADYORIDE_LSB) & UARTCS_UARTRXREADYORIDE_MASK)
#define UARTCS_UARTRXREADYORIDE_RESET                                0
#define UARTCS_UARTDMAEN_MSB                                         6
#define UARTCS_UARTDMAEN_LSB                                         6
#define UARTCS_UARTDMAEN_MASK                                        0x00000040
#define UARTCS_UARTDMAEN_GET(x)                                      (((x) & UARTCS_UARTDMAEN_MASK) >> UARTCS_UARTDMAEN_LSB)
#define UARTCS_UARTDMAEN_SET(x)                                      (((0 | (x)) << UARTCS_UARTDMAEN_LSB) & UARTCS_UARTDMAEN_MASK)
#define UARTCS_UARTDMAEN_RESET                                       0
#define UARTCS_UARTFLOWCONTROLMODE_MSB                               5
#define UARTCS_UARTFLOWCONTROLMODE_LSB                               4
#define UARTCS_UARTFLOWCONTROLMODE_MASK                              0x00000030
#define UARTCS_UARTFLOWCONTROLMODE_GET(x)                            (((x) & UARTCS_UARTFLOWCONTROLMODE_MASK) >> UARTCS_UARTFLOWCONTROLMODE_LSB)
#define UARTCS_UARTFLOWCONTROLMODE_SET(x)                            (((0 | (x)) << UARTCS_UARTFLOWCONTROLMODE_LSB) & UARTCS_UARTFLOWCONTROLMODE_MASK)
#define UARTCS_UARTFLOWCONTROLMODE_RESET                             0
#define UARTCS_UARTINTERFACEMODE_MSB                                 3
#define UARTCS_UARTINTERFACEMODE_LSB                                 2
#define UARTCS_UARTINTERFACEMODE_MASK                                0x0000000c
#define UARTCS_UARTINTERFACEMODE_GET(x)                              (((x) & UARTCS_UARTINTERFACEMODE_MASK) >> UARTCS_UARTINTERFACEMODE_LSB)
#define UARTCS_UARTINTERFACEMODE_SET(x)                              (((0 | (x)) << UARTCS_UARTINTERFACEMODE_LSB) & UARTCS_UARTINTERFACEMODE_MASK)
#define UARTCS_UARTINTERFACEMODE_RESET                               0
#define UARTCS_UARTPARITYMODE_MSB                                    1
#define UARTCS_UARTPARITYMODE_LSB                                    0
#define UARTCS_UARTPARITYMODE_MASK                                   0x00000003
#define UARTCS_UARTPARITYMODE_GET(x)                                 (((x) & UARTCS_UARTPARITYMODE_MASK) >> UARTCS_UARTPARITYMODE_LSB)
#define UARTCS_UARTPARITYMODE_SET(x)                                 (((0 | (x)) << UARTCS_UARTPARITYMODE_LSB) & UARTCS_UARTPARITYMODE_MASK)
#define UARTCS_UARTPARITYMODE_RESET                                  0
#define UARTCS_ADDRESS                                               0x0004
#define UARTCS_HW_MASK                                               0x0000ffff
#define UARTCS_SW_MASK                                               0x0000ffff
#define UARTCS_HW_WRITE_MASK                                         0x0000d600
#define UARTCS_SW_WRITE_MASK                                         0x000029ff
#define UARTCS_RSTMASK                                               0xffff29ff
#define UARTCS_RESET                                                 0x00000000

// 0x0008 (UARTCLOCK)
#define UARTCLOCK_UARTCLOCKSCALE_MSB                                 23
#define UARTCLOCK_UARTCLOCKSCALE_LSB                                 16
#define UARTCLOCK_UARTCLOCKSCALE_MASK                                0x00ff0000
#define UARTCLOCK_UARTCLOCKSCALE_GET(x)                              (((x) & UARTCLOCK_UARTCLOCKSCALE_MASK) >> UARTCLOCK_UARTCLOCKSCALE_LSB)
#define UARTCLOCK_UARTCLOCKSCALE_SET(x)                              (((0 | (x)) << UARTCLOCK_UARTCLOCKSCALE_LSB) & UARTCLOCK_UARTCLOCKSCALE_MASK)
#define UARTCLOCK_UARTCLOCKSCALE_RESET                               0
#define UARTCLOCK_UARTCLOCKSTEP_MSB                                  15
#define UARTCLOCK_UARTCLOCKSTEP_LSB                                  0
#define UARTCLOCK_UARTCLOCKSTEP_MASK                                 0x0000ffff
#define UARTCLOCK_UARTCLOCKSTEP_GET(x)                               (((x) & UARTCLOCK_UARTCLOCKSTEP_MASK) >> UARTCLOCK_UARTCLOCKSTEP_LSB)
#define UARTCLOCK_UARTCLOCKSTEP_SET(x)                               (((0 | (x)) << UARTCLOCK_UARTCLOCKSTEP_LSB) & UARTCLOCK_UARTCLOCKSTEP_MASK)
#define UARTCLOCK_UARTCLOCKSTEP_RESET                                0
#define UARTCLOCK_ADDRESS                                            0x0008
#define UARTCLOCK_HW_MASK                                            0x00ffffff
#define UARTCLOCK_SW_MASK                                            0x00ffffff
#define UARTCLOCK_HW_WRITE_MASK                                      0x00000000
#define UARTCLOCK_SW_WRITE_MASK                                      0x00ffffff
#define UARTCLOCK_RSTMASK                                            0xffffffff
#define UARTCLOCK_RESET                                              0x00000000

// 0x000c (UARTINT)
#define UARTINT_UARTTXEMPTYINT_MSB                                   9
#define UARTINT_UARTTXEMPTYINT_LSB                                   9
#define UARTINT_UARTTXEMPTYINT_MASK                                  0x00000200
#define UARTINT_UARTTXEMPTYINT_GET(x)                                (((x) & UARTINT_UARTTXEMPTYINT_MASK) >> UARTINT_UARTTXEMPTYINT_LSB)
#define UARTINT_UARTTXEMPTYINT_SET(x)                                (((0 | (x)) << UARTINT_UARTTXEMPTYINT_LSB) & UARTINT_UARTTXEMPTYINT_MASK)
#define UARTINT_UARTTXEMPTYINT_RESET                                 0
#define UARTINT_UARTRXFULLINT_MSB                                    8
#define UARTINT_UARTRXFULLINT_LSB                                    8
#define UARTINT_UARTRXFULLINT_MASK                                   0x00000100
#define UARTINT_UARTRXFULLINT_GET(x)                                 (((x) & UARTINT_UARTRXFULLINT_MASK) >> UARTINT_UARTRXFULLINT_LSB)
#define UARTINT_UARTRXFULLINT_SET(x)                                 (((0 | (x)) << UARTINT_UARTRXFULLINT_LSB) & UARTINT_UARTRXFULLINT_MASK)
#define UARTINT_UARTRXFULLINT_RESET                                  0
#define UARTINT_UARTRXBREAKOFFINT_MSB                                7
#define UARTINT_UARTRXBREAKOFFINT_LSB                                7
#define UARTINT_UARTRXBREAKOFFINT_MASK                               0x00000080
#define UARTINT_UARTRXBREAKOFFINT_GET(x)                             (((x) & UARTINT_UARTRXBREAKOFFINT_MASK) >> UARTINT_UARTRXBREAKOFFINT_LSB)
#define UARTINT_UARTRXBREAKOFFINT_SET(x)                             (((0 | (x)) << UARTINT_UARTRXBREAKOFFINT_LSB) & UARTINT_UARTRXBREAKOFFINT_MASK)
#define UARTINT_UARTRXBREAKOFFINT_RESET                              0
#define UARTINT_UARTRXBREAKONINT_MSB                                 6
#define UARTINT_UARTRXBREAKONINT_LSB                                 6
#define UARTINT_UARTRXBREAKONINT_MASK                                0x00000040
#define UARTINT_UARTRXBREAKONINT_GET(x)                              (((x) & UARTINT_UARTRXBREAKONINT_MASK) >> UARTINT_UARTRXBREAKONINT_LSB)
#define UARTINT_UARTRXBREAKONINT_SET(x)                              (((0 | (x)) << UARTINT_UARTRXBREAKONINT_LSB) & UARTINT_UARTRXBREAKONINT_MASK)
#define UARTINT_UARTRXBREAKONINT_RESET                               0
#define UARTINT_UARTRXPARITYERRINT_MSB                               5
#define UARTINT_UARTRXPARITYERRINT_LSB                               5
#define UARTINT_UARTRXPARITYERRINT_MASK                              0x00000020
#define UARTINT_UARTRXPARITYERRINT_GET(x)                            (((x) & UARTINT_UARTRXPARITYERRINT_MASK) >> UARTINT_UARTRXPARITYERRINT_LSB)
#define UARTINT_UARTRXPARITYERRINT_SET(x)                            (((0 | (x)) << UARTINT_UARTRXPARITYERRINT_LSB) & UARTINT_UARTRXPARITYERRINT_MASK)
#define UARTINT_UARTRXPARITYERRINT_RESET                             0
#define UARTINT_UARTTXOFLOWERRINT_MSB                                4
#define UARTINT_UARTTXOFLOWERRINT_LSB                                4
#define UARTINT_UARTTXOFLOWERRINT_MASK                               0x00000010
#define UARTINT_UARTTXOFLOWERRINT_GET(x)                             (((x) & UARTINT_UARTTXOFLOWERRINT_MASK) >> UARTINT_UARTTXOFLOWERRINT_LSB)
#define UARTINT_UARTTXOFLOWERRINT_SET(x)                             (((0 | (x)) << UARTINT_UARTTXOFLOWERRINT_LSB) & UARTINT_UARTTXOFLOWERRINT_MASK)
#define UARTINT_UARTTXOFLOWERRINT_RESET                              0
#define UARTINT_UARTRXOFLOWERRINT_MSB                                3
#define UARTINT_UARTRXOFLOWERRINT_LSB                                3
#define UARTINT_UARTRXOFLOWERRINT_MASK                               0x00000008
#define UARTINT_UARTRXOFLOWERRINT_GET(x)                             (((x) & UARTINT_UARTRXOFLOWERRINT_MASK) >> UARTINT_UARTRXOFLOWERRINT_LSB)
#define UARTINT_UARTRXOFLOWERRINT_SET(x)                             (((0 | (x)) << UARTINT_UARTRXOFLOWERRINT_LSB) & UARTINT_UARTRXOFLOWERRINT_MASK)
#define UARTINT_UARTRXOFLOWERRINT_RESET                              0
#define UARTINT_UARTRXFRAMINGERRINT_MSB                              2
#define UARTINT_UARTRXFRAMINGERRINT_LSB                              2
#define UARTINT_UARTRXFRAMINGERRINT_MASK                             0x00000004
#define UARTINT_UARTRXFRAMINGERRINT_GET(x)                           (((x) & UARTINT_UARTRXFRAMINGERRINT_MASK) >> UARTINT_UARTRXFRAMINGERRINT_LSB)
#define UARTINT_UARTRXFRAMINGERRINT_SET(x)                           (((0 | (x)) << UARTINT_UARTRXFRAMINGERRINT_LSB) & UARTINT_UARTRXFRAMINGERRINT_MASK)
#define UARTINT_UARTRXFRAMINGERRINT_RESET                            0
#define UARTINT_UARTTXREADYINT_MSB                                   1
#define UARTINT_UARTTXREADYINT_LSB                                   1
#define UARTINT_UARTTXREADYINT_MASK                                  0x00000002
#define UARTINT_UARTTXREADYINT_GET(x)                                (((x) & UARTINT_UARTTXREADYINT_MASK) >> UARTINT_UARTTXREADYINT_LSB)
#define UARTINT_UARTTXREADYINT_SET(x)                                (((0 | (x)) << UARTINT_UARTTXREADYINT_LSB) & UARTINT_UARTTXREADYINT_MASK)
#define UARTINT_UARTTXREADYINT_RESET                                 0
#define UARTINT_UARTRXVALIDINT_MSB                                   0
#define UARTINT_UARTRXVALIDINT_LSB                                   0
#define UARTINT_UARTRXVALIDINT_MASK                                  0x00000001
#define UARTINT_UARTRXVALIDINT_GET(x)                                (((x) & UARTINT_UARTRXVALIDINT_MASK) >> UARTINT_UARTRXVALIDINT_LSB)
#define UARTINT_UARTRXVALIDINT_SET(x)                                (((0 | (x)) << UARTINT_UARTRXVALIDINT_LSB) & UARTINT_UARTRXVALIDINT_MASK)
#define UARTINT_UARTRXVALIDINT_RESET                                 0
#define UARTINT_ADDRESS                                              0x000c
#define UARTINT_HW_MASK                                              0x000003ff
#define UARTINT_SW_MASK                                              0x000003ff
#define UARTINT_HW_WRITE_MASK                                        0x000003ff
#define UARTINT_SW_WRITE_MASK                                        0x000003ff
#define UARTINT_RSTMASK                                              0xffffffff
#define UARTINT_RESET                                                0x00000000

// 0x0010 (UARTINTEN)
#define UARTINTEN_UARTTXEMPTYINTEN_MSB                               9
#define UARTINTEN_UARTTXEMPTYINTEN_LSB                               9
#define UARTINTEN_UARTTXEMPTYINTEN_MASK                              0x00000200
#define UARTINTEN_UARTTXEMPTYINTEN_GET(x)                            (((x) & UARTINTEN_UARTTXEMPTYINTEN_MASK) >> UARTINTEN_UARTTXEMPTYINTEN_LSB)
#define UARTINTEN_UARTTXEMPTYINTEN_SET(x)                            (((0 | (x)) << UARTINTEN_UARTTXEMPTYINTEN_LSB) & UARTINTEN_UARTTXEMPTYINTEN_MASK)
#define UARTINTEN_UARTTXEMPTYINTEN_RESET                             0
#define UARTINTEN_UARTRXFULLINTEN_MSB                                8
#define UARTINTEN_UARTRXFULLINTEN_LSB                                8
#define UARTINTEN_UARTRXFULLINTEN_MASK                               0x00000100
#define UARTINTEN_UARTRXFULLINTEN_GET(x)                             (((x) & UARTINTEN_UARTRXFULLINTEN_MASK) >> UARTINTEN_UARTRXFULLINTEN_LSB)
#define UARTINTEN_UARTRXFULLINTEN_SET(x)                             (((0 | (x)) << UARTINTEN_UARTRXFULLINTEN_LSB) & UARTINTEN_UARTRXFULLINTEN_MASK)
#define UARTINTEN_UARTRXFULLINTEN_RESET                              0
#define UARTINTEN_UARTRXBREAKOFFINTEN_MSB                            7
#define UARTINTEN_UARTRXBREAKOFFINTEN_LSB                            7
#define UARTINTEN_UARTRXBREAKOFFINTEN_MASK                           0x00000080
#define UARTINTEN_UARTRXBREAKOFFINTEN_GET(x)                         (((x) & UARTINTEN_UARTRXBREAKOFFINTEN_MASK) >> UARTINTEN_UARTRXBREAKOFFINTEN_LSB)
#define UARTINTEN_UARTRXBREAKOFFINTEN_SET(x)                         (((0 | (x)) << UARTINTEN_UARTRXBREAKOFFINTEN_LSB) & UARTINTEN_UARTRXBREAKOFFINTEN_MASK)
#define UARTINTEN_UARTRXBREAKOFFINTEN_RESET                          0
#define UARTINTEN_UARTRXBREAKONINTEN_MSB                             6
#define UARTINTEN_UARTRXBREAKONINTEN_LSB                             6
#define UARTINTEN_UARTRXBREAKONINTEN_MASK                            0x00000040
#define UARTINTEN_UARTRXBREAKONINTEN_GET(x)                          (((x) & UARTINTEN_UARTRXBREAKONINTEN_MASK) >> UARTINTEN_UARTRXBREAKONINTEN_LSB)
#define UARTINTEN_UARTRXBREAKONINTEN_SET(x)                          (((0 | (x)) << UARTINTEN_UARTRXBREAKONINTEN_LSB) & UARTINTEN_UARTRXBREAKONINTEN_MASK)
#define UARTINTEN_UARTRXBREAKONINTEN_RESET                           0
#define UARTINTEN_UARTRXPARITYERRINTEN_MSB                           5
#define UARTINTEN_UARTRXPARITYERRINTEN_LSB                           5
#define UARTINTEN_UARTRXPARITYERRINTEN_MASK                          0x00000020
#define UARTINTEN_UARTRXPARITYERRINTEN_GET(x)                        (((x) & UARTINTEN_UARTRXPARITYERRINTEN_MASK) >> UARTINTEN_UARTRXPARITYERRINTEN_LSB)
#define UARTINTEN_UARTRXPARITYERRINTEN_SET(x)                        (((0 | (x)) << UARTINTEN_UARTRXPARITYERRINTEN_LSB) & UARTINTEN_UARTRXPARITYERRINTEN_MASK)
#define UARTINTEN_UARTRXPARITYERRINTEN_RESET                         0
#define UARTINTEN_UARTTXOFLOWERRINTEN_MSB                            4
#define UARTINTEN_UARTTXOFLOWERRINTEN_LSB                            4
#define UARTINTEN_UARTTXOFLOWERRINTEN_MASK                           0x00000010
#define UARTINTEN_UARTTXOFLOWERRINTEN_GET(x)                         (((x) & UARTINTEN_UARTTXOFLOWERRINTEN_MASK) >> UARTINTEN_UARTTXOFLOWERRINTEN_LSB)
#define UARTINTEN_UARTTXOFLOWERRINTEN_SET(x)                         (((0 | (x)) << UARTINTEN_UARTTXOFLOWERRINTEN_LSB) & UARTINTEN_UARTTXOFLOWERRINTEN_MASK)
#define UARTINTEN_UARTTXOFLOWERRINTEN_RESET                          0
#define UARTINTEN_UARTRXOFLOWERRINTEN_MSB                            3
#define UARTINTEN_UARTRXOFLOWERRINTEN_LSB                            3
#define UARTINTEN_UARTRXOFLOWERRINTEN_MASK                           0x00000008
#define UARTINTEN_UARTRXOFLOWERRINTEN_GET(x)                         (((x) & UARTINTEN_UARTRXOFLOWERRINTEN_MASK) >> UARTINTEN_UARTRXOFLOWERRINTEN_LSB)
#define UARTINTEN_UARTRXOFLOWERRINTEN_SET(x)                         (((0 | (x)) << UARTINTEN_UARTRXOFLOWERRINTEN_LSB) & UARTINTEN_UARTRXOFLOWERRINTEN_MASK)
#define UARTINTEN_UARTRXOFLOWERRINTEN_RESET                          0
#define UARTINTEN_UARTRXFRAMINGERRINTEN_MSB                          2
#define UARTINTEN_UARTRXFRAMINGERRINTEN_LSB                          2
#define UARTINTEN_UARTRXFRAMINGERRINTEN_MASK                         0x00000004
#define UARTINTEN_UARTRXFRAMINGERRINTEN_GET(x)                       (((x) & UARTINTEN_UARTRXFRAMINGERRINTEN_MASK) >> UARTINTEN_UARTRXFRAMINGERRINTEN_LSB)
#define UARTINTEN_UARTRXFRAMINGERRINTEN_SET(x)                       (((0 | (x)) << UARTINTEN_UARTRXFRAMINGERRINTEN_LSB) & UARTINTEN_UARTRXFRAMINGERRINTEN_MASK)
#define UARTINTEN_UARTRXFRAMINGERRINTEN_RESET                        0
#define UARTINTEN_UARTTXREADYINTEN_MSB                               1
#define UARTINTEN_UARTTXREADYINTEN_LSB                               1
#define UARTINTEN_UARTTXREADYINTEN_MASK                              0x00000002
#define UARTINTEN_UARTTXREADYINTEN_GET(x)                            (((x) & UARTINTEN_UARTTXREADYINTEN_MASK) >> UARTINTEN_UARTTXREADYINTEN_LSB)
#define UARTINTEN_UARTTXREADYINTEN_SET(x)                            (((0 | (x)) << UARTINTEN_UARTTXREADYINTEN_LSB) & UARTINTEN_UARTTXREADYINTEN_MASK)
#define UARTINTEN_UARTTXREADYINTEN_RESET                             0
#define UARTINTEN_UARTRXVALIDINTEN_MSB                               0
#define UARTINTEN_UARTRXVALIDINTEN_LSB                               0
#define UARTINTEN_UARTRXVALIDINTEN_MASK                              0x00000001
#define UARTINTEN_UARTRXVALIDINTEN_GET(x)                            (((x) & UARTINTEN_UARTRXVALIDINTEN_MASK) >> UARTINTEN_UARTRXVALIDINTEN_LSB)
#define UARTINTEN_UARTRXVALIDINTEN_SET(x)                            (((0 | (x)) << UARTINTEN_UARTRXVALIDINTEN_LSB) & UARTINTEN_UARTRXVALIDINTEN_MASK)
#define UARTINTEN_UARTRXVALIDINTEN_RESET                             0
#define UARTINTEN_ADDRESS                                            0x0010
#define UARTINTEN_HW_MASK                                            0x000003ff
#define UARTINTEN_SW_MASK                                            0x000003ff
#define UARTINTEN_HW_WRITE_MASK                                      0x00000000
#define UARTINTEN_SW_WRITE_MASK                                      0x000003ff
#define UARTINTEN_RSTMASK                                            0xffffffff
#define UARTINTEN_RESET                                              0x00000000


#endif /* _ATHRUARTCSR_H_ */
