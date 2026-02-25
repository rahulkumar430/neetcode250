#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    /*
        mask = 0 (00)
        XOR = 0
        Sum += 0

        mask = 1 (01)
        XOR = 1
        Sum += 1

        mask = 2 (10)
        XOR = 2
        Sum += 2

        mask = 3 (11)
        XOR = 1 ^ 2 = 3
        Sum += 3
    */
    // Brute Force Approach using bit masking
    // Time Complexity: O(n * 2^n), Space Complexity: O(1)
    // int subsetXORSum(vector<int>& nums) {
    //     int n = nums.size();
    //     int totalSum = 0;

    //     // There are 2^n subsets
    //     int totalSubsets = 1 << n;

    //     // Iterate through all possible subsets using bitmask representation.
    //     // Each integer from 0 to 2^n-1 represents a unique subset where bit i
    //     // indicates whether nums[i] is included (1) or excluded (0) from the subset.
    //     for (int mask = 0; mask < totalSubsets; mask++) {
    //         int currentXor = 0;

    //         // Check every bit
    //         for (int i = 0; i < n; i++) {
    //             // If ith bit is set, include nums[i]
    //             if (mask & (1 << i)) {
    //                 currentXor ^= nums[i];
    //             }
    //         }

    //         totalSum += currentXor;
    //     }

    //     return totalSum;
    // }

    /*
               (start)
               XOR = 0
              /       \
         include 1   exclude 1
           XOR=1        XOR=0
          /    \       /    \
   include2  exclude2 include2 exclude2
    XOR=3      XOR=1    XOR=2     XOR=0
    */
    // Brute Force using Recursion
    // Time Complexity: O(n * 2^n), Space Complexity: O(n) recursion stack
    // int solve(int index, int currentXor, vector<int>& nums) {
    //     if (index == nums.size()) {
    //         return currentXor;
    //     }

    //     // Include current element
    //     int include = solve(index + 1, currentXor ^ nums[index], nums);

    //     // Exclude current element
    //     int exclude = solve(index + 1, currentXor, nums);

    //     return include + exclude;
    // }

    // int subsetXORSum(vector<int>& nums) {
    //     return solve(0, 0, nums);
    // }

    // Backtracking Approach - Time Complexity: O(n * 2^n), Space Complexity: O(n) recursion stack
    //    private:
    //     int totalSum = 0;

    //     void backtrack(int index, int currentXor, vector<int>& nums) {
    //         // Base Case: one subset completed
    //         if (index == nums.size()) {
    //             totalSum += currentXor;
    //             return;
    //         }

    //         // Choice 1: Include current element
    //         backtrack(index + 1, currentXor ^ nums[index], nums);

    //         // Choice 2: Exclude current element
    //         backtrack(index + 1, currentXor, nums);
    //     }

    //    public:
    //     int subsetXORSum(vector<int>& nums) {
    //         backtrack(0, 0, nums);
    //         return totalSum;
    //     }

    // Optimized Mathematical Approach - Time Complexity: O(n), Space Complexity: O(1)
    /*
    Key Idea:
    ----------
    Instead of generating all 2^n subsets, we use a mathematical observation.

    Observation:
    ------------
    1. Each element appears in exactly 2^(n-1) subsets.
    2. XOR works bit by bit.
    3. If a bit appears in ANY number, it contributes to exactly 2^(n-1) subsets.
    4. Bitwise OR collects all such contributing bits.

    Therefore:
    -----------
    Answer = (OR of all elements) * 2^(n-1)
    */
    int subsetXORSum(vector<int>& nums) {
        int n = nums.size();

        int totalOR = 0;

        // Step 1: Compute OR of all elements
        for (int num : nums) {
            totalOR |= num;  // Collect all active bits
        }

        // Step 2: Multiply with 2^(n-1)
        // (1 << (n-1)) is equal to 2^(n-1)
        return totalOR * (1 << (n - 1));
    }
};

int main() {
    vector<int> nums = {3, 1, 1};

    Solution sol;
    cout << sol.subsetXORSum(nums) << endl;

    return 0;
}