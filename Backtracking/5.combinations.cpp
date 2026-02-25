#include <bits/stdc++.h>
using namespace std;

// Backtracking Approach
// Time Complexity: O(k * C(n, k)), Space Complexity: O(k)
class Solution {
   private:
    vector<vector<int>> ans;

    // Backtracking Approach - 1
    // void backtrack(int n, int k, int index, vector<int>& currentCombination) {
    //     // If we have selected k numbers → store result
    //     if (currentCombination.size() == k) {
    //         ans.push_back(currentCombination);
    //         return;
    //     }

    //     // If we exceed n → stop
    //     if (index > n)
    //         return;

    //     // Choice 1: Include current number
    //     currentCombination.push_back(index);

    //     backtrack(n, k, index + 1, currentCombination);

    //     currentCombination.pop_back();  // Undo choice

    //     // Choice 2: Exclude current number
    //     backtrack(n, k, index + 1, currentCombination);
    // }

    // Backtracking Approach - 2, A little optmised
    void backtrack(int n, int k, int index, vector<int>& currentCombination) {
        // If current combination size == k → valid result found
        if (currentCombination.size() == k) {
            ans.push_back(currentCombination);
            return;
        }

        // Try picking each number starting from 'index'
        for (int i = index; i <= n; i++) {
            currentCombination.push_back(i);  // Choose

            // Move forward (i + 1) → ensures no reuse and no duplicates
            backtrack(n, k, i + 1, currentCombination);

            currentCombination.pop_back();  // Undo choice (backtrack)
        }
    }

   public:
    vector<vector<int>> combine(int n, int k) {
        vector<int> currentCombination;
        backtrack(n, k, 1, currentCombination);

        return ans;
    }

    // bitmasking/bit manipulation approach - Time Complexity - O(2^n)
    // vector<vector<int>> combine(int n, int k) {
    //     int totalSubsets = 1 << n;  // 2^n

    //     // Iterate through all possible masks
    //     for (int mask = 0; mask < totalSubsets; mask++) {
    //         // Count number of set bits
    //         if (__builtin_popcount(mask) == k) {
    //             vector<int> combination;

    //             // Check each bit position
    //             for (int i = 0; i < n; i++) {
    //                 // If ith bit is set → include (i+1)
    //                 if (mask & (1 << i)) {
    //                     combination.push_back(i + 1);
    //                 }
    //             }

    //             ans.push_back(combination);
    //         }
    //     }

    //     return ans;
    // }
};

int main() {
    int n = 3, k = 3;

    Solution sol;
    vector<vector<int>> ans = sol.combine(n, k);

    for (const auto& row : ans) {
        for (int val : row) std::cout << val << " ";
        cout << endl;
    }

    return 0;
}