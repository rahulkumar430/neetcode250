#include <bits/stdc++.h>
using namespace std;

class Solution {
   private:
    // DFS Approach - Time Complexity: O(n*m) , Space Complexity: O(n*m)
    // int dfs(int x, int y, vector<vector<int>>& grid, vector<vector<int>>& visited) {
    //     int n = grid.size();
    //     int m = grid[0].size();

    //     // If out of bounds → contributes to perimeter
    //     if (x < 0 || y < 0 || x >= n || y >= m)
    //         return 1;

    //     // If water → contributes to perimeter
    //     if (grid[x][y] == 0)
    //         return 1;

    //     // If already visited land → no contribution
    //     if (visited[x][y])
    //         return 0;

    //     visited[x][y] = 1;

    //     int perimeter = 0;

    //     // Explore 4 directions
    //     perimeter += dfs(x + 1, y, grid, visited);
    //     perimeter += dfs(x - 1, y, grid, visited);
    //     perimeter += dfs(x, y + 1, grid, visited);
    //     perimeter += dfs(x, y - 1, grid, visited);

    //     return perimeter;
    // }

    //    public:
    // int islandPerimeter(vector<vector<int>>& grid) {
    //     int n = grid.size();
    //     int m = grid[0].size();

    //     vector<vector<int>> visited(n, vector<int>(m, 0));

    //     // Find first land cell
    //     for (int i = 0; i < n; i++) {
    //         for (int j = 0; j < m; j++) {
    //             if (grid[i][j] == 1) {
    //                 return dfs(i, j, grid, visited);
    //             }
    //         }
    //     }

    //     return 0;
    // }
    //    public:
    // BFS Approach - Time Complexity: O(n*m) , Space Complexity: O(n*m)
    // int islandPerimeter(vector<vector<int>>& grid) {
    //     int n = grid.size();
    //     int m = grid[0].size();

    //     vector<vector<int>> visited(n, vector<int>(m, 0));
    //     queue<pair<int, int>> q;

    //     int perimeter = 0;

    //     // Step 1: Find first land cell
    //     bool found = false;
    //     for (int i = 0; i < n && !found; i++) {
    //         for (int j = 0; j < m && !found; j++) {
    //             if (grid[i][j] == 1) {
    //                 q.push({i, j});
    //                 visited[i][j] = 1;
    //                 found = true;
    //             }
    //         }
    //     }

    //     vector<pair<int, int>> directions = {
    //         {1, 0}, {-1, 0}, {0, 1}, {0, -1}};

    //     // Step 2: BFS
    //     while (!q.empty()) {
    //         auto [x, y] = q.front();
    //         q.pop();

    //         for (auto [dx, dy] : directions) {
    //             int nx = x + dx;
    //             int ny = y + dy;

    //             // If out of bounds → contributes to perimeter
    //             if (nx < 0 || ny < 0 || nx >= n || ny >= m) {
    //                 perimeter++;
    //             }
    //             // If water → contributes to perimeter
    //             else if (grid[nx][ny] == 0) {
    //                 perimeter++;
    //             }
    //             // If land and not visited → continue BFS
    //             else if (!visited[nx][ny]) {
    //                 visited[nx][ny] = 1;
    //                 q.push({nx, ny});
    //             }
    //         }
    //     }

    //     return perimeter;
    // }
   public:
    // Optimsed Iterative Approach - Time Complexity: O(n*m) , Space Complexity: O(1)
    int islandPerimeter(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int perimeter = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1) {
                    // Each land cell contributes 4 to perimeter
                    perimeter += 4;

                    // Subtract 2 for each shared edge with upper neighbor
                    if (i > 0 && grid[i - 1][j] == 1)
                        perimeter -= 2;

                    // Subtract 2 for each shared edge with left neighbor
                    if (j > 0 && grid[i][j - 1] == 1)
                        perimeter -= 2;
                }
            }
        }

        return perimeter;
    }
};

int main() {
    vector<vector<int>> grid = {
        {1, 1, 0, 0},
        {1, 0, 0, 0},
        {1, 1, 1, 0},
        {0, 0, 1, 1}};

    Solution sol;
    cout << sol.islandPerimeter(grid) << endl;

    return 0;
}