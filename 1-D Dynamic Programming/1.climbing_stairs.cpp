#include <bits/stdc++.h>
using namespace std;

// Recursive Solution - Time Complexity: O(2^n), Space Complexity: O(n)
// class Solution {
//    public:
//     int dfs(int n) {
//         // Base Case
//         if (n == 1) return 1;
//         if (n == 2) return 2;
//         return dfs(n - 1) + dfs(n - 2);
//     }
//     int climbStairs(int n) {
//         return dfs(n);
//     }
// };

// Top Down DP Solution - Time Complexity: O(n), Space Complexity: O(n)
// class Solution {
//    public:
//     int dfs(int n, vector<int>& dp) {
//         // Base Case
//         if (n == 1) return 1;
//         if (n == 2) return 2;
//         // Memoization
//         if (dp[n] != 0) return dp[n];
//         // Recursion
//         return dp[n] = dfs(n - 1, dp) + dfs(n - 2, dp);
//     }

//     int climbStairs(int n) {
//         vector<int> dp(n + 1, 0);
//         return dfs(n, dp);
//     }
// };

// Bottom Up DP Solution - Time Complexity: O(n), Space Complexity: O(n)
// class Solution {
//    public:
//     int climbStairs(int n) {
//         vector<int> dp(n + 1, 0);
//         // Base Case
//         dp[1] = 1;
//         dp[2] = 2;

//         for (int i = 3; i <= n; i++) {
//             dp[i] = dp[i - 1] + dp[i - 2];
//         }
//         return dp[n];
//     }
// };

// Bottom Up DP Solution (space Optimized) - Time Complexity: O(n), Space Complexity: O(1)
class Solution {
   public:
    int climbStairs(int n) {
        // Base Case - Only storing last 2 ways to reach the top
        int oneStep = 1, twoStep = 1;

        // At every step : ways = last + second_last
        // Shift window forward
        for (int i = 1; i < n; i++) {
            // Curr is the new way to reach the top
            int curr = oneStep + twoStep;

            // Update twoStep, then oneStep
            twoStep = oneStep;
            oneStep = curr;
        }
        return oneStep;
    }
};

int main() {
    int n = 3;

    Solution sol;
    cout << sol.climbStairs(n) << endl;

    return 0;
}