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
    // Iterative Method - Time Complexity: O(N+M), Space Complexity: O(1)
    // ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
    //     // Base cases: if one list is empty, return the other
    //     if (list1 == nullptr) return list2;
    //     if (list2 == nullptr) return list1;

    //     // Ensure list1 always starts with the smaller value
    //     // This simplifies merging logic
    //     if (list1->val > list2->val) {
    //         return mergeTwoLists(list2, list1);
    //     }

    //     // curr1 traverses list1 (result list)
    //     // curr2 traverses list2 (nodes to be inserted)
    //     ListNode* curr1 = list1;
    //     ListNode* curr2 = list2;

    //     // We only check curr1->next and curr2
    //     // because insertion happens BETWEEN curr1 and curr1->next
    //     while (curr1->next != nullptr && curr2 != nullptr) {
    //         // If curr2 should come after curr1->next,
    //         // just move curr1 forward
    //         if (curr1->next->val <= curr2->val) {
    //             curr1 = curr1->next;
    //             continue;
    //         }

    //         // Save the next node of curr1 before modifying links
    //         ListNode* nextNode = curr1->next;

    //         // Insert curr2 between curr1 and nextNode
    //         curr1->next = curr2;

    //         // Move curr2 forward (save remaining list2)
    //         curr2 = curr2->next;

    //         // Complete the insertion by linking back to list1
    //         curr1->next->next = nextNode;

    //         // Move curr1 forward to the newly inserted node
    //         curr1 = curr1->next;
    //     }

    //     // If list2 still has nodes left, attach them at the end
    //     if (curr2 != nullptr) {
    //         curr1->next = curr2;
    //     }

    //     // list1 is the head of the merged list
    //     return list1;
    // }

    // Recursion Method - Time Complexity: O(N+M), Space Complexity: O(N+M)
    // ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
    //     // Base case 1: if list1 is empty, return list2
    //     if (list1 == nullptr) {
    //         return list2;
    //     }

    //     // Base case 2: if list2 is empty, return list1
    //     if (list2 == nullptr) {
    //         return list1;
    //     }

    //     // If list1 has the smaller value,
    //     // keep list1 as head and merge the rest
    //     if (list1->val <= list2->val) {
    //         list1->next = mergeTwoLists(list1->next, list2);
    //         return list1;
    //     }
    //     // Otherwise, list2 has the smaller value
    //     else {
    //         list2->next = mergeTwoLists(list1, list2->next);
    //         return list2;
    //     }
    // }

    // Iterative Method - Time Complexity: O(N+M), Space Complexity: O(1)
    // Using dummy node, its easier and cleaner to attempt this problem
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        // Dummy node to simplify head handling
        ListNode dummy(0);
        ListNode* tail = &dummy;

        // While both lists have nodes
        while (list1 != nullptr && list2 != nullptr) {
            if (list1->val <= list2->val) {
                tail->next = list1;   // attach list1 node
                list1 = list1->next;  // move list1
            } else {
                tail->next = list2;   // attach list2 node
                list2 = list2->next;  // move list2
            }
            tail = tail->next;  // move tail to the element that got attached
        }

        // Attach remaining nodes (only one list can be non-null)
        tail->next = (list1 != nullptr) ? list1 : list2;

        // The merged list starts after dummy
        return dummy.next;
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
    // Create linked list: 1 -> 3 -> 5
    ListNode* list1 = new ListNode(1,
                                   new ListNode(3,
                                                new ListNode(5)));

    // Create linked list: 2 -> 4 -> 6
    ListNode* list2 = new ListNode(2,
                                   new ListNode(4,
                                                new ListNode(6)));

    Solution sol;
    ListNode* merged = sol.mergeTwoLists(list1, list2);

    printList(merged);

    return 0;
}
