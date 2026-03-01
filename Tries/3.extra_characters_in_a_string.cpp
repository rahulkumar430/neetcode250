#include <bits/stdc++.h>
using namespace std;

// Recursion approach
// Time Complexity: O(n * 2^n), Space Complexity: O(n)
// class Solution {
//    public:
//     int dfs(string s, unordered_set<string>& dict, int index) {
//         if (index == s.size()) return 0;

//         int ans = 1 + dfs(s, dict, index + 1);  // treat current char as extra

//         for (int i = index; i < s.size(); i++) {
//             string sub = s.substr(index, i - index + 1);
//             if (dict.count(sub)) {
//                 ans = min(ans, dfs(s, dict, i + 1));
//             }
//         }

//         return ans;
//     }

//     int minExtraChar(string s, vector<string>& dictionary) {
//         unordered_set<string> dict(dictionary.begin(), dictionary.end());
//         return dfs(s, dict, 0);
//     }
// };

// Top-down DP approach with memoization
// Time Complexity: O(n^3), Space Complexity: O(n)
// class Solution {
//    public:
//     int dfs(int i, string& s, unordered_set<string>& dict, vector<int>& dp) {
//         if (i == s.length())
//             return 0;

//         if (dp[i] != -1)
//             return dp[i];

//         // Option 1: treat current char as extra
//         int ans = 1 + dfs(i + 1, s, dict, dp);

//         // Option 2: match dictionary words
//         for (int j = i; j < s.length(); j++) {
//             string sub = s.substr(i, j - i + 1);
//             if (dict.count(sub)) {
//                 ans = min(ans, dfs(j + 1, s, dict, dp));
//             }
//         }

//         return dp[i] = ans;
//     }

//     int minExtraChar(string s, vector<string>& dictionary) {
//         unordered_set<string> dict(dictionary.begin(), dictionary.end());
//         vector<int> dp(s.length(), -1);
//         return dfs(0, s, dict, dp);
//     }
// };

// Most Optimal Top-down DP + Trie Approach
// Time Complexity: O(n^2), Space Complexity: O(n * m) where m is the average length of words in the dictionary
class Solution {
   public:
    struct TrieNode {
        TrieNode* children[26];
        bool isEnd;

        TrieNode() {
            isEnd = false;
            for (int i = 0; i < 26; i++)
                children[i] = nullptr;
        }
    };

    // Function to insert a word into the trie
    // Time Complexity: O(m) where m is the length of the word
    void insert(TrieNode* root, string& word) {
        TrieNode* node = root;
        for (char c : word) {
            int idx = c - 'a';
            if (!node->children[idx])
                node->children[idx] = new TrieNode();
            node = node->children[idx];
        }
        node->isEnd = true;
    }

    int dfs(int i, string& s, TrieNode* root, vector<int>& dp) {
        if (i == s.length())
            return 0;

        if (dp[i] != -1)
            return dp[i];

        // Option 1: treat as extra
        int ans = 1 + dfs(i + 1, s, root, dp);

        // Option 2: traverse trie
        TrieNode* node = root;
        for (int j = i; j < s.length(); j++) {
            int idx = s[j] - 'a';

            if (!node->children[idx])
                break;  // no further match possible

            node = node->children[idx];

            if (node->isEnd) {
                ans = min(ans, dfs(j + 1, s, root, dp));
            }
        }

        return dp[i] = ans;
    }

    int minExtraChar(string s, vector<string>& dictionary) {
        TrieNode* root = new TrieNode();

        for (string& word : dictionary)
            insert(root, word);

        vector<int> dp(s.length(), -1);

        return dfs(0, s, root, dp);
    }
};

int main() {
    string s = "neetcodde";
    vector<string> dictionary = {"neet", "code", "neetcode"};

    Solution sol;
    cout << sol.minExtraChar(s, dictionary) << endl;

    return 0;
}