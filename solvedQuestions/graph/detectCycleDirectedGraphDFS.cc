// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution
{
    public:
	//Function to detect cycle in a directed graph.
	bool isCyclic(int V, vector<int> adj[]) 
	{
	   	// code here
	   	vector<bool> visited(V, false);
	   	vector<bool> dfsVisited(V, false);
	   	
	   	auto dfs = [&visited, &dfsVisited, &V, &adj](const int& node, const auto& dfs)->bool{
	   	    visited[node] = true;    
	   	    dfsVisited[node] = true;
	   	    
	   	    for(auto neighbour: adj[node]){
	   	        if(!visited[neighbour]){
	   	            if(dfs(neighbour,dfs)) return true;
	   	        }else{
	   	            if(dfsVisited[neighbour]) return true;
	   	        }
	   	    }
	   	    
	   	    dfsVisited[node] = false;
	   	    return false;
	   	};
	   	
	   	for(int i=0;i<V;++i) {
	   	    if(!visited[i]){
	   	        if(dfs(i, dfs)) return true;
	   	    }
	   	}
	   	
	   	return false;
	}
};

// { Driver Code Starts.


int main()
{
    
    int t;
    cin >> t;
    while(t--)
    {
    	int V, E;
    	cin >> V >> E;

    	vector<int> adj[V];

    	for(int i = 0; i < E; i++)
    	{
    		int u, v;
    		cin >> u >> v;
    		adj[u].push_back(v);
    	}

    	Solution obj;
    	cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}

  // } Driver Code Ends
