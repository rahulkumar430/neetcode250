#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    // Brute Force Approach - Time Complexity : O((m + n) * min(m, n)), Space Complexity : O(min(m, n))
    string gcdOfStrings(string str1, string str2) {
        int l1 = str1.length();
        int l2 = str2.length();

        // Try every possible prefix, starting from the longest.
        for (int l = min(l1, l2); l >= 1; l--) {
            // A valid base string must divide both string lengths.
            if (l1 % l != 0 || l2 % l != 0)
                continue;

            string candidate = str1.substr(0, l);

            bool valid = true;

            // Check if str1 is made by repeating candidate.
            for (int i = 0; i < l1; i++) {
                if (str1[i] != candidate[i % l]) {
                    valid = false;
                    break;
                }
            }

            // Check if str2 is made by repeating candidate.
            if (valid) {
                for (int i = 0; i < l2; i++) {
                    if (str2[i] != candidate[i % l]) {
                        valid = false;
                        break;
                    }
                }
            }

            if (valid)
                return candidate;
        }

        return "";
    }

    // If a common divisor string exists, then concatenating the two strings in either order must produce the same
    // result: str1 + str2 == str2 + str1. This is because both strings are built from the same repeating pattern.
    // Once verified, the GCD of the two string lengths gives us the length of the largest common divisor.
    // Mathemnatical Approach - Time Complexity : O(m + n), Space Complexity : O(m + n)
    string gcdOfStrings(string str1, string str2) {
        if (str1 + str2 != str2 + str1) {
            return "";
        }
        int l = gcd((int)str1.size(), (int)str2.size());
        return str1.substr(0, l);
    }

    // Space Optimised Mathemnatical Approach - Time Complexity : O(m + n), Space Complexity : O(l)
    string gcdOfStrings(string str1, string str2) {
        int l = gcd((int)str1.size(), (int)str2.size());

        for (int i = 0; i < str1.size(); i++) {
            if (str1[i] != str1[i % l]) {
                return "";
            }
        }

        for (int i = 0; i < str2.size(); i++) {
            if (str2[i] != str1[i % l]) {
                return "";
            }
        }

        return str1.substr(0, l);
    }
};

int main() {
    Solution s;
    string str1 = "NANANA";
    string str2 = "NANA";

    cout << s.gcdOfStrings(str1, str2) << endl;
    return 0;
}