#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    // Brute Force Approach - Time Complexity: O(T * 26), T = total time, Space Complexity : O(26) ≈ O(1)
    // int leastInterval(vector<char>& tasks, int n) {
    //     // Step 1: Count frequencies
    //     vector<int> freq(26, 0);
    //     for (char t : tasks) {
    //         freq[t - 'A']++;
    //     }

    //     // Track when each task becomes available again
    //     vector<int> nextAvailable(26, 0);

    //     int time = 0;
    //     int remaining = tasks.size();

    //     while (remaining > 0) {
    //         time++;

    //         int bestTask = -1;
    //         int maxFreq = 0;

    //         // Step 2: Find best available task
    //         for (int i = 0; i < 26; i++) {
    //             if (freq[i] > 0 && nextAvailable[i] <= time) {
    //                 if (freq[i] > maxFreq) {
    //                     maxFreq = freq[i];
    //                     bestTask = i;
    //                 }
    //             }
    //         }

    //         // Step 3: If we found a task, execute it
    //         if (bestTask != -1) {
    //             freq[bestTask]--;
    //             remaining--;

    //             // Set its next available time
    //             nextAvailable[bestTask] = time + n + 1;
    //         }

    //         // Else → idle (do nothing, just time++)
    //     }

    //     return time;
    // }

    // Optimised approach - Time Complexity: O(N log 26) ≈ O(N), Space Complexity : O(26) ≈ O(1)
    int leastInterval(vector<char>& tasks, int n) {
        // Count frequencies
        unordered_map<char, int> freq;
        for (char t : tasks) {
            freq[t]++;
        }

        // Max heap (based on frequency)
        priority_queue<int> maxHeap;
        for (auto& p : freq) {
            maxHeap.push(p.second);
        }

        // Queue: {remaining_count, time_when_ready}
        queue<pair<int, int>> cooldown;

        int time = 0;

        while (!maxHeap.empty() || !cooldown.empty()) {
            time++;

            // Step 1: Execute task if available
            if (!maxHeap.empty()) {
                int count = maxHeap.top();
                maxHeap.pop();
                count--;

                // If task still remains, put into cooldown
                if (count > 0) {
                    cooldown.push({count, time + n});
                }
            }

            // Step 2: If cooldown task is ready, push back to heap
            if (!cooldown.empty() && cooldown.front().second == time) {
                maxHeap.push(cooldown.front().first);
                cooldown.pop();
            }
        }

        return time;
    }

    // Mathematical Formula Approach - Time Complexity: O(N), Space Complexity: O(26) ≈ O(1)
    // int leastInterval(vector<char>& tasks, int n) {
    //     // Count frequency of each task
    //     vector<int> freq(26, 0);
    //     for (char t : tasks) {
    //         freq[t - 'A']++;
    //     }

    //     // Find the maximum frequency
    //     int maxFreq = *max_element(freq.begin(), freq.end());

    //     // Count how many tasks have the maximum frequency
    //     int maxCount = 0;
    //     for (int f : freq) {
    //         if (f == maxFreq) {
    //             maxCount++;
    //         }
    //     }

    //     // Formula: (maxFreq - 1) * (n + 1) + maxCount
    //     // Represents: (max_freq - 1) groups of (n + 1) slots + remaining tasks with max frequency
    //     int formula = (maxFreq - 1) * (n + 1) + maxCount;

    //     // Return max of total tasks or formula (formula handles idle time, else just execute all)
    //     return max((int)tasks.size(), formula);
    // }
};

int main() {
    vector<char> tasks = {'X', 'X', 'Y', 'Y'};
    int n = 2;
    Solution sol;

    cout << sol.leastInterval(tasks, n) << endl;

    return 0;
}