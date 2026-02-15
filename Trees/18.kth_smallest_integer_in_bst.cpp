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

// DFS Brute Force Approach - Time Complexity : O(N log N), Space Complexity: O(N)
// class Solution {
//    private:
//     // Simple DFS to collect all node values
//     void dfs(TreeNode* node, vector<int>& values) {
//         if (!node) return;

//         values.push_back(node->val);
//         dfs(node->left, values);
//         dfs(node->right, values);
//     }

//    public:
//     int kthSmallest(TreeNode* root, int k) {
//         vector<int> values;

//         // Collect all node values
//         dfs(root, values);

//         // Sort the values
//         sort(values.begin(), values.end());

//         // Return k-th smallest (1-based index)
//         return values[k - 1];
//     }
// };

// Optimised Approach using Inorder Traversal - Time Complexity : O(H + k), Space Complexity: O(H)
class Solution {
   private:
    int count = 0;
    int ans = 0;

    void inorder(TreeNode* node, int k) {
        if (!node) return;

        // Traverse left subtree first (smaller values)
        inorder(node->left, k);

        // Process current node
        count++;

        // If this is the k-th node, store answer
        if (count == k) {
            ans = node->val;
            return;
        }

        // Traverse right subtree
        inorder(node->right, k);
    }

   public:
    int kthSmallest(TreeNode* root, int k) {
        inorder(root, k);
        return ans;
    }
};

// Slightly improved over the previous optimised inorder traversal solution
// class Solution {
//    private:
//     int count = 0;

//     int inorder(TreeNode* node, int k) {
//         if (!node) return -1;

//         // Go left
//         int left = inorder(node->left, k);
//         if (left != -1) return left;

//         // Visit current
//         count++;
//         if (count == k) return node->val;

//         // Go right
//         return inorder(node->right, k);
//     }

//    public:
//     int kthSmallest(TreeNode* root, int k) {
//         return inorder(root, k);
//     }
// };

int main() {
    vector<int> input = {4, 3, 5, 2, INT_MIN};
    int k = 4;

    TreeNode* root = buildTree(input);
    printTree(root);
    cout << endl;

    Solution sol;
    cout << sol.kthSmallest(root, k) << endl;

    return 0;
}