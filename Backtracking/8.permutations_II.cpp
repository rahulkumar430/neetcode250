#include <bits/stdc++.h>
using namespace std;

// Brute Force Backtracking Approach with the help of Set
// Time Complexity: O(n! * n), Space Complexity: O(n! * n) for output, O(n) in used vector
// class Solution {
//    public:
//     set<vector<int>> st;  // Automatically removes duplicates

//     void backtrack(vector<int>& nums, vector<bool>& used, vector<int>& currPerm) {
//         if (currPerm.size() == nums.size()) {
//             st.insert(currPerm);  // Insert into set
//             return;
//         }

//         for (int i = 0; i < nums.size(); i++) {
//             if (used[i]) continue;  // Skip used

//             used[i] = true;               // Mark element as used
//             currPerm.push_back(nums[i]);  // Choose element for current position

//             backtrack(nums, used, currPerm);  // Explore with this element

//             currPerm.pop_back();  // Undo: remove element
//             used[i] = false;      // Undo: mark element as unused
//         }
//     }

//     vector<vector<int>> permuteUnique(vector<int>& nums) {
//         vector<bool> used(nums.size(), false);  // Track which elements are used
//         vector<int> currPerm;

//         backtrack(nums, used, currPerm);

//         return vector<vector<int>>(st.begin(), st.end());  // Convert set to vector
//     }
// };

// Optimised Backtracking Approach - 1
// Time Complexity: O(n! * n), Space Complexity: O(n! * n) for output, O(n) in used vector
class Solution {
   public:
    vector<vector<int>> ans;

    // Include / Exclude style using used[] to avoid reuse
    void backtrack(vector<int>& nums, vector<bool>& used, vector<int>& currPerm) {
        if (currPerm.size() == nums.size()) {  // Full permutation formed
            ans.push_back(currPerm);
            return;
        }

        for (int i = 0; i < nums.size(); i++) {
            if (used[i]) continue;  // Skip already used element

            // Skip duplicates: Only allow first unused duplicate
            if (i > 0 && nums[i] == nums[i - 1] && !used[i - 1])
                continue;

            used[i] = true;  // Choose
            currPerm.push_back(nums[i]);

            backtrack(nums, used, currPerm);  // Explore

            currPerm.pop_back();  // Undo
            used[i] = false;      // Mark unused
        }
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> currPerm;
        vector<bool> used(nums.size(), false);
        backtrack(nums, used, currPerm);
        return ans;
    }
};

// Backtracking Approach - 2
// Time Complexity: O(n! * n), Space Complexity: O(n! * n)
// class Solution {
//    public:
//     vector<vector<int>> ans;

//     // Swap-based backtracking (fix one position at a time)
//     void backtrack(vector<int>& nums, int index) {
//         if (index == nums.size()) {  // One permutation complete
//             ans.push_back(nums);
//             return;
//         }

//         unordered_set<int> usedAtLevel;  // Track duplicates per level

//         for (int i = index; i < nums.size(); i++) {
//             if (usedAtLevel.count(nums[i])) continue;  // Skip duplicates

//             usedAtLevel.insert(nums[i]);
//             swap(nums[index], nums[i]);  // Choose

//             backtrack(nums, index + 1);  // Fix next position

//             swap(nums[index], nums[i]);  // Undo
//         }
//     }

//     vector<vector<int>> permuteUnique(vector<int>& nums) {
//         sort(nums.begin(), nums.end());
//         backtrack(nums, 0);
//         return ans;
//     }
// };

// using STL
// class Solution {
//    public:
//     vector<vector<int>> permuteUnique(vector<int>& nums) {
//         sort(nums.begin(), nums.end());
//         vector<vector<int>> ans;

//         do {
//             ans.push_back(nums);
//         } while (next_permutation(nums.begin(), nums.end()));

//         return ans;
//     }
// };

int main() {
    vector<int> nums = {1, 1, 2};

    Solution sol;
    vector<vector<int>> ans = sol.permuteUnique(nums);

    for (const auto& row : ans) {
        for (int val : row) cout << val << " ";
        cout << endl;
    }

    return 0;
}