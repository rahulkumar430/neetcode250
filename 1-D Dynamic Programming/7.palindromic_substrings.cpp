#include <bits/stdc++.h>
using namespace std;

// Brute Force Approach - Time Complexity: O(n^3), Space Complexity: O(1)
// class Solution {
//    public:
//     int countSubstrings(string s) {
//         int n = s.length();
//         int ans = 0;
//         for (int i = 0; i < n; i++) {
//             for (int j = i + 1; j <= n; j++) {
//                 string temp = s.substr(i, j - i);
//                 if (temp == string(temp.rbegin(), temp.rend())) {
//                     ans++;
//                 }
//             }
//         }
//         return ans;
//     }
// };

// Dynamic Programming Approach - Time Complexity: O(n^2), Space Complexity: O(n^2)
// class Solution {
//    public:
//     int countSubstrings(string s) {
//         int n = s.length();
//         // dp[i][j] = true if s[i..j] is a palindrome
//         vector<vector<bool>> dp(n, vector<bool>(n, false));
//         int ans = 0;
//         // loop i from n-1 to 0 meanwhile j from i to n
//         for (int i = n - 1; i >= 0; i--) {
//             for (int j = i; j < n; j++) {
//                 // Check if s[i] & s[j] are equal and if s[i+1..j-1] is a palindrome with edge case where j-i <= 1
//                 if (s[i] == s[j] && (j - i <= 1 || dp[i + 1][j - 1])) {
//                     dp[i][j] = true;
//                     ans++;
//                 }
//             }
//         }
//         return ans;
//     }
// };

// Two Pointers Approach - Time Complexity: O(n^2), Space Complexity: O(1)
class Solution {
   public:
    int expand(string& s, int left, int right) {
        int count = 0;

        while (left >= 0 && right < s.size() && s[left] == s[right]) {
            count++;  // found one palindrome
            left--;
            right++;
        }

        return count;
    }

    int countSubstrings(string s) {
        int n = s.size();
        int total = 0;

        for (int i = 0; i < n; i++) {
            // Odd length palindromes (center = i)
            total += expand(s, i, i);

            // Even length palindromes (center = i, i+1)
            total += expand(s, i, i + 1);
        }

        return total;
    }
};

int main() {
    string s = "aaa";

    Solution sol;
    cout << sol.countSubstrings(s) << endl;

    return 0;
}