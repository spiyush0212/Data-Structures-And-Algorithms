#include <vector>
#include <iostream>

using namespace std;

// Boyer-Moore Voting Algorithm
//
// Use case:
// Useful when finding an element that appears more than N/2 times
// in an array, especially when O(1) extra space is required.
//
// TIME  : O(N)
// SPACE : O(1)
//
// Key idea:
// Maintain a candidate and its vote count. Matching elements increase the count, 
// while different elements cancel one vote.
// Since the majority element appears more than N/2 times,
// it cannot be completely cancelled and remains as the final candidate with votes = 1.

int majorityElement(const vector<int>& nums) {
    int candidate = nums[0];
    int votes = 1;

    for (int i = 1; i < nums.size(); i++)
        if (candidate == nums[i])
            votes++;
        else if (votes == 1)
            candidate = nums[i];
        else
            votes--;

    return candidate;
}

int main() {
    vector<int> nums = {2, 2, 1, 1, 1, 2, 2};

    cout << majorityElement(nums) << '\n';

    return 0;
}