#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    // Optimised solution using stack - Time & Space Complexity: O(N)
    int evalRPN(vector<string>& tokens) {
        stack<int> st;

        for (const string& token : tokens) {
            // If token is an operator
            if (token == "+" || token == "-" || token == "*" || token == "/") {
                int b = st.top();
                st.pop();  // second operand
                int a = st.top();
                st.pop();  // first operand

                if (token == "+") {
                    st.push(a + b);
                } else if (token == "-") {
                    st.push(a - b);
                } else if (token == "*") {
                    st.push(a * b);
                } else {             // "/"
                    st.push(a / b);  // integer division
                }
            }
            // If token is a number
            else {
                st.push(stoi(token));
            }
        }

        // Final result is on top of stack
        return st.top();
    }
};

int main() {
    Solution s;

    vector<string> tokens = {"2", "1", "+", "3", "*"};
    cout << s.evalRPN(tokens) << endl;  // (2 + 1) * 3 = 9

    vector<string> tokens2 = {"4", "13", "5", "/", "+"};
    cout << s.evalRPN(tokens2) << endl;  // 4 + (13 / 5) = 6

    return 0;
}