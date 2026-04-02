#include <bits/stdc++.h>
using namespace std;

// Brute Force Recursive Approach - Time Complexity: O(2^(m+n)), Space Complexity: O(m+n)
// class Solution {
//    public:
//     int dfs(int i, int j, vector<vector<int>>& grid) {
//         // Out of bounds → invalid path
//         if (i < 0 || j < 0) return INT_MAX;

//         // Start cell
//         if (i == 0 && j == 0) return grid[0][0];

//         // Take min of top and left
//         int up = dfs(i - 1, j, grid);
//         int left = dfs(i, j - 1, grid);

//         return grid[i][j] + min(up, left);
//     }

//     int minPathSum(vector<vector<int>>& grid) {
//         int m = grid.size(), n = grid[0].size();
//         return dfs(m - 1, n - 1, grid);
//     }
// };

// Top Down DP Approach - Time Complexity: O(m*n), Space Complexity: O(m*n)
// class Solution {
//    public:
//     int dfs(int i, int j, vector<vector<int>>& grid, vector<vector<int>>& dp) {
//         if (i < 0 || j < 0) return INT_MAX;  // Out of bounds

//         if (i == 0 && j == 0) return grid[0][0];  // Base case

//         if (dp[i][j] != -1) return dp[i][j];

//         int up = dfs(i - 1, j, grid, dp);
//         int left = dfs(i, j - 1, grid, dp);

//         return dp[i][j] = grid[i][j] + min(up, left);
//     }

//     int minPathSum(vector<vector<int>>& grid) {
//         int m = grid.size(), n = grid[0].size();
//         vector<vector<int>> dp(m, vector<int>(n, -1));

//         return dfs(m - 1, n - 1, grid, dp);
//     }
// };

// Bottom Up DP Approach - Time Complexity: O(m*n), Space Complexity: O(m*n)
// class Solution {
//    public:
//     int minPathSum(vector<vector<int>>& grid) {
//         int m = grid.size(), n = grid[0].size();
//         vector<vector<int>> dp(m, vector<int>(n, 0));

//         dp[0][0] = grid[0][0];

//         // First column
//         for (int i = 1; i < m; i++) {
//             dp[i][0] = grid[i][0] + dp[i - 1][0];
//         }

//         // First row
//         for (int j = 1; j < n; j++) {
//             dp[0][j] = grid[0][j] + dp[0][j - 1];
//         }

//         // Fill rest
//         for (int i = 1; i < m; i++) {
//             for (int j = 1; j < n; j++) {
//                 dp[i][j] = grid[i][j] + min(dp[i - 1][j], dp[i][j - 1]);
//             }
//         }

//         return dp[m - 1][n - 1];
//     }
// };

// Bottom Up Dp Approach with Space Optimization - Time Complexity: O(m*n), Space Complexity: O(n)
class Solution {
   public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<int> dp(n, 0);

        dp[0] = grid[0][0];

        // First row
        for (int j = 1; j < n; j++) {
            dp[j] = grid[0][j] + dp[j - 1];
        }

        for (int i = 1; i < m; i++) {
            // First column
            dp[0] += grid[i][0];

            for (int j = 1; j < n; j++) {
                // dp[j] = Top(Previous row) , dp[j - 1] = Left(Current row)
                dp[j] = grid[i][j] + min(dp[j], dp[j - 1]);
            }
        }

        return dp[n - 1];
    }
};

int main() {
    vector<vector<int>> grid = {{1, 2, 0}, {5, 4, 2}, {1, 1, 3}};

    Solution sol;
    cout << sol.minPathSum(grid) << endl;

    return 0;
}
