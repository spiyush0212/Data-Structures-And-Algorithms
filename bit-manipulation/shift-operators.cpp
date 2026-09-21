/*
========================
BIT SHIFT OPERATORS
========================

LEFT SHIFT (<<)
----------------

1 << k = 2^k

1 << 0 = 1    // 0001
1 << 1 = 2    // 0010
1 << 2 = 4    // 0100
1 << 3 = 8    // 1000

For non-negative integers:

n << k = n * 2^k


RIGHT SHIFT (>>)
-----------------

For non-negative integers:

n >> k = floor(n / 2^k)

13 = 1101

13 >> 1 = 0110 = 6
13 >> 2 = 0011 = 3
13 >> 3 = 0001 = 1


USEFUL PATTERNS
---------------

1. Check rightmost bit:

n & 1

0 → bit is 0
1 → bit is 1


2. Get the k-th bit:

(n >> k) & 1


3. Generate a power of 2:

1 << k = 2^k


KEY IDEA
---------

<<  shifts bits left     multiply by 2^k
>>  shifts bits right    divide   by 2^k
*/