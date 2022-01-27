class Solution {
public:
  static constexpr int sz = 32;

  class TrieNode{
    public:
      TrieNode *child[2];

      TrieNode() {
        this->child[0] = nullptr;
        this->child[1] = nullptr;
      }

      void insert(int num){
        TrieNode* curr_node = this;

        bitset<sz> bs(num);

        for(int bit=sz;bit>=0;--bit){
            if(!curr_node->child[bs[bit]]) curr_node->child[bs[bit]] = new TrieNode();
            curr_node = curr_node->child[bs[bit]];
        }
      }
    
      ~TrieNode(){
        delete this->child[0], delete this->child[1];
        this->child[0] = nullptr, this->child[1] = nullptr;
      }
  };
    
  int findMaximumXOR(vector<int>& nums) {
    TrieNode* trie = new TrieNode();
    //  insert all the numbers
    for(auto& num: nums) trie->insert(num);
    
    auto get_max = [&trie](const int& num){
      TrieNode* curr_trie = trie;
      bitset<sz> bs(num);
      
      int curr_ans = 0;
      
      for(int bit=sz;bit>=0;--bit){
        if(curr_trie->child[!bs[bit]]) curr_ans+=(1<<bit), curr_trie = curr_trie->child[!bs[bit]];
        else curr_trie = curr_trie->child[bs[bit]];
      }
      
      return curr_ans;
    };
    
    int maxx = INT_MIN;
    //  get the max for all the numbers
    for(auto& num: nums) maxx = max(maxx, get_max(num));
    
    delete trie;
    
    return maxx;
  }
};
