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
    // Using DFS recursion
    // Time Complexity: O(N), Space Complexity: O(H), recursion stack
    bool isSameTree(TreeNode* p, TreeNode* q) {
        // Case 1: Both nodes are null → trees match at this branch
        if (p == nullptr && q == nullptr)
            return true;

        // Case 2: One is null and the other is not → not same
        if (p == nullptr || q == nullptr)
            return false;

        // Case 3: Values differ → not same
        if (p->val != q->val)
            return false;

        // Recursively check left and right subtrees
        return isSameTree(p->left, q->left) &&
               isSameTree(p->right, q->right);
    }

    // Another way of writting the same solution above
    // bool isSameTree(TreeNode* p, TreeNode* q) {
    //     // If both nodes are null → trees match at this branch
    //     if (!p && !q)
    //         return true;

    //     /*
    //        If both nodes exist AND values match,
    //        recursively check left and right subtrees
    //     */
    //     if (p && q && p->val == q->val) {
    //         return isSameTree(p->left, q->left) &&
    //                isSameTree(p->right, q->right);
    //     }

    //     // If one is null OR values differ → not same
    //     return false;
    // }
};

int main() {
    vector<int> v1 = {4, 7};
    vector<int> v2 = {4, INT_MIN, 7};

    TreeNode* p = buildTree(v1);
    printTree(p);
    cout << endl;

    TreeNode* q = buildTree(v2);
    printTree(q);
    cout << endl;

    Solution sol;
    cout << (sol.isSameTree(p, q) ? "true" : "false") << endl;

    return 0;
}
