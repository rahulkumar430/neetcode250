#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    // Optimal solution - Time complexity : O(N), Space complexity : O(N)
    string simplifyPath(string path) {
        // You can either take stack or an vector will do the same thing
        stack<string> st;
        string ans = "";
        int idx = 0;

        while (idx < path.length()) {
            // Skip consecutive '/'
            if (path[idx] == '/') {
                idx++;
                continue;
            }

            // Find next '/'
            size_t pos = path.find("/", idx);
            if (pos == string::npos) {
                pos = path.length();
            }

            // Extract directory name
            string folder = path.substr(idx, pos - idx);

            // Apply Unix path rules
            if (folder == "..") {
                // Go to parent directory only if possible
                if (!st.empty()) {
                    st.pop();
                }
            } else if (folder != ".") {
                // Ignore current directory "."
                st.push(folder);
            }

            // Move index past this folder
            idx = pos + 1;
        }

        // Build canonical path from stack
        while (!st.empty()) {
            ans = "/" + st.top() + ans;
            st.pop();
        }

        // If empty, return root
        return ans.empty() ? "/" : ans;
    }

    // Using path as stringstream
    // string simplifyPath(string path) {
    //     stack<string> st;
    //     string token;

    //     // Create a stringstream from the path
    //     stringstream ss(path);

    //     // Split path by '/'
    //     while (getline(ss, token, '/')) {
    //         // Ignore empty tokens and current directory
    //         if (token.empty() || token == ".") {
    //             continue;
    //         }

    //         // Parent directory: pop if possible
    //         if (token == "..") {
    //             if (!st.empty()) {
    //                 st.pop();
    //             }
    //         }
    //         // Valid directory name
    //         else {
    //             st.push(token);
    //         }
    //     }

    //     // Build the canonical path
    //     string result = "";
    //     while (!st.empty()) {
    //         result = "/" + st.top() + result;
    //         st.pop();
    //     }

    //     // Return root if empty
    //     return result.empty() ? "/" : result;
    // }
};

int main() {
    Solution s;
    string path = "/neetcode/practice//...///../courses";
    cout << s.simplifyPath(path) << endl;

    return 0;
}