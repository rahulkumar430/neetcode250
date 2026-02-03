#include <bits/stdc++.h>
using namespace std;

// Mock implementation of MountainArray for local testing
class MountainArray {
   private:
    vector<int> arr;

   public:
    MountainArray(vector<int> nums) : arr(nums) {}

    int get(int index) {
        return arr[index];
    }

    int length() {
        return arr.size();
    }
};

class Solution {
   public:
    // Brute-force solution - Time Complexity: O(N), Space Complexity: O(1)
    // This won't work as you can call the get() function a maximum of 100 times a/c to qn
    // int findInMountainArray(int target, MountainArray& mountainArr) {
    //     int n = mountainArr.length();

    //     // Linearly scan the entire mountain array
    //     for (int i = 0; i < n; i++) {
    //         if (mountainArr.get(i) == target) {
    //             return i;
    //         }
    //     }

    //     // Target not found
    //     return -1;
    // }

    // Optimised binary search approach - Time Complexity: O(log N), Space Complexity: O(1)
    int findInMountainArray(int target, MountainArray& mountainArr) {
        int n = mountainArr.length();

        // -------- Step 1: Find the peak index --------
        int l = 0, r = n - 1;
        while (l < r) {
            int mid = l + (r - l) / 2;

            // If mid element is less than next,
            // peak lies on the right side
            if (mountainArr.get(mid) < mountainArr.get(mid + 1)) {
                l = mid + 1;
            }
            // Otherwise, peak lies on the left side (including mid)
            else {
                r = mid;
            }
        }
        int peak = l;

        // -------- Step 2: Binary search on the left (increasing part) --------
        l = 0, r = peak;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            int val = mountainArr.get(mid);

            if (val == target)
                return mid;
            else if (val < target)
                l = mid + 1;
            else
                r = mid - 1;
        }

        // -------- Step 3: Binary search on the right (decreasing part) --------
        l = peak + 1;
        r = n - 1;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            int val = mountainArr.get(mid);

            if (val == target) return mid;
            // Order is reversed because this part is decreasing
            else if (val > target)
                l = mid + 1;
            else
                r = mid - 1;
        }

        // Target not found
        return -1;
    }
};

int main() {
    vector<int> nums = {1, 5, 9, 12, 8, 4, 2};  // valid mountain array
    MountainArray mountainArr(nums);

    Solution sol;
    int target = 8;

    cout << sol.findInMountainArray(target, mountainArr) << endl;  // Expected: 4

    return 0;
}
