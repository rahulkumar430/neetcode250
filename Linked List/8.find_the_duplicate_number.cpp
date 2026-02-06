#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    // Sorting Approach
    // Time: O(N log N), Space: O(1)
    // int findDuplicate(vector<int>& nums) {
    //     sort(nums.begin(), nums.end());

    //     for (int i = 1; i < nums.size(); i++) {
    //         if (nums[i] == nums[i - 1]) {
    //             return nums[i];
    //         }
    //     }
    //     return -1;
    // }

    // HashSet Approach
    // Time: O(N), Space: O(N)
    // int findDuplicate(vector<int>& nums) {
    //     unordered_set<int> seen;

    //     for (int x : nums) {
    //         if (seen.count(x)) return x;  // already seen
    //         seen.insert(x);
    //     }
    //     return -1;
    // }

    // Bit Manipulation Approach
    // Time: O(N log N), Space: O(1)
    // int findDuplicate(vector<int>& nums) {
    //     int n = nums.size() - 1;
    //     int duplicate = 0;

    //     for (int bit = 0; bit < 32; bit++) {
    //         int countNums = 0;
    //         int countRange = 0;

    //         // Count bits in nums
    //         for (int x : nums) {
    //             if (x & (1 << bit)) countNums++;
    //         }

    //         // Count bits in range [1..n]
    //         for (int i = 1; i <= n; i++) {
    //             if (i & (1 << bit)) countRange++;
    //         }

    //         // If nums has extra bits, duplicate has this bit
    //         if (countNums > countRange) {
    //             duplicate |= (1 << bit);
    //         }
    //     }
    //     return duplicate;
    // }

    // Floyd's Cycle Detection (Fast & Slow Pointer like in linked list) - Most Optimal Solution
    // Time: O(N), Space: O(1)
    int findDuplicate(vector<int>& nums) {
        int slow = nums[0];
        int fast = nums[0];

        // Phase 1: Detect cycle
        do {
            slow = nums[slow];
            fast = nums[nums[fast]];
        } while (slow != fast);

        // Phase 2: Find cycle entrance
        slow = nums[0];
        while (slow != fast) {
            slow = nums[slow];
            fast = nums[fast];
        }

        return slow;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {1, 3, 4, 2, 2};

    cout << sol.findDuplicate(nums) << endl;

    return 0;
}
