
--------------------------------------------------------------
To add a command to TLV2 using the "cmdRspDictGenSrc" utility
--------------------------------------------------------------

1. Make sure:
	- to get the latest halphy_tools component from P4 //components/src/wlanfw_halphy_tools.cnss/1.0
	- to have perl installed in your machine. Any version of Perl should work
	
2. Goto halphy_tools/common/tlv2p0/util directory

3. Create your command cmd*Handler.s file (where * is the command name) under util/input folder
See the format of the file in "To create an input .s file" below

4. Make sure to build the cmdRspDictGenSrc.exe on (Windows) or cmdRspDictGenSrc.out on Linux

5. On Windows, open util.sln using VS2012, and build in either Debug or Release configuration. 
The .exe file will be copied to bin folder.

6. On Linux, run "make -f makefile.Linux", the .out file will be in Linux folder

7. From the "util" folder, run addTlv2Cmd2Dict.pl to add command.

	Usage: perl addTlv2Cmd2Dict.pl input/cmd*Handler.s

This will update the following files:
	- cmdParser/cmdHandlerTbl.c
	- common/cmdRspParmsDict.c
	- common/src/*.s file (if applicable)
	- include/cmdRspParmsDict.h
	- include/cmdHandlers.h
	- include/tlv2Api.h
and add the new command handler files
	- cmdParser/cmd*Handler.c
	- include/cmd*Handler.h

Make sure the files to be updated are checked out (writeable).
NOTE: Please pay attention to the messages of addTlv2Cmd2Dict.pl, especially the errors and the "ALREADY EXISTS" warning.
If your parameter "ALREADY EXISTS", check the one already exists in the cmdRspPArmsDict.c for the type and default value.
If they are the same, you can ignore the WARNING; otherwise, consider if you can use the existing one; if not, change your parameter to a different name.

--------------------------------------------------------------
To add a system (internal) command to TLV2 using the "cmdRspDictGenSrc" utility
--------------------------------------------------------------
Use the same steps in "To add a command to TLV2 using the "cmdRspDictGenSrc" utility" with the following differences:

Step 3: The .s file should use SYSCMD for command and SYSRSP for response
Step 7: Same as step 7 above

This will update the following files (see *):
	*- cmdParser/sysCmdHandlerTbl.c
	*- common/sysCmdRspParmsDict.c
	- common/src/*.s file (if applicable)
	- include/cmdRspParmsDict.h
	- include/cmdHandlers.h
	*- include/tlv2SysApi.h
and add the new command handler files
	- cmdParser/cmd*Handler.c
	- include/cmd*Handler.h

--------------------------------------------------------------
To create an input .s file
--------------------------------------------------------------

Example: See the samples of .s files in "input" folder.
	 See cmdTestArray.s for defining different types of parameters, especially the array.

NOTE: Make sure the parameters are correctly aligned; otherwise UTF will crashes

The format of the parameter entry:

	type:name:numOfElements:specifier[:element1:element2:.]

Valid type: void, char, UINT8, UINT16, UINT32, INT8, INT16, INT32, DATA64, DATA128, DATA256, DATA512, DATA1024
Valid specifier: d(ecimal), u(nsigned decimal) , (he)x
element1..elementn: the default values; if not specified, they are set to 0

Note:
- Number of elements specified should be <= numOfElements
- DO NOT specify [:element1:element2:...] for arrays of 0's to avoid generating default arrays in *Array.s and *Data.s files

03/26/2015
Add the ability to generate array parameter with number of elements as pre-defined macro (option2)

Example: (see cmdTPCCALPWRHandler.s for more detail)

    cmd*Handler.s                                       cmd*Handler.h
    -------------                                       -------------
Option1:
INT16:tgtPwr2G:13:d                      --->         A_INT16	tgtPwr2G[13];

Option2:
#define NUM_CAL_GAINS_2G    13
INT16:tgtPwr2G:NUM_CAL_GAINS_2G:13:d     --->         A_INT16	tgtPwr2G[NUM_CAL_GAINS_2G];

--------------------------------------------------------------
To build tlv2 library with the new added command
--------------------------------------------------------------

Add the new cmd*Handler.c file to the TLV2p0.vcxproj/filters (Windows) or the cmdParser/makefile.Linux (Linux), and build the tlv2p0.


