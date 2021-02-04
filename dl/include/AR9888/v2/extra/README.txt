This directory holds header files that are very specific to
AR9888 hardware but which are managed by the Software team.

Through this directory Software provides
1) some backwards compatibility with header file names, register names, etc. 
2) some level of compatibility across platforms (e.g. AR6004 and AR9888).
3) some useful definitions that are simply not provided in the Hardware
   header files, such as C structure definitions for descriptors.

Typically, source code simply includes a file such as
  #include <hw/xyz.h>

When code is compiled, the build system uses something like this:
  -I ....../include/AR9888/extra -I ....../include/AR9888
