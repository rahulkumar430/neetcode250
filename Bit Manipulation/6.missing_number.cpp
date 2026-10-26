#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    // Brute Force Apporach : Time Complexity: O(N^2), Space Complexity: O(1)
    // int missingNumber(vector<int>& nums) {
    //     int n = nums.size();

    //     for (int i = 0; i <= n; i++) {
    //         bool found = false;

    //         for (int num : nums) {
    //             if (num == i) {
    //                 found = true;
    //                 break;
    //             }
    //         }

    //         if (!found) return i;
    //     }

    //     return -1;
    // }

    // Naive Sorting Apporach : Time Complexity: O(N log N), Space Complexity: O(logN) for sorting
    // int missingNumber(vector<int>& nums) {
    //     sort(nums.begin(), nums.end());
    //     for (int i = 0; i < nums.size(); i++) {
    //         if (i != nums[i])
    //             return i;
    //     }
    //     return nums.size();
    // }

    // Optimised Hash Method : Time Complexity: O(N), Space Complexity: O(N)
    // int missingNumber(vector<int>& nums) {
    //     unordered_set<int> s(nums.begin(), nums.end());

    //     for (int i = 0; i <= nums.size(); i++) {
    //         if (!s.count(i))
    //             return i;
    //     }

    //     return -1;
    // }

    // Optimal Mathematical Sum Approach : Time Complexity: O(N), Space Complexity: O(1)
    // int missingNumber(vector<int>& nums) {
    //     int n = nums.size();
    //     int expected = n * (n + 1) / 2;
    //     int actual = 0;

    //     for (int num : nums)
    //         actual += num;

    //     return expected - actual;
    // }

    // Optimal XOR Approach : Time Complexity: O(N), Space Complexity: O(1)
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int ans = n;  // Imp. to choose this as n, because in for loop we are excluding xor with n

        for (int i = 0; i < n; i++)
            // XOR cancels matching values, leaving the missing number
            ans = nums[i] ^ i ^ ans;

        return ans;
    }
};

int main() {
    Solution s;
    vector<int> nums = {1, 2, 3};

    cout << s.missingNumber(nums) << endl;

    return 0;
}