#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    // Bit masking / Bit manipulation Approach
    // Time Complexity: O(n * 2^n), Space Complexity: O(n * 2^n)
    // vector<vector<int>> subsets(vector<int>& nums) {
    //     int n = nums.size();
    //     // There are 2^n subsets
    //     int totalSubsets = 1 << n;
    //     vector<vector<int>> ans;
    //     // Iterate through all possible subsets using bitmask representation.
    //     // Each integer from 0 to 2^n-1 represents a unique subset where bit i
    //     // indicates whether nums[i] is included (1) or excluded (0) from the subset.
    //     for (int mask = 0; mask < totalSubsets; mask++) {
    //         vector<int> temp = {};
    //         // Check every bit
    //         for (int i = 0; i < n; i++) {
    //             // If ith bit is set, include nums[i]
    //             if (mask & (1 << i)) {
    //                 temp.push_back(nums[i]);
    //             }
    //         }
    //         ans.push_back(temp);
    //     }

    //     return ans;
    // }

    // Recursive Approach
    // Time Complexity: O(n * 2^n), Space Complexity: O(n * 2^n) recursion stack
    //    private:
    //     vector<vector<int>> solve(int index, vector<int>& nums) {
    //         // Base case: if no elements left
    //         if (index == nums.size()) {
    //             return {{}};
    //         }

    //         // Get subsets of remaining elements
    //         vector<vector<int>> subsets = solve(index + 1, nums);
    //         // add subsets without current element
    //         vector<vector<int>> result = subsets;

    //         // Add current element to each subset and then add it to result
    //         for (auto subset : subsets) {
    //             subset.push_back(nums[index]);
    //             result.push_back(subset);
    //         }

    //         return result;
    //     }

    //    public:
    //     vector<vector<int>> subsets(vector<int>& nums) {
    //         return solve(0, nums);
    //     }

    // Backtracking Approach - Time Complexity: O(n * 2^n), Space Complexity: O(n * 2^n)
   private:
    vector<vector<int>> ans;
    void backtrack(int index, vector<int>& nums, vector<int>& path) {
        // Every node in tree is a valid subset
        ans.push_back(path);

        for (int i = index; i < nums.size(); i++) {
            // Choose
            path.push_back(nums[i]);

            // Explore
            backtrack(i + 1, nums, path);

            // Undo choice
            path.pop_back();
        }
    }

   public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> path;
        backtrack(0, nums, path);
        return ans;
    }
};

int main() {
    vector<int> nums = {1, 2, 3};

    Solution sol;
    vector<vector<int>> ans = sol.subsets(nums);

    for (const auto& row : ans) {
        for (int val : row) std::cout << val << " ";
        cout << endl;
    }

    return 0;
}