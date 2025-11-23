#include <bits/stdc++.h>
using namespace std;

// Optimised Approach
int removeElement(vector<int>& nums, int val) {
    int k = 0;  // Pointer to position to place next non-val element
    for (int i = 0; i < nums.size(); i++) {
        if (nums[i] != val) {
            // If current element is not val, move it to index k
            nums[k++] = nums[i];
        }
        // If element is val, do nothing and skip it
    }
    // k now holds the count of elements not equal to val
    // The first k elements of nums are the updated array without val
    return k;
}

// Bruteforce Approach
// int removeElement(vector<int>& nums, int val) {
//     int ans = 0;  // Count of elements not equal to val
//     for (int i = 0; i < nums.size(); i++) {
//         if (nums[i] != val) {
//             // Current element not val, increment count
//             ans++;
//         } else {
//             // Current element equals val, find next non-val element
//             int j = i + 1;
//             // Move j forward while elements are val to find a non-val to swap
//             while (j < nums.size() && nums[j] == val) {
//                 j++;
//             }
//             if (j < nums.size()) {
//                 // Swap the val at i with non-val at j
//                 swap(nums[i], nums[j]);
//                 ans++;  // Increment count as we swapped in a valid element at i
//             } else {
//                 // No more non-val elements to swap, rest are val
//                 break;
//             }
//         }
//     }
//     return ans;
// }

int main() {
    vector<int> nums = {0, 1, 2, 2, 3, 0, 4, 2};
    int val = 2;
    int ans = removeElement(nums, val);

    for (int i = 0; i < nums.size(); i++) {
        cout << nums[i] << " ";
    }
    cout << endl;
    cout << "Elements remaining : " << ans << endl;

    return 0;
}
