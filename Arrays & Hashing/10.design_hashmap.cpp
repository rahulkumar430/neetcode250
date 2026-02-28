#include <bits/stdc++.h>
using namespace std;

// Basic Array Approach
// Time Complexity: O(1), Space Complexity: O(n)
class MyHashMap {
   private:
    vector<int> hashMap;

   public:
    MyHashMap() {
        hashMap.resize(1000001, -1);  // initialize all to -1
    }

    void put(int key, int value) {
        hashMap[key] = value;
    }

    int get(int key) {
        return hashMap[key];
    }

    void remove(int key) {
        hashMap[key] = -1;
    }
};

int main() {
    MyHashMap* obj = new MyHashMap();  // MyHashMap()

    obj->put(1, 1);               // put(1,1)
    obj->put(2, 2);               // put(2,2)
    cout << obj->get(1) << endl;  // get(1)
    cout << obj->get(3) << endl;  // get(3)
    obj->put(2, 1);               // put(2,1)
    cout << obj->get(2) << endl;  // get(2)
    obj->remove(2);               // remove(2)
    cout << obj->get(2) << endl;  // get(2)

    delete obj;
    return 0;
}