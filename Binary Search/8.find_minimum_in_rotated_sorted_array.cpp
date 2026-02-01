#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    // Optimal Solution using binary search - Time Complexity: O(log N)
    int findMin(vector<int>& nums) {
        int l = 0;
        int r = nums.size() - 1;

        // Binary search on the rotated array
        while (l <= r) {
            // If the current search range [l..r] is already sorted,
            // then the leftmost element is the minimum
            if (nums[l] <= nums[r]) {
                return nums[l];
            }

            int mid = l + (r - l) / 2;

            // Decide which half contains the minimum
            if (nums[mid] >= nums[l]) {
                // Left half is sorted, so minimum must be in right half
                l = mid + 1;
            }
            // Minimum lies in the left half (including mid)
            else {
                r = mid;
            }
        }

        // fallback
        // In rotated-array binary search, l always converges to the minimum.
        return nums[l];
    }
};

int main() {
    Solution sol;
    vector<int> nums = {3, 4, 5, 6, 1, 2};

    cout << sol.findMin(nums) << endl;

    return 0;
}
