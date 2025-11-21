#include <bits/stdc++.h>
using namespace std;

string longestCommonPrefix(vector<string>& strs) {
    if (strs.size() == 0)
        return "";
    int i, j;
    string lcp = "";
    char curr_char;
    for (i = 0; i < strs[0].size(); i++) {
        // checking characters of words in strs at position i
        curr_char = strs[0][i];
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