#include <bits/stdc++.h>
using namespace std;

// Brute Force Recursive Solution - Time Complexity: O(2^n), Space Complexity: O(n)
// class Solution {
//    public:
//     int solve(int i, vector<int>& cost) {
//         int n = cost.size();

//         // Base case: reached or crossed top
//         if (i >= n) return 0;

//         // Choose 1 step or 2 steps
//         return cost[i] + min(solve(i + 1, cost), solve(i + 2, cost));
//     }

//     int minCostClimbingStairs(vector<int>& cost) {
//         // Can start from 0 or 1
//         return min(solve(0, cost), solve(1, cost));
//     }
// };

// Top Down DP Solution - Time Complexity: O(n), Space Complexity: O(n)
// class Solution {
//    public:
//     // Top Down DP Solution - Time Complexity: O(n), Space Complexity: O(n)
//     int solve(int i, vector<int>& cost, vector<int>& dp) {
//         int n = cost.size();

//         // Base case: reached or crossed top
//         if (i >= n) return 0;

//         // Memoization
//         if (dp[i] != -1) return dp[i];

//         // Calculate the minimum cost for step i
//         return dp[i] = cost[i] + min(solve(i + 1, cost, dp), solve(i + 2, cost, dp));
//     }

//     int minCostClimbingStairs(vector<int>& cost) {
//         int n = cost.size();
//         vector<int> dp(n, -1);

//         // Can start from 0 or 1
//         return min(solve(0, cost, dp), solve(1, cost, dp));
//     }
// };

// Bottom Up DP Solution - Time Complexity: O(n), Space Complexity: O(n)
// class Solution {
//    public:
//     int minCostClimbingStairs(vector<int>& cost) {
//         int n = cost.size();

//         vector<int> dp(n + 1, 0);

//         // Start from 2nd step because dp[i] represents the minimum cost to reach step i
//         // and to reach 0th or 1st step we need minimum 0 step only
//         for (int i = 2; i <= n; i++) {
//             // Choose 1 step or 2 steps
//             dp[i] = min(dp[i - 1] + cost[i - 1], dp[i - 2] + cost[i - 2]);
//         }

//         return dp[n];
//     }
// };

// Bottom Up DP Solution (space Optimized) - Time Complexity: O(n), Space Complexity: O(1)
class Solution {
   public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();

        // dp[0] = 0, dp[1] = 0
        int twoStep = 0;  // dp[i-2]
        int oneStep = 0;  // dp[i-1]

        for (int i = 2; i <= n; i++) {
            int curr = min(
                oneStep + cost[i - 1],  // from i-1
                twoStep + cost[i - 2]   // from i-2
            );

            // Shift window
            twoStep = oneStep;
            oneStep = curr;
        }

        return oneStep;  // dp[n]
    }
};

int main() {
    vector<int> cost = {1, 2, 1, 2, 1, 1, 1};

    Solution sol;
    cout << sol.minCostClimbingStairs(cost) << endl;

    return 0;
}