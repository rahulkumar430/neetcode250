#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    // Optimised solution but not within O(1) space
    // int firstMissingPositive(vector<int>& nums) {
    //     // Put all numbers into an unordered_set for O(1)-average membership checks
    //     unordered_set<int> us(nums.begin(), nums.end());

    //     // Find the maximum value in the array
    //     int max = INT_MIN;
    //     for (int num : nums) {
    //         if (num >= max) max = num;
    //     }

    //     // Check from 1 up to max to find the first missing positive
    //     for (int i = 1; i <= max; i++) {
    //         // If i is not present in the set, it's the first missing positive
    //         if (us.count(i) != 1) return i;
    //     }

    //     // If all 1..max exist:
    //     // - If max is positive, the first missing positive is max + 1
    //     // - If max <= 0 (no positive numbers), the answer must be 1
    //     return max > 0 ? ++max : 1;
    // }

    // Time complexity: O(n) Space complexity : O(n)
    // int firstMissingPositive(vector<int>& nums) {
    //     int n = nums.size();

    //     // seen[i] tells whether the number (i+1) exists in nums
    //     vector<bool> seen(n, false);

    //     // Mark all positive numbers in the range [1, n]
    //     for (int num : nums) {
    //         if (num > 0 && num <= n) {
    //             seen[num - 1] = true;  // Number num is present → mark index num-1
    //         }
    //     }

    //     // The first index i where seen[i] is false means (i+1) is missing
    //     for (int i = 0; i < n; i++) {
    //         if (!seen[i]) {
    //             return i + 1;  // First missing positive
    //         }
    //     }

    //     // If all numbers 1..n are present, then the answer is n+1
    //     return n + 1;
    // }

    // Cycle Sort : Time complexity: O(n) Space complexity : O(1)
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();

        // Place each number x (1 <= x <= n) at index x-1 if possible
        for (int i = 0; i < n; i++) {
            // While nums[i] is in the range [1, n] and not in its correct position,
            // swap it to its correct position.
            while (nums[i] >= 1 && nums[i] <= n && nums[nums[i] - 1] != nums[i]) {
                swap(nums[i], nums[nums[i] - 1]);
            }
        }

        // Now, the first index i where nums[i] != i + 1 gives the answer i + 1
        for (int i = 0; i < n; i++) {
            if (nums[i] != i + 1) {
                return i + 1;
            }
        }

        // If all positions 1..n are filled correctly, answer is n+1
        return n + 1;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {1, 2, 4};

    cout << sol.firstMissingPositive(nums) << endl;

    return 0;
}