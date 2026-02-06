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
    // Two pointers Approach - Time Complexity: O(N), Space Complexity: O(1)
    // ListNode* removeNthFromEnd(ListNode* head, int n) {
    //     // dummy node is used deal in case, n = length of the linked list
    //     ListNode* dummy = new ListNode(0);
    //     dummy->next = head;
    //     ListNode* curr = dummy;

    //     // Calculate length
    //     int length = 0;
    //     ListNode* temp = head;
    //     while (temp != nullptr) {
    //         length++;
    //         temp = temp->next;
    //     }

    //     // Traverse to length - n
    //     for (int i = 0; i < length - n; i++) {
    //         curr = curr->next;
    //     }

    //     // Remove the nth node
    //     curr->next = curr->next->next;

    //     return dummy->next;
    // }

    // Another Two pointers Approach using Fast & Slow pointers - Time Complexity: O(N), Space Complexity: O(1)
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        // Dummy node to handle removing head cleanly
        ListNode dummy(0);
        dummy.next = head;

        ListNode* fast = &dummy;
        ListNode* slow = &dummy;

        // move fast pointer n+1 steps ahead
        // so that slow ends up just before the node to delete
        for (int i = 0; i <= n; i++) {
            fast = fast->next;
        }

        // move both pointers together
        while (fast != nullptr) {
            fast = fast->next;
            slow = slow->next;
        }

        // remove the nth node from end
        slow->next = slow->next->next;

        return dummy.next;
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
    vector<int> vect = {1, 2, 3, 4};

    ListNode* head = vectorToList(vect);
    printList(head);
    cout << endl;

    Solution sol;
    int n = 2;

    sol.removeNthFromEnd(head, n);

    printList(head);
    return 0;
}