#include <bits/stdc++.h>
using namespace std;

// Time Complexity: O(n), Space Complexity: O(n)
bool isAnagram(string s, string t) {
    if (s.size() != t.size())
        return false;

    unordered_map<char, int> count;

    // Count frequency of each character in s
    for (char c : s)
        count[c]++;

    // Subtract frequency for each character in t
    for (char c : t) {
        count[c]--;
        if (count[c] < 0)  // if any count goes negative, not an anagram
            return false;
    }

    return true;  // all counts are zero
}

// Time Complexity: O(n log n), Space Complexity: O(1)
// Another Approach
// bool isAnagram(string s, string t) {
//     // Sort both the string alphabetically and then compare
//     sort(s.begin(), s.end());
//     sort(t.begin(), t.end());
//     if (s == t)
//         return true;
//     else
//         return false;
// }

int main() {
    string s1 = "racecar";
    string s2 = "carrace";

    cout << (isAnagram(s1, s2) ? "true" : "false") << endl;
    return 0;
}