#include <bits/stdc++.h>
using namespace std;

// Recursion Approach
// Time Complexity: O(N * 2^N), Space Complexity: O(N) , For Output : O(N * 2^N)
// class Solution {
//    private:
//     vector<string> result;

//     void backtrack(int start, string& s, unordered_set<string>& dict, string current) {
//         // Base case: reached end of string
//         if (start == s.length()) {
//             // remove trailing space
//             current.pop_back();
//             result.push_back(current);
//             return;
//         }

//         // Try every possible substring starting at 'start'
//         for (int end = start; end < s.length(); end++) {
//             string word = s.substr(start, end - start + 1);

//             // If substring exists in dictionary
//             if (dict.count(word)) {
//                 // Choose
//                 backtrack(end + 1, s, dict, current + word + " ");

//                 // No need to manually undo because current is passed by value
//             }
//         }
//     }

//    public:
//     vector<string> wordBreak(string s, vector<string>& wordDict) {
//         unordered_set<string> dict(wordDict.begin(), wordDict.end());

//         backtrack(0, s, dict, "");

//         return result;
//     }
// };

// Backtracking Approach
// Time Complexity: O(N * 2^N), Space Complexity: O(N) , For Output : O(N * 2^N)
// class Solution {
//    private:
//     vector<string> result;

//     void backtrack(int start, string& s, unordered_set<string>& dict, vector<string>& path) {
//         // Base case
//         if (start == s.length()) {
//             // Join words in path into a sentence
//             string sentence = "";
//             for (int i = 0; i < path.size(); i++) {
//                 sentence += path[i];
//                 if (i != path.size() - 1)
//                     sentence += " ";
//             }

//             result.push_back(sentence);
//             return;
//         }

//         // Try every possible substring
//         for (int end = start; end < s.length(); end++) {
//             string word = s.substr(start, end - start + 1);

//             if (dict.count(word)) {
//                 // Choose
//                 path.push_back(word);

//                 // Explore
//                 backtrack(end + 1, s, dict, path);

//                 // Undo
//                 path.pop_back();
//             }
//         }
//     }

//    public:
//     vector<string> wordBreak(string s, vector<string>& wordDict) {
//         unordered_set<string> dict(wordDict.begin(), wordDict.end());

//         vector<string> path;
//         backtrack(0, s, dict, path);

//         return result;
//     }
// };

// Optimised DFS + Memoization (Top-Down DP) Approach
// Time Complexity: O(N^2 + K × N)
// Space Complexity: O(N) & For Output : O(K × N), K = number of valid sentences, N = string length
class Solution {
   private:
    unordered_map<int, vector<string>> memo;

    vector<string> dfs(int start, string& s, unordered_set<string>& dict) {
        // If already computed, return cached result
        if (memo.count(start))
            return memo[start];

        vector<string> sentences;

        // Base case: reached end
        if (start == s.length()) {
            sentences.push_back("");  // Important!
            return sentences;
        }

        for (int end = start; end < s.length(); end++) {
            string word = s.substr(start, end - start + 1);

            if (dict.count(word)) {
                vector<string> subSentences = dfs(end + 1, s, dict);

                for (string sub : subSentences) {
                    if (sub.empty())
                        sentences.push_back(word);
                    else
                        sentences.push_back(word + " " + sub);
                }
            }
        }

        // Store in memo before returning
        memo[start] = sentences;
        return sentences;
    }

   public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> dict(wordDict.begin(), wordDict.end());
        memo.clear();

        return dfs(0, s, dict);
    }
};

int main() {
    string s = "racecariscar";
    vector<string> wordDict = {"racecar", "race", "car", "is"};

    Solution sol;
    vector<string> ans = sol.wordBreak(s, wordDict);

    for (string str : ans)
        cout << str << endl;

    return 0;
}