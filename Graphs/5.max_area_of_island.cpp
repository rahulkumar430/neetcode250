#include <bits/stdc++.h>
using namespace std;

// DFS Approach - Time Complexity: O(R * C), Space Complexity: O(R * C) in worst case
class Solution {
   public:
    // DFS to compute area of an island
    void dfs(vector<vector<int>>& grid, int r, int c, int& area) {
        int rows = grid.size();
        int cols = grid[0].size();

        // Stop if out of bounds or water
        if (r < 0 || c < 0 || r >= rows || c >= cols || grid[r][c] == 0)
            return;

        // Mark cell as visited
        grid[r][c] = 0;

        // Increase island area
        area++;

        // Explore 4 directions
        dfs(grid, r + 1, c, area);
        dfs(grid, r - 1, c, area);
        dfs(grid, r, c + 1, area);
        dfs(grid, r, c - 1, area);
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        int maxArea = 0;

        // Traverse the grid
        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; c++) {
                // Start DFS when land is found
                if (grid[r][c] == 1) {
                    int area = 0;
                    dfs(grid, r, c, area);

                    // Update maximum island area
                    maxArea = max(maxArea, area);
                }
            }
        }

        return maxArea;
    }
};

// BFS Approach - Time Complexity: O(R * C), Space Complexity: O(R * C) in worst case
// class Solution {
//    public:
//     int maxAreaOfIsland(vector<vector<int>>& grid) {
//         int rows = grid.size();
//         int cols = grid[0].size();
//         int maxArea = 0;

//         // Directions for 4 neighbors
//         vector<pair<int, int>> dirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

//         // Traverse the grid
//         for (int r = 0; r < rows; r++) {
//             for (int c = 0; c < cols; c++) {
//                 // Start BFS if land is found
//                 if (grid[r][c] == 1) {
//                     queue<pair<int, int>> q;
//                     q.push({r, c});
//                     grid[r][c] = 0;  // mark visited
//                     int area = 1;    // current island area

//                     // BFS to mark entire island
//                     while (!q.empty()) {
//                         auto [x, y] = q.front();
//                         q.pop();

//                         for (auto [dx, dy] : dirs) {
//                             int nx = x + dx;
//                             int ny = y + dy;

//                             // Check bounds and land
//                             if (nx >= 0 && ny >= 0 && nx < rows && ny < cols && grid[nx][ny] == 1) {
//                                 grid[nx][ny] = 0;  // mark visited
//                                 area++;            // Increase island area
//                                 q.push({nx, ny});
//                             }
//                         }
//                     }
//                     // Update maximum island area
//                     maxArea = max(maxArea, area);
//                 }
//             }
//         }

//         return maxArea;
//     }
// };

int main() {
    vector<vector<int>> grid = {
        {0, 1, 1, 0, 1},
        {1, 0, 1, 0, 1},
        {0, 1, 1, 0, 1},
        {0, 1, 0, 0, 1}};

    Solution sol;
    cout << sol.maxAreaOfIsland(grid) << endl;

    return 0;
}
