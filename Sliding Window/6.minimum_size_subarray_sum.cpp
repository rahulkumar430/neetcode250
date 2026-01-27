#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    // Brute-force approach - Time Complexity: O(N^3), Space Complexity: O(1)
    // This might give TLE Error
    // int minSubArrayLen(int target, vector<int>& nums) {
    //     // Stores the minimum length of a subarray
    //     int ans = INT_MAX;

    //     // Choose the starting index of the subarray
    //     for (int i = 0; i < nums.size(); i++) {
    //         // Choose the ending index of the subarray
    //         for (int j = i; j < nums.size(); j++) {
    //             int sum = 0;

    //             // Calculate sum of subarray nums[i..j]
    //             for (int k = i; k <= j; k++) {
    //                 sum += nums[k];
    //             }

    //             // If subarray sum meets or exceeds the target,
    //             // update the minimum length
    //             if (sum >= target) {
    //                 ans = min(ans, j - i + 1);
    //             }
    //         }
    //     }

    //     // Return the minimum subarray length found
    //     return ans == INT_MAX ? 0 : ans;
    // }

    // Prefix sum approach - Time Complexity: O(N^2), Space Complexity: O(1)
    // int minSubArrayLen(int target, vector<int>& nums) {
    //     // Stores the minimum length of a subarray
    //     int ans = INT_MAX;
    //     int n = nums.size();

    //     // Edge case: single element array
    //     if (n == 1) {
    //         return (nums[0] >= target) ? 1 : 0;
    //     }

    //     // Build prefix sum array
    //     // nums[i] will store sum of elements from index 0 to i
    //     for (int i = 1; i < n; i++) {
    //         nums[i] += nums[i - 1];
    //     }

    //     // Check all subarrays using prefix sums
    //     for (int i = 0; i < n; i++) {
    //         for (int j = i; j < n; j++) {
    //             // Calculate sum of subarray nums[i..j]
    //             int subArraySum =
    //                 (i == 0) ? nums[j] : nums[j] - nums[i - 1];

    //             // If sum meets or exceeds target,
    //             // update the minimum length
    //             if (subArraySum >= target) {
    //                 ans = min(ans, j - i + 1);
    //             }
    //         }
    //     }

    //     // If no valid subarray found, return 0
    //     return ans == INT_MAX ? 0 : ans;
    // }

    // Sliding Window approach(Optimised)
    // Time Complexity: O(N), Space Complexity: O(1)
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();

        // Stores the minimum length of a valid subarray
        int ans = INT_MAX;

        int left = 0;  // Left pointer of the window
        int sum = 0;   // Current window sum

        // Expand the window using the right pointer
        for (int right = 0; right < n; right++) {
            // Add current element to the window
            sum += nums[right];

            /*
            Shrink the window from the left as long as
            the current window sum meets or exceeds target
            */
            while (sum >= target) {
                // Update minimum subarray length
                ans = min(ans, right - left + 1);

                // Remove the leftmost element and move left pointer
                sum -= nums[left];
                left++;
            }
        }

        // If no valid subarray found, return 0
        return ans == INT_MAX ? 0 : ans;
    }

    // Prefix Sum + Binary Search approach - Time Complexity: O(N log N) Space Complexity: O(N)
    // Most Optimised : if required you can replace lower_bound with binary search manual logic
    // int minSubArrayLen(int target, vector<int>& nums) {
    //     int n = nums.size();

    //     // Prefix sum array where prefix[i]
    //     // stores sum of elements from index 0 to i-1
    //     vector<int> prefix(n + 1, 0);

    //     for (int i = 0; i < n; i++) {
    //         prefix[i + 1] = prefix[i] + nums[i];
    //     }

    //     // Stores the minimum length of a valid subarray
    //     int ans = INT_MAX;

    //     // For each starting index i, find the smallest j
    //     // such that prefix[j] - prefix[i] >= target
    //     for (int i = 0; i < n; i++) {
    //         int requiredSum = prefix[i] + target;

    //         // Binary search for the first index j
    //         // where prefix[j] >= requiredSum
    //         int j = lower_bound(prefix.begin(), prefix.end(), requiredSum) - prefix.begin();

    //         // If such index exists, update the answer
    //         if (j <= n) {
    //             ans = min(ans, j - i);
    //         }
    //     }

    //     // If no valid subarray found, return 0
    //     return ans == INT_MAX ? 0 : ans;
    // }
};

int main() {
    int target = 10;
    vector<int> nums = {2, 1, 5, 1, 5, 3};

    Solution sol;
    cout << sol.minSubArrayLen(target, nums) << endl;

    return 0;
}