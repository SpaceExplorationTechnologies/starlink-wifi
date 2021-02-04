#ifndef __OTA_CAL_PWR_H__
#define __OTA_CAL_PWR_H__

#ifdef _CAL_PWR_AS_API
#define COM_PORT_BUF_SIZE 4096
#define PWR_READ_BUF_SIZE 4096
#define RATE_STR_LEN      30

typedef const char RATE_STR[RATE_STR_LEN];

typedef enum {
    EN_PWR_WAIT_BURST = 0,
    EN_PWR_READ_NORMAL,
    EN_PWR_READ_PAUSE
} PWR_READ_STATE;

typedef enum {
    EN_THERMAL_CAL_IDLE = 0,
    EN_THERMAL_CAL_T,
    EN_THERMAL_CAL_H,
    EN_THERMAL_CAL_E,
    EN_THERMAL_CAL_R,
    EN_THERMAL_CAL_M,
    EN_THERMAL_CAL_C,
    EN_THERMAL_CAL_A,
    EN_THERMAL_CAL_L,
    EN_THERMAL_CAL_VAL
} COM_CHAR_STATE;

typedef struct {
    int      fd;
    int      stop_wait;
    A_UINT8  ucThermVal[COM_PORT_BUF_SIZE];
    A_UINT32 ulThermValPos;
} COM_THREAD_BUFF;

typedef struct {
    double dPwrValue[PWR_READ_BUF_SIZE];
    A_UINT32 ucPwrValPos;
} PWR_READ_BUFF;

extern int calFlowMeasure(void);
extern int writeCalDataWithThermToFile(void);
extern void setupForCalibrate(void);
extern void setupForVerify(void);
extern void setupForPwrMeter(void);
void logThermValue(A_UINT8 thermVal);
void pthread_read_serial(void* p);
void vReadPwrProc(double pwrInput, PWR_READ_BUFF* pBufPwr);
A_BOOL readOneTxPower(A_INT32 *txPwr_t10, A_UINT32 channel, PWR_READ_BUFF* pBufPwr);
#endif

#endif
