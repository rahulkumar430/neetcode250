#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    // Optimised Approach - O(N log N) due to sorting, O(N) two-pointer scan
    // int numRescueBoats(vector<int>& people, int limit) {
    //     // Stores the minimum number of boats required
    //     int ans = 0;

    //     // Sort people by weight so we can use two-pointer technique
    //     sort(people.begin(), people.end());

    //     // Left pointer: lightest person
    //     int l = 0;

    //     // Right pointer: heaviest person
    //     int r = people.size() - 1;

    //     // Process people until pointers cross
    //     while (l < r) {
    //         /*
    //         If the heaviest person alone has weight equal to the limit,
    //         they must go alone in a boat.
    //         */
    //         if (people[r] == limit) {
    //             r--;    // Heaviest person boards alone
    //             ans++;  // One boat used
    //         }

    //         /*
    //         Try to pair the lightest and heaviest person:
    //         - If their combined weight is within the limit, they can share a boat.
    //         - Otherwise, the heaviest person must go alone.
    //         */
    //         if (people[l] + people[r] <= limit) {
    //             // Pair lightest and heaviest
    //             l++;
    //             r--;
    //             ans++;  // One boat used
    //         } else {
    //             // Heaviest person goes alone
    //             r--;
    //             ans++;  // One boat used
    //         }
    //     }

    //     /*
    //     If one person remains unpaired (l == r),
    //     they need one separate boat.
    //     */
    //     if (l == r) {
    //         ans++;
    //     }

    //     // Return the total number of boats needed
    //     return ans;
    // }

    // Without redundancy of code
    int numRescueBoats(vector<int>& people, int limit) {
        // Sort people by weight
        sort(people.begin(), people.end());

        int l = 0;                  // lightest person
        int r = people.size() - 1;  // heaviest person
        int ans = 0;                // number of boats

        // Continue until all people are assigned
        while (l <= r) {
            /*
            Try to pair the lightest and heaviest person.
            If they fit together, move both pointers.
            Otherwise, the heaviest person goes alone.
            */
            if (people[l] + people[r] <= limit) {
                l++;  // lightest person boards
            }

            // Heaviest person always boards a boat
            r--;
            ans++;  // one boat used
        }

        return ans;
    }
};

int main() {
    vector<int> people = {3, 5, 3, 4};
    int limit = 5;
    Solution sol;
    cout << sol.numRescueBoats(people, limit);

    return 0;
}