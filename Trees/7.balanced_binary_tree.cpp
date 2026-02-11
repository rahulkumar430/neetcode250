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

// Brute force approach
// Time Complexity: O(N^2), Space Complexity: O(H) recursion stack
// class Solution {
//    private:
//     // Returns height of subtree
//     int height(TreeNode* root) {
//         if (root == nullptr) return 0;

//         return 1 + max(height(root->left), height(root->right));
//     }

//    public:
//     bool isBalanced(TreeNode* root) {
//         if (!root) return true;  // Empty tree is balanced

//         int left = height(root->left);
//         int right = height(root->right);

//         // If height difference is more than 1 → not balanced
//         if (abs(left - right) > 1) return false;

//         // Recursively check left and right subtrees
//         return isBalanced(root->left) && isBalanced(root->right);
//     }
// };

// Using DFS recursion
// Time Complexity: O(N), Space Complexity: O(H) where H is tree height
class Solution {
   private:
    // Returns pair<isBalanced, height>
    pair<bool, int> dfs(TreeNode* node) {
        // Base case: An empty tree is balanced and its height is 0
        if (node == nullptr) {
            return {true, 0};
        }

        // Recursively check left and right subtree
        auto left = dfs(node->left);
        auto right = dfs(node->right);

        /*
            A node is balanced if:
            1. Left subtree is balanced
            2. Right subtree is balanced
            3. Height difference between left and right <= 1
        */
        bool balanced = left.first && right.first &&
                        abs(left.second - right.second) <= 1;

        // Height of current node = 1 + max(leftHeight, rightHeight)
        int height = 1 + max(left.second, right.second);

        // Return both balance status and height to parent
        return {balanced, height};
    }

   public:
    bool isBalanced(TreeNode* root) {
        return dfs(root).first;
    }
};

int main() {
    vector<int> input = {1, 2, 3, INT_MIN, INT_MIN, 4};

    TreeNode* root = buildTree(input);
    printTree(root);
    cout << endl;

    Solution sol;
    cout << (sol.isBalanced(root) ? "true" : "false") << endl;

    return 0;
}
