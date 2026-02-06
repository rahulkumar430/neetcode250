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
   public:
    // Brute force Solution - Time Complexity: O(N), Space Complexity: O(N)
    // ListNode* reverseBetween(ListNode* head, int left, int right) {
    //     vector<int> values;
    //     ListNode* curr = head;

    //     // Store all node values in vector
    //     while (curr != nullptr) {
    //         values.push_back(curr->val);
    //         curr = curr->next;
    //     }

    //     // Reverse the portion between left and right (1-indexed)
    //     reverse(values.begin() + left - 1, values.begin() + right);

    //     // Reconstruct the linked list
    //     ListNode* newHead = new ListNode(values[0]);
    //     curr = newHead;
    //     for (int i = 1; i < values.size(); i++) {
    //         curr->next = new ListNode(values[i]);
    //         curr = curr->next;
    //     }
    //     return newHead;
    // }

    // Iterative Method - Time Complexity: O(N), Space Complexity: O(1)
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        // Dummy to handle left = 1
        ListNode dummy(0);
        dummy.next = head;

        // Step 1: reach node before left
        ListNode* prevLeft = &dummy;
        for (int i = 1; i < left; i++) {
            prevLeft = prevLeft->next;
        }

        // Step 2: identify left and right boundaries
        ListNode* leftNode = prevLeft->next;
        ListNode* curr = leftNode;
        ListNode* prev = nullptr;

        // Step 3: reverse nodes from left to right
        for (int i = left; i <= right; i++) {
            ListNode* nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
        }

        // Step 4: reconnect edges
        // prev is new head of reversed part (rightNode)
        // curr is node after right
        prevLeft->next = prev;
        leftNode->next = curr;

        return dummy.next;
    }

    // Another Iterative Method - Time Complexity: O(N), Space Complexity: O(1)
    // ListNode* reverseBetween(ListNode* head, int left, int right) {
    //     // Dummy node to handle left = 1 cleanly
    //     ListNode dummy(0);
    //     dummy.next = head;

    //     // Step 1: move prev to node before `left`
    //     ListNode* prev = &dummy;
    //     for (int i = 1; i < left; i++) {
    //         prev = prev->next;
    //     }

    //     // `start` will become the tail of reversed part
    //     ListNode* start = prev->next;
    //     ListNode* curr = start->next;

    //     // Step 2: reverse nodes between left and right
    //     // Reverse sublist by moving each next node `curr` to the front of `prev`
    //     // `prev` stays fixed; sublist reverses in-place

    //     for (int i = left; i < right; i++) {
    //         start->next = curr->next;  // detach curr
    //         curr->next = prev->next;   // move curr to front
    //         prev->next = curr;         // link prev to curr
    //         curr = start->next;        // advance curr
    //     }

    //     // Return updated head
    //     return dummy.next;
    // }
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
    vector<int> vect = {1, 2, 3, 4, 5, 6, 7};
    int left = 3, right = 6;
    ListNode* head = vectorToList(vect);

    printList(head);

    Solution sol;
    ListNode* result = sol.reverseBetween(head, left, right);

    printList(result);
    return 0;
}