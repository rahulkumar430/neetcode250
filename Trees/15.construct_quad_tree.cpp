#include <bits/stdc++.h>
using namespace std;

// Definition for a QuadTree node.
class Node {
   public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;

    Node() {
        val = false;
        isLeaf = false;
        topLeft = topRight = bottomLeft = bottomRight = nullptr;
    }

    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = topRight = bottomLeft = bottomRight = nullptr;
    }

    Node(bool _val, bool _isLeaf,
         Node* _topLeft, Node* _topRight,
         Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};

// Helper function to print QuadTree (Level order style)
void printQuadTree(Node* root) {
    if (!root) {
        cout << "[]\n";
        return;
    }

    queue<Node*> q;
    q.push(root);

    cout << "[";

    while (!q.empty()) {
        Node* node = q.front();
        q.pop();

        if (!node) {
            cout << "null,";
            continue;
        }

        // Print as [isLeaf, val]
        cout << "[" << node->isLeaf << "," << node->val << "],";

        // If not leaf, push children
        if (!node->isLeaf) {
            q.push(node->topLeft);
            q.push(node->topRight);
            q.push(node->bottomLeft);
            q.push(node->bottomRight);
        } else {
            // For leaf nodes, push null placeholders
            q.push(nullptr);
            q.push(nullptr);
            q.push(nullptr);
            q.push(nullptr);
        }
    }

    cout << "]\n";
}

/*
Time Complexity: O(N^2 log N)
    - At each recursive level, we scan the current subgrid (n x n).
    - The grid is divided into 4 parts recursively (log N levels).
    - Total work across all levels ≈ O(N^2 log N).

Space Complexity: O(log N)
    - Recursion depth is log N (grid keeps dividing by 2).
    - Does not count space used for output QuadTree nodes.
*/
// class Solution {
//    private:
//     /*
//         dfs(grid, n, r, c)

//         n → size of current subgrid
//         r → starting row index
//         c → starting column index

//         We check whether the n x n subgrid starting at (r, c)
//         contains all same values.
//     */
//     Node* dfs(vector<vector<int>>& grid, int n, int r, int c) {
//         bool allSame = true;

//         // Check if all values in current n x n region are equal
//         for (int i = 0; i < n && allSame; ++i) {
//             for (int j = 0; j < n; ++j) {
//                 if (grid[r][c] != grid[r + i][c + j]) {
//                     allSame = false;
//                     break;
//                 }
//             }
//         }

//         // If all values are same → create a leaf node
//         if (allSame) {
//             return new Node(grid[r][c] == 1, true);
//         }

//         // Otherwise divide grid into 4 equal quadrants
//         int mid = n / 2;

//         Node* topLeft = dfs(grid, mid, r, c);
//         Node* topRight = dfs(grid, mid, r, c + mid);
//         Node* bottomLeft = dfs(grid, mid, r + mid, c);
//         Node* bottomRight = dfs(grid, mid, r + mid, c + mid);

//         // Create internal node with 4 children
//         return new Node(false, false,
//                         topLeft, topRight,
//                         bottomLeft, bottomRight);
//     }

//    public:
//     // Entry function: start DFS from full grid
//     Node* construct(vector<vector<int>>& grid) {
//         return dfs(grid, grid.size(), 0, 0);
//     }
// };

// Optimised recursion - Time Complexity: O(N^2), Space Complexity:O(log N)
class Solution {
   private:
    /*
        dfs(r, c, size)

        r, c  → starting coordinates of subgrid
        size  → length of subgrid

        Strategy:
        1. If size == 1 → directly create leaf node
        2. Recursively construct 4 quadrants
        3. If all 4 children are leaf and have same value → merge into single leaf
        4. Otherwise return internal node
    */
    Node* dfs(vector<vector<int>>& grid, int r, int c, int size) {
        // Base case: single cell
        if (size == 1) {
            return new Node(grid[r][c] == 1, true);
        }

        int half = size / 2;

        // Recursively construct four quadrants
        Node* topLeft = dfs(grid, r, c, half);
        Node* topRight = dfs(grid, r, c + half, half);
        Node* bottomLeft = dfs(grid, r + half, c, half);
        Node* bottomRight = dfs(grid, r + half, c + half, half);

        /*
            After building children:
            If all 4 are leaf AND have same value,
            we can merge them into one leaf node.
        */
        if (topLeft->isLeaf && topRight->isLeaf &&
            bottomLeft->isLeaf && bottomRight->isLeaf &&
            topLeft->val == topRight->val &&
            topLeft->val == bottomLeft->val &&
            topLeft->val == bottomRight->val) {
            return new Node(topLeft->val, true);
        }

        // Otherwise create internal node
        return new Node(false, false,
                        topLeft, topRight,
                        bottomLeft, bottomRight);
    }

   public:
    Node* construct(vector<vector<int>>& grid) {
        return dfs(grid, 0, 0, grid.size());
    }
};

int main() {
    vector<vector<int>> grid = {{1, 1, 1, 1, 0, 0, 0, 0}, {1, 1, 1, 1, 0, 0, 0, 0}, {1, 1, 1, 1, 1, 1, 1, 1}, {1, 1, 1, 1, 1, 1, 1, 1}, {1, 1, 1, 1, 0, 0, 0, 0}, {1, 1, 1, 1, 0, 0, 0, 0}, {1, 1, 1, 1, 0, 0, 0, 0}, {1, 1, 1, 1, 0, 0, 0, 0}};

    Solution sol;
    Node* root = sol.construct(grid);

    printQuadTree(root);
    cout << endl;

    return 0;
}
