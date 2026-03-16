#include <bits/stdc++.h>
using namespace std;

// DFS Brute Force Approach - Time Complexity: O(4^(n*m)), Space Complexity: O(n*m)
// It can give TLE
// class Solution {
//    public:
//     int ans = INT_MAX;  // Stores the minimum effort found among all paths

//     // DFS explores all paths from (i,j) to the destination
//     void dfs(int i, int j, int maxEffort, vector<vector<int>>& heights, vector<vector<bool>>& visited) {
//         int n = heights.size();
//         int m = heights[0].size();

//         // If we reach the destination cell
//         if (i == n - 1 && j == m - 1) {
//             // Update the global minimum effort
//             ans = min(ans, maxEffort);
//             return;
//         }

//         // Mark the current cell as visited
//         visited[i][j] = true;

//         // 4 possible directions (up, down, left, right)
//         vector<pair<int, int>> directions = {
//             {-1, 0}, {1, 0}, {0, -1}, {0, 1}};

//         for (auto& dir : directions) {
//             int x = i + dir.first;
//             int y = j + dir.second;

//             // Check boundaries and whether the cell was already visited
//             if (x >= 0 && x < n && y >= 0 && y < m && !visited[x][y]) {
//                 // Effort of moving to next cell
//                 int effort = abs(heights[i][j] - heights[x][y]);

//                 // Update the maximum effort along the path
//                 int newEffort = max(maxEffort, effort);

//                 // Continue DFS
//                 dfs(x, y, newEffort, heights, visited);
//             }
//         }

//         // Backtrack: unmark the cell so other paths can use it
//         visited[i][j] = false;
//     }

//     int minimumEffortPath(vector<vector<int>>& heights) {
//         int n = heights.size();
//         int m = heights[0].size();

//         // visited matrix to prevent cycles
//         vector<vector<bool>> visited(n, vector<bool>(m, false));

//         // Start DFS from top-left cell
//         dfs(0, 0, 0, heights, visited);

//         return ans;
//     }
// };

// Binary Search on Answer set + BFS Approach
// Time Complexity: O(N*M * log(1e6)), Space Complexity: O(N*M)
// You can also try Binary Search on Answer Set with DFS Approach
// class Solution {
//    public:
//     // Helper function to check if we can reach the bottom-right cell
//     // with the given maximum allowed effort using BFS
//     bool canReach(int effort, vector<vector<int>>& heights) {
//         int n = heights.size();
//         int m = heights[0].size();

//         // Visited matrix to avoid revisiting cells
//         vector<vector<bool>> visited(n, vector<bool>(m, false));

//         queue<pair<int, int>> q;  // {row, col}

//         q.push({0, 0});
//         visited[0][0] = true;

//         // 4 possible directions (down, up, right, left)
//         vector<pair<int, int>> dir = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

//         while (!q.empty()) {
//             auto [i, j] = q.front();
//             q.pop();

//             // If we reach the destination cell, return true
//             if (i == n - 1 && j == m - 1)
//                 return true;

//             for (auto& d : dir) {
//                 int x = i + d.first;
//                 int y = j + d.second;

//                 // Check boundaries and whether the cell was already visited
//                 if (x >= 0 && y >= 0 && x < n && y < m && !visited[x][y]) {
//                     int diff = abs(heights[i][j] - heights[x][y]);

//                     // Only move if the effort does not exceed the current limit
//                     if (diff <= effort) {
//                         visited[x][y] = true;
//                         q.push({x, y});
//                     }
//                 }
//             }
//         }

//         // Could not reach the destination with the given effort
//         return false;
//     }

//     int minimumEffortPath(vector<vector<int>>& heights) {
//         int left = 0;
//         int right = 1e6;  // Maximum possible difference in heights

//         int ans = 0;

//         // Binary search over the possible effort values
//         while (left <= right) {
//             int mid = left + (right - left) / 2;

//             // If it's possible to reach with 'mid' effort, try to find a smaller one
//             if (canReach(mid, heights)) {
//                 ans = mid;
//                 right = mid - 1;
//             } else {
//                 // Otherwise, try a larger effort
//                 left = mid + 1;
//             }
//         }

//         return ans;
//     }
// };

// Kruskal (Minimum Spanning Tree approach) / Union-Find Approach
// Each cell is a node and Each adjacent pair of cells creates an edge with weight = absolute height difference
// Sort edges by weight and start connecting components from smallest effort
// Time Complexity: O(N*M log(N*M)), Space Complexity: O(N*M)
// class Solution {
//    public:
//     vector<int> parent;

//     // Find with path compression
//     int find(int x) {
//         if (parent[x] != x)
//             parent[x] = find(parent[x]);
//         return parent[x];
//     }

//     // Union two components
//     void unite(int a, int b) {
//         int pa = find(a);
//         int pb = find(b);

//         if (pa != pb)
//             parent[pa] = pb;
//     }

//     int minimumEffortPath(vector<vector<int>>& heights) {
//         int n = heights.size();
//         int m = heights[0].size();

//         int total = n * m;

//         parent.resize(total);

//         // Initially every node is its own parent
//         for (int i = 0; i < total; i++)
//             parent[i] = i;

//         // Each edge is represented as a tuple: (effort, node1, node2)
//         vector<tuple<int, int, int>> edges;

//         // Build edges between adjacent cells
//         for (int i = 0; i < n; i++) {
//             for (int j = 0; j < m; j++) {
//                 int node = i * m + j;  // convert 2D index → 1D node

//                 // Down neighbor
//                 if (i + 1 < n) {
//                     int diff = abs(heights[i][j] - heights[i + 1][j]);
//                     edges.push_back({diff, node, (i + 1) * m + j});
//                 }

//                 // Right neighbor
//                 if (j + 1 < m) {
//                     int diff = abs(heights[i][j] - heights[i][j + 1]);
//                     edges.push_back({diff, node, i * m + j + 1});
//                 }
//             }
//         }

//         // Sort edges by weight (effort)
//         sort(edges.begin(), edges.end());

//         // Process edges in increasing order
//         for (auto& [diff, u, v] : edges) {
//             unite(u, v);

//             // Check if start and end are connected
//             if (find(0) == find(n * m - 1))
//                 return diff;
//         }

//         return 0;
//     }
// };

// Dijkstra's Algorithm - Greedy shortest path using minheap
// Time Complexity: O(N*M log(N*M)), Space Complexity: O(N*M)
class Solution {
   public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();

        // Min heap: {effort, row, col}
        priority_queue<
            tuple<int, int, int>,
            vector<tuple<int, int, int>>,
            greater<>>
            pq;

        // dist[i][j] = minimum effort required to reach cell (i,j)
        vector<vector<int>> dist(n, vector<int>(m, INT_MAX));

        // Start from top-left
        pq.push({0, 0, 0});
        dist[0][0] = 0;

        vector<pair<int, int>> directions = {
            {1, 0}, {-1, 0}, {0, 1}, {0, -1}};

        while (!pq.empty()) {
            auto [effort, i, j] = pq.top();
            pq.pop();

            // If we reach destination, return effort
            if (i == n - 1 && j == m - 1)
                return effort;

            for (auto& d : directions) {
                int x = i + d.first;
                int y = j + d.second;

                if (x >= 0 && y >= 0 && x < n && y < m) {
                    // effort needed to move to neighbor
                    int newEffort = max(
                        effort,
                        abs(heights[i][j] - heights[x][y]));

                    // relax edge
                    if (newEffort < dist[x][y]) {
                        dist[x][y] = newEffort;

                        pq.push({newEffort, x, y});
                    }
                }
            }
        }

        return 0;
    }
};

int main() {
    vector<vector<int>> heights = {{1, 1, 1},
                                   {3, 2, 4},
                                   {2, 5, 4}};

    Solution sol;
    cout << sol.minimumEffortPath(heights) << endl;

    return 0;
}