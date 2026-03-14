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

// Union-Find Approach - Time Complexity: O(E * α(V)) ≈ O(E), Space Complexity: O(V), V = number of vertices, E = number of edges
// class Solution {
//    public:
//     int find(int x, vector<int>& parent) {
//         if (parent[x] == x) return x;
//         // Path compression optimization: directly connect x to its root parent to flatten the structure and speed up future finds
//         return parent[x] = find(parent[x], parent);
//     }

//     int countComponents(int n, vector<vector<int>>& edges) {
//         vector<int> parent(n);

//         // Initially, each node is its own parent (representing separate sets)
//         for (int i = 0; i < n; i++)
//             parent[i] = i;

//         int components = n;

//         for (auto& e : edges) {
//             int p1 = find(e[0], parent);
//             int p2 = find(e[1], parent);

//             // If p1 and p2 are in different sets, we can union them and reduce the components count by 1
//             if (p1 != p2) {
//                 parent[p1] = p2;
//                 // Reduces the number of components by 1, because we are merging two separate components into one, so the total number of components decreases by one.
//                 components--;
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