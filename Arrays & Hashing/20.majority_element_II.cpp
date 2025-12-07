#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    // O(n) time and O(n) space complexity
    // vector<int> majorityElement(vector<int>& nums) {
    //     // Threshold: element must appear more than floor(size / 3) times
    //     int n = floor(nums.size() / 3);

    //     vector<int> ans;                // Store all majority elements (> n/3)
    //     unordered_map<int, int> count;  // Frequency map for each number

    //     // Count occurrences of each number
    //     for (int num : nums) {
    //         count[num]++;
    //     }

    //     // Collect all numbers whose frequency exceeds n
    //     for (auto& freq : count) {
    //         if (freq.second > n) {
    //             ans.push_back(freq.first);
    //         }
    //     }

    //     return ans;
    // }

    // Boyer - Moore Voting Algorithm(O(n) time and O(1) space complexity)
    // vector<int> majorityElement(vector<int>& nums) {
    //     int n = nums.size();
    //     int num1 = -1, num2 = -1;  // Two candidate numbers
    //     int cnt1 = 0, cnt2 = 0;    // Vote counts for candidates

    //     // Phase 1: Find up to 2 candidates using voting
    //     for (int num : nums) {
    //         if (num == num1) {
    //             cnt1++;  // Vote for candidate 1
    //         } else if (num == num2) {
    //             cnt2++;  // Vote for candidate 2
    //         } else if (cnt1 == 0) {
    //             num1 = num;  // Replace candidate 1 (no votes)
    //             cnt1 = 1;
    //         } else if (cnt2 == 0) {
    //             num2 = num;  // Replace candidate 2 (no votes)
    //             cnt2 = 1;
    //         } else {
    //             cnt1--;  // Cancel one vote from each candidate
    //             cnt2--;
    //         }
    //     }

    //     // Phase 2: Verify actual frequencies of candidates
    //     cnt1 = cnt2 = 0;
    //     for (int num : nums) {
    //         if (num == num1)
    //             cnt1++;
    //         else if (num == num2)
    //             cnt2++;
    //     }

    //     // Phase 3: Return only candidates exceeding n/3 threshold
    //     vector<int> res;
    //     if (cnt1 > n / 3) res.push_back(num1);
    //     if (cnt2 > n / 3) res.push_back(num2);
    //     return res;
    // }

    // Boyer - Moore Voting Algorithm - Hash map (O(n) time and O(1) space complexity)
    vector<int> majorityElement(vector<int>& nums) {
        unordered_map<int, int> count;  // Track frequency of up to 2 candidates

        // Phase 1: Maintain at most 2 candidates with frequencies
        for (int num : nums) {
            count[num]++;  // Increment frequency

            // If more than 2 candidates, reduce by decrementing all
            if (count.size() > 2) {
                unordered_map<int, int> newCount;
                for (auto& entry : count) {
                    if (entry.second > 1) {
                        newCount[entry.first] = entry.second - 1;  // Keep if has votes left
                    }
                }
                count = newCount;  // Replace with reduced set
            }
        }

        // Phase 2: Verify actual frequencies of surviving candidates
        vector<int> res;
        for (auto& entry : count) {
            int frequency = 0;
            for (int num : nums) {
                if (num == entry.first) frequency++;
            }
            // Add only if frequency > n/3
            if (frequency > nums.size() / 3) {
                res.push_back(entry.first);
            }
        }
        return res;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {5, 2, 3, 2, 2, 2, 2, 5, 5, 5};

    vector<int> ans = sol.majorityElement(nums);

    for (int x : ans) {
        cout << x << " ";
    }
    return 0;
}