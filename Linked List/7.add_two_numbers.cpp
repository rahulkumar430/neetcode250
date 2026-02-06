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
    // Iterative Approach : Digit-by-digit addition with carry - Time Complexity: O(N), Space Complexity: O(1)
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        // Dummy node to simplify result list construction
        ListNode* ans = new ListNode(0);
        ListNode* curr = ans;
        int carry = 0;  // Stores carry from previous digit

        // Loop until both lists are exhausted
        while (l1 != nullptr || l2 != nullptr) {
            // Add current digits and carry
            int sum = (l1 ? l1->val : 0) + (l2 ? l2->val : 0) + carry;

            // Current digit of result
            int newDigit = sum % 10;

            // Update carry for next iteration
            carry = sum / 10;

            // Append new digit to result list
            curr->next = new ListNode(newDigit);
            curr = curr->next;

            // Move to next nodes if available
            l1 = l1 ? l1->next : nullptr;
            l2 = l2 ? l2->next : nullptr;
        }
        // If carry is still there attach it to the last
        if (carry) curr->next = new ListNode(carry);
        return ans->next;
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
    vector<int> vect1 = {2, 4, 3};  // represents the number 342
    vector<int> vect2 = {5, 6, 4};  // represents the number 465

    ListNode* l1 = vectorToList(vect1);
    ListNode* l2 = vectorToList(vect2);

    cout << "List 1: ";
    printList(l1);
    cout << "List 2: ";
    printList(l2);

    Solution sol;
    ListNode* result = sol.addTwoNumbers(l1, l2);

    cout << "Result: ";
    printList(result);  // should represent 342+465=807 which is 7->0->8
    return 0;
}