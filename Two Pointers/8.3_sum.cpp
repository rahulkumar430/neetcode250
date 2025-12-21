#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    // Brute-force approach : O(N^3) Time complexity
    // vector<vector<int>> threeSum(vector<int>& nums) {
    //     // Set to store unique triplets (automatically removes duplicates)
    //     set<vector<int>> res;

    //     // Sort the array so triplets are generated in a consistent order
    //     sort(nums.begin(), nums.end());

    //     // Iterate over the first element of the triplet
    //     for (int i = 0; i < nums.size(); i++) {
    //         // Iterate over the second element of the triplet
    //         for (int j = i + 1; j < nums.size(); j++) {
    //             // Iterate over the third element of the triplet
    //             for (int k = j + 1; k < nums.size(); k++) {
    //                 // Check if the sum of the three elements is zero
    //                 if (nums[i] + nums[j] + nums[k] == 0) {
    //                     // Insert the triplet into the set
    //                     // Duplicates are automatically ignored
    //                     res.insert({nums[i], nums[j], nums[k]});
    //                 }
    //             }
    //         }
    //     }

    //     // Convert the set into a vector and return the result
    //     return vector<vector<int>>(res.begin(), res.end());
    // }

    // Optimised approach : O(N^2) Time complexity
    vector<vector<int>> threeSum(vector<int>& nums) {
        // Sort the array to enable two-pointer approach
        sort(nums.begin(), nums.end());

        // Stores the final list of unique triplets
        vector<vector<int>> res;

        // Fix the first element of the triplet
        for (int i = 0; i < nums.size(); i++) {
            // If the current number is greater than 0,
            // no possible triplet can sum to zero
            if (nums[i] > 0) break;

            // Skip duplicate values for the first element
            if (i > 0 && nums[i] == nums[i - 1]) continue;

            // Two pointers for the remaining part of the array
            int l = i + 1;
            int r = nums.size() - 1;

            // Search for valid pairs using twoSum method using 2 pointers
            while (l < r) {
                int sum = nums[i] + nums[l] + nums[r];

                // Sum is too large, decrease it by moving right pointer left
                if (sum > 0) {
                    r--;

                    // Sum is too small, increase it by moving left pointer right
                } else if (sum < 0) {
                    l++;

                    // Found a valid triplet
                } else {
                    res.push_back({nums[i], nums[l], nums[r]});

                    // Move both pointers to look for next unique pair
                    l++;
                    r--;

                    // Skip duplicate values for the second element(one can do for either l or r)
                    // e.g. instead of l++, you can validate duplicates b y doing r-- and slightly changing the while condition to (l < r && nums[r] == nums[r + 1])
                    while (l < r && nums[l] == nums[l - 1]) {
                        l++;
                    }
                }
            }
        }

        return res;
    }
};

int main() {
    vector<int> nums = {-1, 0, 1, 2, -1, -4};
    vector<vector<int>> ans;

    Solution sol;
    ans = sol.threeSum(nums);

    for (auto x : ans) {
        for (auto y : x) {
            cout << y << " ";
        }
        cout << endl;
    }
    cout << endl;

    return 0;
}