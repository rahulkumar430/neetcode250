#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    // Basic Approach using two pointers
    // bool validPalindrome(string s) {
    //     int l = 0, r = (int)s.size() - 1;  // Two pointers: left and right
    //     int cnt = 1;                       // Allowed deletions (at most 1)

    //     while (l < r) {
    //         if (s[l] == s[r]) {
    //             // Characters match → move pointers inward
    //             l++;
    //             r--;
    //         } else {
    //             // First mismatch found
    //             if (cnt == 0) return false;  // Already used our 1 deletion

    //             // Option 1: Try deleting s[l] (skip left character)
    //             int l1 = l + 1, r1 = r;
    //             bool ok1 = true;
    //             while (l1 < r1) {
    //                 if (s[l1] != s[r1]) {  // Check if remaining is palindrome
    //                     ok1 = false;
    //                     break;
    //                 }
    //                 l1++;
    //                 r1--;  // Move pointers for this check
    //             }

    //             // Option 2: Try deleting s[r] (skip right character)
    //             int l2 = l, r2 = r - 1;
    //             bool ok2 = true;
    //             while (l2 < r2) {
    //                 if (s[l2] != s[r2]) {
    //                     ok2 = false;
    //                     break;
    //                 }
    //                 l2++;
    //                 r2--;
    //             }

    //             // Return true if EITHER deletion option makes a palindrome
    //             return ok1 || ok2;
    //         }
    //     }
    //     return true;  // No mismatches or deletions needed
    // }

    // Better Optimal Approach with two pointers and recursion
    // Check if substring s[l..r] forms a strict palindrome
    bool isPalindrome(const string& s, int l, int r) {
        while (l < r) {
            if (s[l] != s[r]) return false;  // Mismatch → not a palindrome
            l++;                             // Move left pointer inward
            r--;                             // Move right pointer inward
        }
        return true;  // All mirrored chars matched
    }

    bool validPalindrome(string s) {
        int l = 0, r = (int)s.size() - 1;  // Two pointers from both ends
        int cnt = 1;                       // Number of deletions allowed (at most 1)

        while (l < r) {
            if (s[l] == s[r]) {
                // Characters match → move both pointers towards center
                l++;
                r--;
            } else {
                // First mismatch encountered
                if (cnt == 0) return false;  // Already used our allowed deletion

                // Option 1: skip character at l → check s[l+1..r]
                // Option 2: skip character at r → check s[l..r-1]
                // If either range is a palindrome, we can fix by deleting at most one char
                return isPalindrome(s, l + 1, r) || isPalindrome(s, l, r - 1);
            }
        }
        // Completed without needing more than one deletion → valid
        return true;
    }
};
int main() {
    Solution sol;
    string s = "abbda";

    cout << sol.validPalindrome(s) << endl;

    return 0;
}