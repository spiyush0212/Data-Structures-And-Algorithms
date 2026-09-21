#include <iostream>
#include <vector>
using namespace std;

/*
    XOR (Exclusive OR)

    Truth Table:

    A B | R
    ------
    0 0 | 0
    0 1 | 1
    1 0 | 1
    1 1 | 0

    Key Properties:
    x ^ x = 0
    x ^ 0 = x

    XOR is:
    - Commutative: a ^ b = b ^ a
    - Associative: (a ^ b) ^ c = a ^ (b ^ c)
*/


// 1. Number appearing an odd number of times
//
// All pairs cancel out.
// Only the odd-occurring number remains.
//
// Example: [2, 2, 2, 3, 2, 4, 3] -> 4

int findOddOccurrence(vector<int>& nums) {
    int result = 0;

    for (int num : nums)
        result ^= num;

    return result;
}


// 2. Missing Number in [0, N] range
//
// XOR index [0, n] with all array elements [arr[i]: 0 to N-1].
// Numbers present in both cancel out.
//
// Example: [3, 0, 1] -> 2

int findMissingNumber(vector<int>& nums) {
    int result = 0;
    int n = nums.size();

    for (int i = 0; i <= n; i++)
        result ^= i;

    for (int num : nums)
        result ^= num;

    return result;
}


// 3. Unique Number
//
// Every number appears twice except one.
// Duplicate numbers cancel out.
//
// Example: [4, 1, 2, 1, 2] -> 4

int findUniqueNumber(vector<int>& nums) {
    int result = 0;

    for (int num : nums)
        result ^= num;

    return result;
}


int main() {
    vector<int> nums1 = {2, 3, 2, 4, 3};
    cout << "Odd Occurrence: "
         << findOddOccurrence(nums1) << endl;

    vector<int> nums2 = {3, 0, 1};
    cout << "Missing Number: "
         << findMissingNumber(nums2) << endl;

    vector<int> nums3 = {4, 1, 2, 1, 2};
    cout << "Unique Number: "
         << findUniqueNumber(nums3) << endl;

    return 0;
}