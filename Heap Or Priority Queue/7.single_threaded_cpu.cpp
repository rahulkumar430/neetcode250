#include <bits/stdc++.h>
using namespace std;

// Optimised Approach(Sorting + MinHeap) - Time Complexity: O(N log N), Space Complexity: O(N)
// class Solution {
//    public:
//     vector<int> getOrder(vector<vector<int>>& tasks) {
//         int n = tasks.size();

//         // Append index to each task
//         for (int i = 0; i < n; i++) {
//             tasks[i].push_back(i);
//         }

//         // Sort by enqueue time
//         sort(tasks.begin(), tasks.end());

//         // Min heap ordered by:
//         // {processingTime, index}
//         priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> minHeap;

//         vector<int> result;

//         long long time = 0;  // current CPU time
//         int i = 0;           // pointer for tasks

//         while (i < n || !minHeap.empty()) {
//             // If heap empty, jump time to next task's enqueue
//             if (minHeap.empty() && time < tasks[i][0]) {
//                 time = tasks[i][0];
//             }

//             // Push all available tasks into heap
//             while (i < n && tasks[i][0] <= time) {
//                 minHeap.push({tasks[i][1], tasks[i][2]});
//                 i++;
//             }

//             // Process task with smallest processing time
//             auto [processingTime, index] = minHeap.top();
//             minHeap.pop();

//             time += processingTime;
//             result.push_back(index);
//         }

//         return result;
//     }
// };

// Optimal Approach(Sorting + MinHeap) - Time Complexity: O(N log N), Space Complexity: O(N)
class Solution {
   public:
    vector<int> getOrder(vector<vector<int>>& tasks) {
        int n = tasks.size();

        // Create indices array [0, 1, 2, ..., n-1]
        vector<int> indices(n);
        iota(indices.begin(), indices.end(), 0);

        // Sort indices by enqueue time
        sort(indices.begin(), indices.end(), [&](int a, int b) {
            if (tasks[a][0] == tasks[b][0])
                return a < b;
            return tasks[a][0] < tasks[b][0];
        });

        // Min-heap: prioritize smaller processing time, then smaller index
        auto comp = [&](int a, int b) {
            if (tasks[a][1] == tasks[b][1])
                return a > b;
            return tasks[a][1] > tasks[b][1];
        };

        priority_queue<int, vector<int>, decltype(comp)> minHeap(comp);

        vector<int> result;
        long long time = 0;
        int i = 0;

        while (!minHeap.empty() || i < n) {
            // Add all tasks available at current time
            while (i < n && tasks[indices[i]][0] <= time) {
                minHeap.push(indices[i]);
                i++;
            }

            if (minHeap.empty()) {
                // Jump to next task's enqueue time
                time = tasks[indices[i]][0];
            } else {
                // Process task with smallest processing time
                int nextIndex = minHeap.top();
                minHeap.pop();
                time += tasks[nextIndex][1];
                result.push_back(nextIndex);
            }
        }

        return result;
    }
};

void printVector(vector<int> v) {
    for (int i : v) {
        cout << i << " ";
    }
    cout << endl;
}

int main() {
    vector<vector<int>> tasks = {{5, 2}, {4, 4}, {4, 1}, {2, 1}, {3, 3}};

    Solution sol;
    printVector(sol.getOrder(tasks));

    return 0;
}