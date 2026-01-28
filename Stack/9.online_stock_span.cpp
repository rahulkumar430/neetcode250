#include <bits/stdc++.h>
using namespace std;

class StockSpanner {
   public:
    // Stores all stock prices seen so far
    // vector<int> prices;  // required for brute force approach
    stack<pair<int, int>> st;  // required for optimised(amortised) solution

    StockSpanner() {}

    // Brute force approach - Time Complexity (worst case per call): O(N), Space Complexity: O(N)
    // Though it is being called N times the total time is O(N^2)
    // int next(int price) {
    //     // Add the current day's price
    //     prices.push_back(price);

    //     int span = 1;  // At least one day (today itself)
    //     int i = prices.size() - 1;

    //     // Count how many consecutive previous days
    //     // have prices less than or equal to today's price
    //     while (i > 0 && prices[i - 1] <= price) {
    //         span++;
    //         i--;
    //     }

    //     // Return the computed span
    //     return span;
    // }

    // Optimised solution - Time Complexity (amortised): O(1), Space Complexity: O(N)
    // Though it is being called N times the total time is O(N)
    int next(int price) {
        int span = 1;
        // Collapse all smaller or equal prices
        while (!st.empty() && st.top().first <= price) {
            span += st.top().second;
            st.pop();
        }

        st.emplace(price, span);
        return span;
    }
};

int main() {
    StockSpanner stockSpanner;

    cout << stockSpanner.next(100) << endl;  // return 1
    cout << stockSpanner.next(80) << endl;   // return 1
    cout << stockSpanner.next(60) << endl;   // return 1
    cout << stockSpanner.next(70) << endl;   // return 2
    cout << stockSpanner.next(60) << endl;   // return 1
    cout << stockSpanner.next(75) << endl;   // return 4, because the last 4 prices (including today's price of 75) were less than or equal to today's price.
    cout << stockSpanner.next(85) << endl;   // return 6

    return 0;
}