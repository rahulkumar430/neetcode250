#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    // Optimised Greey + MaxHeap Approach - Time Complexity: O(a + b + c), Space Complexity: O(1)
    string longestDiverseString(int a, int b, int c) {
        // Max heap: {remainingCount, character}
        priority_queue<pair<int, char>> maxHeap;

        if (a > 0) maxHeap.push({a, 'a'});
        if (b > 0) maxHeap.push({b, 'b'});
        if (c > 0) maxHeap.push({c, 'c'});

        string ans = "";

        while (!maxHeap.empty()) {
            auto [count1, char1] = maxHeap.top();
            maxHeap.pop();

            int n = ans.size();

            // If adding char1 creates three consecutive same letters
            if (n >= 2 && ans[n - 1] == char1 && ans[n - 2] == char1) {
                // If no second option available → stop
                if (maxHeap.empty())
                    break;

                auto [count2, char2] = maxHeap.top();
                maxHeap.pop();

                // Use second most frequent character
                ans.push_back(char2);
                count2--;

                if (count2 > 0)
                    maxHeap.push({count2, char2});

                // Put first one back
                maxHeap.push({count1, char1});
            } else {
                // Safe to use char1
                ans.push_back(char1);
                count1--;

                if (count1 > 0)
                    maxHeap.push({count1, char1});
            }
        }

        return ans;
    }

    // Optimised Greey Approach without using heap, as  n = 3 only so for loop will not harm the time complexity
    // Time Complexity: O(a + b + c), Space Complexity: O(1)
    // string longestDiverseString(int a, int b, int c) {
    //     vector<int> freq = {a, b, c};
    //     string ans = "";

    //     while (true) {
    //         int n = ans.size();

    //         // Find largest and second largest
    //         int first = -1, second = -1;

    //         for (int i = 0; i < 3; i++) {
    //             if (freq[i] > 0) {
    //                 if (first == -1 || freq[i] > freq[first]) {
    //                     second = first;
    //                     first = i;
    //                 } else if (second == -1 || freq[i] > freq[second]) {
    //                     second = i;
    //                 }
    //             }
    //         }

    //         if (first == -1)
    //             break;  // nothing left

    //         // If adding first creates triple
    //         if (n >= 2 && ans[n - 1] == (first + 'a') &&
    //             ans[n - 2] == (first + 'a')) {
    //             if (second == -1)
    //                 break;  // no alternative

    //             ans.push_back(second + 'a');
    //             freq[second]--;
    //         } else {
    //             ans.push_back(first + 'a');
    //             freq[first]--;
    //         }
    //     }

    //     return ans;
    // }
};

int main() {
    int a = 3, b = 4, c = 2;

    Solution sol;
    cout << sol.longestDiverseString(a, b, c) << endl;

    return 0;
}