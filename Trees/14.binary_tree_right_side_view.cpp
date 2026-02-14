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
    // Iterative BFS Approach - Time Complexity : O(N), Space Complexity: O(H)
    vector<int> rightSideView(TreeNode* root) {
        if (!root) return {};

        vector<int> ans;
        queue<pair<TreeNode*, int>> q;

        // push root with level 0
        q.push({root, 0});

        while (!q.empty()) {
            auto [node, level] = q.front();
            q.pop();

            // If this level is seen for the first time,
            // this node is the rightmost (because we push right first)
            if (ans.size() == level)
                ans.push_back(node->val);

            // Push right child first
            if (node->right)
                q.push({node->right, level + 1});

            // Then push left child
            if (node->left)
                q.push({node->left, level + 1});
        }

        return ans;
    }
    // Recursive DFS Approach - Time Complexity : O(N), Space Complexity: O(H)
    //    private:
    //     vector<int> ans;
    //     void dfs(TreeNode* node, int level) {
    //         if (!node) return;

    //         // If this level is visited for the first time,
    //         // this node is the rightmost node at that level
    //         if (ans.size() == level)
    //             ans.push_back(node->val);

    //         // Visit right subtree first
    //         dfs(node->right, level + 1);

    //         // Then visit left subtree
    //         dfs(node->left, level + 1);
    //     }

    //    public:
    //     vector<int> rightSideView(TreeNode* root) {
    //         dfs(root, 0);
    //         return ans;
    //     }
};

int main() {
    vector<int> input = {1, 2, 3, 4, 5, 6, 7};

    TreeNode* root = buildTree(input);
    printTree(root);
    cout << endl;

    Solution sol;
    vector<int> ans = sol.rightSideView(root);
    for (int x : ans) {
        cout << x << " ";
    }
    return 0;
}