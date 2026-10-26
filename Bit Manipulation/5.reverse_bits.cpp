#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    // Naive Iterative Apporach : Time Complexity: O(N), Space Complexity: O(N)
    // uint32_t reverseBits(uint32_t n) {
    //     uint32_t ans = 0;
    //     string str = bitset<32>(n).to_string();

    //     int base = 1;
    //     while (!str.empty()) {
    //         ans = str[0] - '0' ? ans + base : ans;
    //         base <<= 1;
    //         str.erase(0, 1);
    //     }
    //     return ans;
    // }

    // Optimal Apporach : Time Complexity: O(1), Space Complexity: O(1)
    uint32_t reverseBits(uint32_t n) {
        uint32_t ans = 0;

        for (int i = 0; i < 32; i++) {
            // Extract the rightmost bit and Shift ans left and append the rightmost bit of n
            ans = (ans << 1) | (n & 1);

            // Remove the processed bit from n
            n >>= 1;
        }

        return ans;
    }
};

int main() {
    Solution s;
    uint32_t n = 00000000000000000000000000010101;

    cout << s.reverseBits(n) << endl;

    return 0;
}