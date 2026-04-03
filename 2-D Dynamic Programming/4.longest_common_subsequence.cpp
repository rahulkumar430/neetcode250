#include <bits/stdc++.h>
using namespace std;

// Brute Force Recursive Approach - Time Complexity: O(2^(m+n)), Space Complexity: O(m+n)
// class Solution {
//    public:
//     int dfs(int i, int j, string& t1, string& t2) {
//         // If any string is finished
//         if (i < 0 || j < 0) return 0;

//         // If characters match
//         if (t1[i] == t2[j]) {
//             return 1 + dfs(i - 1, j - 1, t1, t2);
//         }

//         // Otherwise skip one character
//         return max(dfs(i - 1, j, t1, t2), dfs(i, j - 1, t1, t2));
//     }

//     int longestCommonSubsequence(string text1, string text2) {
//         int m = text1.size(), n = text2.size();
//         return dfs(m - 1, n - 1, text1, text2);
//     }
// };

// Top Down DP Approach - Time Complexity: O(m*n), Space Complexity: O(m*n)
// class Solution {
//    public:
//     int dfs(int i, int j, string& t1, string& t2, vector<vector<int>>& dp) {
//         // If any string is finished
//         if (i < 0 || j < 0) return 0;

//         // If already calculated
//         if (dp[i][j] != -1) return dp[i][j];

//         // If characters match
//         if (t1[i] == t2[j]) {
//             return dp[i][j] = 1 + dfs(i - 1, j - 1, t1, t2, dp);
//         }

//         // Otherwise skip one character
//         return dp[i][j] = max(dfs(i - 1, j, t1, t2, dp), dfs(i, j - 1, t1, t2, dp));
//     }

//     int longestCommonSubsequence(string text1, string text2) {
//         int m = text1.size(), n = text2.size();
//         vector<vector<int>> dp(m, vector<int>(n, -1));

//         return dfs(m - 1, n - 1, text1, text2, dp);
//     }
// };

// Bottom Up DP Approach - Time Complexity: O(m*n), Space Complexity: O(m*n)
// class Solution {
//    public:
//     int longestCommonSubsequence(string t1, string t2) {
//         int m = t1.size(), n = t2.size();
//         vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

//         // Iterate through both strings and calculate the dp table
//         for (int i = 1; i <= m; i++) {
//             for (int j = 1; j <= n; j++) {
//                 // If current characters match
//                 if (t1[i - 1] == t2[j - 1]) {
//                     // Take this character and move diagonally (reduce both strings)
//                     dp[i][j] = 1 + dp[i - 1][j - 1];

//                 } else {
//                     // Characters don't match → Skip any character by taking the maximum
//                     dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
//                 }
//             }
//         }

//         return dp[m][n];
//     }
// };

// Bottom Up Dp Approach with Space Optimization - Time Complexity: O(m*n), Space Complexity: O(n)
class Solution {
   public:
    int longestCommonSubsequence(string t1, string t2) {
        int m = t1.size(), n = t2.size();

        // prev[j] = LCS of t1[0...i-2] and t2[0...j-1]  (previous row)
        // curr[j] = LCS of t1[0...i-1] and t2[0...j-1]  (current row)
        vector<int> prev(n + 1, 0), curr(n + 1, 0);

        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                // If characters match
                if (t1[i - 1] == t2[j - 1]) {
                    // Take diagonal value + 1
                    // prev[j-1] → LCS excluding both characters
                    curr[j] = 1 + prev[j - 1];

                } else {
                    // If not match, take the best of:
                    // prev[j]     → skip character from t1 (move up)
                    // curr[j-1]   → skip character from t2 (move left)
                    curr[j] = max(prev[j], curr[j - 1]);
                }
            }

            // Move current row to previous row for next iteration
            prev = curr;
        }

        return prev[n];
    }
};

int main() {
    string text1 = "cat", text2 = "crabt";

    Solution sol;
    cout << sol.longestCommonSubsequence(text1, text2) << endl;

    return 0;
}