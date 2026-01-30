#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    // Brute force solution - Time Complexity O(N^3), Space Complexity O(1)
    // int largestRectangleArea(vector<int>& heights) {
    //     int ans = INT_MIN;  // Stores the maximum rectangle area found

    //     // Fix the left boundary of the rectangle
    //     for (int i = 0; i < heights.size(); i++) {
    //         // Fix the right boundary of the rectangle
    //         for (int j = i; j < heights.size(); j++) {
    //             int minHeight = INT_MAX;  // Minimum height in the range [i, j]

    //             // Find the minimum height between indices i and j
    //             // This height limits the rectangle's height
    //             for (int k = i; k <= j; k++) {
    //                 minHeight = min(minHeight, heights[k]);
    //             }

    //             // Calculate area using:
    //             // height = minHeight
    //             // width  = (j - i + 1)
    //             ans = max(ans, minHeight * (j - i + 1));
    //         }
    //     }

    //     // Return the maximum area found
    //     return ans;
    // }

    // Another Brute force approach - Time Complexity O(N^2), Space Complexity O(1)
    // int largestRectangleArea(vector<int>& heights) {
    //     int n = heights.size();
    //     int maxArea = 0;

    //     // Consider each bar as the minimum height of a rectangle
    //     for (int i = 0; i < n; i++) {
    //         int height = heights[i];

    //         // Find how far this bar can extend to the right
    //         int rightLimit = i + 1;
    //         while (rightLimit < n && heights[rightLimit] >= height) {
    //             rightLimit++;
    //         }

    //         // Find how far this bar can extend to the left
    //         int leftLimit = i;
    //         while (leftLimit >= 0 && heights[leftLimit] >= height) {
    //             leftLimit--;
    //         }

    //         // Adjust boundaries to the last valid indices
    //         rightLimit--;  // last index where height >= current bar
    //         leftLimit++;   // first index where height >= current bar

    //         // Calculate area using:
    //         // height = current bar height
    //         // width  = rightLimit - leftLimit + 1
    //         maxArea = max(maxArea, height * (rightLimit - leftLimit + 1));
    //     }

    //     return maxArea;
    // }

    // Optmised approach - Time Complexity O(N), Space Complexity O(N)
    // int largestRectangleArea(vector<int>& heights) {
    //     int n = heights.size();
    //     vector<int> leftLimit(n), rightLimit(n);
    //     stack<int> st;

    //     // Step 1: Nearest smaller to the left
    //     // leftLimit[i] = index of nearest smaller bar to the left of i
    //     // if none exists, set to -1
    //     for (int i = 0; i < n; i++) {
    //         // Remove bars taller or equal to current
    //         while (!st.empty() && heights[st.top()] >= heights[i]) {
    //             st.pop();
    //         }

    //         // If stack is empty, no smaller bar on the left
    //         leftLimit[i] = st.empty() ? -1 : st.top();

    //         // Push current index
    //         st.push(i);
    //     }

    //     // Clear stack
    //     while (!st.empty()) st.pop();

    //     // Step 2: Nearest smaller to the right
    //     // rightLimit[i] = index of nearest smaller bar to the right of i
    //     // if none exists, set to n
    //     for (int i = n - 1; i >= 0; i--) {
    //         // Remove bars taller or equal to current
    //         while (!st.empty() && heights[st.top()] >= heights[i]) {
    //             st.pop();
    //         }

    //         // If stack is empty, no smaller bar on the right
    //         rightLimit[i] = st.empty() ? n : st.top();

    //         // Push current index
    //         st.push(i);
    //     }

    //     // Step 3: Compute max area
    //     int maxArea = 0;
    //     for (int i = 0; i < n; i++) {
    //         int width = rightLimit[i] - leftLimit[i] - 1;
    //         maxArea = max(maxArea, heights[i] * width);
    //     }

    //     return maxArea;
    // }

    // Most Optimal way - Time Complexity O(N), Space Complexity O(N)
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        stack<int> st;  // stores indices of bars
        int maxArea = 0;

        // Traverse all bars
        // As long as heights are increasing → push
        // If a smaller height appears → pop until order is restored
        for (int i = 0; i < n; i++) {
            // While the current bar is smaller than the bar at stack top,
            // the stack top bar cannot extend further to the right
            while (!st.empty() && heights[st.top()] >= heights[i]) {
                // Height of the rectangle is the height of the popped bar
                int height = heights[st.top()];
                st.pop();

                // Determine width:
                // If stack is empty, this bar can extend from index 0 to i-1
                // Else, it extends from (st.top() + 1) to (i - 1)
                int rightBoundary = i - 1;
                int leftBoundary = st.empty() ? 0 : st.top() + 1;

                int width = rightBoundary - leftBoundary + 1;
                maxArea = max(maxArea, height * width);
            }

            // Push current bar index
            st.push(i);
        }

        // Process remaining bars in stack
        while (!st.empty()) {
            int height = heights[st.top()];
            st.pop();

            // If stack is empty, bar extends from 0 to n-1
            // Else, from (st.top() + 1) to n-1
            int rightBoundary = n - 1;
            int leftBoundary = st.empty() ? 0 : st.top() + 1;

            int width = rightBoundary - leftBoundary + 1;
            maxArea = max(maxArea, height * width);
        }

        return maxArea;
    }
};

int main() {
    Solution s;
    vector<int> heights = {7, 1, 7, 2, 2, 4};

    cout << s.largestRectangleArea(heights) << endl;
    return 0;
}