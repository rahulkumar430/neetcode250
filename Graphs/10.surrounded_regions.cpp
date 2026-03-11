#include <bits/stdc++.h>
using namespace std;

// DFS Approach - Time Complexity: O(R * C), Space Complexity: O(R * C) in worst case
// class Solution {
//    public:
//     void dfs(vector<vector<char>>& board, int r, int c) {
//         int rows = board.size();
//         int cols = board[0].size();

//         if (r < 0 || c < 0 || r >= rows || c >= cols || board[r][c] != 'O')
//             return;

//         board[r][c] = '#';  // mark safe

//         dfs(board, r + 1, c);
//         dfs(board, r - 1, c);
//         dfs(board, r, c + 1);
//         dfs(board, r, c - 1);
//     }

//     void solve(vector<vector<char>>& board) {
//         int rows = board.size();
//         int cols = board[0].size();

//         // Start DFS from border O's
//         for (int r = 0; r < rows; r++) {
//             dfs(board, r, 0);         // left border
//             dfs(board, r, cols - 1);  // right border
//         }

//         for (int c = 0; c < cols; c++) {
//             dfs(board, 0, c);         // top border
//             dfs(board, rows - 1, c);  // bottom border
//         }

//         // Flip surrounded regions
//         for (int r = 0; r < rows; r++) {
//             for (int c = 0; c < cols; c++) {
//                 // Flip surrounded 'O' to 'X' and safe 'O' (marked as '#') back to 'O'
//                 if (board[r][c] == 'O')
//                     board[r][c] = 'X';

//                 if (board[r][c] == '#')
//                     board[r][c] = 'O';
//             }
//         }
//     }
// };

// BFS Approach - Time Complexity: O(R * C), Space Complexity: O(R * C) in worst case
class Solution {
   public:
    void solve(vector<vector<char>>& board) {
        int rows = board.size();
        int cols = board[0].size();

        queue<pair<int, int>> q;

        // Directions for exploring neighbors
        vector<pair<int, int>> dirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

        // Step 1: Push all border 'O's into queue
        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; c++) {
                if (r == 0 || c == 0 || r == rows - 1 || c == cols - 1) {
                    if (board[r][c] == 'O') {
                        q.push({r, c});
                        board[r][c] = '#';  // mark as safe
                    }
                }
            }
        }

        // Step 2: BFS to mark all 'O's connected to border
        while (!q.empty()) {
            auto [x, y] = q.front();
            q.pop();

            for (auto [dx, dy] : dirs) {
                int nx = x + dx;
                int ny = y + dy;

                if (nx >= 0 && ny >= 0 && nx < rows && ny < cols && board[nx][ny] == 'O') {
                    board[nx][ny] = '#';  // mark safe
                    q.push({nx, ny});
                }
            }
        }

        // Step 3: Flip surrounded 'O' → 'X'
        // Restore safe '#' → 'O'
        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; c++) {
                if (board[r][c] == 'O')
                    board[r][c] = 'X';

                if (board[r][c] == '#')
                    board[r][c] = 'O';
            }
        }
    }
};

int main() {
    vector<vector<char>> board = {
        {'X', 'X', 'X', 'X'},
        {'X', 'O', 'O', 'X'},
        {'X', 'O', 'O', 'X'},
        {'X', 'X', 'X', 'O'}};

    Solution sol;
    sol.solve(board);

    for (const auto& row : board) {
        for (const auto& cell : row) {
            cout << cell << " ";
        }
        cout << endl;
    }

    return 0;
}
