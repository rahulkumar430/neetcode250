#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    void sortColors(vector<int>& nums) {
        unordered_map<int, int> sortedNums;  // key: color (0/1/2), value: frequency

        // Count frequency of each color in nums
        for (int num : nums) {
            sortedNums[num]++;
        }

        int idx = 0;  // write index in nums

        // Refill nums in order: all 0s, then all 1s, then all 2s
        for (int i = 0; i <= 2; i++) {
            int count = sortedNums[i];  // how many times color i appears
            while (count > 0) {
                nums[idx] = i;  // place color i at current index
                idx++;
                count--;
            }
        }
    }

    // Dutch National Flag Algorithm (3 pointers) : A little optimised way than the first one
    // void sortColors(vector<int>& nums) {
    //     int low = 0;                 // boundary for 0s
    //     int mid = 0;                 // current element being examined
    //     int high = nums.size() - 1;  // boundary for 2s

    //     while (mid <= high) {
    //         if (nums[mid] == 0) {
    //             // swap with low and increment both
    //             swap(nums[low], nums[mid]);
    //             low++;
    //             mid++;
    //         } else if (nums[mid] == 1) {
    //             // 1 stays in middle, just move forward
    //             mid++;
    //         } else {  // nums[mid] == 2
    //             // swap with high and decrement high (don't increment mid)
    //             swap(nums[mid], nums[high]);
    //             high--;
    //         }
    //     }
    // }
};

int main() {
    Solution sol;

    vector<int> nums = {2, 0, 2, 1, 1, 0};

    sol.sortColors(nums);

    for (int x : nums) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}
