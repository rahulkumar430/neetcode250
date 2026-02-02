#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    // Optimised Binary search Approach
    // Search space size = sum(nums)−max(nums)≈sum(nums) → O(log(sum(nums)))
    // Total Time Complexity : O(N * log(sum(nums)))
    int splitArray(vector<int>& nums, int k) {
        int l = *max_element(nums.begin(), nums.end());
        int r = accumulate(nums.begin(), nums.end(), 0);
        int ans = r;

        // Do binary search on the range of possible answer
        while (l <= r) {
            int mid = l + (r - l) / 2;

            int subarrays = 1;  // at least one subarray
            int sum = 0;

            // Count how many subarrays are needed with max sum = mid
            for (int x : nums) {
                if (sum + x > mid) {
                    subarrays++;  // start new subarray
                    sum = x;
                } else {
                    sum += x;
                }
            }

            // If we can split into at most k subarrays, try smaller max sum
            if (subarrays <= k) {
                ans = mid;
                r = mid - 1;
            }
            // Otherwise, we need a larger max sum
            else {
                l = mid + 1;
            }
        }

        return ans;
    }
};

int main() {
    Solution s;

    vector<int> nums = {2, 4, 10, 1, 5};
    int k = 2;

    cout << s.splitArray(nums, k) << endl;

    return 0;
}
