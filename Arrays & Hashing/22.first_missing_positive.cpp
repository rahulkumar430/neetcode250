#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    // Optimised solution but not within O(1) space
    int firstMissingPositive(vector<int>& nums) {
        // Put all numbers into an unordered_set for O(1)-average membership checks
        unordered_set<int> us(nums.begin(), nums.end());

        // Find the maximum value in the array
        int max = INT_MIN;
        for (int num : nums) {
            if (num >= max) max = num;
        }

        // Check from 1 up to max to find the first missing positive
        for (int i = 1; i <= max; i++) {
            // If i is not present in the set, it's the first missing positive
            if (us.count(i) != 1) return i;
        }

        // If all 1..max exist:
        // - If max is positive, the first missing positive is max + 1
        // - If max <= 0 (no positive numbers), the answer must be 1
        return max > 0 ? ++max : 1;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {1, 2, 4};

    cout << sol.firstMissingPositive(nums) << endl;

    return 0;
}