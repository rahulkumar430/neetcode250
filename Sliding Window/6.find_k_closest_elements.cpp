#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    // Sorting(Custom Comparator) - Time Complexity : O(N logN)
    // vector<int> findClosestElements(vector<int>& arr, int k, int x) {
    //     // Custom comparator
    //     sort(arr.begin(), arr.end(), [x](int a, int b) {
    //         int diff = abs(a - x) - abs(b - x);
    //         return diff == 0 ? a < b : diff < 0;
    //     });

    //     // Take the first k closest elements
    //     vector<int> result(arr.begin(), arr.begin() + k);

    //     // Sort the result in ascending order as required
    //     sort(result.begin(), result.end());

    //     return result;
    // }

    // Optimised Approach using binary lower bound search + two pointers
    // Time Complexity : O(log N + k log k)
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int n = arr.size();

        // Use binary search to find the first index where arr[idx] >= x
        int idx = lower_bound(arr.begin(), arr.end(), x) - arr.begin();

        // Adjust idx to point to the closest element to x, Compare arr[idx] and arr[idx - 1] if both are valid

        if (idx > 0 && (idx == n || abs(arr[idx] - x) >= abs(arr[idx - 1] - x))) {
            idx--;
        }

        // Store the closest element
        vector<int> res = {arr[idx]};

        // Two pointers expanding outward from idx
        int l = idx - 1;
        int r = idx + 1;

        // Expand window until we collect k elements, Always pick the closer element between left and right
        while (res.size() < k) {
            if (l >= 0 && r < n) {
                if (abs(arr[l] - x) <= abs(arr[r] - x)) {
                    res.push_back(arr[l--]);
                } else {
                    res.push_back(arr[r++]);
                }
            }
            // Only left side available
            else if (l >= 0) {
                res.push_back(arr[l--]);
            }
            // Only right side available
            else if (r < n) {
                res.push_back(arr[r++]);
            }
        }

        // Result must be returned in ascending order
        sort(res.begin(), res.end());

        return res;
    }
};

int main() {
    vector<int> arr = {2, 4, 5, 10};
    int k = 3;
    int x = 6;

    Solution sol;
    vector<int> ans;
    ans = sol.findClosestElements(arr, k, x);
    for (int i : ans) {
        cout << i << "  ";
    }

    return 0;
}