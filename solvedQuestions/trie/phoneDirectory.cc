// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Trie{
  class Node{
      bool is_leaf;
      unordered_map<char, Node*> mp;
      
      Node(): is_leaf(false) {}
      
      virtual ~Node(){
        for(auto& it: mp){
            delete it.second;
            it.second = nullptr;
        }
      }
      
      friend class Trie;
  };
  
  bool have_children(){
    for(auto& it: this->root->mp){
        if(it.second!=nullptr) return true;
    }
    return false;
  }
  
  Node* root;
  
  public:
  
  Trie(): root(nullptr){}
  
  void insert(const string& data){
    if(this->root==nullptr) this->root = new Node();
    
    Node* curr_node = this->root;
  
    for(auto& ch:data){
        if(curr_node->mp.find(ch)==curr_node->mp.end()) curr_node->mp[ch] = new Node();
        
        curr_node = curr_node->mp[ch];
    }
    
    curr_node->is_leaf = true;
  }
  
  bool find(const string& data){
      if(this->root==nullptr) return false;
      
      Node* curr_node = this->root;
      
      for(auto& ch:data){
          if(curr_node->mp.find(ch)==curr_node->mp.end()) return false;
          
          curr_node = curr_node->mp[ch];
      }
      
      return curr_node->is_leaf;
  }
  
  vector<string> get_matching(const string str){
      if(this->root==nullptr) return vector<string>(1, "0");
      
      Node* curr_node = this->root;
      
      for(auto& ch:str){
          if(curr_node->mp[ch]==nullptr) return vector<string>(1, "0");
          curr_node = curr_node->mp[ch];
      }
      
      vector<string> ans;
      
      auto dfs = [&ans](const auto& dfs, const Node* const new_node, const string& curr_str)->void{
        if(new_node->is_leaf) ans.push_back(curr_str);
        
        for(auto& it:new_node->mp){
            if(it.second!=nullptr) dfs(dfs, it.second, curr_str + it.first);
        }
      };
      
      dfs(dfs, curr_node, str);
      
      sort(ans.begin(), ans.end());
      
      if(ans.size()==0) ans.push_back("0");
      
      return ans;
  }
  
  ~Trie(){
    delete this->root;
    this->root = nullptr;
  }
};

class Solution{
public:
    vector<vector<string>> displayContacts(int n, string contact[], string s)
    {
        // code here
        
        Trie contact_list;
        
        for(int i=0;i<n;++i) contact_list.insert(contact[i]);
    
        vector<vector<string>> ans;
        
        string curr_s = "";
        for(auto& ch:s){
            curr_s += ch;
            ans.push_back(contact_list.get_matching(curr_s));
        }
        
        return ans;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        string contact[n], s;
        for(int i = 0;i < n;i++)
            cin>>contact[i];
        cin>>s;
        
        Solution ob;
        vector<vector<string>> ans = ob.displayContacts(n, contact, s);
        for(int i = 0;i < s.size();i++){
            for(auto u: ans[i])
                cout<<u<<" ";
            cout<<"\n";
        }
    }
    return 0;
}  // } Driver Code Ends
