#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    // Brute-force solution - Time Complexity: O(N * K), Space Complexity: O(1)
    // vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    //     vector<int> ans;
    //     int n = nums.size();

    //     // Slide the window starting index
    //     for (int i = 0; i <= n - k; i++) {
    //         int maxInsideWindow = INT_MIN;

    //         // Find maximum in the current window [i .. i + k - 1]
    //         for (int j = i; j < i + k; j++) {
    //             maxInsideWindow = max(maxInsideWindow, nums[j]);
    //         }

    //         // Store the maximum of the current window
    //         ans.push_back(maxInsideWindow);
    //     }

    //     return ans;
    // }

    // Little optimised but still worst case Brute-force solution - Time Complexity: O(N * K)(worst case), Space Complexity: O(1)
    // vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    //     vector<int> ans;

    //     int l = 0;                      // Left boundary of the window
    //     int maxInsideWindow = INT_MIN;  // Maximum element in the current window
    //     int n = nums.size();

    //     for (int r = 0; r < n; r++) {
    //         // Expand the window until its size becomes k
    //         if (r - l + 1 <= k) {
    //             maxInsideWindow = max(maxInsideWindow, nums[r]);
    //         }

    //         // Once window size exceeds k, slide the window
    //         if (r - l + 1 > k) {
    //             // Store the maximum of the previous valid window
    //             ans.push_back(maxInsideWindow);

    //             /*
    //             If the element leaving the window was the maximum,
    //             we must recompute the maximum for the new window
    //             */
    //             if (nums[l] == maxInsideWindow) {
    //                 maxInsideWindow = INT_MIN;
    //                 for (int i = l + 1; i <= r; i++) {
    //                     maxInsideWindow = max(maxInsideWindow, nums[i]);
    //                 }
    //             } else {
    //                 // Otherwise, only compare with the new element
    //                 maxInsideWindow = max(maxInsideWindow, nums[r]);
    //             }

    //             // Move the left pointer forward
    //             l++;
    //         }
    //     }

    //     // Push the maximum of the last window
    //     ans.push_back(maxInsideWindow);

    //     return ans;
    // }

    // Sliding Window Maximum using Priority Queue (Max Heap)
    // Time Complexity: O(N log N)
    // Space Complexity: O(N)
    // vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    //     vector<int> ans;

    //     /*
    //     Max heap storing pairs of:
    //     {value, index}
    //     - value is used to get the maximum
    //     - index helps discard elements outside the window
    //     */
    //     priority_queue<pair<int, int>> pq;

    //     for (int i = 0; i < nums.size(); i++) {
    //         // Push current element with its index
    //         pq.push({nums[i], i});

    //         /*
    //         Remove elements from the heap that are
    //         outside the current window [i - k + 1, i]
    //         */
    //         while (!pq.empty() && pq.top().second <= i - k) {
    //             pq.pop();
    //         }

    //         // Once the first window is fully formed,
    //         // record the maximum for each window
    //         if (i >= k - 1) {
    //             ans.push_back(pq.top().first);
    //         }
    //     }

    //     return ans;
    // }

    // Optimal Sliding Window Maximum using Deque (You can also use a priority queue but this one is better)
    // Time Complexity: O(N)
    // Space Complexity: O(K)
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans;

        /*
        Deque stores indices of elements.
        It maintains elements in decreasing order of values.
        Front of deque always holds the index of the maximum element.
        */
        deque<int> dq;

        for (int i = 0; i < nums.size(); i++) {
            /*
            Remove indices from the front that are
            outside the current window [i - k + 1, i]
            */
            if (!dq.empty() && dq.front() <= i - k) {
                dq.pop_front();
            }

            /*
            Remove indices from the back whose values
            are smaller than the current element.
            They will never be needed again.
            */
            while (!dq.empty() && nums[dq.back()] < nums[i]) {
                dq.pop_back();
            }

            // Add current element index to the deque
            dq.push_back(i);

            /*
            Once the first window is fully formed,
            record the maximum (front of deque)
            */
            if (i >= k - 1) {
                ans.push_back(nums[dq.front()]);
            }
        }

        return ans;
    }
};

int main() {
    vector<int> nums = {1, 2, 1, 0, 4, 2, 6};
    int k = 3;

    Solution sol;
    vector<int> ans;
    ans = sol.maxSlidingWindow(nums, k);

    for (int i : ans) {
        cout << i << "  ";
    }

    return 0;
}