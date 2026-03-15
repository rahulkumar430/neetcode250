#include <bits/stdc++.h>
using namespace std;

// DFS Brute Force Approach - Time Complexity: O(n^2), Space Complexity: O(n)
// class Solution {
//    public:
//     // DFS returns the height of the tree when rooted at 'node'
//     int dfs(int node, int parent, unordered_map<int, vector<int>>& graph) {
//         int height = 0;

//         // Traverse all neighbors of the current node
//         for (int neighbor : graph[node]) {
//             // Skip the node we came from (avoid going backwards)
//             if (neighbor == parent)
//                 continue;

//             // Recursively compute height of subtree
//             height = max(height, dfs(neighbor, node, graph));
//         }

//         // Add 1 to include current node level
//         return height + 1;
//     }

//     vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
//         // Edge case: if only one node
//         if (n == 1)
//             return {0};

//         // Build adjacency list
//         unordered_map<int, vector<int>> graph;

//         for (auto& edge : edges) {
//             graph[edge[0]].push_back(edge[1]);
//             graph[edge[1]].push_back(edge[0]);
//         }

//         vector<int> ans;
//         int minHeight = INT_MAX;

//         // Try each node as root
//         for (int i = 0; i < n; i++) {
//             // Calculate height of tree when rooted at i
//             int height = dfs(i, -1, graph);

//             if (height < minHeight) {
//                 // Update minimum height and reset answer list
//                 minHeight = height;
//                 ans.clear();
//                 ans.push_back(i);
//             } else if (height == minHeight) {
//                 ans.push_back(i);
//             }
//         }

//         return ans;
//     }
// };

// Optimised BFS Topological Leaf Trimming - Time Complexity: O(n), Space Complexity: O(n)
class Solution {
   public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        // Edge case: single node tree
        if (n == 1)
            return {0};

        // Build adjacency list
        vector<vector<int>> graph(n);

        // Degree array to track number of connections
        vector<int> degree(n, 0);

        for (auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];

            graph[u].push_back(v);
            graph[v].push_back(u);

            degree[u]++;
            degree[v]++;
        }

        queue<int> q;

        // Initialize queue with all leaf nodes (degree = 1)
        for (int i = 0; i < n; i++) {
            if (degree[i] == 1)
                q.push(i);
        }

        int remainingNodes = n;

        // Remove leaves layer by layer
        while (remainingNodes > 2) {
            int size = q.size();
            remainingNodes -= size;

            for (int i = 0; i < size; i++) {
                // Process current leaf node and update neighbors
                int node = q.front();
                q.pop();

                for (int neighbor : graph[node]) {
                    degree[neighbor]--;

                    // If neighbor becomes leaf
                    if (degree[neighbor] == 1)
                        q.push(neighbor);
                }
            }
        }

        // Remaining nodes are the roots of minimum height trees
        vector<int> result;

        // Collect the last 1 or 2 remaining nodes from the queue as MHT roots.
        while (!q.empty()) {
            result.push_back(q.front());
            q.pop();
        }

        return result;
    }
};

int main() {
    int n = 5;
    vector<vector<int>> edges = {{0, 1}, {3, 1}, {2, 3}, {4, 1}};

    Solution sol;
    vector<int> ans = sol.findMinHeightTrees(n, edges);
    for (int x : ans) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}