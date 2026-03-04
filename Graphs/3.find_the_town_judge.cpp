#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    // Naive Approach by counting indegree and outdegree of each person
    // Time Complexity: O(n + m) Space Complexity: O(n), n = number of people, m = number of trust relationships
    // int findJudge(int n, vector<vector<int>>& trust) {
    //     vector<int> indegree(n + 1, 0);   // people who trust i
    //     vector<int> outdegree(n + 1, 0);  // people i trusts

    //     for (auto& t : trust) {
    //         int a = t[0];  // person trusting
    //         int b = t[1];  // person being trusted

    //         outdegree[a]++;
    //         indegree[b]++;
    //     }

    //     for (int i = 1; i <= n; i++) {
    //         // The town judge is trusted by everyone else (n - 1 people) and trusts nobody (0 people)
    //         if (indegree[i] == n - 1 && outdegree[i] == 0) {
    //             return i;
    //         }
    //     }

    //     return -1;
    // }

    // Optimized Approach by using a single array to track trust scores
    // Time Complexity: O(n + m) Space Complexity: O(n), n = number of people, m = number of trust relationships
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> trustScore(n + 1, 0);
        for (auto& t : trust) {
            int a = t[0];  // person trusting
            int b = t[1];  // person being trusted

            trustScore[a]--;  // person a trusts someone, decrease score
            trustScore[b]++;  // person b is trusted by someone, increase score
        }

        for (int i = 1; i <= n; i++) {
            // The town judge will have a trust score of n - 1 (trusted by everyone else) and will not trust anyone (score not decreased)
            if (trustScore[i] == n - 1) {
                return i;
            }
        }
        return -1;
    }
};

int main() {
    vector<vector<int>> trust = {{1, 3}, {4, 3}, {2, 3}};
    int n = 4;
    Solution sol;
    cout << sol.findJudge(n, trust) << endl;

    return 0;
}
