#ifndef _EFUSE_REG_REG_SW_H_
#define _EFUSE_REG_REG_SW_H_

#define WIFI_CORE_ID_WIFI0 0x0
#define WIFI_CORE_ID_WIFI1 0x1

/* IPQ4019 does not have OTP at WiFi level, there is a common OTP for entire SoC */
#define EFUSE_BASE_ADDRESS 0x58000
#define EFUSE_INTF_ADDRESS (EFUSE_BASE_ADDRESS | 0x80000000)

#define EFUSE_WIFI0_FEATURE_CTRL_ROWn_ADDR(n)                                 (EFUSE_BASE_ADDRESS  + 0x200 + (0x8 * (n)))
#define EFUSE_INTF_WIFI0_FEATURE_CTRL_ROWn_ADDR(n) (EFUSE_WIFI0_FEATURE_CTRL_ROWn_ADDR(n) | EFUSE_INTF_ADDRESS)

#define EFUSE_WIFI1_FEATURE_CTRL_ROWn_ADDR(n)                                 (EFUSE_BASE_ADDRESS  + 0x300 + (0x8 * (n)))
#define EFUSE_INTF_WIFI1_FEATURE_CTRL_ROWn_ADDR(n) (EFUSE_WIFI1_FEATURE_CTRL_ROWn_ADDR(n) | EFUSE_INTF_ADDRESS)

#define EFUSE_WIFI0_CALIB_ROWn_ADDR(n)                                 (EFUSE_BASE_ADDRESS  + 0x218 + (0x8 * (n)))
#define EFUSE_INTF_WIFI0_CALIB_ROWn_ADDR(n) (EFUSE_WIFI0_CALIB_ROWn_ADDR(n) | EFUSE_INTF_ADDRESS)

#define EFUSE_WIFI1_CALIB_ROWn_ADDR(n)                                 (EFUSE_BASE_ADDRESS  + 0x318 + (0x8 * (n)))
#define EFUSE_INTF_WIFI1_CALIB_ROWn_ADDR(n) (EFUSE_WIFI1_CALIB_ROWn_ADDR(n) | EFUSE_INTF_ADDRESS)

#define HWIO_QFPROM_BLOW_TIMER_ADDR     (EFUSE_INTF_ADDRESS | 0x203C)
#define HWIO_QFPROM_PPI_TIMER_ADDR      (EFUSE_INTF_ADDRESS | 0x2058)

#define HWIO_QFPROM_RAW_RD_WR_PERM_LSB_WIFI0_FEATURE_BMSK                                       0x100000
#define HWIO_QFPROM_RAW_RD_WR_PERM_LSB_WIFI0_FEATURE_SHFT                                           0x14
#define HWIO_QFPROM_RAW_RD_WR_PERM_LSB_WIFI0_CALIBRATION_BMSK                                   0x200000
#define HWIO_QFPROM_RAW_RD_WR_PERM_LSB_WIFI0_CALIBRATION_SHFT                                       0x15
#define HWIO_QFPROM_RAW_RD_WR_PERM_LSB_WIFI1_FEATURE_BMSK                                       0x800000
#define HWIO_QFPROM_RAW_RD_WR_PERM_LSB_WIFI1_FEATURE_SHFT                                           0x17
#define HWIO_QFPROM_RAW_RD_WR_PERM_LSB_WIFI1_CALIBRATION_BMSK                                  0x1000000
#define HWIO_QFPROM_RAW_RD_WR_PERM_LSB_WIFI1_CALIBRATION_SHFT                                       0x18
#define HWIO_QFPROM_RAW_RD_WR_PERM_LSB_ADDR                                  (EFUSE_INTF_ADDRESS | 0x10)

#define HWIO_QFPROM_RAW_RD_WR_PERM_MSB_WIFI0_FEATURE_BMSK                                       0x100000
#define HWIO_QFPROM_RAW_RD_WR_PERM_MSB_WIFI0_FEATURE_SHFT                                           0x14
#define HWIO_QFPROM_RAW_RD_WR_PERM_MSB_WIFI0_CALIBRATION_BMSK                                   0x200000
#define HWIO_QFPROM_RAW_RD_WR_PERM_MSB_WIFI0_CALIBRATION_SHFT                                       0x15
#define HWIO_QFPROM_RAW_RD_WR_PERM_MSB_WIFI1_FEATURE_BMSK                                       0x800000
#define HWIO_QFPROM_RAW_RD_WR_PERM_MSB_WIFI1_FEATURE_SHFT                                           0x17
#define HWIO_QFPROM_RAW_RD_WR_PERM_MSB_WIFI1_CALIBRATION_BMSK                                  0x1000000
#define HWIO_QFPROM_RAW_RD_WR_PERM_MSB_WIFI1_CALIBRATION_SHFT                                       0x18
#define HWIO_QFPROM_RAW_RD_WR_PERM_MSB_ADDR                                  (EFUSE_INTF_ADDRESS | 0x14)

#endif
