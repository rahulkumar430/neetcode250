#include <bits/stdc++.h>
using namespace std;

// Brute Force Recursive Approach - Time Complexity: O(2^n), Space Complexity: O(n)
// class Solution {
//    public:
//     int dfs(vector<int>& nums, int i, int prevIndex) {
//         // Base case: reached end
//         if (i == nums.size()) return 0;

//         // Option 1: skip current element
//         int skip = dfs(nums, i + 1, prevIndex);

//         int include = 0;

//         // Option 2: include current element (only if increasing)
//         if (prevIndex == -1 || nums[i] > nums[prevIndex]) {
//             include = 1 + dfs(nums, i + 1, i);
//         }

//         // Return best of both choices
//         return max(include, skip);
//     }

//     int lengthOfLIS(vector<int>& nums) {
//         return dfs(nums, 0, -1);
//     }
// };

// Top Down DP Approach - Time Complexity: O(n^2), Space Complexity: O(n^2)
// class Solution {
//    public:
//     int dfs(vector<int>& nums, int currIndex, int prevIndex, vector<vector<int>>& dp) {
//         // Base case
//         if (currIndex == nums.size()) return 0;

//         if (dp[currIndex][prevIndex + 1] != -1) return dp[currIndex][prevIndex + 1];

//         // Option 1: skip current element and let prevIndex as it is
//         int skip = dfs(nums, currIndex + 1, prevIndex, dp);

//         int include = 0;

//         // Option 2: include current element and make currIndex as prevIndex (only if increasing)
//         if (prevIndex == -1 || nums[currIndex] > nums[prevIndex]) {
//             include = 1 + dfs(nums, currIndex + 1, currIndex, dp);
//         }

//         // Store and return result
//         return dp[currIndex][prevIndex + 1] = max(include, skip);
//     }

//     int lengthOfLIS(vector<int>& nums) {
//         int n = nums.size();

//         // dp[i][prevIndex+1] = length of LIS starting from index i,
//         // given that the previous chosen element is at index prevIndex
//         vector<vector<int>> dp(n, vector<int>(n + 1, -1));

//         return dfs(nums, 0, -1, dp);
//     }
// };

// Bottom Up DP Approach - Time Complexity: O(n^2), Space Complexity: O(n)
// class Solution {
//    public:
//     int lengthOfLIS(vector<int>& nums) {
//         int n = nums.size();

//         // dp[i] = LIS ending at index i
//         vector<int> dp(n, 1);  // every element itself is LIS of length 1

//         int ans = 1;

//         for (int i = 0; i < n; i++) {
//             for (int j = 0; j < i; j++) {
//                 // If increasing sequence possible : we can extend LIS ending at j by adding nums[i]
//                 if (nums[i] > nums[j]) {
//                     dp[i] = max(dp[i], dp[j] + 1);
//                 }
//             }

//             ans = max(ans, dp[i]);
//         }

//         return ans;
//     }
// };

// DP + Binary Search Approach (Optimized LIS) - Time Complexity: O(n log n), Space Complexity: O(n)
// Greedy + DP hybrid
class Solution {
   public:
    int lengthOfLIS(vector<int>& nums) {
        // dp[i] = smallest possible tail of an increasing subsequence of length (i+1)
        vector<int> dp;

        for (int num : nums) {
            // Find the first index where dp[index] >= num
            // This ensures we maintain smallest possible tail
            auto it = lower_bound(dp.begin(), dp.end(), num);

            if (it == dp.end()) {
                // num is greater than all → extend subsequence
                dp.push_back(num);
            } else {
                // Replace to keep subsequence optimal
                *it = num;
            }
        }

        // Length of dp = length of LIS
        return dp.size();
    }
};

int main() {
    vector<int> nums = {9, 1, 4, 2, 3, 3, 7};

    Solution sol;
    cout << sol.lengthOfLIS(nums) << endl;

    return 0;
}