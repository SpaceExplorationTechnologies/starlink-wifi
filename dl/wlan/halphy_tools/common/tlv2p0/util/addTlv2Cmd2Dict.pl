#!/usr/bin/perl -w

use English qw' -no_match_vars ';

if (@ARGV < 1)
{
	print "Please enter an input file!\n";
	exit 0;
}
system("perl ./preBuildEvents.pl");
if ($OSNAME eq "MSWin32")
{
	system("bin\\cmdRspDictGenSrc.exe $ARGV[0]");
}
elsif ($OSNAME eq "linux")
{
	system("./Linux/cmdRspDictGenSrc.out $ARGV[0]");
}
else 
{
	print "This util is not supported in $OSNAME\n";
}
system("perl ./updateTlv2GenFiles.pl");


