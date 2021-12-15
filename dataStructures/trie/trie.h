class Trie {
  class Node {
    bool isLeaf;

    unordered_map<char, Node*> mp;

    Node() : isLeaf(false) {}

    virtual ~Node() {
      for (auto it : mp) {
        delete it.S;
        it.S = nullptr;
      }
    }

    friend class Trie;
  };

  bool haveChildren() {
    for (auto it : this->root->mp) {
      if (it.S != nullptr) return true;
    }

    return false;
  }

 public:
  Node* root;

  Trie() : root(nullptr) {}

  void insert(const string& data) {
    //  if the trie is intially empty
    if (this->root == nullptr) this->root = new Node();

    Node* currNode = this->root;

    fo(i, data.size()) {
      //  create a node if the path doesn't exist
      if (currNode->mp.find(data[i]) == currNode->mp.end()) {
        currNode->mp[data[i]] = new Node();
      }

      //  go to next node
      currNode = currNode->mp[data[i]];
    }

    //  after inserting the word, it is valid
    currNode->isLeaf = true;
  }

  bool find(const string& data) {
    if (this->root == nullptr) return false;

    Node* currNode = this->root;

    fo(i, data.size()) {
      //  if node doesn't exist, data is not present
      if (currNode->mp.find(data[i]) == currNode->mp.end()) return false;

      currNode = currNode->mp[data[i]];
    }

    return currNode->isLeaf;
  }

  void remove(const string& data) {
    if (this->root == nullptr) return;

    auto removeHelper = [&](const auto& removeHelper, Node* currNode, string data, ll idx = 0) -> bool {
      //  end of the string
      if ((ll)data.size() == idx && currNode->isLeaf) {
        if (!this->haveChildren()) {
          delete currNode;  //  delete the current node
          currNode = nullptr;
          return true;  //  delete the non-leaf parent nodes
        } else {
          //  mark the current node as a non-leaf node as this is not the end point any more
          currNode->isLeaf = false;
          return false;  //  don't delete its parent nodes
        }
      } else {
        // recur for the node corresponding to the next character in the string and if it returns true, delete the current node if it is non-leaf
        if (currNode->mp.find(data[idx]) != currNode->mp.end() && removeHelper(removeHelper, currNode->mp[data[idx]], data, idx + 1) && currNode->isLeaf == false) {
          if (!this->haveChildren()) {
            delete currNode;
            currNode = nullptr;
            return true;  //  delete the non-leaf parent nodes
          } else
            return false;  //  don't delete its parent nodes
        }
      }

      return false;
    };

    removeHelper(removeHelper, this->root, data, 0);
  }

  ~Trie() {
    delete this->root;
    this->root = nullptr;
  }
};
