#include <bits/stdc++.h>
using namespace std;

// DFS Approach - Time Complexity: O(E * (V + E)), Space Complexity: O(V + E)
// class Solution {
//    public:
//     // DFS to check if a path exists between src and target
//     bool dfs(int src, int target, vector<vector<int>>& graph, vector<bool>& visited) {
//         // If we reached the target node
//         if (src == target)
//             return true;

//         visited[src] = true;

//         // Explore all neighbors
//         for (int neigh : graph[src]) {
//             // Skip if already visited
//             if (visited[neigh])
//                 continue;

//             // If target reachable through neighbor
//             if (dfs(neigh, target, graph, visited))
//                 return true;
//         }

//         return false;
//     }

//     vector<int> findRedundantConnection(vector<vector<int>>& edges) {
//         int n = edges.size();

//         // adjacency list (1-indexed graph)
//         vector<vector<int>> graph(n + 1);

//         // process edges one by one
//         for (auto& e : edges) {
//             int u = e[0];
//             int v = e[1];

//             // visited array for DFS
//             vector<bool> visited(n + 1, false);

//             // if graph already has a path between u and v, adding this edge will create a cycle
//             if (!graph[u].empty() && !graph[v].empty() && dfs(u, v, graph, visited))
//                 return e;

//             // otherwise add edge to graph
//             graph[u].push_back(v);
//             graph[v].push_back(u);
//         }

//         return {};
//     }
// };

// BFS Approach(Kahn's Algorithm) - Remove leaf nodes iteratively until we are left with the cycle nodes
// Time Complexity: O(V + E), Space Complexity: O(V + E)
// class Solution {
//    public:
//     vector<int> findRedundantConnection(vector<vector<int>>& edges) {
//         int n = edges.size();

//         vector<vector<int>> graph(n + 1);
//         vector<int> degree(n + 1, 0);

//         // build graph and increment degree of each node
//         for (auto& e : edges) {
//             int u = e[0];
//             int v = e[1];

//             graph[u].push_back(v);
//             graph[v].push_back(u);

//             degree[u]++;
//             degree[v]++;
//         }

//         queue<int> q;

//         // push leaf nodes which are part of the tree and not cycle (degree = 1)
//         for (int i = 1; i <= n; i++) {
//             if (degree[i] == 1)
//                 q.push(i);
//         }

//         // remove leaves iteratively until we are left with cycle nodes (degree > 1)
//         while (!q.empty()) {
//             int node = q.front();
//             q.pop();

//             degree[node] = 0;

//             for (int neigh : graph[node]) {
//                 if (degree[neigh] > 0) {
//                     degree[neigh]--;

//                     if (degree[neigh] == 1)
//                         q.push(neigh);
//                 }
//             }
//         }

//         // nodes with degree > 1 belong to cycle
//         // traverse backwards to find the last edge that connects two cycle nodes
//         for (int i = edges.size() - 1; i >= 0; i--) {
//             int u = edges[i][0];
//             int v = edges[i][1];

//             if (degree[u] > 1 && degree[v] > 1)
//                 return edges[i];
//         }

//         return {};
//     }
// };

// Union-Find (Disjoint Set) - Time Complexity: O(E * α(N))  ≈ O(E), Space Complexity: O(N)
class Solution {
   public:
    // Find the ultimate parent of node x
    int find(int x, vector<int>& parent) {
        // If node is its own parent, it is the root
        if (parent[x] == x)
            return x;

        // Path compression
        return parent[x] = find(parent[x], parent);
    }

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();

        // Initially each node is its own parent
        vector<int> parent(n + 1);

        for (int i = 1; i <= n; i++)
            parent[i] = i;

        // Process edges one by one
        for (auto& e : edges) {
            int u = e[0];
            int v = e[1];

            int pu = find(u, parent);
            int pv = find(v, parent);

            // If both nodes already share same parent
            // adding this edge forms a cycle
            if (pu == pv)
                return e;

            // Otherwise merge the two components
            parent[pu] = pv;
        }

        return {};
    }
};

int main() {
    vector<vector<int>> edges = {{1, 2}, {1, 3}, {1, 4}, {3, 4}, {4, 5}};

    Solution sol;
    vector<int> ans = sol.findRedundantConnection(edges);
    for (int x : ans) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}