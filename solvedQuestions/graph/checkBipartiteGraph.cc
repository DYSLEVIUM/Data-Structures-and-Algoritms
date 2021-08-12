// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:
	bool isBipartite(int V, vector<int>adj[]){
	    // Code here
	    
	    vector<int> col(V, -1);
	    
	    auto checkBi = [&adj, &col](int node){
	        queue<int> qu;
	        
	        qu.push(node);
	        col[node]=0;
	        
	        while(!qu.empty()){
	            int fr = qu.front();
	            qu.pop();
	            
	            for(auto neighbour: adj[fr]){
	                if(col[neighbour]==-1){
	                    col[neighbour]=1-col[fr];
	                    qu.push(neighbour);
	                }else{
	                    if(col[neighbour]==col[fr]) return false;
	                }
	            }
	        }
	        
	        return true;
	    };
	    
	    for(int i=0;i<V;++i){
	        if(col[i]==-1){
	            if(!checkBi(i)) return false;
	        }
	    }
	    
	    return true;
	}

};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		Solution obj;
		bool ans = obj.isBipartite(V, adj);    
		if(ans)cout << "1\n";
		else cout << "0\n";  
	}
	return 0;
}  // } Driver Code Ends
