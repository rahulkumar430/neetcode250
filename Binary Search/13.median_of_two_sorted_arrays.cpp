#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    // Brute-force approach
    // Time Complexity: O((m + n) log(m + n))
    // Space Complexity: O(m + n)
    // double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    //     int len1 = nums1.size();
    //     int len2 = nums2.size();

    //     // Create a new array to hold all elements from both arrays
    //     vector<int> merged(len1 + len2);

    //     // Copy elements of nums1 into merged
    //     copy(nums1.begin(), nums1.end(), merged.begin());

    //     // Copy elements of nums2 into merged after nums1's elements
    //     copy(nums2.begin(), nums2.end(), merged.begin() + len1);

    //     // Sort the merged array
    //     sort(merged.begin(), merged.end());

    //     int totalLen = merged.size();

    //     // If total length is even, median is the average of the two middle elements
    //     if (totalLen % 2 == 0) {
    //         return (merged[totalLen / 2 - 1] + merged[totalLen / 2]) / 2.0;
    //     }
    //     // If total length is odd, median is the middle element
    //     else {
    //         return merged[totalLen / 2];
    //     }
    // }

    // Merge-based approach using 2 pointers
    // Time Complexity: O(m + n)
    // Space Complexity: O(1)
    // double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    //     int len1 = nums1.size(), len2 = nums2.size();

    //     // Pointers for nums1 and nums2
    //     int i = 0, j = 0;

    //     // median1 holds the current element,
    //     // median2 holds the previous element
    //     int median1 = 0, median2 = 0;

    //     // We only need to iterate until the middle of the merged array
    //     for (int count = 0; count < (len1 + len2) / 2 + 1; count++) {
    //         // Shift median1 to median2 before updating median1
    //         median2 = median1;

    //         // If both arrays still have elements, pick the smaller one
    //         if (i < len1 && j < len2) {
    //             if (nums1[i] > nums2[j]) {
    //                 median1 = nums2[j];
    //                 j++;
    //             } else {
    //                 median1 = nums1[i];
    //                 i++;
    //             }
    //         }
    //         // If nums2 is exhausted, take element from nums1
    //         else if (i < len1) {
    //             median1 = nums1[i];
    //             i++;
    //         }
    //         // If nums1 is exhausted, take element from nums2
    //         else {
    //             median1 = nums2[j];
    //             j++;
    //         }
    //     }

    //     // If total length is odd, median is the middle element
    //     if ((len1 + len2) % 2 == 1) {
    //         return (double)median1;
    //     }
    //     // If total length is even, median is the average of two middle elements
    //     else {
    //         return (median1 + median2) / 2.0;
    //     }
    // }

    // Optimised binary search solution
    // Time Complexity : O(log(m+n)) Space Comlexity: O(1)
    //     double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    //         // Positions of median elements (handles both odd and even length)
    //         int left = (nums1.size() + nums2.size() + 1) / 2;
    //         int right = (nums1.size() + nums2.size() + 2) / 2;

    //         // Median is the average of left-th and right-th smallest elements
    //         return (getKth(nums1, nums1.size(),
    //                        nums2, nums2.size(),
    //                        left, 0, 0) +
    //                 getKth(nums1, nums1.size(),
    //                        nums2, nums2.size(),
    //                        right, 0, 0)) /
    //                2.0;
    //     }

    //    private:
    //     int getKth(vector<int>& a, int m,
    //                vector<int>& b, int n,
    //                int k, int aStart, int bStart) {
    //         // Ensure array 'a' is the smaller one to simplify logic
    //         if (m > n) {
    //             return getKth(b, n, a, m, k, bStart, aStart);
    //         }

    //         // If the smaller array is empty,
    //         // return the k-th element from the other array
    //         if (m == 0) {
    //             return b[bStart + k - 1];
    //         }

    //         // If k == 1, return the minimum of current elements
    //         if (k == 1) {
    //             return min(a[aStart], b[bStart]);
    //         }

    //         // Compare the k/2-th elements of both arrays
    //         int i = min(m, k / 2);
    //         int j = min(n, k / 2);

    //         // If a's k/2-th element is larger,
    //         // discard first j elements of b
    //         if (a[aStart + i - 1] > b[bStart + j - 1]) {
    //             return getKth(a, m,
    //                           b, n - j,
    //                           k - j,
    //                           aStart, bStart + j);
    //         }
    //         // Otherwise, discard first i elements of a
    //         else {
    //             return getKth(a, m - i,
    //                           b, n,
    //                           k - i,
    //                           aStart + i, bStart);
    //         }
    //     }

    // Most Optimal binary seach solution
    // Time Complexity : O(log(min(m, n))) Space Comlexity: O(1)
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        // Ensure nums1 is the smaller array
        if (nums1.size() > nums2.size())
            return findMedianSortedArrays(nums2, nums1);

        int m = nums1.size();
        int n = nums2.size();

        int low = 0, high = m;

        while (low <= high) {
            // Partition index for nums1
            int i = (low + high) / 2;

            // Partition index for nums2
            int j = (m + n + 1) / 2 - i;

            // Boundary elements around the partition
            int maxLeftA = (i == 0) ? INT_MIN : nums1[i - 1];
            int minRightA = (i == m) ? INT_MAX : nums1[i];

            int maxLeftB = (j == 0) ? INT_MIN : nums2[j - 1];
            int minRightB = (j == n) ? INT_MAX : nums2[j];

            // Correct partition found
            if (maxLeftA <= minRightB && maxLeftB <= minRightA) {
                // If total length is even
                if ((m + n) % 2 == 0) {
                    return (max(maxLeftA, maxLeftB) +
                            min(minRightA, minRightB)) /
                           2.0;
                }
                // If total length is odd
                else {
                    return max(maxLeftA, maxLeftB);
                }
            }
            // Move partition left in nums1
            else if (maxLeftA > minRightB) {
                high = i - 1;
            }
            // Move partition right in nums1
            else {
                low = i + 1;
            }
        }

        return 0.0;  // unreachable
    }
};

int main() {
    Solution s;

    vector<int> nums1 = {1, 3};
    vector<int> nums2 = {2, 4};

    cout << s.findMedianSortedArrays(nums1, nums2) << endl;

    return 0;
}
