#include <bits/stdc++.h>
using namespace std;

// DFS Brute Force Approach - Time Complexity: O(N^2 * M), Space Complexity: O(N * M), N = number of words, M = length of each word
// class Solution {
//    public:
//     // Returns true if word1 and word2 differ by exactly one character
//     bool oneCharDiff(const string& word1, const string& word2) {
//         int diffCount = 0;

//         for (int i = 0; i < word1.size(); i++) {
//             if (word1[i] != word2[i]) {
//                 diffCount++;

//                 // If more than one difference, stop early
//                 if (diffCount > 1)
//                     return false;
//             }
//         }

//         // Exactly one character must differ
//         return diffCount == 1;
//     }

//     // DFS helper to explore all transformation paths
//     void dfs(int node, int depth, int endIndex, vector<vector<int>>& graph, vector<bool>& visited, int& minSteps) {
//         // If we reached endWord
//         if (node == endIndex) {
//             minSteps = min(minSteps, depth);
//             return;
//         }

//         // Explore neighbors
//         for (int neighbor : graph[node]) {
//             if (!visited[neighbor]) {
//                 visited[neighbor] = true;

//                 dfs(neighbor, depth + 1, endIndex, graph, visited, minSteps);

//                 // Backtrack so other paths can reuse this node
//                 visited[neighbor] = false;
//             }
//         }
//     }

//     int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
//         // Check if endWord exists
//         if (find(wordList.begin(), wordList.end(), endWord) == wordList.end())
//             return 0;

//         // Add beginWord to simplify graph building
//         wordList.push_back(beginWord);

//         int n = wordList.size();

//         // Build adjacency list
//         vector<vector<int>> graph(n);

//         for (int i = 0; i < n; i++) {
//             for (int j = i + 1; j < n; j++) {
//                 if (oneCharDiff(wordList[i], wordList[j])) {
//                     graph[i].push_back(j);
//                     graph[j].push_back(i);
//                 }
//             }
//         }

//         int beginIndex = n - 1;
//         int endIndex = find(wordList.begin(), wordList.end(), endWord) - wordList.begin();

//         vector<bool> visited(n, false);

//         int minSteps = INT_MAX;

//         visited[beginIndex] = true;

//         // Run DFS to explore all paths
//         dfs(beginIndex, 1, endIndex, graph, visited, minSteps);

//         if (minSteps == INT_MAX)
//             return 0;

//         return minSteps;
//     }
// };

// BFS Brute Force Approach
// Time Complexity: O(N^2 * M), Space Complexity: O(N * M), N = number of words, M = length of each word
// class Solution {
//    public:
//     // Returns true if word1 and word2 differ by exactly one character
//     bool oneCharDiff(const string& word1, const string& word2) {
//         int diffCount = 0;

//         for (int i = 0; i < word1.size(); i++) {
//             if (word1[i] != word2[i]) {
//                 diffCount++;

//                 // If more than one difference, stop early
//                 if (diffCount > 1)
//                     return false;
//             }
//         }

//         // Exactly one character must be different
//         return diffCount == 1;
//     }
//     int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
//         // Check if endWord is in the wordList
//         if (find(wordList.begin(), wordList.end(), endWord) == wordList.end())
//             return 0;

//         // Add beginWord to the wordList for easier processing
//         wordList.push_back(beginWord);
//         int n = wordList.size();

//         // Create an adjacency list for the graph
//         vector<vector<int>> graph(n);
//         for (int i = 0; i < n; i++) {
//             for (int j = i + 1; j < n; j++) {
//                 if (oneCharDiff(wordList[i], wordList[j])) {
//                     graph[i].push_back(j);
//                     graph[j].push_back(i);
//                 }
//             }
//         }

//         // Perform BFS to find the shortest path from beginWord to endWord
//         queue<pair<int, int>> q;  // pair of (index, depth)
//         vector<bool> visited(n, false);
//         int beginIndex = n - 1;  // index of beginWord

//         q.push({beginIndex, 1});
//         visited[beginIndex] = true;

//         while (!q.empty()) {
//             auto [currentIndex, depth] = q.front();
//             q.pop();

//             if (wordList[currentIndex] == endWord)
//                 return depth;

//             // Explore neighbors
//             for (int neighbor : graph[currentIndex]) {
//                 if (!visited[neighbor]) {
//                     visited[neighbor] = true;
//                     q.push({neighbor, depth + 1});
//                 }
//             }
//         }

//         return 0;  // No transformation found
//     }
// };

// Optimized BFS using wildcard hashing
// Time Complexity: O(N * M^2), Space Complexity: O(N * M), N = number of words, M = length of each word
// class Solution {
//    public:
//     int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
//         // Check if endWord exists
//         if (find(wordList.begin(), wordList.end(), endWord) == wordList.end())
//             return 0;

//         int wordLen = beginWord.size();

//         // Map pattern -> list of words
//         unordered_map<string, vector<string>> patternMap;

//         // Add beginWord to word list
//         wordList.push_back(beginWord);

//         // Build pattern map
//         for (string& word : wordList) {
//             for (int i = 0; i < wordLen; i++) {
//                 string pattern = word;
//                 pattern[i] = '*';

//                 patternMap[pattern].push_back(word);
//             }
//         }

//         // BFS queue: {word, depth}
//         queue<pair<string, int>> q;

//         unordered_set<string> visited;

//         q.push({beginWord, 1});
//         visited.insert(beginWord);

//         while (!q.empty()) {
//             auto [word, depth] = q.front();
//             q.pop();

//             // If we reach endWord
//             if (word == endWord)
//                 return depth;

//             // Generate patterns
//             for (int i = 0; i < wordLen; i++) {
//                 string pattern = word;
//                 pattern[i] = '*';

//                 // Check all neighbors
//                 for (string& neighbor : patternMap[pattern]) {
//                     if (!visited.count(neighbor)) {
//                         visited.insert(neighbor);
//                         q.push({neighbor, depth + 1});
//                     }
//                 }
//             }
//         }

//         return 0;
//     }
// };

// Bidirectional BFS solution
// Time Complexity: O(N * M^2), Space Complexity: O(N * M), N = number of words, M = length of each word
class Solution {
   public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> wordSet(wordList.begin(), wordList.end());

        // If endWord not in dictionary
        if (!wordSet.count(endWord))
            return 0;

        // Two search fronts
        unordered_set<string> beginSet;
        unordered_set<string> endSet;

        beginSet.insert(beginWord);
        endSet.insert(endWord);

        int length = 1;
        int wordLen = beginWord.size();

        while (!beginSet.empty() && !endSet.empty()) {
            // Always expand the smaller set
            if (beginSet.size() > endSet.size())
                swap(beginSet, endSet);

            unordered_set<string> nextLevel;

            for (string word : beginSet) {
                for (int i = 0; i < wordLen; i++) {
                    string temp = word;

                    // Try all possible one character transformations
                    for (char c = 'a'; c <= 'z'; c++) {
                        temp[i] = c;

                        // If searches meet
                        if (endSet.count(temp))
                            return length + 1;

                        if (wordSet.count(temp)) {
                            nextLevel.insert(temp);
                            wordSet.erase(temp);
                        }
                    }
                }
            }

            // Move to next level
            beginSet = nextLevel;
            length++;
        }

        return 0;
    }
};

int main() {
    string beginWord = "cat";
    string endWord = "sag";
    vector<string> wordList = {"bat", "bag", "sag", "dag", "dot"};

    Solution sol;
    cout << sol.ladderLength(beginWord, endWord, wordList) << endl;

    return 0;
}