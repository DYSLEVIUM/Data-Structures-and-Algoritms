//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
#define MAX 1000

vector<vector<int>> uniqueRow(int M[MAX][MAX],int row,int col);

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
    	int n,m;
    	cin>>n>>m;
    	int a[MAX][MAX];
    	for(int i=0;i<n;i++)
    	for(int j=0;j<m;j++)
    	cin>>a[i][j];
    	vector<vector<int>> vec = uniqueRow(a,n,m);
    	for(int i = 0;i<vec.size();i++){
    	    for(int x : vec[i]){
    	        cout<<x<<" ";
    	    }
    	    cout<<"$";
    	}
    	cout<<endl;
    }
}

// } Driver Code Ends

class Trie {
    class Node {
        bool is_leaf = false;
        unordered_map<int, Node *> nodes;
        
        Node() = default;
        
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
    
    void insert(const vector<int> &v){
        if(!m_root) {
            m_root = new Node();
        }
        
        Node *crawler = m_root;
        for(auto &num: v) {
            if(crawler->nodes.find(num) == crawler->nodes.end()) {
                crawler->nodes[num] = new Node();
            }
            crawler = crawler->nodes[num];
        }
        
        crawler->is_leaf = true;
    }
    
    bool find(const vector<int> &v) {
        if(!m_root) {
            return false;
        }
        
        Node *crawler = m_root;
        for(auto &num: v) {
            if(crawler->nodes.find(num) == crawler->nodes.end()) {
                return false;
            }
            crawler = crawler->nodes[num];
        }
        
        return crawler->is_leaf;
    }
    
    ~Trie() {
        delete m_root;
        m_root = nullptr;
    }
};

vector<vector<int>> uniqueRow(int M[MAX][MAX],int rows,int cols){
    Trie tr;
    
    vector<vector<int>> ans;
    for(int row = 0; row < rows; ++row) {
        vector<int> curr(M[row], M[row] + cols);
        
        if(!tr.find(curr)) {
            tr.insert(curr);
            ans.push_back(curr);
        }
    }
    
    return ans;
}
