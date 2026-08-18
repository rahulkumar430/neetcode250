#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    // Naive Base Conversion approach - Time Complexity : O(logN), Space Complexity : O(logN)
    string convertToTitle(int columnNumber) {
        string s = "";

        while (columnNumber > 0) {
            columnNumber--;  // Most Imp : Convert 1-26 to 0-25

            int r = columnNumber % 26;
            s += 'A' + r;  // Get the current column character

            columnNumber /= 26;
        }
        reverse(s.begin(), s.end());  // Characters are generated right-to-left
        return s;
    }
};

int main() {
    Solution s;
    int num = 704;

    cout << s.convertToTitle(num) << endl;
    return 0;
}