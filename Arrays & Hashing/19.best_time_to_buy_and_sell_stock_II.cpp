#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    // Optimal Solution is simply: sum all positive differences between consecutive days.
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