#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    // BRUTEFORCE APPROACH (O(n^2) time) - Commented out
    // For each position i, multiply all other elements (skip nums[i])
    // vector<int> productExceptSelf(vector<int>& nums) {
    //     vector<int> ans;
    //     for (int i = 0; i < nums.size(); i++) {
    //         int mul = 1;
    //         for (int j = 0; j < nums.size(); j++) {
    //             if (i == j)
    //                 continue;  // Skip current element
    //             mul *= nums[j];
    //         }
    //         ans.push_back(mul);
    //     }
    //     return ans;
    // }

    // OPTIMIZED SOLUTION - O(n) time, O(1) extra space (excluding output array)
    // Uses LEFT-to-RIGHT (prefix) and RIGHT-to-LEFT (suffix) product passes
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();

        // Initialize 3 vectors of size n: prefix/suffix start with 1s
        // prefix[i] will store product of elements LEFT of i (excluding i)
        // suffix[i] will store product of elements RIGHT of i (excluding i)
        vector<int> prefix(n, 1), suffix(n, 1), ans(n);

        // LEFT PASS: Calculate prefix products (products to the LEFT of each index)
        // prefix[0] = 1 (nothing to left)
        // prefix[1] = nums[0]
        // prefix[2] = nums[0] * nums[1]
        for (int i = 1; i < n; i++) {
            prefix[i] = prefix[i - 1] * nums[i - 1];
        }

        // RIGHT PASS: Calculate suffix products (products to the RIGHT of each index)
        // suffix[n-1] = 1 (nothing to right)
        // suffix[n-2] = nums[n-1]
        // suffix[n-3] = nums[n-2] * nums[n-1]
        for (int i = n - 2; i >= 0; i--) {
            suffix[i] = suffix[i + 1] * nums[i + 1];
        }

        // COMBINE: For each i, result = (left product) * (right product)
        // ans[i] = prefix[i] * suffix[i] = product of all except nums[i]
        for (int i = 0; i < n; i++) {
            ans[i] = prefix[i] * suffix[i];
        }

        return ans;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {1, 2, 4, 6};

    vector<int> ans = sol.productExceptSelf(nums);
    for (int x : ans) {
        cout << x << " ";
    }
    cout << endl;
    return 0;
}
