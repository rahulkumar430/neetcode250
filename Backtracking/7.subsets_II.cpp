#include <bits/stdc++.h>
using namespace std;

class Solution {
    // Brute force Approach using set and backtracking
    // Time Complexity: O(n * 2^n), Space Complexity: O(2^n) recursion stack
    //    private:
    //     set<vector<int>> res;  // Set to store unique subsets (automatically handles duplicates)

    //     void backtrack(vector<int>& nums, int index, vector<int> curr) {
    //         // Base case: reached end of array
    //         if (index == nums.size()) {
    //             res.insert(curr);  // Add current subset to result
    //             return;
    //         }

    //         // Include current element
    //         curr.push_back(nums[index]);
    //         backtrack(nums, index + 1, curr);

    //         // Exclude current element
    //         curr.pop_back();
    //         backtrack(nums, index + 1, curr);
    //     }

    //    public:
    //     vector<vector<int>> subsetsWithDup(vector<int>& nums) {
    //         sort(nums.begin(), nums.end());                      // Sort to group duplicates together
    //         backtrack(nums, 0, {});                              // Start backtracking from index 0
    //         return vector<vector<int>>(res.begin(), res.end());  // Convert set to vector
    //     }

    // Backtracking Approach - Time Complexity: O(n * 2^n), Space Complexity: O(2^n)
   private:
    vector<vector<int>> ans;

    // Backtracking Approach - 1
    // void backtrack(int index, vector<int>& nums, vector<int>& curr) {
    //     // If we reach end, store subset
    //     if (index == nums.size()) {
    //         ans.push_back(curr);
    //         return;
    //     }

    //     // Choice 1: Include nums[index]
    //     curr.push_back(nums[index]);

    //     backtrack(index + 1, nums, curr);

    //     curr.pop_back();  // Undo

    //     // Choice 2: Exclude nums[index]
    //     // Skip all duplicates of current number
    //     int nextIndex = index + 1;
    //     while (nextIndex < nums.size() &&
    //            nums[nextIndex] == nums[index]) {
    //         nextIndex++;
    //     }

    //     backtrack(nextIndex, nums, curr);
    // }

    // Optmised Backtracking Approach - 2
    void backtrack(int index, vector<int>& nums, vector<int>& curr) {
        // Every node in tree is a valid subset
        ans.push_back(curr);

        for (int i = index; i < nums.size(); i++) {
            // Skip to avoid duplicates
            if (i > index && nums[i] == nums[i - 1]) {
                continue;
            }
            // Choose
            curr.push_back(nums[i]);

            // Explore
            backtrack(i + 1, nums, curr);

            // Undo choice
            curr.pop_back();
        }
    }

   public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> curr;
        backtrack(0, nums, curr);
        return ans;
    }
};

int main() {
    vector<int> nums = {1, 2, 1};

    Solution sol;
    vector<vector<int>> ans = sol.subsetsWithDup(nums);

    for (const auto& row : ans) {
        for (int val : row) std::cout << val << " ";
        cout << endl;
    }

    return 0;
}