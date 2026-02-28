#include <bits/stdc++.h>
using namespace std;

// Brute Force Approach using vector storage
// Time Complexity: O(N*L) per search where N is number of words and L is word length
// Space Complexity: O(N*L) where N is number of words
// class WordDictionary {
//    public:
//     vector<string> store;  // Store all added words

//     WordDictionary() {}

//     // Add word to dictionary
//     void addWord(string word) {
//         store.push_back(word);
//     }

//     bool search(string word) {
//         // Check each stored word
//         for (string w : store) {
//             // Skip if lengths don't match
//             if (w.length() != word.length()) continue;

//             // Match characters one by one
//             int i = 0;
//             while (i < w.length()) {
//                 // Character matches or pattern has wildcard
//                 if (w[i] == word[i] || word[i] == '.') {
//                     i++;
//                 } else {
//                     // Mismatch found
//                     break;
//                 }
//             }

//             // If we matched entire word, return true
//             if (i == w.length()) {
//                 return true;
//             }
//         }

//         return false;
//     }
// };

// Using Trie Data Structure with DFS Search for wildcard
// Time Complexity: O(L) for Insert and O(L) for search if no wild card '.', otherwise O(26^L)
// Space Complexity: O(L)
class WordDictionary {
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
    WordDictionary() {
        root = new TrieNode();
    }

    // Insert word
    void addWord(string word) {
        TrieNode* node = root;

        for (char ch : word) {
            int index = ch - 'a';

            if (node->children[index] == nullptr)
                node->children[index] = new TrieNode();

            node = node->children[index];
        }

        node->terminal = true;
    }
    // dfs search
    bool search(string word) {
        return dfs(0, word, root);
    }

    // dfs search helper
    bool dfs(int pos, string& word, TrieNode* node) {
        // If we've reached end of word
        if (pos == word.length()) {
            return node->terminal;
        }

        char ch = word[pos];

        // Case 1: Wildcard '.'
        if (ch == '.') {
            // Try all possible children
            for (int i = 0; i < 26; i++) {
                if (node->children[i] != nullptr) {
                    if (dfs(pos + 1, word, node->children[i]))
                        return true;
                }
            }

            return false;
        }

        // Case 2: Normal character
        int index = ch - 'a';

        if (node->children[index] == nullptr)
            return false;

        return dfs(pos + 1, word, node->children[index]);
    }
};

int main() {
    WordDictionary wordDictionary;
    wordDictionary.addWord("day");
    wordDictionary.addWord("bay");
    wordDictionary.addWord("may");
    cout << (wordDictionary.search("say") ? "true" : "false") << endl;  // return false
    cout << (wordDictionary.search("day") ? "true" : "false") << endl;  // return true
    cout << (wordDictionary.search(".ay") ? "true" : "false") << endl;  // return true
    cout << (wordDictionary.search("b..") ? "true" : "false") << endl;  // return true

    return 0;
}