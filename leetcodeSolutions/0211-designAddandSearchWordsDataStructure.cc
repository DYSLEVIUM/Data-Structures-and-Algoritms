class WordDictionary {
public:
    class Trie{
      class TrieNode{
        unordered_map<char, TrieNode*> mp;
        bool is_leaf;
        
        TrieNode(): is_leaf(false) {}
        
        virtual ~TrieNode(){
          for(auto& it: this->mp){
            delete it.second;
            it.second = nullptr;
          }
        }
        
        friend class Trie;
      };
      
      TrieNode* root;
      
      public:
      Trie() {
        this->root = new TrieNode();
      };
      
      void insert(const string& word) {
        TrieNode* curr_node = this->root;
        
        for(auto& letter: word){
          if(!curr_node->mp[letter]) curr_node->mp[letter] = new TrieNode();
          curr_node = curr_node->mp[letter];
        }
        
        curr_node->is_leaf = true;
      }
      
      bool find(const string& word, const int& st_idx, const int& ed_idx, TrieNode* curr_node){
        if(!this->root) return false;
        if(!curr_node) curr_node = this->root;
        
        for(int i=st_idx; i<=ed_idx; ++i){
          if(word[i]=='.'){
            for(auto& it: curr_node->mp){
              if(it.second && find(word, i+1, ed_idx, it.second)) return true;        
            }
            return false; //  if after taking all the possibilities from here, we get no word, there is no word
          }else if(curr_node->mp.find(word[i])==curr_node->mp.end()) return false;
          curr_node = curr_node->mp[word[i]];
        }
        
        return curr_node->is_leaf;
      }
      
      ~Trie(){
        delete this->root;
        this->root = nullptr;
      }
    };
  
    Trie* trie;
  
    WordDictionary() {
      this->trie = new Trie();
    }
    
    void addWord(string word) {
      this->trie->insert(word);
    }
    
    bool search(string word) {
      int n = word.length();
      return this->trie->find(word, 0, n-1, nullptr);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
