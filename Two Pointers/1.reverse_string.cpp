#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    // Basic approach O(n) time and space complexity
    // void reverseString(vector<char>& s) {
    //     vector<char> tmp;  // Temporary vector to store reversed characters

    //     // Traverse original string from end to start and push characters into tmp
    //     for (int i = s.size() - 1; i >= 0; i--) {
    //         tmp.push_back(s[i]);  // Append characters in reverse order
    //     }

    //     // Copy reversed characters back into the original vector
    //     for (int i = 0; i < s.size(); i++) {
    //         s[i] = tmp[i];  // Overwrite s with reversed content
    //     }
    // }

    // Built in function to use
    //  void reverseString(vector<char>& s) {
    //      reverse(s.begin(), s.end());
    //  }
    // Optmised O(N) Time and O(1) Space complexity with two pointers
    void reverseString(vector<char>& s) {
        int l = 0, r = s.size() - 1;  // l: left pointer, r: right pointer

        // Swap characters while left index is before right index
        while (l < r) {
            swap(s[l++], s[r--]);  // Swap current pair, then move l right and r left
        }
    }
};

int main() {
    Solution sol;
    vector<char> s = {'n', 'e', 'e', 't'};
    sol.reverseString(s);
    cout << string(s.begin(), s.end()) << endl;

    return 0;
}