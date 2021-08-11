// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution 
{
    public:
    //Function to detect cycle in an undirected graph.
	bool isCycle(int V, vector<int>adj[])
	{
	    // Code here
	    vector<int> visited(V, false);
	    
	    auto isCyclic = [&visited, &adj](int v, int parent, const auto& isCyclic)->bool{
	        visited[v] = true;
	        
	        for(auto neighbour: adj[v]){
	            if(!visited[neighbour]){
	                if(isCyclic(neighbour, v, isCyclic)) return true;        
	            }else if(parent != neighbour) return true;
	        }
	        
	        return false;
	    };
	    
	    for(int i=0;i<V;++i){
	        if(!visited[i]){
	            //  first node of each component has no parent as it is the starting point
	            if(isCyclic(i, -1, isCyclic)) return true;
	        }
	    }
	    
	    return false;
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
		bool ans = obj.isCycle(V, adj);
		if(ans)
			cout << "1\n";
		else cout << "0\n";
	}
	return 0;
}  // } Driver Code Ends
