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
   private:
    int maxDiameter = 0;

    // This function returns height of subtree
    int height(TreeNode* node) {
        if (node == nullptr)
            return 0;

        // Recursively get left and right subtree heights
        int leftHeight = height(node->left);
        int rightHeight = height(node->right);

        // Diameter at this node = leftHeight + rightHeight
        // (number of edges between deepest left and right nodes)
        maxDiameter = max(maxDiameter, leftHeight + rightHeight);

        // Return height of current node
        return 1 + max(leftHeight, rightHeight);
    }

   public:
    // Using recursion DFS method
    // Time Complexity: O(N), Space Complexity: O(H), H stands for the height of the tree
    int diameterOfBinaryTree(TreeNode* root) {
        height(root);  // this updates maxDiameter
        return maxDiameter;
    }
};

int main() {
    vector<int> input = {1, INT_MIN, 2, 3, 4, 5};

    TreeNode* root = buildTree(input);
    printTree(root);
    cout << endl;

    Solution sol;
    cout << sol.diameterOfBinaryTree(root) << endl;

    return 0;
}
