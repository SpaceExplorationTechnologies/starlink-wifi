#!/usr/bin/perl -w

use File::Copy;

if (!(-d "output") || (isEmpty("output")))
{
	print "No files generated\n";
}
else
{
	my @slist = <output/*.s>;
	foreach my $file(@slist)
	{
		move ($file, "../common/src/") or print "Error: cannot update ../common/src with $file. Check-out the file first\n";
	}
	my @clist = <output/*.c>;
	foreach my $file(@clist)
	{
		if (($file eq "output/cmdRspParmsDict.c") or ($file eq "output/sysCmdRspParmsDict.c"))
		{
			move ($file, "../common/") or print "Error: cannot update ../common with $file. Check-out the file first\n";
		}
		else
		{
			move ($file, "../cmdParser/") or print "Error: cannot update ../cmdParser with $file. Check-out the file first\n";
		}
	}
	my @hlist = <output/*.h>;
	foreach my $file(@hlist)
	{
		move ($file, "../include/") or print "Error: cannot update ../include with $file. Check-out the file first\n";
	}
}

#--------------------
sub isEmpty
{
	opendir (DIR, shift) or die $!;
	my @files = grep { !m/\A\.{1,2}\Z/} readdir(DIR);
	closedir(DIR);
	@files ? 0 : 1;
}
