#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    // Basic BFS Approach
    // Time Complexity: O(d^n), Space Complexity: O(d^n), d = number of digits(10), n = number of wheels(4)
    // int openLock(vector<string>& deadends, string target) {
    //     unordered_set<string> deadSet(deadends.begin(), deadends.end());
    //     if (deadSet.count("0000")) return -1;

    //     queue<string> q;
    //     unordered_set<string> visited;

    //     q.push("0000");
    //     visited.insert("0000");

    //     int moves = 0;

    //     while (!q.empty()) {
    //         int size = q.size();

    //         while (size--) {
    //             string curr = q.front();
    //             q.pop();

    //             if (curr == target)
    //                 return moves;

    //             // Generate all possible combinations by rotating each wheel
    //             for (int i = 0; i < 4; i++) {
    //                 string up = curr;
    //                 string down = curr;

    //                 // rotate wheel forward
    //                 up[i] = (curr[i] == '9') ? '0' : curr[i] + 1;

    //                 // rotate wheel backward
    //                 down[i] = (curr[i] == '0') ? '9' : curr[i] - 1;

    //                 // Check if the new combinations are not in deadSet and not visited before adding to the queue
    //                 if (!deadSet.count(up) && !visited.count(up)) {
    //                     visited.insert(up);
    //                     q.push(up);
    //                 }

    //                 if (!deadSet.count(down) && !visited.count(down)) {
    //                     visited.insert(down);
    //                     q.push(down);
    //                 }
    //             }
    //         }

    //         moves++;
    //     }

    //     return -1;
    // }

    // Bidirectional BFS Approach
    // Time Complexity: O(d^(n/2)), Space Complexity: O(d^(n/2)), d = number of digits(10), n = number of wheels(4)
    int openLock(vector<string>& deadends, string target) {
        unordered_set<string> deadSet(deadends.begin(), deadends.end());
        if (deadSet.count("0000")) return -1;

        unordered_set<string> beginSet = {"0000"};
        unordered_set<string> endSet = {target};
        unordered_set<string> visited;

        int moves = 0;

        // Continue until either frontier is empty
        while (!beginSet.empty() && !endSet.empty()) {
            // Always expand the smaller frontier to reduce branching
            if (beginSet.size() > endSet.size())
                swap(beginSet, endSet);

            unordered_set<string> nextLevel;  // To store the next level of combinations

            for (string curr : beginSet) {
                // If the current combination is in the opposite frontier, we found a path
                if (endSet.count(curr))
                    return moves;

                // If the current combination is a deadend, skip it
                if (deadSet.count(curr))
                    continue;

                visited.insert(curr);

                for (int i = 0; i < 4; i++) {
                    string up = curr;
                    string down = curr;

                    up[i] = (curr[i] == '9') ? '0' : curr[i] + 1;
                    down[i] = (curr[i] == '0') ? '9' : curr[i] - 1;

                    if (!visited.count(up))
                        nextLevel.insert(up);

                    if (!visited.count(down))
                        nextLevel.insert(down);
                }
            }
            // Move to the next level and increment the move count
            beginSet = nextLevel;
            moves++;
        }

        return -1;
    }
};

int main() {
    vector<string> deadends = {"1111", "0120", "2020", "3333"};
    string target = "5555";

    Solution sol;
    cout << sol.openLock(deadends, target) << endl;

    return 0;
}