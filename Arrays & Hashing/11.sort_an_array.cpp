#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    // Utility function to swap values at two pointers
    void swap(int* a, int* b) {
        int t = *a;
        *a = *b;
        *b = t;
    }

    // Partition function rearranges elements and returns pivot index
    int partition(vector<int>& nums, int low, int high) {
        int pivot = nums[low];  // Choose the first element as pivot
        int start = low;
        int end = high;

        // Move start and end pointers toward each other
        while (start < end) {
            // Move start forward until finding element > pivot
            while (nums[start] <= pivot) {
                start++;
            }
            // Move end backward until finding element <= pivot
            while (nums[end] > pivot) {
                end--;
            }
            // Swap elements if pointers have not crossed
            if (start < end) {
                swap(&nums[start], &nums[end]);
            }
        }
        // Place pivot in its correct position
        swap(&nums[low], &nums[end]);
        return end;  // Return pivot index
    }

    // Main QuickSort function recursively sorts subarrays
    // Time complexity: O(n log n) on average, O(n^2) in worst case
    // Space complexity: O(log n) on average due to recursion stack
    void quickSort(vector<int>& nums, int low, int high) {
        if (low < high) {
            int pi = partition(nums, low, high);  // Partition the array

            quickSort(nums, low, pi - 1);   // Recursively sort left part
            quickSort(nums, pi + 1, high);  // Recursively sort right part
        }
    }

    // Selection sort implementation: find minimum, swap to front
    // Time complexity: O(n^2), Space complexity: O(1)
    void selectionSort(vector<int>& nums, int n) {
        for (int i = 0; i < n - 1; i++) {
            int min_index = i;  // Index of minimum element in unsorted part
            for (int j = i + 1; j < n; j++) {
                if (nums[j] < nums[min_index]) {
                    min_index = j;
                }
            }
            swap(&nums[i], &nums[min_index]);  // Put minimum in correct place
        }
    }

    // Insertion sort implementation: build sorted section one element at a time
    // Time complexity: O(n^2), Space complexity: O(1)
    void insertionSort(vector<int>& nums, int n) {
        for (int i = 1; i <= n - 1; i++) {
            int e = nums[i];
            int j = i - 1;
            // Shift elements greater than e to one position ahead
            while (j >= 0 && nums[j] > e) {
                nums[j + 1] = nums[j];
                j = j - 1;
            }
            nums[j + 1] = e;  // Insert element in correct position
        }
    }

    // Bubble sort implementation: repeatedly swap adjacent if out of order
    // Time complexity: O(n^2), Space complexity: O(1)
    void bubbleSort(vector<int>& nums, int n) {
        // Outer loop controls passes
        for (int itr = 1; itr < n; itr++) {
            // Inner loop for pairwise swapping
            for (int j = 0; j <= ((n - 1) - itr); j++) {
                if (nums[j] > nums[j + 1]) {
                    swap(&nums[j], &nums[j + 1]);
                }
            }
        }
    }

    // Function to call QuickSort by default and return sorted array
    vector<int> sortArray(vector<int>& nums) {
        quickSort(nums, 0, nums.size() - 1);  // Best solution will quickSort based on the requirement of the problem
        // Uncomment to use other sorts:
        // selectionSort(nums, nums.size());
        // insertionSort(nums, nums.size());
        // bubbleSort(nums, nums.size());
        return nums;
    }
};

int main() {
    Solution solution;
    vector<int> nums = {10, 9, 1, 1, 1, 2, 3, 1};
    vector<int> sorted_nums = solution.sortArray(nums);

    for (int num : sorted_nums) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
