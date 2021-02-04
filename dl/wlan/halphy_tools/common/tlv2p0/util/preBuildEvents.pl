#!/usr/bin/perl -w

use File::Copy;

if (-d "output")
{
	my @oldFiles = <output/*>;
	unlink @oldFiles;
}
else
{
	mkdir "output";
}

my @list = <../common/src/*.s>;
foreach my $file(@list)
{
	copy ($file, "output/");
}
my @newFiles = <output/*>;
chmod 0600, @newFiles;
