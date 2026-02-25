#include <bits/stdc++.h>
using namespace std;

// Brute force will be keeping a boolean visited 2d vector
// Time Complexity: O(R * C * 4^L), Space Complexity: O(L), R = no of row, C = no of column, L = length of the word
// class Solution {
//    public:
//     int rows, cols;
//     bool dfs(vector<vector<char>>& board, string& word, int index, int r, int c, vector<vector<bool>>& visited) {
//         // If all characters matched → word found
//         if (index == word.size())
//             return true;

//         // Boundary check + mismatch + already visited
//         if (r < 0 || c < 0 || r >= rows || c >= cols ||
//             visited[r][c] ||
//             board[r][c] != word[index])
//             return false;

//         // Mark current cell as visited
//         visited[r][c] = true;

//         // Explore all 4 directions
//         bool found =
//             dfs(board, word, index + 1, r + 1, c, visited) ||
//             dfs(board, word, index + 1, r - 1, c, visited) ||
//             dfs(board, word, index + 1, r, c + 1, visited) ||
//             dfs(board, word, index + 1, r, c - 1, visited);

//         // Backtrack (unmark cell)
//         visited[r][c] = false;

//         return found;
//     }

//     bool exist(vector<vector<char>>& board, string word) {
//         rows = board.size();
//         cols = board[0].size();

//         // Create visited matrix
//         vector<vector<bool>> visited(rows, vector<bool>(cols, false));

//         // Try starting from every cell
//         for (int r = 0; r < rows; r++) {
//             for (int c = 0; c < cols; c++) {
//                 if (dfs(board, word, 0, r, c, visited))
//                     return true;
//             }
//         }

//         return false;
//     }
// };

// Optimised Approach with backtracking
// Time Complexity: O(R * C * 4^L), Space Complexity: O(L), R = no of row, C = no of column, L = length of the word
class Solution {
   public:
    int rows, cols;

    bool dfs(vector<vector<char>>& board, string& word, int index, int r, int c) {
        // If all characters matched
        if (index == word.size())
            return true;

        // Out of bounds OR character mismatch
        if (r < 0 || c < 0 || r >= rows || c >= cols ||
            board[r][c] != word[index])
            return false;

        // Mark as visited
        char temp = board[r][c];
        board[r][c] = '#';

        // Explore all 4 directions
        bool found =
            dfs(board, word, index + 1, r + 1, c) ||
            dfs(board, word, index + 1, r - 1, c) ||
            dfs(board, word, index + 1, r, c + 1) ||
            dfs(board, word, index + 1, r, c - 1);

        // Restore original character (backtrack)
        board[r][c] = temp;

        return found;
    }

    bool exist(vector<vector<char>>& board, string word) {
        rows = board.size();
        cols = board[0].size();

        // Try starting from every cell
        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; c++) {
                if (dfs(board, word, 0, r, c))
                    return true;
            }
        }

        return false;
    }
};

int main() {
    vector<vector<char>> board = {
        {'A', 'B', 'C', 'D'},
        {'S', 'A', 'A', 'T'},
        {'A', 'C', 'A', 'E'}};
    string word = "CAT";

    Solution sol;
    cout << (sol.exist(board, word) ? "true" : "false") << endl;

    return 0;
}