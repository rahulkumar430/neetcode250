#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    // Maxheap approach - Time Complexity: O(N log N), Space Complexity: O(N)
    // int findKthLargest(vector<int>& nums, int k) {
    //     priority_queue<int> maxHeap(nums.begin(), nums.end());

    //     // Extract k-1 largest
    //     for (int i = 0; i < k - 1; i++) {
    //         maxHeap.pop();
    //     }

    //     // Return the kth largest
    //     return maxHeap.top();
    // }

    // Minheap approach - Time Complexity: O(N log k), Space Complexity: O(k)
    int findKthLargest(vector<int>& nums, int k) {
        // Min heap
        priority_queue<int, vector<int>, greater<int>> minHeap;

        for (int num : nums) {
            // Push current number
            minHeap.push(num);

            // If heap size exceeds k, remove smallest
            if (minHeap.size() > k) {
                minHeap.pop();
            }
        }

        // Top of min heap is kth largest
        return minHeap.top();
    }
};

// QuickSelect algorithm - Time Complexity: Average : O(N) Worst Case : O(N ^ 2)(bad pivot choice)
// Space Complexity : O(1) (in - place partitioning)
// class Solution {
//    public:
//     // Partition function (similar to QuickSort)
//     // Places pivot at its correct sorted position
//     // All elements <= pivot go to left
//     int partition(vector<int>& nums, int left, int right) {
//         int pivot = nums[right];  // Choose last element as pivot
//         int curr = left;

//         // Rearrange elements around pivot
//         for (int i = left; i < right; i++) {
//             if (nums[i] <= pivot) {
//                 swap(nums[i], nums[curr]);
//                 curr++;
//             }
//         }

//         // Place pivot in correct position
//         swap(nums[curr], nums[right]);

//         return curr;  // Pivot index
//     }

//     // QuickSelect: only recurse into the side that contains target index
//     void quickSelect(vector<int>& nums, int left, int right, int targetIndex) {
//         if (left >= right) return;

//         int pivotIndex = partition(nums, left, right);

//         if (pivotIndex == targetIndex) {
//             return;
//         } else if (pivotIndex < targetIndex) {
//             quickSelect(nums, pivotIndex + 1, right, targetIndex);
//         } else {
//             quickSelect(nums, left, pivotIndex - 1, targetIndex);
//         }
//     }

//     int findKthLargest(vector<int>& nums, int k) {
//         int n = nums.size();
//         int targetIndex = n - k;  // Convert kth largest to index

//         quickSelect(nums, 0, n - 1, targetIndex);

//         return nums[targetIndex];
//     }
// };

int main() {
    vector<int> nums = {2, 3, 1, 1, 5, 5, 4};
    int k = 3;
    Solution sol;

    cout << sol.findKthLargest(nums, k) << endl;

    return 0;
}