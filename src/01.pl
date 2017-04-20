use strict;
use warnings;

my $text = <STDIN>;

my @sentences = split /([.?!][\s]*)/, $text;

foreach my $sentence (@sentences) {
	if ($sentence =~ /[.?!][\s]*/) {
		print $sentence;
	} else {
		my @words = reverse split /([- ])/, $sentence;
		foreach my $word (@words) {
			print $word;
		}
	}
}
