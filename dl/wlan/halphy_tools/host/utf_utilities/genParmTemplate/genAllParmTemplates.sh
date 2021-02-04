#! /bin/bash

if [ -z "$WORKAREA" ]
then
        echo "Please set your WORKAREA environment variable."
        exit -1
fi

DATE=`date +%Y%m%d`
mv -f .output .output_bkup_${DATE}
mkdir -p .output

./Linux/genParmTemplate.out ${WORKAREA}/include/systemtools/common/cmdTxParms.h
./Linux/genParmTemplate.out ${WORKAREA}/include/systemtools/common/cmdRxParms.h
./Linux/genParmTemplate.out ${WORKAREA}/include/systemtools/common/cmdCalParms.h
./Linux/genParmTemplate.out ${WORKAREA}/include/systemtools/common/cmdCalDoneParms.h
./Linux/genParmTemplate.out ${WORKAREA}/include/systemtools/common/rspGenericParms.h
./Linux/genParmTemplate.out ${WORKAREA}/include/systemtools/common/submitReportParms.h
./Linux/genParmTemplate.out ${WORKAREA}/include/systemtools/common/cmdPmParms.h
./Linux/genParmTemplate.out ${WORKAREA}/include/systemtools/common/cmdSetRegParms.h
