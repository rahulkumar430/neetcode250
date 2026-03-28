#include <bits/stdc++.h>
using namespace std;

// Brute Force Recursive Solution - Time Complexity: O(2^n), Space Complexity: O(n)
// class Solution {
//    public:
//     int maxMoney(vector<int>& nums, int i, bool firstTaken) {
//         int n = nums.size();

//         // If there is no house left OR last house and first was taken → cannot take this
//         if (i >= n || (i == n - 1 && firstTaken)) return 0;

//         // Choice: take or skip
//         int take = nums[i] + maxMoney(nums, i + 2, firstTaken || (i == 0));
//         int skip = maxMoney(nums, i + 1, firstTaken);

//         return max(take, skip);
//     }

//     int rob(vector<int>& nums) {
//         if (nums.size() == 1) return nums[0];
//         return maxMoney(nums, 0, false);
//     }
// };

// Top Down Dp Solution - Time Complexity: O(n), Space Complexity: O(n)
// class Solution {
//    public:
//     int maxMoney(vector<int>& nums, int i, bool firstTaken, vector<vector<int>>& dp) {
//         int n = nums.size();

//         // If there is no house left OR last house and first was taken → cannot take this
//         if (i >= n || (i == n - 1 && firstTaken)) return 0;

//         if (dp[i][firstTaken] != -1) return dp[i][firstTaken];

//         // Choice: take or skip
//         int take = nums[i] + maxMoney(nums, i + 2, firstTaken || (i == 0), dp);
//         int skip = maxMoney(nums, i + 1, firstTaken, dp);

//         return dp[i][firstTaken] = max(take, skip);
//     }

//     int rob(vector<int>& nums) {
//         int n = nums.size();
//         if (n == 1) return nums[0];

//         // dp[i][0] = max amount of money that can be stolen from houses [0, i]
//         // dp[i][1] = max amount of money that can be stolen from houses [0, i] with first house taken
//         vector<vector<int>> dp(n, vector<int>(2, -1));
//         return maxMoney(nums, 0, false, dp);
//     }
// };

// Bottom Up Dp Solution - Time Complexity: O(n), Space Complexity: O(n)
// class Solution {
//    public:
//     int maxMoney(vector<int>& nums, int l, int r) {
//         int n = nums.size();

//         vector<int> dp(n, 0);

//         dp[l] = nums[l];

//         if (l + 1 <= r)
//             dp[l + 1] = max(nums[l], nums[l + 1]);

//         for (int i = l + 2; i <= r; i++) {
//             dp[i] = max(
//                 nums[i] + dp[i - 2],  // take
//                 dp[i - 1]             // skip
//             );
//         }

//         return dp[r];
//     }

//     int rob(vector<int>& nums) {
//         int n = nums.size();
//         if (n == 1) return nums[0];

//         return max(
//             maxMoney(nums, 0, n - 2),  // include first
//             maxMoney(nums, 1, n - 1)   // exclude first
//         );
//     }
// };

// Bottom Up Space Optimised Solution - Time Complexity: O(n), Space Complexity: O(1)
class Solution {
   public:
    int maxMoney(vector<int>& nums, int l, int r) {
        int prev2 = 0, prev1 = 0;

        for (int i = l; i <= r; i++) {
            int curr = max(nums[i] + prev2, prev1);
            prev2 = prev1;
            prev1 = curr;
        }

        return prev1;
    }

    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return nums[0];

        return max(
            maxMoney(nums, 0, n - 2),  // include first
            maxMoney(nums, 1, n - 1)   // exclude first
        );
    }
};

int main() {
    vector<int> nums = {2, 9, 8, 3, 6};

    Solution sol;
    cout << sol.rob(nums) << endl;

    return 0;
}