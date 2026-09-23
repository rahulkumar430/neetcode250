#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    // Brute Force Approach : Time Complexity: O(N) , Space Complexity: O(1)
    // double myPow(double x, int n) {
    //     double ans = 1;
    //     // cannot be represented by a 32-bit signed int.
    //     long long power = abs((long long)n);
    //     while (power--) {
    //         ans *= x;
    //     }
    //     return (n >= 0) ? ans : 1 / ans;
    // }

    // Binary Exponentiation - Recursive Approach
    // Time Complexity: O(log |n|), Space Complexity: O(log |n|) due to recursion stack
    // double powerRecursion(double x, long long n) {
    //     // Base case: x^0 = 1
    //     if (n == 0)
    //         return 1.0;

    //     // Calculate x^(n / 2)
    //     double power = powerRecursion(x, n / 2);

    //     // If exponent is even
    //     if (n % 2 == 0) {
    //         return power * power;
    //     }

    //     // If exponent is odd
    //     return power * power * x;
    // }

    // double myPow(double x, int n) {
    //     long long power = n;

    //     // Handle negative exponent
    //     if (power < 0) {
    //         x = 1 / x;
    //         power = -power;
    //     }

    //     return powerRecursion(x, power);
    // }

    // Binary Exponentiation - Iterative Approach
    // Time Complexity: O(log |n|), Space Complexity: O(1)
    double myPow(double x, int n) {
        long long power = n;

        // Handle negative exponent
        if (power < 0) {
            x = 1 / x;
            power = -power;
        }

        double ans = 1.0;

        while (power > 0) {
            // If the current exponent is odd,
            // multiply the answer by the current base
            if (power & 1) {
                ans *= x;
            }

            // Square the base
            x *= x;

            // Divide the exponent by 2
            power >>= 1;
        }

        return ans;
    }
};

int main() {
    Solution s;
    double x = 2.00000;
    int n = -3;

    cout << s.myPow(x, n) << endl;

    return 0;
}