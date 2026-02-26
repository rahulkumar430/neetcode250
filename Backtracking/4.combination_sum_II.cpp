#include <bits/stdc++.h>
using namespace std;

// Backtracking Approach-1
// Time Complexity: O(n * 2^n), Space Complexity: O(n * 2^n)
// class Solution {
//    private:
//     vector<vector<int>> ans;
//     void backtrack(vector<int>& candidates, int target, int total, int index, vector<int>& currentCombination) {
//         // valid combination found
//         if (total == target) {
//             ans.push_back(currentCombination);
//             return;
//         }
//         // invalid path
//         if (total > target || index >= candidates.size())
//             return;

//         // Choice 1: Include candidates[index]
//         currentCombination.push_back(candidates[index]);

//         // Move to next index (reuse not allowed)
//         backtrack(candidates, target, total + candidates[index], index + 1, currentCombination);

//         currentCombination.pop_back();  // Undo choice

//         // Choice 2: Exclude candidates[index]
//         // Skip all duplicates of current value
//         int nextIndex = index + 1;
//         while (nextIndex < candidates.size() && candidates[nextIndex] == candidates[index])
//             nextIndex++;

//         backtrack(candidates, target, total, nextIndex, currentCombination);
//     }

//    public:
//     vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
//         vector<int> currentCombination;
//         sort(candidates.begin(), candidates.end());
//         backtrack(candidates, target, 0, 0, currentCombination);
//         return ans;
//     }
// };

// Backtracking Approach-2, a little optimised
// Time Complexity: O(n * 2^n), Space Complexity: O(n * 2^n)
class Solution {
   private:
    vector<vector<int>> ans;
    void backtrack(vector<int>& candidates, int target, int index, vector<int>& currentCombination) {
        // If target becomes 0 → valid combination found
        if (target == 0) {
            ans.push_back(currentCombination);
            return;
        }

        // Try all candidates starting from 'index'
        for (int i = index; i < candidates.size(); i++) {
            // Skip duplicates at same level
            if (i > index && candidates[i] == candidates[i - 1])
                continue;
            // If current number exceeds remaining target → stop
            if (candidates[i] > target) continue;

            // Choose: Include candidates[i]
            currentCombination.push_back(candidates[i]);

            // Explore : Stay at same index (reuse allowed)
            backtrack(candidates, target - candidates[i], i + 1, currentCombination);

            // Undo choice
            currentCombination.pop_back();
        }
    }

   public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int> currentCombination;
        sort(candidates.begin(), candidates.end());
        backtrack(candidates, target, 0, currentCombination);
        return ans;
    }
};

int main() {
    vector<int> candidates = {9, 2, 2, 4, 6, 1, 5};
    int target = 8;

    Solution sol;
    vector<vector<int>> ans = sol.combinationSum2(candidates, target);

    for (const auto& row : ans) {
        for (int val : row) cout << val << " ";
        cout << endl;
    }

    return 0;
}