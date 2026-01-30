#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    // Optimal approach -> Binary Search - Time Complexity : O(logN)
    int search(vector<int>& nums, int target) {
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

        // Target not found
        return -1;
    }
};

int main() {
    Solution s;
    vector<int> nums = {-1, 0, 2, 4, 6, 8};
    int target = 4;

    cout << s.search(nums, target) << endl;
    return 0;
}