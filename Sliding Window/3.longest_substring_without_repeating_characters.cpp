#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    // Brute force approach: O(N^3) Time and O(N) Space complexity
    // int lengthOfLongestSubstring(string s) {
    //     int n = s.length();
    //     int ans = 0;

    //     // Check all substrings
    //     for (int i = 0; i < n; i++) {
    //         for (int j = i; j < n; j++) {
    //             unordered_set<char> seen;
    //             bool valid = true;

    //             // Check if substring s[i..j] has all unique characters
    //             for (int k = i; k <= j; k++) {
    //                 if (seen.count(s[k])) {
    //                     valid = false;
    //                     break;
    //                 }
    //                 seen.insert(s[k]);
    //             }

    //             if (valid) {
    //                 ans = max(ans, j - i + 1);
    //             }
    //         }
    //     }

    //     return ans;
    // }

    // Optimised approach: O(N) Time and O(min(N, character_set_size)) Space complexity
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> window;
        int l = 0, r = 0, ans = 0;

        while (r < s.length()) {
            // If duplicate found, shrink window from left
            while (window.count(s[r])) {
                window.erase(s[l]);
                l++;
            }

            // Add current character
            window.insert(s[r]);

            // Update answer
            ans = max(ans, r - l + 1);

            // Expand window
            r++;
        }

        return ans;
    }
};

int main() {
    string s = "zxyzxyz";

    Solution sol;
    cout << sol.lengthOfLongestSubstring(s) << endl;

    return 0;
}