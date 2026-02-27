#include <bits/stdc++.h>
using namespace std;

// Backtracking Approach
// Time Complexity: O(N!), Space Complexity: O(N^2)
// class Solution {
//    private:
//     int count = 0;  // stores number of valid solutions

//     // Check if placing queen at (row, col) is safe
//     bool isSafe(int row, int col, vector<vector<int>>& board, int n) {
//         // Check column
//         for (int i = 0; i < row; i++) {
//             if (board[i][col])
//                 return false;
//         }

//         // Check upper-left diagonal
//         for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--) {
//             if (board[i][j])
//                 return false;
//         }

//         // Check upper-right diagonal
//         for (int i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++) {
//             if (board[i][j])
//                 return false;
//         }

//         return true;
//     }

//     void backtrack(int row, vector<vector<int>>& board, int n) {
//         // If all queens are placed successfully
//         if (row == n) {
//             count++;  // increment solution count
//             return;
//         }

//         for (int col = 0; col < n; col++) {
//             if (isSafe(row, col, board, n)) {
//                 board[row][col] = 1;  // place queen
//                 backtrack(row + 1, board, n);
//                 board[row][col] = 0;  // backtrack
//             }
//         }
//     }

//    public:
//     int totalNQueens(int n) {
//         vector<vector<int>> board(n, vector<int>(n, 0));
//         count = 0;  // reset for safety
//         backtrack(0, board, n);
//         return count;
//     }
// };

// Optimised Backtracking Approach with using visited vectors, you can replace the vector by hash set as well
// Time Complexity: O(N!), Space Complexity: O(N^2)
// class Solution {
//    private:
//     int ans = 0;
//     vector<bool> colUsed;
//     vector<bool> diag1Used;  // row - col
//     vector<bool> diag2Used;  // row + col

//     void backtrack(int row, vector<vector<int>>& board, int n) {
//         // If all queens placed
//         if (row == n) {
//             ans++;
//             return;
//         }

//         for (int col = 0; col < n; col++) {
//             // Check in O(1)
//             if (colUsed[col] || diag1Used[row - col + n - 1] || diag2Used[row + col])
//                 continue;

//             // Place queen
//             board[row][col] = 1;
//             colUsed[col] = true;
//             diag1Used[row - col + n - 1] = true;
//             diag2Used[row + col] = true;

//             backtrack(row + 1, board, n);

//             // Undo
//             board[row][col] = 0;
//             colUsed[col] = false;
//             diag1Used[row - col + n - 1] = false;
//             diag2Used[row + col] = false;
//         }
//     }

//    public:
//     int totalNQueens(int n) {
//         vector<vector<int>> board(n, vector<int>(n, 0));

//         colUsed.assign(n, false);
//         diag1Used.assign(2 * n - 1, false);
//         diag2Used.assign(2 * n - 1, false);

//         backtrack(0, board, n);

//         return ans;
//     }
// };

// Optimised Backtracking Approach with using visited hash sets
// Time Complexity: O(N!), Space Complexity: O(N^2)
// class Solution {
//    private:
//     int ans = 0;

//     // Hash sets to track used columns and diagonals
//     unordered_set<int> cols;   // column index
//     unordered_set<int> diag1;  // row - col
//     unordered_set<int> diag2;  // row + col

//     void backtrack(int row, vector<vector<int>>& board, int n) {
//         // If all queens placed → store solution
//         if (row == n) {
//             ans++;
//             return;
//         }

//         for (int col = 0; col < n; col++) {
//             // Check if column or diagonals are already occupied
//             if (cols.count(col) || diag1.count(row - col) || diag2.count(row + col))
//                 continue;

//             // Place queen
//             board[row][col] = 1;
//             cols.insert(col);
//             diag1.insert(row - col);
//             diag2.insert(row + col);

//             // Recurse to next row
//             backtrack(row + 1, board, n);

//             // Undo placement (backtrack)
//             board[row][col] = 0;
//             cols.erase(col);
//             diag1.erase(row - col);
//             diag2.erase(row + col);
//         }
//     }

//    public:
//     int totalNQueens(int n) {
//         vector<vector<int>> board(n, vector<int>(n, 0));

//         backtrack(0, board, n);

//         return ans;
//     }
// };

// Bitmask Solution, replacing hash set with binary bitmask, but fatser than other approaches
// Time Complexity: O(N!), Space Complexity: O(N^2)
// class Solution {
//    private:
//     int ans = 0;

//     void backtrack(int row, int n, int colsMask, int diag1Mask, int diag2Mask, vector<vector<int>>& board) {
//         // If all rows are processed, we found a valid solution
//         if (row == n) {
//             ans++;
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
//             board[row][col] = 1;

//             // Update masks for column and diagonals
//             backtrack(row + 1, n, colsMask | colBit, (diag1Mask | colBit) << 1, (diag2Mask | colBit) >> 1, board);

//             // Undo placement (backtrack)
//             board[row][col] = 0;
//         }
//     }

//    public:
//     int totalNQueens(int n) {
//         // Initialize empty board
//         vector<vector<int>> board(n, vector<int>(n, 0));
//         backtrack(0, n, 0, 0, 0, board);
//         return ans;
//     }
// };

// Using Bitset, This Is Cleaner Than Bitmask Version(No Shifting required)
// Time Complexity: O(N!), Space Complexity: O(N^2)
class Solution {
   private:
    static const int MAX_N = 20;  // safe upper bound

    int ans = 0;

    bitset<MAX_N> cols;       // columns used
    bitset<2 * MAX_N> diag1;  // main diagonals (row - col + n - 1)
    bitset<2 * MAX_N> diag2;  // anti-diagonals (row + col)

    void backtrack(int row, int n, vector<vector<int>>& board) {
        // If all queens placed
        if (row == n) {
            ans++;
            return;
        }

        for (int col = 0; col < n; col++) {
            // Compute diagonal indices
            int d1 = row - col + n - 1;  // shift to avoid negative index
            int d2 = row + col;

            // If column or diagonals already occupied → skip
            if (cols[col] || diag1[d1] || diag2[d2])
                continue;

            // Place queen
            board[row][col] = cols[col] = diag1[d1] = diag2[d2] = 1;

            backtrack(row + 1, n, board);

            // Undo (backtrack)
            board[row][col] = cols[col] = diag1[d1] = diag2[d2] = 0;
        }
    }

   public:
    int totalNQueens(int n) {
        // Initialize empty board
        vector<vector<int>> board(n, vector<int>(n, 0));
        backtrack(0, n, board);
        return ans;
    }
};

int main() {
    int n = 4;

    Solution sol;
    cout << sol.totalNQueens(n) << endl;

    return 0;
}