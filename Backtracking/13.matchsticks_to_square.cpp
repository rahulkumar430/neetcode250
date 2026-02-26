#include <bits/stdc++.h>
using namespace std;

// Backtracking Approach (Partition array into 4 subsets with equal sum)
// Time Complexity: O(4^n), Space Complexity: O(n)
// class Solution {
//    public:
//     bool backtrack(int index, vector<int>& matchsticks, vector<int>& sides, int target) {
//         // If all sticks assigned
//         if (index == matchsticks.size()) {
//             // All 4 sides must equal target
//             return sides[0] == target &&
//                    sides[1] == target &&
//                    sides[2] == target &&
//                    sides[3] == target;
//         }

//         for (int i = 0; i < 4; i++) {
//             // If adding this stick exceeds side length → skip
//             if (sides[i] + matchsticks[index] > target)
//                 continue;

//             // Place stick into side i
//             sides[i] += matchsticks[index];

//             // Recurse for next stick
//             if (backtrack(index + 1, matchsticks, sides, target))
//                 return true;

//             // Undo placement
//             sides[i] -= matchsticks[index];

//             // Optimization:
//             // If this side was empty and placing failed,
//             // no need to try other empty sides (symmetry pruning)
//             if (sides[i] == 0)
//                 break;
//         }

//         return false;
//     }

//     bool makesquare(vector<int>& matchsticks) {
//         int total = accumulate(matchsticks.begin(), matchsticks.end(), 0);

//         if (total % 4 != 0)
//             return false;

//         int target = total / 4;

//         // Sort descending for better pruning
//         sort(matchsticks.rbegin(), matchsticks.rend());

//         // If largest stick > target → impossible
//         if (matchsticks[0] > target)
//             return false;

//         vector<int> sides(4, 0);

//         return backtrack(0, matchsticks, sides, target);
//     }
// };

// More Optimised Backtracking Approach
// Time Complexity: O(n * 2^n), Space Complexity: O(n)
class Solution {
   private:
    vector<bool> used;  // Tracks which sticks are already used
    int target;         // Required length for each side

    bool backtrack(vector<int>& matchsticks,
                   int k,           // Remaining sides to build
                   int currentSum,  // Current side length being built
                   int start) {     // Start index for choosing sticks

        // If all 4 sides are successfully built
        if (k == 0)
            return true;

        // If current side reached target, start building next side
        if (currentSum == target)
            return backtrack(matchsticks, k - 1, 0, 0);

        for (int i = start; i < matchsticks.size(); i++) {
            // Skip if already used OR exceeds side length
            if (used[i] || currentSum + matchsticks[i] > target)
                continue;

            // Choose this stick
            used[i] = true;

            // Continue building current side
            if (backtrack(matchsticks, k, currentSum + matchsticks[i], i + 1))
                return true;

            // Undo choice
            used[i] = false;

            // Pruning:
            // If we tried starting a new side and it failed,
            // no need to try other sticks at same level
            if (currentSum == 0)
                return false;
        }

        return false;
    }

   public:
    bool makesquare(vector<int>& matchsticks) {
        int total = accumulate(matchsticks.begin(), matchsticks.end(), 0);

        // Total must be divisible by 4
        if (total % 4 != 0)
            return false;

        target = total / 4;

        // Sort descending → larger sticks placed first (faster pruning)
        sort(matchsticks.rbegin(), matchsticks.rend());

        // If largest stick > target → impossible
        if (matchsticks[0] > target)
            return false;

        used.assign(matchsticks.size(), false);

        return backtrack(matchsticks, 4, 0, 0);
    }
};

int main() {
    vector<int> matchsticks = {1, 3, 4, 2, 2, 4};

    Solution sol;
    cout << (sol.makesquare(matchsticks) ? "true" : "false") << endl;

    return 0;
}