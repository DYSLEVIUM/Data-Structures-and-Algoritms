// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

typedef long long ll;
typedef long double ld;
typedef std::pair<ll, ll> pl;
typedef std::vector<ll> vl;
typedef std::vector<pl> vpl;
typedef std::vector<vl> vvl;
typedef std::map<ll, ll> mll;
typedef std::priority_queue<ll> pqd;
typedef std::priority_queue<ll, vl, std::greater<ll>> pqi;

#define pb push_back
#define eb emplace_back
#define F first
#define S second
#define MOD (ll)(1e9 + 7)

std::mt19937_64 RNG(std::chrono::high_resolution_clock::now().time_since_epoch().count());

//  macro functions
#define fo(i, n) for (ll i = 0; i < (ll)n; ++i)
#define Fo(i, k, n) for (ll i = k; k < (ll)n ? i < (ll)n : i > (ll)n; k < (ll)n ? ++i : --i)
#define all(x) x.begin(), x.end()
#define tr(it, a) for (auto it = a.begin(); it != a.end(); ++it)
#define ps(x, y) std::fixed << std::setprecision(y) << x
#define setbits(x) __builtin_popcountll(x)
#define zerobits(x) __builtin_ctzll(x)
#define modAdd(a, b) ((((a % MOD) + (b % MOD)) % MOD) + MOD) % MOD
#define modSub(a, b) ((((a % MOD) - (b % MOD)) % MOD) + MOD) % MOD
#define modMul(a, b) ((((a % MOD) * (b % MOD)) % MOD) + MOD) % MOD

class Trie {
  class Node {
    bool isLeaf;

    unordered_map<char, Node*> mp;

    Node() : isLeaf(false) {}

    virtual ~Node() {
      for (auto it : mp) {
        delete it.second;
        it.second = nullptr;
      }
    }

    friend class Trie;
  };

  bool haveChildren() {
    for (auto it : this->root->mp) {
      if (it.second != nullptr) return true;
    }

    return false;
  }

 public:
  Node* root;

  Trie() : root(nullptr) {}

  void insert(string data) {
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

  bool find(string data) {
    if (this->root == nullptr) return false;

    Node* currNode = this->root;

    fo(i, data.size()) {
      //  if node doesn;t exist, data is not present
      if (currNode->mp.find(data[i]) == currNode->mp.end()) return false;

      currNode = currNode->mp[data[i]];
    }

    return currNode->isLeaf;
  }
  
  vector<string> findSubTree(string data){
      vector<string> res;
      if(this->root==nullptr) return res;
      
      Node* currNode = this->root;
      
      int match = 0;
      //    go to the last possible ans char
      fo(i, data.size()){
          if(currNode->mp.find(data[i])==currNode->mp.end()) break;
            
          ++match;
          currNode = currNode->mp[data[i]];
      }
      
      //    do dfs from this point
      auto dfs = [&](const Node* node, const string currAns,const auto& dfs)->void{
        if(node->isLeaf) res.emplace_back(currAns);
        
        if(this->haveChildren()==false) return;
        
        for(auto x: node->mp) dfs(x.second, currAns+x.first, dfs);
      };
      
      if(match==data.size()) dfs(currNode, data, dfs);
      
      sort(all(res));
      
      if(res.size()==0) res.emplace_back("0");
      
      return res;
  }

  ~Trie() {
    delete this->root;
    this->root = nullptr;
  }
};

class Solution{
public:
    vector<vector<string>> displayContacts(int n, string contact[], string s)
    {
        // code here
        
        Trie contactList;
        
        for(int i=0;i<n;++i) contactList.insert(contact[i]);
        
        vector<vector<string>> ans;
        
        string temp = "";
        for(auto x: s){
            temp += x;
            ans.emplace_back(contactList.findSubTree(temp));
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
