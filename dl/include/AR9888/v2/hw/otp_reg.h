#ifndef _OTP_REG_REG_H_
#define _OTP_REG_REG_H_

#define OTP_BITMAP_ADDRESS                       0x00000000
#define OTP_BITMAP_OFFSET                        0x00000000
#define OTP_BITMAP_V_MSB                         31
#define OTP_BITMAP_V_LSB                         0
#define OTP_BITMAP_V_MASK                        0xffffffff
#define OTP_BITMAP_V_GET(x)                      (((x) & OTP_BITMAP_V_MASK) >> OTP_BITMAP_V_LSB)
#define OTP_BITMAP_V_SET(x)                      (((x) << OTP_BITMAP_V_LSB) & OTP_BITMAP_V_MASK)

#define TRS_CSRST_REG_ADDRESS                    0x00000004
#define TRS_CSRST_REG_OFFSET                     0x00000004
#define TRS_CSRST_REG_V_MSB                      31
#define TRS_CSRST_REG_V_LSB                      0
#define TRS_CSRST_REG_V_MASK                     0xffffffff
#define TRS_CSRST_REG_V_GET(x)                   (((x) & TRS_CSRST_REG_V_MASK) >> TRS_CSRST_REG_V_LSB)
#define TRS_CSRST_REG_V_SET(x)                   (((x) << TRS_CSRST_REG_V_LSB) & TRS_CSRST_REG_V_MASK)

#define TPW_REG_ADDRESS                          0x00000008
#define TPW_REG_OFFSET                           0x00000008
#define TPW_REG_V_MSB                            31
#define TPW_REG_V_LSB                            0
#define TPW_REG_V_MASK                           0xffffffff
#define TPW_REG_V_GET(x)                         (((x) & TPW_REG_V_MASK) >> TPW_REG_V_LSB)
#define TPW_REG_V_SET(x)                         (((x) << TPW_REG_V_LSB) & TPW_REG_V_MASK)

#define TPES_REG_ADDRESS                         0x0000000c
#define TPES_REG_OFFSET                          0x0000000c
#define TPES_REG_V_MSB                           31
#define TPES_REG_V_LSB                           0
#define TPES_REG_V_MASK                          0xffffffff
#define TPES_REG_V_GET(x)                        (((x) & TPES_REG_V_MASK) >> TPES_REG_V_LSB)
#define TPES_REG_V_SET(x)                        (((x) << TPES_REG_V_LSB) & TPES_REG_V_MASK)

#define TCPS_REG_ADDRESS                         0x00000010
#define TCPS_REG_OFFSET                          0x00000010
#define TCPS_REG_V_MSB                           31
#define TCPS_REG_V_LSB                           0
#define TCPS_REG_V_MASK                          0xffffffff
#define TCPS_REG_V_GET(x)                        (((x) & TCPS_REG_V_MASK) >> TCPS_REG_V_LSB)
#define TCPS_REG_V_SET(x)                        (((x) << TCPS_REG_V_LSB) & TCPS_REG_V_MASK)

#define TCPH_REG_ADDRESS                         0x00000014
#define TCPH_REG_OFFSET                          0x00000014
#define TCPH_REG_V_MSB                           31
#define TCPH_REG_V_LSB                           0
#define TCPH_REG_V_MASK                          0xffffffff
#define TCPH_REG_V_GET(x)                        (((x) & TCPH_REG_V_MASK) >> TCPH_REG_V_LSB)
#define TCPH_REG_V_SET(x)                        (((x) << TCPH_REG_V_LSB) & TCPH_REG_V_MASK)

#define TPEH_REG_ADDRESS                         0x00000018
#define TPEH_REG_OFFSET                          0x00000018
#define TPEH_REG_V_MSB                           31
#define TPEH_REG_V_LSB                           0
#define TPEH_REG_V_MASK                          0xffffffff
#define TPEH_REG_V_GET(x)                        (((x) & TPEH_REG_V_MASK) >> TPEH_REG_V_LSB)
#define TPEH_REG_V_SET(x)                        (((x) << TPEH_REG_V_LSB) & TPEH_REG_V_MASK)

#define TPGSV_REG_ADDRESS                        0x0000001c
#define TPGSV_REG_OFFSET                         0x0000001c
#define TPGSV_REG_V_MSB                          31
#define TPGSV_REG_V_LSB                          0
#define TPGSV_REG_V_MASK                         0xffffffff
#define TPGSV_REG_V_GET(x)                       (((x) & TPGSV_REG_V_MASK) >> TPGSV_REG_V_LSB)
#define TPGSV_REG_V_SET(x)                       (((x) << TPGSV_REG_V_LSB) & TPGSV_REG_V_MASK)

#define TPVSR_REG_ADDRESS                        0x00000020
#define TPVSR_REG_OFFSET                         0x00000020
#define TPVSR_REG_V_MSB                          31
#define TPVSR_REG_V_LSB                          0
#define TPVSR_REG_V_MASK                         0xffffffff
#define TPVSR_REG_V_GET(x)                       (((x) & TPVSR_REG_V_MASK) >> TPVSR_REG_V_LSB)
#define TPVSR_REG_V_SET(x)                       (((x) << TPVSR_REG_V_LSB) & TPVSR_REG_V_MASK)

#define TRWH_REG_ADDRESS                         0x00000024
#define TRWH_REG_OFFSET                          0x00000024
#define TRWH_REG_V_MSB                           31
#define TRWH_REG_V_LSB                           0
#define TRWH_REG_V_MASK                          0xffffffff
#define TRWH_REG_V_GET(x)                        (((x) & TRWH_REG_V_MASK) >> TRWH_REG_V_LSB)
#define TRWH_REG_V_SET(x)                        (((x) << TRWH_REG_V_LSB) & TRWH_REG_V_MASK)

#define TPVHR_REG_ADDRESS                        0x00000028
#define TPVHR_REG_OFFSET                         0x00000028
#define TPVHR_REG_V_MSB                          31
#define TPVHR_REG_V_LSB                          0
#define TPVHR_REG_V_MASK                         0xffffffff
#define TPVHR_REG_V_GET(x)                       (((x) & TPVHR_REG_V_MASK) >> TPVHR_REG_V_LSB)
#define TPVHR_REG_V_SET(x)                       (((x) << TPVHR_REG_V_LSB) & TPVHR_REG_V_MASK)

#define TPVSA_REG_ADDRESS                        0x0000002c
#define TPVSA_REG_OFFSET                         0x0000002c
#define TPVSA_REG_V_MSB                          31
#define TPVSA_REG_V_LSB                          0
#define TPVSA_REG_V_MASK                         0xffffffff
#define TPVSA_REG_V_GET(x)                       (((x) & TPVSA_REG_V_MASK) >> TPVSA_REG_V_LSB)
#define TPVSA_REG_V_SET(x)                       (((x) << TPVSA_REG_V_LSB) & TPVSA_REG_V_MASK)

#define TACC_REG_ADDRESS                         0x00000030
#define TACC_REG_OFFSET                          0x00000030
#define TACC_REG_V_MSB                           31
#define TACC_REG_V_LSB                           0
#define TACC_REG_V_MASK                          0xffffffff
#define TACC_REG_V_GET(x)                        (((x) & TACC_REG_V_MASK) >> TACC_REG_V_LSB)
#define TACC_REG_V_SET(x)                        (((x) << TACC_REG_V_LSB) & TACC_REG_V_MASK)

#define OTP_BITMAP_RD_ADDRESS                    0x00000034
#define OTP_BITMAP_RD_OFFSET                     0x00000034
#define OTP_BITMAP_RD_V_MSB                      31
#define OTP_BITMAP_RD_V_LSB                      0
#define OTP_BITMAP_RD_V_MASK                     0xffffffff
#define OTP_BITMAP_RD_V_GET(x)                   (((x) & OTP_BITMAP_RD_V_MASK) >> OTP_BITMAP_RD_V_LSB)
#define OTP_BITMAP_RD_V_SET(x)                   (((x) << OTP_BITMAP_RD_V_LSB) & OTP_BITMAP_RD_V_MASK)

#define OTP_INTF_ADDRESS                         0x00000200
#define OTP_INTF_OFFSET                          0x00000200
#define OTP_INTF_R_MSB                           31
#define OTP_INTF_R_LSB                           0
#define OTP_INTF_R_MASK                          0xffffffff
#define OTP_INTF_R_GET(x)                        (((x) & OTP_INTF_R_MASK) >> OTP_INTF_R_LSB)
#define OTP_INTF_R_SET(x)                        (((x) << OTP_INTF_R_LSB) & OTP_INTF_R_MASK)

#ifndef __ASSEMBLER__
typedef struct otp_reg_reg_s {
  volatile unsigned int otp_bitmap;
  volatile unsigned int trs_csrst_reg;
  volatile unsigned int tpw_reg;
  volatile unsigned int tpes_reg;
  volatile unsigned int tcps_reg;
  volatile unsigned int tcph_reg;
  volatile unsigned int tpeh_reg;
  volatile unsigned int tpgsv_reg;
  volatile unsigned int tpvsr_reg;
  volatile unsigned int trwh_reg;
  volatile unsigned int tpvhr_reg;
  volatile unsigned int tpvsa_reg;
  volatile unsigned int tacc_reg;
  volatile unsigned int otp_bitmap_rd;
  unsigned char pad0[456]; /* pad to 0x200 */
  volatile unsigned int otp_intf[128];
} otp_reg_reg_t;
#endif /* __ASSEMBLER__ */

#endif /* _OTP_REG_H_ */
