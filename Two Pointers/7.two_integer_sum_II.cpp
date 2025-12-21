#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    // Brute-force approach : O(N^2) Time and O(1) Space complexity
    // vector<int> twoSum(vector<int>& numbers, int target) {
    //     // Iterate over each element in the array
    //     for (int i = 0; i < numbers.size(); i++) {
    //         // For each element at index i, check all elements from i to end
    //         for (int j = i; j < numbers.size(); j++) {
    //             // Check if the sum of the two selected elements equals the target
    //             if (numbers[i] + numbers[j] == target) {
    //                 // Return  1-based indices immediately once the valid pair is found
    //                 return {i + 1, j + 1};
    //             }
    //         }
    //     }

    //     // If no valid pair is found, return {-1, -1}
    //     return {-1, -1};
    // }
    // Two pointers approach due non increasing nature of the vector : O(N) Time and O(1) Space complexity
    vector<int> twoSum(vector<int>& numbers, int target) {
        // Pointer starting from the beginning of the array
        int i = 0;

        // Pointer starting from the end of the array
        int j = numbers.size() - 1;

        // Two-pointer approach: move pointers based on current sum
        while (i < j) {
            // Calculate sum of elements at both pointers
            int currentSum = numbers[i] + numbers[j];

            // If sum is greater than target, move right pointer left
            if (currentSum > target) {
                j--;

                // If sum is smaller than target, move left pointer right
            } else if (currentSum < target) {
                i++;

                // If sum matches the target
            } else {
                return {i + 1, j + 1};
            }
        }

        // If no valid pair is found, return {-1, -1}
        return {-1, -1};
    }
};

int main() {
    vector<int> nums = {1, 2, 3, 4};
    int k = 3;
    vector<int> ans;
    Solution sol;
    ans = sol.twoSum(nums, k);

    // Print 1-based indices summing the target
    for (int x : ans) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}