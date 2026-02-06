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

    /**
     * Floyd's Cycle Detection (Fast & Slow Pointer like in linked list) - Most Optimal Solution
     * Key idea:
     * - Treat the array as a linked list where:
     *     next index = nums[current]
     * - Since there are n+1 indices but values are in [1..n],
     *   a cycle must exist due to the duplicate.
     *
     * Pointer movement:
     * index → nums[index] → nums[nums[index]] → ...
     * similar to : node → node->next → node->next->next
     *
     * Example: nums = {1, 3, 4, 2, 2}
     * 0 → 1 → 3 → 2 → 4 → 2 (cycle detected)
     * we are hopping by nums[value] inside
     *
     * Time Complexity: O(N)
     * Space Complexity: O(1)
     */

    int findDuplicate(vector<int>& nums) {
        int slow = nums[0];
        int fast = nums[0];

        // Phase 1: Detect cycle
        do {
            // slow moves 1 step:  slow = nums[slow] : similar to slow = slow->next;
            slow = nums[slow];
            // fast moves 2 steps: fast = nums[nums[fast]] : similar to fast = fast->next->next;
            fast = nums[nums[fast]];
        } while (slow != fast);

        // Phase 2: Find cycle entrance
        slow = nums[0];
        while (slow != fast) {
            // Distance from start → cycle entry
            // Equals distance from meeting point → cycle entry
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
