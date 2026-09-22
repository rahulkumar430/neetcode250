#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    // Brute Force Mathematical Approach : Time Complexity: O(N), Space Complexity: O(N)
    // vector<int> plusOne(vector<int>& digits) {
    //     long int num = 0;  // using long int instead of int to avoid overflow due to large number

    //     // Convert the vector of digits into an integer.
    //     for (int digit : digits) {
    //         num = num * 10 + digit;
    //     }

    //     // Add one to the number.
    //     num++;

    //     vector<int> ans;

    //     // Extract digits from the number in reverse order.
    //     while (num > 0) {
    //         ans.push_back(num % 10);
    //         num /= 10;
    //     }

    //     // Reverse the digits to restore the original order.
    //     reverse(ans.begin(), ans.end());

    //     return ans;
    // }

    // Optimised Approach : Time Complexity: O(N) , Space Complexity: O(1)
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();

        // Traverse from the last digit to the first.
        for (int i = n - 1; i >= 0; i--) {
            // If the digit is less than 9, increment and return.
            if (digits[i] < 9) {
                digits[i]++;
                return digits;
            }

            // If the digit is 9, set it to 0 and carry forward.
            digits[i] = 0;
        }

        // If all digits were 9, add 1 at the beginning.
        digits.insert(digits.begin(), 1);

        return digits;
    }
};

int main() {
    Solution s;
    vector<int> digits = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0};

    vector<int> ans = s.plusOne(digits);

    for (int x : ans)
        cout << x << " ";

    return 0;
}