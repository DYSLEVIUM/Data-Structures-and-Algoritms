// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:
	bool isBipartite(int V, vector<int>adj[]){
	    // Code here
	    
	    vector<int> color(V, -1);
	    
	    auto checkBi = [&adj, &color](int node){
	        queue<int> qu;
	        
	        qu.push(node);
	        color[node]=0;
	        
	        while(!qu.empty()){
	            int fr = qu.front();
	            qu.pop();
	            
	            for(auto neighbour: adj[fr]){
	                if(color[neighbour]==-1){
	                    color[neighbour]=1-color[fr];
	                    qu.push(neighbour);
	                }else{
	                    if(color[neighbour]==color[fr]) return false;
	                }
	            }
	        }
	        
	        return true;
	    };
	    
	    for(int i=0;i<V;++i){
	        if(color[i]==-1){
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
