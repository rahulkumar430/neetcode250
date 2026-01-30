#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    // Brute force approach - Time Complexity : O(N)
    // int searchInsert(vector<int>& nums, int target) {
    //     // Traverse the array from left to right
    //     for (int i = 0; i < nums.size(); i++) {
    //         // If the current element is greater than or equal to target,
    //         // target should be inserted at this index
    //         if (nums[i] >= target) {
    //             return i;
    //         }
    //     }

    //     // If target is greater than all elements,
    //     // it should be inserted at the end
    //     return nums.size();
    // }

    // Optimal approach -> Using Binary Search - Time Complexity : O(logN)
    int searchInsert(vector<int>& nums, int target) {
        int l = 0;
        int r = nums.size() - 1;

        // Continue searching while the search space is valid
        while (l <= r) {
            // Compute mid safely to avoid integer overflow
            int mid = l + (r - l) / 2;

            // If target is found, return its index
            if (nums[mid] == target) {
                return mid;
            }
            // If target is greater, ignore the left half
            else if (nums[mid] < target) {
                l = mid + 1;
            }
            // If target is smaller, ignore the right half
            else {
                r = mid - 1;
            }
        }

        // If target is not found, l points to the correct insertion index
        // because it always moves past elements smaller than target
        return l;
    }

    // Uses STL lower_bound to find the first position
    // where target can be inserted without breaking sorted order
    // Time Complexity: O(log N)
    // int searchInsert(vector<int>& nums, int target) {
    //     // lower_bound returns an iterator to the first element >= target
    //     // Subtracting begin() gives the corresponding index
    //     return lower_bound(nums.begin(), nums.end(), target) - nums.begin();
    // }
};

int main() {
    Solution s;
    vector<int> nums = {-1, 0, 2, 4, 6, 8};
    int target = 5;

    cout << s.searchInsert(nums, target) << endl;  // should return 4
    return 0;
}