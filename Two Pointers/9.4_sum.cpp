#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    // Brute-force approach : O(N^4) Time complexity
    // vector<vector<int>> fourSum(vector<int>& nums, int target) {
    //     // Sort the array so that quadruplets are generated
    //     // in a consistent, non-decreasing order
    //     sort(nums.begin(), nums.end());

    //     // Set to store unique quadruplets (automatically removes duplicates)
    //     set<vector<int>> res;

    //     // First element of the quadruplet
    //     for (int i = 0; i < nums.size(); i++) {
    //         // Second element of the quadruplet
    //         for (int j = i + 1; j < nums.size(); j++) {
    //             // Third element of the quadruplet
    //             for (int k = j + 1; k < nums.size(); k++) {
    //                 // Fourth element of the quadruplet
    //                 for (int l = k + 1; l < nums.size(); l++) {
    //                     // Calculate sum using long long to avoid overflow
    //                     long long sum =
    //                         (long long)nums[i] + nums[j] + nums[k] + nums[l];

    //                     // If the sum matches the target,
    //                     // insert the quadruplet into the set
    //                     if (sum == target) {
    //                         // Since nums is sorted, this quadruplet
    //                         // is already in sorted order
    //                         res.insert({nums[i], nums[j], nums[k], nums[l]});
    //                     }
    //                 }
    //             }
    //         }
    //     }

    //     // Convert the set into a vector before returning
    //     return vector<vector<int>>(res.begin(), res.end());
    // }

    // Optimised approach : O(N^3) Time complexity -> Extending 3 sum solution
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        // Sort the array to:
        // 1. Enable two-pointer approach
        // 2. Make duplicate handling easy
        sort(nums.begin(), nums.end());

        // Stores all unique quadruplets whose sum equals target
        vector<vector<int>> res;

        // Fix the first element of the quadruplet
        for (int i = 0; i < nums.size(); i++) {
            // Optimization:
            // If the smallest possible value is already greater than target,
            // no valid quadruplet can exist further
            if (nums[i] > target) break;

            // Skip duplicate values for the first element
            if (i > 0 && nums[i] == nums[i - 1]) continue;

            // Fix the second element of the quadruplet
            for (int j = i + 1; j < nums.size(); j++) {
                // Skip duplicate values for the second element
                if (j > i + 1 && nums[j] == nums[j - 1]) continue;

                // Two pointers for the remaining two elements
                int l = j + 1;
                int r = nums.size() - 1;

                // Search for valid pairs using two-pointer technique
                while (l < r) {
                    // Use long long to prevent integer overflow
                    long long sum =
                        (long long)nums[i] + nums[j] + nums[l] + nums[r];

                    // If sum is too large, decrease it by moving right pointer left
                    if (sum > target) {
                        r--;

                        // If sum is too small, increase it by moving left pointer right
                    } else if (sum < target) {
                        l++;

                        // Found a valid quadruplet
                    } else {
                        res.push_back({nums[i], nums[j], nums[l], nums[r]});

                        // Move both pointers to find next unique combination
                        l++;
                        r--;

                        // Skip duplicate values for the third element
                        while (l < r && nums[l] == nums[l - 1]) l++;

                        // Skip duplicate values for the fourth element
                        while (l < r && nums[r] == nums[r + 1]) r--;
                    }
                }
            }
        }

        // Return all unique quadruplets
        return res;
    }

    // Optimised approach using Hashmap : O(N^3) Time complexity -> Extending 3 sum solution
    // vector<vector<int>> fourSum(vector<int>& nums, int target) {
    //     // Sort the array for:
    //     // 1. Consistent ordering of quadruplets
    //     // 2. Easy duplicate skipping
    //     sort(nums.begin(), nums.end());

    //     // Frequency map to track how many times
    //     // each number is available for use
    //     unordered_map<int, int> count;
    //     for (int num : nums) {
    //         count[num]++;
    //     }

    //     // Stores all unique quadruplets whose sum equals target
    //     vector<vector<int>> res;

    //     // Fix the first element of the quadruplet
    //     for (int i = 0; i < nums.size(); i++) {
    //         // Use nums[i], so mark it as consumed
    //         count[nums[i]]--;

    //         // Skip duplicate values for the first element
    //         if (i > 0 && nums[i] == nums[i - 1]) continue;

    //         // Fix the second element of the quadruplet
    //         for (int j = i + 1; j < nums.size(); j++) {
    //             // Use nums[j], so mark it as consumed
    //             count[nums[j]]--;

    //             // Skip duplicate values for the second element
    //             if (j > i + 1 && nums[j] == nums[j - 1]) continue;

    //             // Fix the third element of the quadruplet
    //             for (int k = j + 1; k < nums.size(); k++) {
    //                 // Use nums[k], so mark it as consumed
    //                 count[nums[k]]--;

    //                 // Skip duplicate values for the third element
    //                 if (k > j + 1 && nums[k] == nums[k - 1]) continue;

    //                 // Calculate the required fourth number
    //                 // Use long long to avoid integer overflow
    //                 long long fourth =
    //                     target - (nums[i] + nums[j] + 0LL + nums[k]);

    //                 // If the computed value is outside int range,
    //                 // it cannot exist in the array
    //                 if (fourth < INT_MIN || fourth > INT_MAX) continue;

    //                 // Check if the fourth number exists
    //                 // and is still available
    //                 if (count[fourth] > 0) {
    //                     // Found a valid quadruplet
    //                     res.push_back({nums[i], nums[j], nums[k], (int)fourth});
    //                 }
    //             }

    //             // Restore counts for nums[k] before moving to next j
    //             for (int k = j + 1; k < nums.size(); k++) {
    //                 count[nums[k]]++;
    //             }
    //         }

    //         // Restore counts for nums[j] before moving to next i
    //         for (int j = i + 1; j < nums.size(); j++) {
    //             count[nums[j]]++;
    //         }
    //     }

    //     return res;
    // }
};

int main() {
    vector<int> nums = {-2, -1, -1, 1, 1, 2, 2};
    vector<vector<int>> ans;
    int target = 0;

    Solution sol;
    ans = sol.fourSum(nums, target);

    for (auto x : ans) {
        for (auto y : x) {
            cout << y << " ";
        }
        cout << endl;
    }
    cout << endl;

    return 0;
}