#include <bits/stdc++.h>
using namespace std;

// Brute Force Approach(Using Sorting)
// Time Complexity: addNum(): O(N log N), findMedian():O(1)
// Space Complexity: O(N)
// class MedianFinder {
//    private:
//     vector<int> v;

//    public:
//     MedianFinder() {
//     }

//     void addNum(int num) {
//         v.push_back(num);
//         sort(v.begin(), v.end());
//     }

//     double findMedian() {
//         int n = v.size();
//         return (n % 2 == 1) ? v[n / 2] : (v[n / 2 - 1] + v[n / 2]) / 2.0;
//     }
// };

// Optimised Approach (Using MaxHeap and MinHeap)
// Time Complexity: addNum(): O(log N), findMedian(): O(1)
// Space Complexity: O(N)
class MedianFinder {
   private:
    priority_queue<int> maxHeap;                             // max heap for smaller half
    priority_queue<int, vector<int>, greater<int>> minHeap;  // min heap for larger half

   public:
    MedianFinder() {
    }

    void addNum(int num) {
        // add to max heap if empty or num is smaller
        if (maxHeap.empty() || num <= maxHeap.top()) {
            maxHeap.push(num);
        } else {
            minHeap.push(num);
        }

        // balance heaps: max heap size should be equal or 1 more than min heap
        if (maxHeap.size() > minHeap.size() + 1) {
            minHeap.push(maxHeap.top());
            maxHeap.pop();
        } else if (minHeap.size() > maxHeap.size()) {
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }
    }

    double findMedian() {
        // if odd total elements, return top of max heap
        if (maxHeap.size() > minHeap.size()) {
            return maxHeap.top();
        }
        // if even, return average of both heap tops
        return (maxHeap.top() + minHeap.top()) / 2.0;
    }
};

int main() {
    MedianFinder medianFinder;
    medianFinder.addNum(1);                     // arr = [1]
    cout << medianFinder.findMedian() << endl;  // return 1.0
    medianFinder.addNum(3);                     // arr = [1, 3]
    cout << medianFinder.findMedian() << endl;  // return 2.0
    medianFinder.addNum(2);                     // arr[1, 2, 3]
    cout << medianFinder.findMedian() << endl;  // return 2.0

    return 0;
}