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

// BFS Approach - Time Complexity : O(N), Space Complexity: O(H)
// class Solution {
//    public:
//     bool isValidBST(TreeNode* root) {
//         if (!root) return true;

//         // Queue stores:
//         // (node pointer, minAllowed, maxAllowed)
//         queue<tuple<TreeNode*, int, int>> q;
//         q.push({root, INT_MIN, INT_MAX});

//         while (!q.empty()) {
//             auto [node, minVal, maxVal] = q.front();
//             q.pop();

//             // Current node must lie strictly within (minVal, maxVal)
//             if (node->val <= minVal || node->val >= maxVal)
//                 return false;

//             // Left subtree:
//             // values must be < node->val
//             if (node->left)
//                 q.push({node->left, minVal, node->val});

//             // Right subtree:
//             // values must be > node->val
//             if (node->right)
//                 q.push({node->right, node->val, maxVal});
//         }

//         return true;
//     }
// };

// DFS Recursion Approach - Time Complexity : O(N), Space Complexity: O(H)
class Solution {
   private:
    // Helper function with allowed value range
    bool dfs(TreeNode* node, int minVal, int maxVal) {
        if (!node) return true;

        // Current node must lie strictly within (minVal, maxVal)
        if (node->val <= minVal || node->val >= maxVal)
            return false;

        // Left subtree: values must be < node->val
        // Right subtree: values must be > node->val
        return dfs(node->left, minVal, node->val) &&
               dfs(node->right, node->val, maxVal);
    }

   public:
    bool isValidBST(TreeNode* root) {
        return dfs(root, INT_MIN, INT_MAX);
    }
};

int main() {
    vector<int> input = {1, 2, 3};

    TreeNode* root = buildTree(input);
    printTree(root);
    cout << endl;

    Solution sol;
    cout << (sol.isValidBST(root) ? "true" : "false") << endl;

    return 0;
}