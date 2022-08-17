#!/usr/bin/perl
use warnings;
use strict;
use utf8;
use open ":utf8";
binmode STDIN, ':encoding(cp932)';
binmode STDOUT, ':encoding(cp932)';
binmode STDERR, ':encoding(cp932)';

die "program x y density" unless (scalar(@ARGV) == 3);
my ($empty, $len, $filename) = @ARGV;

open(DATAFILE, "+>>", $filename) or die "Failed to open a file\n";
print DATAFILE "#include <stdio.h>\nint main(){\nint a;\na = printf(\"";
for (my $i = 0; $i < $len; $i++) {
	print DATAFILE $empty;
}
print DATAFILE "\");\nprintf(\"\n\%d\", a);}";
close(DATAFILE);