#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    // Bruteforce Approach
    // int longestConsecutive(vector<int>& nums) {
    //     int n = nums.size();
    //     if (n == 0) return 0;  // Edge case: empty input

    //     int max_streak = 0;  // Track longest streak found

    //     // Iterate over each number to try building a consecutive streak
    //     for (int i = 0; i < n; i++) {
    //         int current = nums[i], streak_len = 1;

    //         // Attempt to extend the streak by repeatedly looking for current + 1
    //         while (true) {
    //             bool found_next = false;

    //             // Scan entire array to find if next consecutive number exists
    //             for (int j = 0; j < n; j++) {
    //                 if (nums[j] == current + 1) {
    //                     found_next = true;
    //                     current++;     // Move to next number in sequence
    //                     streak_len++;  // Increment streak length
    //                     break;         // Stop scanning after found
    //                 }
    //             }

    //             if (!found_next) break;  // No further extension possible, exit
    //         }

    //         max_streak = max(max_streak, streak_len);  // Update global max streak length
    //     }

    //     return max_streak;
    // }

    // Optimised Solution O(N) time complexity, worst case O(N^2)
    int longestConsecutive(vector<int>& nums) {
        // Hash set to allow O(1)-average lookups for existence checks
        unordered_set<int> s;
        for (int i = 0; i < (int)nums.size(); i++) {
            s.insert(nums[i]);
        }

        int max_streak = 0;  // Length of the longest consecutive sequence

        // Iterate all numbers and only start counting from "sequence starts"
        for (int i = 0; i < (int)nums.size(); i++) {
            // A number is a start if there is no previous consecutive number (num - 1)
            if (s.find(nums[i] - 1) == s.end()) {
                int current = nums[i];
                int streak_len = 1;

                // Count how long the streak continues: num, num+1, num+2, ...
                while (s.find(current + 1) != s.end()) {
                    current++;
                    streak_len++;
                }

                // Update global maximum streak length
                max_streak = max(max_streak, streak_len);
            }
        }

        return max_streak;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {0, 3, 2, 5, 4, 6, 1, 1};

    cout << sol.longestConsecutive(nums) << endl;
    return 0;
}