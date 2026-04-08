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
    if (arr.empty()) return nullptr;

    TreeNode* root = new TreeNode(arr[0]);
    queue<TreeNode*> q;
    q.push(root);

    int i = 1;

    while (!q.empty() && i < arr.size()) {
        TreeNode* curr = q.front();
        q.pop();

        if (i < arr.size()) {
            curr->left = new TreeNode(arr[i++]);
            q.push(curr->left);
        }
        if (i < arr.size()) {
            curr->right = new TreeNode(arr[i++]);
            q.push(curr->right);
        }
    }
    return root;
}

/* print level order INCLUDING nulls */
void printLevelOrder(TreeNode* root) {
    queue<TreeNode*> q;
    q.push(root);

    vector<string> out;

    while (!q.empty()) {
        TreeNode* node = q.front();
        q.pop();

        if (!node) {
            out.push_back("null");
            continue;
        }

        out.push_back(to_string(node->val));

        // push both children to preserve structure
        q.push(node->left);
        q.push(node->right);
    }

    // remove trailing nulls
    while (!out.empty() && out.back() == "null") out.pop_back();

    cout << "[";
    for (int i = 0; i < out.size(); i++) {
        if (i) cout << ",";
        cout << out[i];
    }
    cout << "]";
}

class Solution {
   public:
    // Breadth First Search : Time Complexity: O(N), Space Complexity: O(W), W = maximum width of the tree
    TreeNode* invertTree(TreeNode* root) {
        if (!root) return root;

        queue<TreeNode*> q;
        q.push(root);

        // Process nodes level by level using BFS
        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();

            // Swap left and right children to invert the tree structure
            swap(node->left, node->right);

            // Add children to queue for processing
            if (node->left) q.push(node->left);
            if (node->right) q.push(node->right);
        }

        return root;
    }

    // DFS Recursive approach : Time Complexity: O(N), Space Complexity: O(H), H = height of the tree
    // TreeNode* invertTree(TreeNode* root) {
    //     if (!root) return root;

    //     // Recursively invert left and right subtrees
    //     TreeNode* left = invertTree(root->left);
    //     TreeNode* right = invertTree(root->right);

    //     // Swap children
    //     root->left = right;
    //     root->right = left;

    //     return root;
    // }
};

int main() {
    vector<int> input = {1, 2};

    TreeNode* root = buildTree(input);

    Solution sol;
    TreeNode* ans = sol.invertTree(root);

    printLevelOrder(ans);

    return 0;
}
