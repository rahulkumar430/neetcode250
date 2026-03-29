#include <bits/stdc++.h>
using namespace std;

// Brute Force Recursive Approach - Time Complexity: O(2^n), Space Complexity: O(n)
// class Solution {
//    public:
//     bool dfs(vector<int>& nums, int i, int target) {
//         // If target becomes 0 → subset found
//         if (target == 0) return true;

//         // If we reach end or target becomes negative
//         if (i == nums.size() || target < 0) return false;

//         // Option 1: include current element
//         bool include = dfs(nums, i + 1, target - nums[i]);

//         // Option 2: skip current element
//         bool skip = dfs(nums, i + 1, target);

//         return include || skip;
//     }

//     bool canPartition(vector<int>& nums) {
//         int sum = 0;
//         for (int num : nums) sum += num;

//         // If sum is odd → cannot divide into equal parts
//         if (sum % 2 != 0) return false;

//         return dfs(nums, 0, sum / 2);
//     }
// };

// Top-Down DP Approach - Time Complexity: O(n * target), Space Complexity: O(n * target)
// class Solution {
//    public:
//     bool dfs(vector<int>& nums, int i, int target, vector<vector<int>>& dp) {
//         if (target == 0) return true;
//         if (i == nums.size() || target < 0) return false;

//         // If already computed
//         if (dp[i][target] != -1) return dp[i][target];

//         // Include or skip
//         bool include = dfs(nums, i + 1, target - nums[i], dp);
//         bool skip = dfs(nums, i + 1, target, dp);

//         return dp[i][target] = include || skip;
//     }

//     bool canPartition(vector<int>& nums) {
//         int sum = 0;
//         for (int num : nums) sum += num;

//         if (sum % 2 != 0) return false;

//         int target = sum / 2;

//         vector<vector<int>> dp(nums.size(), vector<int>(target + 1, -1));

//         return dfs(nums, 0, target, dp);
//     }
// };

// Bottom-Up DP Approach - Time Complexity: O(n * target), Space Complexity: O(n * target)
// class Solution {
//    public:
//     bool canPartition(vector<int>& nums) {
//         int sum = 0;
//         for (int num : nums) sum += num;

//         if (sum % 2 != 0) return false;

//         int target = sum / 2;
//         int n = nums.size();

//         // dp[i][j] = can we make sum j using first i elements (i elements allowed to use)
//         vector<vector<bool>> dp(n + 1, vector<bool>(target + 1, false));

//         // Base case: sum 0 is always possible
//         for (int i = 0; i <= n; i++) {
//             dp[i][0] = true;
//         }

//         for (int i = 1; i <= n; i++) {
//             for (int j = 1; j <= target; j++) {
//                 // Option 1: skip current element
//                 dp[i][j] = dp[i - 1][j];

//                 // Option 2: take current element (if possible)
//                 if (j >= nums[i - 1]) {
//                     dp[i][j] = dp[i][j] || dp[i - 1][j - nums[i - 1]];
//                 }
//             }
//         }

//         return dp[n][target];
//     }
// };

// Bottom-Up Space Optimized DP Approach
// Time Complexity: O(n * target), Space Complexity: O(target)
class Solution {
   public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for (int num : nums) sum += num;

        if (sum % 2 != 0) return false;

        int target = sum / 2;

        vector<bool> dp(target + 1, false);  // dp[j] = can we make sum j
        dp[0] = true;                        // Base case

        for (int num : nums) {
            // Traverse backward to avoid overwriting
            for (int j = target; j >= num; j--) {
                // We go from right to left so that dp[j - num] is from previous iteration
                dp[j] = dp[j] || dp[j - num];
            }
        }

        return dp[target];
    }
};

int main() {
    vector<int> nums = {1, 2, 3, 4};

    Solution sol;
    cout << (sol.canPartition(nums) ? "true" : "false") << endl;

    return 0;
}