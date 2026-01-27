#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    // Time & Space Complexity - O(N)
    // int calPoints(vector<string>& operations) {
    //     vector<int> record;  // Stack to store scores
    //     int sum = 0;

    //     for (string str : operations) {
    //         // Add last two scores
    //         if (str[0] == '+') {
    //             record.push_back(record.back() + record[record.size() - 2]);
    //         }
    //         // Double last score
    //         else if (str[0] == 'D') {
    //             record.push_back(record.back() * 2);
    //         }
    //         // Remove last score
    //         else if (str[0] == 'C') {
    //             record.pop_back();

    //         }
    //         // Numeric value
    //         else {
    //             record.push_back(stoi(str));
    //         }
    //     }

    //     // Total score
    //     for (int x : record) sum += x;

    //     return sum;
    // }

    // Time & Space Complexity - O(N)
    int calPoints(vector<string>& operations) {
        stack<int> st;  // Stack to store valid scores
        int sum = 0;

        for (string str : operations) {
            if (str == "+") {
                // Sum of last two scores
                int top1 = st.top();
                st.pop();
                int top2 = st.top();
                st.push(top1);  // Restore top
                st.push(top1 + top2);
            } else if (str == "D") {
                // Double last score
                st.push(st.top() * 2);
            } else if (str == "C") {
                // Remove last score
                st.pop();
            } else {
                // Numeric value (multi-digit or negative)
                st.push(stoi(str));
            }
        }

        // Sum all scores
        while (!st.empty()) {
            sum += st.top();
            st.pop();
        }

        return sum;
    }
};

int main() {
    vector<string> operations = {"1", "2", "+", "C", "5", "D"};

    Solution sol;

    cout << sol.calPoints(operations) << endl;

    return 0;
}