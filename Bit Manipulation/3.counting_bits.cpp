#include <bits/stdc++.h>
using namespace std;

class Solution {
   private:
    // Bitmask approach (Brian Kernighan's algorithm) : Time Complexity: O(N log N), Space Complexity: O(N)
    // int hammingWeight(uint32_t n) {
    //     int cnt = 0;
    //     while (n) {
    //         // n & (n - 1) removes the rightmost set bit (1) in each iteration
    //         // Explanation : when you subtract 1 from any binary no : rightmost 1 becomes 0,
    //         // any zero to its right becomes 1 and all bits to left remain unchanged
    //         // when you do n & n-1, those changed bits become 0, and the rightmost 1 is removed
    //         n = n & (n - 1);
    //         cnt++;
    //     }
    //     return cnt;
    // }

   public:
    // Using Brian Kernighan's algorithm N times : Time Complexity: O(N log N), Space Complexity: O(N)
    // vector<int> countBits(int n) {
    //     vector<int> ans;
    //     for (int i = 0; i <= n; i++) {
    //         ans.push_back(hammingWeight(i));
    //         // ans.push_back(__builtin_popcount(i));
    //     }
    //     return ans;
    // }

    // Optimal DP Approach: Time Complexity: O(N), Space Complexity: O(N)
    // vector<int> countBits(int n) {
    //     vector<int> dp(n + 1, 0);
    //     int power = 1;

    //     for (int i = 1; i <= n; i++) {
    //         if (power * 2 == i)
    //             power = i;  // Update to the next power of 2

    //         int remainder = i - power;

    //         // Set bits in i = 1 (for power of 2) + set bits in remainder
    //         dp[i] = 1 + dp[remainder];
    //     }

    //     return dp;
    // }

    // Alternate More Optimal DP Approach : Time Complexity: O(N), Space Complexity: O(N)
    vector<int> countBits(int n) {
        vector<int> dp(n + 1, 0);

        for (int i = 1; i <= n; i++) {
            // i >> 1 removes the last bit and we get that from dp; i & 1 tells if removed bit was 1 or not.
            // Count set bits in i = dp[i / 2] + (i % 2).
            dp[i] = dp[i >> 1] + (i & 1);
            // OR dp[i] = dp[i/2] + (i % 2);
        }

        return dp;
    }
};

int main() {
    Solution s;
    int n = 5;

    vector<int> ans = s.countBits(n);
    for (int x : ans) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}