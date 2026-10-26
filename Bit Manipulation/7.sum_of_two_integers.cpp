#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    // Bit Manipulation Approach: Time Complexity: O(32), Space Complexity: O(1)
    // int getSum(int a, int b) {
    //     uint32_t x = a, y = b, ans = 0;
    //     int carry = 0;

    //     for (int i = 0; i < 32; i++) {
    //         // Extract the rightmost bit from both numbers.
    //         int n1 = x & 1;
    //         int n2 = y & 1;

    //         // Calculate the sum bit using XOR and determine the outgoing carry.
    //         int total = n1 ^ n2 ^ carry;
    //         carry = (n1 & n2) | (n1 & carry) | (n2 & carry);

    //         // Place the sum bit at its original bit position.
    //         ans |= (uint32_t)total << i;

    //         // Remove the processed rightmost bit from both numbers.
    //         x >>= 1;
    //         y >>= 1;
    //     }

    //     return (int)ans;
    // }

    // Optimal XOR Approach: Time Complexity: O(1), Space Complexity: O(1)
    int getSum(int a, int b) {
        while (b != 0) {
            // Find carry bits where both bits are 1, then shift them to the next position.
            int carry = (a & b) << 1;

            // Calculate the partial sum without carry using XOR.
            a = a ^ b;

            // Add the pending carry in the next iteration.
            b = carry;
        }

        // When no carry remains, a contains the final sum.
        return a;
    }
};

int main() {
    Solution s;
    int a = 4, b = -7;

    cout << s.getSum(a, b) << endl;

    return 0;
}