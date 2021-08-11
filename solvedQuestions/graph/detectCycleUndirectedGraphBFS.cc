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
	    
	    auto isCyclic = [&visited, &adj](int v){
	        //  queue for bfs with first as the node itself and the second as the parent of the node
	        queue<pair<int,int>> qu;
	        
	        visited[v] = true;
	        
	        //  this component's first node doesn't have a parent 
	        qu.push({v,-1});
	        
	        while(!qu.empty()){
	            int node = qu.front().first;
	            int parent = qu.front().second;
	            qu.pop();
	            
	            for(auto neighbour: adj[node]){
    	            if(!visited[neighbour]){
    	                visited[neighbour] = true;
    	                qu.push({neighbour, node});
    	            }else if(parent!=neighbour) return true;
	            }
	        }
	        
	        return false;
	    };
	    
	    for(int i=0;i<V;++i){
	        if(!visited[i]){
	            if(isCyclic(i)) return true;
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
