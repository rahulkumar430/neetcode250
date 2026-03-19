#include <bits/stdc++.h>
using namespace std;

// Dijkstra's Algorithm - Time Complexity: O(E * k * log(n * k)), Space Complexity: O(n * k)
// n = number of nodes (cities), E = number of flights(edges), k = maximum allowed stops
// class Solution {
//    public:
//     int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
//         // Build adjacency list
//         vector<vector<pair<int, int>>> adj(n);
//         for (auto& f : flights) {
//             adj[f[0]].push_back({f[1], f[2]});
//         }

//         // Min heap: {cost, node, stops}
//         priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;

//         pq.push({0, src, 0});

//         // dist[node][stops] = min cost
//         vector<vector<int>> dist(n, vector<int>(k + 2, INT_MAX));
//         dist[src][0] = 0;

//         while (!pq.empty()) {
//             auto curr = pq.top();
//             pq.pop();

//             int cost = curr[0];
//             int node = curr[1];
//             int stops = curr[2];

//             // If destination reached
//             if (node == dst) return cost;

//             // If exceeded stops
//             if (stops > k) continue;

//             for (auto& [next, price] : adj[node]) {
//                 int newCost = cost + price;

//                 if (newCost < dist[next][stops + 1]) {
//                     dist[next][stops + 1] = newCost;

//                     pq.push({newCost, next, stops + 1});
//                 }
//             }
//         }

//         return -1;
//     }
// };

// Bellman-Ford Algorithm - Time Complexity: O(E * k), Space Complexity: O(n)
// n = number of nodes (cities), E = number of flights(edges), k = maximum allowed stops
class Solution {
   public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        // Distance array
        vector<int> dist(n, INT_MAX);
        dist[src] = 0;

        // Relax edges k+1 times
        for (int i = 0; i <= k; i++) {
            // Copy of previous distances
            // Each iteration adds one more allowed edge,
            // and using a temp array ensures we don’t exceed the stop limit.
            vector<int> temp = dist;

            for (auto& f : flights) {
                int u = f[0];
                int v = f[1];
                int w = f[2];

                // If source reachable
                if (dist[u] != INT_MAX) {
                    temp[v] = min(temp[v], dist[u] + w);
                }
            }

            // Update distances
            dist = temp;
        }

        return dist[dst] == INT_MAX ? -1 : dist[dst];
    }
};

// SPFA (Shortest Path Faster Algorithm) - Queue-optimized Bellman–Ford Algorithm
// Time Complexity: O(E * k), Space Complexity: O(n)
// class Solution {
//    public:
//     int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
//         // Step 1: Build adjacency list
//         vector<vector<pair<int, int>>> adj(n);
//         for (auto& f : flights) {
//             int u = f[0], v = f[1], w = f[2];
//             adj[u].push_back({v, w});
//         }

//         // Step 2: Distance array
//         // dist[i] = minimum cost to reach node i
//         vector<int> dist(n, INT_MAX);
//         dist[src] = 0;

//         // Step 3: Queue (SPFA style)
//         // {currentCost, currentNode, stopsUsed}
//         queue<tuple<int, int, int>> q;
//         q.push({0, src, 0});

//         // Step 4: BFS traversal
//         while (!q.empty()) {
//             auto [cost, node, stops] = q.front();
//             q.pop();

//             // If stops exceed limit → skip this path
//             if (stops > k) continue;

//             // Explore neighbors
//             for (auto& [next, price] : adj[node]) {
//                 int newCost = cost + price;

//                 // Relaxation step
//                 if (newCost < dist[next]) {
//                     dist[next] = newCost;

//                     // Push next state with incremented stops
//                     q.push({newCost, next, stops + 1});
//                 }
//             }
//         }

//         // Step 5: Result
//         return dist[dst] == INT_MAX ? -1 : dist[dst];
//     }
// };

int main() {
    int n = 4;
    vector<vector<int>> flights = {{0, 1, 200}, {1, 2, 100}, {1, 3, 300}, {2, 3, 100}};
    int src = 0, dst = 3, k = 1;

    Solution sol;
    cout << sol.findCheapestPrice(n, flights, src, dst, k) << endl;
    return 0;
}