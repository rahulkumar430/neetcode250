#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int calPoints(vector<string>& operations) {
        vector<int> record;  // Stack to store scores
        int sum = 0;

        for (string str : operations) {
            // Numeric value (supports multi-digit and negative)
            if ((str[0] >= '0' && str[0] <= '9') || str[0] == '-') {
                record.push_back(stoi(str));
            }
            // Add last two scores
            else if (str[0] == '+') {
                record.push_back(record.back() + record[record.size() - 2]);
            }
            // Double last score
            else if (str[0] == 'D') {
                record.push_back(record.back() * 2);
            }
            // Remove last score
            else if (str[0] == 'C') {
                record.pop_back();
            }
        }

        // Total score
        for (int x : record) sum += x;

        return sum;
    }
};

int main() {
    vector<string> operations = {"1", "2", "+", "C", "5", "D"};

    Solution sol;

    cout << sol.calPoints(operations) << endl;

    return 0;
}