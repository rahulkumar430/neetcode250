#include <bits/stdc++.h>
using namespace std;

// Brute Force Recursive Approach - Time Complexity: O(2^n), Space Complexity: O(n)
// class Solution {
//    public:
//     int dfs(string s, int i) {
//         // Base Case
//         if (i == s.size()) return 1;
//         if (s[i] == '0') return 0;

//         // Consider 1 digit
//         int ans = dfs(s, i + 1);

//         // Consider 2 digits and check if it is less than or equal to 26
//         if (i + 1 < s.size() && (s[i] == '1' || (s[i] == '2' && s[i + 1] <= '6')))
//             ans += dfs(s, i + 2);

//         return ans;
//     }

//     int numDecodings(string s) {
//         return dfs(s, 0);
//     }
// };

// Top Down DP Approach - Time Complexity: O(n), Space Complexity: O(n)
// class Solution {
//    public:
//     int dfs(string& s, int i, vector<int>& dp) {
//         // Base Case
//         if (i == s.size()) return 1;
//         if (s[i] == '0') return 0;

//         if (dp[i] != -1) return dp[i];

//         // Consider 1 digit
//         int ans = dfs(s, i + 1, dp);

//         // Consider 2 digits and check if it is less than or equal to 26
//         if (i + 1 < s.size() && (s[i] == '1' || (s[i] == '2' && s[i + 1] <= '6')))
//             ans += dfs(s, i + 2, dp);

//         // Store the result in the dp array
//         return dp[i] = ans;
//     }

//     int numDecodings(string s) {
//         vector<int> dp(s.size(), -1);
//         return dfs(s, 0, dp);
//     }
// };

// Bottom Up DP Approach - Time Complexity: O(n), Space Complexity: O(n)
// class Solution {
//    public:
//     int numDecodings(string s) {
//         int n = s.size();

//         // dp[i] = number of ways to decode substring starting from index i
//         vector<int> dp(n + 1, 0);

//         // Base case:
//         // If we reach the end → 1 valid way (successful decoding path)
//         dp[n] = 1;

//         // Fill DP from right to left
//         for (int i = n - 1; i >= 0; i--) {
//             // If current character is '0', no valid decoding
//             if (s[i] == '0') {
//                 dp[i] = 0;
//                 continue;
//             }

//             // Case 1: Take single digit
//             dp[i] = dp[i + 1];

//             // Case 2: Take two digits (if valid: 10–26)
//             if (i + 1 < n && (s[i] == '1' || (s[i] == '2' && s[i + 1] <= '6'))) {
//                 dp[i] += dp[i + 2];
//             }
//         }

//         return dp[0];
//     }
// };

// Space Optimized Bottom Up DP Approach - Time Complexity: O(n), Space Complexity: O(1)
class Solution {
   public:
    int numDecodings(string s) {
        int n = s.size();

        int next = 1;      // dp[i+1]
        int nextNext = 1;  // dp[i+2]

        // Iterate from right to left
        for (int i = n - 1; i >= 0; i--) {
            int curr = 0;

            // Proceeed only if current character is not '0'
            if (s[i] != '0') {
                // Case 1: Take single digit
                curr = next;

                // Case 2: Take two digits (if valid: 10–26)
                if (i + 1 < n && (s[i] == '1' || (s[i] == '2' && s[i + 1] <= '6'))) {
                    curr += nextNext;
                }
            }

            // Update next and nextNext for the next iteration
            nextNext = next;
            next = curr;
        }

        return next;
    }
};

int main() {
    string s = "12";

    Solution sol;
    cout << sol.numDecodings(s) << endl;

    return 0;
}