#include <bits/stdc++.h>
using namespace std;

// Definition for a Node.
class Node {
   public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = nullptr;
        random = nullptr;
    }
};

class Solution {
   public:
    // Hashmap Approach - Time Complexity: O(N), Space Complexity: O(N)
    Node* copyRandomList(Node* head) {
        // Edge case: empty list
        if (head == nullptr) return nullptr;

        // HashMap: original node -> copied node
        unordered_map<Node*, Node*> mp;

        // Create copy of each node
        Node* curr = head;
        while (curr != nullptr) {
            // Create a new node with same value
            mp[curr] = new Node(curr->val);
            curr = curr->next;
        }

        // Assign next and random pointers
        curr = head;
        while (curr != nullptr) {
            // Set next pointer of copied node
            if (curr->next != nullptr) {
                mp[curr]->next = mp[curr->next];
            }

            // Set random pointer of copied node
            if (curr->random != nullptr) {
                mp[curr]->random = mp[curr->random];
            }

            curr = curr->next;
        }

        // Head of copied list
        return mp[head];
    }

    // Interleaving / Weaving Nodes Technique - Time Complexity: O(N), Space Complexity: O(1), but O(N) for the output
    // Node* copyRandomList(Node* head) {
    //     if (head == nullptr) return nullptr;

    //     Node* curr = head;

    //     // STEP 1: Create copied nodes and insert after originals
    //     // A → B → C  →  A → A' → B → B' → C → C'
    //     while (curr != nullptr) {
    //         // Create a new node (copy) with same value
    //         Node* copy = new Node(curr->val);

    //         // Insert the copied node right after the original node
    //         copy->next = curr->next;
    //         curr->next = copy;

    //         // Move to the next original node
    //         curr = copy->next;
    //     }

    //     // STEP 2: Assign random pointers for copied nodes
    //     // original.random->next gives copied random
    //     curr = head;
    //     while (curr != nullptr) {
    //         // If original node has a random pointer
    //         if (curr->random != nullptr) {
    //             // Set copied node's random pointer
    //             curr->next->random = curr->random->next;
    //         }

    //         // Move to next original node (skip copied node)
    //         curr = curr->next->next;
    //     }

    //     // STEP 3: Separate original and copied lists
    //     Node* dummy = new Node(0);
    //     Node* copyCurr = dummy;
    //     curr = head;

    //     while (curr != nullptr) {
    //         copyCurr->next = curr->next;    // extract copy
    //         curr->next = curr->next->next;  // restore original

    //         copyCurr = copyCurr->next;
    //         curr = curr->next;
    //     }

    //     // dummy->next is the head of the deep copied list
    //     return dummy->next;
    // }
};

// Helper to build list from input like [[3,null],[7,3],[4,0],[5,1]]
Node* buildList(const vector<pair<int, int>>& data) {
    int n = data.size();
    if (n == 0) return nullptr;

    vector<Node*> nodes;

    // Create all nodes
    for (int i = 0; i < n; i++) {
        nodes.push_back(new Node(data[i].first));
    }

    // Set next pointers
    for (int i = 0; i < n - 1; i++) {
        nodes[i]->next = nodes[i + 1];
    }

    // Set random pointers
    for (int i = 0; i < n; i++) {
        int randomIndex = data[i].second;
        if (randomIndex != -1) {
            nodes[i]->random = nodes[randomIndex];
        }
    }

    return nodes[0];
}

// Helper to print the list
// Output format: index, value, random_index
void printList(Node* head) {
    vector<Node*> nodes;
    Node* curr = head;

    // Collect nodes
    while (curr != nullptr) {
        nodes.push_back(curr);
        curr = curr->next;
    }

    // Print
    cout << "[\n";
    for (int i = 0; i < nodes.size(); i++) {
        cout << "  Index " << i
             << " | Val = " << nodes[i]->val
             << " | Random = ";

        if (nodes[i]->random == nullptr) {
            cout << "null";
        } else {
            // Find random index
            for (int j = 0; j < nodes.size(); j++) {
                if (nodes[j] == nodes[i]->random) {
                    cout << j;
                    break;
                }
            }
        }
        cout << "\n";
    }
    cout << "]\n";
}

int main() {
    // Input: [[3,null],[7,3],[4,0],[5,1]]
    // We use -1 to represent null
    vector<pair<int, int>> input = {
        {3, -1},
        {7, 3},
        {4, 0},
        {5, 1}};

    Node* head = buildList(input);

    cout << "Original List:\n";
    printList(head);

    Solution sol;
    Node* copied = sol.copyRandomList(head);

    cout << "\nCopied List:\n";
    printList(copied);  // currently prints empty / null list

    return 0;
}
