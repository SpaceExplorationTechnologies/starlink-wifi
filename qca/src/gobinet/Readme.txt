Gobi Extensible API 2013-07-31-1347

This readme covers important information concerning 
the Gobi Extensible API.

Table of Contents

1. What's new in this release
2. Known issues
3. Build steps

-------------------------------------------------------------------------------

1. WHAT'S NEW

This Release (Gobi Extensible API 2013-07-31-1347)
a. Updated API reflect the following QMI ICDs:
     AUTH     ICD Rev. C  (80-VB816-21)
     CAT      ICD Rev. P  (80-VB816-11)
     DMS      ICD Rev. R  (80-VB816-4)
     LOC      ICD Rev. K  (80-VB816-17)
     NAS      ICD Rev. YL (80-VB816-6)
     PBM      ICD Rev. M  (80-VB816-15)
     PDC      ICD Rev. B  (80-VB816-38)
     PDS      ICD Rev. W  (80-VB816-8)
     QCMAP    ICD Rev. B  (80-VB816-34)
     RFRPE    ICD Rev. A  (80-VB816-44)
     UIM      ICD Rev. YC (80-VB816-12)
     Voice    ICD Rev. U  (80-VB816-10)
     WDA      ICD Rev. F  (80-VB816-26)
     WDS      ICD Rev. YJ (80-VB816-5)
     WMS      ICD Rev. N  (80-VB816-9)
     Addendum ICD Rev. E  (80-VK268-3)

Prior Release (Gobi Extensible API 2013-03-16-0832)
a. Fix QMI LOC support
b. Updated API reflect the following QMI ICDs:
     AUTH     ICD Rev. C  (80-VB816-21)
     CAT      ICD Rev. P  (80-VB816-11)
     DMS      ICD Rev. R  (80-VB816-4)
     LOC      ICD Rev. H  (80-VB816-17)
     NAS      ICD Rev. YH (80-VB816-6)
     PBM      ICD Rev. K  (80-VB816-15)
     PDC      ICD Rev. B  (80-VB816-38)
     PDS      ICD Rev. T  (80-VB816-8)
     QCMAP    ICD Rev. B  (80-VB816-34)
     UIM      ICD Rev. YB (80-VB816-12)
     Voice    ICD Rev. T  (80-VB816-10)
     WDA      ICD Rev. F  (80-VB816-26)
     WDS      ICD Rev. YG (80-VB816-5)
     WMS      ICD Rev. M  (80-VB816-9)
     Addendum ICD Rev. E  (80-VK268-3) 

Prior Release (Gobi Extensible API 2012-09-12-0719)
a. Updated API reflect the following QMI ICDs:
     AUTH     ICD Rev. C  (80-VB816-21)
     CAT      ICD Rev. L  (80-VB816-11)
     DMS      ICD Rev. N  (80-VB816-4)
     LOC      ICD Rev. G  (80-VB816-17)
     NAS      ICD Rev. YC (80-VB816-6)
     PBM      ICD Rev. K  (80-VB816-15)
     PDC      ICD Rev. A  (80-VB816-38)
     PDS      ICD Rev. N  (80-VB816-8)
     UIM      ICD Rev. Y  (80-VB816-12)
     Voice    ICD Rev. M  (80-VB816-10)
     WDS      ICD Rev. YC (80-VB816-5)
     WMS      ICD Rev. K  (80-VB816-9)
     Addendum ICD Rev. C  (80-VK268-3) 

Prior Release (Gobi Extensible API 2012-08-23-0740)
a. Updated reference platform to Nexus 7 tablet, kernel 3.1.10
b. Updated icons in GobiSampleCM
c. Updated API reflect the following QMI ICDs:
     AUTH     ICD Rev. C  (80-VB816-21)
     CAT      ICD Rev. L  (80-VB816-11)
     DMS      ICD Rev. N  (80-VB816-4)
     LOC      ICD Rev. F  (80-VB816-17)
     NAS      ICD Rev. YC (80-VB816-6)
     PBM      ICD Rev. J  (80-VB816-15)
     PDC      ICD Rev. A  (80-VB816-38)
     PDS      ICD Rev. N  (80-VB816-8)
     UIM      ICD Rev. Y  (80-VB816-12)
     Voice    ICD Rev. M  (80-VB816-10)
     WDS      ICD Rev. YB (80-VB816-5)
     WMS      ICD Rev. K  (80-VB816-9)
     Addendum ICD Rev. C  (80-VK268-3) 

Prior Release (Gobi Extensible API 2012-08-08-1042)
a. Updated API reflect the following QMI ICDs:
     AUTH     ICD Rev. C  (80-VB816-21)
     CAT      ICD Rev. L  (80-VB816-11)
     DMS      ICD Rev. N  (80-VB816-4)
     LOC      ICD Rev. F  (80-VB816-17)
     NAS      ICD Rev. YC (80-VB816-6)
     PBM      ICD Rev. J  (80-VB816-15)
     PDS      ICD Rev. N  (80-VB816-8)
     UIM      ICD Rev. Y  (80-VB816-12)
     Voice    ICD Rev. M  (80-VB816-10)
     WDS      ICD Rev. YB (80-VB816-5)
     WMS      ICD Rev. K  (80-VB816-9)
     Addendum ICD Rev. C  (80-VK268-3)     

Prior Release (Gobi Extensible API 2012-07-12-1036)
a. Cleanup correctly during Disconnect() to fix possible race condition
   which could cause future connections to have read timeouts.
b. Add a device access qualifier for SMD connections, for example: 
   "QMUXD:0" for the first SMD channel.
c. Updated API reflect the following QMI ICDs:
     AUTH     ICD Rev. C  (80-VB816-21)
     CAT      ICD Rev. L  (80-VB816-11)
     DMS      ICD Rev. N  (80-VB816-4)
     LOC      ICD Rev. F  (80-VB816-17)
     NAS      ICD Rev. YC (80-VB816-6)
     PBM      ICD Rev. H  (80-VB816-15)
     PDS      ICD Rev. N  (80-VB816-8)
     UIM      ICD Rev. W  (80-VB816-12)
     Voice    ICD Rev. M  (80-VB816-10)
     WDS      ICD Rev. YB (80-VB816-5)
     WMS      ICD Rev. H  (80-VB816-9)
     Addendum ICD Rev. C  (80-VK268-3)     

Prior Release (Gobi Extensible API 2012-06-18-1054)
a. Added support for SMD devices
b. Updated API reflect the following QMI ICDs:
     AUTH     ICD Rev. B  (80-VB816-21)
     CAT      ICD Rev. L  (80-VB816-11)
     DMS      ICD Rev. N  (80-VB816-4)
     LOC      ICD Rev. F  (80-VB816-17)
     NAS      ICD Rev. YA (80-VB816-6)
     PBM      ICD Rev. H  (80-VB816-15)
     PDS      ICD Rev. N  (80-VB816-8)
     UIM      ICD Rev. V  (80-VB816-12)
     Voice    ICD Rev. L  (80-VB816-10)
     WDS      ICD Rev. YA (80-VB816-5)
     WMS      ICD Rev. H  (80-VB816-9)
     Addendum ICD Rev. C  (80-VK268-3)     

Prior Release (Gobi Extensible API 2012-01-12-1106)
a. Addition of Gobi Sample CM (documentation is on QDevNet -
   the use of this me be subject to additional license terms)
b. Updated API reflect the following QMI ICDs:
     AUTH   ICD Rev. B (80-VB816-21)
     CAT    ICD Rev. J (80-VB816-11)
     DMS    ICD Rev. K (80-VB816-4)
     LOC    ICD Rev. D (80-VB816-17)
     NAS    ICD Rev. W (80-VB816-6)
     PBM    ICD Rev. F (80-VB816-15)
     PDS 1  ICD Rev. J (80-VB816-8)
     PDS 2  ICD Rev. D (80-VB816-14)
     UIM    ICD Rev. T (80-VB816-12)
     Voice  ICD Rev. J (80-VB816-10)
     WDS    ICD Rev. U (80-VB816-5)
     WMS    ICD Rev. F (80-VB816-9)

Prior Release (Gobi Extensible API 2011-12-15-0819)
a. Initial beta code release

-------------------------------------------------------------------------------

2. KNOWN ISSUES

No known issues.
         
-------------------------------------------------------------------------------

3. BUILD STEPS

a. Start in the 'GobiConnectionMgmt' folder
b. For Android, run:
      make Android ANDROID_PATH=<path to android toolchain>
   For x86, run:
      make

-------------------------------------------------------------------------------



