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
    // Time Complexity: O(N), Space Complexity: O(1)
    void reorderList(ListNode* head) {
        // ---------- Edge cases ----------
        if (!head || !head->next || !head->next->next) {
            return;
        }

        // ---------- 1. Find middle using slow & fast ----------
        ListNode* slow = head;
        ListNode* fast = head;

        // slow moves 1 step, fast moves 2 steps
        // when fast reaches end, slow is at middle
        while (fast->next != nullptr && fast->next->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // ---------- 2. Split the list ----------
        ListNode* secondHalf = slow->next;
        slow->next = nullptr;  // terminate first half

        // ---------- 3. Reverse the second half ----------
        secondHalf = reverseList(secondHalf);

        // ---------- 4. Merge both halves alternately ----------
        ListNode* first = head;
        ListNode* second = secondHalf;

        while (second != nullptr) {
            ListNode* temp1 = first->next;
            ListNode* temp2 = second->next;

            first->next = second;
            second->next = temp1;

            first = temp1;
            second = temp2;
        }
    }

    // Recursive helper
    // - right moves to the end via recursion
    // - left moves forward during unwinding (passed by reference)
    // void reorderHelper(ListNode* right, ListNode*& left) {
    //     // Base case 1: reach end of list (downward phase stop)
    //     if (right == nullptr) return;

    //     // Go to the end first
    //     reorderHelper(right->next, left);

    //     // Base case 2: reordering already finished
    //     if (left == nullptr) return;

    //     // Base case 3: pointers meet or cross (odd / even length)
    //     if (left == right || left->next == right) {
    //         right->next = nullptr;  // properly terminate list
    //         left = nullptr;         // signal completion to upper frames
    //         return;
    //     }

    //     // Save next pointer of left
    //     ListNode* nextLeft = left->next;

    //     // Reorder links: left -> right -> nextLeft
    //     left->next = right;
    //     right->next = nextLeft;

    //     // Move left forward
    //     left = nextLeft;
    // }

    // void reorderList(ListNode* head) {
    //     // Edge cases: no reordering needed
    //     if (!head || !head->next || !head->next->next) return;

    //     // Declare left locally
    //     ListNode* left = head;

    //     // Start recursion with right at head
    //     reorderHelper(head, left);
    // }
};
// Helper function to print the list
ListNode* arrayToList(int arr[], int n) {
    // If array is empty, return null
    if (n == 0) return nullptr;

    // Create head node
    ListNode* head = new ListNode(arr[0]);
    ListNode* curr = head;

    // Create remaining nodes
    for (int i = 1; i < n; i++) {
        curr->next = new ListNode(arr[i]);
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
    int arr[] = {2, 4, 6, 8, 10};
    int n = 5;

    ListNode* head = arrayToList(arr, n);
    printList(head);
    cout << endl;

    Solution sol;
    sol.reorderList(head);

    printList(head);
    return 0;
}