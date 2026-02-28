#include <bits/stdc++.h>
using namespace std;

// Trie (Prefix Tree), Hash Map Version
// Time Complexity per operation: O(L), L = length of the word
// Space Complexity: O(total characters inserted)
// class PrefixTree {
//    private:
//     // Node class
//     class TrieNode {
//        public:
//         unordered_map<char, TrieNode*> children;  // child links
//         bool terminal;                            // true if word ends here

//         TrieNode() {
//             terminal = false;
//         }
//     };

//     TrieNode* root;

//    public:
//     // Constructor
//     PrefixTree() {
//         root = new TrieNode();
//     }

//     // Insert word into trie
//     // Time: O(L)
//     void insert(string word) {
//         TrieNode* node = root;

//         for (char ch : word) {
//             // If child does not exist, create it
//             if (node->children.count(ch) == 0) {
//                 node->children[ch] = new TrieNode();
//             }

//             node = node->children[ch];
//         }

//         // Mark end of word
//         node->terminal = true;
//     }

//     // Search full word
//     // Returns true only if exact word exists
//     // Time: O(L)
//     bool search(string word) {
//         TrieNode* node = root;

//         for (char ch : word) {
//             if (node->children.count(ch) == 0)
//                 return false;

//             node = node->children[ch];
//         }

//         return node->terminal;
//     }

//     // Check if any word starts with given prefix
//     // Returns true if prefix path exists
//     // Time: O(L)
//     bool startsWith(string prefix) {
//         TrieNode* node = root;

//         for (char ch : prefix) {
//             if (node->children.count(ch) == 0)
//                 return false;

//             node = node->children[ch];
//         }

//         return true;  // prefix exists
//     }
// };

// Trie (Prefix Tree), More faster version using vector/array
// Time Complexity per operation: O(L)
// Space Complexity: O(total characters inserted)
class PrefixTree {
   private:
    class TrieNode {
       public:
        TrieNode* children[26];
        bool terminal;

        TrieNode() {
            terminal = false;
            for (int i = 0; i < 26; i++)
                children[i] = nullptr;
        }
    };

    TrieNode* root;

   public:
    PrefixTree() {
        root = new TrieNode();
    }

    // Insert word
    void insert(string word) {
        TrieNode* node = root;

        for (char ch : word) {
            int index = ch - 'a';

            if (node->children[index] == nullptr)
                node->children[index] = new TrieNode();

            node = node->children[index];
        }

        node->terminal = true;
    }

    // Search full word
    bool search(string word) {
        TrieNode* node = root;

        for (char ch : word) {
            int index = ch - 'a';

            if (node->children[index] == nullptr)
                return false;

            node = node->children[index];
        }

        return node->terminal;
    }

    // Check prefix
    bool startsWith(string prefix) {
        TrieNode* node = root;

        for (char ch : prefix) {
            int index = ch - 'a';

            if (node->children[index] == nullptr)
                return false;

            node = node->children[index];
        }

        return true;
    }
};

int main() {
    PrefixTree prefixTree;
    prefixTree.insert("dog");
    cout << (prefixTree.search("dog") ? "true" : "false") << endl;     // return true
    cout << (prefixTree.search("do") ? "true" : "false") << endl;      // return false
    cout << (prefixTree.startsWith("do") ? "true" : "false") << endl;  // return true
    prefixTree.insert("do");
    cout << (prefixTree.search("do") ? "true" : "false") << endl;  // return true

    return 0;
}