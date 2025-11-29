#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    // Naive approach : O(N log N) time complexity due to inbuilt sorting
    // vector<int> topKFrequent(vector<int>& nums, int k) {
    //     map<int, int> freqMap;
    //     vector<int> ans;
    //     // Count frequency of each color in nums
    //     for (int num : nums) {
    //         freqMap[num]++;
    //     }

    //     vector<pair<int, int>> freq(freqMap.begin(), freqMap.end());
    //     sort(freq.begin(), freq.end(), [](pair<int, int>& a, pair<int, int>& b) {
    //         return a.second > b.second;
    //     });

    //     int idx = 0;
    //     while (k--) {
    //         ans.push_back(freq[idx++].first);
    //     }

    //     return ans;
    // }

    // Optimised Bucket Sort - O(n) time complexity
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // Get frequency of each element
        unordered_map<int, int> freq;
        for (int num : nums) {
            freq[num]++;
        }

        // Create buckets: index=frequency, value=elements
        vector<vector<int>> bucket(nums.size() + 1);  // max freq <= n

        for (auto& p : freq) {
            bucket[p.second].push_back(p.first);  // freq -> elements with that freq
        }

        // Collect top k from highest freq buckets
        vector<int> result;
        for (int i = bucket.size() - 1; i >= 0; i--) {
            for (int num : bucket[i]) {
                result.push_back(num);
                if (result.size() == k) {
                    return result;  // early exit
                }
            }
        }
        return result;
    }
};

int main() {
    Solution sol;

    vector<int> nums = {1, 2, 2, 3, 3, 3, 4, 4, 4, 4, 4, 4, 4, 4, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6};
    int k = 2;

    vector<int> ans = sol.topKFrequent(nums, k);

    for (int x : ans) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}
