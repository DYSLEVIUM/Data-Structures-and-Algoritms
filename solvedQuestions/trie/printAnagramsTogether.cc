// { Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

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

class Solution{
  public:
    vector<vector<string> > Anagrams(vector<string>& string_list) {
        //code here
        Trie tr;
        
        for(auto& str: string_list){
            string te = str;
            sort(te.begin(), te.end());
            
            tr.insert(te);
        }
        unordered_map<string, vector<string>> mp;
        
        for(auto& str: string_list){
            string te = str;
            sort(te.begin(), te.end());
            
            if(tr.find(te)) mp[te].push_back(str);
            
        }
        
        vector<vector<string>> ans;
        
        for(auto& it1:mp){
            vector<string> te;
            for(auto& it2:it1.second) te.push_back(it2);
            
            ans.push_back(te);
        }
        
        return ans;
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<string> string_list(n);
        for (int i = 0; i < n; ++i)
            cin>>string_list[i]; 
        Solution ob;
        vector<vector<string> > result = ob.Anagrams(string_list);
        sort(result.begin(),result.end());
        for (int i = 0; i < result.size(); i++)
        {
            for(int j=0; j < result[i].size(); j++)
            {
                cout<<result[i][j]<<" ";
            }
            cout<<"\n";
        }
    }

    return 0;
}
  // } Driver Code Ends
