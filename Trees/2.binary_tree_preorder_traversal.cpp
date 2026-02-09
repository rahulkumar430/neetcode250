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

        // Left child
        if (i < arr.size()) {
            curr->left = new TreeNode(arr[i++]);
            q.push(curr->left);
        }

        // Right child
        if (i < arr.size()) {
            curr->right = new TreeNode(arr[i++]);
            q.push(curr->right);
        }
    }

    return root;
}

// Approach: Recursive DFS (Preorder Traversal)
// Time Complexity: O(N), Space Complexity: O(H) (recursion stack, H = tree height)
class Solution {
    // Stores the preorder traversal result
    vector<int> res;

   private:
    // Recursive helper function to perform preorder traversal
    void preorder(TreeNode* node) {
        // Base case: if node is NULL, simply return
        if (!node) {
            return;
        }

        // Visit current node
        res.push_back(node->val);

        // Traverse left subtree
        preorder(node->left);

        // Traverse right subtree
        preorder(node->right);
    }

   public:
    // Function that initiates preorder traversal
    vector<int> preorderTraversal(TreeNode* root) {
        preorder(root);  // call helper recursive function
        return res;
    }
};

// Iterative DFS using stack (Preorder Traversal)
// Time Complexity: O(N), Space Complexity: O(H) (explicit stack)
// class Solution {
//    public:
//     vector<int> preorderTraversal(TreeNode* root) {
//         vector<int> res;
//         if (!root) return res;

//         stack<TreeNode*> st;
//         st.push(root);

//         while (!st.empty()) {
//             TreeNode* node = st.top();
//             st.pop();

//             // Visit node
//             res.push_back(node->val);

//             // stack is LIFO, left gets processed first so push right first
//             if (node->right) st.push(node->right);
//             if (node->left) st.push(node->left);
//         }

//         return res;
//     }
// };

int main() {
    vector<int> input = {1, 2, 3, 4, 5, 6, 7};

    // Build tree using helper
    TreeNode* root = buildTree(input);

    Solution sol;
    vector<int> ans = sol.preorderTraversal(root);

    for (int x : ans) cout << x << " ";
    cout << endl;

    return 0;
}
