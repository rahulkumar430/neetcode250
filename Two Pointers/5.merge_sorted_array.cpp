#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    // Basic two pointers approach with taking O(N) Space
    // void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    //     vector<int> ans;     // Extra array to store merged result
    //     ans.reserve(m + n);  // Optional: avoid reallocations

    //     int i = 0, j = 0;

    //     // Merge like in merge-sort: pick smaller of nums1[i], nums2[j]
    //     while (i < m && j < n) {
    //         if (nums1[i] <= nums2[j]) {
    //             ans.push_back(nums1[i++]);
    //         } else {
    //             ans.push_back(nums2[j++]);
    //         }
    //     }

    //     // Push remaining elements from nums1 (if any)
    //     while (i < m) {
    //         ans.push_back(nums1[i++]);
    //     }

    //     // Push remaining elements from nums2 (if any)
    //     while (j < n) {
    //         ans.push_back(nums2[j++]);
    //     }

    //     // Copy result back into nums1
    //     for (int k = 0; k < m + n; k++) {
    //         nums1[k] = ans[k];
    //     }
    // }

    // Optimised approach with in place modification: O(m+n) time and O(1) space complexity
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = m - 1;      // Last valid element in nums1
        int j = n - 1;      // Last element in nums2
        int k = m + n - 1;  // Last position in nums1 (total size)

        // Merge from the back while both arrays have elements
        while (i >= 0 && j >= 0) {
            if (nums1[i] > nums2[j]) {
                nums1[k--] = nums1[i--];  // Place larger nums1[i] at the end
            } else {
                nums1[k--] = nums2[j--];  // Place larger/equal nums2[j] at the end
            }
        }

        // If any elements remain in nums2, copy them (nums1's remaining elements are already in place)
        while (j >= 0) {
            nums1[k--] = nums2[j--];
        }
    }
};

int main() {
    vector<int> nums1 = {10, 20, 20, 40, 0, 0};  // size = m + n, last n are placeholders
    vector<int> nums2 = {1, 2};
    int m = 4;  // number of valid elements in nums1
    int n = 2;  // number of elements in nums2

    Solution sol;
    sol.merge(nums1, m, nums2, n);

    // Print merged nums1
    for (int x : nums1) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}