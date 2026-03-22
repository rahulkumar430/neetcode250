#include <bits/stdc++.h>
using namespace std;

// DFS Approach on both row and column - Time Complexity: O(k + n + m), Space Complexity: O(k + n + m)
// class Solution {
//    public:
//     vector<int> rowOrder, colOrder;

//     bool dfs(int node, vector<vector<int>>& graph, vector<int>& state, vector<int>& order) {
//         // If node is currently being visited → cycle detected
//         if (state[node] == 1)
//             return false;

//         // Already processed safely
//         if (state[node] == 2)
//             return true;

//         state[node] = 1;  // mark as visiting

//         for (int neigh : graph[node]) {
//             if (!dfs(neigh, graph, state, order))
//                 return false;
//         }

//         state[node] = 2;        // mark as fully processed
//         order.push_back(node);  // add to topological order
//         return true;
//     }

//     vector<vector<int>> buildMatrix(int k, vector<vector<int>>& rowConditions, vector<vector<int>>& colConditions) {
//         vector<vector<int>> rowGraph(k + 1), colGraph(k + 1);

//         for (auto& p : rowConditions) {
//             // above: p[0], below: p[1] => above -> below
//             rowGraph[p[0]].push_back(p[1]);
//         }
//         for (auto& p : colConditions) {
//             // left: p[0], right: p[1] => left -> right
//             colGraph[p[0]].push_back(p[1]);
//         }

//         vector<int> rowState(k + 1, 0), colState(k + 1, 0);

//         for (int i = 1; i <= k; i++) {
//             if (!dfs(i, rowGraph, rowState, rowOrder))
//                 return {};
//         }
//         for (int i = 1; i <= k; i++) {
//             if (!dfs(i, colGraph, colState, colOrder))
//                 return {};
//         }

//         // Reverse the order to get correct topological sorting because of dfs nature
//         reverse(rowOrder.begin(), rowOrder.end());
//         reverse(colOrder.begin(), colOrder.end());

//         // Map number to position
//         unordered_map<int, int> rowPos, colPos;
//         for (int i = 0; i < k; i++) {
//             rowPos[rowOrder[i]] = i;
//             colPos[colOrder[i]] = i;
//         }

//         vector<vector<int>> ans(k, vector<int>(k, 0));

//         for (int num = 1; num <= k; num++) {
//             ans[rowPos[num]][colPos[num]] = num;
//         }

//         return ans;
//     }
// };

// Kahn's Algorithm - Time Complexity: O(k + n + m), Space Complexity: O(k + n + m)
class Solution {
   public:
    vector<int> topoSort(int k, vector<vector<int>>& conditions) {
        vector<vector<int>> graph(k + 1);
        vector<int> indegree(k + 1, 0);

        // Step 1: Build graph + indegree
        for (auto& p : conditions) {
            int u = p[0], v = p[1];
            graph[u].push_back(v);
            indegree[v]++;
        }

        // Step 2: Push nodes with indegree 0
        queue<int> q;
        for (int i = 1; i <= k; i++) {
            if (indegree[i] == 0)
                q.push(i);
        }

        vector<int> order;

        // Step 3: BFS
        while (!q.empty()) {
            int node = q.front();
            q.pop();

            order.push_back(node);  // add node to topological order

            for (int neigh : graph[node]) {
                // Reduce indegree of dependent nodes and push all the independent ones
                indegree[neigh]--;
                if (indegree[neigh] == 0)
                    q.push(neigh);
            }
        }

        // Step 4: Cycle check
        if (order.size() != k)
            return {};  // cycle

        return order;
    }

    vector<vector<int>> buildMatrix(int k, vector<vector<int>>& rowConditions, vector<vector<int>>& colConditions) {
        // Step 1: Get row and column topo orders
        vector<int> rowOrder = topoSort(k, rowConditions);
        vector<int> colOrder = topoSort(k, colConditions);

        if (rowOrder.empty() || colOrder.empty())
            return {};

        // Step 2: Map number to position
        unordered_map<int, int> rowPos, colPos;

        for (int i = 0; i < k; i++) {
            rowPos[rowOrder[i]] = i;
            colPos[colOrder[i]] = i;
        }

        // Step 3: Build matrix
        vector<vector<int>> ans(k, vector<int>(k, 0));

        for (int num = 1; num <= k; num++) {
            ans[rowPos[num]][colPos[num]] = num;
        }

        return ans;
    }
};

int main() {
    int k = 3;
    vector<vector<int>> rowConditions = {{2, 1}, {1, 3}};
    vector<vector<int>> colConditions = {{3, 1}, {2, 3}};

    Solution sol;
    vector<vector<int>> ans = sol.buildMatrix(k, rowConditions, colConditions);

    for (const auto& i : ans) {
        for (const auto& j : i) {
            cout << j << " ";
        }
        cout << endl;
    }
    return 0;
}