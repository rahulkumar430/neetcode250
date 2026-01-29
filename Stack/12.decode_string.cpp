#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    // Optimal solution using single stack - Time complexity : O(N), Space complexity : O(N)
    string decodeString(string s) {
        stack<string> st;

        for (int i = 0; i < s.length(); i++) {
            // When closing bracket is found
            if (s[i] == ']') {
                string curr = "";

                // Extract the encoded string
                while (!st.empty() && st.top() != "[") {
                    curr = st.top() + curr;
                    st.pop();
                }

                // Remove '['
                st.pop();

                // Extract number (can be multi-digit)
                string numStr = "";
                while (!st.empty() && isdigit(st.top()[0])) {
                    numStr = st.top() + numStr;
                    st.pop();
                }

                int repeat = stoi(numStr);

                // Repeat the decoded string
                string expanded = "";
                while (repeat--) {
                    expanded += curr;
                }

                // Push back to stack
                st.push(expanded);
            } else {
                // Push characters as strings
                st.push(string(1, s[i]));
            }
        }

        // Build final answer
        string ans = "";
        while (!st.empty()) {
            ans = st.top() + ans;
            st.pop();
        }

        return ans;
    }
    // Optimised approach using two stacks - Time complexity : O(N), Space complexity : O(N)
    // string decodeString(string s) {
    //     stack<int> countStack;      // stores repetition counts
    //     stack<string> stringStack;  // stores previous strings

    //     string curr = "";
    //     int num = 0;

    //     for (char ch : s) {
    //         // Build the number (handles multi-digit numbers)
    //         if (isdigit(ch)) {
    //             num = num * 10 + (ch - '0');
    //         }

    //         // Opening bracket: save state
    //         else if (ch == '[') {
    //             countStack.push(num);
    //             stringStack.push(curr);

    //             // Reset for the substring inside brackets
    //             num = 0;
    //             curr = "";
    //         }

    //         // Closing bracket: decode
    //         else if (ch == ']') {
    //             int repeat = countStack.top();
    //             countStack.pop();

    //             string prev = stringStack.top();
    //             stringStack.pop();

    //             // Repeat current string
    //             while (repeat--) {
    //                 prev += curr;
    //             }

    //             curr = prev;
    //         }

    //         // Normal character
    //         else {
    //             curr += ch;
    //         }
    //     }

    //     return curr;
    // }
};

int main() {
    Solution s;
    string str = "2[a3[b]]c";
    cout << s.decodeString(str) << endl;

    return 0;
}