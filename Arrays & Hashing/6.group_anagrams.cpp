#include <bits/stdc++.h>
using namespace std;

vector<vector<string>> groupAnagrams(vector<string>& strs) {
    unordered_map<string, vector<string>> anagramMap;
    // Loop through entire vector and by sorting the whole string and put the original string in the same sorted key
    for (const string& s : strs) {
        string sortedS = s;
        sort(sortedS.begin(), sortedS.end());
        anagramMap[sortedS].push_back(s);
    }
    vector<vector<string>> result;
    // Push the whole vector inside each key two the result by traversing the map
    for (auto& entry : anagramMap) {
        result.push_back(entry.second);
    }
    return result;
}

int main() {
    vector<string> strs = {"act", "pots", "tops", "cat", "stop", "hat"};
    vector<vector<string>> result;

    result = groupAnagrams(strs);

    for (int i = 0; i < result.size(); i++) {
        cout << "[";
        for (int j = 0; j < result[i].size(); j++) {
            cout << "\"" << result[i][j] << "\"";
            if (j < result[i].size() - 1) cout << ", ";
        }
        cout << "]";
        if (i < result.size() - 1) cout << ",";
    }
    cout << endl;

    return 0;
}
