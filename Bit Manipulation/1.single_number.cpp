#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    // Naive approach : Time Complexity: O(N), Space Complexity: O(1)
    int singleNumber(vector<int>& nums) {
        int ans = 0;
        // XOR all numbers, Every duplicate cancels out
        for (int num : nums) {
            ans ^= num;
        }

        return ans;
    }
};

int main() {
    Solution s;
    vector<int> nums = {7, 6, 6, 7, 8};

    cout << s.singleNumber(nums) << endl;

    return 0;
}