// Dutch National Flag Algorithm
//
// WHY:
// Sort 0s, 1s, and 2s in one pass without extra space.
//
// WHEN TO USE:
// - Sorting an array containing three distinct values.
// - Partitioning elements into three categories.
//
// ALGORITHM:
// 1. low tracks the next position where 0 can be added [ending].
// 2. mid tracks the current element.
// 3. high tracks the next position wher 2 can be added [starting].
// 4. If nums[mid] == 0, swap with low; increment low and mid.
// 5. If nums[mid] == 1, increment mid
// 6. If nums[mid] == 2, swap with high; decrement high only.
// 7. Repeat while mid <= high.
//
// TIME:  O(N)
// SPACE: O(1)

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int low = 0;
        int mid = 0;
        int high = nums.size() - 1;

        while (mid <= high) {
            if (nums[mid] == 0) {
                swap(nums[mid], nums[low]);
                low++;
                mid++;
            }
            else if (nums[mid] == 1) {
                mid++;
            }
            else {
                swap(nums[mid], nums[high]);
                high--;
            }
        }
    }
};