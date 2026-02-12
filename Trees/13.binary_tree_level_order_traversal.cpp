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
    // Iterative BFS Approach - Time & Space Complexity: O(N)
    vector<vector<int>> levelOrder(TreeNode* root) {
        if (!root) return {};

        vector<vector<int>> ans;

        // queue stores {node, level}
        queue<pair<TreeNode*, int>> q;
        q.push({root, 0});

        while (!q.empty()) {
            auto [curr, level] = q.front();  // always use front()
            q.pop();

            // Create new level if needed
            if (ans.size() == level)
                ans.push_back({});

            // Add current node value
            ans[level].push_back(curr->val);

            // Push children if they exist
            if (curr->left)
                q.push({curr->left, level + 1});
            if (curr->right)
                q.push({curr->right, level + 1});
        }

        return ans;
    }

    //  private:
    //   vector<vector<int>> ans;

    //   // DFS helper function
    //   void dfs(TreeNode* node, int level) {
    //       if (!node) return;

    //       // If visiting this level for the first time, create a new vector
    //       if (ans.size() == level)
    //           ans.push_back({});

    //       // Add current node to its level
    //       ans[level].push_back(node->val);

    //       // Recurse left then right (order matters)
    //       dfs(node->left, level + 1);
    //       dfs(node->right, level + 1);
    //   }

    //  public:
    //   // Recursive DFS Approach - Time Complexity : O(N), Space Complexity : O(H)
    //   vector<vector<int>> levelOrder(TreeNode* root) {
    //       dfs(root, 0);
    //       return ans;
    //   }
};

int main() {
    vector<int> input = {1, 2, 3, 4, 5, 6, 7};

    TreeNode* root = buildTree(input);

    printTree(root);
    cout << endl;

    Solution sol;
    vector<vector<int>> ans = sol.levelOrder(root);

    for (vector<int> x : ans) {
        for (int y : x) {
            cout << y << " ";
        }
        cout << endl;
    }

    return 0;
}