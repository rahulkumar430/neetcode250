#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    // Brute force approach-Time Complexity: O(N^2) Space Complexity: O(1)
    // int maxProfit(vector<int>& prices) {
    //     // Stores the maximum profit found so far
    //     int profit = 0;

    //     /*
    //     Compare every possible buy day (i) with every possible
    //     sell day (j > i) and calculate the profit.
    //     */
    //     for (int i = 0; i < prices.size(); i++) {
    //         // j starts from i + 1 to ensure selling happens after buying
    //         for (int j = i + 1; j < prices.size(); j++) {
    //             // Update maximum profit if selling on day j
    //             // after buying on day i gives better profit
    //             profit = max(profit, prices[j] - prices[i]);
    //         }
    //     }

    //     // Return the maximum profit achievable
    //     return profit;
    // }

    // Optimised Approach(2 pointers) - Time Complexity: O(N) Space Complexity: O(1)
    // int maxProfit(vector<int>& prices) {
    //     // l -> pointer for the best buying day (minimum price so far)
    //     // r -> pointer for the current selling day
    //     int l = 0, r = 1;

    //     // Stores the maximum profit found
    //     int maxProfit = 0;

    //     // Traverse the array with the selling pointer
    //     while (r < prices.size()) {
    //         /*
    //         If selling price is higher than buying price,
    //         calculate the profit and update maxProfit.
    //         */
    //         if (prices[l] < prices[r]) {
    //             int profit = prices[r] - prices[l];
    //             maxProfit = max(maxProfit, profit);
    //         }
    //         /*
    //         If current price is lower than the buying price,
    //         update l to r (better day to buy).
    //         */
    //         else {
    //             l = r;
    //         }

    //         // Move the selling pointer forward
    //         r++;
    //     }

    //     // Return the maximum profit achievable
    //     return maxProfit;
    // }

    // Optimised Approach - Time Complexity: O(N) Space Complexity: O(1)
    int maxProfit(vector<int>& prices) {
        // Stores the maximum profit found so far
        int profit = 0;

        // Stores the minimum price seen so far (best day to buy)
        int leftMin = prices[0];

        // Traverse prices from left to right
        for (int i = 0; i < prices.size(); i++) {
            // Update the minimum buying price up to the current day
            leftMin = min(leftMin, prices[i]);

            // Calculate profit if sold on the current day and update the maximum profit
            profit = max(profit, prices[i] - leftMin);
        }

        // Return the maximum profit achievable
        return profit;
    }
};

int main() {
    vector<int> prices = {10, 1, 5, 6, 7, 1};

    Solution sol;
    cout << sol.maxProfit(prices) << endl;

    return 0;
}