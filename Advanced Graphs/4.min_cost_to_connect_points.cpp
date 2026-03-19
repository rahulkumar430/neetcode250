#include <bits/stdc++.h>
using namespace std;

// DFS Brute Force Approach - Time Complexity: O(N!), Space Complexity: O(N^2)
// It will give TLE because of the time complexity
// class Solution {
//    public:
//     int ans = INT_MAX;

//     void dfs(vector<bool>& visited, unordered_map<int, unordered_map<int, int>>& adj, int count, int cost) {
//         // Base case: all nodes visited
//         if (count == visited.size()) {
//             ans = min(ans, cost);
//             return;
//         }

//         // Try all edges connecting visited → unvisited
//         for (int u = 0; u < visited.size(); u++) {
//             if (!visited[u]) continue;

//             for (auto& [v, w] : adj[u]) {
//                 if (!visited[v]) {
//                     visited[v] = true;

//                     // explore
//                     dfs(visited, adj, count + 1, cost + w);

//                     // backtrack
//                     visited[v] = false;
//                 }
//             }
//         }
//     }

//     int minCostConnectPoints(vector<vector<int>>& points) {
//         int n = points.size();

//         unordered_map<int, unordered_map<int, int>> adj;

//         // build full graph
//         for (int i = 0; i < n; i++) {
//             for (int j = i + 1; j < n; j++) {
//                 int d = abs(points[i][0] - points[j][0]) +
//                         abs(points[i][1] - points[j][1]);

//                 adj[i][j] = d;
//                 adj[j][i] = d;
//             }
//         }

//         vector<bool> visited(n, false);

//         // start from node 0
//         visited[0] = true;

//         dfs(visited, adj, 1, 0);

//         return ans;
//     }
// };

// Kruskal's Algorithm - Greedy MST Building - Union by Rank or Size(both works)
// You can also avoid using rank by size to unite for smaller tree for ex: N < 1000 in this case
// But for larger N, rank or size is more efficient
// Time Complexity : O(N^2 log N) Space Complexity: O(N ^ 2)
// class Solution {
//    public:
//     // DSU (Disjoint Set Union)
//     vector<int> parent, rank;  // Union By Rank
//     // vector<int> parent, size;  // Union By Size

//     // Find with path compression
//     int find(int x) {
//         if (parent[x] != x)
//             parent[x] = find(parent[x]);  // compress path
//         return parent[x];
//     }

//     // Union by rank
//     bool unite(int x, int y) {
//         int px = find(x);
//         int py = find(y);

//         // If already in same set → cycle
//         if (px == py) return false;

//         // Attach smaller tree under bigger one
//         // Equal height → height increases → increase rank
//         // Unequal height → no height change → no rank update
//         if (rank[px] < rank[py]) {
//             parent[px] = py;
//         } else if (rank[px] > rank[py]) {
//             parent[py] = px;
//         } else {
//             parent[py] = px;
//             rank[px]++;
//         }

//         return true;
//     }

//     // Union by size
//     // bool unite(int x, int y) {
//     //     int px = find(x);
//     //     int py = find(y);

//     //     if (px == py) return false;

//     //     // Attach smaller tree under bigger tree
//     //     if (size[px] < size[py])
//     //         swap(px, py);

//     //     parent[py] = px;
//     //     size[px] += size[py];  // increase size

//     //     return true;
//     // }

//     int minCostConnectPoints(vector<vector<int>>& points) {
//         int n = points.size();

//         // Step 1: Generate all edges
//         vector<vector<int>> edges;  // {weight, u, v}

//         for (int i = 0; i < n; i++) {
//             for (int j = i + 1; j < n; j++) {
//                 int dist = abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]);

//                 edges.push_back({dist, i, j});
//             }
//         }

//         // Step 2: Sort edges by weight
//         sort(edges.begin(), edges.end());

//         // Step 3: Initialize DSU
//         parent.resize(n);
//         rank.resize(n, 0);

//         for (int i = 0; i < n; i++)
//             parent[i] = i;

//         int totalCost = 0;
//         int edgesUsed = 0;

//         // Step 4: Pick edges greedily
//         for (auto& e : edges) {
//             int w = e[0];
//             int u = e[1];
//             int v = e[2];

//             // If adding this edge does NOT form a cycle
//             if (unite(u, v)) {
//                 totalCost += w;
//                 edgesUsed++;

//                 // MST will have exactly (n-1) edges
//                 if (edgesUsed == n - 1)
//                     break;
//             }
//         }

//         return totalCost;
//     }
// };

// Prim's Algorithm Using Min Heap
// Time Complexity : O(N^2 log N) Space Complexity: O(N ^ 2)
// class Solution {
//    public:
//     int minCostConnectPoints(vector<vector<int>>& points) {
//         int n = points.size();

//         // Min heap: {cost, node}
//         priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

//         // Track visited nodes (already in MST)
//         vector<bool> visited(n, false);

//         // Start from node 0
//         pq.push({0, 0});  // cost = 0, node = 0

//         int totalCost = 0;
//         int edgesUsed = 0;

//         while (edgesUsed < n) {
//             auto [cost, u] = pq.top();
//             pq.pop();

//             // If already included in MST → skip
//             if (visited[u]) continue;

//             // Include this node
//             visited[u] = true;
//             totalCost += cost;
//             edgesUsed++;

//             // Add all edges from this node to heap
//             for (int v = 0; v < n; v++) {
//                 if (!visited[v]) {
//                     int dist = abs(points[u][0] - points[v][0]) + abs(points[u][1] - points[v][1]);

//                     pq.push({dist, v});
//                 }
//             }
//         }

//         return totalCost;
//     }
// };

// Optimised Prim's Algorithm
// Time Complexity : O(N^2) Space Complexity: O(N)
class Solution {
   public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();

        // minDist[i] = minimum cost to connect point i to MST
        vector<int> minDist(n, INT_MAX);

        // visited[i] = whether point i is already in MST
        vector<bool> visited(n, false);

        // Start from point 0
        minDist[0] = 0;

        int totalCost = 0;

        // We need to include all n nodes
        for (int i = 0; i < n; i++) {
            int u = -1;

            // Step 1: pick the unvisited node with smallest cost
            for (int j = 0; j < n; j++) {
                if (!visited[j] && (u == -1 || minDist[j] < minDist[u])) {
                    u = j;
                }
            }

            // Step 2: add this node to MST
            visited[u] = true;
            totalCost += minDist[u];

            // Step 3: update distances of neighbors
            for (int v = 0; v < n; v++) {
                if (!visited[v]) {
                    int dist = abs(points[u][0] - points[v][0]) + abs(points[u][1] - points[v][1]);

                    // Relaxation: keep minimum edge
                    minDist[v] = min(minDist[v], dist);
                }
            }
        }

        return totalCost;
    }
};

int main() {
    vector<vector<int>> points = {{0, 0}, {2, 2}, {3, 3}, {2, 4}, {4, 2}};

    Solution sol;
    cout << sol.minCostConnectPoints(points) << endl;
    return 0;
}