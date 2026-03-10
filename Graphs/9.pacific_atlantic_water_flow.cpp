#include <bits/stdc++.h>
using namespace std;

// Bruteforce Approach - Time Complexity: O((R*C)^2), Space Complexity: O(R * C)
// class Solution {
//    public:
//     bool dfs(vector<vector<int>>& heights, int r, int c,
//              vector<vector<bool>>& visited, int prevHeight,
//              bool& pacific, bool& atlantic) {
//         int rows = heights.size();
//         int cols = heights[0].size();

//         // Out of bounds
//         if (r < 0 || c < 0 || r >= rows || c >= cols)
//             return false;

//         // Cannot flow uphill
//         if (visited[r][c] || heights[r][c] > prevHeight)
//             return false;

//         visited[r][c] = true;

//         // Check if touching oceans
//         if (r == 0 || c == 0)
//             pacific = true;

//         if (r == rows - 1 || c == cols - 1)
//             atlantic = true;

//         vector<pair<int, int>> dirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

//         for (auto [dr, dc] : dirs)
//             dfs(heights, r + dr, c + dc, visited, heights[r][c], pacific, atlantic);

//         return pacific && atlantic;
//     }

//     vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
//         int rows = heights.size();
//         int cols = heights[0].size();

//         vector<vector<int>> res;

//         for (int r = 0; r < rows; r++) {
//             for (int c = 0; c < cols; c++) {
//                 vector<vector<bool>> visited(rows, vector<bool>(cols, false));

//                 bool pacific = false;
//                 bool atlantic = false;

//                 dfs(heights, r, c, visited, heights[r][c], pacific, atlantic);

//                 if (pacific && atlantic)
//                     res.push_back({r, c});
//             }
//         }

//         return res;
//     }
// };

// DFS Approach - Time Complexity: O(R * C), Space Complexity: O(R * C)
// class Solution {
//    public:
//     void dfs(vector<vector<int>>& heights, int r, int c, vector<vector<bool>>& visited) {
//         int rows = heights.size();
//         int cols = heights[0].size();

//         visited[r][c] = true;

//         vector<pair<int, int>> dirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

//         for (auto [dr, dc] : dirs) {
//             int nr = r + dr;
//             int nc = c + dc;
//             // Move to next cell if it's within bounds, not visited, and height is greater or equal
//             if (nr >= 0 && nc >= 0 && nr < rows && nc < cols &&
//                 !visited[nr][nc] && heights[nr][nc] >= heights[r][c]) {
//                 dfs(heights, nr, nc, visited);
//             }
//         }
//     }

//     vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
//         int rows = heights.size();
//         int cols = heights[0].size();

//         vector<vector<bool>> pac(rows, vector<bool>(cols, false));
//         vector<vector<bool>> atl(rows, vector<bool>(cols, false));

//         // Pacific DFS (top row + left column)
//         for (int c = 0; c < cols; c++)
//             dfs(heights, 0, c, pac);

//         for (int r = 0; r < rows; r++)
//             dfs(heights, r, 0, pac);

//         // Atlantic DFS (bottom row + right column)
//         for (int c = 0; c < cols; c++)
//             dfs(heights, rows - 1, c, atl);

//         for (int r = 0; r < rows; r++)
//             dfs(heights, r, cols - 1, atl);

//         vector<vector<int>> res;

//         // Cells reachable from both oceans
//         for (int r = 0; r < rows; r++) {
//             for (int c = 0; c < cols; c++) {
//                 if (pac[r][c] && atl[r][c])
//                     res.push_back({r, c});
//             }
//         }

//         return res;
//     }
// };

// BFS Approach - Time Complexity: O(R * C), Space Complexity: O(R * C)
class Solution {
   public:
    bool bfs(vector<vector<int>>& heights, int r, int c) {
        int rows = heights.size();
        int cols = heights[0].size();

        queue<pair<int, int>> q;
        vector<vector<bool>> visited(rows, vector<bool>(cols, false));

        q.push({r, c});
        visited[r][c] = true;

        bool pacific = false;
        bool atlantic = false;

        vector<pair<int, int>> dirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

        while (!q.empty()) {
            auto [x, y] = q.front();
            q.pop();

            // Check if current cell touches Pacific
            if (x == 0 || y == 0)
                pacific = true;

            // Check if current cell touches Atlantic
            if (x == rows - 1 || y == cols - 1)
                atlantic = true;

            // If both oceans reachable we can stop early
            if (pacific && atlantic)
                return true;

            for (auto [dx, dy] : dirs) {
                int nx = x + dx;
                int ny = y + dy;

                // Water can only flow to equal or lower height
                if (nx >= 0 && ny >= 0 && nx < rows && ny < cols &&
                    !visited[nx][ny] && heights[nx][ny] <= heights[x][y]) {
                    visited[nx][ny] = true;
                    q.push({nx, ny});
                }
            }
        }

        return false;
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int rows = heights.size();
        int cols = heights[0].size();

        vector<vector<int>> res;

        // Try BFS from every cell
        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; c++) {
                if (bfs(heights, r, c))
                    res.push_back({r, c});
            }
        }

        return res;
    }
};

int main() {
    vector<vector<int>> heights = {
        {4, 2, 7, 3, 4},
        {7, 4, 6, 4, 7},
        {6, 3, 5, 3, 6}};

    Solution sol;
    vector<vector<int>> ans = sol.pacificAtlantic(heights);

    for (const auto& row : ans) {
        for (const auto& cell : row) {
            cout << cell << " ";
        }
        cout << endl;
    }

    return 0;
}
