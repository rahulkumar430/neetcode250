#include <bits/stdc++.h>
using namespace std;

// Bruteforce Recursive Approach - Time Complexity: O(2^n), Space Complexity: O(n)
// class Solution {
//    private:
//     int rec(vector<int>& prices, int i, bool bought) {
//         if (i == prices.size()) {
//             return 0;
//         }
//         // Option 1: Skip current day
//         int res = rec(prices, i + 1, bought);
//         // Option 2: Buy or Sell on current day
//         if (bought) {
//             res = max(res, prices[i] + rec(prices, i + 1, false));  // Sell and move to next day
//         } else {
//             res = max(res, -prices[i] + rec(prices, i + 1, true));  // Buy and move to next day
//         }
//         return res;
//     }

//    public:
//     int maxProfit(vector<int>& prices) {
//         return rec(prices, 0, false);
//     }
// };

// Top-Down DP (Memoization) - Time Complexity: O(n), Space Complexity: O(n) for dp + recursion stack
class Solution {
   private:
    int rec(vector<int>& prices, int i, int bought, vector<vector<int>>& dp) {
        // Base case: no days left
        if (i == prices.size()) {
            return 0;
        }

        // If already computed, return cached value
        if (dp[i][bought] != -1) {
            return dp[i][bought];
        }

        // Option 1: Skip current day
        int res = rec(prices, i + 1, bought, dp);

        if (bought) {
            // Option 2: Sell today
            res = max(res, prices[i] + rec(prices, i + 1, 0, dp));
        } else {
            // Option 2: Buy today
            res = max(res, -prices[i] + rec(prices, i + 1, 1, dp));
        }

        // Store and return
        return dp[i][bought] = res;
    }

   public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();

        // dp[i][bought]
        vector<vector<int>> dp(n, vector<int>(2, -1));

        return rec(prices, 0, 0, dp);
    }
};

class Solution {
   public:
    // Optimal Greedy Solution is simply: sum all positive differences between consecutive days.
    // Time Complexity: O(n), Space Complexity: O(1)
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if (n <= 1) return 0;

        int profit = 0;

        // Add every positive difference between consecutive days
        for (int i = 1; i < n; i++) {
            if (prices[i] > prices[i - 1]) {
                profit += prices[i] - prices[i - 1];
            }
        }

        return profit;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {1, 2, 3, 4, 5};

    cout << sol.maxProfit(nums) << endl;
    return 0;
}