#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    // Brute-force approach
    // Time Complexity: O(N * max(piles))
    // int minEatingSpeed(vector<int>& piles, int h) {
    //     int speed = 1;
    //     // Try every possible eating speed

    //     while (true) {
    //         long long totalTime = 0;

    //         // Calculate total hours needed at current speed
    //         for (int x : piles) {
    //             // Hours needed for this pile at given speed
    //             // Using integer math for ceil(x / speed)
    //             // ceil(a / b) = (a + b - 1) / b
    //             totalTime += (x + speed - 1) / speed;
    //         }

    //         // If Koko can finish all piles within h hours,
    //         // this is the minimum valid speed
    //         if (totalTime <= h) {
    //             return speed;
    //         }
    //         speed++;
    //     }
    // }

    // Binary Search on answer (eating speed)
    // Time Complexity: O(N * log(max(piles)))
    int minEatingSpeed(vector<int>& piles, int h) {
        // Minimum possible speed is 1 (cannot eat 0 bananas/hour)
        int l = 1;

        // Maximum possible speed is the largest pile
        int r = *max_element(piles.begin(), piles.end());

        int ans = r;  // stores the minimum valid eating speed

        // Binary search on eating speed
        while (l <= r) {
            // Candidate eating speed
            int mid = l + (r - l) / 2;

            long long totalTime = 0;

            // Calculate total hours needed at speed = mid
            for (int x : piles) {
                // ceil(x / mid) gives hours needed for one pile
                totalTime += ceil((double)x / mid);
            }

            // If Koko can finish within h hours,
            // try to minimize the eating speed
            if (totalTime <= h) {
                ans = mid;    // mid is a valid speed
                r = mid - 1;  // try smaller speed
            }
            // Otherwise, speed is too slow
            else {
                l = mid + 1;  // increase speed
            }
        }

        // ans holds the minimum speed that allows finishing within h hours
        return ans;
    }
};

int main() {
    Solution sol;
    vector<int> piles = {1, 4, 3, 2};
    int h = 9;
    cout << sol.minEatingSpeed(piles, h) << endl;

    return 0;
}
