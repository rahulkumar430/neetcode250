#include <bits/stdc++.h>
using namespace std;

// Brute force approach - Time Complexity: O(N log N), Space Complexity: O(N)
// class KthLargest {
//    private:
//     vector<int> rNums;  // Stores all numbers in descending sorted order
//     int kth = 0;        // Stores the value of k (which kth largest element to return)

//    public:
//     // Constructor initializes the object with k and the initial numbers
//     KthLargest(int k, vector<int>& nums) {
//         rNums = nums;  // Copy all initial elements
//         kth = k;       // Store k

//         // Sort the vector in descending order
//         sort(rNums.begin(), rNums.end(), greater<int>());

//         // Other possible sorting methods:
//         // sort(rNums.rbegin(), rNums.rend());
//         // sort(rNums.begin(), rNums.end(), [](const int a, const int b) { return a > b; });
//     }

//     // Adds a new value and returns the kth largest element
//     int add(int val) {
//         rNums.push_back(val);  // Insert the new value

//         // Re-sort the entire array (brute force approach)
//         sort(rNums.begin(), rNums.end(), greater<int>());

//         // Since array is sorted in descending order,
//         // kth largest element is at index (k - 1)
//         return rNums[kth - 1];
//     }
// };

// Min Heap Optimised Solution - Time Complexity: Constructor: O(N log K), add(): O(log K), Space Complexity: O(K)
class KthLargest {
   private:
    int kth;  // value of k
    priority_queue<int, vector<int>, greater<int>> minHeap;
    // Min-heap to store k largest elements

   public:
    KthLargest(int k, vector<int>& nums) {
        kth = k;

        // Push elements into heap
        for (int num : nums) {
            minHeap.push(num);

            // Keep only k largest elements
            if (minHeap.size() > kth) {
                minHeap.pop();  // remove smallest
            }
        }
    }

    int add(int val) {
        minHeap.push(val);

        // Maintain heap size = k
        if (minHeap.size() > kth) {
            minHeap.pop();
        }

        // Top of min-heap = kth largest element
        return minHeap.top();
    }
};

int main() {
    vector<int> nums = {1, 2, 3, 3};
    int k = 3;
    KthLargest kthLargest(k, nums);

    cout << kthLargest.add(3) << endl;  // return 3
    cout << kthLargest.add(5) << endl;  // return 3
    cout << kthLargest.add(6) << endl;  // return 3
    cout << kthLargest.add(7) << endl;  // return 5
    cout << kthLargest.add(8) << endl;  // return 6

    return 0;
}