#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    // Iterative Apporach : Time Complexity: O(N * M), Space Complexity: O(N + M)
    string multiply(string num1, string num2) {
        string ans = "";

        // Edge case : incase a number is zero
        if (num1 == "0" || num2 == "0")
            return "0";

        // Keep num1 as the longer string to reduce iterations.
        if (num1.length() < num2.length())
            return multiply(num2, num1);

        int zero = 0;

        // Multiply num1 by each digit of num2 from right to left.
        for (int i = num2.length() - 1; i >= 0; i--, zero++) {
            string mul = multiplyHelper(num2[i], num1, zero);

            // Add the current partial product to the answer.
            ans = additionHelper(ans, mul);
        }

        return ans;
    }

    // Multiply a number string by a single digit and append trailing zeros.
    string multiplyHelper(char n, string num1, int zero) {
        int i = num1.size() - 1, carry = 0;
        int digit = n - '0';
        string res;

        // Multiply each digit and propagate the carry.
        while (i >= 0 || carry) {
            int n = (i >= 0) ? num1[i] - '0' : 0;
            int prod = n * digit + carry;
            res.push_back((prod % 10) + '0');
            carry = prod / 10;
            i--;
        }

        // Digits were collected in reverse order.
        reverse(res.begin(), res.end());

        // Shift the partial product according to the digit's place value.
        res.append(zero, '0');

        return res;
    }

    // Add two number strings without converting them to integers.
    string additionHelper(string num1, string num2) {
        int i = num1.size() - 1, j = num2.size() - 1, carry = 0;
        string res;

        // Add corresponding digits from right to left.
        while (i >= 0 || j >= 0 || carry) {
            int n1 = (i >= 0) ? num1[i] - '0' : 0;
            int n2 = (j >= 0) ? num2[j] - '0' : 0;
            int total = n1 + n2 + carry;

            res.push_back((total % 10) + '0');
            carry = total / 10;

            i--;
            j--;
        }

        // Reverse to restore the correct digit order.
        reverse(res.begin(), res.end());
        return res;
    }
};

int main() {
    Solution s;
    string num1 = "987", num2 = "222";

    cout << s.multiply(num1, num2) << endl;

    return 0;
}