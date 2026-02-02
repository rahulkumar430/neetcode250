#include <bits/stdc++.h>
using namespace std;

class TimeMap {
   private:
    // key -> {timestamp, value}
    unordered_map<string, vector<pair<int, string>>> map;

   public:
    TimeMap() {
    }
    // Time Complexity : O(1) amortized
    void set(string key, string value, int timestamp) {
        map[key].push_back({timestamp, value});
    }
    // Time Complexity : O(log N)
    string get(string key, int timestamp) {
        // Reference to avoid copying the vector for this key
        auto& temp = map[key];

        // If no values exist for this key, return empty string
        if (temp.empty()) return "";
        string result = "";
        int l = 0;
        int r = temp.size() - 1;

        // Binary search to find the largest timestamp <= given timestamp
        while (l <= r) {
            int mid = l + (r - l) / 2;

            // Current timestamp is valid (<= target),
            // so move right to try finding a larger valid timestamp
            if (temp[mid].first <= timestamp) {
                result = temp[mid].second;
                l = mid + 1;
            }
            // Current timestamp is too large,
            // discard the right half
            else {
                r = mid - 1;
            }
        }

        return result;
    }

    // STL version of get - Time Complexity : O(log N)
    // string get(string key, int timestamp) {
    //     // Reference to avoid copying the vector for this key
    //     auto& temp = map[key];

    //     auto it = upper_bound(
    //         temp.begin(), temp.end(), timestamp,
    //         [](int t, const pair<int, string>& p) {
    //             return t < p.first;
    //         });

    //     if (it == temp.begin()) return "";
    //     return prev(it)->second;
    // }
};

// class TimeMap {
//    private:
//     // key -> (timestamp -> value)
//     unordered_map<string, map<int, string>> mp;

//    public:
//     TimeMap() {}

//     // Time Complexity : O(log N)
//     // Store the value for a key at a given timestamp
//     void set(string key, string value, int timestamp) {
//         mp[key][timestamp] = value;
//     }

//     // Time Complexity : O(log N)
//     // Retrieve the value with the largest timestamp <= given timestamp
//     string get(string key, int timestamp) {
//         auto it = mp[key].upper_bound(timestamp);
//         return it == mp[key].begin() ? "" : prev(it)->second;
//     }
// };

int main() {
    TimeMap timeMap;
    timeMap.set("alice", "happy", 1);         // store the key "alice" and value "happy" along with timestamp = 1.
    cout << timeMap.get("alice", 1) << endl;  // return "happy"
    cout << timeMap.get("alice", 2) << endl;  // return "happy", there is no value stored for timestamp 2, thus we return the value at timestamp 1.
    timeMap.set("alice", "sad", 3);           // store the key "alice" and value "sad" along with timestamp = 3.
    cout << timeMap.get("alice", 3) << endl;  // return "sad"

    return 0;
}
