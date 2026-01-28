#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    // Optimal solution - Time complexity : O(N)
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> ans;  // Acts like a stack, you can take a stack and replace back with top and push_back with push and pop_back with pop, and the result will be same

        for (int i = 0; i < asteroids.size(); i++) {
            int curr = asteroids[i];
            bool destroyed = false;

            // Collision happens only if:
            // last asteroid moves right (>0)
            // current asteroid moves left (<0)
            while (!ans.empty() && ans.back() > 0 && curr < 0) {
                // Case 1: last asteroid is smaller → it explodes
                if (abs(ans.back()) < abs(curr)) {
                    ans.pop_back();
                }
                // Case 2: both asteroids are equal → both explode
                else if (abs(ans.back()) == abs(curr)) {
                    ans.pop_back();
                    destroyed = true;
                    break;
                }
                // Case 3: last asteroid is larger → current explodes
                else {
                    destroyed = true;
                    break;
                }
            }

            // Push current asteroid only if it survived
            if (!destroyed) {
                ans.push_back(curr);
            }
        }

        return ans;
    }
};

int main() {
    Solution s;

    vector<int> asteroids = {2, 4, -4, -1};
    vector<int> ans = s.asteroidCollision(asteroids);

    for (int x : ans) {
        cout << x << " ";
    }

    return 0;
}