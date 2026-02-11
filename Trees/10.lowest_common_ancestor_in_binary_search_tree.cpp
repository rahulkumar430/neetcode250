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

// Helper to find pointer to node with given value
TreeNode* findNode(TreeNode* root, int val) {
    if (!root) return nullptr;
    if (root->val == val) return root;

    TreeNode* left = findNode(root->left, val);
    if (left) return left;

    return findNode(root->right, val);
}

class Solution {
   public:
    // Recursion Method - Time Complexity: O(H), Space Complexity : O(H)(recursion stack)
    // TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    //     // Base case (should not happen if p and q exist in tree)
    //     if (!root) return nullptr;

    //     // If both p and q are smaller than root → LCA lies in left subtree
    //     if (p->val < root->val && q->val < root->val)
    //         return lowestCommonAncestor(root->left, p, q);

    //     // If both p and q are greater than root → LCA lies in right subtree
    //     if (p->val > root->val && q->val > root->val)
    //         return lowestCommonAncestor(root->right, p, q);

    //     /*
    //        If one is on left and one is on right,
    //        OR one of them equals root,
    //        then current root is the LCA
    //     */
    //     return root;
    // }

    // Iterative Method - Time Complexity: O(H), Space Complexity : O(1)
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        while (root) {
            // Both nodes are smaller → go left
            if (p->val < root->val && q->val < root->val) {
                root = root->left;
            }

            // Both nodes are greater → go right
            else if (p->val > root->val && q->val > root->val) {
                root = root->right;
            }

            // Split point found
            else {
                return root;
            }
        }

        return nullptr;
    }
};

int main() {
    vector<int> input = {5, 3, 8, 1, 4, 7, 9, INT_MIN, 2};
    int pVal = 3, qVal = 8;

    TreeNode* root = buildTree(input);

    printTree(root);
    cout << endl;

    // Convert values to actual node pointers
    TreeNode* p = findNode(root, pVal);
    TreeNode* q = findNode(root, qVal);

    Solution sol;
    TreeNode* lca = sol.lowestCommonAncestor(root, p, q);

    cout << lca->val << endl;

    return 0;
}