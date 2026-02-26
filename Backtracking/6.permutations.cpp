#include <bits/stdc++.h>
using namespace std;

// Backtracking Approach - 1
// Time Complexity: O(n! * n), Space Complexity: O(n! * n) for output, O(n) in used vector
// class Solution {
//    public:
//     vector<vector<int>> ans;

//     // Include / Exclude style using used[] to avoid reuse
//     void backtrack(vector<int>& nums, vector<bool>& used, vector<int>& path) {
//         if (path.size() == nums.size()) {  // Full permutation formed
//             ans.push_back(path);
//             return;
//         }

//         for (int i = 0; i < nums.size(); i++) {
//             if (used[i]) continue;  // Skip already used element

//             used[i] = true;  // Choose
//             path.push_back(nums[i]);

//             backtrack(nums, used, path);  // Explore

//             path.pop_back();  // Undo
//             used[i] = false;  // Mark unused
//         }
//     }

//     vector<vector<int>> permute(vector<int>& nums) {
//         vector<int> path;
//         vector<bool> used(nums.size(), false);
//         backtrack(nums, used, path);
//         return ans;
//     }
// };

// Optimsied Backtracking Approach - 2
// Time Complexity: O(n! * n), Space Complexity: O(n! * n), O(1) for in place swap
class Solution {
   public:
    vector<vector<int>> ans;

    // Swap-based backtracking (fix one position at a time)
    void backtrack(vector<int>& nums, int index) {
        if (index == nums.size()) {  // One permutation complete
            ans.push_back(nums);
            return;
        }

        for (int i = index; i < nums.size(); i++) {
            swap(nums[index], nums[i]);  // Choose

            backtrack(nums, index + 1);  // Fix next position

            swap(nums[index], nums[i]);  // Undo
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        backtrack(nums, 0);
        return ans;
    }
};

// BitMasking / Bit Manipulation Approach with backtracking
// Time Complexity: O(n! * n), Space Complexity: O(n! * n) for output, O(n) in path vector
// class Solution {
//    public:
//     vector<vector<int>> ans;

//     // Bitmask tracks which indices are used
//     void backtrack(vector<int>& nums, int mask, vector<int>& path) {
//         if (path.size() == nums.size()) {  // Full permutation formed
//             ans.push_back(path);
//             return;
//         }

//         for (int i = 0; i < nums.size(); i++) {
//             if (mask & (1 << i)) continue;  // Skip used element

//             path.push_back(nums[i]);

//             backtrack(nums, mask | (1 << i), path);  // Mark bit as used

//             path.pop_back();  // Undo
//         }
//     }

//     vector<vector<int>> permute(vector<int>& nums) {
//         vector<int> path;
//         backtrack(nums, 0, path);
//         return ans;
//     }
// };

int main() {
    vector<int> nums = {1, 2, 3};

    Solution sol;
    vector<vector<int>> ans = sol.permute(nums);

    for (const auto& row : ans) {
        for (int val : row) cout << val << " ";
        cout << endl;
    }

    return 0;
}