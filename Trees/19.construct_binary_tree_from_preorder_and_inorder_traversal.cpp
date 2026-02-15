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

void printTree(TreeNode* root) {
    if (root == nullptr) {
        cout << "null ";
        return;
    }
    cout << root->val << " ";
    printTree(root->left);
    printTree(root->right);
}

// Optimised Approach using DFS Traversal - Time Complexity : O(N), Space Complexity: O(N)
class Solution {
   private:
    unordered_map<int, int> inorderMap;
    int preorderIndex = 0;

    TreeNode* dfs(vector<int>& preorder, int l, int r) {
        if (l > r) return nullptr;

        // Root value from preorder
        int rootVal = preorder[preorderIndex++];
        TreeNode* root = new TreeNode(rootVal);

        // Find root index in inorder
        // In brute force approach you just search mid in the inorder vector in every recursion call, so time can go upto O(N^2), that's why using space we can reduce the time complexity
        int mid = inorderMap[rootVal];

        // Build left subtree
        root->left = dfs(preorder, l, mid - 1);

        // Build right subtree
        root->right = dfs(preorder, mid + 1, r);

        return root;
    }

   public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for (int i = 0; i < inorder.size(); i++) {
            inorderMap[inorder[i]] = i;
        }
        return dfs(preorder, 0, inorder.size() - 1);
    }
};

int main() {
    vector<int> preorder = {1, 2, 3, 4};
    vector<int> inorder = {2, 1, 3, 4};

    Solution sol;
    TreeNode* root = sol.buildTree(preorder, inorder);
    printTree(root);
    cout << endl;

    return 0;
}