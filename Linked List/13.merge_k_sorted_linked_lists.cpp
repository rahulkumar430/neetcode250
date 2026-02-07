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

    // Recursively merge lists in range [l, r]
    ListNode* mergeRange(vector<ListNode*>& lists, int l, int r) {
        // Base case: invalid range
        if (l > r) return nullptr;

        // Base case: single list in range
        if (l == r) return lists[l];

        // Divide: find middle point
        int mid = l + (r - l) / 2;

        ListNode* left = mergeRange(lists, l, mid);       // Conquer : recursively merge left half
        ListNode* right = mergeRange(lists, mid + 1, r);  // Conquer : recursively merge right half

        // Combine: merge the two halves
        return mergeTwoLists(left, right);
    }

   public:
    // Brute force approach
    // Time Complexity: O(N * K)
    // Space Complexity: O(1) (excluding input/output)
    // ListNode* mergeKLists(vector<ListNode*>& lists) {
    //     if (lists.empty()) return nullptr;

    //     // Start with first list
    //     ListNode* mergedList = lists[0];

    //     // Merge remaining lists one by one
    //     for (int i = 1; i < lists.size(); i++) {
    //         mergedList = mergeTwoLists(mergedList, lists[i]);
    //     }

    //     return mergedList;
    // }

    // Very brute-force solution using vector sort
    // Time Complexity: O(N log N)
    // Space Complexity: O(N)
    // ListNode* mergeKLists(vector<ListNode*>& lists) {
    //     vector<int> values;

    //     // Step 1: Collect all values from all lists
    //     for (ListNode* head : lists) {
    //         while (head != nullptr) {
    //             values.push_back(head->val);
    //             head = head->next;
    //         }
    //     }

    //     // If no elements exist
    //     if (values.empty()) return nullptr;

    //     // Step 2: Sort all values
    //     sort(values.begin(), values.end());

    //     // Step 3: Build new linked list from sorted values
    //     ListNode* dummy = new ListNode(0);
    //     ListNode* curr = dummy;

    //     for (int val : values) {
    //         curr->next = new ListNode(val);
    //         curr = curr->next;
    //     }

    //     return dummy->next;
    // }

    // Optimal Appraoch using Divide and Conquer Method
    // Time: O(N log K)
    // Space: O(log K)
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.empty()) return nullptr;
        return mergeRange(lists, 0, lists.size() - 1);
    }

    // Optimal solution using Min Heap
    // Time: O(N log K)
    // Space: O(K)
    // ListNode* mergeKLists(vector<ListNode*>& lists) {
    //     // Min heap (max heap with inverted comparator) to track smallest nodes
    //     priority_queue<ListNode*, vector<ListNode*>,
    //                    function<bool(ListNode*, ListNode*)>>
    //         pq(
    //             [](ListNode* a, ListNode* b) {
    //                 return a->val > b->val;  // Min-heap: smaller values have higher priority
    //             });

    //     // Insert all list heads into the heap
    //     for (auto list : lists) {
    //         if (list != nullptr) {
    //             pq.push(list);
    //         }
    //     }

    //     ListNode dummy(0);
    //     ListNode* tail = &dummy;

    //     // Repeatedly extract min node and add its successor
    //     while (!pq.empty()) {
    //         ListNode* node = pq.top();
    //         pq.pop();

    //         tail->next = node;
    //         tail = tail->next;

    //         // Push next node if it exists
    //         if (node->next != nullptr) {
    //             pq.push(node->next);
    //         }
    //     }

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
    vector<vector<int>> lists = {{1, 2, 4}, {1, 3, 5}, {3, 6}};
    // Convert vector of vectors to vector of ListNodes
    vector<ListNode*> listNodes;
    for (auto& vec : lists) {
        listNodes.push_back(vectorToList(vec));
    }

    Solution sol;
    ListNode* result = sol.mergeKLists(listNodes);

    printList(result);
    return 0;
}