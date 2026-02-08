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

// Approach: Recursive DFS (Inorder Traversal)
// Time Complexity: O(N), Space Complexity: O(H) (recursion stack, H = tree height)
class Solution {
    // Stores the inorder traversal result
    vector<int> res;

   private:
    // Recursive helper function to perform inorder traversal
    void inorder(TreeNode* node) {
        // Base case: if node is NULL, simply return
        if (!node) {
            return;
        }

        // Traverse left subtree
        inorder(node->left);

        // Visit current node
        res.push_back(node->val);

        // Traverse right subtree
        inorder(node->right);
    }

   public:
    // Function that initiates inorder traversal
    vector<int> inorderTraversal(TreeNode* root) {
        inorder(root);  // call helper recursive function
        return res;
    }
};

// Iterative DFS using Stack (Inorder Traversal)
// Time Complexity: O(N), Space Complexity: O(H) (explicit stack)
// class Solution {
//    public:
//     // Iterative inorder traversal using stack
//     vector<int> inorderTraversal(TreeNode* root) {
//         vector<int> res;
//         stack<TreeNode*> st;
//         TreeNode* curr = root;

//         while (curr != nullptr || !st.empty()) {
//             // Go to the leftmost node
//             while (curr != nullptr) {
//                 st.push(curr);
//                 curr = curr->left;
//             }

//             // Process node
//             curr = st.top();
//             st.pop();
//             res.push_back(curr->val);

//             // Visit right subtree
//             curr = curr->right;
//         }

//         return res;
//     }
// };

int main() {
    vector<int> input = {1, 2, 3, 4, 5, 6, 7};

    // Build tree using helper
    TreeNode* root = buildTree(input);

    Solution sol;
    vector<int> ans = sol.inorderTraversal(root);

    for (int x : ans) cout << x << " ";
    cout << endl;

    return 0;
}
