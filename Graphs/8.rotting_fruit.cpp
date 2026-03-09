#include <bits/stdc++.h>
using namespace std;

// BFS Brute Force Approach - Time Complexity: O((R*C)^2), Space Complexity: O(R * C)
// class Solution {
//    public:
//     // Rot adjacent fresh oranges
//     bool updateAdjacent(vector<vector<int>>& grid) {
//         int rows = grid.size();
//         int cols = grid[0].size();
//         bool changed = false;

//         vector<pair<int, int>> dirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

//         // Temporary grid so new rotten oranges don't spread immediately
//         vector<vector<int>> temp = grid;

//         for (int r = 0; r < rows; r++) {
//             for (int c = 0; c < cols; c++) {
//                 if (grid[r][c] == 2) {
//                     for (auto [dx, dy] : dirs) {
//                         int nx = r + dx;
//                         int ny = c + dy;

//                         if (nx >= 0 && ny >= 0 && nx < rows && ny < cols && grid[nx][ny] == 1) {
//                             temp[nx][ny] = 2;
//                             changed = true;
//                         }
//                     }
//                 }
//             }
//         }

//         grid = temp;
//         return changed;
//     }

//     int orangesRotting(vector<vector<int>>& grid) {
//         int minutes = 0;

//         // Repeat until no more oranges rot
//         while (updateAdjacent(grid)) {
//             minutes++;
//         }

//         // Check if any fresh orange remains
//         for (auto& row : grid) {
//             for (int cell : row) {
//                 if (cell == 1)
//                     return -1;
//             }
//         }

//         return minutes;
//     }
// };

// BFS Optimised Approach - Time Complexity: O(R * C), Space Complexity: O(R * C)
class Solution {
   public:
    int orangesRotting(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();

        queue<pair<int, int>> q;
        int fresh = 0;
        // Step 1: Initialize queue with all initially rotten oranges and count fresh oranges
        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; c++) {
                if (grid[r][c] == 2)
                    q.push({r, c});
                if (grid[r][c] == 1)
                    fresh++;
            }
        }

        int minutes = 0;

        vector<pair<int, int>> dirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

        // Step 2: Multi-source BFS
        while (!q.empty() && fresh > 0) {
            int size = q.size();
            // Process all rotten oranges at the current minute
            while (size--) {
                auto [x, y] = q.front();
                q.pop();

                for (auto [dx, dy] : dirs) {
                    int nx = x + dx;
                    int ny = y + dy;

                    if (nx >= 0 && ny >= 0 && nx < rows && ny < cols && grid[nx][ny] == 1) {
                        // Rot the fresh orange
                        grid[nx][ny] = 2;
                        fresh--;
                        // New rotten orange will rot others in the next minute
                        q.push({nx, ny});
                    }
                }
            }

            minutes++;
        }
        // If there are still fresh oranges left, return -1
        if (fresh > 0)
            return -1;

        return minutes;
    }
};

int main() {
    vector<vector<int>> grid = {
        {1, 1, 0},
        {0, 1, 1},
        {0, 1, 2}};

    Solution sol;
    cout << sol.orangesRotting(grid) << endl;

    return 0;
}