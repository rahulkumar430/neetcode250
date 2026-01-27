#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    // Brute force approach: O(N^2) Time and O(min(N, unique_character_set_size)) Space complexity
    // int characterReplacement(string s, int k) {
    //     // Stores the maximum valid substring length found
    //     int ans = 0;

    //     // Fix the starting index of the substring
    //     for (int i = 0; i < s.size(); i++) {
    //         // Frequency map for characters in the current window
    //         unordered_map<char, int> count;

    //         // Maximum frequency of any character in the current window
    //         int maxFreq = 0;

    //         // Extend the substring from index i to j
    //         for (int j = i; j < s.size(); j++) {
    //             // Update frequency of the current character
    //             count[s[j]]++;

    //             // Track the most frequent character in the window
    //             maxFreq = max(maxFreq, count[s[j]]);

    //             /*
    //             If the number of characters to replace
    //             (window length - max frequency)
    //             is within k, update the result
    //             */
    //             if ((j - i + 1) - maxFreq <= k) {
    //                 ans = max(ans, j - i + 1);
    //             }
    //         }
    //     }

    //     return ans;
    // }

    // Optimised Approach : O(N) Time and O(1) Space complexity as max characters will be 26 and O(N*26) will be still O(N)
    // int characterReplacement(std::string s, int k) {
    //     // Stores the maximum length of a valid substring
    //     int ans = 0;

    //     /*
    //     Collect all unique characters in the string.
    //     We will treat each character as a potential
    //     target character to convert the window into.
    //     */
    //     unordered_set<char> charSet(s.begin(), s.end());

    //     // Try making the substring all of one character at a time
    //     for (char c : charSet) {
    //         int count = 0;  // Count of character 'c' in the current window
    //         int l = 0;      // Left pointer of the sliding window

    //         // Expand the window using the right pointer
    //         for (int r = 0; r < s.size(); r++) {
    //             // Increase count if current character matches target
    //             if (s[r] == c) {
    //                 count++;
    //             }

    //             /*
    //             If replacements needed exceed k,
    //             shrink the window from the left
    //             */
    //             while ((r - l + 1) - count > k) {
    //                 if (s[l] == c) {
    //                     count--;
    //                 }
    //                 l++;
    //             }

    //             // Update the maximum valid window length
    //             ans = max(ans, r - l + 1);
    //         }
    //     }

    //     return ans;
    // }

    // Sliding Window (Optimal) solution
    // Time Complexity : O(N)
    // Space Complexity: O(Σ) → O(1) for fixed alphabet (e.g., uppercase letters)
    int characterReplacement(std::string s, int k) {
        // Frequency map of characters in the current window
        unordered_map<char, int> count;

        int ans = 0;   // Stores the maximum valid window length
        int l = 0;     // Left pointer of the sliding window
        int maxf = 0;  // Maximum frequency of any character in the current window

        // Expand the window using the right pointer
        for (int r = 0; r < s.size(); r++) {
            // Update frequency of the current character
            count[s[r]]++;

            // Track the highest frequency seen in the window
            maxf = max(maxf, count[s[r]]);

            /*
            If replacements needed exceed k,
            shrink the window from the left
            */
            while ((r - l + 1) - maxf > k) {
                count[s[l]]--;
                l++;
            }

            // Update the maximum window length
            ans = max(ans, r - l + 1);
        }

        return ans;
    }
};

int main() {
    string s = "XYYX";
    int k = 2;

    Solution sol;

    cout << sol.characterReplacement(s, k) << endl;

    return 0;
}