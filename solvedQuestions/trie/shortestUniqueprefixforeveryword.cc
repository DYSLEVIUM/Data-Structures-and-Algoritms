//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Trie {
    class Node {
        int cnt = 0;
        unordered_map<char, Node *> nodes;
        
        virtual ~Node() {
            for(auto &it : nodes) {
                delete it.second;
                it.second = nullptr;
            }
        }
        
        friend class Trie;
    };
    
    Node *m_root;
    
public:
    Trie() : m_root(nullptr) {}
    
    void insert(const string &s){
        if(!m_root) {
            m_root = new Node();
        }
        
        Node *node = m_root;
        for(auto &ch: s) {
            if(node->nodes.find(ch) == node->nodes.end()) {
                node->nodes[ch] = new Node();
            }
            
            node = node->nodes[ch];
            ++(node->cnt);
        }
    }
    
    string find_unique_prefix(const string &s) {
        string prefix = "";
        if(!m_root) {
            return prefix;
        }
        
        Node *node = m_root;
        for(auto &ch: s) {
            if(node->cnt == 1) {
                return prefix;
            }
            
            node = node->nodes[ch];
            prefix += ch;
        }
        
        // here the prefix will be the string itself
        return prefix;
    }
    
    ~Trie() {
        delete m_root;
        m_root = nullptr;
    }
};

class Solution
{
    public:
    vector<string> findPrefixes(string arr[], int n) {
        Trie tr;
        for(int i = 0; i < n; ++i) {
            tr.insert(arr[i]);
        }
        
        vector<string> ans(n);
        for(int i = 0; i < n; ++i) {
            ans[i] = tr.find_unique_prefix(arr[i]);
        }
        
        return ans;
    }
    
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        string arr[n];
        for (int i = 0; i < n; i++)
            cin >> arr[i];
            
        Solution ob;
        vector<string> ans = ob.findPrefixes(arr, n);
        
        for (int i = 0; i < ans.size(); i++)
            cout << ans[i] <<" ";


        cout << "\n";

    }

    return 0;
}

// } Driver Code Ends
