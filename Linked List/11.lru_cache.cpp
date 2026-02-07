#include <bits/stdc++.h>
using namespace std;

// Brute force LRU Cache using vector
// Time: O(N) for get and put
// class LRUCache {
//    private:
//     vector<pair<int, int>> v;  // stores (key, value) in LRU order
//     int maxCapacity;

//    public:
//     LRUCache(int capacity) {
//         maxCapacity = capacity;
//     }

//     int get(int key) {
//         for (int i = 0; i < v.size(); i++) {
//             if (v[i].first == key) {
//                 int value = v[i].second;

//                 // Move accessed key to back (most recently used)
//                 v.erase(v.begin() + i);
//                 v.push_back({key, value});

//                 return value;
//             }
//         }
//         return -1;  // key not found
//     }

//     void put(int key, int value) {
//         // Remove key if it already exists
//         for (int i = 0; i < v.size(); i++) {
//             if (v[i].first == key) {
//                 v.erase(v.begin() + i);
//                 break;
//             }
//         }

//         // If cache is full, remove least recently used
//         if (v.size() == maxCapacity) {
//             v.erase(v.begin());
//         }

//         // Insert new key as most recently used
//         v.push_back({key, value});
//     }
// };

// Using Doubly Linked List - O(1) time for all operations
class LRUCache {
   private:
    struct ListNode {
        int key, value;
        ListNode* prev;
        ListNode* next;
        ListNode(int k, int v) : key(k), value(v), prev(nullptr), next(nullptr) {}
    };

    int capacity;
    unordered_map<int, ListNode*> map;
    ListNode* left;   // LRU sentinel
    ListNode* right;  // MRU sentinel

    // Remove node from list
    void remove(ListNode* node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }

    // Insert node before right (MRU)
    void insert(ListNode* node) {
        node->prev = right->prev;
        node->next = right;
        right->prev->next = node;
        right->prev = node;
    }

   public:
    // Initialize cache with capacity and sentinel nodes
    LRUCache(int cap) {
        capacity = cap;
        left = new ListNode(0, 0);   // LRU sentinel
        right = new ListNode(0, 0);  // MRU sentinel
        left->next = right;
        right->prev = left;
    }

    // Get value and mark as recently used
    int get(int key) {
        if (!map.count(key)) return -1;

        ListNode* node = map[key];
        remove(node);  // Remove from current position
        insert(node);  // Move to MRU position

        return node->value;
    }

    // Insert or update key-value pair
    void put(int key, int value) {
        // Update existing key
        if (map.count(key)) {
            ListNode* node = map[key];
            node->value = value;
            remove(node);
            insert(node);  // Move to MRU position
            return;
        }

        // Insert new key
        ListNode* node = new ListNode(key, value);
        map[key] = node;
        insert(node);

        // Evict LRU if capacity exceeded
        if (map.size() > capacity) {
            ListNode* lru = left->next;
            remove(lru);
            map.erase(lru->key);
            delete lru;
        }
    }
};

// LRU Cache using STL
// Time Complexity: O(1) for get and put
// class LRUCache {
//    private:
//     int capacity;

//     // Doubly linked list storing (key, value)
//     // Front  -> Least Recently Used
//     // Back   -> Most Recently Used
//     list<pair<int, int>> dll;

//     // Map: key -> iterator pointing to list node
//     unordered_map<int, list<pair<int, int>>::iterator> map;

//    public:
//     LRUCache(int cap) {
//         capacity = cap;
//     }

//     int get(int key) {
//         // Key not present
//         if (!map.count(key)) return -1;

//         // Get iterator of the node
//         auto it = map[key];

//         // Move accessed node to the back (MRU)
//         dll.splice(dll.end(), dll, it);

//         // Return value
//         return it->second;
//     }

//     void put(int key, int value) {
//         // If key already exists
//         if (map.count(key)) {
//             auto it = map[key];

//             // Update value
//             it->second = value;

//             // Move to MRU position
//             dll.splice(dll.end(), dll, it);
//             return;
//         }

//         // If cache is full, remove LRU (front)
//         if (dll.size() == capacity) {
//             auto lru = dll.front();
//             map.erase(lru.first);
//             dll.pop_front();
//         }

//         // Insert new key-value at MRU position
//         dll.push_back({key, value});
//         map[key] = prev(dll.end());
//     }
// };

int main() {
    LRUCache lRUCache(2);
    lRUCache.put(1, 10);  // cache: {1=10}
    lRUCache.get(1);      // return 10
    lRUCache.put(2, 20);  // cache: {1=10, 2=20}
    lRUCache.put(3, 30);  // cache: {2=20, 3=30}, key=1 was evicted
    lRUCache.get(2);      // returns 20
    lRUCache.get(1);      // return -1 (not found)
}