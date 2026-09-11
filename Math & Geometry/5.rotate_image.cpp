#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    // Naive Iterative Approach - Time Complexity : O(N * N), Space Complexity : O(N * N)
    // void rotate(vector<vector<int>>& matrix) {
    //     int n = matrix.size();

    //     vector<vector<int>> rMatrix(n, vector<int>(n));

    //     for (int i = 0; i < n; i++) {
    //         for (int j = 0; j < n; j++) {
    //             rMatrix[j][n - i - 1] = matrix[i][j];
    //         }
    //     }

    //     matrix = rMatrix;
    // }

    // Space Optimised Approach - Time Complexity : O(N * N), Space Complexity : O(1)
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();

        // Step 1: Transpose the matrix
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                swap(matrix[i][j], matrix[j][i]);
            }
        }

        // Step 2: Reverse each row
        for (int i = 0; i < n; i++) {
            reverse(matrix[i].begin(), matrix[i].end());
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
        {4, 5, 6},
        {7, 8, 9}};

    printMatrix(matrix);

    s.rotate(matrix);
    printMatrix(matrix);

    return 0;
}