#include <bits/stdc++.h>
using namespace std;

class NumMatrix {
   public:
    // 2D vector to store prefix sums of the matrix
    vector<vector<int>> prefixSum;

    // Constructor - builds the prefix sum matrix in O(m*n)
    NumMatrix(vector<vector<int>>& matrix) {
        int rows = matrix.size();
        if (rows == 0) return;  // Handle empty input matrix
        int cols = matrix[0].size();

        // Resize prefixSum matrix to match input dimensions, initialize with zeros
        prefixSum = vector<vector<int>>(rows, vector<int>(cols, 0));

        // Compute prefix sums:
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (i == 0 && j == 0) {
                    // Base case: first element
                    prefixSum[i][j] = matrix[i][j];
                } else if (i == 0) {
                    // First row - sum of current element and element to the left
                    prefixSum[i][j] = prefixSum[i][j - 1] + matrix[i][j];
                } else if (j == 0) {
                    // First column - sum of current element and element above
                    prefixSum[i][j] = prefixSum[i - 1][j] + matrix[i][j];
                } else {
                    // General case:
                    // Current element + sum above + sum left - sum diag top-left (to avoid double counting)
                    prefixSum[i][j] = matrix[i][j] + prefixSum[i - 1][j] + prefixSum[i][j - 1] - prefixSum[i - 1][j - 1];
                }
            }
        }
    }

    // Returns the sum of elements inside the rectangle defined by (row1, col1) to (row2, col2)
    // O(1) after prefix sums calculation
    int sumRegion(int row1, int col1, int row2, int col2) {
        int res = prefixSum[row2][col2];

        // Subtract area above the rectangle if row1 > 0
        if (row1 > 0) res -= prefixSum[row1 - 1][col2];

        // Subtract area to the left of the rectangle if col1 > 0
        if (col1 > 0) res -= prefixSum[row2][col1 - 1];

        // Add back area overlap (top-left corner) if both row1 > 0 and col1 > 0
        if (row1 > 0 && col1 > 0) res += prefixSum[row1 - 1][col1 - 1];

        return res;
    }
};

int main() {
    vector<vector<int>> matrix = {
        {3, 0, 1, 4, 2},
        {5, 6, 3, 2, 1},
        {1, 2, 0, 1, 5},
        {4, 1, 0, 1, 7},
        {1, 0, 3, 0, 5}};

    NumMatrix numMatrix(matrix);

    cout << numMatrix.sumRegion(2, 1, 4, 3) << endl;

    return 0;
}
