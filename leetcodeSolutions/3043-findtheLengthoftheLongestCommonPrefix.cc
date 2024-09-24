#pragma GCC optimize("O3", "unroll-loops")

auto _ = [](){
    return cin.tie(nullptr)->sync_with_stdio(false);
}();

const int static CHAR_SET = 10;
const char static BASE_CHAR = '0';

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
            if(!node->nodes[ch - BASE_CHAR]) {
                node->nodes[ch - BASE_CHAR] = new TrieNode();
            }

            node = node->nodes[ch - BASE_CHAR];
        }

        return node->is_leaf = true;
    }

    int find(const string & s) {
        if(!root) {
            return false;
        }
        
        TrieNode * node = root;

        int cnt = 0;
        for(auto & ch: s) {
            if(!node->nodes[ch - BASE_CHAR]) {
                break;
            }

            ++cnt;
            node = node->nodes[ch - BASE_CHAR];
        }

        return cnt;
    }
};

class Solution {
public:
    int longestCommonPrefix(vector<int> & arr1, vector<int> & arr2) {
        Trie trie;
        for(auto & num : arr1) {
            auto str = to_string(num);

            trie.insert(str);
        }

        int lcp = -0x3f3f3f3f;
        for(auto & num : arr2) {
            auto str = to_string(num);
            lcp = max(lcp, trie.find(str));
        }

        return lcp;
    }
};
