#include <bits/stdc++.h>
using namespace std;

// DFS Approach using memoization to check if one course is a prerequisite of another
// Time Complexity: Time = O(V * (V + E)) ≈ O(V^3)
// Space Complexity: O(V^2), V = number of courses(nodes), E = number of prerequisites(edges)
// class Solution {
//    public:
//     bool dfs(int src, int target, vector<vector<int>>& graph, vector<vector<int>>& memo) {
//         // Return memoized result if already computed
//         if (memo[src][target] != -1)
//             return memo[src][target];

//         // Explore all neighbors of current node
//         for (int next : graph[src]) {
//             // If we found target directly or through further exploration
//             if (next == target || dfs(next, target, graph, memo))
//                 return memo[src][target] = true;  // Memoize and return true
//         }

//         // No path found from src to target
//         return memo[src][target] = false;  // Memoize and return false
//     }

//     vector<bool> checkIfPrerequisite(int n, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
//         vector<vector<int>> graph(n);

//         // Adjacency list: graph[a] contains courses that depend on 'a'
//         for (auto& p : prerequisites)
//             graph[p[0]].push_back(p[1]);

//         // Memoization table: memo[i][j] = whether i is prerequisite of j
//         vector<vector<int>> memo(n, vector<int>(n, -1));

//         vector<bool> ans;

//         // Process each query
//         for (auto& q : queries)
//             ans.push_back(dfs(q[0], q[1], graph, memo));

//         return ans;
//     }
// };

// Topological Sort using BFS (Kahn’s Algorithm) to detect cycle in directed graph
// Time Complexity: Time = O(V * (V + E)) ≈ O(V^3)
// Space Complexity: O(V^2), V = number of courses(nodes), E = number of prerequisites(edges)
class Solution {
   public:
    vector<bool> checkIfPrerequisite(int n, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        vector<vector<int>> graph(n);  // adjacency list : graph[a] contains courses that depend on 'a'
        vector<int> indegree(n, 0);    // indegree[i] = number of prerequisites for course i

        // prereq[i][j] = true if i is prerequisite of j
        vector<vector<bool>> prereq(n, vector<bool>(n, false));

        // Build graph and indegree array
        for (auto& p : prerequisites) {
            int prerequisite = p[0], course = p[1];
            graph[prerequisite].push_back(course);
            indegree[course]++;
            prereq[prerequisite][course] = true;  // direct prerequisite
        }

        queue<int> q;

        // Push all courses with no prerequisites into the queue to start with
        for (int i = 0; i < n; i++) {
            if (indegree[i] == 0)
                q.push(i);
        }

        // Topological traversal
        while (!q.empty()) {
            int node = q.front();
            q.pop();

            for (int dependentCourse : graph[node]) {
                // Propagate all prerequisites of 'node' to its dependent courses
                for (int i = 0; i < n; i++) {
                    // If 'i' is a prerequisite of 'node', then 'i' is also a prerequisite of 'dependentCourse'
                    if (prereq[i][node])
                        prereq[i][dependentCourse] = true;
                }

                indegree[dependentCourse]--;  // Reduce indegree of dependent courses

                // If no more prerequisites remain, add to queue
                if (indegree[dependentCourse] == 0)
                    q.push(dependentCourse);
            }
        }

        vector<bool> ans;

        // Answer queries based on the prereq matrix
        for (auto& q : queries)
            ans.push_back(prereq[q[0]][q[1]]);

        return ans;
    }
};

int main() {
    int numCourses = 4;
    vector<vector<int>> prerequisites = {{1, 0}, {2, 1}, {3, 2}};
    vector<vector<int>> queries = {{1, 3}, {0, 3}, {1, 2}};

    Solution sol;
    vector<bool> ans = sol.checkIfPrerequisite(numCourses, prerequisites, queries);

    for (bool x : ans) {
        cout << (x ? "true" : "false") << " ";
    }
    cout << endl;

    return 0;
}