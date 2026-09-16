#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    // Naive Iterative Approach - Time Complexity : O(m × n), Space Complexity : O(1)
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        vector<int> ans;

        int left = 0, right = n - 1, up = 0, down = m - 1;

        while (left <= right && up <= down) {
            // Left -> Right
            for (int j = left; j <= right; j++) {
                ans.push_back(matrix[up][j]);
            }
            up++;

            // Top -> Bottom
            for (int i = up; i <= down; i++) {
                ans.push_back(matrix[i][right]);
            }
            right--;

            // Right -> Left
            if (up <= down) {
                for (int j = right; j >= left; j--) {
                    ans.push_back(matrix[down][j]);
                }
                down--;
            }

            // Bottom -> Top
            if (left <= right) {
                for (int i = down; i >= up; i--) {
                    ans.push_back(matrix[i][left]);
                }
                left++;
            }
        }

        return ans;
    }
};

int main() {
    Solution s;
    vector<vector<int>> matrix = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}};

    vector<int> ans = s.spiralOrder(matrix);

    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " ";
    }

    return 0;
}