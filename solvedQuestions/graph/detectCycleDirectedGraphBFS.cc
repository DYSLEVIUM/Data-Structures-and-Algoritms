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
        vector<int> ordering;
        
        vector<int> indegree(V, 0);
        
        for(int i=0;i<V;++i){
            for(auto neighbour: adj[i]){
                ++indegree[neighbour];
            }
        }
        
        queue<int> qu;
        
        for(int i=0;i<V;++i){
            if(indegree[i]==0) qu.push(i);
        }
        
        while(!qu.empty()){
            int fr = qu.front();
            qu.pop();
            ordering.emplace_back(fr);
            
            for(auto neighbour: adj[fr]){
                --indegree[neighbour];
                if(indegree[neighbour]==0) qu.push(neighbour);
            }
        }
        
        return ordering.size()!=V;
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
