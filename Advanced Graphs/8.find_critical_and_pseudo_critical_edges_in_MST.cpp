#include <bits/stdc++.h>
using namespace std;

// Kruskal's Algorithm - For each edge → run Kruskal (O(E log E))
// Time Complexity: O(E^2 log E), Space Complexity: O(V)
// Remove edge → check if MST breaks → critical
// Force edge → check if MST still valid → pseudo-critical
class Solution {
   public:
    vector<int> parent;

    int find(int x) {
        if (parent[x] != x)
            parent[x] = find(parent[x]);
        return parent[x];
    }

    // Union (without size or rank for simplicity- one can use though)
    bool unite(int x, int y) {
        int px = find(x), py = find(y);
        if (px == py) return false;
        parent[py] = px;
        return true;
    }

    // Kruskal helper : Build MST with optional skip / pick
    int kruskal(int n, vector<vector<int>>& edges, int skipEdge, int pickEdge) {
        parent.resize(n);

        for (int i = 0; i < n; i++)
            parent[i] = i;

        int cost = 0;
        int edgesUsed = 0;

        // Force include an edge first (for pseudo-critical check)
        if (pickEdge != -1) {
            auto& e = edges[pickEdge];
            if (unite(e[0], e[1])) {
                cost += e[2];
                edgesUsed++;
            }
        }

        // Normal Kruskal
        for (int i = 0; i < edges.size(); i++) {
            if (i == skipEdge) continue;

            auto& e = edges[i];

            if (unite(e[0], e[1])) {
                cost += e[2];
                edgesUsed++;
            }
        }

        // If not all nodes connected → invalid MST
        return edgesUsed == n - 1 ? cost : INT_MAX;
    }

    vector<vector<int>> findCriticalAndPseudoCriticalEdges(int n, vector<vector<int>>& edges) {
        // Add index to edges
        for (int i = 0; i < edges.size(); i++) {
            edges[i].push_back(i);
        }

        // Sort edges by weight
        sort(edges.begin(), edges.end(),
             [](auto& a, auto& b) {
                 return a[2] < b[2];
             });

        // Step 1: find baseline MST
        int base = kruskal(n, edges, -1, -1);

        vector<int> critical, pseudo;

        // Step 2: check each edge
        for (int i = 0; i < edges.size(); i++) {
            // Check critical
            if (kruskal(n, edges, i, -1) > base) {
                critical.push_back(edges[i][3]);
            }
            // Check pseudo-critical
            else if (kruskal(n, edges, -1, i) == base) {
                pseudo.push_back(edges[i][3]);
            }
        }

        return {critical, pseudo};
    }
};

// Dijkstra-like function: Find minimum "maximum edge weight" from src → target
// Time Complexity: O(E^2 log V), Space Complexity: O(V + E)
// class Solution {
//    public:
//     int minMaxPath(int n, vector<vector<pair<int, int>>>& adj, int src, int target, int skipU, int skipV, int skipW) {
//         // Min heap: {maxEdgeSoFar, node}
//         priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
//         vector<int> dist(n, INT_MAX);

//         pq.push({0, src});
//         dist[src] = 0;

//         while (!pq.empty()) {
//             auto [maxW, node] = pq.top();
//             pq.pop();

//             // Found the target node
//             if (node == target) return maxW;

//             // Iterate over all neighbours of the current node
//             for (auto& [neighbour, weight] : adj[node]) {
//                 // Skip the edge we are testing
//                 if (node == skipU && neighbour == skipV && weight == skipW)
//                     continue;
//                 if (node == skipV && neighbour == skipU && weight == skipW)
//                     continue;

//                 // Calculate the maximum edge weight of the path
//                 int newMax = max(maxW, weight);

//                 // If the new maximum edge weight is smaller, update it
//                 if (newMax < dist[neighbour]) {
//                     dist[neighbour] = newMax;
//                     pq.push({newMax, neighbour});
//                 }
//             }
//         }

//         // If target node is not reachable, return INT_MAX
//         return INT_MAX;
//     }

//     vector<vector<int>> findCriticalAndPseudoCriticalEdges(
//         int n, vector<vector<int>>& edges) {
//         // Build adjacency list
//         vector<vector<pair<int, int>>> adj(n);
//         for (auto& e : edges) {
//             adj[e[0]].push_back({e[1], e[2]});
//             adj[e[1]].push_back({e[0], e[2]});
//         }

//         vector<int> critical, pseudo;

//         for (int i = 0; i < edges.size(); i++) {
//             int u = edges[i][0];
//             int v = edges[i][1];
//             int w = edges[i][2];

//             // Find alternative path without this edge
//             int alt = minMaxPath(n, adj, u, v, u, v, w);

//             if (alt > w) {
//                 // No equal replacement → critical
//                 critical.push_back(i);
//             } else if (alt == w) {
//                 // Can be replaced → pseudo-critical
//                 pseudo.push_back(i);
//             }
//         }

//         return {critical, pseudo};
//     }
// };

int main() {
    int n = 5;
    vector<vector<int>> edges = {{0, 3, 2}, {0, 4, 2}, {1, 3, 2}, {3, 4, 2}, {2, 3, 1}, {1, 2, 3}, {0, 1, 1}};

    Solution sol;
    vector<vector<int>> ans = sol.findCriticalAndPseudoCriticalEdges(n, edges);

    for (const auto& i : ans) {
        for (const auto& j : i) {
            cout << j << " ";
        }
        cout << endl;
    }
    return 0;
}