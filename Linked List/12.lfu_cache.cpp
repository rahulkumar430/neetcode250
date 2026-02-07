#include <bits/stdc++.h>
using namespace std;

// Brute force LFU Cache using vector and map for use counter
// Time: O(N) for get and put
// class LFUCache {
//    private:
//     vector<pair<int, int>> v;          // (key, value) in recency order
//     unordered_map<int, int> useCount;  // key -> frequency
//     int maxCapacity;

//    public:
//     LFUCache(int capacity) {
//         maxCapacity = capacity;
//     }

//     int get(int key) {
//         for (int i = 0; i < v.size(); i++) {
//             if (v[i].first == key) {
//                 int value = v[i].second;

//                 // Update frequency
//                 useCount[key]++;

//                 // Move to most recently used position
//                 v.erase(v.begin() + i);
//                 v.push_back({key, value});

//                 return value;
//             }
//         }
//         return -1;
//     }

//     void put(int key, int value) {
//         // Edge case: zero capacity
//         if (maxCapacity == 0) return;

//         // If key exists, update value and frequency
//         for (int i = 0; i < v.size(); i++) {
//             if (v[i].first == key) {
//                 v.erase(v.begin() + i);
//                 useCount[key]++;
//                 v.push_back({key, value});
//                 return;
//             }
//         }

//         // If cache is full, evict LFU (LRU on tie)
//         if (v.size() == maxCapacity) {
//             int minFreq = INT_MAX;

//             // Find minimum frequency
//             for (auto& it : useCount) {
//                 minFreq = min(minFreq, it.second);
//             }

//             // Evict the first key in v having minFreq (LRU among LFU)
//             for (int i = 0; i < v.size(); i++) {
//                 int k = v[i].first;
//                 if (useCount[k] == minFreq) {
//                     useCount.erase(k);
//                     v.erase(v.begin() + i);
//                     break;  // remove ONLY one
//                 }
//             }
//         }

//         // Insert new key
//         v.push_back({key, value});
//         useCount[key] = 1;
//     }
// };

// Using Doubly Linked List - O(1) time for all operations
class LFUCache {
   private:
    // Node structure for doubly linked list
    struct Node {
        int key, value, freq;
        Node* prev;
        Node* next;
        Node(int k, int v) : key(k), value(v), freq(1), prev(nullptr), next(nullptr) {}
    };

    // Doubly Linked List to maintain nodes in LRU order within same frequency
    struct DLL {
        Node* head;
        Node* tail;
        int size;
        DLL() {
            head = new Node(0, 0);
            tail = new Node(0, 0);
            head->next = tail;
            tail->prev = head;
            size = 0;
        }

        // Add node to end (MRU position)
        void add(Node* node) {
            node->prev = tail->prev;
            node->next = tail;
            tail->prev->next = node;
            tail->prev = node;
            size++;
        }

        // Remove node from list
        void remove(Node* node) {
            node->prev->next = node->next;
            node->next->prev = node->prev;
            size--;
        }

        // Remove and return least recently used node (at front)
        Node* removeLRU() {
            if (size == 0) return nullptr;
            Node* lru = head->next;
            remove(lru);
            return lru;
        }
    };

    int capacity;
    int minFreq;
    unordered_map<int, Node*> keyMap;  // Maps key to its node
    unordered_map<int, DLL*> freqMap;  // Maps frequency to list of nodes with that frequency

   public:
    LFUCache(int cap) : capacity(cap), minFreq(0) {}

    // Get value for key and increment its frequency
    int get(int key) {
        if (!keyMap.count(key)) return -1;

        Node* node = keyMap[key];
        int freq = node->freq;

        // Remove from current frequency list
        freqMap[freq]->remove(node);

        // Update minFreq if current frequency list is empty
        if (freq == minFreq && freqMap[freq]->size == 0) {
            minFreq++;
        }

        // Move to next frequency list
        node->freq++;
        if (!freqMap.count(node->freq)) {
            freqMap[node->freq] = new DLL();
        }
        freqMap[node->freq]->add(node);

        return node->value;
    }

    // Insert/update key-value pair
    void put(int key, int value) {
        if (capacity == 0) return;

        // If key exists, update value and frequency
        if (keyMap.count(key)) {
            keyMap[key]->value = value;
            get(key);  // Update frequency
            return;
        }

        // Evict LFU (and LRU on tie) if cache is full
        if (keyMap.size() == capacity) {
            Node* lru = freqMap[minFreq]->removeLRU();
            keyMap.erase(lru->key);
            delete lru;
        }

        // Insert new key with frequency 1
        Node* node = new Node(key, value);
        minFreq = 1;

        if (!freqMap.count(1)) {
            freqMap[1] = new DLL();
        }

        freqMap[1]->add(node);
        keyMap[key] = node;
    }
};

// LFU Cache using STL
// Time Complexity: O(1) average for get and put
// class LFUCache {
//    private:
//     int capacity;
//     int minFreq;

//     // key -> {value, frequency}
//     unordered_map<int, pair<int, int>> keyData;

//     // frequency -> list of keys (LRU at front, MRU at back)
//     unordered_map<int, list<int>> freqList;

//     // key -> iterator pointing to its position in freqList[freq]
//     unordered_map<int, list<int>::iterator> keyIter;

//    public:
//     LFUCache(int cap) {
//         capacity = cap;
//         minFreq = 0;
//     }

//     int get(int key) {
//         if (!keyData.count(key)) return -1;

//         int value = keyData[key].first;
//         int freq = keyData[key].second;

//         // Remove key from current frequency list
//         freqList[freq].erase(keyIter[key]);

//         // If this was the last key in minFreq list, update minFreq
//         if (freq == minFreq && freqList[freq].empty()) {
//             minFreq++;
//         }

//         // Increase frequency
//         freq++;
//         keyData[key].second = freq;

//         // Insert key into new frequency list (MRU position)
//         freqList[freq].push_back(key);
//         keyIter[key] = prev(freqList[freq].end());

//         return value;
//     }

//     void put(int key, int value) {
//         if (capacity == 0) return;

//         // If key already exists, update value and frequency
//         if (keyData.count(key)) {
//             keyData[key].first = value;
//             get(key);  // reuse get to update frequency
//             return;
//         }

//         // If cache is full, evict LFU + LRU
//         if (keyData.size() == capacity) {
//             int lruKey = freqList[minFreq].front();
//             freqList[minFreq].pop_front();

//             keyData.erase(lruKey);
//             keyIter.erase(lruKey);
//         }

//         // Insert new key with frequency = 1
//         keyData[key] = {value, 1};
//         freqList[1].push_back(key);
//         keyIter[key] = prev(freqList[1].end());

//         minFreq = 1;
//     }
// }
;

int main() {
    LFUCache lfu(2);
    lfu.put(1, 1);  // cache=[1,_], cnt(1)=1
    lfu.put(2, 2);  // cache=[2,1], cnt(2)=1, cnt(1)=1
    lfu.get(1);     // return 1
    // cache=[1,2], cnt(2)=1, cnt(1)=2
    lfu.put(3, 3);  // 2 is the LFU key because cnt(2)=1 is the smallest, invalidate 2.
    // cache=[3,1], cnt(3)=1, cnt(1)=2
    lfu.get(2);  // return -1 (not found)
    lfu.get(3);  // return 3
    // cache=[3,1], cnt(3)=2, cnt(1)=2
    lfu.put(4, 4);  // Both 1 and 3 have the same cnt, but 1 is LRU, invalidate 1.
    // cache=[4,3], cnt(4)=1, cnt(3)=2
    lfu.get(1);  // return -1 (not found)
    lfu.get(3);  // return 3
    // cache=[3,4], cnt(4)=1, cnt(3)=3
    lfu.get(4);  // return 4
    // cache=[4,3], cnt(4)=2, cnt(3)=3
}