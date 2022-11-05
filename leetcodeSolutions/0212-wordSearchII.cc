struct TrieNode {
    unordered_map<char, TrieNode *> m_nodes;
    bool m_is_leaf = false;
    string word;
};

struct Trie {
    TrieNode * m_root = nullptr;
    void insert(const string_view & s) {
        if(!m_root) m_root = new TrieNode;
        TrieNode * node = m_root;
        string word;
        for(auto & ch : s) {
            if(!node->m_nodes[ch]) node->m_nodes[ch] = new TrieNode;
            node = node->m_nodes[ch];
        }
        node->word = static_cast<string>(s);
        node->m_is_leaf = true;
    }
};

class Solution {
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        int rows = board.size(), cols = rows ? board[0].size() : 0;

        Trie dict;
        for(string & word : words) dict.insert(word);

        vector<string> ans;
        vector<vector<int>> vis(rows, vector<int>(cols));
        vector<pair<int, int>> deltas {{-1, 0}, {0, -1}, {0, 1}, {1, 0}};
        
        auto dfs = [&](const auto & dfs, const int & row, const int & col, TrieNode * node){
            if(row < 0 || row == rows || col < 0 || col == cols || vis[row][col]) return;

            char ch = board[row][col];
            if(!node->m_nodes[ch]) return; // no matching prefix

            vis[row][col] = 1;

            node = node->m_nodes[ch];
            if(node->m_is_leaf) {
                ans.push_back(node->word); // we got a matching word
                node->m_is_leaf = false; // so we don't use it again
            }
            
            for(auto & [dr, dc] : deltas) dfs(dfs, row + dr, col + dc, node);
            
            vis[row][col] = 0;
        };
        
        for(int row = 0; row < rows; ++row) {
            for(int col = 0; col < cols; ++col)
                dfs(dfs, row, col, dict.m_root);
        }

        return ans;
    }
};
