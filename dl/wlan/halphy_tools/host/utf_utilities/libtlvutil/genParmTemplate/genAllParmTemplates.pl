#!/usr/bin/perl -w

use strict;

my $HALPHY_TOOLS_COMPONENT_DIR = "../../../..";
my $WORK_DIR = $HALPHY_TOOLS_COMPONENT_DIR;
my $EXE = "";

if ($#ARGV == 0 && $ARGV[0] =~ /linux/i)
{
    $EXE = "Linux/genParmTemplate.out";
}
elsif ($ARGV[0] =~ /darwin/i)
{
    my $DARWIN_GENPARMTEMPLATE = "../../../../art2_peregrine/src/art2/art2_MacOs/Build";
    
    if ($#ARGV == 1 && $ARGV[1] =~ /debug/i)
    {
        $EXE = "$DARWIN_GENPARMTEMPLATE/Debug/genParmTemplate";
    }
    else
    {
        $EXE = "$DARWIN_GENPARMTEMPLATE/Release/genParmTemplate";
    }
}
elsif ($ARGV[0] =~ /win/i && $ARGV[1] =~ /debug/i)
{
    $EXE = "Debug/genParmTemplate.exe";
}
else
{
    $EXE = "Release/genParmTemplate.exe";
}


system("$EXE $WORK_DIR/include/tlv1/cmdTxParms.h");
system("$EXE $WORK_DIR/include/tlv1/cmdRxParms.h");
system("$EXE $WORK_DIR/include/tlv1/cmdCalParms.h");

system("$EXE $WORK_DIR/include/tlv1/cmdCalDoneParms.h");
system("$EXE $WORK_DIR/include/tlv1/rspGenericParms.h");
system("$EXE $WORK_DIR/include/tlv1/submitReportParms.h");
system("$EXE $WORK_DIR/include/tlv1/cmdPmParms.h");
system("$EXE $WORK_DIR/include/tlv1/cmdSetRegParms.h");
system("$EXE $WORK_DIR/include/tlv1/cmdNartGenericCmdParms.h");
system("$EXE $WORK_DIR/include/tlv1/cmdNartGenericRspParms.h");
system("$EXE $WORK_DIR/include/tlv1/cmdTxStatus.h");
system("$EXE $WORK_DIR/include/tlv1/cmdRxStatus.h");
