#include <bits/stdc++.h>
using namespace std;

// Bruteforce Approach
// Time Complexity: O(n), Space Complexity: O(n)
// class MyHashSet {
//    public:
//     vector<int> hashSet;

//     MyHashSet() {
//     }

//     void add(int key) {
//         auto it = find(hashSet.begin(), hashSet.end(), key);
//         if (it != hashSet.end()) {
//             return;  // Key already exists
//         } else {
//             cout << key << endl;  // Print key on addition
//             hashSet.push_back(key);
//         }
//     }

//     void remove(int key) {
//         auto it = find(hashSet.begin(), hashSet.end(), key);
//         if (it != hashSet.end()) {
//             hashSet.erase(it);
//         }
//     }

//     bool contains(int key) {
//         auto it = find(hashSet.begin(), hashSet.end(), key);
//         return it != hashSet.end();
//     }
// };

// Optimised Approach
// Time Complexity: O(1), Space Complexity: O(n)
class MyHashSet {
   private:
    vector<bool> table;

   public:
    MyHashSet() {
        table.resize(1000001, false);  // initialize all to false
    }

    void add(int key) {
        table[key] = true;
    }

    void remove(int key) {
        table[key] = false;
    }

    bool contains(int key) {
        return table[key];
    }
};

int main() {
    MyHashSet* obj = new MyHashSet();  // MyHashSet()

    obj->add(1);     // add(1)
    obj->add(2);     // add(2)
    obj->remove(1);  // remove(1)
    obj->remove(1);  // remove(1) again (no effect)

    cout << obj->contains(1) << endl;  // contains(1) -> 0 (false)
    cout << obj->contains(2) << endl;  // contains(2) -> 1 (true)

    delete obj;
    return 0;
}