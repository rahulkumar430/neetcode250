#include <bits/stdc++.h>
using namespace std;

class Solution {
    // struct Compare {
    //     bool operator()(vector<int> p1, vector<int> p2) {
    //         int dist1 = p1[0] * p1[0] + p1[1] * p1[1];
    //         int dist2 = p2[0] * p2[0] + p2[1] * p2[1];
    //         return dist1 > dist2;
    //     }
    // };

   public:
    // Minheap approach - Time Complexity: O(N log N), Space Complexity: O(N)
    // vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
    //     vector<vector<int>> ans;
    //     // decalre MinHeap Using Lambda Comparator
    //     // auto cmp = [](vector<int> p1, vector<int> p2) {
    //     //     return p1[0] * p1[0] + p1[1] * p1[1] > p2[0] * p2[0] + p2[1] * p2[1];
    //     // };
    //     // priority_queue<vector<int>, vector<vector<int>>, decltype(cmp)> minHeap(cmp);
    //     priority_queue<vector<int>, vector<vector<int>>, Compare> minHeap;

    //     // Push all points into heap
    //     for (auto& point : points) {
    //         minHeap.push(point);
    //     }

    //     // Extract k closest
    //     for (int i = 0; i < k; i++) {
    //         ans.push_back(minHeap.top());
    //         minHeap.pop();
    //     }

    //     return ans;
    // }

    // Maxheap approach - Time Complexity: O(N log k), Space Complexity: O(k)
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        // Max heap based on distance
        priority_queue<pair<int, vector<int>>> maxHeap;

        for (auto& point : points) {
            int x = point[0];
            int y = point[1];

            // Use squared distance (avoid sqrt)
            int dist = x * x + y * y;

            maxHeap.push({dist, point});

            // Keep only k closest points
            if (maxHeap.size() > k) {
                maxHeap.pop();  // remove farthest
            }
        }

        vector<vector<int>> ans;

        // Extract points from heap
        while (!maxHeap.empty()) {
            ans.push_back(maxHeap.top().second);
            maxHeap.pop();
        }

        return ans;
    }
};

// QuickSelect algorithm - Time Complexity: Average : O(N) Worst Case : O(N ^ 2)(bad pivot choice)
// Space Complexity : O(1) (in - place partitioning)
// class Solution {
//    public:
//     // Helper function to compute squared distance from origin
//     // Use squared distance to avoid unnecessary sqrt()
//     int distance(vector<int>& point) {
//         return point[0] * point[0] + point[1] * point[1];
//     }

//     // Partition function similar to QuickSort
//     // Places pivot element at correct position
//     // All elements with smaller distance go to left
//     int partition(vector<vector<int>>& points, int left, int right) {
//         // Choose last element as pivot
//         int pivotDist = distance(points[right]);
//         int storeIndex = left;

//         // Rearrange elements based on pivot distance
//         for (int i = left; i < right; i++) {
//             // If current distance <= pivot distance
//             // move it to left side
//             if (distance(points[i]) <= pivotDist) {
//                 swap(points[i], points[storeIndex]);
//                 storeIndex++;
//             }
//         }

//         // Place pivot at its correct position
//         swap(points[storeIndex], points[right]);

//         return storeIndex;  // return pivot index
//     }

//     // Only recurse into the part that contains kth element
//     void quickSelect(vector<vector<int>>& points, int left, int right, int k) {
//         if (left >= right) return;

//         int pivotIndex = partition(points, left, right);

//         // If pivot is exactly kth index → done
//         if (pivotIndex == k) {
//             return;
//         }
//         // If pivot is smaller than k → search right side
//         else if (pivotIndex < k) {
//             quickSelect(points, pivotIndex + 1, right, k);
//         }
//         // If pivot is larger than k → search left side
//         else {
//             quickSelect(points, left, pivotIndex - 1, k);
//         }
//     }

//     vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
//         // Rearrange array such that first k elements
//         // are the k closest points
//         quickSelect(points, 0, points.size() - 1, k);

//         // Return first k elements
//         return vector<vector<int>>(points.begin(), points.begin() + k);
//     }
// };

int main() {
    vector<vector<int>> points = {{0, 2}, {2, 2}};
    int k = 1;
    Solution sol;

    vector<vector<int>> ans = sol.kClosest(points, k);

    for (vector<int> x : ans) {
        cout << x[0] << "," << x[1] << endl;
    }

    return 0;
}