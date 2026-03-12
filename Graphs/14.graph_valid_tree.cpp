#include <bits/stdc++.h>
using namespace std;
/*
A graph is a tree if:

1. It has no cycle
2. It is fully connected
3. It has exactly n - 1 edges, where n is the number of nodes
*/

// DFS Approach to detect cycle in undirected graph
//  Time Complexity: O(V + E), Space Complexity: O(V + E), V = number of courses(nodes), E = number of prerequisites(edges)
// class Solution {
//    public:
//     bool dfs(int node, int parent, vector<vector<int>>& graph, vector<bool>& visited) {
//         visited[node] = true;

//         for (int neigh : graph[node]) {
//             // Skip the node we came from
//             if (neigh == parent)
//                 continue;

//             // If already visited → cycle found
//             if (visited[neigh])
//                 return false;

//             // Continue DFS
//             if (!dfs(neigh, node, graph, visited))
//                 return false;
//         }

//         return true;
//     }

//     bool validTree(int n, vector<vector<int>>& edges) {
//         // Tree must have exactly n-1 edges
//         if (edges.size() != n - 1)
//             return false;

//         vector<vector<int>> graph(n);

//         // Build adjacency list
//         for (auto& e : edges) {
//             graph[e[0]].push_back(e[1]);
//             graph[e[1]].push_back(e[0]);
//         }

//         vector<bool> visited(n, false);

//         // Run DFS from node 0
//         if (!dfs(0, -1, graph, visited))
//             return false;

//         // Ensure graph is connected
//         for (bool v : visited)
//             // If any node is not visited → not fully connected, hence not a tree
//             if (!v) return false;

//         return true;
//     }
// };

// Topological Sort using BFS (Kahn’s Algorithm) to detect cycle in undirected graph
//  Time Complexity: O(V + E), Space Complexity: O(V + E), V = number of courses(nodes), E = number of prerequisites(edges)
class Solution {
   public:
    bool validTree(int n, vector<vector<int>>& edges) {
        // Tree must have exactly n-1 edges
        if (edges.size() != n - 1)
            return false;

        vector<vector<int>> graph(n);

        // Build adjacency list
        for (auto& e : edges) {
            graph[e[0]].push_back(e[1]);
            graph[e[1]].push_back(e[0]);
        }

        vector<bool> visited(n, false);

        queue<pair<int, int>> q;
        q.push({0, -1});  // node, parent
        visited[0] = true;

        while (!q.empty()) {
            auto [node, parent] = q.front();
            q.pop();

            for (int neigh : graph[node]) {
                if (neigh == parent)
                    continue;

                // cycle detected
                if (visited[neigh])
                    return false;

                visited[neigh] = true;
                q.push({neigh, node});
            }
        }

        // Ensure graph is connected
        for (bool v : visited)
            // If any node is not visited → not fully connected, hence not a tree
            if (!v) return false;

        return true;
    }
};

int main() {
    int n = 5;
    vector<vector<int>> edges = {{0, 1}, {0, 2}, {0, 3}, {1, 4}};

    Solution sol;
    cout << (sol.validTree(n, edges) ? "true" : "false") << endl;

    return 0;
}