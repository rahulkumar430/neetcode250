#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    // Brute Force Appraoach - Time Complexity : O(N * k), Space Complexity: O(N)
    // int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
    //     int n = profits.size();
    //     vector<bool> used(n, false);

    //     int currentCapital = w;

    //     while (k--) {
    //         int maxProfit = -1;
    //         int projectIndex = -1;

    //         // Scan all projects
    //         for (int i = 0; i < n; i++) {
    //             if (!used[i] && capital[i] <= currentCapital) {
    //                 if (profits[i] > maxProfit) {
    //                     maxProfit = profits[i];
    //                     projectIndex = i;
    //                 }
    //             }
    //         }

    //         // If no project can be taken → stop
    //         if (projectIndex == -1)
    //             break;

    //         // Take project
    //         used[projectIndex] = true;
    //         currentCapital += profits[projectIndex];
    //     }

    //     return currentCapital;
    // }

    // Optimised Approach using both Min and Max heap
    // Time Complexity: O(n log n + k log n) ≈ O(n log n), Space Complexity: O(n)
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        int n = profits.size();

        // Min heap based on required capital
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minCapitalHeap;

        // Max heap based on profit
        priority_queue<int> maxProfitHeap;

        // Step 1: Push all projects into min heap (sorted by capital)
        for (int i = 0; i < n; i++) {
            minCapitalHeap.push({capital[i], profits[i]});
        }

        int currentCapital = w;

        // Step 2: Perform at most k projects
        while (k--) {
            // Move all affordable projects into maxProfitHeap
            while (!minCapitalHeap.empty() && minCapitalHeap.top().first <= currentCapital) {
                maxProfitHeap.push(minCapitalHeap.top().second);
                minCapitalHeap.pop();
            }

            // If no affordable projects available → stop
            if (maxProfitHeap.empty())
                break;

            // Pick most profitable project
            currentCapital += maxProfitHeap.top();
            maxProfitHeap.pop();
        }

        return currentCapital;
    }

    // Another Optimised Approach using vector(instead of min heap) and Max heap
    // Time Complexity: O(n log n + k log n) ≈ O(n log n), Space Complexity: O(n)
    // int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
    //     int n = profits.size();

    //     // Step 1: Combine capital and profit
    //     vector<pair<int, int>> projects;
    //     for (int i = 0; i < n; i++) {
    //         projects.push_back({capital[i], profits[i]});
    //     }

    //     // Step 2: Sort by required capital
    //     sort(projects.begin(), projects.end());

    //     priority_queue<int> maxProfitHeap;

    //     int i = 0;
    //     int currentCapital = w;

    //     while (k--) {
    //         // Add all affordable projects into maxHeap
    //         while (i < n && projects[i].first <= currentCapital) {
    //             maxProfitHeap.push(projects[i].second);
    //             i++;
    //         }

    //         // If no project available → stop
    //         if (maxProfitHeap.empty())
    //             break;

    //         // Pick highest profit
    //         currentCapital += maxProfitHeap.top();
    //         maxProfitHeap.pop();
    //     }

    //     return currentCapital;
    // }
};

int main() {
    vector<int> profits = {2, 3, 1, 5, 3};
    vector<int> capital = {4, 4, 2, 3, 3};
    int k = 4, w = 2;

    Solution sol;
    cout << sol.findMaximizedCapital(k, w, profits, capital) << endl;

    return 0;
}