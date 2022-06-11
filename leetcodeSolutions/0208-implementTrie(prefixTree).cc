class Trie {
public:
    Trie() : m_root(nullptr) {}
    
    void insert(const string &word) {
        if(m_root == nullptr) {
            m_root = new Node();
        }
        
        Node *curr_node = m_root;
        for(auto& ch: word) {
            if(curr_node->m_trie_node.find(ch) == curr_node->m_trie_node.end()){
                curr_node->m_trie_node[ch] = new Node();
            }
            curr_node = curr_node->m_trie_node[ch];
        }
        
        curr_node->m_is_leaf = true;
    }
    
    bool search(const string &word) {
        if(m_root == nullptr) {
            return false;
        }
        
        Node *curr_node = m_root;
        for(auto& ch: word) {
            if(curr_node->m_trie_node.find(ch) == curr_node->m_trie_node.end()) {
                return false;
            }
            
            curr_node = curr_node->m_trie_node[ch];
        }
        
        return curr_node->m_is_leaf;
    }
    
    bool startsWith(const string &prefix) {
        if(m_root == nullptr) {
            return false;
        }
        
        Node *curr_node = m_root;
        for(auto& ch: prefix) {
            if(curr_node->m_trie_node.find(ch) == curr_node->m_trie_node.end()) {
                return false;
            }
            
            curr_node = curr_node->m_trie_node[ch];
        }
        
        return true;
    }
    
    ~Trie() {
        delete m_root;
        m_root = nullptr;
    }
    
private:
    class Node {
        bool m_is_leaf;
        unordered_map<char, Node*> m_trie_node;
        
        Node() : m_is_leaf(false) {}
        
        virtual ~Node() {
            for(auto &it: m_trie_node) {
                delete it.second;
                it.second = nullptr;
            }
        }
        
        friend class Trie;
    };
    
    Node *m_root;
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
