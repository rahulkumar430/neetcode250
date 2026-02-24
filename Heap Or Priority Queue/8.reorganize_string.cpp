#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    // Optimised Approach(Greedy + MaxHeap)
    // Time Complexity: O(N log k) → O(N) if alphabet size is fixed, Space Complexity: O(N)
    // string reorganizeString(string s) {
    //     // Count frequency of each character
    //     unordered_map<char, int> freq;
    //     for (char c : s)
    //         freq[c]++;

    //     // Create max heap to store characters by frequency
    //     priority_queue<pair<int, char>> maxHeap;
    //     for (auto& p : freq)
    //         maxHeap.push({p.second, p.first});

    //     string ans = "";

    //     // Pair up characters from most frequent to least frequent
    //     while (maxHeap.size() >= 2) {
    //         auto p1 = maxHeap.top();
    //         maxHeap.pop();
    //         auto p2 = maxHeap.top();
    //         maxHeap.pop();

    //         // Add both characters to result
    //         ans.push_back(p1.second);
    //         ans.push_back(p2.second);

    //         // Decrease frequency and push back if still available
    //         p1.first--;
    //         p2.first--;

    //         if (p1.first > 0)
    //             maxHeap.push(p1);
    //         if (p2.first > 0)
    //             maxHeap.push(p2);
    //     }

    //     // Handle remaining single character
    //     if (!maxHeap.empty()) {
    //         auto last = maxHeap.top();
    //         // If frequency > 1, reorganization is impossible
    //         if (last.first > 1)
    //             return "";
    //         ans.push_back(last.second);
    //     }

    //     return ans;
    // }

    // Optimal Bucket Approach - Time & Space Complexity: O(N)
    string reorganizeString(string s) {
        int n = s.size();

        vector<int> freq(26, 0);

        // Count frequency
        for (char c : s) {
            freq[c - 'a']++;
        }

        // Find most frequent character
        int maxFreq = 0;
        int maxChar = 0;

        for (int i = 0; i < 26; i++) {
            if (freq[i] > maxFreq) {
                maxFreq = freq[i];
                maxChar = i;
            }
        }

        // If impossible
        if (maxFreq > (n + 1) / 2)
            return "";

        string result(n, ' ');

        int index = 0;

        // Step 1: Fill most frequent character at even indices
        while (freq[maxChar] > 0) {
            result[index] = maxChar + 'a';
            index += 2;
            freq[maxChar]--;
        }

        // Step 2: Fill remaining characters
        for (int i = 0; i < 26; i++) {
            while (freq[i] > 0) {
                if (index >= n)
                    index = 1;  // move to odd positions

                result[index] = i + 'a';
                index += 2;
                freq[i]--;
            }
        }

        return result;
    }
};

int main() {
    string s = "abbccdd";

    Solution sol;
    cout << sol.reorganizeString(s) << endl;

    return 0;
}