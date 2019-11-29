use feature ':5.10';

sub Tatami
{
  my ($arg1) = @_;
  use constant nMax => 100000000;
  use constant nMaxSqrt => int(sqrt(nMax));
  foreach my $i (7..nMaxSqrt - 1) {
    $k2 = $i + 3;
    $k3 = $i + $i - 4;
    foreach my $k ($k2..$k3) {
      last if (($i * $k2) >= nMax);
      $k4 = int(nMax / $i);
      if ($k3 < $k4) {
        $k4 = $k3;
      }
      if (($i & 1) == 1) {
        if (($k2 & 1) == 0) {
          for ($j = $k2; $j <= $k4; $j += 2) {
             $v[$i * $j]++;
          }
        }
      }
      else {
        foreach my $j ($k2..$k4) {
          $v[$i * $j]++;
        }
      }
      $k2 += $i + 1;
      $k3 += $i - 1;
    }
  }
  foreach my $i (0..nMax - 1) {
    if ($v[$i] == $arg1) {
      return $i;
    }
  }
}

say "The smallest room size s for which T(s) = 200 is ", Tatami(200);
