Observe a pattern for writing and calculating all number upto 8 or 16: <br>

0000 : 0<br>
0001 : 1<br>
0010 : 1<br>
0101 : 2<br>
...<br>
...<br>

1111 : 4<br>

The pattern coming is that Number of 1's in a given number, is<br>
(Number / 2 ) + (LSB) i.e.<br>
dp[i] = dp[i >> 1] + (i & 1)<br>

Came to this Approach with the hints given

