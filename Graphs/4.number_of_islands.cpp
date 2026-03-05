#include <bits/stdc++.h>
using namespace std;

// DFS Approach - Time Complexity: O(R*C), Space Complexity: O(R*C) in worst case
class Solution {
   public:
    // DFS to mark all connected land as visited
    void dfs(vector<vector<char>>& grid, int r, int c) {
        int rows = grid.size();
        int cols = grid[0].size();

        // Stop if out of bounds or water
        if (r < 0 || c < 0 || r >= rows || c >= cols || grid[r][c] == '0')
            return;

        // Mark current land as visited
        grid[r][c] = '0';

        // Explore 4 directions
        dfs(grid, r + 1, c);
        dfs(grid, r - 1, c);
        dfs(grid, r, c + 1);
        dfs(grid, r, c - 1);
    }

    int numIslands(vector<vector<char>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        int islands = 0;

        // Traverse the grid
        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; c++) {
                // If land found → new island
                if (grid[r][c] == '1') {
                    islands++;

                    // Flood fill the entire island
                    dfs(grid, r, c);
                }
            }
        }

        return islands;
    }
};

// BFS Approach - Time Complexity: O(R*C), Space Complexity: O(min(R, C)) in worst case
// class Solution {
//    public:
//     int numIslands(vector<vector<char>>& grid) {
//         int rows = grid.size();
//         int cols = grid[0].size();
//         int islands = 0;

//         // Directions for 4 neighbors
//         vector<pair<int, int>> dirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

//         for (int r = 0; r < rows; r++) {
//             for (int c = 0; c < cols; c++) {
//                 // Found new island
//                 if (grid[r][c] == '1') {
//                     islands++;

//                     queue<pair<int, int>> q;
//                     q.push({r, c});
//                     grid[r][c] = '0';  // mark visited

//                     // BFS to mark entire island
//                     while (!q.empty()) {
//                         auto [x, y] = q.front();
//                         q.pop();

//                         for (auto [dx, dy] : dirs) {
//                             int nx = x + dx;
//                             int ny = y + dy;

//                             // Check bounds and land
//                             if (nx >= 0 && ny >= 0 && nx < rows && ny < cols && grid[nx][ny] == '1') {
//                                 grid[nx][ny] = '0';  // mark visited
//                                 q.push({nx, ny});
//                             }
//                         }
//                     }
//                 }
//             }
//         }

//         return islands;
//     }
// };

int main() {
    vector<vector<char>> grid = {
        {'0', '1', '1', '1', '0'},
        {'0', '1', '0', '1', '0'},
        {'1', '1', '0', '0', '0'},
        {'0', '0', '0', '0', '0'}};

    Solution sol;
    cout << sol.numIslands(grid) << endl;

    return 0;
}
