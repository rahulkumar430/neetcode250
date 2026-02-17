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

// DFS Postorder Approach: Time Complexity : O(N), Space Complexity : O(H)
class Solution {
   private:
    int maxSum = INT_MIN;  // Stores global maximum path sum

    int dfs(TreeNode* node) {
        if (!node) return 0;

        // Compute max gain from left and right subtree
        // If negative, ignore (take 0 instead)
        int leftGain = max(0, dfs(node->left));
        int rightGain = max(0, dfs(node->right));

        // Path passing through current node
        int currentPath = node->val + leftGain + rightGain;

        // Update global maximum
        maxSum = max(maxSum, currentPath);

        // Return max gain if continuing upward
        return node->val + max(leftGain, rightGain);
    }

   public:
    int maxPathSum(TreeNode* root) {
        dfs(root);
        return maxSum;
    }
};

int main() {
    vector<int> input = {-15, 10, 20, INT_MIN, INT_MIN, 15, 5, -5};

    TreeNode* root = buildTree(input);
    printTree(root);
    cout << endl;

    Solution sol;
    cout << sol.maxPathSum(root) << endl;

    return 0;
}