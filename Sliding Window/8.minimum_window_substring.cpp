#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    // Helper function to check whether all characters of str2
    // are present in str1 with at least the same frequency
    // bool allCharsPresent(const string& str1, const string& str2) {
    //     // Frequency map for characters in str1
    //     unordered_map<char, int> counts1;

    //     // Frequency map for characters in str2
    //     unordered_map<char, int> counts2;

    //     // Count characters in str1
    //     for (char c : str1) {
    //         counts1[c]++;
    //     }

    //     // Count characters in str2
    //     for (char c : str2) {
    //         counts2[c]++;
    //     }

    //     // Check whether every character required by str2 exists in str1 with sufficient frequency
    //     for (auto const& [key, val] : counts2) {
    //         // Character missing in str1
    //         // or not enough occurrences
    //         if (counts1.find(key) == counts1.end() || counts1[key] < val) {
    //             return false;
    //         }
    //     }

    //     return true;
    // }

    // Brute-force solution for Minimum Window Substring
    // Time Complexity: O(N^3)
    // string minWindow(string s, string t) {
    //     // Stores the final minimum window substring
    //     string ans = "";

    //     // Stores the minimum length found so far
    //     int minLength = INT_MAX;

    //     // Choose the starting index of the substring
    //     for (int i = 0; i < s.length(); i++) {
    //         // Try all possible substring lengths starting from i
    //         for (int len = 1; len <= s.length() - i; len++) {
    //             // Extract substring s[i..i+len-1]
    //             string compare = s.substr(i, len);

    //             // Check if current substring contains all characters of t and update the answer if it is smaller
    //             if (allCharsPresent(compare, t) &&
    //                 minLength >= compare.length()) {
    //                 ans = compare;
    //                 minLength = compare.length();
    //             }
    //         }
    //     }

    //     // Return the minimum window substring (or empty string if none found)
    //     return ans;
    // }

    // Optimal Sliding Window approach for Minimum Window Substring
    // Time Complexity: O(N)
    string minWindow(string s, string t) {
        // Edge case: if t is longer than s, no valid window exists
        if (t.length() > s.length()) return "";

        // Frequency map for characters required from t
        unordered_map<char, int> need;
        for (char c : t) {
            need[c]++;
        }

        // Number of characters still needed to form a valid window
        int required = t.length();

        // Sliding window pointers
        int left = 0;

        // Stores the best window found
        int minLen = INT_MAX;
        int startIdx = 0;

        // Expand the window using the right pointer
        for (int right = 0; right < s.length(); right++) {
            // If current character is needed, reduce required count
            if (need[s[right]] > 0) {
                required--;
            }

            // Decrease frequency for current character
            need[s[right]]--;

            /*
            When required becomes 0, the current window
            contains all characters of t
            */
            while (required == 0) {
                // Update minimum window if smaller one is found
                if (right - left + 1 < minLen) {
                    minLen = right - left + 1;
                    startIdx = left;
                }

                // Try to shrink the window from the left
                need[s[left]]++;

                // If removing s[left] breaks the requirement,
                // increase required count
                if (need[s[left]] > 0) {
                    required++;
                }

                left++;
            }
        }

        // If no valid window was found, return empty string
        return minLen == INT_MAX ? "" : s.substr(startIdx, minLen);
    }
};

int main() {
    string s = "OUZODYXAZV";
    string t = "XYZ";

    Solution sol;

    cout << sol.minWindow(s, t) << endl;

    return 0;
}