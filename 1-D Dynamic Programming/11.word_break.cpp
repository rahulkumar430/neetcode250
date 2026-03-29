#include <bits/stdc++.h>
using namespace std;

// Brute Force Recusive Approach
// Time Complexity: O(2^n * n * m), Space Complexity: O(n), n = length of string s, m = size of wordDict
// class Solution {
//    public:
//     bool dfs(string s, vector<string>& wordDict, int index) {
//         if (index == s.size()) return true;  // Base Case

//         for (int i = index; i < s.size(); i++) {
//             // Check if the current substring is present in the dictionary
//             if (find(wordDict.begin(), wordDict.end(), s.substr(index, i - index + 1)) != wordDict.end()) {
//                 // If the substring is present, recursively call the dfs function for the remaining substring
//                 if (dfs(s, wordDict, i + 1)) return true;
//             }
//         }
//         return false;
//     }

//     bool wordBreak(string s, vector<string>& wordDict) {
//         return dfs(s, wordDict, 0);
//     }
// };

// Top Down DP Approach - Time Complexity: O(n^2), Space Complexity: O(n)
// class Solution {
//    public:
//     bool dfs(string& s, unordered_set<string>& dict, int index, vector<int>& dp) {
//         // Base case
//         if (index == s.size()) return true;

//         // If already computed
//         if (dp[index] != -1) return dp[index];

//         for (int i = index; i < s.size(); i++) {
//             string word = s.substr(index, i - index + 1);

//             // Check in dictionary
//             if (dict.count(word)) {
//                 if (dfs(s, dict, i + 1, dp)) {
//                     return dp[index] = true;
//                 }
//             }
//         }

//         return dp[index] = false;
//     }

//     bool wordBreak(string s, vector<string>& wordDict) {
//         unordered_set<string> dict(wordDict.begin(), wordDict.end());

//         vector<int> dp(s.size(), -1);  // -1 = not computed

//         return dfs(s, dict, 0, dp);
//     }
// };

// Bottom Up DP Approach - Time Complexity: O(n^2), Space Complexity: O(n)
class Solution {
   public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();

        unordered_set<string> dict(wordDict.begin(), wordDict.end());

        // dp[i] = can substring s[0..i-1] be segmented?
        vector<bool> dp(n + 1, false);

        // Base case: empty string is valid
        dp[0] = true;

        // Build dp from left → right
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j < i; j++) {
                // If prefix is valid AND substring exists in dict
                if (dp[j] && dict.count(s.substr(j, i - j))) {
                    dp[i] = true;
                    break;  // no need to check further
                }
            }
        }

        return dp[n];
    }
};

// Bottom-Up DP + Trie Optimization
// Time Complexity: O(n^2), Space Complexity: O(n + total chars in dictionary)
// class TrieNode {
//    public:
//     TrieNode* children[26];
//     bool isEnd;

//     TrieNode() {
//         isEnd = false;
//         for (int i = 0; i < 26; i++) children[i] = nullptr;
//     }
// };

// class Solution {
//    public:
//     // Insert word into Trie
//     void insert(TrieNode* root, string& word) {
//         TrieNode* node = root;
//         for (char c : word) {
//             int idx = c - 'a';
//             if (!node->children[idx]) {
//                 node->children[idx] = new TrieNode();
//             }
//             node = node->children[idx];
//         }
//         node->isEnd = true;
//     }

//     bool wordBreak(string s, vector<string>& wordDict) {
//         int n = s.size();

//         // Step 1: Build Trie
//         TrieNode* root = new TrieNode();
//         for (auto& word : wordDict) {
//             insert(root, word);
//         }

//         // dp[i] = can s[0..i-1] be segmented?
//         vector<bool> dp(n + 1, false);
//         dp[0] = true;

//         // Step 2: DP traversal
//         for (int i = 0; i < n; i++) {
//             // If prefix till i is not valid → skip
//             if (!dp[i]) continue;

//             TrieNode* node = root;

//             // Try extending from index i
//             for (int j = i; j < n; j++) {
//                 int idx = s[j] - 'a';

//                 // If path doesn't exist → break early
//                 if (!node->children[idx]) break;

//                 node = node->children[idx];

//                 // If we found a word ending here
//                 if (node->isEnd) {
//                     dp[j + 1] = true;
//                 }
//             }
//         }

//         return dp[n];
//     }
// };

int main() {
    string s = "applepenapple";
    vector<string> wordDict = {"apple", "pen", "ape"};

    Solution sol;
    cout << (sol.wordBreak(s, wordDict) ? "true" : "false") << endl;

    return 0;
}