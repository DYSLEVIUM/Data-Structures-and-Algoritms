class Trie {
    class Node {
        unordered_map<char, Node *> nodes;
        bool is_leaf = false;
    public:
        Node() = default;
        virtual ~Node() {
            for(auto & [_, node] : nodes) {
                delete(node);
                node = nullptr;
            }
        }

        friend class Trie;
    };

    Node *root = nullptr;
public:
    Trie() {
        root = new Node();
    }
    
    void insert(const string & word) {
        Node * node = root;
        for(const char & ch : word) {
            if(!node->nodes[ch]) {
                node->nodes[ch] = new Node();
            }
            node = node->nodes[ch];
        }

        node->is_leaf = true;
    }
    
    bool search(const string & word) {
        Node * node = root;
        for(const char & ch : word) {
            if(!node->nodes[ch]) {
                return false;
            }
            node = node->nodes[ch];
        }

        return node->is_leaf;
    }
    
    bool startsWith(const string & prefix) {
        Node * node = root;
        for(const char & ch : prefix) {
            if(!node->nodes[ch]) {
                return false;
            }
            node = node->nodes[ch];
        }

        return true;
    }

    ~Trie() {
        delete(root);
        root = nullptr;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
