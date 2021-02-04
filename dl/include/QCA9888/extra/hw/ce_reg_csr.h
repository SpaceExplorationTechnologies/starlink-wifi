/*
 * Copyright (c) 2014 Qualcomm Atheros, Inc.
 * All Rights Reserved.
 * Qualcomm Atheros Confidential and Proprietary.
 */
// ------------------------------------------------------------------
// Copyright (c) 2004-2007 Atheros Corporation.  All rights reserved.
// $ATH_LICENSE_HOSTSDK0_C$
// ------------------------------------------------------------------
//===================================================================
// Author(s): ="Atheros"
//===================================================================


#ifdef WLAN_HEADERS

/* We want the CE register addresses to be relative to 0 */
#undef __CE0_CE_REG_CSR_BASE_ADDRESS
#define __CE0_CE_REG_CSR_BASE_ADDRESS   0x0

#include "../../hw/ce0_ce_reg_csr.h"

#if !defined(CE_COUNT)
#define CE_COUNT 12         /* Number of Copy Engines supported */
#endif

// 0x0 (SR_BA)                                                      
#define SR_BA_V_LSB                                             CE0_SR_BA_V_LSB                                             
#define SR_BA_V_MSB                                             CE0_SR_BA_V_MSB                                             
#define SR_BA_V_MASK                                            CE0_SR_BA_V_MASK                                            
#define SR_BA_V_GET(x)                                          CE0_SR_BA_V_GET(x)                                          
#define SR_BA_V_SET(x)                                          CE0_SR_BA_V_SET(x)                                          
#define SR_BA_V_RESET                                           CE0_SR_BA_V_RESET                                           
#define SR_BA_ADDRESS                                           CE0_SR_BA_ADDRESS                                           
#define SR_BA_RSTMASK                                           CE0_SR_BA_RSTMASK                                           
#define SR_BA_RESET                                             CE0_SR_BA_RESET                                             
                                                                                                                              
// 0x4 (SR_SIZE)                                                (CE0_SR_SIZE)
#define SR_SIZE_V_LSB                                           CE0_SR_SIZE_V_LSB                                           
#define SR_SIZE_V_MSB                                           CE0_SR_SIZE_V_MSB                                           
#define SR_SIZE_V_MASK                                          CE0_SR_SIZE_V_MASK                                          
#define SR_SIZE_V_GET(x)                                        CE0_SR_SIZE_V_GET(x)                                        
#define SR_SIZE_V_SET(x)                                        CE0_SR_SIZE_V_SET(x)                                        
#define SR_SIZE_V_RESET                                         CE0_SR_SIZE_V_RESET                                         
#define SR_SIZE_ADDRESS                                         CE0_SR_SIZE_ADDRESS                                         
#define SR_SIZE_RSTMASK                                         CE0_SR_SIZE_RSTMASK                                         
#define SR_SIZE_RESET                                           CE0_SR_SIZE_RESET                                           
                                                                                                                              
// 0x8 (DR_BA)                                                  (CE0_DR_BA)
#define DR_BA_V_LSB                                             CE0_DR_BA_V_LSB                                             
#define DR_BA_V_MSB                                             CE0_DR_BA_V_MSB                                             
#define DR_BA_V_MASK                                            CE0_DR_BA_V_MASK                                            
#define DR_BA_V_GET(x)                                          CE0_DR_BA_V_GET(x)                                          
#define DR_BA_V_SET(x)                                          CE0_DR_BA_V_SET(x)                                          
#define DR_BA_V_RESET                                           CE0_DR_BA_V_RESET                                           
#define DR_BA_ADDRESS                                           CE0_DR_BA_ADDRESS                                           
#define DR_BA_RSTMASK                                           CE0_DR_BA_RSTMASK                                           
#define DR_BA_RESET                                             CE0_DR_BA_RESET                                             
                                                                                                                             
// 0xc (DR_SIZE)                                                (CE0_DR_SIZE)
#define DR_SIZE_V_LSB                                           CE0_DR_SIZE_V_LSB                                           
#define DR_SIZE_V_MSB                                           CE0_DR_SIZE_V_MSB                                           
#define DR_SIZE_V_MASK                                          CE0_DR_SIZE_V_MASK                                          
#define DR_SIZE_V_GET(x)                                        CE0_DR_SIZE_V_GET(x)                                        
#define DR_SIZE_V_SET(x)                                        CE0_DR_SIZE_V_SET(x)                                        
#define DR_SIZE_V_RESET                                         CE0_DR_SIZE_V_RESET                                         
#define DR_SIZE_ADDRESS                                         CE0_DR_SIZE_ADDRESS                                         
#define DR_SIZE_RSTMASK                                         CE0_DR_SIZE_RSTMASK                                         
#define DR_SIZE_RESET                                           CE0_DR_SIZE_RESET                                           
                                                                                                                                 
// 0x10 (CE_CTRL1)                                              (CE0_CE_CTRL1)
#define CE_CTRL1_MSI_EN_LSB                                     CE0_CE_CTRL1_MSI_EN_LSB                                     
#define CE_CTRL1_MSI_EN_MSB                                     CE0_CE_CTRL1_MSI_EN_MSB                                     
#define CE_CTRL1_MSI_EN_MASK                                    CE0_CE_CTRL1_MSI_EN_MASK                                    
#define CE_CTRL1_MSI_EN_GET(x)                                  CE0_CE_CTRL1_MSI_EN_GET(x)                                  
#define CE_CTRL1_MSI_EN_SET(x)                                  CE0_CE_CTRL1_MSI_EN_SET(x)                                  
#define CE_CTRL1_MSI_EN_RESET                                   CE0_CE_CTRL1_MSI_EN_RESET                                   
#define CE_CTRL1_DST_RING_BYTE_SWAP_EN_LSB                      CE0_CE_CTRL1_DST_RING_BYTE_SWAP_EN_LSB                      
#define CE_CTRL1_DST_RING_BYTE_SWAP_EN_MSB                      CE0_CE_CTRL1_DST_RING_BYTE_SWAP_EN_MSB                      
#define CE_CTRL1_DST_RING_BYTE_SWAP_EN_MASK                     CE0_CE_CTRL1_DST_RING_BYTE_SWAP_EN_MASK                     
#define CE_CTRL1_DST_RING_BYTE_SWAP_EN_GET(x)                   CE0_CE_CTRL1_DST_RING_BYTE_SWAP_EN_GET(x)                   
#define CE_CTRL1_DST_RING_BYTE_SWAP_EN_SET(x)                   CE0_CE_CTRL1_DST_RING_BYTE_SWAP_EN_SET(x)                   
#define CE_CTRL1_DST_RING_BYTE_SWAP_EN_RESET                    CE0_CE_CTRL1_DST_RING_BYTE_SWAP_EN_RESET                    
#define CE_CTRL1_SRC_RING_BYTE_SWAP_EN_LSB                      CE0_CE_CTRL1_SRC_RING_BYTE_SWAP_EN_LSB                      
#define CE_CTRL1_SRC_RING_BYTE_SWAP_EN_MSB                      CE0_CE_CTRL1_SRC_RING_BYTE_SWAP_EN_MSB                      
#define CE_CTRL1_SRC_RING_BYTE_SWAP_EN_MASK                     CE0_CE_CTRL1_SRC_RING_BYTE_SWAP_EN_MASK                     
#define CE_CTRL1_SRC_RING_BYTE_SWAP_EN_GET(x)                   CE0_CE_CTRL1_SRC_RING_BYTE_SWAP_EN_GET(x)                   
#define CE_CTRL1_SRC_RING_BYTE_SWAP_EN_SET(x)                   CE0_CE_CTRL1_SRC_RING_BYTE_SWAP_EN_SET(x)                   
#define CE_CTRL1_SRC_RING_BYTE_SWAP_EN_RESET                    CE0_CE_CTRL1_SRC_RING_BYTE_SWAP_EN_RESET                    
#define CE_CTRL1_DMAX_LENGTH_LSB                                CE0_CE_CTRL1_DMAX_LENGTH_LSB                                
#define CE_CTRL1_DMAX_LENGTH_MSB                                CE0_CE_CTRL1_DMAX_LENGTH_MSB                                
#define CE_CTRL1_DMAX_LENGTH_MASK                               CE0_CE_CTRL1_DMAX_LENGTH_MASK                               
#define CE_CTRL1_DMAX_LENGTH_GET(x)                             CE0_CE_CTRL1_DMAX_LENGTH_GET(x)                             
#define CE_CTRL1_DMAX_LENGTH_SET(x)                             CE0_CE_CTRL1_DMAX_LENGTH_SET(x)                             
#define CE_CTRL1_DMAX_LENGTH_RESET                              CE0_CE_CTRL1_DMAX_LENGTH_RESET                              
#define CE_CTRL1_ADDRESS                                        CE0_CE_CTRL1_ADDRESS                                        
#define CE_CTRL1_RSTMASK                                        CE0_CE_CTRL1_RSTMASK                                        
#define CE_CTRL1_RESET                                          CE0_CE_CTRL1_RESET                                          
                                                                                                                                 
// 0x14 (CE_CTRL2)                                              (CE0_CE_CTRL2)
#define CE_CTRL2_NUM_AXI_OUTSTANDING_WRITES_LSB                 CE0_CE_CTRL2_NUM_AXI_OUTSTANDING_WRITES_LSB                 
#define CE_CTRL2_NUM_AXI_OUTSTANDING_WRITES_MSB                 CE0_CE_CTRL2_NUM_AXI_OUTSTANDING_WRITES_MSB                 
#define CE_CTRL2_NUM_AXI_OUTSTANDING_WRITES_MASK                CE0_CE_CTRL2_NUM_AXI_OUTSTANDING_WRITES_MASK                
#define CE_CTRL2_NUM_AXI_OUTSTANDING_WRITES_GET(x)              CE0_CE_CTRL2_NUM_AXI_OUTSTANDING_WRITES_GET(x)              
#define CE_CTRL2_NUM_AXI_OUTSTANDING_WRITES_SET(x)              CE0_CE_CTRL2_NUM_AXI_OUTSTANDING_WRITES_SET(x)              
#define CE_CTRL2_NUM_AXI_OUTSTANDING_WRITES_RESET               CE0_CE_CTRL2_NUM_AXI_OUTSTANDING_WRITES_RESET               
#define CE_CTRL2_NUM_AXI_OUTSTANDING_READS_LSB                  CE0_CE_CTRL2_NUM_AXI_OUTSTANDING_READS_LSB                  
#define CE_CTRL2_NUM_AXI_OUTSTANDING_READS_MSB                  CE0_CE_CTRL2_NUM_AXI_OUTSTANDING_READS_MSB                  
#define CE_CTRL2_NUM_AXI_OUTSTANDING_READS_MASK                 CE0_CE_CTRL2_NUM_AXI_OUTSTANDING_READS_MASK                 
#define CE_CTRL2_NUM_AXI_OUTSTANDING_READS_GET(x)               CE0_CE_CTRL2_NUM_AXI_OUTSTANDING_READS_GET(x)               
#define CE_CTRL2_NUM_AXI_OUTSTANDING_READS_SET(x)               CE0_CE_CTRL2_NUM_AXI_OUTSTANDING_READS_SET(x)               
#define CE_CTRL2_NUM_AXI_OUTSTANDING_READS_RESET                CE0_CE_CTRL2_NUM_AXI_OUTSTANDING_READS_RESET                
#define CE_CTRL2_AXI_TIMEOUT_LSB                                CE0_CE_CTRL2_AXI_TIMEOUT_LSB                                
#define CE_CTRL2_AXI_TIMEOUT_MSB                                CE0_CE_CTRL2_AXI_TIMEOUT_MSB                                
#define CE_CTRL2_AXI_TIMEOUT_MASK                               CE0_CE_CTRL2_AXI_TIMEOUT_MASK                               
#define CE_CTRL2_AXI_TIMEOUT_GET(x)                             CE0_CE_CTRL2_AXI_TIMEOUT_GET(x)                             
#define CE_CTRL2_AXI_TIMEOUT_SET(x)                             CE0_CE_CTRL2_AXI_TIMEOUT_SET(x)                             
#define CE_CTRL2_AXI_TIMEOUT_RESET                              CE0_CE_CTRL2_AXI_TIMEOUT_RESET                              
#define CE_CTRL2_DEST_AXI_MAX_LEN_LSB                           CE0_CE_CTRL2_DEST_AXI_MAX_LEN_LSB                           
#define CE_CTRL2_DEST_AXI_MAX_LEN_MSB                           CE0_CE_CTRL2_DEST_AXI_MAX_LEN_MSB                           
#define CE_CTRL2_DEST_AXI_MAX_LEN_MASK                          CE0_CE_CTRL2_DEST_AXI_MAX_LEN_MASK                          
#define CE_CTRL2_DEST_AXI_MAX_LEN_GET(x)                        CE0_CE_CTRL2_DEST_AXI_MAX_LEN_GET(x)                        
#define CE_CTRL2_DEST_AXI_MAX_LEN_SET(x)                        CE0_CE_CTRL2_DEST_AXI_MAX_LEN_SET(x)                        
#define CE_CTRL2_DEST_AXI_MAX_LEN_RESET                         CE0_CE_CTRL2_DEST_AXI_MAX_LEN_RESET                         
#define CE_CTRL2_SRC_AXI_MAX_LEN_LSB                            CE0_CE_CTRL2_SRC_AXI_MAX_LEN_LSB                            
#define CE_CTRL2_SRC_AXI_MAX_LEN_MSB                            CE0_CE_CTRL2_SRC_AXI_MAX_LEN_MSB                            
#define CE_CTRL2_SRC_AXI_MAX_LEN_MASK                           CE0_CE_CTRL2_SRC_AXI_MAX_LEN_MASK                           
#define CE_CTRL2_SRC_AXI_MAX_LEN_GET(x)                         CE0_CE_CTRL2_SRC_AXI_MAX_LEN_GET(x)                         
#define CE_CTRL2_SRC_AXI_MAX_LEN_SET(x)                         CE0_CE_CTRL2_SRC_AXI_MAX_LEN_SET(x)                         
#define CE_CTRL2_SRC_AXI_MAX_LEN_RESET                          CE0_CE_CTRL2_SRC_AXI_MAX_LEN_RESET                          
#define CE_CTRL2_ADDRESS                                        CE0_CE_CTRL2_ADDRESS                                        
#define CE_CTRL2_RSTMASK                                        CE0_CE_CTRL2_RSTMASK                                        
#define CE_CTRL2_RESET                                          CE0_CE_CTRL2_RESET                                          
                                                                                                                                 
// 0x18 (CE_CMD)                                                (CE0_CE_CMD)
#define CE_CMD_HALT_STATUS_LSB                                  CE0_CE_CMD_HALT_STATUS_LSB                                  
#define CE_CMD_HALT_STATUS_MSB                                  CE0_CE_CMD_HALT_STATUS_MSB                                  
#define CE_CMD_HALT_STATUS_MASK                                 CE0_CE_CMD_HALT_STATUS_MASK                                 
#define CE_CMD_HALT_STATUS_GET(x)                               CE0_CE_CMD_HALT_STATUS_GET(x)                               
#define CE_CMD_HALT_STATUS_SET(x)                               CE0_CE_CMD_HALT_STATUS_SET(x)                               
#define CE_CMD_HALT_STATUS_RESET                                CE0_CE_CMD_HALT_STATUS_RESET                                
#define CE_CMD_DST_FLUSH_LSB                                    CE0_CE_CMD_DST_FLUSH_LSB                                    
#define CE_CMD_DST_FLUSH_MSB                                    CE0_CE_CMD_DST_FLUSH_MSB                                    
#define CE_CMD_DST_FLUSH_MASK                                   CE0_CE_CMD_DST_FLUSH_MASK                                   
#define CE_CMD_DST_FLUSH_GET(x)                                 CE0_CE_CMD_DST_FLUSH_GET(x)                                 
#define CE_CMD_DST_FLUSH_SET(x)                                 CE0_CE_CMD_DST_FLUSH_SET(x)                                 
#define CE_CMD_DST_FLUSH_RESET                                  CE0_CE_CMD_DST_FLUSH_RESET                                  
#define CE_CMD_SRC_FLUSH_LSB                                    CE0_CE_CMD_SRC_FLUSH_LSB                                    
#define CE_CMD_SRC_FLUSH_MSB                                    CE0_CE_CMD_SRC_FLUSH_MSB                                    
#define CE_CMD_SRC_FLUSH_MASK                                   CE0_CE_CMD_SRC_FLUSH_MASK                                   
#define CE_CMD_SRC_FLUSH_GET(x)                                 CE0_CE_CMD_SRC_FLUSH_GET(x)                                 
#define CE_CMD_SRC_FLUSH_SET(x)                                 CE0_CE_CMD_SRC_FLUSH_SET(x)                                 
#define CE_CMD_SRC_FLUSH_RESET                                  CE0_CE_CMD_SRC_FLUSH_RESET                                  
#define CE_CMD_HALT_LSB                                         CE0_CE_CMD_HALT_LSB                                         
#define CE_CMD_HALT_MSB                                         CE0_CE_CMD_HALT_MSB                                         
#define CE_CMD_HALT_MASK                                        CE0_CE_CMD_HALT_MASK                                        
#define CE_CMD_HALT_GET(x)                                      CE0_CE_CMD_HALT_GET(x)                                      
#define CE_CMD_HALT_SET(x)                                      CE0_CE_CMD_HALT_SET(x)                                      
#define CE_CMD_HALT_RESET                                       CE0_CE_CMD_HALT_RESET                                       
#define CE_CMD_ADDRESS                                          CE0_CE_CMD_ADDRESS                                          
#define CE_CMD_RSTMASK                                          CE0_CE_CMD_RSTMASK                                          
#define CE_CMD_RESET                                            CE0_CE_CMD_RESET                                            
                                                                                                                                 
// 0x1c (MSI_ADDR)                                              (CE0_MSI_ADDR)
#define MSI_ADDR_V_LSB                                          CE0_MSI_ADDR_V_LSB                                          
#define MSI_ADDR_V_MSB                                          CE0_MSI_ADDR_V_MSB                                          
#define MSI_ADDR_V_MASK                                         CE0_MSI_ADDR_V_MASK                                         
#define MSI_ADDR_V_GET(x)                                       CE0_MSI_ADDR_V_GET(x)                                       
#define MSI_ADDR_V_SET(x)                                       CE0_MSI_ADDR_V_SET(x)                                       
#define MSI_ADDR_V_RESET                                        CE0_MSI_ADDR_V_RESET                                        
#define MSI_ADDR_ADDRESS                                        CE0_MSI_ADDR_ADDRESS                                        
#define MSI_ADDR_RSTMASK                                        CE0_MSI_ADDR_RSTMASK                                        
#define MSI_ADDR_RESET                                          CE0_MSI_ADDR_RESET                                          
                                                                                                                                 
// 0x20 (MSI_DATA)                                              (CE0_MSI_DATA)
#define MSI_DATA_V_LSB                                          CE0_MSI_DATA_V_LSB                                          
#define MSI_DATA_V_MSB                                          CE0_MSI_DATA_V_MSB                                          
#define MSI_DATA_V_MASK                                         CE0_MSI_DATA_V_MASK                                         
#define MSI_DATA_V_GET(x)                                       CE0_MSI_DATA_V_GET(x)                                       
#define MSI_DATA_V_SET(x)                                       CE0_MSI_DATA_V_SET(x)                                       
#define MSI_DATA_V_RESET                                        CE0_MSI_DATA_V_RESET                                        
#define MSI_DATA_ADDRESS                                        CE0_MSI_DATA_ADDRESS                                        
#define MSI_DATA_RSTMASK                                        CE0_MSI_DATA_RSTMASK                                        
#define MSI_DATA_RESET                                          CE0_MSI_DATA_RESET                                          
                                                                                                                                 
// 0x24 (TARGET_IE)                                             (CE0_TARGET_IE)
#define TARGET_IE_DST_RING_LOW_WATERMARK_LSB                    CE0_TARGET_IE_DST_RING_LOW_WATERMARK_LSB                    
#define TARGET_IE_DST_RING_LOW_WATERMARK_MSB                    CE0_TARGET_IE_DST_RING_LOW_WATERMARK_MSB                    
#define TARGET_IE_DST_RING_LOW_WATERMARK_MASK                   CE0_TARGET_IE_DST_RING_LOW_WATERMARK_MASK                   
#define TARGET_IE_DST_RING_LOW_WATERMARK_GET(x)                 CE0_TARGET_IE_DST_RING_LOW_WATERMARK_GET(x)                 
#define TARGET_IE_DST_RING_LOW_WATERMARK_SET(x)                 CE0_TARGET_IE_DST_RING_LOW_WATERMARK_SET(x)                 
#define TARGET_IE_DST_RING_LOW_WATERMARK_RESET                  CE0_TARGET_IE_DST_RING_LOW_WATERMARK_RESET                  
#define TARGET_IE_DST_RING_HIGH_WATERMARK_LSB                   CE0_TARGET_IE_DST_RING_HIGH_WATERMARK_LSB                   
#define TARGET_IE_DST_RING_HIGH_WATERMARK_MSB                   CE0_TARGET_IE_DST_RING_HIGH_WATERMARK_MSB                   
#define TARGET_IE_DST_RING_HIGH_WATERMARK_MASK                  CE0_TARGET_IE_DST_RING_HIGH_WATERMARK_MASK                  
#define TARGET_IE_DST_RING_HIGH_WATERMARK_GET(x)                CE0_TARGET_IE_DST_RING_HIGH_WATERMARK_GET(x)                
#define TARGET_IE_DST_RING_HIGH_WATERMARK_SET(x)                CE0_TARGET_IE_DST_RING_HIGH_WATERMARK_SET(x)                
#define TARGET_IE_DST_RING_HIGH_WATERMARK_RESET                 CE0_TARGET_IE_DST_RING_HIGH_WATERMARK_RESET                 
#define TARGET_IE_SRC_RING_LOW_WATERMARK_LSB                    CE0_TARGET_IE_SRC_RING_LOW_WATERMARK_LSB                    
#define TARGET_IE_SRC_RING_LOW_WATERMARK_MSB                    CE0_TARGET_IE_SRC_RING_LOW_WATERMARK_MSB                    
#define TARGET_IE_SRC_RING_LOW_WATERMARK_MASK                   CE0_TARGET_IE_SRC_RING_LOW_WATERMARK_MASK                   
#define TARGET_IE_SRC_RING_LOW_WATERMARK_GET(x)                 CE0_TARGET_IE_SRC_RING_LOW_WATERMARK_GET(x)                 
#define TARGET_IE_SRC_RING_LOW_WATERMARK_SET(x)                 CE0_TARGET_IE_SRC_RING_LOW_WATERMARK_SET(x)                 
#define TARGET_IE_SRC_RING_LOW_WATERMARK_RESET                  CE0_TARGET_IE_SRC_RING_LOW_WATERMARK_RESET                  
#define TARGET_IE_SRC_RING_HIGH_WATERMARK_LSB                   CE0_TARGET_IE_SRC_RING_HIGH_WATERMARK_LSB                   
#define TARGET_IE_SRC_RING_HIGH_WATERMARK_MSB                   CE0_TARGET_IE_SRC_RING_HIGH_WATERMARK_MSB                   
#define TARGET_IE_SRC_RING_HIGH_WATERMARK_MASK                  CE0_TARGET_IE_SRC_RING_HIGH_WATERMARK_MASK                  
#define TARGET_IE_SRC_RING_HIGH_WATERMARK_GET(x)                CE0_TARGET_IE_SRC_RING_HIGH_WATERMARK_GET(x)                
#define TARGET_IE_SRC_RING_HIGH_WATERMARK_SET(x)                CE0_TARGET_IE_SRC_RING_HIGH_WATERMARK_SET(x)                
#define TARGET_IE_SRC_RING_HIGH_WATERMARK_RESET                 CE0_TARGET_IE_SRC_RING_HIGH_WATERMARK_RESET                 
#define TARGET_IE_COPY_COMPLETE_LSB                             CE0_TARGET_IE_COPY_COMPLETE_LSB                             
#define TARGET_IE_COPY_COMPLETE_MSB                             CE0_TARGET_IE_COPY_COMPLETE_MSB                             
#define TARGET_IE_COPY_COMPLETE_MASK                            CE0_TARGET_IE_COPY_COMPLETE_MASK                            
#define TARGET_IE_COPY_COMPLETE_GET(x)                          CE0_TARGET_IE_COPY_COMPLETE_GET(x)                          
#define TARGET_IE_COPY_COMPLETE_SET(x)                          CE0_TARGET_IE_COPY_COMPLETE_SET(x)                          
#define TARGET_IE_COPY_COMPLETE_RESET                           CE0_TARGET_IE_COPY_COMPLETE_RESET                           
#define TARGET_IE_ADDRESS                                       CE0_TARGET_IE_ADDRESS                                       
#define TARGET_IE_RSTMASK                                       CE0_TARGET_IE_RSTMASK                                       
#define TARGET_IE_RESET                                         CE0_TARGET_IE_RESET                                         
                                                                                                                                 
// 0x28 (TARGET_IS)                                             (CE0_TARGET_IS)
#define TARGET_IS_DST_RING_LOW_WATERMARK_LSB                    CE0_TARGET_IS_DST_RING_LOW_WATERMARK_LSB                    
#define TARGET_IS_DST_RING_LOW_WATERMARK_MSB                    CE0_TARGET_IS_DST_RING_LOW_WATERMARK_MSB                    
#define TARGET_IS_DST_RING_LOW_WATERMARK_MASK                   CE0_TARGET_IS_DST_RING_LOW_WATERMARK_MASK                   
#define TARGET_IS_DST_RING_LOW_WATERMARK_GET(x)                 CE0_TARGET_IS_DST_RING_LOW_WATERMARK_GET(x)                 
#define TARGET_IS_DST_RING_LOW_WATERMARK_SET(x)                 CE0_TARGET_IS_DST_RING_LOW_WATERMARK_SET(x)                 
#define TARGET_IS_DST_RING_LOW_WATERMARK_RESET                  CE0_TARGET_IS_DST_RING_LOW_WATERMARK_RESET                  
#define TARGET_IS_DST_RING_HIGH_WATERMARK_LSB                   CE0_TARGET_IS_DST_RING_HIGH_WATERMARK_LSB                   
#define TARGET_IS_DST_RING_HIGH_WATERMARK_MSB                   CE0_TARGET_IS_DST_RING_HIGH_WATERMARK_MSB                   
#define TARGET_IS_DST_RING_HIGH_WATERMARK_MASK                  CE0_TARGET_IS_DST_RING_HIGH_WATERMARK_MASK                  
#define TARGET_IS_DST_RING_HIGH_WATERMARK_GET(x)                CE0_TARGET_IS_DST_RING_HIGH_WATERMARK_GET(x)                
#define TARGET_IS_DST_RING_HIGH_WATERMARK_SET(x)                CE0_TARGET_IS_DST_RING_HIGH_WATERMARK_SET(x)                
#define TARGET_IS_DST_RING_HIGH_WATERMARK_RESET                 CE0_TARGET_IS_DST_RING_HIGH_WATERMARK_RESET                 
#define TARGET_IS_SRC_RING_LOW_WATERMARK_LSB                    CE0_TARGET_IS_SRC_RING_LOW_WATERMARK_LSB                    
#define TARGET_IS_SRC_RING_LOW_WATERMARK_MSB                    CE0_TARGET_IS_SRC_RING_LOW_WATERMARK_MSB                    
#define TARGET_IS_SRC_RING_LOW_WATERMARK_MASK                   CE0_TARGET_IS_SRC_RING_LOW_WATERMARK_MASK                   
#define TARGET_IS_SRC_RING_LOW_WATERMARK_GET(x)                 CE0_TARGET_IS_SRC_RING_LOW_WATERMARK_GET(x)                 
#define TARGET_IS_SRC_RING_LOW_WATERMARK_SET(x)                 CE0_TARGET_IS_SRC_RING_LOW_WATERMARK_SET(x)                 
#define TARGET_IS_SRC_RING_LOW_WATERMARK_RESET                  CE0_TARGET_IS_SRC_RING_LOW_WATERMARK_RESET                  
#define TARGET_IS_SRC_RING_HIGH_WATERMARK_LSB                   CE0_TARGET_IS_SRC_RING_HIGH_WATERMARK_LSB                   
#define TARGET_IS_SRC_RING_HIGH_WATERMARK_MSB                   CE0_TARGET_IS_SRC_RING_HIGH_WATERMARK_MSB                   
#define TARGET_IS_SRC_RING_HIGH_WATERMARK_MASK                  CE0_TARGET_IS_SRC_RING_HIGH_WATERMARK_MASK                  
#define TARGET_IS_SRC_RING_HIGH_WATERMARK_GET(x)                CE0_TARGET_IS_SRC_RING_HIGH_WATERMARK_GET(x)                
#define TARGET_IS_SRC_RING_HIGH_WATERMARK_SET(x)                CE0_TARGET_IS_SRC_RING_HIGH_WATERMARK_SET(x)                
#define TARGET_IS_SRC_RING_HIGH_WATERMARK_RESET                 CE0_TARGET_IS_SRC_RING_HIGH_WATERMARK_RESET                 
#define TARGET_IS_COPY_COMPLETE_LSB                             CE0_TARGET_IS_COPY_COMPLETE_LSB                             
#define TARGET_IS_COPY_COMPLETE_MSB                             CE0_TARGET_IS_COPY_COMPLETE_MSB                             
#define TARGET_IS_COPY_COMPLETE_MASK                            CE0_TARGET_IS_COPY_COMPLETE_MASK                            
#define TARGET_IS_COPY_COMPLETE_GET(x)                          CE0_TARGET_IS_COPY_COMPLETE_GET(x)                          
#define TARGET_IS_COPY_COMPLETE_SET(x)                          CE0_TARGET_IS_COPY_COMPLETE_SET(x)                          
#define TARGET_IS_COPY_COMPLETE_RESET                           CE0_TARGET_IS_COPY_COMPLETE_RESET                           
#define TARGET_IS_ADDRESS                                       CE0_TARGET_IS_ADDRESS                                       
#define TARGET_IS_RSTMASK                                       CE0_TARGET_IS_RSTMASK                                       
#define TARGET_IS_RESET                                         CE0_TARGET_IS_RESET                                         
                                                                                                                                 
// 0x2c (HOST_IE)                                               (CE0_HOST_IE)
#define HOST_IE_DST_RING_LOW_WATERMARK_LSB                      CE0_HOST_IE_DST_RING_LOW_WATERMARK_LSB                      
#define HOST_IE_DST_RING_LOW_WATERMARK_MSB                      CE0_HOST_IE_DST_RING_LOW_WATERMARK_MSB                      
#define HOST_IE_DST_RING_LOW_WATERMARK_MASK                     CE0_HOST_IE_DST_RING_LOW_WATERMARK_MASK                     
#define HOST_IE_DST_RING_LOW_WATERMARK_GET(x)                   CE0_HOST_IE_DST_RING_LOW_WATERMARK_GET(x)                   
#define HOST_IE_DST_RING_LOW_WATERMARK_SET(x)                   CE0_HOST_IE_DST_RING_LOW_WATERMARK_SET(x)                   
#define HOST_IE_DST_RING_LOW_WATERMARK_RESET                    CE0_HOST_IE_DST_RING_LOW_WATERMARK_RESET                    
#define HOST_IE_DST_RING_HIGH_WATERMARK_LSB                     CE0_HOST_IE_DST_RING_HIGH_WATERMARK_LSB                     
#define HOST_IE_DST_RING_HIGH_WATERMARK_MSB                     CE0_HOST_IE_DST_RING_HIGH_WATERMARK_MSB                     
#define HOST_IE_DST_RING_HIGH_WATERMARK_MASK                    CE0_HOST_IE_DST_RING_HIGH_WATERMARK_MASK                    
#define HOST_IE_DST_RING_HIGH_WATERMARK_GET(x)                  CE0_HOST_IE_DST_RING_HIGH_WATERMARK_GET(x)                  
#define HOST_IE_DST_RING_HIGH_WATERMARK_SET(x)                  CE0_HOST_IE_DST_RING_HIGH_WATERMARK_SET(x)                  
#define HOST_IE_DST_RING_HIGH_WATERMARK_RESET                   CE0_HOST_IE_DST_RING_HIGH_WATERMARK_RESET                   
#define HOST_IE_SRC_RING_LOW_WATERMARK_LSB                      CE0_HOST_IE_SRC_RING_LOW_WATERMARK_LSB                      
#define HOST_IE_SRC_RING_LOW_WATERMARK_MSB                      CE0_HOST_IE_SRC_RING_LOW_WATERMARK_MSB                      
#define HOST_IE_SRC_RING_LOW_WATERMARK_MASK                     CE0_HOST_IE_SRC_RING_LOW_WATERMARK_MASK                     
#define HOST_IE_SRC_RING_LOW_WATERMARK_GET(x)                   CE0_HOST_IE_SRC_RING_LOW_WATERMARK_GET(x)                   
#define HOST_IE_SRC_RING_LOW_WATERMARK_SET(x)                   CE0_HOST_IE_SRC_RING_LOW_WATERMARK_SET(x)                   
#define HOST_IE_SRC_RING_LOW_WATERMARK_RESET                    CE0_HOST_IE_SRC_RING_LOW_WATERMARK_RESET                    
#define HOST_IE_SRC_RING_HIGH_WATERMARK_LSB                     CE0_HOST_IE_SRC_RING_HIGH_WATERMARK_LSB                     
#define HOST_IE_SRC_RING_HIGH_WATERMARK_MSB                     CE0_HOST_IE_SRC_RING_HIGH_WATERMARK_MSB                     
#define HOST_IE_SRC_RING_HIGH_WATERMARK_MASK                    CE0_HOST_IE_SRC_RING_HIGH_WATERMARK_MASK                    
#define HOST_IE_SRC_RING_HIGH_WATERMARK_GET(x)                  CE0_HOST_IE_SRC_RING_HIGH_WATERMARK_GET(x)                  
#define HOST_IE_SRC_RING_HIGH_WATERMARK_SET(x)                  CE0_HOST_IE_SRC_RING_HIGH_WATERMARK_SET(x)                  
#define HOST_IE_SRC_RING_HIGH_WATERMARK_RESET                   CE0_HOST_IE_SRC_RING_HIGH_WATERMARK_RESET                   
#define HOST_IE_COPY_COMPLETE_LSB                               CE0_HOST_IE_COPY_COMPLETE_LSB                               
#define HOST_IE_COPY_COMPLETE_MSB                               CE0_HOST_IE_COPY_COMPLETE_MSB                               
#define HOST_IE_COPY_COMPLETE_MASK                              CE0_HOST_IE_COPY_COMPLETE_MASK                              
#define HOST_IE_COPY_COMPLETE_GET(x)                            CE0_HOST_IE_COPY_COMPLETE_GET(x)                            
#define HOST_IE_COPY_COMPLETE_SET(x)                            CE0_HOST_IE_COPY_COMPLETE_SET(x)                            
#define HOST_IE_COPY_COMPLETE_RESET                             CE0_HOST_IE_COPY_COMPLETE_RESET                             
#define HOST_IE_ADDRESS                                         CE0_HOST_IE_ADDRESS                                         
#define HOST_IE_RSTMASK                                         CE0_HOST_IE_RSTMASK                                         
#define HOST_IE_RESET                                           CE0_HOST_IE_RESET                                           
                                                                                                                                 
// 0x30 (HOST_IS)                                               (CE0_HOST_IS)
#define HOST_IS_DST_RING_LOW_WATERMARK_LSB                      CE0_HOST_IS_DST_RING_LOW_WATERMARK_LSB                      
#define HOST_IS_DST_RING_LOW_WATERMARK_MSB                      CE0_HOST_IS_DST_RING_LOW_WATERMARK_MSB                      
#define HOST_IS_DST_RING_LOW_WATERMARK_MASK                     CE0_HOST_IS_DST_RING_LOW_WATERMARK_MASK                     
#define HOST_IS_DST_RING_LOW_WATERMARK_GET(x)                   CE0_HOST_IS_DST_RING_LOW_WATERMARK_GET(x)                   
#define HOST_IS_DST_RING_LOW_WATERMARK_SET(x)                   CE0_HOST_IS_DST_RING_LOW_WATERMARK_SET(x)                   
#define HOST_IS_DST_RING_LOW_WATERMARK_RESET                    CE0_HOST_IS_DST_RING_LOW_WATERMARK_RESET                    
#define HOST_IS_DST_RING_HIGH_WATERMARK_LSB                     CE0_HOST_IS_DST_RING_HIGH_WATERMARK_LSB                     
#define HOST_IS_DST_RING_HIGH_WATERMARK_MSB                     CE0_HOST_IS_DST_RING_HIGH_WATERMARK_MSB                     
#define HOST_IS_DST_RING_HIGH_WATERMARK_MASK                    CE0_HOST_IS_DST_RING_HIGH_WATERMARK_MASK                    
#define HOST_IS_DST_RING_HIGH_WATERMARK_GET(x)                  CE0_HOST_IS_DST_RING_HIGH_WATERMARK_GET(x)                  
#define HOST_IS_DST_RING_HIGH_WATERMARK_SET(x)                  CE0_HOST_IS_DST_RING_HIGH_WATERMARK_SET(x)                  
#define HOST_IS_DST_RING_HIGH_WATERMARK_RESET                   CE0_HOST_IS_DST_RING_HIGH_WATERMARK_RESET                   
#define HOST_IS_SRC_RING_LOW_WATERMARK_LSB                      CE0_HOST_IS_SRC_RING_LOW_WATERMARK_LSB                      
#define HOST_IS_SRC_RING_LOW_WATERMARK_MSB                      CE0_HOST_IS_SRC_RING_LOW_WATERMARK_MSB                      
#define HOST_IS_SRC_RING_LOW_WATERMARK_MASK                     CE0_HOST_IS_SRC_RING_LOW_WATERMARK_MASK                     
#define HOST_IS_SRC_RING_LOW_WATERMARK_GET(x)                   CE0_HOST_IS_SRC_RING_LOW_WATERMARK_GET(x)                   
#define HOST_IS_SRC_RING_LOW_WATERMARK_SET(x)                   CE0_HOST_IS_SRC_RING_LOW_WATERMARK_SET(x)                   
#define HOST_IS_SRC_RING_LOW_WATERMARK_RESET                    CE0_HOST_IS_SRC_RING_LOW_WATERMARK_RESET                    
#define HOST_IS_SRC_RING_HIGH_WATERMARK_LSB                     CE0_HOST_IS_SRC_RING_HIGH_WATERMARK_LSB                     
#define HOST_IS_SRC_RING_HIGH_WATERMARK_MSB                     CE0_HOST_IS_SRC_RING_HIGH_WATERMARK_MSB                     
#define HOST_IS_SRC_RING_HIGH_WATERMARK_MASK                    CE0_HOST_IS_SRC_RING_HIGH_WATERMARK_MASK                    
#define HOST_IS_SRC_RING_HIGH_WATERMARK_GET(x)                  CE0_HOST_IS_SRC_RING_HIGH_WATERMARK_GET(x)                  
#define HOST_IS_SRC_RING_HIGH_WATERMARK_SET(x)                  CE0_HOST_IS_SRC_RING_HIGH_WATERMARK_SET(x)                  
#define HOST_IS_SRC_RING_HIGH_WATERMARK_RESET                   CE0_HOST_IS_SRC_RING_HIGH_WATERMARK_RESET                   
#define HOST_IS_COPY_COMPLETE_LSB                               CE0_HOST_IS_COPY_COMPLETE_LSB                               
#define HOST_IS_COPY_COMPLETE_MSB                               CE0_HOST_IS_COPY_COMPLETE_MSB                               
#define HOST_IS_COPY_COMPLETE_MASK                              CE0_HOST_IS_COPY_COMPLETE_MASK                              
#define HOST_IS_COPY_COMPLETE_GET(x)                            CE0_HOST_IS_COPY_COMPLETE_GET(x)                            
#define HOST_IS_COPY_COMPLETE_SET(x)                            CE0_HOST_IS_COPY_COMPLETE_SET(x)                            
#define HOST_IS_COPY_COMPLETE_RESET                             CE0_HOST_IS_COPY_COMPLETE_RESET                             
#define HOST_IS_ADDRESS                                         CE0_HOST_IS_ADDRESS                                         
#define HOST_IS_RSTMASK                                         CE0_HOST_IS_RSTMASK                                         
#define HOST_IS_RESET                                           CE0_HOST_IS_RESET                                           
                                                                                                                                 
// 0x34 (MISC_IE)                                               (CE0_MISC_IE)
#define MISC_IE_AXI_ERR_LSB                                     CE0_MISC_IE_AXI_ERR_LSB                                     
#define MISC_IE_AXI_ERR_MSB                                     CE0_MISC_IE_AXI_ERR_MSB                                     
#define MISC_IE_AXI_ERR_MASK                                    CE0_MISC_IE_AXI_ERR_MASK                                    
#define MISC_IE_AXI_ERR_GET(x)                                  CE0_MISC_IE_AXI_ERR_GET(x)                                  
#define MISC_IE_AXI_ERR_SET(x)                                  CE0_MISC_IE_AXI_ERR_SET(x)                                  
#define MISC_IE_AXI_ERR_RESET                                   CE0_MISC_IE_AXI_ERR_RESET                                   
#define MISC_IE_DST_ADDR_ERR_LSB                                CE0_MISC_IE_DST_ADDR_ERR_LSB                                
#define MISC_IE_DST_ADDR_ERR_MSB                                CE0_MISC_IE_DST_ADDR_ERR_MSB                                
#define MISC_IE_DST_ADDR_ERR_MASK                               CE0_MISC_IE_DST_ADDR_ERR_MASK                               
#define MISC_IE_DST_ADDR_ERR_GET(x)                             CE0_MISC_IE_DST_ADDR_ERR_GET(x)                             
#define MISC_IE_DST_ADDR_ERR_SET(x)                             CE0_MISC_IE_DST_ADDR_ERR_SET(x)                             
#define MISC_IE_DST_ADDR_ERR_RESET                              CE0_MISC_IE_DST_ADDR_ERR_RESET                              
#define MISC_IE_SRC_LEN_ERR_LSB                                 CE0_MISC_IE_SRC_LEN_ERR_LSB                                 
#define MISC_IE_SRC_LEN_ERR_MSB                                 CE0_MISC_IE_SRC_LEN_ERR_MSB                                 
#define MISC_IE_SRC_LEN_ERR_MASK                                CE0_MISC_IE_SRC_LEN_ERR_MASK                                
#define MISC_IE_SRC_LEN_ERR_GET(x)                              CE0_MISC_IE_SRC_LEN_ERR_GET(x)                              
#define MISC_IE_SRC_LEN_ERR_SET(x)                              CE0_MISC_IE_SRC_LEN_ERR_SET(x)                              
#define MISC_IE_SRC_LEN_ERR_RESET                               CE0_MISC_IE_SRC_LEN_ERR_RESET                               
#define MISC_IE_DST_MAX_LEN_VIO_LSB                             CE0_MISC_IE_DST_MAX_LEN_VIO_LSB                             
#define MISC_IE_DST_MAX_LEN_VIO_MSB                             CE0_MISC_IE_DST_MAX_LEN_VIO_MSB                             
#define MISC_IE_DST_MAX_LEN_VIO_MASK                            CE0_MISC_IE_DST_MAX_LEN_VIO_MASK                            
#define MISC_IE_DST_MAX_LEN_VIO_GET(x)                          CE0_MISC_IE_DST_MAX_LEN_VIO_GET(x)                          
#define MISC_IE_DST_MAX_LEN_VIO_SET(x)                          CE0_MISC_IE_DST_MAX_LEN_VIO_SET(x)                          
#define MISC_IE_DST_MAX_LEN_VIO_RESET                           CE0_MISC_IE_DST_MAX_LEN_VIO_RESET                           
#define MISC_IE_DST_RING_OVERFLOW_LSB                           CE0_MISC_IE_DST_RING_OVERFLOW_LSB                           
#define MISC_IE_DST_RING_OVERFLOW_MSB                           CE0_MISC_IE_DST_RING_OVERFLOW_MSB                           
#define MISC_IE_DST_RING_OVERFLOW_MASK                          CE0_MISC_IE_DST_RING_OVERFLOW_MASK                          
#define MISC_IE_DST_RING_OVERFLOW_GET(x)                        CE0_MISC_IE_DST_RING_OVERFLOW_GET(x)                        
#define MISC_IE_DST_RING_OVERFLOW_SET(x)                        CE0_MISC_IE_DST_RING_OVERFLOW_SET(x)                        
#define MISC_IE_DST_RING_OVERFLOW_RESET                         CE0_MISC_IE_DST_RING_OVERFLOW_RESET                         
#define MISC_IE_SRC_RING_OVERFLOW_LSB                           CE0_MISC_IE_SRC_RING_OVERFLOW_LSB                           
#define MISC_IE_SRC_RING_OVERFLOW_MSB                           CE0_MISC_IE_SRC_RING_OVERFLOW_MSB                           
#define MISC_IE_SRC_RING_OVERFLOW_MASK                          CE0_MISC_IE_SRC_RING_OVERFLOW_MASK                          
#define MISC_IE_SRC_RING_OVERFLOW_GET(x)                        CE0_MISC_IE_SRC_RING_OVERFLOW_GET(x)                        
#define MISC_IE_SRC_RING_OVERFLOW_SET(x)                        CE0_MISC_IE_SRC_RING_OVERFLOW_SET(x)                        
#define MISC_IE_SRC_RING_OVERFLOW_RESET                         CE0_MISC_IE_SRC_RING_OVERFLOW_RESET                         
#define MISC_IE_DST_RING_LOW_WATERMARK_LSB                      CE0_MISC_IE_DST_RING_LOW_WATERMARK_LSB                      
#define MISC_IE_DST_RING_LOW_WATERMARK_MSB                      CE0_MISC_IE_DST_RING_LOW_WATERMARK_MSB                      
#define MISC_IE_DST_RING_LOW_WATERMARK_MASK                     CE0_MISC_IE_DST_RING_LOW_WATERMARK_MASK                     
#define MISC_IE_DST_RING_LOW_WATERMARK_GET(x)                   CE0_MISC_IE_DST_RING_LOW_WATERMARK_GET(x)                   
#define MISC_IE_DST_RING_LOW_WATERMARK_SET(x)                   CE0_MISC_IE_DST_RING_LOW_WATERMARK_SET(x)                   
#define MISC_IE_DST_RING_LOW_WATERMARK_RESET                    CE0_MISC_IE_DST_RING_LOW_WATERMARK_RESET                    
#define MISC_IE_DST_RING_HIGH_WATERMARK_LSB                     CE0_MISC_IE_DST_RING_HIGH_WATERMARK_LSB                     
#define MISC_IE_DST_RING_HIGH_WATERMARK_MSB                     CE0_MISC_IE_DST_RING_HIGH_WATERMARK_MSB                     
#define MISC_IE_DST_RING_HIGH_WATERMARK_MASK                    CE0_MISC_IE_DST_RING_HIGH_WATERMARK_MASK                    
#define MISC_IE_DST_RING_HIGH_WATERMARK_GET(x)                  CE0_MISC_IE_DST_RING_HIGH_WATERMARK_GET(x)                  
#define MISC_IE_DST_RING_HIGH_WATERMARK_SET(x)                  CE0_MISC_IE_DST_RING_HIGH_WATERMARK_SET(x)                  
#define MISC_IE_DST_RING_HIGH_WATERMARK_RESET                   CE0_MISC_IE_DST_RING_HIGH_WATERMARK_RESET                   
#define MISC_IE_SRC_RING_LOW_WATERMARK_LSB                      CE0_MISC_IE_SRC_RING_LOW_WATERMARK_LSB                      
#define MISC_IE_SRC_RING_LOW_WATERMARK_MSB                      CE0_MISC_IE_SRC_RING_LOW_WATERMARK_MSB                      
#define MISC_IE_SRC_RING_LOW_WATERMARK_MASK                     CE0_MISC_IE_SRC_RING_LOW_WATERMARK_MASK                     
#define MISC_IE_SRC_RING_LOW_WATERMARK_GET(x)                   CE0_MISC_IE_SRC_RING_LOW_WATERMARK_GET(x)                   
#define MISC_IE_SRC_RING_LOW_WATERMARK_SET(x)                   CE0_MISC_IE_SRC_RING_LOW_WATERMARK_SET(x)                   
#define MISC_IE_SRC_RING_LOW_WATERMARK_RESET                    CE0_MISC_IE_SRC_RING_LOW_WATERMARK_RESET                    
#define MISC_IE_SRC_RING_HIGH_WATERMARK_LSB                     CE0_MISC_IE_SRC_RING_HIGH_WATERMARK_LSB                     
#define MISC_IE_SRC_RING_HIGH_WATERMARK_MSB                     CE0_MISC_IE_SRC_RING_HIGH_WATERMARK_MSB                     
#define MISC_IE_SRC_RING_HIGH_WATERMARK_MASK                    CE0_MISC_IE_SRC_RING_HIGH_WATERMARK_MASK                    
#define MISC_IE_SRC_RING_HIGH_WATERMARK_GET(x)                  CE0_MISC_IE_SRC_RING_HIGH_WATERMARK_GET(x)                  
#define MISC_IE_SRC_RING_HIGH_WATERMARK_SET(x)                  CE0_MISC_IE_SRC_RING_HIGH_WATERMARK_SET(x)                  
#define MISC_IE_SRC_RING_HIGH_WATERMARK_RESET                   CE0_MISC_IE_SRC_RING_HIGH_WATERMARK_RESET                   
#define MISC_IE_COPY_COMPLETE_LSB                               CE0_MISC_IE_COPY_COMPLETE_LSB                               
#define MISC_IE_COPY_COMPLETE_MSB                               CE0_MISC_IE_COPY_COMPLETE_MSB                               
#define MISC_IE_COPY_COMPLETE_MASK                              CE0_MISC_IE_COPY_COMPLETE_MASK                              
#define MISC_IE_COPY_COMPLETE_GET(x)                            CE0_MISC_IE_COPY_COMPLETE_GET(x)                            
#define MISC_IE_COPY_COMPLETE_SET(x)                            CE0_MISC_IE_COPY_COMPLETE_SET(x)                            
#define MISC_IE_COPY_COMPLETE_RESET                             CE0_MISC_IE_COPY_COMPLETE_RESET                             
#define MISC_IE_ADDRESS                                         CE0_MISC_IE_ADDRESS                                         
#define MISC_IE_RSTMASK                                         CE0_MISC_IE_RSTMASK                                         
#define MISC_IE_RESET                                           CE0_MISC_IE_RESET                                           
                                                                                                                                 
// 0x38 (MISC_IS)                                               (CE0_MISC_IS)
#define MISC_IS_AXI_ERR_LSB                                     CE0_MISC_IS_AXI_ERR_LSB                                     
#define MISC_IS_AXI_ERR_MSB                                     CE0_MISC_IS_AXI_ERR_MSB                                     
#define MISC_IS_AXI_ERR_MASK                                    CE0_MISC_IS_AXI_ERR_MASK                                    
#define MISC_IS_AXI_ERR_GET(x)                                  CE0_MISC_IS_AXI_ERR_GET(x)                                  
#define MISC_IS_AXI_ERR_SET(x)                                  CE0_MISC_IS_AXI_ERR_SET(x)                                  
#define MISC_IS_AXI_ERR_RESET                                   CE0_MISC_IS_AXI_ERR_RESET                                   
#define MISC_IS_DST_ADDR_ERR_LSB                                CE0_MISC_IS_DST_ADDR_ERR_LSB                                
#define MISC_IS_DST_ADDR_ERR_MSB                                CE0_MISC_IS_DST_ADDR_ERR_MSB                                
#define MISC_IS_DST_ADDR_ERR_MASK                               CE0_MISC_IS_DST_ADDR_ERR_MASK                               
#define MISC_IS_DST_ADDR_ERR_GET(x)                             CE0_MISC_IS_DST_ADDR_ERR_GET(x)                             
#define MISC_IS_DST_ADDR_ERR_SET(x)                             CE0_MISC_IS_DST_ADDR_ERR_SET(x)                             
#define MISC_IS_DST_ADDR_ERR_RESET                              CE0_MISC_IS_DST_ADDR_ERR_RESET                              
#define MISC_IS_SRC_LEN_ERR_LSB                                 CE0_MISC_IS_SRC_LEN_ERR_LSB                                 
#define MISC_IS_SRC_LEN_ERR_MSB                                 CE0_MISC_IS_SRC_LEN_ERR_MSB                                 
#define MISC_IS_SRC_LEN_ERR_MASK                                CE0_MISC_IS_SRC_LEN_ERR_MASK                                
#define MISC_IS_SRC_LEN_ERR_GET(x)                              CE0_MISC_IS_SRC_LEN_ERR_GET(x)                              
#define MISC_IS_SRC_LEN_ERR_SET(x)                              CE0_MISC_IS_SRC_LEN_ERR_SET(x)                              
#define MISC_IS_SRC_LEN_ERR_RESET                               CE0_MISC_IS_SRC_LEN_ERR_RESET                               
#define MISC_IS_DST_MAX_LEN_VIO_LSB                             CE0_MISC_IS_DST_MAX_LEN_VIO_LSB                             
#define MISC_IS_DST_MAX_LEN_VIO_MSB                             CE0_MISC_IS_DST_MAX_LEN_VIO_MSB                             
#define MISC_IS_DST_MAX_LEN_VIO_MASK                            CE0_MISC_IS_DST_MAX_LEN_VIO_MASK                            
#define MISC_IS_DST_MAX_LEN_VIO_GET(x)                          CE0_MISC_IS_DST_MAX_LEN_VIO_GET(x)                          
#define MISC_IS_DST_MAX_LEN_VIO_SET(x)                          CE0_MISC_IS_DST_MAX_LEN_VIO_SET(x)                          
#define MISC_IS_DST_MAX_LEN_VIO_RESET                           CE0_MISC_IS_DST_MAX_LEN_VIO_RESET                           
#define MISC_IS_DST_RING_OVERFLOW_LSB                           CE0_MISC_IS_DST_RING_OVERFLOW_LSB                           
#define MISC_IS_DST_RING_OVERFLOW_MSB                           CE0_MISC_IS_DST_RING_OVERFLOW_MSB                           
#define MISC_IS_DST_RING_OVERFLOW_MASK                          CE0_MISC_IS_DST_RING_OVERFLOW_MASK                          
#define MISC_IS_DST_RING_OVERFLOW_GET(x)                        CE0_MISC_IS_DST_RING_OVERFLOW_GET(x)                        
#define MISC_IS_DST_RING_OVERFLOW_SET(x)                        CE0_MISC_IS_DST_RING_OVERFLOW_SET(x)                        
#define MISC_IS_DST_RING_OVERFLOW_RESET                         CE0_MISC_IS_DST_RING_OVERFLOW_RESET                         
#define MISC_IS_SRC_RING_OVERFLOW_LSB                           CE0_MISC_IS_SRC_RING_OVERFLOW_LSB                           
#define MISC_IS_SRC_RING_OVERFLOW_MSB                           CE0_MISC_IS_SRC_RING_OVERFLOW_MSB                           
#define MISC_IS_SRC_RING_OVERFLOW_MASK                          CE0_MISC_IS_SRC_RING_OVERFLOW_MASK                          
#define MISC_IS_SRC_RING_OVERFLOW_GET(x)                        CE0_MISC_IS_SRC_RING_OVERFLOW_GET(x)                        
#define MISC_IS_SRC_RING_OVERFLOW_SET(x)                        CE0_MISC_IS_SRC_RING_OVERFLOW_SET(x)                        
#define MISC_IS_SRC_RING_OVERFLOW_RESET                         CE0_MISC_IS_SRC_RING_OVERFLOW_RESET                         
#define MISC_IS_DST_RING_LOW_WATERMARK_LSB                      CE0_MISC_IS_DST_RING_LOW_WATERMARK_LSB                      
#define MISC_IS_DST_RING_LOW_WATERMARK_MSB                      CE0_MISC_IS_DST_RING_LOW_WATERMARK_MSB                      
#define MISC_IS_DST_RING_LOW_WATERMARK_MASK                     CE0_MISC_IS_DST_RING_LOW_WATERMARK_MASK                     
#define MISC_IS_DST_RING_LOW_WATERMARK_GET(x)                   CE0_MISC_IS_DST_RING_LOW_WATERMARK_GET(x)                   
#define MISC_IS_DST_RING_LOW_WATERMARK_SET(x)                   CE0_MISC_IS_DST_RING_LOW_WATERMARK_SET(x)                   
#define MISC_IS_DST_RING_LOW_WATERMARK_RESET                    CE0_MISC_IS_DST_RING_LOW_WATERMARK_RESET                    
#define MISC_IS_DST_RING_HIGH_WATERMARK_LSB                     CE0_MISC_IS_DST_RING_HIGH_WATERMARK_LSB                     
#define MISC_IS_DST_RING_HIGH_WATERMARK_MSB                     CE0_MISC_IS_DST_RING_HIGH_WATERMARK_MSB                     
#define MISC_IS_DST_RING_HIGH_WATERMARK_MASK                    CE0_MISC_IS_DST_RING_HIGH_WATERMARK_MASK                    
#define MISC_IS_DST_RING_HIGH_WATERMARK_GET(x)                  CE0_MISC_IS_DST_RING_HIGH_WATERMARK_GET(x)                  
#define MISC_IS_DST_RING_HIGH_WATERMARK_SET(x)                  CE0_MISC_IS_DST_RING_HIGH_WATERMARK_SET(x)                  
#define MISC_IS_DST_RING_HIGH_WATERMARK_RESET                   CE0_MISC_IS_DST_RING_HIGH_WATERMARK_RESET                   
#define MISC_IS_SRC_RING_LOW_WATERMARK_LSB                      CE0_MISC_IS_SRC_RING_LOW_WATERMARK_LSB                      
#define MISC_IS_SRC_RING_LOW_WATERMARK_MSB                      CE0_MISC_IS_SRC_RING_LOW_WATERMARK_MSB                      
#define MISC_IS_SRC_RING_LOW_WATERMARK_MASK                     CE0_MISC_IS_SRC_RING_LOW_WATERMARK_MASK                     
#define MISC_IS_SRC_RING_LOW_WATERMARK_GET(x)                   CE0_MISC_IS_SRC_RING_LOW_WATERMARK_GET(x)                   
#define MISC_IS_SRC_RING_LOW_WATERMARK_SET(x)                   CE0_MISC_IS_SRC_RING_LOW_WATERMARK_SET(x)                   
#define MISC_IS_SRC_RING_LOW_WATERMARK_RESET                    CE0_MISC_IS_SRC_RING_LOW_WATERMARK_RESET                    
#define MISC_IS_SRC_RING_HIGH_WATERMARK_LSB                     CE0_MISC_IS_SRC_RING_HIGH_WATERMARK_LSB                     
#define MISC_IS_SRC_RING_HIGH_WATERMARK_MSB                     CE0_MISC_IS_SRC_RING_HIGH_WATERMARK_MSB                     
#define MISC_IS_SRC_RING_HIGH_WATERMARK_MASK                    CE0_MISC_IS_SRC_RING_HIGH_WATERMARK_MASK                    
#define MISC_IS_SRC_RING_HIGH_WATERMARK_GET(x)                  CE0_MISC_IS_SRC_RING_HIGH_WATERMARK_GET(x)                  
#define MISC_IS_SRC_RING_HIGH_WATERMARK_SET(x)                  CE0_MISC_IS_SRC_RING_HIGH_WATERMARK_SET(x)                  
#define MISC_IS_SRC_RING_HIGH_WATERMARK_RESET                   CE0_MISC_IS_SRC_RING_HIGH_WATERMARK_RESET                   
#define MISC_IS_COPY_COMPLETE_LSB                               CE0_MISC_IS_COPY_COMPLETE_LSB                               
#define MISC_IS_COPY_COMPLETE_MSB                               CE0_MISC_IS_COPY_COMPLETE_MSB                               
#define MISC_IS_COPY_COMPLETE_MASK                              CE0_MISC_IS_COPY_COMPLETE_MASK                              
#define MISC_IS_COPY_COMPLETE_GET(x)                            CE0_MISC_IS_COPY_COMPLETE_GET(x)                            
#define MISC_IS_COPY_COMPLETE_SET(x)                            CE0_MISC_IS_COPY_COMPLETE_SET(x)                            
#define MISC_IS_COPY_COMPLETE_RESET                             CE0_MISC_IS_COPY_COMPLETE_RESET                             
#define MISC_IS_ADDRESS                                         CE0_MISC_IS_ADDRESS                                         
#define MISC_IS_RSTMASK                                         CE0_MISC_IS_RSTMASK                                         
#define MISC_IS_RESET                                           CE0_MISC_IS_RESET                                           
                                                                                                                                 
// 0x3c (SR_WR_INDEX)                                           (CE0_SR_WR_INDEX)
#define SR_WR_INDEX_V_LSB                                       CE0_SR_WR_INDEX_V_LSB                                       
#define SR_WR_INDEX_V_MSB                                       CE0_SR_WR_INDEX_V_MSB                                       
#define SR_WR_INDEX_V_MASK                                      CE0_SR_WR_INDEX_V_MASK                                      
#define SR_WR_INDEX_V_GET(x)                                    CE0_SR_WR_INDEX_V_GET(x)                                    
#define SR_WR_INDEX_V_SET(x)                                    CE0_SR_WR_INDEX_V_SET(x)                                    
#define SR_WR_INDEX_V_RESET                                     CE0_SR_WR_INDEX_V_RESET                                     
#define SR_WR_INDEX_ADDRESS                                     CE0_SR_WR_INDEX_ADDRESS                                     
#define SR_WR_INDEX_RSTMASK                                     CE0_SR_WR_INDEX_RSTMASK                                     
#define SR_WR_INDEX_RESET                                       CE0_SR_WR_INDEX_RESET                                       
                                                                                                                                 
// 0x40 (DST_WR_INDEX)                                          (CE0_DST_WR_INDEX)
#define DST_WR_INDEX_V_LSB                                      CE0_DST_WR_INDEX_V_LSB                                      
#define DST_WR_INDEX_V_MSB                                      CE0_DST_WR_INDEX_V_MSB                                      
#define DST_WR_INDEX_V_MASK                                     CE0_DST_WR_INDEX_V_MASK                                     
#define DST_WR_INDEX_V_GET(x)                                   CE0_DST_WR_INDEX_V_GET(x)                                   
#define DST_WR_INDEX_V_SET(x)                                   CE0_DST_WR_INDEX_V_SET(x)                                   
#define DST_WR_INDEX_V_RESET                                    CE0_DST_WR_INDEX_V_RESET                                    
#define DST_WR_INDEX_ADDRESS                                    CE0_DST_WR_INDEX_ADDRESS                                    
#define DST_WR_INDEX_RSTMASK                                    CE0_DST_WR_INDEX_RSTMASK                                    
#define DST_WR_INDEX_RESET                                      CE0_DST_WR_INDEX_RESET                                      
                                                                                                                                 
// 0x44 (CURRENT_SRRI)                                          (CE0_CURRENT_SRRI)
#define CURRENT_SRRI_V_LSB                                      CE0_CURRENT_SRRI_V_LSB                                      
#define CURRENT_SRRI_V_MSB                                      CE0_CURRENT_SRRI_V_MSB                                      
#define CURRENT_SRRI_V_MASK                                     CE0_CURRENT_SRRI_V_MASK                                     
#define CURRENT_SRRI_V_GET(x)                                   CE0_CURRENT_SRRI_V_GET(x)                                   
#define CURRENT_SRRI_V_SET(x)                                   CE0_CURRENT_SRRI_V_SET(x)                                   
#define CURRENT_SRRI_V_RESET                                    CE0_CURRENT_SRRI_V_RESET                                    
#define CURRENT_SRRI_ADDRESS                                    CE0_CURRENT_SRRI_ADDRESS                                    
#define CURRENT_SRRI_RSTMASK                                    CE0_CURRENT_SRRI_RSTMASK                                    
#define CURRENT_SRRI_RESET                                      CE0_CURRENT_SRRI_RESET                                      
                                                                                                                                 
// 0x48 (CURRENT_DRRI)                                          (CE0_CURRENT_DRRI)
#define CURRENT_DRRI_V_LSB                                      CE0_CURRENT_DRRI_V_LSB                                      
#define CURRENT_DRRI_V_MSB                                      CE0_CURRENT_DRRI_V_MSB                                      
#define CURRENT_DRRI_V_MASK                                     CE0_CURRENT_DRRI_V_MASK                                     
#define CURRENT_DRRI_V_GET(x)                                   CE0_CURRENT_DRRI_V_GET(x)                                   
#define CURRENT_DRRI_V_SET(x)                                   CE0_CURRENT_DRRI_V_SET(x)                                   
#define CURRENT_DRRI_V_RESET                                    CE0_CURRENT_DRRI_V_RESET                                    
#define CURRENT_DRRI_ADDRESS                                    CE0_CURRENT_DRRI_ADDRESS                                    
#define CURRENT_DRRI_RSTMASK                                    CE0_CURRENT_DRRI_RSTMASK                                    
#define CURRENT_DRRI_RESET                                      CE0_CURRENT_DRRI_RESET                                      
                                                                                                                                 
// 0x4c (SRC_WATERMARK)                                         (CE0_SRC_WATERMARK)
#define SRC_WATERMARK_LOW_LSB                                   CE0_SRC_WATERMARK_LOW_LSB                                   
#define SRC_WATERMARK_LOW_MSB                                   CE0_SRC_WATERMARK_LOW_MSB                                   
#define SRC_WATERMARK_LOW_MASK                                  CE0_SRC_WATERMARK_LOW_MASK                                  
#define SRC_WATERMARK_LOW_GET(x)                                CE0_SRC_WATERMARK_LOW_GET(x)                                
#define SRC_WATERMARK_LOW_SET(x)                                CE0_SRC_WATERMARK_LOW_SET(x)                                
#define SRC_WATERMARK_LOW_RESET                                 CE0_SRC_WATERMARK_LOW_RESET                                 
#define SRC_WATERMARK_HIGH_LSB                                  CE0_SRC_WATERMARK_HIGH_LSB                                  
#define SRC_WATERMARK_HIGH_MSB                                  CE0_SRC_WATERMARK_HIGH_MSB                                  
#define SRC_WATERMARK_HIGH_MASK                                 CE0_SRC_WATERMARK_HIGH_MASK                                 
#define SRC_WATERMARK_HIGH_GET(x)                               CE0_SRC_WATERMARK_HIGH_GET(x)                               
#define SRC_WATERMARK_HIGH_SET(x)                               CE0_SRC_WATERMARK_HIGH_SET(x)                               
#define SRC_WATERMARK_HIGH_RESET                                CE0_SRC_WATERMARK_HIGH_RESET                                
#define SRC_WATERMARK_ADDRESS                                   CE0_SRC_WATERMARK_ADDRESS                                   
#define SRC_WATERMARK_RSTMASK                                   CE0_SRC_WATERMARK_RSTMASK                                   
#define SRC_WATERMARK_RESET                                     CE0_SRC_WATERMARK_RESET                                     
                                                                                                                                 
// 0x50 (DST_WATERMARK)                                         (CE0_DST_WATERMARK)
#define DST_WATERMARK_LOW_LSB                                   CE0_DST_WATERMARK_LOW_LSB                                   
#define DST_WATERMARK_LOW_MSB                                   CE0_DST_WATERMARK_LOW_MSB                                   
#define DST_WATERMARK_LOW_MASK                                  CE0_DST_WATERMARK_LOW_MASK                                  
#define DST_WATERMARK_LOW_GET(x)                                CE0_DST_WATERMARK_LOW_GET(x)                                
#define DST_WATERMARK_LOW_SET(x)                                CE0_DST_WATERMARK_LOW_SET(x)                                
#define DST_WATERMARK_LOW_RESET                                 CE0_DST_WATERMARK_LOW_RESET                                 
#define DST_WATERMARK_HIGH_LSB                                  CE0_DST_WATERMARK_HIGH_LSB                                  
#define DST_WATERMARK_HIGH_MSB                                  CE0_DST_WATERMARK_HIGH_MSB                                  
#define DST_WATERMARK_HIGH_MASK                                 CE0_DST_WATERMARK_HIGH_MASK                                 
#define DST_WATERMARK_HIGH_GET(x)                               CE0_DST_WATERMARK_HIGH_GET(x)                               
#define DST_WATERMARK_HIGH_SET(x)                               CE0_DST_WATERMARK_HIGH_SET(x)                               
#define DST_WATERMARK_HIGH_RESET                                CE0_DST_WATERMARK_HIGH_RESET                                
#define DST_WATERMARK_ADDRESS                                   CE0_DST_WATERMARK_ADDRESS                                   
#define DST_WATERMARK_RSTMASK                                   CE0_DST_WATERMARK_RSTMASK                                   
#define DST_WATERMARK_RESET                                     CE0_DST_WATERMARK_RESET                                     
                                                                                                                                 
// 0x54 (CE_DEBUG)                                              (CE0_CE_DEBUG)
#define CE_DEBUG_SEL_LSB                                        CE0_CE_DEBUG_SEL_LSB                                        
#define CE_DEBUG_SEL_MSB                                        CE0_CE_DEBUG_SEL_MSB                                        
#define CE_DEBUG_SEL_MASK                                       CE0_CE_DEBUG_SEL_MASK                                       
#define CE_DEBUG_SEL_GET(x)                                     CE0_CE_DEBUG_SEL_GET(x)                                     
#define CE_DEBUG_SEL_SET(x)                                     CE0_CE_DEBUG_SEL_SET(x)                                     
#define CE_DEBUG_SEL_RESET                                      CE0_CE_DEBUG_SEL_RESET                                      
#define CE_DEBUG_ADDRESS                                        CE0_CE_DEBUG_ADDRESS                                        
#define CE_DEBUG_RSTMASK                                        CE0_CE_DEBUG_RSTMASK                                        
#define CE_DEBUG_RESET                                          CE0_CE_DEBUG_RESET                                          
                                                                                                                                 
// 0x58 (CE_WATCHDOG)                                           (CE0_CE_WATCHDOG)
#define CE_WATCHDOG_STATUS_LSB                                  CE0_CE_WATCHDOG_STATUS_LSB                                  
#define CE_WATCHDOG_STATUS_MSB                                  CE0_CE_WATCHDOG_STATUS_MSB                                  
#define CE_WATCHDOG_STATUS_MASK                                 CE0_CE_WATCHDOG_STATUS_MASK                                 
#define CE_WATCHDOG_STATUS_GET(x)                               CE0_CE_WATCHDOG_STATUS_GET(x)                               
#define CE_WATCHDOG_STATUS_SET(x)                               CE0_CE_WATCHDOG_STATUS_SET(x)                               
#define CE_WATCHDOG_STATUS_RESET                                CE0_CE_WATCHDOG_STATUS_RESET                                
#define CE_WATCHDOG_LIMIT_LSB                                   CE0_CE_WATCHDOG_LIMIT_LSB                                   
#define CE_WATCHDOG_LIMIT_MSB                                   CE0_CE_WATCHDOG_LIMIT_MSB                                   
#define CE_WATCHDOG_LIMIT_MASK                                  CE0_CE_WATCHDOG_LIMIT_MASK                                  
#define CE_WATCHDOG_LIMIT_GET(x)                                CE0_CE_WATCHDOG_LIMIT_GET(x)                                
#define CE_WATCHDOG_LIMIT_SET(x)                                CE0_CE_WATCHDOG_LIMIT_SET(x)                                
#define CE_WATCHDOG_LIMIT_RESET                                 CE0_CE_WATCHDOG_LIMIT_RESET                                 
#define CE_WATCHDOG_ADDRESS                                     CE0_CE_WATCHDOG_ADDRESS                                     
#define CE_WATCHDOG_RSTMASK                                     CE0_CE_WATCHDOG_RSTMASK                                     
#define CE_WATCHDOG_RESET                                       CE0_CE_WATCHDOG_RESET                                       
                                                                    
#endif
