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

// DFS Approach - Time Complexity : O(N), Space Complexity: O(H)
class Solution {
   public:
    int goodNodes(TreeNode* root) {
        if (!root) return 0;

        stack<pair<TreeNode*, int>> st;
        st.push({root, root->val});

        int ans = 0;

        while (!st.empty()) {
            auto [node, maxSoFar] = st.top();
            st.pop();

            // Check BEFORE updating max
            if (node->val >= maxSoFar)
                ans++;

            // Update max for children
            int newMax = max(maxSoFar, node->val);

            // Push children only if not null
            if (node->left)
                st.push({node->left, newMax});
            if (node->right)
                st.push({node->right, newMax});
        }

        return ans;
    }
};

// DFS with recursion approach - Time Complexity : O(N), Space Complexity : O(H)
// class Solution {
//    private:
//     // DFS helper
//     // maxSoFar = maximum value from root to parent
//     int dfs(TreeNode* node, int maxSoFar) {
//         if (!node) return 0;

//         int count = 0;

//         // If current node is >= max value seen so far → it's a good node
//         if (node->val >= maxSoFar)
//             count = 1;

//         // Update max for children
//         int newMax = max(maxSoFar, node->val);

//         // Recurse left and right
//         count += dfs(node->left, newMax);
//         count += dfs(node->right, newMax);

//         return count;
//     }

//    public:
//     int goodNodes(TreeNode* root) {
//         if (!root) return 0;
//         return dfs(root, root->val);
//     }
// };

int main() {
    vector<int> input = {2, 1, 1, 3, INT_MIN, 1, 5};

    TreeNode* root = buildTree(input);
    printTree(root);
    cout << endl;

    Solution sol;
    cout << sol.goodNodes(root) << endl;

    return 0;
}