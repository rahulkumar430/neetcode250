#include <bits/stdc++.h>
using namespace std;

// Brute Force Recursive Approach - Time Complexity: O(2^n), Space Complexity: O(n)
// class Solution {
//    public:
//     int dfs(int i, bool canBuy, vector<int>& prices) {
//         // Base case: no more days
//         if (i >= prices.size()) return 0;

//         if (canBuy) {
//             // Option 1: Buy
//             int buy = -prices[i] + dfs(i + 1, false, prices);

//             // Option 2: Skip
//             int skip = dfs(i + 1, true, prices);

//             return max(buy, skip);
//         } else {
//             // Option 1: Sell (cooldown → skip next day)
//             int sell = prices[i] + dfs(i + 2, true, prices);

//             // Option 2: Skip
//             int skip = dfs(i + 1, false, prices);

//             return max(sell, skip);
//         }
//     }

//     int maxProfit(vector<int>& prices) {
//         return dfs(0, true, prices);
//     }
// };

// Top-Down DP Approach - Time Complexity: O(n), Space Complexity: O(n)
// class Solution {
//    public:
//     int dfs(int i, int canBuy, vector<int>& prices, vector<vector<int>>& dp) {
//         if (i >= prices.size()) return 0;

//         if (dp[i][canBuy] != -1) return dp[i][canBuy];

//         if (canBuy) {
//             // Option 1: Buy
//             int buy = -prices[i] + dfs(i + 1, 0, prices, dp);
//             // Option 2: Skip
//             int skip = dfs(i + 1, 1, prices, dp);

//             return dp[i][canBuy] = max(buy, skip);
//         } else {
//             // Option 1: Sell (cooldown → skip next day)
//             int sell = prices[i] + dfs(i + 2, 1, prices, dp);
//             // Option 2: Skip
//             int skip = dfs(i + 1, 0, prices, dp);

//             return dp[i][canBuy] = max(sell, skip);
//         }
//     }

//     int maxProfit(vector<int>& prices) {
//         int n = prices.size();

//         // dp[i][0/1] → max profit from day i with buy/sell state
//         vector<vector<int>> dp(n, vector<int>(2, -1));

//         return dfs(0, 1, prices, dp);
//     }
// };

// Bottom-Up DP Approach - Time Complexity: O(n), Space Complexity: O(n)
// class Solution {
//    public:
//     int maxProfit(vector<int>& prices) {
//         int n = prices.size();

//         // dp[i][1] → can buy
//         // dp[i][0] → holding stock (can sell)
//         vector<vector<int>> dp(n + 2, vector<int>(2, 0));

//         // Fill backwards
//         for (int i = n - 1; i >= 0; i--) {
//             // Can Buy
//             dp[i][1] = max(
//                 -prices[i] + dp[i + 1][0],  // buy + next day hold or sell
//                 dp[i + 1][1]                // skip
//             );

//             // Can Sell (holding stock)
//             dp[i][0] = max(
//                 prices[i] + dp[i + 2][1],  // sell + cooldown
//                 dp[i + 1][0]               // skip
//             );
//         }

//         return dp[0][1];  // start with canBuy
//     }
// };

// Space Optimized Bottom-Up DP Approach - Time Complexity: O(n), Space Complexity: O(1)
class Solution {
   public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();

        int aheadBuy = 0, aheadSell = 0;  // dp[i+1]
        int ahead2Buy = 0;                // dp[i+2][buy]

        int currBuy, currSell;

        for (int i = n - 1; i >= 0; i--) {
            // If we can buy
            currBuy = max(
                -prices[i] + aheadSell,  // buy + next day hold or sell
                aheadBuy                 // skip
            );

            // If we are holding (can sell)
            currSell = max(
                prices[i] + ahead2Buy,  // sell + cooldown
                aheadSell               // skip
            );

            // Shift states
            ahead2Buy = aheadBuy;
            aheadBuy = currBuy;
            aheadSell = currSell;
        }

        return aheadBuy;
    }
};

int main() {
    vector<int> prices = {1, 3, 4, 0, 4};

    Solution sol;
    cout << sol.maxProfit(prices) << endl;

    return 0;
}