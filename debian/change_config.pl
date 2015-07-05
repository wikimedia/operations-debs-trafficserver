#! /usr/bin/perl

use strict;

our @config_lines;
our %defaults = (
    "proxy.config.alarm_email" => "trafficserver",
    "proxy.config.admin.user_id" => "trafficserver",
    "proxy.config.log.max_space_mb_for_logs" => 2000,
);

die("Usage: $0 <file name>") unless $#ARGV == 0;

open(F, "+<", $ARGV[0]) || die("Cannot open $ARGV[0]: $!");
while(my $line = <F>)
{
        if ($line =~ /^CONFIG/)
        {
                foreach my $pattern (keys %defaults)
                {
                    $line =~ s/(?<=CONFIG $pattern)(\s+[A-Z]+)\s+.+$/$1 $defaults{$pattern}/;
                }
        }
        push(@config_lines, $line);
}
seek(F, 0, 0);
foreach my $line (@config_lines)
{
        print F $line;
}
print F "CONFIG proxy.config.admin.user_id STRING trafficserver\n";
close(F);
