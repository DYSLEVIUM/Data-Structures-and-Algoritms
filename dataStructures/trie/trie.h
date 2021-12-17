class Trie {
  class Node {
    bool is_leaf;
    unordered_map<char, Node*> mp;

    Node() : is_leaf(false) {}

    virtual ~Node() {
      for (auto& it : mp) {
        delete it.second;
        it.second = nullptr;
      }
    }

    friend class Trie;
  };

  bool have_children() {
    for (auto& it : this->root->mp) {
      if (it.second != nullptr) return true;
    }
    return false;
  }

  Node* root;

 public:
  Trie() : root(nullptr) {}

  void insert(const string& data) {
    if (this->root == nullptr) this->root = new Node();

    Node* curr_node = this->root;

    for (auto& ch : data) {
      if (curr_node->mp.find(ch) == curr_node->mp.end()) curr_node->mp[ch] = new Node();

      curr_node = curr_node->mp[ch];
    }

    curr_node->is_leaf = true;
  }

  bool find(const string& data) {
    if (this->root == nullptr) return false;

    Node* curr_node = this->root;

    for (auto& ch : data) {
      if (curr_node->mp.find(ch) == curr_node->mp.end()) return false;

      curr_node = curr_node->mp[ch];
    }

    return curr_node->is_leaf;
  }

  ~Trie() {
    delete this->root;
    this->root = nullptr;
  }
};
