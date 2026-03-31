#include <bits/stdc++.h>
using namespace std;

// Brute Force Recursive Approach - Time Complexity: O(3^n), Space Complexity: O(n)
// class Solution {
//    public:
//     // Dumb version of writing recursion
//     // int dfs(int i, vector<int>& stones) {
//     //     if (i >= stones.size()) return 0;

//     //     int best = INT_MIN;

//     //     // Take 1 stone
//     //     int take1 = stones[i] - dfs(i + 1, stones);
//     //     best = max(best, take1);

//     //     // Take 2 stones
//     //     if (i + 1 < stones.size()) {
//     //         int take2 = stones[i] + stones[i + 1] - dfs(i + 2, stones);
//     //         best = max(best, take2);
//     //     }

//     //     // Take 3 stones
//     //     if (i + 2 < stones.size()) {
//     //         int take3 = stones[i] + stones[i + 1] + stones[i + 2] - dfs(i + 3, stones);
//     //         best = max(best, take3);
//     //     }

//     //     return best;
//     // }

//     int dfs(int i, vector<int>& stones) {
//         // Base case: no stones left
//         if (i >= stones.size()) return 0;

//         int sum = 0;
//         int best = INT_MIN;

//         // Try taking 1, 2, or 3 stones
//         for (int k = 0; k < 3 && i + k < stones.size(); k++) {
//             sum += stones[i + k];  // accumulate taken stones

//             // current player gains "sum" and opponent will play optimally → dfs(i + k + 1)
//             // so net gain = sum - opponent's best
//             best = max(best, sum - dfs(i + k + 1, stones));
//         }

//         return best;
//     }

//     string stoneGameIII(vector<int>& stoneValue) {
//         int diff = dfs(0, stoneValue);

//         // Final decision based on score difference
//         if (diff > 0) return "Alice";
//         if (diff < 0) return "Bob";
//         return "Tie";
//     }
// };

// Top-Down DP Approach - Time Complexity: O(n), Space Complexity: O(n)
// class Solution {
//    public:
//     int dfs(int i, vector<int>& stones, vector<int>& dp) {
//         if (i >= stones.size()) return 0;

//         if (dp[i] != INT_MIN) return dp[i];

//         int sum = 0;
//         int best = INT_MIN;

//         // Try taking 1, 2, or 3 stones
//         for (int k = 0; k < 3 && i + k < stones.size(); k++) {
//             sum += stones[i + k];

//             // subtract opponent's best
//             best = max(best, sum - dfs(i + k + 1, stones, dp));
//         }

//         return dp[i] = best;
//     }

//     string stoneGameIII(vector<int>& stoneValue) {
//         int n = stoneValue.size();

//         vector<int> dp(n, INT_MIN);

//         int diff = dfs(0, stoneValue, dp);

//         if (diff > 0) return "Alice";
//         if (diff < 0) return "Bob";
//         return "Tie";
//     }
// };

// Bottom-up DP Approach - Time Complexity: O(n), Space Complexity: O(n)
// class Solution {
//    public:
//     string stoneGameIII(vector<int>& stoneValue) {
//         int n = stoneValue.size();

//         // dp[i] = max score difference from index i
//         vector<int> dp(n + 1, 0);

//         // dp[n] = 0 → no stones left

//         // Build from back → front
//         for (int i = n - 1; i >= 0; i--) {
//             int sum = 0;
//             int best = INT_MIN;

//             // Try taking 1, 2, or 3 stones
//             for (int k = 0; k < 3 && i + k < n; k++) {
//                 sum += stoneValue[i + k];

//                 // logic: current gain - opponent's best
//                 best = max(best, sum - dp[i + k + 1]);
//             }

//             dp[i] = best;
//         }

//         int diff = dp[0];

//         if (diff > 0) return "Alice";
//         if (diff < 0) return "Bob";
//         return "Tie";
//     }
// };

// Space Optimized Bottom-up DP Approach - Time Complexity: O(n), Space Complexity: O(1)
// class Solution {
//    public:
//     string stoneGameIII(vector<int>& stoneValue) {
//         int n = stoneValue.size();

//         // Only need next 3 states
//         int dp1 = 0, dp2 = 0, dp3 = 0;
//         // dp1 = dp[i+1], dp2 = dp[i+2], dp3 = dp[i+3]

//         for (int i = n - 1; i >= 0; i--) {
//             int sum = 0;
//             int best = INT_MIN;

//             // Take 1 stone
//             sum = stoneValue[i];
//             best = max(best, sum - dp1);

//             // Take 2 stones
//             if (i + 1 < n) {
//                 sum += stoneValue[i + 1];
//                 best = max(best, sum - dp2);
//             }

//             // Take 3 stones
//             if (i + 2 < n) {
//                 sum += stoneValue[i + 2];
//                 best = max(best, sum - dp3);
//             }

//             // Shift values (like sliding window)
//             dp3 = dp2;
//             dp2 = dp1;
//             dp1 = best;
//         }

//         int diff = dp1;

//         if (diff > 0) return "Alice";
//         if (diff < 0) return "Bob";
//         return "Tie";
//     }
// };

// Space Optimized using Rolling Array (mod)
// Time Complexity: O(n), Space Complexity: O(1)
class Solution {
   public:
    string stoneGameIII(vector<int>& stoneValue) {
        int n = stoneValue.size();

        // Rolling array of size 3
        vector<int> dp(3, 0);

        // dp[i % 3] stores dp[i]

        for (int i = n - 1; i >= 0; i--) {
            int sum = 0;
            int best = INT_MIN;

            // Try taking 1, 2, or 3 stones
            for (int k = 0; k < 3 && i + k < n; k++) {
                sum += stoneValue[i + k];

                // dp[(i + k + 1) % 3] → future state
                best = max(best, sum - dp[(i + k + 1) % 3]);
            }

            // Store current result
            dp[i % 3] = best;
        }

        int diff = dp[0];  // dp[0 % 3]

        if (diff > 0) return "Alice";
        if (diff < 0) return "Bob";
        return "Tie";
    }
};

int main() {
    vector<int> stoneValue = {2, 4, 3, 1};

    Solution sol;
    cout << sol.stoneGameIII(stoneValue) << endl;

    return 0;
}