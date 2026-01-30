#include <bits/stdc++.h>
using namespace std;

// This simulates the picked number
int pickedNumber = 6;

// Mock guess API as described in the problem
int guess(int num) {
    if (num > pickedNumber) return -1;
    if (num < pickedNumber) return 1;
    return 0;
}

class Solution {
   public:
    // Brute-force approach - Time Complexity: O(N)
    // int guessNumber(int n) {
    //     // Try every number from 1 to n
    //     for (int num = 1; num <= n; num++) {
    //         // guess(num) returns:
    //         //  0  -> correct guess
    //         // -1  -> num is higher than the picked number
    //         //  1  -> num is lower than the picked number
    //         if (guess(num) == 0) {
    //             return num;  // found the picked number
    //         }
    //     }

    //     // Fallback (the picked number must be within [1, n])
    //     return n;
    // }

    // Binary Search - Time Complexity: O(log N)
    int guessNumber(int n) {
        int l = 1;
        int r = n;

        while (l <= r) {
            int mid = l + (r - l) / 2;

            int res = guess(mid);

            if (res == 0) {
                return mid;  // correct guess
            } else if (res == 1) {
                l = mid + 1;  // mid is smaller than picked number
            } else {
                r = mid - 1;  // mid is larger than picked number
            }
        }

        return -1;  // should never happen
    }
};

int main() {
    Solution sol;

    int n = 10;
    cout << sol.guessNumber(n) << endl;

    return 0;
}
