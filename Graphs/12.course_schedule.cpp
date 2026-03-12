#include <bits/stdc++.h>
using namespace std;

// DFS Approach to detect cycle in directed graph
//  Time Complexity: O(V + E), Space Complexity: O(V + E), V = number of courses(nodes), E = number of prerequisites(edges)
// class Solution {
//    public:
//     bool dfs(int node, vector<vector<int>>& graph, vector<int>& state) {
//         // If node is currently being visited → cycle detected
//         if (state[node] == 1)
//             return false;

//         // Already processed safely
//         if (state[node] == 2)
//             return true;

//         state[node] = 1;  // mark as visiting

//         for (int neigh : graph[node]) {
//             if (!dfs(neigh, graph, state))
//                 return false;
//         }

//         state[node] = 2;  // mark as fully processed
//         return true;
//     }

//     bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
//         vector<vector<int>> graph(numCourses);

//         // Build adjacency list, you can also take a map instead of vector of vectors
//         for (auto& p : prerequisites) {
//             graph[p[1]].push_back(p[0]);
//         }

//         vector<int> state(numCourses, 0);

//         for (int i = 0; i < numCourses; i++) {
//             if (!dfs(i, graph, state))
//                 return false;
//         }

//         return true;
//     }
// };

// Topological Sort using BFS (Kahn’s Algorithm) to detect cycle in directed graph
//  Time Complexity: O(V + E), Space Complexity: O(V + E), V = number of courses(nodes), E = number of prerequisites(edges)
class Solution {
   public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        // adjacency list: graph[a] contains courses dependent on 'a'
        vector<vector<int>> graph(numCourses);

        // indegree[i] = number of prerequisites for course i
        vector<int> indegree(numCourses, 0);

        // Build graph and indegree array
        for (auto& p : prerequisites) {
            int course = p[0];
            int prereq = p[1];

            graph[prereq].push_back(course);  // prereq → course
            indegree[course]++;               // course has one more prerequisite
        }

        queue<int> q;

        // Push all courses with no prerequisites
        for (int i = 0; i < numCourses; i++) {
            if (indegree[i] == 0)
                q.push(i);
        }

        int coursesTaken = 0;

        // Process courses in BFS order
        while (!q.empty()) {
            int curr = q.front();
            q.pop();

            coursesTaken++;  // we can take this course

            // Reduce indegree of dependent courses
            for (int next : graph[curr]) {
                indegree[next]--;

                // If no more prerequisites remain, add to queue
                if (indegree[next] == 0)
                    q.push(next);
            }
        }

        // If we processed all courses → no cycle
        return coursesTaken == numCourses;
    }
};

int main() {
    vector<vector<int>> prerequisites = {{0, 1}, {1, 0}};
    int numCourses = 2;

    Solution sol;
    cout << (sol.canFinish(numCourses, prerequisites) ? "true" : "false") << endl;

    return 0;
}