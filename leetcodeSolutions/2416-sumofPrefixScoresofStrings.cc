#pragma GCC optimize("O3", "unroll-loops")

auto _ = [](){
    return cin.tie(nullptr)->sync_with_stdio(false);
}();

const int static CHAR_SET = 26;
const char static BASE_CHAR = 'a';

class Trie {
    class TrieNode {
        int children;
        array<TrieNode*, CHAR_SET> nodes;

        TrieNode(): children(0), nodes({}) {}

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

    int insert(const string & s) {
        if(!root) {
            root = new TrieNode();
        }

        TrieNode * node = root;
        for(auto & ch : s) {
            if(!node->nodes[ch - BASE_CHAR]) {
                node->nodes[ch - BASE_CHAR] = new TrieNode();
            }

            ++node->children;
            node = node->nodes[ch - BASE_CHAR];
        }

        return ++node->children;
    }

    int count(const string & s) {
        if(!root) {
            return 0;
        }

        int cnt = 0;
        TrieNode * node = root;
        for(auto & ch : s) {
            if(!node->nodes[ch - BASE_CHAR]) {
                break;
            }

            node = node->nodes[ch - BASE_CHAR];
            cnt += node->children;
        }

        return cnt;
    }
};

class Solution {
public:
    vector<int> sumPrefixScores(vector<string> & words) {
        int n = words.size();

        Trie trie;
        for(string & word: words) {
            trie.insert(word);
        }

        vector<int> ans(n);
        for(int i = 0; i < n; ++i) {
            ans[i] = trie.count(words[i]);
        }

        return ans;
    }
};
