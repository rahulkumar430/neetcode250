#include <bits/stdc++.h>
using namespace std;

// Backtracking Approach
// Time Complexity: O(k^n), Space Complexity: O(n + k)
// class Solution {
//    public:
//     bool backtrack(int index, vector<int>& nums, vector<int>& subsets, int target, int k) {
//         // If all elements are placed,
//         // check whether every subset reached the target sum
//         if (index == nums.size()) {
//             for (int i = 0; i < k; i++) {
//                 if (subsets[i] != target)
//                     return false;
//             }
//             return true;
//         }

//         // Try placing nums[index] into each subset
//         for (int i = 0; i < k; i++) {
//             // Skip if adding current number exceeds target sum
//             if (subsets[i] + nums[index] > target)
//                 continue;

//             // Choose: add current number to subset i
//             subsets[i] += nums[index];

//             // Explore next element
//             if (backtrack(index + 1, nums, subsets, target, k))
//                 return true;

//             // Undo choice (backtrack)
//             subsets[i] -= nums[index];

//             // Symmetry pruning:
//             // If placing in an empty subset didn't work,
//             // no need to try other empty subsets (they are identical)
//             if (subsets[i] == 0)
//                 break;
//         }

//         // No valid placement found for this index
//         return false;
//     }

//     bool canPartitionKSubsets(vector<int>& nums, int k) {
//         int total = accumulate(nums.begin(), nums.end(), 0);

//         // Total sum must be divisible by k
//         if (total % k != 0)
//             return false;

//         int target = total / k;

//         // Sort in descending order to place larger elements first
//         // (helps prune invalid branches earlier)
//         sort(nums.rbegin(), nums.rend());

//         // If the largest element exceeds target, partition impossible
//         if (nums[0] > target)
//             return false;

//         // Initialize k subsets with sum 0
//         vector<int> subsets(k, 0);

//         return backtrack(0, nums, subsets, target, k);
//     }
// };

// More Optimised Backtracking Approach
// Time Complexity: O(k * 2^n), Space Complexity: O(n)
class Solution {
   private:
    vector<bool> used;  // Tracks which elements are already used
    int target;         // Required sum for each subset

    bool backtrack(vector<int>& nums,  // input array
                   int k,              // remaining subsets to build
                   int currentSum,     // current subset sum being formed
                   int start) {        // index to continue choosing elements
        // If all k subsets are successfully built
        if (k == 0)
            return true;

        // If current subset reached target,
        // start building next subset
        if (currentSum == target)
            return backtrack(nums, k - 1, 0, 0);

        for (int i = start; i < nums.size(); i++) {
            // Skip if already used OR adding exceeds target
            if (used[i] || currentSum + nums[i] > target)
                continue;

            // Choose element
            used[i] = true;

            // Continue building current subset
            if (backtrack(nums, k, currentSum + nums[i], i + 1))
                return true;

            // Undo choice (backtrack)
            used[i] = false;

            // Pruning:
            // If starting a new subset and it fails,
            // no need to try other elements at this level
            if (currentSum == 0)
                return false;
        }

        return false;
    }

   public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int total = accumulate(nums.begin(), nums.end(), 0);

        // Total sum must be divisible by k
        if (total % k != 0)
            return false;

        target = total / k;

        // Sort descending to place larger numbers first
        // (improves pruning efficiency)
        sort(nums.rbegin(), nums.rend());

        // If largest element exceeds target, impossible
        if (nums[0] > target)
            return false;

        used.assign(nums.size(), false);

        return backtrack(nums, k, 0, 0);
    }
};

int main() {
    vector<int> nums = {2, 4, 1, 3, 5};
    int k = 3;

    Solution sol;
    cout << (sol.canPartitionKSubsets(nums, k) ? "true" : "false") << endl;

    return 0;
}