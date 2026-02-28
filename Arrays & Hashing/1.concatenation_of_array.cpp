#include <bits/stdc++.h>
using namespace std;

// Time Complexity: O(n), Space Complexity: O(1) (in place modification)
vector<int> getConcatenation(vector<int>& nums) {
    nums.insert(nums.end(), nums.begin(), nums.end());
    return nums;
}

int main() {
    vector<int> nums = {1, 4, 1, 2};
    vector<int> result = getConcatenation(nums);

    for (int val : result) {
        cout << val << " ";
    }
    cout << endl;
    return 0;
}