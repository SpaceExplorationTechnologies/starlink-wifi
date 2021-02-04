#ifndef __OL_ATH_H__
#define __OL_ATH_H__

#define BUS_TYPE_SIM   0x1 /* simulator */
#define BUS_TYPE_PCIE  0x2 /* pcie */
#define BUS_TYPE_SDIO  0x3 /* sdio */

struct ol_attach_t {
    u_int16_t devid;
    u_int16_t bus_type;
};

/* Temp defines */
#define AR6004_REV1_VERSION                 0x30000623
#define AR6004_REV1_FIRMWARE_FILE           "athwlan.bin"
#define AR6004_REV1_UTF_FIRMWARE_FILE       "utf.bin"
#define AR6004_REV1_BOARD_DATA_FILE         "fakeBoardData_AR6004.bin"
#define AR6004_REV1_EPPING_FIRMWARE_FILE    "endpointping.bin"
#define AR6004_REV1_OTP_FILE                 "otp.bin"
#define AR6004_VERSION_REV1_3               0x31c8088a
#define AR6004_REV1_3_FIRMWARE_FILE         L"ar6004v1_1fw.bin"
#define AR6004_REV1_3_BOARD_DATA_FILE       L"FakeBoardData.bin"

/* AR9888 Revision 1 */
#define AR9888_REV1_VERSION                 0x4000002c /* Build#44 */
#define AR9888_REV1_FIRMWARE_FILE           "athwlan.bin"
#define AR9888_REV1_UTF_FIRMWARE_FILE       "utf.bin"
#define AR9888_REV1_BOARD_DATA_FILE         "fakeBoardData_AR6004.bin"
#define AR9888_REV1_OTP_FILE                 "otp.bin"

/* AR9888 Revision 2 */
#define AR9888_REV2_VERSION                 0x4100016c /* __VER_MINOR_ 1, __BUILD_NUMBER_ 364 */
#define AR9888_REV2_FIRMWARE_FILE           "athwlan.bin"
#define AR9888_REV2_UTF_FIRMWARE_FILE       "utf.bin"
#define AR9888_REV2_BOARD_DATA_FILE         "fakeBoardData_AR6004.bin"
#define AR9888_REV2_OTP_FILE                 "otp.bin"

/* AR9888 Developer version */
#define AR9888_DEV_VERSION                  0x4100270f /* __VER_MINOR_ 1, __BUILD_NUMBER_ 9999 */
#define AR9888_DEV_FIRMWARE_FILE            "athwlan.bin"
#define AR9888_DEV_UTF_FIRMWARE_FILE        "utf.bin"
#define AR9888_DEV_BOARD_DATA_FILE          "fakeBoardData_AR6004.bin"
#define AR9888_DEV_OTP_FILE                 "otp.bin"

#define AR6320_REV1_VERSION                 0x4000280F
#define AR6320_REV1_FIRMWARE_FILE           "athwlan.bin"
#define AR6320_REV1_UTF_FIRMWARE_FILE       "utf.bin"
#define AR6320_REV1_BOARD_DATA_FILE         "fakeBoardData_AR6004.bin"

#define AR900B_DEV_VERSION                  0x1000000

/* ARXXXX: all developing chips which are valid but won't match others above */
#define ARXXXX_DEV_FIRMWARE_FILE            "athwlan.bin"
#define ARXXXX_DEV_UTF_FIRMWARE_FILE        "utf.bin"
#define ARXXXX_DEV_BOARD_DATA_FILE          "fakeBoardData_AR6004.bin"
#define ARXXXX_DEV_OTP_FILE                 "otp.bin"

/* Configuration for statistics pushed by firmware */
#define PDEV_DEFAULT_STATS_UPDATE_PERIOD    500
#define VDEV_DEFAULT_STATS_UPDATE_PERIOD    500
#define PEER_DEFAULT_STATS_UPDATE_PERIOD    500

/* Platform specific configuration for max. no. of fragments */
#define QCA_OL_11AC_TX_MAX_FRAGS            2

int __ol_ath_attach(hif_softc_t hif_sc, struct ol_attach_t *cfg, osdev_t osdev, struct net_device **pdev);
void __ol_ath_suspend_resume_attach(struct net_device *dev);
int __ol_ath_detach(struct net_device *dev);
int __ol_vap_destroy(struct net_device *dev);
int __ol_ath_suspend(struct net_device *dev);
int __ol_ath_resume(struct net_device *dev);
void __ol_ath_target_status_update(struct net_device *dev, ol_target_status status);

#ifdef HIF_PCI
#if !defined(A_SIMOS_DEVHOST)
#define CONFIG_ATH_SYSFS_DIAG_SUPPORT /* include user-level diagnostic support? */
#endif

int ol_ath_pci_configure(hif_softc_t hif_sc, struct net_device *dev, hif_handle_t *hif_hdl);
void ol_ath_pci_nointrs(struct net_device *dev);
#elif defined(HIF_SDIO)
#if !defined(A_SIMOS_DEVHOST)
#define CONFIG_ATH_SYSFS_DIAG_SUPPORT /* include user-level diagnostic support? */
#endif
int ol_ath_sdio_configure(hif_softc_t hif_sc, struct net_device *dev, hif_handle_t *hif_hdl);
#endif
#endif /* __OL_ATH_H__ */

