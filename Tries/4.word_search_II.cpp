#include <bits/stdc++.h>
using namespace std;

// Backtracking Approach (Word Search I + II naive approach)
// Time Complexity: O(W * R * C * 4^L) where L = length of the word, W = number of words, R = rows, C = cols
// Space Complexity: O(R * C) for visited matrix, O(L) recursion stack
// class Solution {
//    public:
//     vector<string> ans;  // Stores found words
//     int rows, cols;

//     // DFS to check whether word[index...] can be formed
//     bool dfs(vector<vector<char>>& board, string& word, int index, int r, int c, vector<vector<bool>>& visited) {
//         // If all characters matched → word found
//         if (index == word.size())
//             return true;

//         // Boundary check or Already visited or Character mismatch
//         if (r < 0 || c < 0 || r >= rows || c >= cols ||
//             visited[r][c] ||
//             board[r][c] != word[index])
//             return false;

//         // Mark current cell as visited
//         visited[r][c] = true;

//         // Explore 4 directions (down, up, right, left)
//         bool found =
//             dfs(board, word, index + 1, r + 1, c, visited) ||
//             dfs(board, word, index + 1, r - 1, c, visited) ||
//             dfs(board, word, index + 1, r, c + 1, visited) ||
//             dfs(board, word, index + 1, r, c - 1, visited);

//         // Backtrack (unmark cell)
//         visited[r][c] = false;

//         return found;
//     }

//     // Check if a single word exists in board
//     bool exist(vector<vector<char>>& board, string word) {
//         if (board.empty() || board[0].empty())
//             return false;

//         rows = board.size();
//         cols = board[0].size();

//         // Create visited matrix
//         vector<vector<bool>> visited(rows, vector<bool>(cols, false));

//         // Try starting DFS from every cell
//         for (int r = 0; r < rows; r++) {
//             for (int c = 0; c < cols; c++) {
//                 if (dfs(board, word, 0, r, c, visited))
//                     return true;
//             }
//         }

//         return false;
//     }

//     // Find all words from the list that exist in board
//     vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
//         for (string& word : words) {
//             if (exist(board, word)) {
//                 ans.push_back(word);
//             }
//         }

//         return ans;
//     }
// };

// Most Optimal HashSet + Trie Approach
// Time Complexity: O(R * C * 4^L)
// Space Complexity: O(W * L) + O(L), where L = length of the word, W = number of words, R = rows, C = cols
class Solution {
   public:
    struct TrieNode {
        TrieNode* children[26];
        // stores full word if this node ends a word, because in dfs search when we reach the end then no need to rebuild the word, we can just push_back to the result
        string word;

        TrieNode() {
            for (int i = 0; i < 26; i++)
                children[i] = nullptr;
            word = "";
        }
    };

    // Insert word into Trie
    void insert(TrieNode* root, string& word) {
        TrieNode* node = root;
        for (char c : word) {
            int idx = c - 'a';
            if (!node->children[idx])
                node->children[idx] = new TrieNode();
            node = node->children[idx];
        }
        node->word = word;  // mark complete word
    }

    void dfs(vector<vector<char>>& board, int r, int c, TrieNode* node, vector<string>& result) {
        char ch = board[r][c];

        // If no word continues with this character → prune
        if (!node->children[ch - 'a'])
            return;

        node = node->children[ch - 'a'];

        // If we found a complete word
        if (node->word != "") {
            result.push_back(node->word);
            node->word = "";  // avoid duplicates
        }

        // Mark visited
        board[r][c] = '#';

        int rows = board.size();
        int cols = board[0].size();

        // Explore 4 directions
        int directions[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        for (auto& dir : directions) {
            int nr = r + dir[0];
            int nc = c + dir[1];

            if (nr >= 0 && nc >= 0 &&
                nr < rows && nc < cols &&
                board[nr][nc] != '#') {
                dfs(board, nr, nc, node, result);
            }
        }

        // Backtrack (restore character)
        board[r][c] = ch;
    }

    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        TrieNode* root = new TrieNode();

        // Build Trie
        for (string& word : words)
            insert(root, word);

        vector<string> result;

        int rows = board.size();
        int cols = board[0].size();

        // Start DFS from each cell
        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; c++) {
                dfs(board, r, c, root, result);
            }
        }

        return result;
    }
};

int main() {
    vector<vector<char>> board = {
        {'a', 'b', 'c', 'd'},
        {'s', 'a', 'a', 't'},
        {'a', 'c', 'k', 'e'},
        {'a', 'c', 'd', 'n'}};
    vector<string> words = {"bat", "cat", "back", "backend", "stack"};

    Solution sol;
    vector<string> ans = sol.findWords(board, words);

    for (const string& word : ans) {
        cout << word << " ";
    }
    cout << endl;

    return 0;
}