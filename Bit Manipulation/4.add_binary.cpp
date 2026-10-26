#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    // Naive Iterative Apporach : Time Complexity: O(max(N, M)), Space Complexity: O(max(N, M))
    // string addBinary(string a, string b) {
    //     int i = a.size() - 1, j = b.size() - 1, carry = 0;
    //     string res;

    //     // Add bits from right to left, including any remaining carry
    //     while (i >= 0 || j >= 0 || carry) {
    //         int n1 = (i >= 0) ? a[i] - '0' : 0;
    //         int n2 = (j >= 0) ? b[j] - '0' : 0;
    //         int total = (n1 ^ n2) ^ carry;
    //         // If any pair contains two 1s, the outgoing carry becomes 1
    //         carry = (n1 & n2) | (n1 & carry) | (n2 & carry);

    //         res.push_back(total + '0');

    //         i--;
    //         j--;
    //     }

    //     // Reverse to restore the correct binary number order
    //     reverse(res.begin(), res.end());
    //     return res;
    // }

    // Optimal Interative Approach : Time Complexity: O(max(N, M)), Space Complexity: O(max(N, M))
    string addBinary(string a, string b) {
        int i = a.size() - 1, j = b.size() - 1, carry = 0;
        string res;

        // Add bits from right to left, including any remaining carry
        while (i >= 0 || j >= 0 || carry) {
            int n1 = (i >= 0) ? a[i] - '0' : 0;
            int n2 = (j >= 0) ? b[j] - '0' : 0;

            int total = n1 + n2 + carry;

            res.push_back((total % 2) + '0');
            carry = total / 2;

            i--;
            j--;
        }

        // Reverse to restore the correct binary number order
        reverse(res.begin(), res.end());

        return res;
    }
};

int main() {
    Solution s;
    string a = "10010", b = "111";

    cout << s.addBinary(a, b) << endl;

    return 0;
}