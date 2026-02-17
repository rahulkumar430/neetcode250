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

// Recursive DFS Solution - Time Complexity : O(N), Space Complexity : O(H)
class Solution {
   private:
    TreeNode* dfs(TreeNode* root, int target) {
        if (!root) return nullptr;

        // First process children
        root->left = dfs(root->left, target);
        root->right = dfs(root->right, target);

        // Now check if current node became a leaf
        if (!root->left && !root->right && root->val == target) {
            delete root;
            return nullptr;
        }

        return root;  // Important!
    }

   public:
    TreeNode* removeLeafNodes(TreeNode* root, int target) {
        return dfs(root, target);
    }
};

int main() {
    vector<int> input = {1, 2, 3, 5, 2, 2, 5};
    int target = 2;

    TreeNode* root = buildTree(input);
    printTree(root);
    cout << endl;

    Solution sol;
    TreeNode* ans = sol.removeLeafNodes(root, target);
    printTree(ans);

    return 0;
}