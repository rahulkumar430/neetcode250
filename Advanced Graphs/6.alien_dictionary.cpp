#include <bits/stdc++.h>
using namespace std;

// DFS Approach with Backtracking - Time Complexity: O(N + V + E), Space Complexity: O(V + E)
// class Solution {
//    public:
//     string result;

//     bool dfs(char ch, unordered_map<char, unordered_set<char>>& adj, unordered_map<char, bool>& visited) {
//         // If the character has already been visited, return the status
//         if (visited.find(ch) != visited.end()) {
//             return visited[ch];
//         }

//         // Mark the character as visited
//         visited[ch] = true;

//         // Iterate over all the adjacent characters of the current character
//         for (char next : adj[ch]) {
//             if (dfs(next, adj, visited)) {
//                 return true;
//             }
//         }

//         // Backtrack and mark the character as unvisited
//         visited[ch] = false;

//         // Add the character to the result string
//         result.push_back(ch);

//         // Return false to indicate that the character cannot form a valid foreign dictionary
//         return false;
//     }

//     // Function to find a valid foreign dictionary
//     string foreignDictionary(vector<string>& words) {
//         // Create an adjacency list to store the adjacency information of each character
//         unordered_map<char, unordered_set<char>> adj;
//         unordered_map<char, bool> visited;

//         // Iterate over all the words in the given vector
//         for (const auto& word : words) {
//             // Iterate over all the characters in the current word
//             for (char ch : word) {
//                 // Add the character to the adjacency list
//                 adj[ch];
//             }
//         }

//         // Iterate over all the words in the given vector
//         for (int i = 0; i < words.size() - 1; ++i) {
//             const string &word1 = words[i], &word2 = words[i + 1];
//             int minLen = min(word1.length(), word2.length());

//             // Check if the current word is a prefix of the next word
//             if (word1.length() > word2.length() &&
//                 word1.substr(0, minLen) == word2.substr(0, minLen)) {
//                 return "";
//             }

//             // Iterate over all the characters in the current word and the next word
//             for (int j = 0; j < minLen; ++j) {
//                 // Check if the characters at the current index are different
//                 if (word1[j] != word2[j]) {
//                     adj[word1[j]].insert(word2[j]);
//                     break;
//                 }
//             }
//         }

//         // Iterate over all the characters in the adjacency list
//         for (const auto& pair : adj) {
//             if (dfs(pair.first, adj, visited)) {
//                 return "";
//             }
//         }

//         // Reverse the result string
//         reverse(result.begin(), result.end());

//         return result;
//     }
// };

// DFS (Topological sort + Cycle detection)- Time Complexity: O(C + V + E), Space Complexity: O(V + E), C = total number of characters
// 0 = unvisited, 1 = visiting(cycle detection), 2 = visited
// class Solution {
//    public:
//     // DFS function for topological sort
//     bool dfs(int node, vector<vector<int>>& graph, vector<int>& state, string& result) {
//         // If currently visiting → cycle detected
//         if (state[node] == 1) return false;

//         // If already processed → skip
//         if (state[node] == 2) return true;

//         // Mark as visiting
//         state[node] = 1;

//         // Visit all neighbors
//         for (int nei : graph[node]) {
//             if (!dfs(nei, graph, state, result))
//                 return false;
//         }

//         // Mark as visited
//         state[node] = 2;

//         // Add to result (postorder)
//         result.push_back(node + 'a');

//         return true;
//     }

//     string foreignDictionary(vector<string>& words) {
//         vector<vector<int>> graph(26);    // adjacency list
//         vector<bool> present(26, false);  // track used characters

//         // Step 1: mark all characters present
//         for (auto& word : words) {
//             for (char c : word)
//                 present[c - 'a'] = true;
//         }

//         // Step 2: build graph
//         for (int i = 0; i < words.size() - 1; i++) {
//             string& w1 = words[i];
//             string& w2 = words[i + 1];

//             // invalid case: prefix issue
//             if (w1.size() > w2.size() && w1.substr(0, w2.size()) == w2)
//                 return "";

//             for (int j = 0; j < min(w1.size(), w2.size()); j++) {
//                 if (w1[j] != w2[j]) {
//                     // edge: w1[j] → w2[j]
//                     graph[w1[j] - 'a'].push_back(w2[j] - 'a');
//                     break;
//                 }
//             }
//         }

//         // Step 3: DFS topo sort
//         vector<int> state(26, 0);  // 0=unvisited, 1=visiting, 2=visited
//         string result;

//         for (int i = 0; i < 26; i++) {
//             if (present[i] && state[i] == 0) {
//                 if (!dfs(i, graph, state, result))
//                     return "";  // cycle detected
//             }
//         }

//         // reverse because we used postorder DFS
//         reverse(result.begin(), result.end());

//         return result;
//     }
// };

// BFS(Kahn’s Algorithm) - Time Complexity: O(C + V + E), Space Complexity: O(V + E), C = total number of characters
class Solution {
   public:
    string foreignDictionary(vector<string>& words) {
        // Step 1: Build graph
        unordered_map<char, unordered_set<char>> adj;
        unordered_map<char, int> indegree;

        // Initialize all characters
        for (auto& word : words) {
            for (char c : word) {
                adj[c];           // ensure node exists
                indegree[c] = 0;  // initialize indegree
            }
        }

        // Step 2: Build edges
        for (int i = 0; i < words.size() - 1; i++) {
            string& w1 = words[i];
            string& w2 = words[i + 1];

            int minLen = min(w1.size(), w2.size());

            // invalid case: prefix issue
            if (w1.size() > w2.size() && w1.substr(0, minLen) == w2.substr(0, minLen)) {
                return "";
            }

            for (int j = 0; j < minLen; j++) {
                if (w1[j] != w2[j]) {
                    // Add edge w1[j] → w2[j]
                    if (!adj[w1[j]].count(w2[j])) {
                        adj[w1[j]].insert(w2[j]);

                        // Increase indegree of destination
                        indegree[w2[j]]++;
                    }

                    break;  // ONLY first mismatch matters
                }
            }
        }

        // Step 3: Push all nodes with indegree = 0
        queue<char> q;

        for (auto& [ch, deg] : indegree) {
            if (deg == 0) {
                q.push(ch);
            }
        }

        // Step 4: BFS
        string result;

        while (!q.empty()) {
            char curr = q.front();
            q.pop();

            // Add to result
            result.push_back(curr);

            // Reduce indegree of neighbors
            for (char nei : adj[curr]) {
                indegree[nei]--;

                // If no more dependencies → push to queue
                if (indegree[nei] == 0) {
                    q.push(nei);
                }
            }
        }

        // Step 5: Cycle detection
        // If result doesn't contain all characters → cycle exists
        if (result.size() != adj.size()) {
            return "";
        }

        return result;
    }
};

int main() {
    vector<string> words = {"hrn", "hrf", "er", "enn", "rfnn"};

    Solution sol;
    cout << sol.foreignDictionary(words) << endl;
    return 0;
}