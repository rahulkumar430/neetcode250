#include <bits/stdc++.h>
using namespace std;

// Brute Force Recursive Approach - Time Complexity: O(2^n), Space Complexity: O(n)
// class Solution {
//    public:
//     int dfs(int i, int currSum, int total, vector<int>& stones) {
//         // If all stones are considered
//         if (i == stones.size()) {
//             // Two groups: currSum and (total - currSum)
//             return abs((total - currSum) - currSum);
//         }

//         // Choice 1: include current stone in subset
//         int take = dfs(i + 1, currSum + stones[i], total, stones);

//         // Choice 2: skip current stone
//         int notTake = dfs(i + 1, currSum, total, stones);

//         // Return minimum difference
//         return min(take, notTake);
//     }

//     int lastStoneWeightII(vector<int>& stones) {
//         int total = 0;
//         for (int s : stones) total += s;

//         return dfs(0, 0, total, stones);
//     }
// };

// Top-Down DP Approach - Time Complexity: O(n * sum), Space Complexity: O(n * sum)
// class Solution {
//    public:
//     int dfs(int i, int currSum, int total, vector<int>& stones, vector<vector<int>>& dp) {
//         if (i == stones.size()) {
//             return abs((total - currSum) - currSum);
//         }

//         // Already computed
//         if (dp[i][currSum] != -1)
//             return dp[i][currSum];

//         // Choice 1: include current stone in subset
//         int take = dfs(i + 1, currSum + stones[i], total, stones, dp);

//         // Choice 2: skip current stone
//         int notTake = dfs(i + 1, currSum, total, stones, dp);

//         return dp[i][currSum] = min(take, notTake);
//     }

//     int lastStoneWeightII(vector<int>& stones) {
//         int total = 0;
//         for (int s : stones) total += s;

//         // dp[i][currSum] stores min difference
//         vector<vector<int>> dp(stones.size(), vector<int>(total + 1, -1));

//         return dfs(0, 0, total, stones, dp);
//     }
// };

// Bottom-Up DP Approach - Time Complexity: O(n * sum), Space Complexity: O(sum)
// class Solution {
//    public:
//     int lastStoneWeightII(vector<int>& stones) {
//         int total = 0;
//         for (int s : stones) total += s;

//         int target = total / 2;

//         // dp[i][j] = whether we can achieve sum j using first i stones
//         vector<vector<bool>> dp(stones.size() + 1, vector<bool>(target + 1, false));

//         // Base case: sum 0 is always possible
//         for (int i = 0; i <= stones.size(); i++) {
//             dp[i][0] = true;
//         }

//         for (int i = 1; i <= stones.size(); i++) {
//             for (int j = 1; j <= target; j++) {
//                 // Not take current stone
//                 dp[i][j] = dp[i - 1][j];

//                 // Take current stone if possible
//                 if (j >= stones[i - 1]) {
//                     // Check if we can reach sum j - stones[i - 1] using first i - 1 stones
//                     dp[i][j] = dp[i][j] || dp[i - 1][j - stones[i - 1]];
//                 }
//             }
//         }

//         // Find best subset sum closest to target if it exists
//         for (int j = target; j >= 0; j--) {
//             if (dp[stones.size()][j]) {
//                 // difference = total - 2 * subsetSum
//                 return total - 2 * j;
//             }
//         }

//         return 0;
//     }
// };

// Space Optimized Bottom-Up DP Approach - Time Complexity: O(n * sum), Space Complexity: O(sum)
class Solution {
   public:
    int lastStoneWeightII(vector<int>& stones) {
        int total = 0;
        for (int s : stones) total += s;

        int target = total / 2;

        // dp[j] = can we achieve sum j
        vector<bool> dp(target + 1, false);

        dp[0] = true;  // base case

        for (int stone : stones) {
            // Traverse backwards (IMPORTANT for 0/1 knapsack)
            for (int j = target; j >= stone; j--) {
                // Either we already had j OR we can form it using this stone
                dp[j] = dp[j] || dp[j - stone];
            }
        }

        // Find best achievable sum closest to target
        for (int j = target; j >= 0; j--) {
            if (dp[j]) {
                // difference = total - 2 * subsetSum
                return total - 2 * j;
            }
        }

        return 0;
    }
};

int main() {
    vector<int> stones = {2, 4, 1, 5, 6, 3};

    Solution sol;
    cout << sol.lastStoneWeightII(stones) << endl;

    return 0;
}