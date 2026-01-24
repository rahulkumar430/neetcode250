#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    bool checkInclusion(string s1, string s2) {
        // If s1 is longer than s2, no permutation is possible
        if (s1.size() > s2.size()) return false;

        // Frequency map for characters in s1
        unordered_map<char, int> freq1;

        // Frequency map for the current sliding window in s2
        unordered_map<char, int> freq2;

        // Build frequency map for s1
        for (char c : s1) {
            freq1[c]++;
        }

        int windowSize = s1.size();

        // Slide a window of size windowSize over s2
        for (int i = 0; i < s2.size(); i++) {
            // Add current character to the window
            freq2[s2[i]]++;

            // If window exceeds required size, remove leftmost character
            if (i >= windowSize) {
                char toRemove = s2[i - windowSize];
                freq2[toRemove]--;

                // Clean up map to keep comparisons accurate
                if (freq2[toRemove] == 0) {
                    freq2.erase(toRemove);
                }
            }

            // If frequency maps match, a permutation exists
            if (freq1 == freq2) {
                return true;
            }
        }

        // No permutation of s1 found in s2
        return false;
    }
};

int main() {
    string s1 = "abc";
    string s2 = "lecabee";

    Solution sol;
    cout << (sol.checkInclusion(s1, s2) ? "true" : "false") << endl;

    return 0;
}