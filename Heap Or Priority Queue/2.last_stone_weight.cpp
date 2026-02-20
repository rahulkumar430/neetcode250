#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    // Brute force approach - Time Complexity: O(N^2 log N), Space Complexity: O(1)
    // int lastStoneWeight(vector<int>& stones) {
    //     // Keep processing until 1 or 0 stones remain
    //     while (stones.size() > 1) {
    //         // Sort in descending order
    //         sort(stones.begin(), stones.end(), greater<int>());

    //         int first = stones[0];   // largest
    //         int second = stones[1];  // second largest

    //         // Remove both stones
    //         stones.erase(stones.begin());
    //         stones.erase(stones.begin());

    //         // If they are not equal, push the difference
    //         if (first != second) {
    //             stones.push_back(first - second);
    //         }
    //     }

    //     // If empty return 0, else remaining stone
    //     return stones.empty() ? 0 : stones[0];
    // }

    // Optimised maxheap approach - Time Complexity: O(N log N), Space Complexity: O(N)
    int lastStoneWeight(vector<int>& stones) {
        // Max heap
        priority_queue<int> maxHeap(stones.begin(), stones.end());

        // Process until 1 or 0 stones remain
        while (maxHeap.size() > 1) {
            int first = maxHeap.top();
            maxHeap.pop();

            int second = maxHeap.top();
            maxHeap.pop();

            // If not equal, push the difference
            if (first != second) {
                maxHeap.push(first - second);
            }
        }

        // If heap empty return 0, else remaining stone
        return maxHeap.empty() ? 0 : maxHeap.top();
    }

    // Bucket Sort Approach - since the constraint 1 <= stones[i] <= 100
    // Time Complexity: O(W^2) worst case, but W = 100 (constant) So practically O(1)
    // Space Complexity: O(W)
    // int lastStoneWeight(vector<int>& stones) {
    //     // Max weight constraint is 100
    //     const int MAX_WEIGHT = 100;
    //     vector<int> bucket(MAX_WEIGHT + 1, 0);

    //     // Count frequency of each weight
    //     for (int stone : stones) {
    //         bucket[stone]++;
    //     }

    //     int current = MAX_WEIGHT;  // Start from heaviest

    //     while (true) {
    //         // Find the heaviest available stone
    //         while (current > 0 && bucket[current] == 0) {
    //             current--;
    //         }

    //         if (current == 0) return 0;  // No stones left

    //         bucket[current]--;  // Take first heaviest
    //         int first = current;

    //         // Find next heaviest stone
    //         int next = current;
    //         while (next > 0 && bucket[next] == 0) {
    //             next--;
    //         }

    //         if (next == 0) return first;  // Only one stone left

    //         bucket[next]--;  // Take second heaviest
    //         int second = next;

    //         // If different, insert the difference
    //         int diff = first - second;
    //         bucket[diff]++;

    //         // Reset current to max(first, diff)
    //         current = max(diff, second);
    //     }
    // }
};

int main() {
    vector<int> nums = {2, 3, 6, 2, 4};

    Solution sol;

    cout << sol.lastStoneWeight(nums) << endl;

    return 0;
}