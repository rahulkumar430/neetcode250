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
    // Using HashSet to store the node addresses - Time Complexity: O(N), Space Complexity: O(N)
    // bool hasCycle(ListNode* head) {
    //     // HashSet to store addresses of visited nodes
    //     unordered_set<ListNode*> visited;

    //     ListNode* curr = head;

    //     // Traverse the linked list
    //     while (curr != nullptr) {
    //         // If this node's address is already in the set,
    //         // we have visited it before → cycle exists
    //         if (visited.count(curr)) {
    //             return true;
    //         }

    //         // Mark current node as visited
    //         visited.insert(curr);

    //         // Move to next node
    //         curr = curr->next;
    //     }

    //     // If we reach nullptr, no cycle exists
    //     return false;
    // }

    // Optimal Fast & Slow Pointer Approach - Time Complexity: O(N), Space Complexity: O(1)
    bool hasCycle(ListNode* head) {
        // If list is empty or has only one node, no cycle
        if (head == nullptr || head->next == nullptr) {
            return false;
        }

        // Slow moves 1 step, fast moves 2 steps
        ListNode* slow = head;
        ListNode* fast = head;

        // Traverse while fast pointer can move
        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;        // move slow by 1
            fast = fast->next->next;  // move fast by 2

            // If they meet, cycle exists
            if (slow == fast) {
                return true;
            }
        }

        // Fast reached null → no cycle
        return false;
    }
};

// Helper to create a linked list with a cycle
ListNode* createListWithCycle(int arr[], int n, int index) {
    if (n == 0) return nullptr;

    ListNode* head = new ListNode(arr[0]);
    ListNode* curr = head;
    ListNode* cycleNode = nullptr;

    if (index == 0) cycleNode = head;

    for (int i = 1; i < n; i++) {
        curr->next = new ListNode(arr[i]);
        curr = curr->next;

        if (i == index) {
            cycleNode = curr;
        }
    }

    // Create cycle if index != -1
    if (index != -1) {
        curr->next = cycleNode;
    }

    return head;
}

int main() {
    int arr[] = {1, 2, 3, 4};
    int n = 4;
    int index = -1;  // cycle starts at node with value 2

    ListNode* head = createListWithCycle(arr, n, index);

    Solution sol;
    bool result = sol.hasCycle(head);

    cout << (result ? "true" : "false") << endl;

    return 0;
}