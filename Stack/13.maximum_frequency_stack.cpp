#include <bits/stdc++.h>
using namespace std;

// Brute Force way : Time Complexity for push O(1) & pop O(N)
// Total(N ops) O(N^2)
// class FreqStack {
//    private:
//     vector<int> st;                // acts like stack
//     unordered_map<int, int> freq;  // value -> frequency

//    public:
//     FreqStack() {}

//     void push(int val) {
//         st.push_back(val);
//         freq[val]++;
//     }

//     int pop() {
//         // Step 1: find max frequency
//         int maxFreq = 0;
//         for (auto& p : freq) {
//             maxFreq = max(maxFreq, p.second);
//         }

//         // Step 2: find most recent element with max frequency
//         for (int i = st.size() - 1; i >= 0; i--) {
//             int val = st[i];
//             if (freq[val] == maxFreq) {
//                 // Remove from stack
//                 st.erase(st.begin() + i);

//                 // Update frequency
//                 freq[val]--;
//                 if (freq[val] == 0) {
//                     freq.erase(val);
//                 }

//                 return val;
//             }
//         }

//         return -1;  // should never reach here
//     }
// };

// Optimised Approach using Stack of stack & HashMap
// Time Complexity O(1) for push and pop, Space Complexity is O(N)
class FreqStack {
   private:
    unordered_map<int, int> freq;          // val -> frequency
    unordered_map<int, stack<int>> group;  // frequency -> stack of values/stack
    int maxFreq = 0;

   public:
    FreqStack() {}

    void push(int val) {
        int f = ++freq[val];        // increment frequency
        maxFreq = max(maxFreq, f);  // update max frequency
        group[f].push(val);         // push value into its frequency group
    }

    int pop() {
        int val = group[maxFreq].top();
        group[maxFreq].pop();

        freq[val]--;  // decrement frequency

        // If no elements left at this frequency, reduce maxFreq
        if (group[maxFreq].empty()) {
            maxFreq--;
        }

        return val;
    }
};

int main() {
    FreqStack freqStack;

    freqStack.push(5);                // The stack is [5]
    freqStack.push(7);                // The stack is [5,7]
    freqStack.push(5);                // The stack is [5,7,5]
    freqStack.push(7);                // The stack is [5,7,5,7]
    freqStack.push(4);                // The stack is [5,7,5,7,4]
    freqStack.push(5);                // The stack is [5,7,5,7,4,5]
    cout << freqStack.pop() << endl;  // return 5, as 5 is the most frequent. The stack becomes [5,7,5,7,4].
    cout << freqStack.pop() << endl;  // return 7, as 5 and 7 is the most frequent, but 7 is closest to the top. The stack becomes [5,7,5,4].
    cout << freqStack.pop() << endl;  // return 5, as 5 is the most frequent. The stack becomes [5,7,4].
    cout << freqStack.pop() << endl;  // return 4, as 4, 5 and 7 is the most frequent, but 4 is closest to the top. The stack becomes [5,7].
    return 0;
}