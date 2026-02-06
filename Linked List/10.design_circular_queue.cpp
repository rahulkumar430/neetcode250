#include <bits/stdc++.h>
using namespace std;

// Brute force approach - Using vector
// O(1) Time for everything except deQueue which takes O(N) due to shifting
// class MyCircularQueue {
//    private:
//     vector<int> v;
//     int maxSize = 0;  // max capacity

//    public:
//     MyCircularQueue(int k) {
//         maxSize = k;
//     }

//     bool enQueue(int value) {
//         if (v.size() == maxSize) {
//             return false;
//         }
//         v.push_back(value);
//         return true;
//     }

//     bool deQueue() {
//         if (v.empty()) {
//             return false;
//         }
//         v.erase(v.begin());
//         return true;
//     }

//     int Front() {
//         return (v.empty() ? -1 : v.front());
//     }

//     int Rear() {
//         return (v.empty() ? -1 : v.back());
//     }

//     bool isEmpty() {
//         return v.empty();
//     }

//     bool isFull() {
//         return v.size() == maxSize;
//     }
// };

// Using Array with modulo operation - O(1) time for all operations
// It takes the least space amongst the other 2 solution
// class MyCircularQueue {
//    private:
//     vector<int> q;  // fixed-size array
//     int front;      // index of front element
//     int rear;       // index of last element
//     int size;       // current number of elements
//     int maxSize;    // maximum size

//    public:
//     // Initialize circular queue with size k
//     MyCircularQueue(int k) {
//         q.resize(k);
//         maxSize = k;
//         front = 0;
//         rear = -1;
//         size = 0;
//     }

//     // Insert element at rear
//     bool enQueue(int value) {
//         if (isFull()) return false;

//         rear = (rear + 1) % maxSize;  // wrap around
//         q[rear] = value;
//         size++;

//         return true;
//     }

//     // Remove element from front
//     bool deQueue() {
//         if (isEmpty()) return false;

//         front = (front + 1) % maxSize;  // wrap around
//         size--;

//         return true;
//     }

//     // Get front element
//     int Front() {
//         return isEmpty() ? -1 : q[front];
//     }

//     // Get rear element
//     int Rear() {
//         return isEmpty() ? -1 : q[rear];
//     }

//     // Check if queue is empty
//     bool isEmpty() {
//         return size == 0;
//     }

//     // Check if queue is full
//     bool isFull() {
//         return size == maxSize;
//     }
// };

// Using Doubly Linked List - O(1) time for all operations
// class MyCircularQueue {
//    private:
//     struct ListNode {
//         int val;
//         ListNode* next;
//         ListNode* prev;
//         ListNode(int v = 0) : val(v), next(nullptr), prev(nullptr) {}
//     };

//     int size;         // current number of elements
//     int maxSize;      // max capacity
//     ListNode* left;   // dummy head (front side)
//     ListNode* right;  // dummy tail (rear side)

//    public:
//     MyCircularQueue(int k) {
//         maxSize = k;
//         size = 0;

//         // Create sentinel nodes
//         left = new ListNode();
//         right = new ListNode();

//         left->next = right;
//         right->prev = left;
//     }

//     // Insert at rear
//     bool enQueue(int value) {
//         if (isFull()) return false;

//         // Insert before right sentinel
//         ListNode* node = new ListNode(value);
//         node->prev = right->prev;
//         node->next = right;

//         right->prev->next = node;
//         right->prev = node;

//         size++;
//         return true;
//     }

//     // Remove from front
//     bool deQueue() {
//         if (isEmpty()) return false;

//         // Remove node after left sentinel
//         ListNode* node = left->next;
//         left->next = node->next;
//         node->next->prev = left;

//         delete node;  // free memory
//         size--;
//         return true;
//     }

//     // Get front element
//     int Front() {
//         return isEmpty() ? -1 : left->next->val;
//     }

//     // Get rear element
//     int Rear() {
//         return isEmpty() ? -1 : right->prev->val;
//     }

//     bool isEmpty() {
//         return size == 0;
//     }

//     bool isFull() {
//         return size == maxSize;
//     }
// };

// Using Singly Linked List - O(1) time for all operations
class MyCircularQueue {
   private:
    struct ListNode {
        int val;
        ListNode* next;
        ListNode(int v) : val(v), next(nullptr) {}
    };

    int size;        // current number of elements
    int maxSize;     // max allowed size
    ListNode* head;  // front of queue
    ListNode* tail;  // rear of queue

   public:
    // Initialize queue with size k
    MyCircularQueue(int k) {
        maxSize = k;
        size = 0;
        head = nullptr;
        tail = nullptr;
    }

    // Insert element at rear
    bool enQueue(int value) {
        if (isFull()) return false;

        ListNode* node = new ListNode(value);

        if (isEmpty()) {
            head = tail = node;  // first element
        } else {
            tail->next = node;  // attach at rear
            tail = node;
        }

        size++;
        return true;
    }

    // Remove element from front
    bool deQueue() {
        if (isEmpty()) return false;

        ListNode* temp = head;
        head = head->next;  // move front forward
        delete temp;

        if (head == nullptr) {
            tail = nullptr;  // queue became empty
        }

        size--;
        return true;
    }

    // Get front element
    int Front() {
        return isEmpty() ? -1 : head->val;
    }

    // Get rear element
    int Rear() {
        return isEmpty() ? -1 : tail->val;
    }

    bool isEmpty() {
        return size == 0;
    }

    bool isFull() {
        return size == maxSize;
    }
};

int main() {
    MyCircularQueue myCircularQueue(3);
    cout << myCircularQueue.enQueue(1) << endl;  // return True
    cout << myCircularQueue.enQueue(2) << endl;  // return True
    cout << myCircularQueue.enQueue(3) << endl;  // return True
    cout << myCircularQueue.enQueue(4) << endl;  // return False
    cout << myCircularQueue.Rear() << endl;      // return 3
    cout << myCircularQueue.isFull() << endl;    // return True
    cout << myCircularQueue.deQueue() << endl;   // return True
    cout << myCircularQueue.enQueue(4) << endl;  // return True
    cout << myCircularQueue.Rear() << endl;      // return 4
}