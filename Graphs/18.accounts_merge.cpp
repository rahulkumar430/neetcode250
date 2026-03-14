#include <bits/stdc++.h>
using namespace std;

// DFS Approach - Time Complexity: O(N log N), Space Complexity: O(N), N = total number of emails
// class Solution {
//    public:
//     void dfs(string email, unordered_map<string, vector<string>>& graph,
//              unordered_set<string>& visited, vector<string>& component) {
//         visited.insert(email);       // Mark the email as visited
//         component.push_back(email);  // Add the email to the current component

//         // Explore all neighboring emails
//         for (string& neigh : graph[email]) {
//             // If the neighboring email has not been visited, perform DFS on it
//             if (!visited.count(neigh))
//                 dfs(neigh, graph, visited, component);
//         }
//     }

//     vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
//         unordered_map<string, vector<string>> graph;
//         unordered_map<string, string> emailToName;

//         // Build adjacency list and email to name mapping
//         for (auto& acc : accounts) {
//             string name = acc[0];

//             for (int i = 1; i < acc.size(); i++) {
//                 emailToName[acc[i]] = name;  // Map email to name

//                 if (i == 1) continue;  // Skip the first email as it has no previous email to connect to

//                 graph[acc[i]].push_back(acc[i - 1]);  // Connect current email to previous email
//                 graph[acc[i - 1]].push_back(acc[i]);  // Connect previous email to current email
//             }
//         }

//         unordered_set<string> visited;
//         vector<vector<string>> result;

//         // DFS on each email
//         for (auto& [email, name] : emailToName) {
//             if (visited.count(email))
//                 continue;

//             vector<string> component;

//             dfs(email, graph, visited, component);

//             sort(component.begin(), component.end());  // Sort emails in the component

//             component.insert(component.begin(), name);  // Insert the name at the beginning of the component

//             result.push_back(component);
//         }

//         return result;
//     }
// };

// BFS Approach - Time Complexity: O(N log N), Space Complexity: O(N), N = total number of emails
// class Solution {
//    public:
//     vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
//         unordered_map<string, vector<string>> graph;
//         unordered_map<string, string> emailToName;

//         // Build adjacency list and email to name mapping
//         for (auto& acc : accounts) {
//             string name = acc[0];

//             for (int i = 1; i < acc.size(); i++) {
//                 emailToName[acc[i]] = name;  // Map email to name

//                 if (i == 1) continue;  // Skip the first email as it has no previous email to connect to

//                 graph[acc[i]].push_back(acc[i - 1]);  // Connect current email to previous email
//                 graph[acc[i - 1]].push_back(acc[i]);  // Connect previous email to current email
//             }
//         }

//         unordered_set<string> visited;
//         vector<vector<string>> result;

//         // BFS on each email
//         for (auto& [email, name] : emailToName) {
//             if (visited.count(email))
//                 continue;

//             queue<string> q;
//             vector<string> component;

//             q.push(email);
//             visited.insert(email);  // Mark the email as visited

//             while (!q.empty()) {
//                 string node = q.front();
//                 q.pop();

//                 component.push_back(node);  // Add the email to the current component

//                 // Explore all neighboring emails
//                 for (string& neigh : graph[node]) {
//                     // If the neighboring email has not been visited, add to queue
//                     if (!visited.count(neigh)) {
//                         visited.insert(neigh);  // Mark neighbor as visited
//                         q.push(neigh);
//                     }
//                 }
//             }

//             sort(component.begin(), component.end());   // Sort emails in the component
//             component.insert(component.begin(), name);  // Insert the name at the beginning of the component

//             result.push_back(component);
//         }

//         return result;
//     }
// };

// Union-Find Approach - Time Complexity: O(N log N), Space Complexity: O(N), N = total number of emails
class Solution {
   public:
    // Find parent with path compression
    int find(int x, vector<int>& parent) {
        // If x is its own parent, return x as the root parent
        if (parent[x] == x)
            return parent[x];
        // Path compression optimization: directly connect x to its root parent
        return parent[x] = find(parent[x], parent);
    }

    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size();

        vector<int> parent(n);
        for (int i = 0; i < n; i++)
            parent[i] = i;

        unordered_map<string, int> emailToAccount;

        // Step 1: union accounts sharing emails
        for (int i = 0; i < n; i++) {
            for (int j = 1; j < accounts[i].size(); j++) {
                string email = accounts[i][j];

                if (emailToAccount.count(email)) {
                    int pa = find(i, parent);                      // Find parent of current account
                    int pb = find(emailToAccount[email], parent);  // Find parent of the account that has this email

                    if (pa != pb)
                        parent[pb] = pa;  // Union: merge the two sets by updating parent

                } else {
                    emailToAccount[email] = i;  // Map email to current account index
                }
            }
        }

        // Step 2: group emails by root account
        unordered_map<int, vector<string>> merged;

        for (auto& it : emailToAccount) {
            string email = it.first;
            int acc = it.second;

            int root = find(acc, parent);  // Find the representative/root of this account

            merged[root].push_back(email);  // Group email under its root account
        }

        // Step 3: build result
        vector<vector<string>> result;

        for (auto& it : merged) {
            int acc = it.first;
            vector<string>& emails = it.second;

            sort(emails.begin(), emails.end());  // Sort emails lexicographically

            vector<string> temp;
            temp.push_back(accounts[acc][0]);  // name

            for (auto& e : emails)
                temp.push_back(e);

            result.push_back(temp);
        }

        return result;
    }
};

int main() {
    vector<vector<string>> accounts = {
        {"neet", "neet@gmail.com", "neet_dsa@gmail.com"},
        {"alice", "alice@gmail.com"},
        {"neet", "bob@gmail.com", "neet@gmail.com"},
        {"neet", "neetcode@gmail.com"}};

    Solution sol;
    vector<vector<string>> ans = sol.accountsMerge(accounts);
    for (const auto& account : ans) {
        for (const auto& x : account) {
            cout << x << " ";
        }
        cout << endl;
    }

    return 0;
}