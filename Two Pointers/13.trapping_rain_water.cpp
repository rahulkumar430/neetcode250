#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    // Brute force way : O(N^2) time complexity
    // int trap(vector<int>& height) {
    //     // Stores the total amount of trapped water
    //     int ans = 0;

    //     // We iterate from index 1 to (n - 2) because First and last bars cannot trap water
    //     for (int i = 1; i < height.size() - 1; i++) {
    //         // Find the maximum height on the LEFT side of index i including i
    //         int left = height[i];
    //         for (int j = 0; j < i; j++) {
    //             left = max(left, height[j]);
    //         }

    //         // Find the maximum height on the RIGHT side of index i including i
    //         int right = height[i];
    //         for (int j = i + 1; j < height.size(); j++) {
    //             right = max(right, height[j]);
    //         }

    //         // Water trapped at index i
    //         ans += min(left, right) - height[i];
    //     }

    //     // Return the total trapped water
    //     return ans;
    // }

    // A little optimisation with space complexity O(N) and O(N) time complexity
    // int trap(vector<int>& height) {
    //     int ans = 0;
    //     int n = height.size();

    //     // l[i] will store the maximum height to the left of i (including i)
    //     // r[i] will store the maximum height to the right of i (including i)
    //     vector<int> l(n);
    //     vector<int> r(n);

    //     // Initialize boundary values
    //     l[0] = height[0];
    //     r[n - 1] = height[n - 1];

    //     // Build left max array
    //     for (int i = 1; i < n; i++) {
    //         l[i] = max(l[i - 1], height[i]);
    //     }

    //     // Build right max array
    //     for (int i = n - 2; i >= 0; i--) {
    //         r[i] = max(r[i + 1], height[i]);
    //     }

    //     // Calculate trapped water at each index
    //     for (int i = 0; i < n; i++) {
    //         ans += min(l[i], r[i]) - height[i];
    //     }

    //     return ans;
    // }

    // Most Optimised Approach with space complexity O(1) and O(N) time complexity
    // int trap(vector<int>& height) {
    //     int ans = 0;
    //     int n = height.size();

    //     // Maximum height seen so far from the left
    //     int left_max = 0;

    //     // Maximum height seen so far from the right
    //     int right_max = 0;

    //     // Pointer starting from the left end
    //     int low = 0;

    //     // Pointer starting from the right end
    //     int high = n - 1;

    //     // Process until the two pointers cross
    //     while (low <= high) {
    //         /*
    //         The side with the smaller height determines
    //         the maximum water that can be trapped.
    //         */
    //         if (height[low] < height[high]) {
    //             // Update left_max if current bar is taller
    //             if (height[low] > left_max) {
    //                 left_max = height[low];
    //             }
    //             // Otherwise, water can be trapped at this index
    //             else {
    //                 ans += left_max - height[low];
    //             }

    //             // Move left pointer inward
    //             low++;

    //         } else {
    //             // Update right_max if current bar is taller
    //             if (height[high] > right_max) {
    //                 right_max = height[high];
    //             }
    //             // Otherwise, water can be trapped at this index
    //             else {
    //                 ans += right_max - height[high];
    //             }

    //             // Move right pointer inward
    //             high--;
    //         }
    //     }

    //     return ans;
    // }

    // Most Optimised Approach(with Code simplication from above answer) with space complexity O(1) and O(N) time complexity
    int trap(vector<int>& height) {
        int ans = 0;
        int n = height.size();

        // Maximum height seen so far from the left
        int left_max = 0;

        // Maximum height seen so far from the right
        int right_max = 0;

        // Pointer starting from the left end
        int low = 0;

        // Pointer starting from the right end
        int high = n - 1;

        // Process until the two pointers cross
        while (low <= high) {
            /*
            The side with the smaller height determines
            the maximum water that can be trapped.
            */
            if (height[low] < height[high]) {
                // Update left_max if current bar is taller
                left_max = max(left_max, height[low]);
                // Otherwise, water can be trapped at this index
                ans += left_max - height[low];
                // Move left pointer inward
                low++;

            } else {
                // Update right_max if current bar is taller
                right_max = max(right_max, height[high]);
                // Otherwise, water can be trapped at this index
                ans += right_max - height[high];
                // Move right pointer inward
                high--;
            }
        }

        return ans;
    }
};

int main() {
    vector<int> height = {0, 2, 0, 3, 1, 0, 1, 3, 2, 1};

    Solution sol;
    cout << sol.trap(height);

    return 0;
}