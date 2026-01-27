#include <bits/stdc++.h>
using namespace std;

// Using 2 queue
// class MyStack {
//    private:
//     queue<int> q1, q2;

//    public:
//     // Constructor
//     MyStack() {}

//     // Push element onto stack (O(1))
//     void push(int x) {
//         q1.push(x);
//     }

//     // Removes and returns the top element (O(N))
//     int pop() {
//         // if (q1.empty()) {
//         //     throw runtime_error("Stack is empty");
//         // }

//         // Move all elements except the last to q2
//         while (q1.size() > 1) {
//             q2.push(q1.front());
//             q1.pop();
//         }

//         // Last element is the stack top
//         int topElement = q1.front();
//         q1.pop();

//         // Swap queues so q1 again holds the stack
//         swap(q1, q2);

//         return topElement;
//     }

//     // Returns the top element without removing it (O(N))
//     int top() {
//         // if (q1.empty()) {
//         //     throw runtime_error("Stack is empty");
//         // }

//         // Move all elements except the last to q2
//         while (q1.size() > 1) {
//             q2.push(q1.front());
//             q1.pop();
//         }

//         // Get the top element
//         int topElement = q1.front();
//         q1.pop();

//         // Push it back to maintain stack state
//         q2.push(topElement);

//         // Restore q1
//         swap(q1, q2);

//         return topElement;
//     }

//     // Checks whether the stack is empty
//     bool empty() {
//         return q1.empty();
//     }
// };

// Using 2 queue
class MyStack {
   private:
    queue<int> q1, q2;

   public:
    MyStack() {}

    // Push element onto stack (O(N))
    void push(int x) {
        // Push new element into empty q2 queue
        q2.push(x);

        // Move all existing elements behind it
        while (!q1.empty()) {
            q2.push(q1.front());
            q1.pop();
        }

        // Swap queues so q always has stack order
        swap(q1, q2);
    }

    // Removes and returns top element (O(1))
    int pop() {
        // if (q1.empty()) {
        //     throw runtime_error("Stack is empty");
        // }
        int topElement = q1.front();
        q1.pop();
        return topElement;
    }

    // Returns top element without removing (O(1))
    int top() {
        // if (q1.empty()) {
        //     throw runtime_error("Stack is empty");
        // }
        return q1.front();
    }

    // Checks if stack is empty (O(1))
    bool empty() {
        return q1.empty();
    }
};

// Using one queue only
// class MyStack {
//    private:
//     queue<int> q;

//    public:
//     MyStack() {}

//     // Push element onto stack (O(N))
//     void push(int x) {
//         int size = q.size();

//         // Push new element
//         q.push(x);

//         // Rotate previous elements behind it
//         for (int i = 0; i < size; i++) {
//             q.push(q.front());
//             q.pop();
//         }
//     }

//     // Removes and returns the top element (O(1))
//     int pop() {
//         // if (q.empty()) {
//         //     throw runtime_error("Stack is empty");
//         // }
//         int topElement = q.front();
//         q.pop();
//         return topElement;
//     }

//     // Returns the top element without removing (O(1))
//     int top() {
//         // if (q.empty()) {
//         //     throw runtime_error("Stack is empty");
//         // }
//         return q.front();
//     }

//     // Checks whether the stack is empty (O(1))
//     bool empty() {
//         return q.empty();
//     }
// };

int main() {
    MyStack st;

    st.push(10);
    st.push(20);
    st.push(30);

    cout << "Top: " << st.top() << endl;         // 30
    cout << "Pop: " << st.pop() << endl;         // 30
    cout << "Top: " << st.top() << endl;         // 20
    cout << "Is empty: " << st.empty() << endl;  // 0 (false)

    st.pop();
    st.pop();

    cout << "Is empty after pops: " << st.empty() << endl;  // 1 (true)

    return 0;
}
