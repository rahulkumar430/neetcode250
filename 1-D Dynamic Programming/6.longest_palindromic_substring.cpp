#include <bits/stdc++.h>
using namespace std;

// Brute Force Approach - Time Complexity: O(n^3), Space Complexity: O(1)
// class Solution {
//    public:
//     string longestPalindrome(string s) {
//         int n = s.length();
//         string ans = "";
//         for (int i = 0; i < n; i++) {
//             for (int j = i + 1; j <= n; j++) {
//                 string temp = s.substr(i, j - i);
//                 if (temp == string(temp.rbegin(), temp.rend())) {
//                     if (j - i > ans.length()) {
//                         ans = temp;
//                     }
//                 }
//             }
//         }
//         return ans;
//     }
// };

// Dynamic Programming Approach - Time Complexity: O(n^2), Space Complexity: O(n^2)
// class Solution {
//    public:
//     string longestPalindrome(string s) {
//         int n = s.length();
//         // dp[i][j] = true if s[i..j] is a palindrome
//         vector<vector<bool>> dp(n, vector<bool>(n, false));
//         string ans = "";
//         // loop i from n-1 to 0 meanwhile j from i to n
//         for (int i = n - 1; i >= 0; i--) {
//             for (int j = i; j < n; j++) {
//                 // Check if s[i] & s[j] are equal and if s[i+1..j-1] is a palindrome with edge case where j-i <= 1
//                 if (s[i] == s[j] && (j - i <= 1 || dp[i + 1][j - 1])) {
//                     dp[i][j] = true;
//                     if (j - i + 1 > ans.length()) {
//                         ans = s.substr(i, j - i + 1);
//                     }
//                 }
//             }
//         }
//         return ans;
//     }
// };

// Two Pointers Approach - Time Complexity: O(n^2), Space Complexity: O(1)
class Solution {
   public:
    // Expand from center and return longest palindrome
    string expand(string& s, int left, int right) {
        while (left >= 0 && right < s.size() && s[left] == s[right]) {
            left--;
            right++;
        }

        // After loop ends, we went one step extra on both sides
        return s.substr(left + 1, right - left - 1);
    }

    string longestPalindrome(string s) {
        int n = s.length();
        string ans = "";

        for (int i = 0; i < n; i++) {
            // Case 1: Odd length palindrome (center = i)
            string odd = expand(s, i, i);

            // Case 2: Even length palindrome (center = i, i+1)
            string even = expand(s, i, i + 1);

            // Take the longer one
            if (odd.length() > ans.length()) ans = odd;
            if (even.length() > ans.length()) ans = even;
        }

        return ans;
    }
};

// Optimal Manacher’s Algorithm - Time Complexity: O(n), Space Complexity: O(n)
/*
        center
          ↓
----|-----|-----|----
    m     c     i
    p[i] ≈ p[m]

    Formula :
    mirror = center - (i - center)
           = 2 * center - i
*/
// class Solution {
//    public:
//     string longestPalindrome(string s) {
//         // Step 1: Transform string
//         string t = "#";
//         for (char c : s) {
//             t += c;
//             t += "#";
//         }

//         int n = t.size();
//         // p[i] = length of longest palindrome centered at i
//         vector<int> p(n, 0);

//         int center = 0, right = 0;
//         int maxLen = 0, maxCenter = 0;

//         for (int i = 0; i < n; i++) {
//             int mirror = 2 * center - i;

//             // Step 2: Use mirror info
//             if (i < right) {
//                 p[i] = min(right - i, p[mirror]);
//             }

//             // Step 3: Expand around center i
//             int left = i - (p[i] + 1);
//             int rightPtr = i + (p[i] + 1);

//             while (left >= 0 && rightPtr < n && t[left] == t[rightPtr]) {
//                 p[i]++;
//                 left--;
//                 rightPtr++;
//             }

//             // Step 4: Update center and right boundary
//             if (i + p[i] > right) {
//                 center = i;
//                 right = i + p[i];
//             }

//             // Step 5: Track max palindrome
//             if (p[i] > maxLen) {
//                 maxLen = p[i];
//                 maxCenter = i;
//             }
//         }

//         // Step 6: Extract result
//         int start = (maxCenter - maxLen) / 2;
//         return s.substr(start, maxLen);
//     }
// };

int main() {
    string s = "ababd";

    Solution sol;
    cout << sol.longestPalindrome(s) << endl;

    return 0;
}