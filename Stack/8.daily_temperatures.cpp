#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    // Brute force solution - Time complexity : O(N^2)
    // vector<int> dailyTemperatures(vector<int>& temperatures) {
    //     int n = temperatures.size();

    //     // Initialize answer array with 0s
    //     // If no warmer day exists in the future, answer remains 0
    //     vector<int> ans(n, 0);

    //     // For each day i, check all future days j
    //     for (int i = 0; i < n; i++) {
    //         // Look for the first warmer temperature after day i
    //         for (int j = i + 1; j < n; j++) {
    //             // If a warmer day is found
    //             if (temperatures[j] > temperatures[i]) {
    //                 // Store the number of days waited
    //                 ans[i] = j - i;
    //                 break;  // Stop at the first warmer day
    //             }
    //         }
    //     }

    //     return ans;
    // }

    // Optimised approach - Time complexity : O(N)
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> ans(n, 0);
        stack<int> st;  // stores indices

        for (int i = 0; i < n; i++) {
            // Resolve all previous colder days
            while (!st.empty() && temperatures[i] > temperatures[st.top()]) {
                int prevDay = st.top();
                st.pop();
                ans[prevDay] = i - prevDay;
            }

            // Push current day index
            st.push(i);
        }

        return ans;
    }
};

int main() {
    Solution s;

    vector<int> temperatures = {30, 38, 30, 36, 35, 40, 28};
    vector<int> ans = s.dailyTemperatures(temperatures);

    for (int x : ans) {
        cout << x << " ";
    }

    return 0;
}