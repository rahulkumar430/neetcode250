#include <bits/stdc++.h>
using namespace std;

// Brute Force Recursive Approach - Time Complexity: O(n^amount), Space Complexity: O(amount)
// class Solution {
//    public:
//     int dfs(vector<int>& coins, int amount) {
//         // Base case
//         if (amount == 0) return 0;

//         // If amount becomes negative → invalid
//         if (amount < 0) return INT_MAX;

//         int minCoins = INT_MAX;

//         // Try every coin
//         for (int coin : coins) {
//             int res = dfs(coins, amount - coin);

//             // If valid result, take minimum
//             if (res != INT_MAX) {
//                 minCoins = min(minCoins, 1 + res);
//             }
//         }

//         return minCoins;
//     }

//     int coinChange(vector<int>& coins, int amount) {
//         int ans = dfs(coins, amount);

//         return (ans == INT_MAX) ? -1 : ans;
//     }
// };

// Top Down DP Approach - Time Complexity: O(n * amount), Space Complexity: O(amount)
// class Solution {
//    public:
//     int dfs(vector<int>& coins, int amount, vector<int>& dp) {
//         // Base case
//         if (amount == 0) return 0;
//         if (amount < 0) return INT_MAX;

//         // If already computed
//         if (dp[amount] != -1) return dp[amount];

//         int minCoins = INT_MAX;

//         for (int coin : coins) {
//             int res = dfs(coins, amount - coin, dp);

//             if (res != INT_MAX) {
//                 minCoins = min(minCoins, 1 + res);
//             }
//         }

//         return dp[amount] = minCoins;
//     }

//     int coinChange(vector<int>& coins, int amount) {
//         vector<int> dp(amount + 1, -1);

//         int ans = dfs(coins, amount, dp);

//         return (ans == INT_MAX) ? -1 : ans;
//     }
// };

// Bottom Up DP Approach - Time Complexity: O(n * amount), Space Complexity: O(amount)
class Solution {
   public:
    int coinChange(vector<int>& coins, int amount) {
        // dp[i] = minimum coins needed to make amount i
        vector<int> dp(amount + 1, INT_MAX);

        // Base case
        dp[0] = 0;

        // Build dp from 1 → amount
        for (int i = 1; i <= amount; i++) {
            for (int coin : coins) {
                if (i - coin >= 0 && dp[i - coin] != INT_MAX) {
                    dp[i] = min(dp[i], 1 + dp[i - coin]);
                }
            }
        }

        return (dp[amount] == INT_MAX) ? -1 : dp[amount];
    }
};

// BFS Approach - Time Complexity: O(n * amount), Space Complexity: O(amount)
// class Solution {
//    public:
//     int coinChange(vector<int>& coins, int amount) {
//         // Edge case
//         if (amount == 0) return 0;

//         queue<int> q;
//         vector<bool> visited(amount + 1, false);

//         // Start from amount 0
//         q.push(0);
//         visited[0] = true;

//         int coinsUsed = 0;  // number of coins used

//         while (!q.empty()) {
//             int size = q.size();
//             coinsUsed++;

//             for (int i = 0; i < size; i++) {
//                 int curr = q.front();
//                 q.pop();

//                 // Try all coins
//                 for (int coin : coins) {
//                     int next = curr + coin;

//                     // If we reach target
//                     if (next == amount) {
//                         return coinsUsed;
//                     }

//                     // If valid and not visited
//                     if (next < amount && !visited[next]) {
//                         visited[next] = true;
//                         q.push(next);
//                     }
//                 }
//             }
//         }

//         return -1;  // not possible
//     }
// };

int main() {
    vector<int> coins = {1, 5, 10};
    int amount = 12;

    Solution sol;
    cout << sol.coinChange(coins, amount) << endl;

    return 0;
}