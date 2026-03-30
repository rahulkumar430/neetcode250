#include <bits/stdc++.h>
using namespace std;

// Brute Force Recursive Approach - Time Complexity: O(n^target), Space Complexity: O(target)
// class Solution {
//    public:
//     int helper(vector<int>& nums, int target) {
//         // If exact sum formed → 1 valid way
//         if (target == 0) return 1;

//         // If exceeded → no way
//         if (target < 0) return 0;

//         int count = 0;

//         // Try all numbers (order matters)
//         for (int num : nums) {
//             count += helper(nums, target - num);
//         }

//         return count;
//     }

//     int combinationSum4(vector<int>& nums, int target) {
//         return helper(nums, target);
//     }
// };

// Top-Down DP Approach - Time Complexity: O(n * target), Space Complexity: O(target)
// class Solution {
//    public:
//     int dfs(vector<int>& nums, int target, vector<int>& dp) {
//         // Base case
//         if (target == 0) return 1;

//         // If already computed
//         if (dp[target] != -1) return dp[target];

//         int count = 0;

//         // Try all numbers (order matters)
//         for (int num : nums) {
//             if (target - num >= 0) {
//                 count += dfs(nums, target - num, dp);
//             }
//         }

//         // Store result
//         return dp[target] = count;
//     }

//     int combinationSum4(vector<int>& nums, int target) {
//         vector<int> dp(target + 1, -1);

//         return dfs(nums, target, dp);
//     }
// };

// Bottom-Up DP Approach - Time Complexity: O(n * target), Space Complexity: O(target)
class Solution {
   public:
    int combinationSum4(vector<int>& nums, int target) {
        // dp[i] = number of ways to form sum i
        vector<int> dp(target + 1, 0);

        // Base case
        dp[0] = 1;  // one way: choose nothing

        // Build from 1 → target
        for (int i = 1; i <= target; i++) {
            for (int num : nums) {
                if (i - num >= 0) {
                    dp[i] += dp[i - num];
                }
            }
        }

        return dp[target];
    }
};

int main() {
    vector<int> nums = {3, 1, 2};
    int target = 4;

    Solution sol;
    cout << sol.combinationSum4(nums, target) << endl;

    return 0;
}