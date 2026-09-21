#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    // Iterative Approach - Time Complexity : O(m × n), Space Complexity : O(m + n)
    // void setZeroes(vector<vector<int>>& matrix) {
    //     int m = matrix.size(), n = matrix[0].size();

    //     // Store which rows and columns contain at least one zero
    //     vector<bool> rowZero(m, false);
    //     vector<bool> colZero(n, false);

    //     // First: find all rows and columns that need to be zeroed
    //     for (int i = 0; i < m; i++) {
    //         for (int j = 0; j < n; j++) {
    //             if (matrix[i][j] == 0) {
    //                 rowZero[i] = true;
    //                 colZero[j] = true;
    //             }
    //         }
    //     }

    //     // Second: set the entire row or column to zero if marked
    //     for (int i = 0; i < m; i++) {
    //         for (int j = 0; j < n; j++) {
    //             if (rowZero[i] || colZero[j]) {
    //                 matrix[i][j] = 0;
    //             }
    //         }
    //     }
    // }

    // Optimised Approach - Time Complexity : O(m × n), Space Complexity : O(1)
    // void setZeroes(vector<vector<int>>& matrix) {
    //     int m = matrix.size(), n = matrix[0].size();

    //     bool rowZero = false;
    //     bool colZero = false;

    //     // Mark whether the first row and first column contain a zero.
    //     for (int i = 0; i < m; i++) {
    //         for (int j = 0; j < n; j++) {
    //             if (matrix[i][j] == 0) {
    //                 if (i == 0) rowZero = true;
    //                 if (j == 0) colZero = true;

    //                 // Mark the corresponding row and column.
    //                 if (i > 0 && j > 0) {
    //                     matrix[i][0] = 0;
    //                     matrix[0][j] = 0;
    //                 }
    //             }
    //         }
    //     }

    //     // Set zeroes for the inner matrix.
    //     for (int i = 1; i < m; i++) {
    //         for (int j = 1; j < n; j++) {
    //             if (matrix[i][0] == 0 || matrix[0][j] == 0) {
    //                 matrix[i][j] = 0;
    //             }
    //         }
    //     }

    //     // Zero the first row if needed.
    //     if (rowZero) {
    //         for (int j = 0; j < n; j++) {
    //             matrix[0][j] = 0;
    //         }
    //     }

    //     // Zero the first column if needed.
    //     if (colZero) {
    //         for (int i = 0; i < m; i++) {
    //             matrix[i][0] = 0;
    //         }
    //     }
    // }

    // Optimised Approach - Time Complexity : O(m × n), Space Complexity : O(1)
    // Use of matrix[0][0] instead of rowZero as it serves the same purpose without using another variable
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();

        // Track whether the first column originally contains a zero.
        bool colZero = false;

        // Use the first row and first column as markers.
        for (int i = 0; i < m; i++) {
            if (matrix[i][0] == 0)
                colZero = true;

            for (int j = 1; j < n; j++) {
                if (matrix[i][j] == 0) {
                    // Mark the corresponding row.
                    matrix[i][0] = 0;

                    // Mark the corresponding column.
                    matrix[0][j] = 0;
                }
            }
        }

        // Process the matrix except the first row and first column.
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                if (matrix[i][0] == 0 || matrix[0][j] == 0) {
                    matrix[i][j] = 0;
                }
            }
        }

        // If a row was marked, zero the entire first row.
        if (matrix[0][0] == 0) {
            for (int j = 0; j < n; j++) {
                matrix[0][j] = 0;
            }
        }

        // If the first column originally had a zero, zero it.
        if (colZero) {
            for (int i = 0; i < m; i++) {
                matrix[i][0] = 0;
            }
        }
    }
};

void printMatrix(vector<vector<int>>& matrix) {
    for (const auto& row : matrix) {
        for (int value : row) {
            cout << value << ' ';
        }
        cout << endl;
    }
    cout << endl;
}

int main() {
    Solution s;
    vector<vector<int>> matrix = {
        {1, 2, 3},
        {4, 0, 5},
        {6, 7, 8}};
    printMatrix(matrix);

    s.setZeroes(matrix);
    printMatrix(matrix);

    return 0;
}