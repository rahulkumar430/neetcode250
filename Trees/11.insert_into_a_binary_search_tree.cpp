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
    // Iterative Approach - Time Complexity : O(H), Space Complexity: O(1)
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        // If tree is empty, new node becomes the root
        if (root == nullptr)
            return new TreeNode(val);

        TreeNode* curr = root;

        // Create the new node to be inserted
        TreeNode* node = new TreeNode(val);

        // Traverse the tree to find the correct insertion position
        while (curr != nullptr) {
            // If value is smaller, go to left subtree
            if (curr->val > val) {
                if (curr->left) {
                    curr = curr->left;  // Move left if child exists
                } else {
                    curr->left = node;  // Insert when left is empty
                    return root;
                }
            }
            // If value is greater, go to right subtree
            else {
                if (curr->right) {
                    curr = curr->right;  // Move right if child exists
                } else {
                    curr->right = node;  // Insert when right is empty
                    return root;
                }
            }
        }

        return root;  // (curr should never reach here)
    }

    // Recursive Approach - Time Complexity : O(H), Space Complexity: O(H)
    // TreeNode* insertIntoBST(TreeNode* root, int val) {
    //     // Base case:
    //     // If we reach a null position, this is the correct place to insert
    //     if (!root) {
    //         return new TreeNode(val);
    //     }

    //     // If value is greater than current node,
    //     // insert into the right subtree
    //     if (val > root->val) {
    //         root->right = insertIntoBST(root->right, val);
    //     }
    //     // Otherwise insert into the left subtree
    //     else {
    //         root->left = insertIntoBST(root->left, val);
    //     }

    //     // Return the unchanged root pointer after insertion
    //     return root;
    // }
};

int main() {
    vector<int> input = {5, 3, 9, 1, 4};
    int value = 6;
    TreeNode* root = buildTree(input);
    printTree(root);
    cout << endl;

    Solution sol;
    root = sol.insertIntoBST(root, value);
    printTree(root);
    cout << endl;
    return 0;
}