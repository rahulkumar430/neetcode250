#include <bits/stdc++.h>
using namespace std;

// DFS Brute Force Approach - Time Complexity: O(V * E), Space Complexity: O(V + E)
// class Solution {
//    public:
//     void dfs(int node, int currTime, vector<vector<pair<int, int>>>& adj, vector<int>& dist) {
//         // If we already reached this node faster before, stop exploring
//         if (currTime >= dist[node]) return;

//         // Update the best time to reach this node
//         dist[node] = currTime;

//         // Explore all neighbors
//         for (auto& [nextNode, weight] : adj[node]) {
//             dfs(nextNode, currTime + weight, adj, dist);
//         }
//     }

//     int networkDelayTime(vector<vector<int>>& times, int n, int k) {
//         // Build adjacency list: sourceNode -> {destinationNode, networkDelay}
//         vector<vector<pair<int, int>>> adj(n + 1);

//         for (auto& t : times) {
//             adj[t[0]].push_back({t[1], t[2]});
//         }

//         // Store minimum time to reach each node
//         vector<int> dist(n + 1, INT_MAX);

//         dfs(k, 0, adj, dist);

//         // Find the maximum delay
//         int ans = *max_element(dist.begin() + 1, dist.end());
//         // if anywhere it is INT_MAX, there is no path
//         return ans == INT_MAX ? -1 : ans;
//     }
// };

// Floyd-Warshall (All-Pairs Shortest Path) Algorithm - Transitive property (i → k → j)
// Time Complexity: O(V^3), Space Complexity: O(V^2)
// class Solution {
//    public:
//     int networkDelayTime(vector<vector<int>>& times, int n, int k) {
//         // distance matrix
//         vector<vector<int>> dist(n + 1, vector<int>(n + 1, INT_MAX));

//         // distance to itself = 0
//         for (int i = 1; i <= n; i++)
//             dist[i][i] = 0;

//         // initialize direct edges : dist[source][destination] = networkDelay
//         for (auto& t : times) {
//             dist[t[0]][t[1]] = t[2];
//         }

//         // Floyd-Warshall core algorithm
//         for (int via = 1; via <= n; via++) {
//             for (int i = 1; i <= n; i++) {
//                 for (int j = 1; j <= n; j++) {
//                     // check if going through "via" improves distance
//                     // Can not add 2 INT_MAX or anything to INT_MAX, it will overflow and give wrong result
//                     if (dist[i][via] != INT_MAX && dist[via][j] != INT_MAX && dist[i][via] + dist[via][j] < dist[i][j]) {
//                         dist[i][j] = dist[i][via] + dist[via][j];
//                     }
//                 }
//             }
//         }

//         // find max time from source k
//         int ans = *max_element(dist[k].begin() + 1, dist[k].end());
//         // if anywhere it is INT_MAX, there is no path
//         return ans == INT_MAX ? -1 : ans;
//     }
// };

// Bellman-Ford Algorithm - repeatedly relaxes all edges up to V−1 times, updating the shortest distance to each node whenever a shorter path through another node is found
// Time Complexity: O(V * E), Space Complexity: O(V)
// class Solution {
//    public:
//     int networkDelayTime(vector<vector<int>>& times, int n, int k) {
//         const int INF = 1e9;  // in order to avoid overflow using INT_MAX

//         // distance array
//         vector<int> dist(n + 1, INF);

//         dist[k] = 0;  // source distance

//         // relax edges n-1 times
//         for (int i = 1; i <= n - 1; i++) {
//             for (auto& t : times) {
//                 int u = t[0];
//                 int v = t[1];
//                 int w = t[2];

//                 // relaxation step
//                 if (dist[u] != INF && dist[u] + w < dist[v]) {
//                     dist[v] = dist[u] + w;
//                 }
//             }
//         }

//         // compute maximum delay
//         int ans = *max_element(dist.begin() + 1, dist.end());
//         // if anywhere it is INT_MAX, there is no path
//         return ans == INF ? -1 : ans;
//     }
// };

// Shortest Path Faster Algorithm (SPFA) - Optimized Bellman-Ford
// Instead of relaxing all edges every iteration : Only process nodes whose distance changed
// Time Complexity: O(V * E) ≈ O(E) Average case , Space Complexity: O(V)
// class Solution {
//    public:
//     int networkDelayTime(vector<vector<int>>& times, int n, int k) {
//         const int INF = 1e9;

//         // Build adjacency list: sourceNode -> {destinationNode, networkDelay}
//         vector<vector<pair<int, int>>> adj(n + 1);

//         for (auto& t : times) {
//             adj[t[0]].push_back({t[1], t[2]});
//         }

//         vector<int> dist(n + 1, INF);
//         // inQueue[node] = true if node is in queue
//         vector<bool> inQueue(n + 1, false);

//         queue<int> q;

//         dist[k] = 0;
//         q.push(k);
//         inQueue[k] = true;

//         while (!q.empty()) {
//             int node = q.front();
//             q.pop();
//             inQueue[node] = false;

//             // explore all neighbors
//             for (auto& edge : adj[node]) {
//                 int next = edge.first;
//                 int weight = edge.second;

//                 // relaxation
//                 if (dist[node] + weight < dist[next]) {
//                     dist[next] = dist[node] + weight;

//                     // push to queue if not already inside
//                     if (!inQueue[next]) {
//                         q.push(next);
//                         inQueue[next] = true;
//                     }
//                 }
//             }
//         }

//         // compute maximum delay
//         int ans = *max_element(dist.begin() + 1, dist.end());
//         // if anywhere it is INT_MAX, there is no path
//         return ans == INF ? -1 : ans;
//     }
// };

// Dijkstra's Algorithm - Greedy shortest path using minheap
// Time Complexity: O((V + E) * log V), Space Complexity: O(V + E)
class Solution {
   public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        // Build adjacency list: sourceNode -> {destinationNode, networkDelay}
        vector<vector<pair<int, int>>> adj(n + 1);

        for (auto& t : times) {
            adj[t[0]].push_back({t[1], t[2]});
        }

        // dist[i] = shortest time required to reach node i
        vector<int> dist(n + 1, INT_MAX);

        // Stores {current_time, node} in min heap, where smallest time will always come first
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        // Start from source node k
        pq.push({0, k});  // time = 0 to reach source
        dist[k] = 0;

        // Dijkstra main loop
        while (!pq.empty()) {
            // Get node with smallest known distance
            auto [time, node] = pq.top();
            pq.pop();

            // Traverse all neighbors of this node
            for (auto& [next, w] : adj[node]) {
                // Relaxation step: If going through current node gives a shorter path
                if (time + w < dist[next]) {
                    // Update shortest distance
                    dist[next] = time + w;

                    // Push updated distance into heap
                    pq.push({dist[next], next});
                }
            }
        }

        // Find the maximum delay
        int ans = *max_element(dist.begin() + 1, dist.end());
        // if anywhere it is INT_MAX, there is no path
        return ans == INT_MAX ? -1 : ans;
    }
};

int main() {
    vector<vector<int>> times = {{1, 2, 1}, {2, 3, 1}, {1, 4, 4}, {3, 4, 1}};
    int n = 4, k = 1;

    Solution sol;
    cout << sol.networkDelayTime(times, n, k) << endl;

    return 0;
}