#include <bits/stdc++.h>
using namespace std;

//  Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
   public:
    // Iterative Approach - Time Complexity : O(N), Space Complexity : O(N)
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        ListNode* l = head;
        ListNode* r = head->next;

        while (r != NULL) {
            int g = gcd(l->val, r->val);

            ListNode* gNode = new ListNode(g);

            gNode->next = r;
            l->next = gNode;

            l = r;
            r = r->next;
        }
        // Actually no need of two pointers, One pointer is enough
        // ListNode* curr = head;

        // while (curr != NULL && curr->next != NULL) {
        //     int g = gcd(curr->val, curr->next->val);

        //     ListNode* gNode = new ListNode(g);

        //     gNode->next = curr->next;
        //     curr->next = gNode;

        //     curr = gNode->next;
        // }

        return head;
    }
};

ListNode* createList(vector<int>& nums) {
    if (nums.empty()) return nullptr;

    ListNode* head = new ListNode(nums[0]);
    ListNode* curr = head;

    for (int i = 1; i < nums.size(); i++) {
        curr->next = new ListNode(nums[i]);
        curr = curr->next;
    }

    return head;
}

void printList(ListNode* head) {
    while (head) {
        cout << head->val;
        if (head->next) cout << " -> ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    Solution s;

    vector<int> nums = {18, 6, 10, 3};

    ListNode* head = createList(nums);
    printList(head);

    head = s.insertGreatestCommonDivisors(head);
    printList(head);

    return 0;
}