#include <bits/stdc++.h>
using namespace std;

// ALGO     KADANE'S ALGORITHM - SIMILAR TO TWO POINTERS & SLIDING WINDOW

// IDEA     Maintain the maximum sum of a subarray ending at the current index.
//          If the current sum becomes negative, discard that prefix since it
//          can only reduce the sum of any future subarray.
//          Keep updating the maximum sum seen so far.

// TIME     O(N)
// SPACE    O(1)

int maxSubArray(vector<int>& nums) {
    int start = 0;
    int result = INT_MIN;
    int curSum = 0;

    for (int end = 0; end < nums.size(); end++) {
        curSum += nums[end];
        result = max(result, curSum);

        while (start <= end && curSum < 0) {
            curSum -= nums[start];
            start++;
        }
    }

    return result;
}

int main() {
    vector<int> nums = {-2, 1, -3, 4, -1, 2, 1, -5, 4};

    cout << maxSubArray(nums) << endl;

    return 0;
}