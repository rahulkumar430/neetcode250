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
    // Find the minimum node in a subtree (leftmost node)
    // This is used to get the inorder successor
    TreeNode* findMin(TreeNode* node) {
        while (node->left)
            node = node->left;
        return node;
    }

   public:
    // Iterative Approach - Time Complexity : O(H), Space Complexity: O(1)
    TreeNode* deleteNode(TreeNode* root, int key) {
        TreeNode* parent = nullptr;
        TreeNode* curr = root;

        // Step 1: Search for the node to delete
        while (curr && curr->val != key) {
            parent = curr;
            if (key < curr->val)
                curr = curr->left;
            else
                curr = curr->right;
        }

        // If key not found, return original tree
        if (!curr) return root;

        // Step 2: If node has TWO children
        if (curr->left && curr->right) {
            // Find inorder successor (smallest in right subtree)
            TreeNode* succ = findMin(curr->right);

            // Copy successor value to current node
            curr->val = succ->val;

            // Now delete the successor instead
            key = succ->val;
            parent = curr;
            curr = curr->right;

            // Move to successor node
            while (curr->val != key) {
                parent = curr;
                curr = curr->left;
            }
        }

        // Step 3: Node has at most ONE child
        TreeNode* child = (curr->left) ? curr->left : curr->right;

        // If deleting root node
        if (!parent) {
            delete curr;
            return child;
        }

        // Reconnect parent to child
        if (parent->left == curr)
            parent->left = child;
        else
            parent->right = child;

        delete curr;
        return root;
    }

    // Recursive Approach - Time Complexity : O(H), Space Complexity: O(H)
    // TreeNode* deleteNode(TreeNode* root, int key) {
    //     // Base case: key not found
    //     if (!root) return nullptr;

    //     // Step 1: Traverse the BST to find the node
    //     if (key < root->val) {
    //         root->left = deleteNode(root->left, key);
    //     } else if (key > root->val) {
    //         root->right = deleteNode(root->right, key);
    //     } else {
    //         // Step 2: Node found — handle deletion cases

    //         // Case A: No child (leaf node)
    //         if (!root->left && !root->right) {
    //             delete root;
    //             return nullptr;
    //         }

    //         // Case B: One child
    //         if (!root->left) {
    //             TreeNode* temp = root->right;
    //             delete root;
    //             return temp;
    //         }
    //         if (!root->right) {
    //             TreeNode* temp = root->left;
    //             delete root;
    //             return temp;
    //         }

    //         // Case C: Two children
    //         // Replace with inorder successor (smallest in right subtree)
    //         TreeNode* succ = findMin(root->right);
    //         root->val = succ->val;

    //         // Delete the successor recursively
    //         root->right = deleteNode(root->right, succ->val);
    //     }

    //     return root;
    // }
};

int main() {
    vector<int> input = {5, 3, 9, 1, 4};
    int key = 3;
    TreeNode* root = buildTree(input);
    printTree(root);
    cout << endl;

    Solution sol;
    root = sol.deleteNode(root, key);
    printTree(root);
    cout << endl;
    return 0;
}