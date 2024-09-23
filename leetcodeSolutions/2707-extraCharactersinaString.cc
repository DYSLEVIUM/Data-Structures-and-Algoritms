#pragma GCC optimize("O3", "unroll-loops")

auto _ = [](){
    return cin.tie(nullptr)->sync_with_stdio(false);
}();

const int static CHAR_SET = 26;

class Trie {
    class TrieNode {
        bool is_leaf;
        array<TrieNode*, CHAR_SET> nodes;

        TrieNode(): is_leaf(false), nodes({}) {}

        ~TrieNode() {
            for(auto & node: nodes) {
                delete node;
                node = nullptr;
            }
        }

        friend class Trie;
    };

    TrieNode *root;

public:
    Trie() : root(nullptr) {}

    ~Trie() {
        if(root == nullptr) {
            return ;
        }

        delete root;
        root = nullptr;
    }

    bool insert(const string & s) {
        if(!root) {
            root = new TrieNode();
        }

        TrieNode * node = root;
        for(auto & ch: s) {
            if(!node->nodes[ch - 'a']) {
                node->nodes[ch - 'a'] = new TrieNode();
            }

            node = node->nodes[ch - 'a'];
        }

        return node->is_leaf = true;
    }

    bool find(const string & s) {
        if(!root) {
            return false;
        }
        
        TrieNode * node = root;
        for(auto & ch: s) {
            if(!node->nodes[ch - 'a']) {
                return false;
            }

            node = node->nodes[ch - 'a'];
        }

        return node->is_leaf;
    }
};

class Solution {
public:
    int minExtraChar(string & s, vector<string> & dictionary) {
        static const int INF = 0x3f3f3f3f;

        int n = s.size();

        Trie trie;
        for(auto & word: dictionary) {
            trie.insert(word);
        }

        vector<int> dp(n + 1, INF);
        dp[0] = 0;

        for(int ed = 1; ed < n + 1; ++ed) {
            for(int len = 1; len <= ed; ++len) {
                bool has_word = trie.find(s.substr(ed - len, len));
                dp[ed] = min(dp[ed], dp[ed - len] + (has_word ? 0 : len)); 
            }
        }

        return dp[n];
    }
};
