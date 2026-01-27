#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    // Stack-based solution
    // Time & Space Complexity: O(N)
    bool isValid(string s) {
        stack<char> st;  // Stack to store opening brackets

        for (char c : s) {
            // Push opening brackets
            if (c == '(' || c == '{' || c == '[') {
                st.push(c);
            }
            // Handle closing brackets
            else {
                // If stack is empty, no matching opening bracket
                if (st.empty()) return false;

                // Check for matching pair
                if ((c == ')' && st.top() != '(') ||
                    (c == '}' && st.top() != '{') ||
                    (c == ']' && st.top() != '[')) {
                    return false;
                }

                // Valid match found
                st.pop();
            }
        }

        // Stack should be empty if all brackets matched
        return st.empty();
    }
};

int main() {
    string s = "([{}])";

    Solution sol;

    cout << (sol.isValid(s) ? "true" : "false") << endl;

    return 0;
}