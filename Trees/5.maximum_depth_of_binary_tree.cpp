#include <bits/stdc++.h>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// Helper function to build a binary tree from level-order vector
TreeNode* buildTree(const vector<int>& arr) {
    if (arr.empty() || arr[0] == INT_MIN) return nullptr;

    TreeNode* root = new TreeNode(arr[0]);
    queue<TreeNode*> q;
    q.push(root);

    int i = 1;

    while (!q.empty() && i < arr.size()) {
        TreeNode* curr = q.front();
        q.pop();

        if (i < arr.size() && arr[i] != INT_MIN) {
            curr->left = new TreeNode(arr[i]);
            q.push(curr->left);
        }
        i++;

        if (i < arr.size() && arr[i] != INT_MIN) {
            curr->right = new TreeNode(arr[i]);
            q.push(curr->right);
        }
        i++;
    }
    return root;
}

void printTree(TreeNode* root) {
    if (root == nullptr) {
        cout << "null ";
        return;
    }
    cout << root->val << " ";
    printTree(root->left);
    printTree(root->right);
}

class Solution {
   public:
    // Using DFS Recursion Method
    // Time Complexity: O(N), Space Complexity: O(H) - recursion stack depth, where H is the height
    int maxDepth(TreeNode* root) {
        if (root == nullptr) return 0;
        return 1 + max(maxDepth(root->left), maxDepth(root->right));
    }

    // Using Iterative DFS with Stack Method
    // Time Complexity: O(N), Space Complexity: O(H) - where H is the height
    // int maxDepth(TreeNode* root) {
    //     stack<pair<TreeNode*, int>> stack;
    //     stack.push({root, 1});
    //     int res = 0;

    //     while (!stack.empty()) {
    //         // Get the top node and its current depth
    //         pair<TreeNode*, int> current = stack.top();
    //         stack.pop();
    //         TreeNode* node = current.first;
    //         int depth = current.second;

    //         // Process node if it exists
    //         if (node != nullptr) {
    //             // Update maximum depth found
    //             res = max(res, depth);
    //             // Push left child with incremented depth
    //             stack.push({node->left, depth + 1});
    //             // Push right child with incremented depth
    //             stack.push({node->right, depth + 1});
    //         }
    //     }
    //     return res;
    // }

    // Using Level-Order Traversal (BFS) Method
    // Time Complexity: O(N), Space Complexity: O(W) - where W is max width of tree
    // int maxDepth(TreeNode* root) {
    //     queue<TreeNode*> q;
    //     if (root != nullptr) {
    //         q.push(root);
    //     }

    //     int level = 0;
    //     while (!q.empty()) {
    //         int size = q.size();
    //         // Process all nodes at current level
    //         for (int i = 0; i < size; i++) {
    //             TreeNode* node = q.front();
    //             q.pop();
    //             // Add children to queue for next level
    //             if (node->left != nullptr) {
    //                 q.push(node->left);
    //             }
    //             if (node->right != nullptr) {
    //                 q.push(node->right);
    //             }
    //         }
    //         level++;
    //     }
    //     return level;
    // }
};

int main() {
    vector<int> input = {1, 2, 3, INT_MIN, INT_MIN, 4};

    TreeNode* root = buildTree(input);
    printTree(root);
    cout << endl;

    Solution sol;
    cout << sol.maxDepth(root) << endl;

    return 0;
}
