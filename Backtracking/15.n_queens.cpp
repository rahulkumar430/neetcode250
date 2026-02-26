#include <bits/stdc++.h>
using namespace std;

// Backtracking Approach
// Time Complexity: O(N!), Space Complexity: O(N^2)
// class Solution {
//    private:
//     vector<vector<string>> ans;

//     // Check if placing queen at (row, col) is safe
//     bool isSafe(int row, int col, vector<string>& board, int n) {
//         // Check column
//         for (int i = 0; i < row; i++) {
//             if (board[i][col] == 'Q')
//                 return false;
//         }

//         // Check upper-left diagonal
//         for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--) {
//             if (board[i][j] == 'Q')
//                 return false;
//         }

//         // Check upper-right diagonal
//         for (int i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++) {
//             if (board[i][j] == 'Q')
//                 return false;
//         }

//         return true;
//     }

//     void backtrack(int row, vector<string>& board, int n) {
//         // If all queens placed
//         if (row == n) {
//             ans.push_back(board);
//             return;
//         }

//         // Try placing queen in each column
//         for (int col = 0; col < n; col++) {
//             if (isSafe(row, col, board, n)) {
//                 // Place queen
//                 board[row][col] = 'Q';

//                 // Move to next row
//                 backtrack(row + 1, board, n);

//                 // Undo (backtrack)
//                 board[row][col] = '.';
//             }
//         }
//     }

//    public:
//     vector<vector<string>> solveNQueens(int n) {
//         vector<string> board(n, string(n, '.'));

//         backtrack(0, board, n);

//         return ans;
//     }
// };

// Optimised Backtracking Approach with using visited vectors, you can replace the vector by hash set as well
// Time Complexity: O(N!), Space Complexity: O(N^2)
// class Solution {
//    private:
//     vector<vector<string>> ans;
//     vector<bool> colUsed;
//     vector<bool> diag1Used;  // row - col
//     vector<bool> diag2Used;  // row + col

//     void backtrack(int row, vector<string>& board, int n) {
//         // If all queens placed
//         if (row == n) {
//             ans.push_back(board);
//             return;
//         }

//         for (int col = 0; col < n; col++) {
//             // Check in O(1)
//             if (colUsed[col] || diag1Used[row - col + n - 1] || diag2Used[row + col])
//                 continue;

//             // Place queen
//             board[row][col] = 'Q';
//             colUsed[col] = true;
//             diag1Used[row - col + n - 1] = true;
//             diag2Used[row + col] = true;

//             backtrack(row + 1, board, n);

//             // Undo
//             board[row][col] = '.';
//             colUsed[col] = false;
//             diag1Used[row - col + n - 1] = false;
//             diag2Used[row + col] = false;
//         }
//     }

//    public:
//     vector<vector<string>> solveNQueens(int n) {
//         vector<string> board(n, string(n, '.'));

//         colUsed.assign(n, false);
//         diag1Used.assign(2 * n - 1, false);
//         diag2Used.assign(2 * n - 1, false);

//         backtrack(0, board, n);

//         return ans;
//     }
// };

// Optimised Backtracking Approach with using visited hash sets
// Time Complexity: O(N!), Space Complexity: O(N^2)
class Solution {
   private:
    vector<vector<string>> ans;

    // Hash sets to track used columns and diagonals
    unordered_set<int> cols;   // column index
    unordered_set<int> diag1;  // row - col
    unordered_set<int> diag2;  // row + col

    void backtrack(int row, vector<string>& board, int n) {
        // If all queens placed → store solution
        if (row == n) {
            ans.push_back(board);
            return;
        }

        for (int col = 0; col < n; col++) {
            // Check if column or diagonals are already occupied
            if (cols.count(col) || diag1.count(row - col) || diag2.count(row + col))
                continue;

            // Place queen
            board[row][col] = 'Q';
            cols.insert(col);
            diag1.insert(row - col);
            diag2.insert(row + col);

            // Recurse to next row
            backtrack(row + 1, board, n);

            // Undo placement (backtrack)
            board[row][col] = '.';
            cols.erase(col);
            diag1.erase(row - col);
            diag2.erase(row + col);
        }
    }

   public:
    vector<vector<string>> solveNQueens(int n) {
        vector<string> board(n, string(n, '.'));

        backtrack(0, board, n);

        return ans;
    }
};

// Bitmask Solution, replacing hash set with binary bitmask, but fatser than other approaches
// Time Complexity: O(N!), Space Complexity: O(N^2)
// class Solution {
//    private:
//     vector<vector<string>> ans;

//     void backtrack(int row, int n, int colsMask, int diag1Mask, int diag2Mask, vector<string>& board) {
//         // If all rows are processed, we found a valid solution
//         if (row == n) {
//             ans.push_back(board);
//             return;
//         }

//         // Try placing queen in every column of this row
//         for (int col = 0; col < n; col++) {
//             // Create a bit for this column position
//             int colBit = 1 << col;

//             // If this column OR either diagonal is already occupied, we cannot place the queen here.
//             if ((colsMask & colBit) ||   // Column already used
//                 (diag1Mask & colBit) ||  // Main diagonal blocked
//                 (diag2Mask & colBit))    // Anti-diagonal blocked
//                 continue;

//             // Place the queen
//             board[row][col] = 'Q';

//             // Update masks for column and diagonals
//             backtrack(row + 1, n, colsMask | colBit, (diag1Mask | colBit) << 1, (diag2Mask | colBit) >> 1, board);

//             // Undo placement (backtrack)
//             board[row][col] = '.';
//         }
//     }

//    public:
//     vector<vector<string>> solveNQueens(int n) {
//         // Initialize empty board
//         vector<string> board(n, string(n, '.'));
//         backtrack(0, n, 0, 0, 0, board);
//         return ans;
//     }
// };

// Using Bitset, This Is Cleaner Than Bitmask Version(No Shifting required)
// Time Complexity: O(N!), Space Complexity: O(N^2)
// class Solution {
//    private:
//     static const int MAX_N = 20;  // safe upper bound

//     vector<vector<string>> ans;

//     bitset<MAX_N> cols;       // columns used
//     bitset<2 * MAX_N> diag1;  // main diagonals (row - col + n - 1)
//     bitset<2 * MAX_N> diag2;  // anti-diagonals (row + col)

//     void backtrack(int row, int n, vector<string>& board) {
//         // If all queens placed
//         if (row == n) {
//             ans.push_back(board);
//             return;
//         }

//         for (int col = 0; col < n; col++) {
//             // Compute diagonal indices
//             int d1 = row - col + n - 1;  // shift to avoid negative index
//             int d2 = row + col;

//             // If column or diagonals already occupied → skip
//             if (cols[col] || diag1[d1] || diag2[d2])
//                 continue;

//             // Place queen
//             board[row][col] = 'Q';
//             cols[col] = 1;
//             diag1[d1] = 1;
//             diag2[d2] = 1;

//             backtrack(row + 1, n, board);

//             // Undo (backtrack)
//             board[row][col] = '.';
//             cols[col] = 0;
//             diag1[d1] = 0;
//             diag2[d2] = 0;
//         }
//     }

//    public:
//     vector<vector<string>> solveNQueens(int n) {
//         vector<string> board(n, string(n, '.'));

//         backtrack(0, n, board);

//         return ans;
//     }
// };

int main() {
    int n = 4;

    Solution sol;
    vector<vector<string>> ans = sol.solveNQueens(n);

    for (const auto& row : ans) {
        for (string val : row) cout << val << "  ,  ";
        cout << endl;
    }

    return 0;
}