#include <iostream>
#include <bitset>
using namespace std;

/*
    COUNT SET BITS

    Also called:
    - Hamming Weight
    - Population Count (Popcount)

    Set Bit = A bit whose value is 1.

    Example:
        n = 11

        Binary:
        00000000 00000000 00000000 00001011

        Set Bits = 3
*/


/*
    --------------------------------------------------
    1. Using bitset
    --------------------------------------------------

    bitset<32> stores the 32-bit binary representation.

    count()         returns the number of set bits.
    flip()          toggles the values of bits
    to_string()     returns a string representation of the data
    to_ulong()      returns an unsigned long integer representation of the data

    Time:  O(1)
    Space: O(1)
*/

int countSetBitsBitset(int n) {
    bitset<32> binary(n);

    return binary.count();
}


/*
    --------------------------------------------------
    2. Using Bit Mask
    --------------------------------------------------

    bitMask = 1 -> 000...0001

    n & bitMask checks whether the current bit is set.

    Shift the mask left after checking each bit.

    Time:  O(1)
    Space: O(1)
*/

int countSetBitsMask(int n) {
    int bitMask = 1;
    int setBits = 0;

    for (int i = 0; i < 32; i++) {
        setBits += ((n & bitMask) > 0) ? 1 : 0;
        bitMask = bitMask << 1;
    }

    return setBits;
}


/*
    --------------------------------------------------
    3. Brian Kernighan's Algorithm
    --------------------------------------------------

    Key idea:

        n       = XXXXX1 000...000
        n - 1   = XXXXX0 111...111

    AND:

                XXXXX1 000...000
              & XXXXX0 111...111
              ------------------
                XXXXX0 000...000

    Therefore:

        n & (n - 1)

    always removes the rightmost set bit.
        
    Example:

        n     = 101100
        n - 1 = 101011

        n & (n - 1)
              101000

    Therefore, the loop runs once for every set bit.

    Time:  O(K), K = number of set bits
    Space: O(1)

    Worst case for 32-bit integer with all bits set: O(32) = O(1)
*/

int countSetBitsKernighan(int n) {
    int setBits = 0;

    while (n != 0) {
        n &= (n - 1);
        setBits++;
    }

    return setBits;
}


int main() {
    int n = 11;

    cout << "Using bitset: "
         << countSetBitsBitset(n) << endl;

    cout << "Using bit mask: "
         << countSetBitsMask(n) << endl;

    cout << "Using Kernighan: "
         << countSetBitsKernighan(n) << endl;

    return 0;
}