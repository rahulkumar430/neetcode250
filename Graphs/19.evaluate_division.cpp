#include <bits/stdc++.h>
using namespace std;

// DFS Approach - Time Complexity: O(Q * (V + E)), Space Complexity: O(V + E)
// E = number of equations, V = number of unique variables, Q = number of queries
// class Solution {
//    public:
//     double dfs(const string& current, const string& target, unordered_map<string, vector<pair<string, double>>>& graph, unordered_set<string>& visited) {
//         if (current == target) return 1.0;  // Found the target variable
//         visited.insert(current);
//         for (const auto& neighbor : graph[current]) {
//             const string& next = neighbor.first;
//             double weight = neighbor.second;
//             // If the neighbor has not been visited, continue DFS
//             if (!visited.count(next)) {
//                 double result = dfs(next, target, graph, visited);
//                 if (result != -1.0) {
//                     return weight * result;  // Multiply the weight with the result from the neighbor
//                 }
//             }
//         }
//         return -1.0;  // No path found from current to target
//     }

//     vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values,
//                                 vector<vector<string>>& queries) {
//         // Graph structure: variable -> list of (neighbor, weight)
//         unordered_map<string, vector<pair<string, double>>> graph;
//         // Build the graph from equations and values
//         for (int i = 0; i < equations.size(); i++) {
//             string a = equations[i][0];
//             string b = equations[i][1];
//             double val = values[i];
//             graph[a].push_back({b, val});        // a -> b with weight val
//             graph[b].push_back({a, 1.0 / val});  // b -> a with weight 1/val
//         }
//         vector<double> results;
//         // Process each query using DFS
//         for (const auto& query : queries) {
//             string start = query[0];
//             string end = query[1];

//             // If either variable is not in the graph, return -1.0
//             if (!graph.count(start) || !graph.count(end)) {
//                 results.push_back(-1.0);
//             }
//             // If both variables are the same, the result is 1.0
//             else if (start == end) {
//                 results.push_back(1.0);
//                 continue;
//             } else {
//                 unordered_set<string> visited;
//                 double result = dfs(start, end, graph, visited);
//                 results.push_back(result);
//             }
//         }
//         return results;
//     }
// };

// BFS Approach : Time Complexity: O(Q * (V + E)), Space Complexity: O(V + E)
// E = number of equations, V = number of unique variables, Q = number of queries
// class Solution {
//    public:
//     vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
//         // Graph: variable -> list of (neighbor, weight)
//         unordered_map<string, vector<pair<string, double>>> graph;

//         // Build the graph
//         for (int i = 0; i < equations.size(); i++) {
//             string a = equations[i][0];
//             string b = equations[i][1];
//             double val = values[i];

//             // a / b = val
//             graph[a].push_back({b, val});

//             // reverse relation
//             graph[b].push_back({a, 1.0 / val});
//         }

//         vector<double> result;

//         // Process each query
//         for (auto& query : queries) {
//             string start = query[0];
//             string end = query[1];

//             // If variable doesn't exist
//             if (!graph.count(start) || !graph.count(end)) {
//                 result.push_back(-1.0);
//                 continue;
//             }

//             // If both variables are same
//             if (start == end) {
//                 result.push_back(1.0);
//                 continue;
//             }

//             // BFS queue: {current node, accumulated value}
//             queue<pair<string, double>> q;

//             unordered_set<string> visited;

//             q.push({start, 1.0});
//             visited.insert(start);

//             double ans = -1.0;

//             while (!q.empty()) {
//                 auto [node, value] = q.front();
//                 q.pop();

//                 // If target reached
//                 if (node == end) {
//                     ans = value;
//                     break;
//                 }

//                 // Traverse neighbors
//                 for (auto& neigh : graph[node]) {
//                     string next = neigh.first;
//                     double weight = neigh.second;

//                     if (!visited.count(next)) {
//                         visited.insert(next);

//                         // multiply accumulated value
//                         q.push({next, value * weight});
//                     }
//                 }
//             }

//             result.push_back(ans);
//         }

//         return result;
//     }
// };

// Union-Find with weights : Time Complexity: O((E + Q) * α(N)), Space Complexity: O(N)
// E = number of equations, Q = number of queries, N = number of unique variables
// class Solution {
//    public:
//     // Find parent with path compression
//     string find(string x, unordered_map<string, string>& parent, unordered_map<string, double>& weight) {
//         // If x is not its own parent
//         if (parent[x] != x) {
//             string origParent = parent[x];

//             // Find ultimate parent
//             parent[x] = find(parent[x], parent, weight);

//             // Adjust weight during path compression
//             weight[x] *= weight[origParent];
//         }

//         return parent[x];
//     }

//     vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
//         unordered_map<string, string> parent;
//         unordered_map<string, double> weight;

//         // Initialize parents as themselves and weights as 1.0
//         for (auto& eq : equations) {
//             string a = eq[0];
//             string b = eq[1];

//             if (!parent.count(a)) {
//                 parent[a] = a;
//                 weight[a] = 1.0;
//             }

//             if (!parent.count(b)) {
//                 parent[b] = b;
//                 weight[b] = 1.0;
//             }
//         }

//         // Perform union operations
//         for (int i = 0; i < equations.size(); i++) {
//             string a = equations[i][0];
//             string b = equations[i][1];

//             string rootA = find(a, parent, weight);
//             string rootB = find(b, parent, weight);

//             if (rootA == rootB)
//                 continue;  // Already connected

//             // Connect rootA under rootB
//             parent[rootA] = rootB;
//             // We know weight[x] = x / parent[x] = x / root X;
//             // So, weight[a] = a / rootA and weight[b] = b / rootB
//             // rootA = a / weight[a] & rootB = b / weight[b]
//             // We want to maintain the equation: a / b = values[i]
//             // weight[rootA] = rootA / rootB = (a / weight[a]) / (b / weight[b]) = (a / b) * (weight[b] / weight[a]) = values[i] * (weight[b] / weight[a])
//             weight[rootA] = weight[b] * values[i] / weight[a];
//         }

//         vector<double> result;

//         // Process queries
//         for (auto& q : queries) {
//             string a = q[0];
//             string b = q[1];

//             // variable doesn't exist
//             if (!parent.count(a) || !parent.count(b)) {
//                 result.push_back(-1.0);
//                 continue;
//             }

//             string rootA = find(a, parent, weight);
//             string rootB = find(b, parent, weight);

//             // if not connected
//             if (rootA != rootB) {
//                 result.push_back(-1.0);
//             } else {
//                 // ratio = a / b = weight[a] * rootA / (weight[b] * rootB)
//                 // As rootA = rootB, this simplifies to a / b = weight[a] / weight[b]
//                 result.push_back(weight[a] / weight[b]);
//             }
//         }

//         return result;
//     }
// };

// Floyd–Warshall approach(transitive closure) - For every intermediate variable k, update: i → j = (i → k) * (k → j)
// Time Complexity: O(V^3), Space Complexity: O(V^2), V = number of unique variables
class Solution {
   public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        // Graph storing ratios between variables
        unordered_map<string, unordered_map<string, double>> graph;

        // Step 1: Build direct relations
        for (int i = 0; i < equations.size(); i++) {
            string a = equations[i][0];
            string b = equations[i][1];
            double val = values[i];

            graph[a][b] = val;        // a / b = val
            graph[b][a] = 1.0 / val;  // b / a = 1/val
        }

        // Step 2: Self ratio
        for (auto& node : graph) {
            graph[node.first][node.first] = 1.0;
        }

        // Step 3: Floyd–Warshall
        for (auto& k : graph) {
            for (auto& i : graph) {
                for (auto& j : graph) {
                    string mid = k.first;
                    string start = i.first;
                    string end = j.first;

                    // If start → mid and mid → end exist
                    if (graph[start].count(mid) && graph[mid].count(end)) {
                        graph[start][end] = graph[start][mid] * graph[mid][end];
                    }
                }
            }
        }

        // Step 4: Answer queries
        vector<double> result;

        for (auto& q : queries) {
            string a = q[0];
            string b = q[1];

            if (graph.count(a) && graph[a].count(b))
                result.push_back(graph[a][b]);
            else
                result.push_back(-1.0);
        }

        return result;
    }
};

int main() {
    vector<vector<string>> equations = {{"a", "b"}, {"b", "c"}, {"ab", "bc"}};
    vector<double> values = {4.0, 1.0, 3.25};
    vector<vector<string>> queries = {{"a", "c"}, {"b", "a"}, {"c", "c"}, {"ab", "a"}, {"d", "d"}};

    Solution sol;
    vector<double> ans = sol.calcEquation(equations, values, queries);
    for (const auto& x : ans) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}