#include <bits/stdc++.h>
using namespace std;

// DFS Brute Force Approach - Time Complexity: O(V!), Space Complexity: O(V + E)
// Due to the fact that the number of possible paths is O(V!), it can give TLE sometimes
// class Solution {
//    public:
//     int n;
//     vector<string> result;

//     // DFS function
//     bool dfs(string curr, unordered_map<string, vector<pair<string, bool>>>& adj, vector<string>& path) {
//         // If all tickets are used → valid itinerary
//         if (path.size() == n + 1) {
//             result = path;
//             return true;  // stop early (smallest lexicographical)
//         }

//         // Traverse all outgoing edges
//         for (auto& edge : adj[curr]) {
//             string next = edge.first;
//             bool& used = edge.second;  // reference to modify directly

//             // Skip if already used
//             if (used) continue;

//             // Mark this ticket as used
//             used = true;

//             path.push_back(next);

//             // Continue DFS
//             if (dfs(next, adj, path))
//                 return true;

//             // Backtrack
//             path.pop_back();
//             used = false;
//         }

//         return false;
//     }

//     vector<string> findItinerary(vector<vector<string>>& tickets) {
//         n = tickets.size();

//         // Build adjacency with used flag
//         unordered_map<string, vector<pair<string, bool>>> adj;

//         for (auto& t : tickets) {
//             adj[t[0]].push_back({t[1], false});
//         }

//         // Sort based on destination (lexicographically)
//         for (auto& p : adj) {
//             sort(p.second.begin(), p.second.end(),
//                  [](auto& a, auto& b) {
//                      return a.first < b.first;
//                  });
//         }

//         vector<string> path;
//         path.push_back("JFK");

//         dfs("JFK", adj, path);

//         return result;
//     }
// };

// Hierholzer's Algorithm (Optimal — Eulerian Path) - Using vector & sort
// Greedy DFS combined with Post-Order Traversal
// Time Complexity: O(E log E), Space Complexity: O(E)
// class Solution {
//    public:
//     vector<string> result;

//     void dfs(string curr, unordered_map<string, vector<string>>& adj) {
//         // Continue while there are outgoing edges
//         while (!adj[curr].empty()) {
//             // Take the lexicographically smallest airport
//             string next = adj[curr].back();

//             // Remove the edge
//             adj[curr].pop_back();

//             dfs(next, adj);
//         }

//         // Postorder insertion
//         // Dead ends are not wrong — they are just final nodes of subpaths, and we place them in the result first.
//         result.push_back(curr);
//     }

//     vector<string> findItinerary(vector<vector<string>>& tickets) {
//         unordered_map<string, vector<string>> adj;

//         // Build graph
//         for (auto& t : tickets)
//             adj[t[0]].push_back(t[1]);

//         // Sort destinations in reverse lexical order
//         // so we can pop_back() smallest first
//         for (auto& p : adj)
//             sort(p.second.rbegin(), p.second.rend());

//         dfs("JFK", adj);

//         reverse(result.begin(), result.end());

//         return result;
//     }
// };

// Hierholzer's Algorithm (Optimal — Eulerian Path) - Using Min Heap
// Time Complexity: O(E log E), Space Complexity: O(E)
class Solution {
   public:
    vector<string> result;

    void dfs(string curr, unordered_map<string, priority_queue<string, vector<string>, greater<string>>>& adj) {
        auto& pq = adj[curr];

        while (!pq.empty()) {
            // Take the lexicographically smallest airport which is on top of the min heap
            string next = pq.top();
            // Remove the edge
            pq.pop();

            dfs(next, adj);
        }
        // Postorder insertion
        // Dead ends are not wrong — they are just final nodes of subpaths, and we place them in the result first.
        result.push_back(curr);
    }

    vector<string> findItinerary(vector<vector<string>>& tickets) {
        // Build graph using min heap, because we want the lexicographically smallest
        unordered_map<string, priority_queue<string, vector<string>, greater<string>>> adj;

        for (auto& t : tickets)
            adj[t[0]].push(t[1]);

        dfs("JFK", adj);

        reverse(result.begin(), result.end());

        return result;
    }
};

int main() {
    vector<vector<string>> tickets = {{"BUF", "HOU"}, {"HOU", "SEA"}, {"JFK", "BUF"}};

    Solution sol;
    vector<string> ans = sol.findItinerary(tickets);

    for (string s : ans) {
        cout << s << "  ";
    }
    return 0;
}