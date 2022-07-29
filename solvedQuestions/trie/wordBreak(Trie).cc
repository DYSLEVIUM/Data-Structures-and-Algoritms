//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Trie {
    class Node {
        bool is_leaf = false;
        unordered_map<char, Node *> nodes;
        
        Node() = default;
        
        // virtual ~Node() {
        //     for(auto &it : nodes) {
        //         delete it.second;
        //         it.second = nullptr;
        //     }
        // }
        
        friend class Trie;
    };
    
    Node *m_root;
    
public:
    Trie() : m_root(nullptr) {}
    
    void insert(const string &s){
        if(!m_root) {
            m_root = new Node();
        }
        
        Node *crawler = m_root;
        for(auto &ch: s) {
            if(crawler->nodes.find(ch) == crawler->nodes.end()) {
                crawler->nodes[ch] = new Node();
            }
            crawler = crawler->nodes[ch];
        }
        
        crawler->is_leaf = true;
    }
    
    bool find(const string &s) {
        if(!m_root) {
            return false;
        }
        
        Node *crawler = m_root;
        for(auto &ch: s) {
            if(crawler->nodes.find(ch) == crawler->nodes.end()) {
                return false;
            }
            crawler = crawler->nodes[ch];
        }
        
        return crawler->is_leaf;
    }
    
    // ~Trie() {
    //     delete m_root;
    //     m_root = nullptr;
    // }
};

class Solution{
    public:
    // A : given string to search
    // B : vector of available strings
    
    int wordBreak(string A, vector<string> &B) {
        Trie tr;
        for(auto &s : B) {
            tr.insert(s);
        }
        
        unordered_map<string, bool> dp;
        auto break_word = [&](const auto &break_word, const string &word){
            int n = word.length();
            
            if(!n) {
                return true;
            }
            
            if(dp.find(word) != dp.end()) {
                return dp[word];
            }
            
            for(int len = 1; len < n + 1; ++len) {
                if(tr.find(word.substr(0, len)) && break_word(break_word, word.substr(len, n - len))) {
                    return dp[word] = true;
                }
            }
            
            return dp[word] = false;
        };
        
        return break_word(break_word, A);
    }
};

//{ Driver Code Starts.
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<string> dict;
        for(int i=0;i<n;i++){
            string S;
            cin>>S;
            dict.push_back(S);
        }
        string line;
        cin>>line;
        Solution ob;
        cout<<ob.wordBreak(line, dict)<<"\n";
    }
}

// } Driver Code Ends
