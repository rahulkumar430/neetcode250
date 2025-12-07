#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    // O(n) time and O(n) space complexity
    vector<int> majorityElement(vector<int>& nums) {
        // Threshold: element must appear more than floor(size / 3) times
        int n = floor(nums.size() / 3);

        vector<int> ans;                // Store all majority elements (> n/3)
        unordered_map<int, int> count;  // Frequency map for each number

        // Count occurrences of each number
        for (int num : nums) {
            count[num]++;
        }

        // Collect all numbers whose frequency exceeds n
        for (auto& freq : count) {
            if (freq.second > n) {
                ans.push_back(freq.first);
            }
        }

        return ans;
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