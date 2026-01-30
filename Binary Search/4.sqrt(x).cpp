#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    // Brute-force approach - Time Complexity: O(N)
    // int mySqrt(int x) {
    //     // Handle edge cases
    //     if (x == 0 || x == 1)
    //         return x;

    //     // Try all possible integers from 1 onwards
    //     for (int i = 1; i <= x / 2; i++) {
    //         // Use long long to avoid overflow while squaring
    //         long long square = 1LL * i * i;

    //         // If exact square is found, return i
    //         if (square == x)
    //             return i;

    //         // If square exceeds x, previous i is the answer
    //         if (square > x)
    //             return i - 1;
    //     }

    //     // Fallback (should not be reached)
    //     return x / 2;
    // }

    // Optimal Binary Search Approach - Time Complexity: O(log N)
    int mySqrt(int x) {
        // Handle edge cases
        if (x == 0 || x == 1)
            return x;

        int left = 1;
        int right = x / 2;  // sqrt(x) cannot be greater than x/2 for x >= 2
        int ans = 0;

        // Standard binary search
        while (left <= right) {
            // Calculate mid safely to avoid overflow
            int mid = left + (right - left) / 2;

            // Use long long to avoid overflow when squaring
            long long square = 1LL * mid * mid;

            // If mid*mid equals x, mid is the exact square root
            if (square == x) {
                return mid;
            }
            // If mid*mid is smaller, try to find a larger value
            else if (square < x) {
                ans = mid;  // store last valid mid
                left = mid + 1;
            }
            // If mid*mid is larger, search the left half
            else {
                right = mid - 1;
            }
        }

        // ans holds the integer part of sqrt(x)
        return ans;

        // When the loop ends, right points to the largest value
        // whose square is <= x, which is the integer square root
        // In this case, we don't have to write this line in else if case : ans = mid;
        // return right;
    }
};

int main() {
    Solution sol;

    int x = 13;
    cout << sol.mySqrt(x) << endl;

    return 0;
}
