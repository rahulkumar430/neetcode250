#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    // Brute Force Approach
    // Time Complexity: O(n * 1000)  → O(n) since 1000 is constant, Space Complexity: O(1000) → O(1)
    // But if max location is more than 1000 then time and space will become O(N^2) and O(N) respectively
    // bool carPooling(vector<vector<int>>& trips, int capacity) {
    //     // rideCapacity[i] = number of passengers in car at location i
    //     vector<int> rideCapacity(1000, 0);

    //     sort(trips.begin(), trips.end(), [](const vector<int>& a, const vector<int>& b) {
    //         return a[1] < b[1];
    //     });

    //     // Process each trip
    //     for (int i = 0; i < trips.size(); i++) {
    //         int passengers = trips[i][0];
    //         int start = trips[i][1];
    //         int end = trips[i][2];

    //         // Add passengers for each location in range [start, end)
    //         for (int pos = start; pos < end; pos++) {
    //             rideCapacity[pos] += passengers;

    //             // If capacity exceeded at any point → invalid
    //             if (rideCapacity[pos] > capacity)
    //                 return false;
    //         }
    //     }

    //     return true;
    // }

    // Optimised Min Heap Approach - Time Complexity: O(N log N), Space Complexity : O(N)
    // bool carPooling(vector<vector<int>>& trips, int capacity) {
    //     // Sort trips by start location
    //     sort(trips.begin(), trips.end(),
    //          [](vector<int>& a, vector<int>& b) {
    //              return a[1] < b[1];
    //          });

    //     // Min heap: {endLocation, passengers}
    //     priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;

    //     int currentPassengers = 0;

    //     for (auto& trip : trips) {
    //         int passengers = trip[0];
    //         int start = trip[1];
    //         int end = trip[2];

    //         // Remove all passengers whose trips have ended
    //         while (!minHeap.empty() && minHeap.top().first <= start) {
    //             currentPassengers -= minHeap.top().second;
    //             minHeap.pop();
    //         }

    //         // Add current trip passengers
    //         currentPassengers += passengers;

    //         if (currentPassengers > capacity)
    //             return false;

    //         // Push this trip into heap
    //         minHeap.push({end, passengers});
    //     }

    //     return true;
    // }

    // Optimal Line Sweep / Difference Array Approach - Time Complexity: O(N + n) ≈ O(N), where n = trips length
    // Space Complexity: O(n) ≈ O(1), as n = 1000
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        // Find the range of locations [L, R]
        int L = INT_MAX, R = INT_MIN;
        for (auto& trip : trips) {
            L = min(L, trip[1]);  // Minimum start location
            R = max(R, trip[2]);  // Maximum end location
        }

        // Create difference array for the range
        int N = R - L + 1;
        vector<int> passChange(N + 1, 0);

        // Build difference array: mark passenger changes at start and end points
        for (auto& trip : trips) {
            int passengers = trip[0];
            int start = trip[1] - L;  // Normalize start location
            int end = trip[2] - L;    // Normalize end location

            passChange[start] += passengers;  // Passengers board
            passChange[end] -= passengers;    // Passengers deboard
        }

        // Scan through locations and check if capacity is exceeded at any point
        int current = 0;
        for (int i = 0; i < N; i++) {
            current += passChange[i];
            if (current > capacity)
                return false;
        }

        return true;
    }
};

int main() {
    vector<vector<int>> trips = {{4, 1, 2}, {3, 2, 4}};
    int capacity = 4;

    Solution sol;
    cout << (sol.carPooling(trips, capacity) ? "true" : "false") << endl;

    return 0;
}