#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    // Naive Solution
    // string encode(vector<string>& strs) {
    //     string ans;
    //     string del = "é";  // Non ASCII Character
    //     for (string str : strs) {
    //         ans += str + del;
    //     }
    //     return ans;
    // }

    // vector<string> decode(string s) {
    //     vector<string> ans;

    //     string del = "é";  // Delimiter

    //     // Splitting the str string by delimiter
    //     size_t pos = 0;
    //     while ((pos = s.find(del)) != string::npos) {
    //         ans.push_back(s.substr(0, pos));  // Everything before delimiter
    //         s.erase(0, pos + del.length());   // Remove processed part
    //     }
    //     return ans;
    // }

    // Optimised Solution
    string encode(vector<string>& strs) {
        string ans;

        // For each string: "<length>#<string>"
        for (string str : strs) {
            // Convert length to string (handles 0, 1, 2+ digits automatically)
            // Add '#' separator, then the string itself
            ans += to_string(str.length()) + "#" + str;
        }

        return ans;
    }

    vector<string> decode(string s) {
        vector<string> ans;
        int i = 0;  // Current position in string

        // Process until end of encoded string
        while (i < s.length()) {
            // Find length - read digits until '#' separator
            int start = i;
            while (i < s.length() && s[i] != '#') {
                i++;
            }
            // Parse length from digits: e.g., "12" → 12
            int len = stoi(s.substr(start, i - start));

            // Skip '#' and read exactly 'len' characters
            i++;  // Skip the '#' separator
            string str = s.substr(i, len);
            ans.push_back(str);

            // Move past the string to next length prefix
            i += len;
        }

        return ans;
    }
};

int main() {
    Solution sol;
    vector<string> strs = {"we", "say", ":", "yes"};

    string encoded = sol.encode(strs);
    cout << "Encoded: " << encoded << endl;

    vector<string> decoded = sol.decode(encoded);

    cout << "Decoded: ";
    for (auto str : decoded) {
        cout << "'" << str << "' ";
    }
    cout << endl;
    return 0;
}
