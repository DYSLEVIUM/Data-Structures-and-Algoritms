class Trie {
public:
  void insert(const string &word) {
    if(!m_root){
      m_root = new Node();
    }
    
    Node *curr_node = m_root;
    for(auto &ch: word) {
      if(curr_node->m_mp.find(ch) == curr_node->m_mp.end()) {
        curr_node->m_mp[ch] = new Node();
      }
      
      curr_node = curr_node->m_mp[ch];
    }
    curr_node->m_is_leaf = true;
  }
  
  vector<string> search(const string &prefix) {
    if(!m_root){
      return {};
    }
    
    vector<string> ans;
    auto dfs = [&ans](const auto& dfs, Node * const curr_node, const string curr_ans){
      if(ans.size() == 3) {
        return;
      }
      
      if(curr_node->m_is_leaf) {
        ans.push_back(curr_ans);
      }
      
      for(auto &it: curr_node->m_mp) {
        dfs(dfs, it.second, curr_ans + it.first);
      }
    };
    
    string curr_ans = "";
    Node *curr_node = m_root;
    for(auto &ch: prefix) {
      if(curr_node->m_mp.find(ch) == curr_node->m_mp.end()) {
        //  no matches
        return {};
      }
      
      curr_ans += ch;
      curr_node = curr_node->m_mp[ch];
    }
    dfs(dfs, curr_node, curr_ans);
    
    return ans;
  }
private:
  class Node {
    map<char, Node *> m_mp;
    bool m_is_leaf = false;
    friend class Trie;
  };
  Node *m_root;
};

class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
      Trie *pre_tree = new Trie();
      for(string& product: products) {
        pre_tree->insert(product);
      }
      
      string prefix = "";
      vector<vector<string>> res;
      for(char& ch: searchWord) {
        prefix += ch;
        res.push_back(pre_tree->search(prefix));
      }
      
      return res;
    }
};
