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

// BFS Approach: Time Complexity : O(N), Space Complexity : O(N)
class Codec {
   public:
    // Encodes a tree to a single string (BFS)
    string serialize(TreeNode* root) {
        if (!root) return "";

        queue<TreeNode*> q;
        q.push(root);

        string result;

        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();

            if (node) {
                result += to_string(node->val) + ",";

                // Push children even if null
                q.push(node->left);
                q.push(node->right);
            } else {
                result += "N,";  // Special marker for null
            }
        }

        return result;
    }

    // Decodes your encoded data to tree
    TreeNode* deserialize(string data) {
        if (data.empty()) return nullptr;

        stringstream ss(data);
        string value;

        // First value is root
        getline(ss, value, ',');
        TreeNode* root = new TreeNode(stoi(value));

        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();

            // Process left child
            if (getline(ss, value, ',')) {
                if (value != "N") {
                    node->left = new TreeNode(stoi(value));
                    q.push(node->left);
                }
            }

            // Process right child
            if (getline(ss, value, ',')) {
                if (value != "N") {
                    node->right = new TreeNode(stoi(value));
                    q.push(node->right);
                }
            }
        }

        return root;
    }
};

// DFS Approach: Time Complexity : O(N), Space Complexity : O(H)
// class Codec {
//    public:
//     // Serialize using preorder DFS
//     string serialize(TreeNode* root) {
//         string result;
//         dfsSerialize(root, result);
//         return result;
//     }

//     void dfsSerialize(TreeNode* node, string& result) {
//         if (!node) {
//             result += "N,";
//             return;
//         }

//         // Add current node value
//         result += to_string(node->val) + ",";

//         // Recurse left then right
//         dfsSerialize(node->left, result);
//         dfsSerialize(node->right, result);
//     }

//     // Deserialize using preorder DFS
//     TreeNode* deserialize(string data) {
//         stringstream ss(data);
//         return dfsDeserialize(ss);
//     }

//     TreeNode* dfsDeserialize(stringstream& ss) {
//         string value;
//         getline(ss, value, ',');

//         if (value == "N")
//             return nullptr;

//         // Create node
//         TreeNode* node = new TreeNode(stoi(value));

//         // Build left subtree
//         node->left = dfsDeserialize(ss);

//         // Build right subtree
//         node->right = dfsDeserialize(ss);

//         return node;
//     }
// };

int main() {
    vector<int> input = {1, 2, 3, INT_MIN, INT_MIN, 4, 5};

    TreeNode* root = buildTree(input);
    printTree(root);
    cout << endl;

    Codec codec;

    // Serialize
    string data = codec.serialize(root);
    cout << "Serialized: " << data << endl;

    // Deserialize
    TreeNode* newRoot = codec.deserialize(data);

    cout << "Tree after deserialization: ";
    printTree(newRoot);

    return 0;
}