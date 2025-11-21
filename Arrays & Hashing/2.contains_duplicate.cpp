#include <bits/stdc++.h>
using namespace std;

bool hasDuplicate(vector<int>& nums) {
    map<int, int> numsCount = {};  // using map to loop and add the count of each number
    for (int i = 0; i < nums.size(); i++) {
        numsCount[nums[i]]++;

        // If any numbers count is greater than 1 then return true
        if (numsCount[nums[i]] > 1) {
            return true;
        }
    }
    return false;
}

int main() {
    vector<int> nums = {1, 2, 3, 3};

    cout << (hasDuplicate(nums) ? "true" : "false") << endl;
    return 0;
}