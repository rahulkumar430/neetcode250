#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    // Brute-force approach
    // Time Complexity: O(N * sum(weights))
    // int shipWithinDays(vector<int>& weights, int days) {
    //     int capacity = *max_element(weights.begin(), weights.end());

    //     // Try every possible ship capacity
    //     while (true) {
    //         int daysUsed = 1;
    //         int load = 0;

    //         // Simulate shipping with this capacity
    //         for (int w : weights) {
    //             if (load + w > capacity) {
    //                 daysUsed++;  // need an extra day
    //                 load = 0;
    //             }
    //             load += w;
    //         }

    //         // If we can ship within allowed days, return capacity
    //         if (daysUsed <= days) {
    //             return capacity;
    //         }
    //         capacity++;
    //     }
    // }

    // Binary Search on answer
    // Time Complexity: O(N * log(sum(weights)))
    int shipWithinDays(vector<int>& weights, int days) {
        // Minimum capacity must be at least the heaviest package
        int left = *max_element(weights.begin(), weights.end());
        // Maximum capacity is sum of all packages (ship all in one day)
        int right = accumulate(weights.begin(), weights.end(), 0);

        int ans = right;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            int daysUsed = 1;
            int load = 0;

            // Check if capacity = mid is feasible
            for (int w : weights) {
                if (load + w > mid) {
                    daysUsed++;
                    load = 0;
                }
                load += w;
            }

            // If feasible, try smaller capacity
            if (daysUsed <= days) {
                ans = mid;
                right = mid - 1;
            }
            // Otherwise, increase capacity
            else {
                left = mid + 1;
            }
        }

        return ans;
    }
};

int main() {
    Solution sol;
    vector<int> weights = {2, 4, 6, 1, 3, 10};
    int days = 4;
    cout << sol.shipWithinDays(weights, days) << endl;

    return 0;
}
