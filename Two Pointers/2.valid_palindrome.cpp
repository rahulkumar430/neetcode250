#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    bool isAlnumManual(char c) {
        return (c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z') || (c >= '0' && c <= '9');
    }
    // Optimised Solution using two pointers approach
    bool isPalindrome(string s) {
        int l = 0, r = s.size() - 1;

        while (l < r) {
            // Skip non-alphanumeric WITH boundary check
            while (l < r && !isAlnumManual(s[l])) l++;
            while (l < r && !isAlnumManual(s[r])) r--;

            // If pointers crossed, string is palindrome
            if (l >= r) return true;

            // Case-insensitive comparison
            if (tolower(s[l++]) != tolower(s[r--])) return false;
        }
        return true;
    }
};
int main() {
    Solution sol;
    string s = "Was it a car or a cat I saw?";

    cout << sol.isPalindrome(s) << endl;

    return 0;
}