#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;

        int k = 1;  // index to place next unique element

        for (int i = 1; i < n; i++) {
            if (nums[i] != nums[i - 1]) {  // found a new unique value
                nums[k] = nums[i];         // place it at position k
                k++;                       // move unique write index
            }
        }
        return k;  // number of unique elements
    }
};

int main() {
    vector<int> nums = {2, 10, 10, 10, 30, 30, 30};

    Solution sol;
    cout << sol.removeDuplicates(nums) << endl;

    // Print merged nums
    for (int x : nums) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}