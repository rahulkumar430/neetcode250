#include <bits/stdc++.h>
using namespace std;

// Brute Force Recursive Approach - Time Complexity: O(2^(m+n)), Space Complexity: O(m+n)
// Start from the end to the beginning to avoid exceeding boundaries
// class Solution {
//    public:
//     int helper(int m, int n) {
//         if (m == 0 || n == 0) {
//             return 1;
//         }
//         return helper(m - 1, n) + helper(m, n - 1);
//     }
//     int uniquePaths(int m, int n) {
//         return helper(m - 1, n - 1);
//     }
// };

// Top Down DP Approach - Time Complexity: O(m*n), Space Complexity: O(m*n)
// class Solution {
//    public:
//     int dfs(int m, int n, vector<vector<int>>& dp) {
//         // Base case
//         if (m == 0 || n == 0) {
//             return 1;
//         }
//         // If the value is already calculated, return it
//         if (dp[m][n] != -1)
//             return dp[m][n];

//         // Go up or left
//         dp[m][n] = dfs(m - 1, n, dp) + dfs(m, n - 1, dp);
//         return dp[m][n];
//     }

//     int uniquePaths(int m, int n) {
//         vector<vector<int>> dp(m, vector<int>(n, -1));
//         return dfs(m - 1, n - 1, dp);
//     }
// };

// Bottom Up DP Approach - Time Complexity: O(m*n), Space Complexity: O(m*n)
// class Solution {
//    public:
//     int uniquePaths(int m, int n) {
//         vector<vector<int>> dp(m, vector<int>(n, 1));

//         for (int i = 1; i < m; i++) {
//             for (int j = 1; j < n; j++) {
//                 dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
//             }
//         }
//         return dp[m - 1][n - 1];
//     }
// };

// Bottom Up Dp Approach with Space Optimization - Time Complexity: O(m*n), Space Complexity: O(n)
class Solution {
   public:
    int uniquePaths(int m, int n) {
        vector<int> dp(n, 1);

        // Though we are going row wise left to right, we don't a 2d dp array
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                // dp[j] = top and dp[j-1] = left
                dp[j] += dp[j - 1];
            }
        }
        return dp[n - 1];
    }
};

// Maths Approach - nCr - Time Complexity: O(n), Space Complexity: O(1)
// class Solution {
//    public:
//     int uniquePaths(int m, int n) {
//         int N = m + n - 2;          // total moves
//         int r = min(m - 1, n - 1);  // choose smaller to optimize

//         long long res = 1;

//         // Compute nCr using iterative multiplication
//         for (int i = 1; i <= r; i++) {
//             res = res * (N - r + i) / i;
//         }

//         return (int)res;
//     }
// };

int main() {
    int m = 3, n = 6;

    Solution sol;
    cout << sol.uniquePaths(m, n) << endl;

    return 0;
}