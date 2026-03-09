#include <bits/stdc++.h>
using namespace std;

// BFS Brute Force Approach - Time Complexity: O(R^2 * C^2), Space Complexity: O(R * C)
// class Solution {
//    public:
//     int bfs(vector<vector<int>>& grid, int r, int c) {
//         int rows = grid.size();
//         int cols = grid[0].size();

//         queue<pair<int, int>> q;
//         q.push({r, c});

//         vector<vector<int>> visited(rows, vector<int>(cols, 0));

//         vector<pair<int, int>> dirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

//         visited[r][c] = 1;
//         int dist = 0;

//         while (!q.empty()) {
//             int size = q.size();

//             while (size--) {
//                 auto [x, y] = q.front();
//                 q.pop();

//                 // If we find a gate
//                 if (grid[x][y] == 0)
//                     return dist;

//                 for (auto [dx, dy] : dirs) {
//                     int nx = x + dx;
//                     int ny = y + dy;

//                     if (nx >= 0 && ny >= 0 && nx < rows && ny < cols && !visited[nx][ny] && grid[nx][ny] != -1) {
//                         visited[nx][ny] = 1;
//                         q.push({nx, ny});
//                     }
//                 }
//             }

//             dist++;
//         }

//         return INT_MAX;
//     }

//     void islandsAndTreasure(vector<vector<int>>& grid) {
//         int rows = grid.size();
//         int cols = grid[0].size();

//         for (int r = 0; r < rows; r++) {
//             for (int c = 0; c < cols; c++) {
//                 if (grid[r][c] == INT_MAX) {
//                     grid[r][c] = bfs(grid, r, c);
//                 }
//             }
//         }
//     }
// };

// BFS Optimised Approach - Time Complexity: O(R * C), Space Complexity: O(R * C)
class Solution {
   public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();

        queue<pair<int, int>> q;

        // Step 1: Push all tresure points into queue
        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; c++) {
                if (grid[r][c] == 0) {
                    q.push({r, c});
                }
            }
        }

        vector<pair<int, int>> dirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

        // Step 2: Multi-source BFS
        while (!q.empty()) {
            auto [x, y] = q.front();
            q.pop();

            for (auto [dx, dy] : dirs) {
                int nx = x + dx;
                int ny = y + dy;

                // If valid land that can be traversed
                if (nx >= 0 && ny >= 0 && nx < rows && ny < cols && grid[nx][ny] == INT_MAX) {
                    // Update distance from nearest treasure
                    grid[nx][ny] = grid[x][y] + 1;

                    q.push({nx, ny});
                }
            }
        }
    }
};

int main() {
    vector<vector<int>> grid = {
        {2147483647, -1, 0, 2147483647},
        {2147483647, 2147483647, 2147483647, -1},
        {2147483647, -1, 2147483647, -1},
        {0, -1, 2147483647, 2147483647}};

    Solution sol;
    sol.islandsAndTreasure(grid);

    for (const auto& row : grid) {
        for (const auto& cell : row) {
            cout << cell << " ";
        }
        cout << endl;
    }

    return 0;
}
