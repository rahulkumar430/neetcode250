#include <bits/stdc++.h>
using namespace std;

// Optimised Approach
int majorityElement(vector<int>& nums) {
    int count = 0;  // Counter for the candidate
    int ans = 0;    // Current candidate for majority element

    for (int num : nums) {
        if (count == 0) {
            // If count drops to zero, pick new candidate
            ans = num;
        }
        // Increment count if current element is candidate, else decrement
        count += (num == ans) ? 1 : -1;
    }

    // Return the candidate which is the majority element
    return ans;
}

// Bruteforce Approach
// int majorityElement(vector<int>& nums) {
//     unordered_map<int, int> count;  // Map to store frequency of each element

//     // Count occurrences of each element in nums
//     for (int i = 0; i < nums.size(); i++) {
//         count[nums[i]]++;
//     }

//     int ans = 0;       // To store the element with highest frequency (majority element)
//     int maxCount = 0;  // To track the maximum frequency found so far

//     // Iterate over the frequency map
//     for (auto n : count) {
//         // If current element's frequency is greater than maxCount, update ans and maxCount
//         if (n.second > maxCount) {
//             ans = n.first;        // Update majority element candidate
//             maxCount = n.second;  // Update max frequency
//         }
//     }

//     // Return the majority element found
//     return ans;
// }

int main() {
    vector<int> nums = {5, 5, 1, 1, 1, 5, 5};
    int ans = majorityElement(nums);

    cout << ans << endl;

    return 0;
}