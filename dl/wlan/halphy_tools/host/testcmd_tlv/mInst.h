#if !defined(__MINST_H) 
#define __MINST_H

#define NRP_Z11                         0x04

/* functions exported */
double pmMeasAvgPower(const int ud, const int reset); 
void psClose(void);
int pmInit(const int ud, const int model); 

/*
 * usage: 
 *    A_INT32 devPM = pmInit(addr, model);  // addr no used in USB PM
 *    double power = pmMeasAvgPower(devPM, 0) ;
 *    psClose();
 *
 */

#endif //#if !defined(__MINST_H) 

