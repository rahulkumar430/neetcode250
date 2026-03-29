#include <bits/stdc++.h>
using namespace std;

// Brute Force Approach - Time Complexity: O(n^3), Space Complexity: O(1)
// class Solution {
//    public:
//     int maxProduct(vector<int>& nums) {
//         int n = nums.size();
//         int ans = INT_MIN;

//         // Loop over all possible subarrays
//         for (int i = 0; i < n; i++) {
//             for (int j = i; j < n; j++) {
//                 int product = 1;
//                 for (int k = i; k <= j; k++) {
//                     product *= nums[k];
//                 }

//                 ans = max(ans, product);
//             }
//         }

//         return ans;
//     }
// };

// Better Brute Force - Time Complexity: O(n^2), Space Complexity: O(1)
// class Solution {
//    public:
//     int maxProduct(vector<int>& nums) {
//         int n = nums.size();
//         int ans = INT_MIN;

//         for (int i = 0; i < n; i++) {
//             int product = 1;

//             for (int j = i; j < n; j++) {
//                 // reuse previous product
//                 product *= nums[j];

//                 // Update the answer at every step, which acts as a right bound and avoids the third loop from i to j
//                 ans = max(ans, product);
//             }
//         }

//         return ans;
//     }
// };

// Kadane's Modified Approach (for Product) - Time Complexity: O(n), Space Complexity: O(1)
// At index i, any subarray ending at i must be:
// 1. Just[nums[i]](start new) OR 2. Extend previous subarray ending at i - 1
// class Solution {
//    public:
//     int maxProduct(vector<int>& nums) {
//         int n = nums.size();

//         int currMax = nums[0];  // max product ending here
//         int currMin = nums[0];  // min product ending here
//         int ans = nums[0];

//         for (int i = 1; i < n; i++) {
//             // Store previous max because it will change
//             int temp = currMax;

//             // Update currMax and currMin
//             currMax = max({
//                 nums[i],            // start new subarray
//                 nums[i] * currMax,  // extend max
//                 nums[i] * currMin   // extend min (important for negative)
//             });

//             currMin = min({nums[i],
//                            nums[i] * temp,
//                            nums[i] * currMin});

//             ans = max(ans, currMax);
//         }

//         return ans;
//     }
// };

// Kadane's Optimized Approach (Swap Trick) - Time Complexity: O(n), Space Complexity: O(1)
// Track both max and min because negative numbers flip the result
class Solution {
   public:
    int maxProduct(vector<int>& nums) {
        int currMax = nums[0];  // currMax → best product ending here
        int currMin = nums[0];  // currMin → worst product ending here
        int ans = nums[0];

        for (int i = 1; i < nums.size(); i++) {
            // If negative → swap
            if (nums[i] < 0) {
                swap(currMax, currMin);
            }

            currMax = max(nums[i], currMax * nums[i]);
            currMin = min(nums[i], currMin * nums[i]);

            ans = max(ans, currMax);
        }

        return ans;
    }
};

// Bottom Up DP Approach - Time Complexity: O(n), Space Complexity: O(n)
// class Solution {
//    public:
//     int maxProduct(vector<int>& nums) {
//         int n = nums.size();

//         vector<int> dpMax(n), dpMin(n);

//         // Base case
//         dpMax[0] = nums[0];
//         dpMin[0] = nums[0];

//         int ans = nums[0];

//         for (int i = 1; i < n; i++) {
//             // Three choices:
//             // 1. Start new subarray from nums[i]
//             // 2. Extend previous max
//             // 3. Extend previous min (important for negative)
//             dpMax[i] = max({nums[i],
//                             nums[i] * dpMax[i - 1],
//                             nums[i] * dpMin[i - 1]});

//             dpMin[i] = min({nums[i],
//                             nums[i] * dpMax[i - 1],
//                             nums[i] * dpMin[i - 1]});

//             // Update answer
//             ans = max(ans, dpMax[i]);
//         }

//         return ans;
//     }
// };

int main() {
    vector<int> nums = {1, 2, -3, 4};

    Solution sol;
    cout << sol.maxProduct(nums) << endl;

    return 0;
}