#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    // Naive Approach by comparing each adjacent pair of words and checking their order based on the given alien dictionary
    // Time Complexity: O(n * m), Space Complexity: O(1), n = number of words, m = average length of words
    bool isAlienSorted(vector<string>& words, string order) {
        unordered_map<char, int> charToIndex;

        // Map each character to its rank in alien dictionary
        for (int i = 0; i < order.size(); i++) {
            charToIndex[order[i]] = i;
        }

        // Compare every adjacent pair
        for (int i = 1; i < words.size(); i++) {
            string word1 = words[i - 1];
            string word2 = words[i];

            // Compare up to the length of the shorter word
            int minLength = min(word1.size(), word2.size());
            bool isSorted = false;

            // Compare characters until first difference
            for (int j = 0; j < minLength; j++) {
                if (charToIndex[word1[j]] < charToIndex[word2[j]]) {
                    isSorted = true;  // Correct order
                    break;
                } else if (charToIndex[word1[j]] > charToIndex[word2[j]]) {
                    return false;  // Wrong order
                }
            }

            // Handle prefix case (e.g., "apple" vs "app"), Shorter word should come first
            if (!isSorted && word1.size() > word2.size()) {
                return false;
            }
        }

        return true;  // All pairs valid
    }

    // Using custom comparator
    // Time Complexity: O(n * m), Space Complexity: O(1), n = number of words, m = average length of words
    // bool isAlienSorted(vector<string>& words, string order) {
    //     // Map each character to its alien rank
    //     vector<int> rank(26);
    //     for (int i = 0; i < order.size(); i++) {
    //         rank[order[i] - 'a'] = i;
    //     }

    //     // Custom comparator for alien dictionary
    //     auto comp = [&](const string& a, const string& b) {
    //         int len = min(a.size(), b.size());

    //         for (int i = 0; i < len; i++) {
    //             if (a[i] != b[i]) {
    //                 return rank[a[i] - 'a'] < rank[b[i] - 'a'];
    //             }
    //         }

    //         // If all characters same till min length,
    //         // shorter word should come first
    //         return a.size() <= b.size();
    //     };

    //     // Check if already sorted using custom comparator
    //     return is_sorted(words.begin(), words.end(), comp);
    // }
};

int main() {
    vector<string> words = {"dag", "disk", "dog"};
    string order = "hlabcdefgijkmnopqrstuvwxyz";

    Solution sol;
    cout << (sol.isAlienSorted(words, order) ? "true" : "false") << endl;

    return 0;
}
