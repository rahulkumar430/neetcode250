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

// Brute Force Recursive Approach  - Time Complexity : O(2^N), Space Complexity : O(H)
// But this will give TLE, so we have to use memoisation to avoid repeated.
// class Solution {
//    public:
//     int rob(TreeNode* root) {
//         if (!root) return 0;

//         // Case 1: Rob this node
//         int robThis = root->val;

//         // If left child exists, add grandchildren
//         if (root->left) {
//             robThis += rob(root->left->left);
//             robThis += rob(root->left->right);
//         }

//         // If right child exists, add grandchildren
//         if (root->right) {
//             robThis += rob(root->right->left);
//             robThis += rob(root->right->right);
//         }

//         // Case 2: Do NOT rob this node
//         int skipThis = rob(root->left) + rob(root->right);

//         // Return maximum of two choices
//         return max(robThis, skipThis);
//     }
// };

// DP + Memoization Approach  - Time Complexity : O(N), Space Complexity : O(N)
// class Solution {
//    private:
//     // Memoization map
//     unordered_map<TreeNode*, int> memo;

//    public:
//     int rob(TreeNode* root) {
//         if (!root) return 0;

//         // If already computed, return stored value
//         if (memo.count(root))
//             return memo[root];

//         // Case 1: Rob this node
//         int robThis = root->val;

//         if (root->left) {
//             robThis += rob(root->left->left);
//             robThis += rob(root->left->right);
//         }

//         if (root->right) {
//             robThis += rob(root->right->left);
//             robThis += rob(root->right->right);
//         }

//         // Case 2: Skip this node
//         int skipThis = rob(root->left) + rob(root->right);

//         // Store the result
//         memo[root] = max(robThis, skipThis);

//         return memo[root];
//     }
// };

// Bottom-Up Tree DP - Time Complexity : O(N), Space Complexity : O(H)
class Solution {
   private:
    /*
        dfs(node) returns:
        pair<int,int>
        first  = max money if we ROB this node
        second = max money if we SKIP this node
    */
    pair<int, int> dfs(TreeNode* node) {
        if (!node)
            return {0, 0};

        // Get results from left and right subtrees
        auto left = dfs(node->left);
        auto right = dfs(node->right);

        // If we rob this node:
        // we CANNOT rob its children
        int robThis = node->val + left.second + right.second;

        // If we skip this node:
        // we can choose best of rob or skip from children
        int skipThis = max(left.first, left.second) +
                       max(right.first, right.second);

        return {robThis, skipThis};
    }

   public:
    int rob(TreeNode* root) {
        auto result = dfs(root);

        // Final answer is max of rob or skip at root
        return max(result.first, result.second);
    }
};

int main() {
    vector<int> input = {1, 4, INT_MIN, 2, 3, 3};

    TreeNode* root = buildTree(input);
    printTree(root);
    cout << endl;

    Solution sol;
    cout << sol.rob(root) << endl;

    return 0;
}