#include <bits/stdc++.h>
using namespace std;

// Brute force approach
// Time Complexity: O(n*m), Space Complexity: O(1), n = number of strings & m = length of the longest string
string longestCommonPrefix(vector<string>& strs) {
    if (strs.size() == 0)
        return "";
    string lcp = "";
    char curr_char;
    for (int i = 0; i < strs[0].size(); i++) {
        // checking characters of words in strs at position i
        curr_char = strs[0][i];
        int j;
        for (j = 0; j < strs.size(); j++) {
            if (strs[j][i] != curr_char)
                break;
        }
        // all the characters were equal
        if (j == strs.size())
            lcp += curr_char;
        else
            break;
    }
    return lcp;
}

int main() {
    vector<string> strs = {"bat", "bag", "bank", "band"};
    string prefix = longestCommonPrefix(strs);

    cout << prefix << endl;
    return 0;
}