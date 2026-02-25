#include <bits/stdc++.h>
using namespace std;

// Brute Force Approach with validator
// Time Complexity: O(n * 2^(2n)), Space Complexity: O(n * 2^(2n))
// class Solution {
//    private:
//     vector<string> ans;

//     // Validator function to check if parentheses string is valid
//     bool isValid(string& s) {
//         int balance = 0;

//         for (char c : s) {
//             if (c == '(')
//                 balance++;
//             else
//                 balance--;

//             // If at any point closing exceeds opening → invalid
//             if (balance < 0)
//                 return false;
//         }

//         // Valid only if all opened are closed
//         return balance == 0;
//     }

//     // Generate all possible strings of length 2n
//     void backtrack(string curr, int n) {
//         if (curr.length() == 2 * n) {
//             if (isValid(curr))  // Validate
//                 ans.push_back(curr);

//             return;
//         }

//         // Add '('
//         backtrack(curr + "(", n);

//         // Add ')'
//         backtrack(curr + ")", n);
//     }

//    public:
//     vector<string> generateParenthesis(int n) {
//         backtrack("", n);
//         return ans;
//     }
// };

// Optimised Backtracking Solution
// Time Complexity: O(Catalan(n)) ≈ O(4^n / sqrt(n)), Space Complexity: O(n)
class Solution {
   private:
    vector<string> ans;

    void backtrack(string curr, int openCount, int closeCount, int n) {
        // If string length reaches 2n → valid parentheses constructed
        if (curr.length() == 2 * n) {
            ans.push_back(curr);
            return;
        }

        // Invalid state: more ')' than '(' OR exceeded limit
        if (closeCount > openCount || openCount > n || closeCount > n)
            return;

        // Add '(' if we still have '(' remaining
        if (openCount < n) {
            backtrack(curr + "(", openCount + 1, closeCount, n);
        }

        // Add ')' only if it won't make it invalid
        if (closeCount < openCount) {
            backtrack(curr + ")", openCount, closeCount + 1, n);
        }
    }

   public:
    vector<string> generateParenthesis(int n) {
        backtrack("", 0, 0, n);  // Start with empty string
        return ans;
    }
};

int main() {
    int n = 3;
    Solution sol;
    vector<string> ans = sol.generateParenthesis(n);

    for (string str : ans) {
        cout << str << endl;
    }

    return 0;
}