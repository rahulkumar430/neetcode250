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

// Approach: Recursive DFS (Postorder Traversal)
// Time Complexity: O(N), Space Complexity: O(H) (recursion stack, H = tree height)
class Solution {
    // Stores the postorder traversal result
    vector<int> res;

   private:
    // Recursive helper function to perform postorder traversal
    void postorder(TreeNode* node) {
        // Base case: if node is NULL, simply return
        if (!node) {
            return;
        }

        // Traverse left subtree
        postorder(node->left);

        // Traverse right subtree
        postorder(node->right);

        // Visit current node
        res.push_back(node->val);
    }

   public:
    // Function that initiates postorder traversal
    vector<int> postorderTraversal(TreeNode* root) {
        postorder(root);  // call helper recursive function
        return res;
    }
};

// Iterative DFS using stack (Postorder Traversal)
// Time Complexity: O(N), Space Complexity: O(H) (explicit stack)
// class Solution {
//    public:
//     // Iterative Postorder Traversal (using two stacks)
//     // Order: Left → Right → Node
//     vector<int> postorderTraversal(TreeNode* root) {
//         vector<int> res;
//         if (!root) return res;

//         stack<TreeNode*> st1, st2;
//         st1.push(root);

//         while (!st1.empty()) {
//             TreeNode* node = st1.top();
//             st1.pop();

//             // Push node into second stack
//             st2.push(node);

//             // Push left and right children into first stack
//             if (node->left) st1.push(node->left);
//             if (node->right) st1.push(node->right);
//         }

//         // st2 gives nodes in reverse postorder (Node → Right → Left)
//         // popping from it gives Left → Right → Node
//         while (!st2.empty()) {
//             res.push_back(st2.top()->val);
//             st2.pop();
//         }

//         return res;
//     }

//     // Iterative Postorder Traversal using single stack
//     // Order: Left → Right → Node
//     // vector<int> postorderTraversal(TreeNode* root) {
//     //     vector<int> res;
//     //     if (!root) return res;

//     //     stack<TreeNode*> st;
//     //     TreeNode* curr = root;
//     //     TreeNode* lastVisited = nullptr;

//     //     while (curr != nullptr || !st.empty()) {
//     //         // Go to the leftmost node
//     //         if (curr != nullptr) {
//     //             st.push(curr);
//     //             curr = curr->left;
//     //         } else {
//     //             TreeNode* node = st.top();

//     //             // If right child exists and not yet processed, move to right
//     //             if (node->right != nullptr && lastVisited != node->right) {
//     //                 curr = node->right;
//     //             } else {
//     //                 // Process node
//     //                 res.push_back(node->val);
//     //                 lastVisited = node;
//     //                 st.pop();
//     //             }
//     //         }
//     //     }

//     //     return res;
//     // }
// };

int main() {
    vector<int> input = {1, 2, 3, 4, 5, 6, 7};

    // Build tree using helper
    TreeNode* root = buildTree(input);

    Solution sol;
    vector<int> ans = sol.postorderTraversal(root);

    for (int x : ans) cout << x << " ";
    cout << endl;

    return 0;
}
