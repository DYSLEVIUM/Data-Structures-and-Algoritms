// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:
	bool isBipartite(int V, vector<int>adj[]){
	   vector<int> color(V, -1);
	    
	    auto checkBi = [&adj, &color](int& node, const auto& checkBi)->bool{
	        if (color[node] == -1) color[node] = 0;

            for (auto neighbour : adj[node]) {
                if (color[neighbour] == -1) {
                  color[neighbour] = 1 - color[node];
                  if (!checkBi(neighbour, checkBi)) return false;
                } else {
                  if (color[neighbour] == color[node]) return false;
                }
            }
            
            return true;
	    };
	    
	    for(int i=0;i<V;++i){
	        if(color[i]==-1){
	            if(!checkBi(i, checkBi)) return false;
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
