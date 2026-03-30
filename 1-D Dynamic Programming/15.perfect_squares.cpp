#include <bits/stdc++.h>
using namespace std;

// Brute Force Recursive Approach - Time Complexity: (O(n^(√n))), Space Complexity: O(n)
// class Solution {
//    public:
//     int helper(int n) {
//         // Base case
//         if (n == 0) return 0;

//         int ans = n;  // worst case : all 1's

//         // Try all possible square numbers
//         for (int i = 1; i * i <= n; i++) {
//             ans = min(ans, 1 + helper(n - i * i));
//         }

//         return ans;
//     }

//     int numSquares(int n) {
//         return helper(n);
//     }
// };

// Top-Down DP Approach - Time Complexity: O(n * √n), Space Complexity: O(n)
// class Solution {
//    public:
//     int dfs(int n, vector<int>& dp) {
//         // Base case
//         if (n == 0) return 0;

//         // If already computed
//         if (dp[n] != -1) return dp[n];

//         int ans = n;  // worst case: all 1's

//         // Try all perfect squares ≤ n
//         for (int i = 1; i * i <= n; i++) {
//             // Choose square i*i and solve remaining
//             ans = min(ans, 1 + dfs(n - i * i, dp));
//         }

//         return dp[n] = ans;
//     }

//     int numSquares(int n) {
//         vector<int> dp(n + 1, -1);
//         return dfs(n, dp);
//     }
// };

// Bottom-Up DP Approach - Time Complexity: O(n * √n), Space Complexity: O(n)
class Solution {
   public:
    int numSquares(int n) {
        // dp[i] = minimum squares needed to make sum i
        vector<int> dp(n + 1, INT_MAX);

        // Base case
        dp[0] = 0;

        // Build from 1 → n
        for (int i = 1; i <= n; i++) {
            // Try all perfect squares ≤ i
            for (int j = 1; j * j <= i; j++) {
                // If we use square j*j
                dp[i] = min(dp[i], 1 + dp[i - j * j]);
            }
        }

        return dp[n];
    }
};

// BFS Approach (Shortest Path) - Time Complexity: O(n * √n), Space Complexity: O(n)
// class Solution {
//    public:
//     int numSquares(int n) {
//         // Precompute all perfect squares ≤ n
//         vector<int> squares;
//         for (int i = 1; i * i <= n; i++) {
//             squares.push_back(i * i);
//         }

//         // Queue for BFS
//         queue<int> q;
//         q.push(n);

//         // Visited array to avoid revisiting same number
//         vector<bool> visited(n + 1, false);
//         visited[n] = true;

//         int level = 0;  // number of squares used

//         while (!q.empty()) {
//             int size = q.size();
//             level++;  // moving to next level → one more square used

//             for (int i = 0; i < size; i++) {
//                 int curr = q.front();
//                 q.pop();

//                 // Try subtracting all squares
//                 for (int sq : squares) {
//                     int next = curr - sq;

//                     // If we reach 0 → answer found
//                     if (next == 0) return level;

//                     // If valid and not visited
//                     if (next > 0 && !visited[next]) {
//                         visited[next] = true;
//                         q.push(next);
//                     }
//                 }
//             }
//         }

//         return -1;  // should never happen
//     }
// };

int main() {
    int n = 13;

    Solution sol;
    cout << sol.numSquares(n) << endl;

    return 0;
}