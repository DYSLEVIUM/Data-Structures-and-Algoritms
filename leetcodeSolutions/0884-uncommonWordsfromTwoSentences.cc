#pragma GCC optimize("O3", "unroll-loops")

auto _ = [](){
    return cin.tie(nullptr)->sync_with_stdio(false);
}();

class Trie {
    class Node {
        int cnt;
        unordered_map<char, Node *> mp;

        Node(): cnt(0) {}

        virtual ~Node() {
            for(auto &it : mp) {
                delete it.second;
                it.second = nullptr;
            }
        }

        friend class Trie;
    };

    Node * root;

public:
    Trie(): root(nullptr) {}

    void insert(string & s) {
        if(!this->root) {
            root = new Node();
        }

        Node * node = this->root;
        for(auto & ch: s) {
            if(!node->mp.count(ch)) {
                node->mp[ch] = new Node();
            }
            node = node->mp[ch];
        }

        ++node->cnt;
    }

    int find(string & s) {
        if(!this->root) {
            return 0;
        }

        Node * node = this->root;
        for(auto & ch: s) {
            if(!node->mp.count(ch)) {
                return 0;
            }
            node = node->mp[ch];
        }

        return node->cnt;
    }

    ~Trie() {
        delete this->root;
        this->root = nullptr;
    }
};

class Solution {
public:
    vector<string> uncommonFromSentences(string & s1, string & s2) {
        Trie tr;

        string word;
        stringstream ss;
        
        ss << s1 << " " << s2;
        while(ss >> word) {
            tr.insert(word);
        }
        ss.clear();

        vector<string> ans;

        ss << s1 << " " << s2;
        while(ss >> word) {
            if(tr.find(word) != 1) {
                continue;
            }
            ans.push_back(word);
        }
        
        return ans;
    }
};
