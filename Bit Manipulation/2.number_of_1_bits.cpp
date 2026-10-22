#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    // Brute Force approach : Time Complexity: O(1), Space Complexity: O(1)
    // int hammingWeight(uint32_t n) {
    //     int cnt = 0;
    //     while (n) {
    //         // checks whether the last bit is 1
    //         if (n & 1 == 1)
    //             cnt++;
    //         n = n >> 1;  // shifts bits right to check the next bit
    //     }
    //     return cnt;
    // }

    // Optimal Bitmask approach (Brian Kernighan's algorithm) : Time Complexity: O(1), Space Complexity: O(1)
    int hammingWeight(uint32_t n) {
        int cnt = 0;
        while (n) {
            // n & (n - 1) removes the rightmost set bit (1) in each iteration
            // Explanation : when you subtract 1 from any binary no : rightmost 1 becomes 0,
            // any zero to its right becomes 1 and all bits to left remain unchanged
            // when you do n & n-1, those changed bits become 0, and the rightmost 1 is removed
            n = n & (n - 1);
            cnt++;
        }
        return cnt;
    }

    // Using inbuilt function
    // int hammingWeight(uint32_t n) {
    //     return __builtin_popcount(n);
    // }
};

int main() {
    Solution s;
    uint32_t n = 2147483645;

    cout << s.hammingWeight(n) << endl;

    return 0;
}