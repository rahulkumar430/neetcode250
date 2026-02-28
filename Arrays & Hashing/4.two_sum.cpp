#include <bits/stdc++.h>
using namespace std;

// Bruteforce Approach
// Time Complexity: O(n^2), Space Complexity: O(1)
// vector<int> twoSum(vector<int>& nums, int target) {
//     vector<int> ans;
//     for (int i = 0; i < nums.size(); i++) {
//         for (int j = 0; j < nums.size(); j++) {
//             if (nums[i] + nums[j] == target && i != j) {
//                 ans.push_back(i);
//                 ans.push_back(j);
//                 return ans;
//             }
//         }
//     }
//     return {0, 0};
// }

// Optimised Approach
// Time Complexity: O(n), Space Complexity: O(n)
vector<int> twoSum(vector<int>& nums, int target) {
    unordered_map<int, int> countMap;  //<value,index>
    // loop through the vector and store all the index
    for (int i = 0; i < nums.size(); i++) {
        countMap[nums[i]] = i;
    }
    for (int i = 0; i < nums.size(); i++) {
        // using hashmaps O(1) time complexity to search,
        // find if the difference of target and the number exists or not
        auto it = countMap.find(target - nums[i]);
        if (it != countMap.end() && i != it->second) {
            return {i, it->second};
        }
    }
    return {0, 0};
}

int main() {
    vector<int> nums = {4, 5, 6};
    int target = 10;

    vector<int> result = twoSum(nums, target);

    cout << "[" << result[0] << "," << result[1] << "]" << endl;

    return 0;
}