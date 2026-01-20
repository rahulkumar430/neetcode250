#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    // Extra space basic approach
    // void rotate(vector<int>& nums, int k) {
    //     int n = nums.size();

    //     // Handle cases where k >= n
    //     // Rotating n times brings the array back to original state
    //     k = k % n;

    //     // Temporary vector to store the rotated result
    //     vector<int> temp;

    //     // Copy the last k elements to the temp vector
    //     // These elements will move to the front after rotation
    //     for (int i = n - k; i < n; i++) {
    //         temp.push_back(nums[i]);
    //     }

    //     // Copy the first (n - k) elements to the temp vector
    //     // These elements will move after the last k elements
    //     for (int i = 0; i < n - k; i++) {
    //         temp.push_back(nums[i]);
    //     }

    //     // Replace the original array with the rotated array
    //     nums = temp;
    // }

    // In place using reverse
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();

        // Handle cases where k >= n
        k = k % n;

        // Step 1: Reverse the entire array
        reverse(nums.begin(), nums.end());

        // Step 2: Reverse the first k elements
        reverse(nums.begin(), nums.begin() + k);

        // Step 3: Reverse the remaining (n - k) elements
        reverse(nums.begin() + k, nums.end());
    }

    // Cyclic traversal solution
    /*
    Rotate an array to the RIGHT by k steps using CYCLIC REPLACEMENT.

    ------------------------------------------------------------
    CORE IDEA
    ------------------------------------------------------------
    Each element at index i moves to:
        newIndex = (i + k) % n

    This mapping forms one or more CYCLES.
    We rotate each cycle in-place.

    ------------------------------------------------------------
    TIME / SPACE
    ------------------------------------------------------------
    Time  : O(n)   (each element moved exactly once)
    Space : O(1)   (in-place)

    ------------------------------------------------------------
    DETAILED EXAMPLE (Index + Value Movement)
    ------------------------------------------------------------
    nums = [1, 2, 3, 4, 5, 6]
    k = 2
    n = 6

    After rotation (right by 2):
    result = [5, 6, 1, 2, 3, 4]

    Index mapping:
    ------------------------------------------------------------
    Cycle 1:
    index : 0 → 2 → 4 → 0
    value : 1 → 3 → 5 → 1
    result :    5 2 1 4 3 6
    movement :  -   -   -
    Cycle 2:
    index : 1 → 3 → 5 → 1
    value : 2 → 4 → 6 → 2
    result :    5 6 1 2 3 4
    movement :    -   -   -
    ------------------------------------------------------------

    Why two cycles?
    gcd(n, k) = gcd(6, 2) = 2 → 2 cycles required
    ------------------------------------------------------------
    */

    // void rotate(vector<int>& nums, int k) {
    //     int n = nums.size();

    //     // Rotating n times gives the same array,
    //     // so reduce k to avoid unnecessary cycles
    //     k = k % n;

    //     // Counts how many elements have been moved so far
    //     int count = 0;

    //     // Start a new cycle from each index until
    //     // all elements are moved
    //     for (int start = 0; count < n; start++) {
    //         int current = start;

    //         // Store the value that will be moved
    //         int prev = nums[start];

    //         /*
    //         Start rotating the current cycle.
    //         Keep moving elements until we return
    //         to the starting index.
    //         */
    //         do {
    //             // Compute the index where the current value should go
    //             int nextIdx = (current + k) % n;

    //             // Save the value at nextIdx before overwriting
    //             int temp = nums[nextIdx];

    //             // Move the previous value into its rotated position
    //             nums[nextIdx] = prev;

    //             // Prepare for the next move in the cycle
    //             prev = temp;
    //             current = nextIdx;

    //             // One element has been placed correctly
    //             count++;

    //         } while (current != start);  // Cycle completed
    //     }
    // }

    // One liner using existing stl
    // void rotate(vector<int>& nums, int k) {
    //     std::rotate(nums.begin(), nums.end() - (k % nums.size()), nums.end());
    // }
};

int main() {
    vector<int> nums = {1, 2, 3, 4, 5, 6, 7, 8, 9};

    int k = 4;
    Solution sol;
    sol.rotate(nums, k);

    for (auto x : nums) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}