#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    // Naive Approach : Time Complexity: O(1), Space Complexity: O(1)
    // int reverse(int x) {
    //     // Handle INT_MIN edge case because multiplying it by -1 overflows
    //     if (x == INT_MIN) return 0;

    //     string s = to_string(abs(x));
    //     std::reverse(s.begin(), s.end());

    //     // Use a long long to safely check for overflow
    //     long long reversed_val = stoll(s);

    //     // Re-apply the negative sign if needed
    //     if (x < 0) {
    //         reversed_val = -reversed_val;
    //     }

    //     // Check if the result fits inside standard 32-bit INT limits
    //     if (reversed_val > INT_MAX || reversed_val < INT_MIN) {
    //         return 0;
    //     }

    //     return (int)reversed_val;
    // }

    // Math Approach : Time Complexity: O(1), Space Complexity: O(1)
    int reverse(int x) {
        long long reversed_val = 0;

        while (x != 0) {
            // Extract the last digit, module handles the -ve numbers as well
            int last_digit = x % 10;

            // Append the digit to the running total
            reversed_val = (reversed_val * 10) + last_digit;

            // Remove the last digit from x
            x /= 10;
        }

        // Check for 32-bit integer overflow
        if (reversed_val > INT_MAX || reversed_val < INT_MIN) {
            return 0;
        }

        return static_cast<int>(reversed_val);
    }
};

int main() {
    Solution s;
    int x = 12345;

    cout << s.reverse(x) << endl;

    return 0;
}