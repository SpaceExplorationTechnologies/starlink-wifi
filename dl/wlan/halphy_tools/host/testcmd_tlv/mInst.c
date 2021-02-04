#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <errno.h>
#include <stdarg.h>
#include <ctype.h>
#include "wlantype.h"
//#include "athreg.h"
#include "addnl_inst/nrp_z11.h"
#include "mInst.h"

// Globals

// device numbers
int          spa, pm, att, ps;

ViSession lSession  = 0xFFFFFFFF;

// model numbers
int          pm_model;


void psClose() {
    if(lSession != 0xFFFFFFFF){
        printf("to close the Nrp-Z11's handle\n");
        nrp_close( lSession );
    }
}

int pmInit(const int ud, const int model) {
    if (model == NRP_Z11) {
        pm_model = model;
        lSession = nrp_open();
        if ( lSession == 0xFFFFFFFF ){
            printf( "Error in nrp_open()\n" );
            return -1;
        }
    } 
    return 0;
}

double pmMeasAvgPower(const int ud, const int reset) 
{
    double retval = -120.0;	
    //unsigned int avg_count = 20;
    //int central_freq = 2412;  //dont need to care for the channel, the power sensor could take care of it

    switch (pm_model) {
        case NRP_Z11 :
	    //printf("Average Mode ------>\n");
            //retval = nrp_get(lSession, avg_count, central_freq, 1 );
	    //printf("Burst Mode -------->\n");
            //retval = nrp_get_burst( lSession, central_freq, 1 );
            retval = ContBurstMode( lSession );
            //printf("retval = %e\n", retval);
            return retval;

        default:
            return -120.;
    }

}


