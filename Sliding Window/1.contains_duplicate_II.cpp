#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    // Brute force approach-Time Complexity: O(N^2) Space Complexity: O(1)
    // bool containsNearbyDuplicate(vector<int>& nums, int k) {
    //     // Compare every element with every other element
    //     for (int i = 0; i < nums.size(); i++) {
    //         for (int j = i + 1; j < nums.size(); j++) {
    //             /*
    //             Check:
    //             1. Values are equal
    //             2. Index distance is within k
    //             */
    //             if (nums[i] == nums[j] && abs(i - j) <= k) {
    //                 return true;
    //             }
    //         }
    //     }

    //     // No such pair found
    //     return false;
    // }

    // Optimised approach-Time Complexity: O(N) Space Complexity: O(N)
    // bool containsNearbyDuplicate(vector<int>& nums, int k) {
    //     // Map to store the last index of each number
    //     unordered_map<int, int> lastIndex;

    //     for (int i = 0; i < nums.size(); i++) {
    //         // If we've seen this number before
    //         if (lastIndex.count(nums[i])) {
    //             // Check distance between current index and last occurrence
    //             if (i - lastIndex[nums[i]] <= k) {
    //                 return true;
    //             }
    //         }

    //         // Update last seen index of the current number
    //         lastIndex[nums[i]] = i;
    //     }

    //     // No duplicates found within distance k
    //     return false;
    // }

    // Optimised approach-Time Complexity: O(N) Space Complexity: O(min(N,k))
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        // Set to store elements in the current window
        unordered_set<int> window;

        for (int i = 0; i < nums.size(); i++) {
            // If current element already exists in the window,
            // we found a duplicate within distance k
            if (window.count(nums[i])) {
                return true;
            }

            // Add current element to the window
            window.insert(nums[i]);

            // Maintain window size of at most k
            if (window.size() > k) {
                // Remove the element that is now out of the window
                window.erase(nums[i - k]);
            }
        }

        // No duplicates found within distance k
        return false;
    }
};

int main() {
    vector<int> nums = {1, 2, 3, 1};
    int k = 3;
    Solution sol;
    cout << (sol.containsNearbyDuplicate(nums, k) ? "true" : "false") << endl;

    return 0;
}