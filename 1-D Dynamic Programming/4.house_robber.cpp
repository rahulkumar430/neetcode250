#include <bits/stdc++.h>
using namespace std;

// Brute Force Recursive Solution - Time Complexity: O(2^n), Space Complexity: O(n)
// class Solution {
//    public:
//     int maxMoney(vector<int>& nums, int i) {
//         if (i >= nums.size()) return 0;
//         return max(nums[i] + maxMoney(nums, i + 2), maxMoney(nums, i + 1));
//     }
//     int rob(vector<int>& nums) {
//         return maxMoney(nums, 0);
//     }
// };

// Top Down Dp Solution - Time Complexity: O(n), Space Complexity: O(n)
// class Solution {
//    public:
//     int maxMoney(vector<int>& nums, int i, vector<int>& dp) {
//         if (i >= nums.size()) return 0;
//         if (dp[i] != -1) return dp[i];

//         dp[i] = max(nums[i] + maxMoney(nums, i + 2, dp), maxMoney(nums, i + 1, dp));

//         return dp[i];
//     }
//     int rob(vector<int>& nums) {
//         vector<int> dp(nums.size(), -1);
//         return maxMoney(nums, 0, dp);
//     }
// };

// Bottom Up Dp Solution - Time Complexity: O(n), Space Complexity: O(n)
// class Solution {
//    public:
//     int rob(vector<int>& nums) {
//         int n = nums.size();
//         if (n == 0) return 0;
//         if (n == 1) return nums[0];

//         vector<int> dp(n + 1, 0);
//         dp[0] = nums[0];
//         dp[1] = max(nums[0], nums[1]);

//         for (int i = 2; i < n; i++) {
//             dp[i] = max(nums[i] + dp[i - 2], dp[i - 1]);
//         }
//         return dp[n - 1];
//     }
// };

// Bottom Up Space Optimised Solution - Time Complexity: O(n), Space Complexity: O(1)
class Solution {
   public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;
        if (n == 1) return nums[0];

        int a = nums[0];
        int b = max(nums[0], nums[1]);

        for (int i = 2; i < n; i++) {
            int temp = max(nums[i] + a, b);
            a = b;
            b = temp;
        }
        return b;
    }
};

int main() {
    vector<int> nums = {2, 9, 8, 3, 6};

    Solution sol;
    cout << sol.rob(nums) << endl;

    return 0;
}