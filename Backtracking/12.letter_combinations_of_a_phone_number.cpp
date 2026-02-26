#include <bits/stdc++.h>
using namespace std;

// Backtracking Approach
// Time Complexity: O(n * 4^n), Space Complexity: O(n * 4^n)
class Solution {
   public:
    vector<string> ans;

    vector<string> dialLetters = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

    void backtrack(string& digits, int index, string currStr) {
        // If we formed a combination of same length as digits
        if (index == digits.length()) {
            ans.push_back(currStr);
            return;
        }

        string dialLetter = dialLetters[digits[index] - '0'];

        for (int i = 0; i < dialLetter.length(); i++) {
            currStr.push_back(dialLetter[i]);       // Choose
            backtrack(digits, index + 1, currStr);  // Move to next digit
            currStr.pop_back();                     // Undo

            // Above 3 lines or the below line, both works
            // backtrack(digits, index + 1, currStr + dialLetter[i]);
        }
    }

    vector<string> letterCombinations(string digits) {
        if (digits.empty())
            return {};

        backtrack(digits, 0, "");

        return ans;
    }
};

int main() {
    string digits = "34";

    Solution sol;
    vector<string> ans = sol.letterCombinations(digits);

    for (string str : ans) {
        cout << str << " ";
    }

    return 0;
}