#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    // Brute force - O(N^2) Complexity
    // int maxArea(vector<int>& heights) {
    //     // Stores the maximum amount of water found so far
    //     int ans = 0;

    //     // Pick the first line
    //     for (int i = 0; i < heights.size(); i++) {
    //         // Pick the second line
    //         for (int j = 0; j < heights.size(); j++) {
    //             /*
    //             The water stored between two lines depends on:
    //             1. The shorter of the two heights
    //             2. The horizontal distance between them (j - i)
    //             */
    //             int waterStored =
    //                 min(heights[i], heights[j]) * (j - i);

    //             // Update the maximum area if current area is larger
    //             ans = max(ans, waterStored);
    //         }
    //     }

    //     // Return the maximum water that can be stored
    //     return ans;
    // }

    // Optimised Approach - O(N) Complexity
    int maxArea(vector<int>& heights) {
        // Stores the maximum amount of water found so far
        int ans = 0;

        int l = 0;                   // Left pointer starts at the beginning
        int r = heights.size() - 1;  // Right pointer starts at the end

        // Continue until the two pointers meet
        while (l < r) {
            /*
            Water stored between two lines is determined by:
            1. The shorter of the two heights
            2. The distance between them (r - l)
            */
            int waterStored =
                min(heights[l], heights[r]) * (r - l);

            // Update the maximum area if the current one is larger
            ans = max(ans, waterStored);

            /*
            POINTER MOVEMENT LOGIC (MOST IMPORTANT PART):

            - The height of the container is limited by the SHORTER line.
            - Moving the taller line inward CANNOT increase the height.
            - Only moving the SHORTER line might find a taller boundary.

            Case 1:
            heights[l] < heights[r]
            → Left line is shorter
            → Height is limited by heights[l]
            → Move left pointer to possibly find a taller line

            Case 2:
            heights[l] >= heights[r]
            → Right line is shorter (or equal)
            → Height is limited by heights[r]
            → Move right pointer inward
            */
            heights[l] < heights[r] ? l++ : r--;
        }

        // Return the maximum water that can be stored
        return ans;
    }
};

int main() {
    vector<int> heights = {1, 7, 2, 5, 4, 7, 3, 6};

    Solution sol;
    cout << sol.maxArea(heights);

    return 0;
}