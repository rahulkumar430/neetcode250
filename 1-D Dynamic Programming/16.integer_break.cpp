#include <bits/stdc++.h>
using namespace std;

// Brute Force Recursive Approach - Time Complexity: O(2^n), Space Complexity: O(n)
// class Solution {
//    public:
//     int helper(int n) {
//         // Base case
//         if (n == 1) return 1;

//         int maxProduct = 0;

//         // Try all possible splits
//         for (int i = 1; i < n; i++) {
//             // Two choices:
//             // 1. Don't break further → i * (n - i)
//             // 2. Break further → i * helper(n - i)
//             maxProduct = max(maxProduct, max(i * (n - i), i * helper(n - i)));
//         }

//         return maxProduct;
//     }

//     int integerBreak(int n) {
//         return helper(n);
//     }
// };

// Top-Down DP Approach - Time Complexity: O(n^2), Space Complexity: O(n)
// class Solution {
//    public:
//     int helper(int n, vector<int>& dp) {
//         if (n == 1) return 1;

//         // If already computed
//         if (dp[n] != -1) return dp[n];

//         int maxProduct = 0;

//         for (int i = 1; i < n; i++) {
//             // Two choices:
//             // 1. Don't break further → i * (n - i)
//             // 2. Break further → i * helper(n - i)
//             maxProduct = max(maxProduct, max(i * (n - i), i * helper(n - i, dp)));
//         }

//         return dp[n] = maxProduct;
//     }

//     int integerBreak(int n) {
//         vector<int> dp(n + 1, -1);
//         return helper(n, dp);
//     }
// };

// Bottom-Up DP Approach - Time Complexity: O(n^2), Space Complexity: O(n)
// class Solution {
//    public:
//     int integerBreak(int n) {
//         // dp[i] = max product for integer i
//         vector<int> dp(n + 1, 0);

//         // Base case
//         dp[1] = 1;

//         // Build from 2 → n
//         for (int i = 2; i <= n; i++) {
//             for (int j = 1; j < i; j++) {
//                 // Two choices:
//                 // 1. Don't break further → j * (i - j)
//                 // 2. Break further → j * dp[i - j]
//                 dp[i] = max(dp[i], max(j * (i - j), j * dp[i - j]));
//             }
//         }

//         return dp[n];
//     }
// };

// Mathematical Approach - Time Complexity: O(n), Space Complexity: O(1)
// Breaking into 3's - always increases product and best multiplication growth
// class Solution {
//    public:
//     int integerBreak(int n) {
//         // Base Case : return 2 incase n = 3 and return 1 incase n = 2
//         if (n <= 3) return n - 1;

//         int ans = 1;
//         while (n > 4) {
//             ans *= 3;
//             n -= 3;
//         }
//         return ans * n;
//     }
// };

// Optimal Mathematical Approach - Time Complexity: O(log n), Space Complexity: O(1)
// Breaking into 3's - always increases product and best multiplication growth
class Solution {
   public:
    int integerBreak(int n) {
        // Base Case : return 2 incase n = 3 and return 1 incase n = 2
        if (n <= 3) return n - 1;

        int ans = pow(3, n / 3);

        // In case of remainder of n/3 = 1, Divide by 3 and multiply by 2 * 2 to maximise the number
        // n = 3k + 1 then 3^k * 1 is bad instead of which 3^k/3 * (2*2)
        if (n % 3 == 1) {
            return (ans / 3) * 4;
        }

        // In case of remainder of n/3 = 2 or 0
        return ans * max(1, n % 3);
    }
};

int main() {
    int n = 12;

    Solution sol;
    cout << sol.integerBreak(n) << endl;

    return 0;
}