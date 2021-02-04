#!/usr/bin/perl -w

use File::Copy;

if (!(-d "bin"))
{
	mkdir "bin";
}
copy ("$ARGV[0]/cmdRspDictGenSrc.exe", "bin/cmdRspDictGenSrc.exe") or print "Error: cannot copy cmdRspDictGenSrc.exe file to bin\n";

