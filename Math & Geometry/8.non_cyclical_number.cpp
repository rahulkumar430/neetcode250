#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    // Helper function to calculate the sum of squared digits.
    int helper(int num) {
        int n = 0;

        while (num > 0) {
            int digit = num % 10;
            n += digit * digit;
            num /= 10;
        }

        return n;
    }

    // Iterative Approach : Time Complexity: O(log N) , Space Complexity: O(log N)
    // bool isHappy(int n) {
    //     unordered_set<int> squaredSet;

    //     while (n != 1 && !squaredSet.contains(n)) {
    //         // Store the current number to detect cycles.
    //         squaredSet.insert(n);

    //         // Calculate the sum of squared digits.
    //         n = helper(n);
    //     }

    //     // True if we reached 1, false if a cycle was detected.
    //     return n == 1;
    // }

    // Floyd's Cycle Detection : Fast and Slow Pointers
    // Time Complexity: O(log N), Space Complexity: O(1)
    bool isHappy(int n) {
        int slow = n;
        int fast = n;

        do {
            // Slow pointer moves one step.
            slow = helper(slow);

            // Fast pointer moves two steps.
            fast = helper(helper(fast));

        } while (slow != fast);

        // If the meeting point is 1, it is a happy number.
        return slow == 1;
    }
};

int main() {
    Solution s;
    int n = 123;
    cout << (s.isHappy(n) ? "true" : "false");

    return 0;
}