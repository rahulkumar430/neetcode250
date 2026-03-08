#include <bits/stdc++.h>
using namespace std;

class Node {
   public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};

// DFS Approach - Time Complexity: O(N + E), Space Complexity: O(N)
// class Solution {
//    public:
//     // Map to store original node -> cloned node
//     unordered_map<Node*, Node*> mp;

//     Node* dfs(Node* node) {
//         if (!node) return nullptr;

//         // If node already cloned, return it
//         if (mp.count(node))
//             return mp[node];

//         // Create clone
//         Node* clone = new Node(node->val);
//         mp[node] = clone;

//         // Clone neighbors
//         for (Node* neigh : node->neighbors) {
//             clone->neighbors.push_back(dfs(neigh));
//         }

//         return clone;
//     }
//     Node* cloneGraph(Node* node) {
//         return dfs(node);
//     }
// };

// BFS Approach - Time Complexity: O(N + E), Space Complexity: O(N)
class Solution {
   public:
    Node* cloneGraph(Node* node) {
        if (!node) return nullptr;

        unordered_map<Node*, Node*> mp;  // original -> clone
        queue<Node*> q;

        // Create clone of first node
        mp[node] = new Node(node->val);
        q.push(node);

        while (!q.empty()) {
            Node* curr = q.front();
            q.pop();

            for (Node* neigh : curr->neighbors) {
                // If neighbor not cloned yet
                if (!mp.count(neigh)) {
                    mp[neigh] = new Node(neigh->val);
                    q.push(neigh);
                }

                // Add cloned neighbor to current cloned node
                mp[curr]->neighbors.push_back(mp[neigh]);
            }
        }

        return mp[node];
    }
};

// Build graph from adjacency list
Node* buildGraph(vector<vector<int>>& adjList) {
    if (adjList.empty()) return nullptr;

    int n = adjList.size();
    vector<Node*> nodes;

    for (int i = 0; i < n; i++)
        nodes.push_back(new Node(i + 1));

    for (int i = 0; i < n; i++) {
        for (int neigh : adjList[i]) {
            nodes[i]->neighbors.push_back(nodes[neigh - 1]);
        }
    }

    return nodes[0];
}

// Print graph adjacency list
void printGraph(Node* node) {
    unordered_set<Node*> visited;
    queue<Node*> q;

    q.push(node);
    visited.insert(node);

    while (!q.empty()) {
        Node* curr = q.front();
        q.pop();

        cout << curr->val << " -> ";

        for (Node* neigh : curr->neighbors) {
            cout << neigh->val << " ";
            if (!visited.count(neigh)) {
                visited.insert(neigh);
                q.push(neigh);
            }
        }
        cout << endl;
    }
}

int main() {
    vector<vector<int>> adjList = {{2}, {1, 3}, {2}};

    Node* graph = buildGraph(adjList);
    printGraph(graph);

    Solution sol;
    Node* cloned = sol.cloneGraph(graph);

    printGraph(cloned);

    return 0;
}
