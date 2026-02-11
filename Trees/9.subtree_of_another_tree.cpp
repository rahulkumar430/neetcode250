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

// Brute Force Approach - Time Complexity : O(N * M), Space Complexity: O(H)
// class Solution {
//    private:
//     // Reuse same tree comparison logic
//     bool isSameTree(TreeNode* p, TreeNode* q) {
//         if (!p && !q) return true;
//         if (!p || !q) return false;
//         if (p->val != q->val) return false;

//         return isSameTree(p->left, q->left) &&
//                isSameTree(p->right, q->right);
//     }

//    public:
//     // Brute-force DFS approach
//     // For every node in root, check if subtree matches subRoot
//     // bool isSubtree(TreeNode* root, TreeNode* subRoot) {
//     //     // If main tree becomes null → no subtree possible
//     //     if (!root) return false;

//     //     // If trees match at current node → return true
//     //     if (isSameTree(root, subRoot))
//     //         return true;

//     //     // Otherwise check left and right subtrees
//     //     return isSubtree(root->left, subRoot) ||
//     //            isSubtree(root->right, subRoot);
//     // }

//     // Improved brute-force approach
//     // Only call isSameTree when root values match
//     bool isSubtree(TreeNode* root, TreeNode* subRoot) {
//         if (!root) return false;

//         // Optimization: check value before full comparison
//         if (root->val == subRoot->val &&
//             isSameTree(root, subRoot)) {
//             return true;
//         }

//         // Continue searching in left and right
//         return isSubtree(root->left, subRoot) ||
//                isSubtree(root->right, subRoot);
//     }
// };

// Optimised Approach : Tree serialization + substring check
// Time & Space Complexity : O(N * M)
class Solution {
   private:
    // Preorder serialization with null markers
    void serialize(TreeNode* root, string& s) {
        if (!root) {
            s += "#,";  // marker for null
            return;
        }

        s += to_string(root->val) + ",";  // add value
        serialize(root->left, s);
        serialize(root->right, s);
    }

   public:
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        string s1 = "";
        string s2 = "";

        // Serialize both trees
        serialize(root, s1);
        serialize(subRoot, s2);

        // Check if subRoot serialization is substring of root
        return s1.find(s2) != string::npos;
    }
};

int main() {
    vector<int> v1 = {1, 2, 3, 4, 5};
    vector<int> v2 = {2, 4, 5};

    TreeNode* root = buildTree(v1);
    printTree(root);
    cout << endl;

    TreeNode* subRoot = buildTree(v2);
    printTree(subRoot);
    cout << endl;

    Solution sol;
    cout << (sol.isSubtree(root, subRoot) ? "true" : "false") << endl;

    return 0;
}
