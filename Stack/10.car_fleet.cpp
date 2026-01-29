#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    // Optimal solution - Time complexity : O(NlogN), Space complexity : O(N)
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = position.size();

        // Step 1: Combine position and speed so their relationship is preserved
        // Each pair represents one car: {position, speed}
        vector<pair<int, int>> combined;
        for (int i = 0; i < n; i++) {
            combined.push_back({position[i], speed[i]});
        }

        // Step 2: Sort cars by position in ascending order
        // This allows us to process cars from closest to the target to farthest
        sort(combined.begin(), combined.end());

        // Step 3: Unzip the sorted data back into position and speed arrays
        for (int i = 0; i < n; i++) {
            position[i] = combined[i].first;
            speed[i] = combined[i].second;
        }
        // You can proceed without unzipping as well with the pair vector

        // Step 4: Use a stack to track the time each car (or fleet) takes to reach the target
        // Each entry in the stack represents a distinct fleet
        stack<double> st;

        // Process cars from left to right (from closest to farthest after sorting)
        for (int i = 0; i < n; i++) {
            // Time needed for the current car to reach the target
            double time = (double)(target - position[i]) / speed[i];
            // double time = (double)(target - combined[i].first) / combined[i].second;

            // If the current car catches up to a fleet ahead,
            // it becomes part of that fleet (merge fleets)
            while (!st.empty() && st.top() <= time) {
                st.pop();
            }

            // Push the time of the current fleet
            st.push(time);
        }

        // The number of fleets is equal to the number of entries in the stack
        return st.size();
    }
};

int main() {
    Solution s;
    int target = 10;
    vector<int> position = {4, 1, 0, 7};
    vector<int> speed = {2, 2, 1, 1};

    cout << s.carFleet(target, position, speed) << endl;

    return 0;
}