#include <bits/stdc++.h>
using namespace std;

// Backtracking Approach with palindrome validation
// Time Complexity: O(n * 2^n), Space Complexity: O(n * 2^n)
class Solution {
   public:
    vector<vector<string>> ans;

    // Check if substring s[l..r] is palindrome
    bool isPalindrome(string& s, int l, int r) {
        while (l < r) {
            if (s[l] != s[r])
                return false;
            l++;
            r--;
        }
        return true;
    }
    // index means Current position in the string from where partitioning should start that means the left boundary
    void backtrack(string& s, int index, vector<string>& currStr) {
        // If reached end → one full partition formed
        if (index == s.size()) {
            ans.push_back(currStr);
            return;
        }

        // Try every possible substring starting from 'index'
        for (int right = index; right < s.size(); right++) {
            // Check if s[index..right] is palindrome
            if (isPalindrome(s, index, right)) {
                currStr.push_back(s.substr(index, right - index + 1));  // Choose

                backtrack(s, right + 1, currStr);  // Explore

                currStr.pop_back();  // Undo
            }
        }
    }

    vector<vector<string>> partition(string s) {
        vector<string> currStr;
        backtrack(s, 0, currStr);
        return ans;
    }
};

// Backtracking Approach with DP
// Time Complexity: O(n * 2^n), Space Complexity: O(n * 2^n)
// class Solution {
//    public:
//     vector<vector<string>> ans;

//     void backtrack(string& s, int index, vector<string>& currStr, vector<vector<bool>>& dp) {
//         // If reached end → store partition
//         if (index == s.size()) {
//             ans.push_back(currStr);
//             return;
//         }

//         for (int right = index; right < s.size(); right++) {
//             // Use DP instead of recalculating palindrome
//             if (dp[index][right]) {
//                 currStr.push_back(s.substr(index, right - index + 1));

//                 backtrack(s, right + 1, currStr, dp);

//                 currStr.pop_back();
//             }
//         }
//     }

//     vector<vector<string>> partition(string s) {
//         int n = s.size();

//         // Step 1: Build DP table
//         vector<vector<bool>> dp(n, vector<bool>(n, false));
//         // dp[i][j] = (s[i] == s[j]) AND (substring inside is palindrome OR length <= 3)
//         // That's why i is starting from the second next from end, but inside j is looping from i till end
//         for (int i = n - 1; i >= 0; i--) {
//             for (int j = i; j < n; j++) {
//                 if (s[i] == s[j] &&
//                     (j - i <= 2 || dp[i + 1][j - 1])) {
//                     dp[i][j] = true;
//                 }
//             }
//         }

//         // Step 2: Backtracking using DP
//         vector<string> currStr;
//         backtrack(s, 0, currStr, dp);

//         return ans;
//     }
// };

int main() {
    string s = "aab";

    Solution sol;
    vector<vector<string>> ans = sol.partition(s);

    for (auto v : ans) {
        for (string str : v) {
            cout << str << " ";
        }
        cout << endl;
    }

    return 0;
}