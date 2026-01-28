#include <bits/stdc++.h>
using namespace std;

// Optimised solution using two stacks
class MinStack {
   private:
    stack<int> s;     // Main stack (stores values)
    stack<int> minS;  // Min stack (stores current minimums)

   public:
    MinStack() {}

    // Push value onto stack
    void push(int val) {
        s.push(val);

        // Push to min stack if it's empty or val is new minimum
        if (minS.empty() || val <= minS.top()) {
            minS.push(val);
        }
    }

    // Removes the top element
    void pop() {
        // if (s.empty()) {
        //     throw runtime_error("Stack is empty");
        // }

        // If top element is current minimum, pop from min stack too
        if (s.top() == minS.top()) {
            minS.pop();
        }
        s.pop();
    }

    // Returns top element
    int top() {
        // if (s.empty()) {
        //     throw runtime_error("Stack is empty");
        // }
        return s.top();
    }

    // Returns minimum element in stack
    int getMin() {
        // if (minS.empty()) {
        //     throw runtime_error("Stack is empty");
        // }
        return minS.top();
    }

    // Brute force solution for minStack if using only one stack above
    // int getMin() {
    //     stack<int> tmp;
    //     int minValue = s.top();
    //     while (s.size()) {
    //         minValue = min(minValue, s.top());
    //         tmp.push(s.top());
    //         s.pop();
    //     }

    //     while (tmp.size()) {
    //         s.push(tmp.top());
    //         tmp.pop();
    //     }

    //     return minValue;
    // }
};

// Most optmised solution using only one stack
// Encode values smaller than the current minimum so that restore the previous minimum during pop
// class MinStack {
//    private:
//     stack<long long> s;  // Use long long to avoid overflow
//     long long minVal;

//    public:
//     MinStack() {}

//     // Push value onto stack
//     void push(int val) {
//         if (s.empty()) {
//             s.push(val);
//             minVal = val;
//         } else if (val >= minVal) {
//             s.push(val);
//         } else {
//             // Encode value
//             // Since val < oldMin:(add val ob bth side and take oldMin to the lhs) 2 * val - oldMin < val
//             // so 2 * cal - oldMin becomes the encoded value which will be small than the val(which is the new minValue)
//             long long encoded = 2LL * val - minVal;
//             s.push(encoded);
//             minVal = val;
//         }
//     }

//     // Remove top element
//     void pop() {
//         // if (s.empty()) {
//         //     throw runtime_error("Stack is empty");
//         // }

//         long long topVal = s.top();
//         s.pop();

//         // If encoded, restore previous minimum using the same formula above to encode the new minimum using oldMin
//         // where encoded value is the topVal and oldMin = 2 * Current Minmum - encoded
//         if (topVal < minVal) {
//             minVal = 2LL * minVal - topVal;
//         }
//     }

//     // Return top element
//     int top() {
//         // if (s.empty()) {
//         //     throw runtime_error("Stack is empty");
//         // }

//         long long topVal = s.top();
//         if (topVal >= minVal) {
//             return (int)topVal;
//         }
//         return (int)minVal;
//     }

//     // Return minimum element
//     int getMin() {
//         // if (s.empty()) {
//         //     throw runtime_error("Stack is empty");
//         // }
//         return (int)minVal;
//     }
// };

int main() {
    MinStack minStack;
    minStack.push(1);
    minStack.push(2);
    minStack.push(0);
    cout << minStack.getMin() << endl;  // return 0
    minStack.pop();
    cout << minStack.top() << endl;     // return 2
    cout << minStack.getMin() << endl;  // return 1

    return 0;
}