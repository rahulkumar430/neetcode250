#include <bits/stdc++.h>
using namespace std;

// Brute Force Recursive Approach - Time Complexity: O(2^(m+n)), Space Complexity: O(m+n)
// class Solution {
//    public:
//     int helper(int m, int n, vector<vector<int>>& obstacleGrid) {
//         // Out of bounds
//         if (m < 0 || n < 0) return 0;

//         // If obstacle, no path
//         if (obstacleGrid[m][n] == 1) return 0;

//         // Reached start
//         if (m == 0 && n == 0) return 1;

//         // Move from top + left
//         return helper(m - 1, n, obstacleGrid) + helper(m, n - 1, obstacleGrid);
//     }

//     int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
//         // If starting cell is blocked
//         if (obstacleGrid[0][0] == 1) return 0;

//         int m = obstacleGrid.size();
//         int n = obstacleGrid[0].size();

//         return helper(m - 1, n - 1, obstacleGrid);
//     }
// };

// Top Down DP Approach - Time Complexity: O(m*n), Space Complexity: O(m*n)
// class Solution {
//    public:
//     int dfs(int m, int n, vector<vector<int>>& grid, vector<vector<int>>& dp) {
//         // Out of bounds
//         if (m < 0 || n < 0) return 0;

//         // Obstacle
//         if (grid[m][n] == 1) return 0;

//         // Start cell
//         if (m == 0 && n == 0) return 1;

//         // Already computed
//         if (dp[m][n] != -1) return dp[m][n];

//         // Compute from top + left
//         return dp[m][n] = dfs(m - 1, n, grid, dp) + dfs(m, n - 1, grid, dp);
//     }

//     int uniquePathsWithObstacles(vector<vector<int>>& grid) {
//         // Start blocked
//         if (grid[0][0] == 1) return 0;

//         int m = grid.size(), n = grid[0].size();
//         vector<vector<int>> dp(m, vector<int>(n, -1));

//         return dfs(m - 1, n - 1, grid, dp);
//     }
// };

// Bottom Up DP Approach - Time Complexity: O(m*n), Space Complexity: O(m*n)
// class Solution {
//    public:
//     int uniquePathsWithObstacles(vector<vector<int>>& grid) {
//         int m = grid.size(), n = grid[0].size();
//         // Edge case
//         if (grid[0][0] == 1 || grid[m - 1][n - 1] == 1) return 0;

//         vector<vector<int>> dp(m, vector<int>(n, 0));
//         dp[0][0] = 1;

//         for (int i = 0; i < m; i++) {
//             for (int j = 0; j < n; j++) {
//                 // Obstacle
//                 if (grid[i][j] == 1) {
//                     dp[i][j] = 0;
//                 } else {
//                     if (i > 0) dp[i][j] += dp[i - 1][j];  // Move from top
//                     if (j > 0) dp[i][j] += dp[i][j - 1];  // Move from left
//                 }
//             }
//         }

//         return dp[m - 1][n - 1];
//     }
// };

// Bottom Up Dp Approach with Space Optimization - Time Complexity: O(m*n), Space Complexity: O(n)
class Solution {
   public:
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        // Edge case
        if (grid[0][0] == 1 || grid[m - 1][n - 1] == 1) return 0;

        vector<int> dp(n, 0);

        // Start cell
        dp[0] = 1;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                // If obstacle → no path
                if (grid[i][j] == 1) {
                    dp[j] = 0;
                } else if (j > 0) {
                    // dp[j] = top & dp[j-1] = left
                    dp[j] += dp[j - 1];
                }
            }
        }

        return dp[n - 1];
    }
};

int main() {
    vector<vector<int>> obstacleGrid = {{0, 0, 0}, {0, 0, 0}, {0, 1, 0}};

    Solution sol;
    cout << sol.uniquePathsWithObstacles(obstacleGrid) << endl;

    return 0;
}
