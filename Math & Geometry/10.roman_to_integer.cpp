#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    // Naive Approach : Time Complexity: O(N) , Space Complexity: O(1)
    // int romanToInt(string s) {
    //     unordered_map<char, int> m = {
    //         {'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}};

    //     int ans = 0;
    //     int i = 0;

    //     while (i < s.length()) {
    //         // Check whether the next character exists
    //         if (i + 1 < s.length() &&
    //             ((s[i] == 'I' && (s[i + 1] == 'V' || s[i + 1] == 'X')) ||
    //              (s[i] == 'X' && (s[i + 1] == 'L' || s[i + 1] == 'C')) ||
    //              (s[i] == 'C' && (s[i + 1] == 'D' || s[i + 1] == 'M')))) {
    //             ans += m[s[i + 1]] - m[s[i]];
    //             i += 2;
    //         } else {
    //             ans += m[s[i]];
    //             i++;
    //         }
    //     }

    //     return ans;
    // }

    // Optimized Approach : Time Complexity: O(N), Space Complexity: O(1)
    int romanToInt(string s) {
        unordered_map<char, int> m = {
            {'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}};

        int ans = 0;

        for (int i = 0; i < s.length(); i++) {
            // Subtract if current value is smaller than next value, else add it
            if (i + 1 < s.length() && m[s[i]] < m[s[i + 1]]) {
                ans -= m[s[i]];
            } else {
                ans += m[s[i]];
            }
        }

        return ans;
    }
};

int main() {
    Solution s;
    string str = "XLIX";

    cout << s.romanToInt(str) << endl;

    return 0;
}