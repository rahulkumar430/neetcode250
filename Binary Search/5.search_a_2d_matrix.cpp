#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    // Brute-force approach - Time Complexity: O(m * n)
    // bool searchMatrix(vector<vector<int>>& matrix, int target) {
    //     int m = matrix.size();     // number of rows
    //     int n = matrix[0].size();  // number of columns

    //     // Traverse each row
    //     for (int i = 0; i < m; i++) {
    //         // Traverse each column in the current row
    //         for (int j = 0; j < n; j++) {
    //             // If target is found, return true
    //             if (matrix[i][j] == target) {
    //                 return true;
    //             }
    //         }
    //     }

    //     // Target not found in the matrix
    //     return false;
    // }

    // Staircase Search - Time Complexity: O(m + n)
    // bool searchMatrix(vector<vector<int>>& matrix, int target) {
    //     int m = matrix.size();
    //     int n = matrix[0].size();

    //     // Start from top-right corner
    //     int row = 0;
    //     int col = n - 1;

    //     while (row < m && col >= 0) {
    //         // If target is found, return true
    //         if (matrix[row][col] == target) {
    //             return true;
    //         }
    //         // If current value is larger than target,
    //         // move left to reduce the value
    //         else if (matrix[row][col] > target) {
    //             col--;
    //         }
    //         // If current value is smaller than target,
    //         // move down to increase the value
    //         else {
    //             row++;
    //         }
    //     }

    //     // Target not found
    //     return false;
    // }

    // Optimised Two-step Binary approach
    // Time Complexity: O(log m + log n)(which reduces to O(log(m * n)))
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();     // number of rows
        int n = matrix[0].size();  // number of columns

        // ---------------- Step 1: Binary search on rows ----------------
        // Goal: find the row in which the target could exist
        int up = 0, down = m - 1;

        while (up <= down) {
            int mid = up + (down - up) / 2;

            // If the first element of the row equals target, target is found
            if (matrix[mid][0] == target) {
                return true;
            }
            // If target is larger, it must be in a lower row
            else if (matrix[mid][0] < target) {
                up = mid + 1;
            }
            // If target is smaller, it must be in an upper row
            else {
                down = mid - 1;
            }
        }

        // After the loop, 'up' points to the first row
        // whose first element is greater than target,
        // so the candidate row is (up - 1)
        up--;

        // If no valid row exists, target cannot be present
        if (up < 0) return false;

        // ---------------- Step 2: Binary search within the selected row ----------------
        int left = 0, right = n - 1;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            // If target is found in the row, return true
            if (matrix[up][mid] == target) {
                return true;
            }
            // If target is larger, search the right half of the row
            else if (matrix[up][mid] < target) {
                left = mid + 1;
            }
            // If target is smaller, search the left half of the row
            else {
                right = mid - 1;
            }
        }

        // Target not found in the matrix
        return false;
    }

    // Binary Search by treating the 2D matrix as a flattened 1D sorted array
    // matrix is sorted row-wise and each row is sorted left-to-right, the entire matrix behaves like one big sorted array.
    // Time Complexity: O(log(m * n))
    // bool searchMatrix(vector<vector<int>>& matrix, int target) {
    //     int m = matrix.size();
    //     int n = matrix[0].size();

    //     // Search space is [0, m*n - 1] in the virtual 1D array
    //     int l = 0, r = m * n - 1;

    //     while (l <= r) {
    //         // Middle index in the virtual 1D array
    //         int m = l + (r - l) / 2;

    //         // Convert 1D index to 2D coordinates
    //         int row = m / n;
    //         int col = m % n;

    //         // Compare target with the current element
    //         if (target > matrix[row][col]) {
    //             l = m + 1;  // search right half
    //         } else if (target < matrix[row][col]) {
    //             r = m - 1;  // search left half
    //         } else {
    //             return true;  // target found
    //         }
    //     }

    //     // Target not found
    //     return false;
    // }
};

int main() {
    Solution sol;
    vector<vector<int>> matrix = {{1, 2, 4, 8}, {10, 11, 12, 13}, {14, 20, 30, 40}};
    int target = 10;
    cout << (sol.searchMatrix(matrix, target) ? "true" : "false") << endl;

    return 0;
}
