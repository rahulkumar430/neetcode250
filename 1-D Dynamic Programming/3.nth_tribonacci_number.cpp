#include <bits/stdc++.h>
using namespace std;

// Brute Force Recursive Solution - Time Complexity: O(3^n), Space Complexity: O(n)
// class Solution {
//    public:
//     int tribonacci(int n) {
//         if (n == 0) return 0;
//         if (n == 1) return 1;
//         if (n == 2) return 1;
//         return tribonacci(n - 1) + tribonacci(n - 2) + tribonacci(n - 3);
//     }
// };

// Top Down Dp Solution - Time Complexity: O(n), Space Complexity: O(n)
// class Solution {
//    public:
//     int dfs(int n, vector<int>& dp) {
//         if (dp[n] != -1) return dp[n];
//         if (n == 0) return dp[n] = 0;
//         if (n == 1) return dp[n] = 1;
//         if (n == 2) return dp[n] = 1;
//         return dp[n] = dfs(n - 1, dp) + dfs(n - 2, dp) + dfs(n - 3, dp);
//     }
//     int tribonacci(int n) {
//         vector<int> dp(n + 1, -1);
//         return dfs(n, dp);
//     }
// };

// Bottom Up Dp Solution - Time Complexity: O(n), Space Complexity: O(n)
// class Solution {
//    public:
//     int tribonacci(int n) {
//         vector<int> dp(n + 1);
//         dp[0] = 0;
//         dp[1] = 1;
//         dp[2] = 1;
//         for (int i = 3; i <= n; i++) {
//             dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
//         }
//         return dp[n];
//     }
// };

// Bottom Up Space Optimised Solution - Time Complexity: O(n), Space Complexity: O(1)
class Solution {
   public:
    int tribonacci(int n) {
        int a = 0, b = 1, c = 1;
        if (n == 0) return 0;
        if (n == 1) return 1;
        if (n == 2) return 1;
        for (int i = 3; i <= n; i++) {
            int temp = a + b + c;
            a = b;
            b = c;
            c = temp;
        }
        return c;
    }
};

int main() {
    int n = 21;

    Solution sol;
    cout << sol.tribonacci(n) << endl;

    return 0;
}