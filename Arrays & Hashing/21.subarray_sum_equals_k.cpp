#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    // Bruteforce approach: O(N^3) time complexity : never use this as you'll get TLE error
    // int subarraySum(vector<int>& nums, int k) {
    //     int cnt = 0;  // Count of subarrays whose sum equals k
    //     int n = nums.size();

    //     // Fix starting index i of subarray
    //     for (int i = 0; i < n; i++) {
    //         // Fix ending index j of subarray (from i to n-1)
    //         for (int j = i; j < n; j++) {
    //             int sum = 0;

    //             // Compute sum of current subarray nums[i..j]
    //             for (int l = i; l <= j; l++) {
    //                 sum += nums[l];
    //             }

    //             // If sum equals k, increment count
    //             if (sum == k) cnt++;
    //         }
    //     }

    //     return cnt;
    // }

    // Optimised from bruteforce but still O(N^2) time complexity
    // Eliminates inner summation loop by using prefix sum accumulation - sum naturally builds nums[i..j] incrementally
    // int subarraySum(vector<int>& nums, int k) {
    //     int cnt = 0;
    //     // Fix starting index i of subarray
    //     for (int i = 0; i < nums.size(); i++) {
    //         int sum = 0;  // Running sum from index i

    //         // Extend ending index j from i to end
    //         for (int j = i; j < nums.size(); j++) {
    //             sum += nums[j];  // Add nums[j] to current subarray sum nums[i..j]

    //             if (sum == k) cnt++;  // Found valid subarray nums[i..j]
    //         }
    //     }
    //     return cnt;
    // }
    // Optimised with O(N) time complexity
    // subarray sum nums[i+1..j] = k exists when prefixSum[j] - prefixSum[i] = k
    int subarraySum(vector<int>& nums, int k) {
        int cnt = 0, curSum = 0;             // curSum: prefix sum till current index
        unordered_map<int, int> prefixSums;  // Maps prefix sum → frequency of that sum
        prefixSums[0] = 1;                   // Empty prefix sum 0 appears once (before index 0)

        for (int num : nums) {
            curSum += num;  // Update prefix sum up to current position

            // Find previous prefix sum that was exactly k before current sum
            // subarray_sum = curSum[i] - curSum[j] = k → curSum[j] = curSum[i] - k
            int diff = curSum - k;
            cnt += prefixSums[diff];  // Add frequency of that prefix sum

            prefixSums[curSum]++;  // Record current prefix sum frequency
        }

        return cnt;  // Total subarrays with sum = k
    }
};

int main() {
    Solution sol;
    vector<int> nums = {2, -1, 1, 2};
    int k = 2;

    cout << sol.subarraySum(nums, k) << endl;

    return 0;
}