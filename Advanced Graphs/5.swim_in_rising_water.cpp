#include <bits/stdc++.h>
using namespace std;

// DFS Brute Force Approach - Time Complexity: O(4^(N^2)), Space Complexity: O(N^2)
// It will give TLE because of the time complexity
// class Solution {
//    public:
//     int ans = INT_MAX;

//     void dfs(int r, int c, vector<vector<int>>& grid, vector<vector<bool>>& visited, int currMax) {
//         int n = grid.size();

//         // Out of bounds or already visited
//         if (r < 0 || c < 0 || r >= n || c >= n || visited[r][c])
//             return;

//         // Update current path max
//         currMax = max(currMax, grid[r][c]);

//         // If reached destination → update answer
//         if (r == n - 1 && c == n - 1) {
//             ans = min(ans, currMax);
//             return;
//         }

//         // Mark visited
//         visited[r][c] = true;

//         // Explore all 4 directions
//         dfs(r + 1, c, grid, visited, currMax);
//         dfs(r - 1, c, grid, visited, currMax);
//         dfs(r, c + 1, grid, visited, currMax);
//         dfs(r, c - 1, grid, visited, currMax);

//         // Backtracking
//         visited[r][c] = false;
//     }

//     int swimInWater(vector<vector<int>>& grid) {
//         int n = grid.size();

//         vector<vector<bool>> visited(n, vector<bool>(n, false));

//         dfs(0, 0, grid, visited, 0);

//         return ans;
//     }
// };

// Binary Search on Answer Space with DFS - Time Complexity: O(N^2 log N), Space Complexity: O(N^2)
// class Solution {
//    public:
//     // DFS to check if we can reach destination with max allowed height = t
//     bool dfs(int r, int c, vector<vector<int>>& grid, vector<vector<bool>>& visited, int t) {
//         int n = grid.size();

//         // Out of bounds OR already visited OR cannot step (height > t)
//         if (r < 0 || c < 0 || r >= n || c >= n ||
//             visited[r][c] || grid[r][c] > t)
//             return false;

//         // If reached destination
//         if (r == n - 1 && c == n - 1)
//             return true;

//         visited[r][c] = true;

//         // Explore all 4 directions
//         return dfs(r + 1, c, grid, visited, t) || dfs(r - 1, c, grid, visited, t) ||
//                dfs(r, c + 1, grid, visited, t) || dfs(r, c - 1, grid, visited, t);
//     }

//     bool canReach(vector<vector<int>>& grid, int t) {
//         int n = grid.size();

//         vector<vector<bool>> visited(n, vector<bool>(n, false));

//         return dfs(0, 0, grid, visited, t);
//     }

//     int swimInWater(vector<vector<int>>& grid) {
//         int n = grid.size();

//         int low = max(grid[0][0], grid[n - 1][n - 1]);
//         int high = 0;

//         // find max value in grid
//         for (auto& row : grid)
//             for (auto& val : row)
//                 high = max(high, val);

//         int ans = high;

//         // Binary search on time
//         while (low <= high) {
//             int mid = low + (high - low) / 2;

//             if (canReach(grid, mid)) {
//                 ans = mid;
//                 high = mid - 1;  // try smaller time
//             } else {
//                 low = mid + 1;  // need more time
//             }
//         }

//         return ans;
//     }
// };

// Dijkstra's Algorithm - Time Complexity: O(N^2 log N), Space Complexity: O(N^2)
class Solution {
   public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();

        // Min heap: {time, row, col}
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;

        vector<vector<bool>> visited(n, vector<bool>(n, false));

        // Start from (0,0)
        pq.push({grid[0][0], 0, 0});

        while (!pq.empty()) {
            auto curr = pq.top();
            pq.pop();

            int time = curr[0];
            int r = curr[1];
            int c = curr[2];

            // If reached destination
            if (r == n - 1 && c == n - 1)
                return time;

            if (visited[r][c]) continue;
            visited[r][c] = true;

            // Directions
            vector<pair<int, int>> dir = {
                {0, 1}, {0, -1}, {1, 0}, {-1, 0}};

            for (auto& d : dir) {
                int nr = r + d.first;
                int nc = c + d.second;

                // Not out of bounds and not visited
                if (nr >= 0 && nr < n && nc >= 0 && nc < n && !visited[nr][nc]) {
                    pq.push({max(time, grid[nr][nc]), nr, nc});
                }
            }
        }

        return -1;
    }
};

// Kruskal's Algorithm - Time Complexity: O(N^2 log N), Space Complexity: O(N^2)
// Not a classic MST problem but can be solved by kruskal
// class Solution {
//    public:
//     vector<int> parent;

//     // Find with path compression
//     int find(int x) {
//         if (parent[x] != x)
//             parent[x] = find(parent[x]);
//         return parent[x];
//     }

//     // Union WITHOUT rank/size
//     bool unite(int x, int y) {
//         int px = find(x);
//         int py = find(y);

//         if (px == py) return false;

//         // simply attach py under px
//         parent[py] = px;
//         return true;
//     }

//     int swimInWater(vector<vector<int>>& grid) {
//         int n = grid.size();

//         // Convert 2D index → 1D
//         auto getId = [&](int r, int c) {
//             return r * n + c;
//         };

//         vector<vector<int>> edges;

//         // Build edges (only right & down to avoid duplicates)
//         for (int r = 0; r < n; r++) {
//             for (int c = 0; c < n; c++) {
//                 if (r + 1 < n) {
//                     int w = max(grid[r][c], grid[r + 1][c]);
//                     edges.push_back({w, getId(r, c), getId(r + 1, c)});
//                 }

//                 if (c + 1 < n) {
//                     int w = max(grid[r][c], grid[r][c + 1]);
//                     edges.push_back({w, getId(r, c), getId(r, c + 1)});
//                 }
//             }
//         }

//         // Sort edges by weight
//         sort(edges.begin(), edges.end());

//         // Initialize DSU
//         parent.resize(n * n);
//         for (int i = 0; i < n * n; i++)
//             parent[i] = i;

//         int start = getId(0, 0);
//         int end = getId(n - 1, n - 1);

//         // Process edges
//         for (auto& e : edges) {
//             int w = e[0];
//             int u = e[1];
//             int v = e[2];

//             unite(u, v);

//             // If start and end are connected → answer found
//             if (find(start) == find(end))
//                 return w;
//         }

//         return -1;
//     }
// };

int main() {
    vector<vector<int>> grid = {{0, 1, 2, 10},
                                {9, 14, 4, 13},
                                {12, 3, 8, 15},
                                {11, 5, 7, 6}};

    Solution sol;
    cout << sol.swimInWater(grid) << endl;
    return 0;
}