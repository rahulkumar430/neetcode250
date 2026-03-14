#include <bits/stdc++.h>
using namespace std;

// DFS Approach - Time Comlexity: O(V + E), Space Complexity: O(V), V = number of vertices, E = number of edges
class Solution {
   public:
    void dfs(int node, vector<vector<int>>& adj, vector<bool>& visited) {
        visited[node] = true;

        for (int neighbor : adj[node]) {
            if (!visited[neighbor]) {
                dfs(neighbor, adj, visited);
            }
        }
    }

    int countComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);

        // build graph
        for (auto& e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        vector<bool> visited(n, false);

        int components = 0;

        // count components
        for (int i = 0; i < n; i++) {
            // With one dfs call we can visit all the nodes in the same component, so we only need to call dfs when we find an unvisited node, and we can count the number of times we call dfs to get the number of components.
            if (!visited[i]) {
                dfs(i, adj, visited);
                components++;
            }
        }

        return components;
    }
};

// BFS Approach - Time Comlexity: O(V + E), Space Complexity: O(V), V = number of vertices, E = number of edges
// class Solution {
//    public:
//     int countComponents(int n, vector<vector<int>>& edges) {
//         vector<vector<int>> adj(n);
//         // build graph
//         for (auto& e : edges) {
//             adj[e[0]].push_back(e[1]);
//             adj[e[1]].push_back(e[0]);
//         }

//         vector<bool> visited(n, false);

//         int components = 0;
//         queue<int> q;

//         // count components
//         for (int i = 0; i < n; i++) {
//             if (!visited[i]) {
//                 q.push(i);
//                 visited[i] = true;

//                 while (!q.empty()) {
//                     int node = q.front();
//                     q.pop();
//                     // One bfs call from unvisited node -> Visit all the connected nodes
//                     for (int neighbor : adj[node]) {
//                         if (!visited[neighbor]) {
//                             visited[neighbor] = true;
//                             q.push(neighbor);
//                         }
//                     }
//                 }
//                 // Increment components count after finishing bfs for one component
//                 components++;
//             }
//         }

//         return components;
//     }
// };

int main() {
    int n = 5;
    vector<vector<int>> edges = {{0, 1}, {1, 2}, {3, 4}};

    Solution sol;
    cout << sol.countComponents(n, edges) << endl;

    return 0;
}