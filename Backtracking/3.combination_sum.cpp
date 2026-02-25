#include <bits/stdc++.h>
using namespace std;

// Backtracking Approach
// Time Complexity: O(2^t/m), Space Complexity: O(t/m), t = target & m = minimum value in nums
class Solution {
   private:
    vector<vector<int>> ans;
    // Backtracking Approach - 1
    // void backtrack(vector<int>& nums, int target, int index, vector<int>& currentCombination) {
    //     // If target becomes 0 → valid combination found
    //     if (target == 0) {
    //         ans.push_back(currentCombination);
    //         return;
    //     }
    //     // If target < 0 OR no elements left → invalid path
    //     if (target < 0 || index >= nums.size())
    //         return;

    //     // Choice 1: Include nums[index]
    //     currentCombination.push_back(nums[index]);

    //     // Stay at same index (reuse allowed)
    //     backtrack(nums, target - nums[index], index, currentCombination);

    //     currentCombination.pop_back();  // Undo choice

    //     // Choice 2: Exclude nums[index]
    //     backtrack(nums, target, index + 1, currentCombination);
    // }

    // Backtracking Approach - 2, more optimised
    void backtrack(vector<int>& nums, int target, int index, vector<int>& currentCombination) {
        // If target becomes 0 → valid combination found
        if (target == 0) {
            ans.push_back(currentCombination);
            return;
        }

        // Try all candidates starting from 'index'
        for (int i = index; i < nums.size(); i++) {
            // If current number exceeds remaining target → stop
            if (nums[i] > target) continue;

            // Choose: Include nums[i]
            currentCombination.push_back(nums[i]);

            // Explore : Stay at same index (reuse allowed)
            backtrack(nums, target - nums[i], i, currentCombination);

            // Undo choice
            currentCombination.pop_back();
        }
    }

   public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<int> currentCombination;
        backtrack(nums, target, 0, currentCombination);
        return ans;
    }
};

int main() {
    vector<int> nums = {3, 4, 5};
    int target = 16;

    Solution sol;
    vector<vector<int>> ans = sol.combinationSum(nums, target);

    for (const auto& row : ans) {
        for (int val : row) std::cout << val << " ";
        cout << endl;
    }

    return 0;
}