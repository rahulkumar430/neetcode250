#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    // Optimal Solution using binary search - Time Complexity: O(log N)
    int search(vector<int>& nums, int target) {
        int l = 0;
        int r = nums.size() - 1;

        while (l <= r) {
            int mid = l + (r - l) / 2;

            // If target is found at mid
            if (nums[mid] == target) {
                return mid;
            }

            // -------- Check which half is sorted --------

            // Left half [l..mid] is sorted
            if (nums[l] <= nums[mid]) {
                // If target lies within the sorted left half
                if (nums[l] <= target && target < nums[mid]) {
                    r = mid - 1;  // search left
                } else {
                    l = mid + 1;  // search right
                }
            }
            // Right half [mid..r] is sorted
            else {
                // If target lies within the sorted right half
                if (nums[mid] < target && target <= nums[r]) {
                    l = mid + 1;  // search right
                } else {
                    r = mid - 1;  // search left
                }
            }
        }

        // Target not found
        return -1;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {3, 4, 5, 6, 1, 2};
    int target = 4;

    cout << sol.search(nums, target) << endl;

    return 0;
}
