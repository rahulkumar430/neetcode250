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
    // Iterative Method - Time Complexity: O(N), Space Complexity: O(1)
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* curr = head;

        while (curr != nullptr) {
            ListNode* nextNode = curr->next;  // store next
            curr->next = prev;                // reverse link
            prev = curr;                      // move prev
            curr = nextNode;                  // move curr
        }
        return prev;
    }

    // Recursion method - Time Complexity: O(N), Space Complexity: O(N)
    // Works by : reverse the rest, then fix the pointer for the current node
    ListNode* reverseList(ListNode* head) {
        // Base case: empty list OR single node
        if (head == nullptr || head->next == nullptr) {
            return head;
        }

        // Reverse the remaining list
        ListNode* newHead = reverseList(head->next);

        // Fix the current node
        head->next->next = head;  // make next node point back to current
        head->next = nullptr;     // break original link

        return newHead;
    }
};

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
    // Create linked list: 1 -> 2 -> 3 -> 4 -> 5
    ListNode* head = new ListNode(1,
                                  new ListNode(2,
                                               new ListNode(3,
                                                            new ListNode(4,
                                                                         new ListNode(5)))));

    cout << "Original List: ";
    printList(head);

    Solution sol;
    head = sol.reverseList(head);

    cout << "Reversed List: ";
    printList(head);

    return 0;
}
