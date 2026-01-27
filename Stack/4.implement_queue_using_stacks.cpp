#include <bits/stdc++.h>
using namespace std;

// Brute force solution using two stacks
// class MyQueue {
//    private:
//     stack<int> s1;  // Maintains queue order (top = front)
//     stack<int> s2;  // Helper stack

//    public:
//     MyQueue() {}

//     // Push element to back of queue (O(1))
//     void push(int x) {
//         s1.push(x);
//     }

//     // Removes and returns front element (O(N) every time)
//     int pop() {
//         // if (empty()) {
//         //     throw runtime_error("Queue is empty");
//         // }

//         // Move all except the bottom (front) element to s2
//         while (s1.size() > 1) {
//             s2.push(s1.top());
//             s1.pop();
//         }

//         // Bottom element of s1 is the front of the queue
//         int frontElement = s1.top();
//         s1.pop();

//         // Restore original order
//         while (!s2.empty()) {
//             s1.push(s2.top());
//             s2.pop();
//         }

//         return frontElement;
//     }

//     // Returns front element without removing it (O(N))
//     int peek() {
//         // if (empty()) {
//         //     throw runtime_error("Queue is empty");
//         // }

//         // Move all except the bottom element to s2
//         while (s1.size() > 1) {
//             s2.push(s1.top());
//             s1.pop();
//         }

//         int frontElement = s1.top();

//         // Put front element back
//         s2.push(frontElement);
//         s1.pop();

//         // Restore order
//         while (!s2.empty()) {
//             s1.push(s2.top());
//             s2.pop();
//         }

//         return frontElement;
//     }

//     // Checks whether queue is empty (O(1))
//     bool empty() {
//         return s1.empty();
//     }
// };

// Amortized Solution using two stacks
class MyQueue {
   private:
    stack<int> s1;  // Used for push operations
    stack<int> s2;  // Used for pop and peek operations

    // Transfers elements from s1 to s2 if needed
    void moveIfNeeded() {
        if (s2.empty()) {
            while (!s1.empty()) {
                s2.push(s1.top());
                s1.pop();
            }
        }
    }

   public:
    MyQueue() {}

    // Push element to the back of queue (O(1))
    void push(int x) {
        s1.push(x);
    }

    // Removes and returns the front element (O(1) amortized)
    int pop() {
        // if (empty()) {
        //     throw runtime_error("Queue is empty");
        // }

        moveIfNeeded();
        int frontElement = s2.top();
        s2.pop();
        return frontElement;
    }

    // Returns the front element without removing it (O(1) amortized)
    int peek() {
        // if (empty()) {
        //     throw runtime_error("Queue is empty");
        // }

        moveIfNeeded();
        return s2.top();
    }

    // Checks whether the queue is empty (O(1))
    bool empty() {
        return s1.empty() && s2.empty();
    }
};

int main() {
    MyQueue q;

    q.push(1);
    q.push(2);
    q.push(3);

    cout << "Front: " << q.peek() << endl;  // 1
    cout << "Pop: " << q.pop() << endl;     // 1
    cout << "Front: " << q.peek() << endl;  // 2

    q.pop();
    q.pop();

    cout << "Is empty: " << q.empty() << endl;  // 1 (true)

    return 0;
}

/*
IMPORTANT NOTE :
“Amortisation works for queue using stacks because elements are reversed once and never touched again. For stack using queues, every push changes the top, forcing a full rearrangement, so work cannot be reused.”
*/