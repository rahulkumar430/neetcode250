#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
   private:
    ListNode* reverseList(ListNode* head, ListNode* tail) {
        ListNode* prev = nullptr;
        ListNode* curr = head;

        while (curr != tail) {
            ListNode* nextNode = curr->next;  // store next
            curr->next = prev;                // reverse link
            prev = curr;                      // move prev
            curr = nextNode;                  // move curr
        }
        return prev;
    }

   public:
    // Brute force approach - Time & Space Complexity: O(N)
    // ListNode* reverseKGroup(ListNode* head, int k) {
    //     vector<int> v;
    //     ListNode* temp = head;
    //     while (temp != nullptr) {
    //         v.push_back(temp->val);
    //         temp = temp->next;
    //     }

    //     // Reverse every k elements
    //     for (int i = 0; i + k <= v.size(); i += k) {
    //         reverse(v.begin() + i, v.begin() + i + k);
    //     }

    //     // Convert vector back to linked list
    //     head = new ListNode(v[0]);
    //     temp = head;
    //     for (int i = 1; i < v.size(); i++) {
    //         temp->next = new ListNode(v[i]);
    //         temp = temp->next;
    //     }

    //     return head;
    // }

    // Optimised Iterative Method by reversing k and move forward
    // Time Complexity: O(N), Space Complexity: O(1)
    ListNode* reverseKGroup(ListNode* head, int k) {
        // Create a dummy node to simplify edge cases
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* prevGroup = dummy;        // Points to the node before current group
        ListNode* currGroup = dummy->next;  // Points to the start of current group

        while (currGroup != nullptr) {
            ListNode* kthNode = prevGroup;

            // Find the kth node in the current group
            for (int i = 0; i < k; i++) {
                if (kthNode->next != nullptr) {
                    kthNode = kthNode->next;
                } else {
                    // Not enough nodes left, return result
                    return dummy->next;
                }
            }

            // Store the next group's start node before reversing
            ListNode* nextGroup = kthNode->next;
            kthNode->next = nullptr;  // Separate the current group from rest

            // Reverse the current group and link it to previous group
            prevGroup->next = reverseList(currGroup, nullptr);
            // Connect the end of reversed group to the next group
            currGroup->next = nextGroup;

            // Move to next group
            prevGroup = currGroup;
            currGroup = nextGroup;
        }

        return dummy->next;
    }
};

// Helper function to convert vector to linked list
ListNode* vectorToList(vector<int>& vect) {
    // If vector is empty, return null
    if (vect.empty()) return nullptr;

    // Create head node
    ListNode* head = new ListNode(vect[0]);
    ListNode* curr = head;

    // Create remaining nodes
    for (int i = 1; i < vect.size(); i++) {
        curr->next = new ListNode(vect[i]);
        curr = curr->next;
    }

    return head;
}

// Helper function to print the list
void printList(ListNode* head) {
    while (head != nullptr) {
        cout << head->val;
        if (head->next) cout << " -> ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    vector<int> vect = {1, 2, 3, 4, 5, 6};
    ListNode* head = vectorToList(vect);
    printList(head);

    Solution sol;
    int k = 3;

    ListNode* result = sol.reverseKGroup(head, k);

    printList(result);
    return 0;
}