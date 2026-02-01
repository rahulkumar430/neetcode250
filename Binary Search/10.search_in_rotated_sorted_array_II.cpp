#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    // Optimal Solution using binary search - Time Complexity: O(log N)
    bool search(vector<int>& nums, int target) {
        int l = 0;
        int r = nums.size() - 1;

        while (l <= r) {
            int mid = l + (r - l) / 2;

            // If target is found at mid, return true
            if (nums[mid] == target) {
                return true;
            }

            // When duplicates prevent identifying the sorted half,
            // shrink the search space from the left
            if (nums[l] == nums[r]) {
                l++;
                continue;
            }

            // If left half [l..mid] is sorted
            if (nums[l] <= nums[mid]) {
                // Check if target lies within the sorted left half
                if (nums[l] <= target && target < nums[mid]) {
                    r = mid - 1;  // discard right half
                } else {
                    l = mid + 1;  // discard left half
                }
            }
            // Otherwise, right half [mid..r] is sorted
            else {
                // Check if target lies within the sorted right half
                if (nums[mid] < target && target <= nums[r]) {
                    l = mid + 1;  // discard left half
                } else {
                    r = mid - 1;  // discard right half
                }
            }
        }

        // Target does not exist in the array
        return false;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {3, 4, 4, 5, 6, 1, 2, 2};
    int target = 4;
    // vector<int> nums = {1, 0, 1, 1, 1};
    // int target = 0;

    cout << (sol.search(nums, target) ? "true" : "false") << endl;

    return 0;
}
