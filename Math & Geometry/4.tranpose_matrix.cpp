#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    // Naive Iterative Approach - Time Complexity : O(M*N), Space Complexity : O(M*N)
    vector<vector<int>> transpose(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();

        vector<vector<int>> tMatrix(n, vector<int>(m));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                tMatrix[i][j] = matrix[j][i];
            }
        }

        return tMatrix;
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

    matrix = s.transpose(matrix);
    printMatrix(matrix);

    return 0;
}