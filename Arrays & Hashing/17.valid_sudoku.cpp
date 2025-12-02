#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    // BRUTEFORCE APPROACH (O(n^2) time)
    // bool isValidSudoku(vector<vector<char>>& board) {
    //     vector<int> count(10, 0);

    //     // Check rows (horizontal)
    //     for (int i = 0; i < 9; i++) {
    //         fill(count.begin(), count.end(), 0);
    //         for (int j = 0; j < 9; j++) {
    //             if (board[i][j] != '.') {
    //                 int digit = board[i][j] - '0';
    //                 if (++count[digit] > 1) return false;
    //             }
    //         }
    //     }

    //     // Check columns (vertical)
    //     for (int j = 0; j < 9; j++) {
    //         fill(count.begin(), count.end(), 0);
    //         for (int i = 0; i < 9; i++) {
    //             if (board[i][j] != '.') {
    //                 int digit = board[i][j] - '0';
    //                 if (++count[digit] > 1) return false;
    //             }
    //         }
    //     }

    //     // Check 3x3 sub-boxes
    //     for (int bi = 0; bi < 3; bi++) {      // Block row
    //         for (int bj = 0; bj < 3; bj++) {  // Block column
    //             fill(count.begin(), count.end(), 0);
    //             for (int i = bi * 3; i < bi * 3 + 3; i++) {
    //                 for (int j = bj * 3; j < bj * 3 + 3; j++) {
    //                     if (board[i][j] != '.') {
    //                         int digit = board[i][j] - '0';
    //                         if (++count[digit] > 1) return false;
    //                     }
    //                 }
    //             }
    //         }
    //     }

    //     return true;
    // }

    // OPTIMISED APPROACH (O(n^2) time)
    // bool isValidSudoku(vector<vector<char>>& board) {
    //     int rows[9][10] = {0};
    //     int cols[9][10] = {0};
    //     int boxes[9][10] = {0};

    //     for (int i = 0; i < 9; i++) {
    //         for (int j = 0; j < 9; j++) {
    //             if (board[i][j] == '.') continue;

    //             int digit = board[i][j] - '0';
    //             int boxIndex = (i / 3) * 3 + (j / 3);

    //             if (rows[i][digit]++) return false;
    //             if (cols[j][digit]++) return false;
    //             if (boxes[boxIndex][digit]++) return false;
    //         }
    //     }

    //     return true;
    // }

    // OPTIMISED APPROACH (O(n^2) time)
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<unordered_set<char>> row(9), col(9), square(9);

        for (int r = 0; r < 9; r++) {
            for (int c = 0; c < 9; c++) {
                char val = board[r][c];
                if (val == '.') continue;

                int boxIndex = (r / 3) * 3 + (c / 3);

                // Check row
                if (row[r].count(val)) return false;

                // Check column
                if (col[c].count(val)) return false;

                // Check 3x3 square
                if (square[boxIndex].count(val)) return false;

                // Insert digit into its row, column, and square
                row[r].insert(val);
                col[c].insert(val);
                square[boxIndex].insert(val);
            }
        }

        return true;
    }

    // OPTIMISED APPROACH (O(n^2) time) But faster than set/hashmaps
    // bool isValidSudoku(vector<vector<char>>& board) {
    //     int rows[9] = {}, cols[9] = {}, boxes[9] = {};

    //     for (int r = 0; r < 9; r++) {
    //         for (int c = 0; c < 9; c++) {
    //             if (board[r][c] == '.') continue;

    //             int digit = board[r][c] - '1';
    //             int mask = 1 << digit;
    //             int boxIndex = (r / 3) * 3 + (c / 3);

    //             if (rows[r] & mask) return false;
    //             if (cols[c] & mask) return false;
    //             if (boxes[boxIndex] & mask) return false;

    //             rows[r] |= mask;
    //             cols[c] |= mask;
    //             boxes[boxIndex] |= mask;
    //         }
    //     }
    //     return true;
    // }
};

int main() {
    Solution sol;
    vector<vector<char>> board =
        {{'1', '2', '.', '.', '3', '.', '.', '.', '.'},
         {'4', '.', '.', '5', '.', '.', '.', '.', '.'},
         {'.', '9', '8', '.', '.', '.', '.', '.', '3'},
         {'5', '.', '.', '.', '6', '.', '.', '.', '4'},
         {'.', '.', '.', '8', '.', '3', '.', '.', '5'},
         {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
         {'.', '.', '.', '.', '.', '.', '2', '.', '.'},
         {'.', '.', '.', '4', '1', '9', '.', '.', '8'},
         {'.', '.', '.', '.', '8', '.', '.', '7', '9'}};

    cout << (sol.isValidSudoku(board) ? "true" : "false") << endl;
    return 0;
}
