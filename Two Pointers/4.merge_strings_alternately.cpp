#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    string mergeAlternately(string word1, string word2) {
        int l1 = word1.length();  // Length of first string
        int l2 = word2.length();  // Length of second string
        string ans;               // Result string after merging
        int i = 0, j = 0;         // Pointers for word1 and word2

        // Continue while there are characters left in either string
        while (i < l1 || j < l2) {
            if (i < l1) ans += word1[i++];  // Take next char from word1 if available
            if (j < l2) ans += word2[j++];  // Then take next char from word2 if available
        }

        return ans;  // Return merged string
    }

    // string mergeAlternately(string word1, string word2) {
    //     string ans;        // result string to store merged characters
    //     int i = 0, j = 0;  // Pointers for word1 and word2

    //     // Take characters alternately while both strings have remaining characters
    //     while (i < word1.size() && j < word2.size()) {
    //         ans += word1[i++];  // Append next character from word1
    //         ans += word2[j++];  // Append next character from word2
    //     }

    //     // Append any remaining characters from word1 (if word1 is longer)
    //     ans += word1.substr(i);

    //     // Append any remaining characters from word2 (if word2 is longer)
    //     ans += word2.substr(j);

    //     return ans;  // Return the merged string
    // }
};
int main() {
    Solution sol;
    string s1 = "abc";
    string s2 = "xyz";

    cout << sol.mergeAlternately(s1, s2) << endl;

    return 0;
}