class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        int wires = connections.size();
        if(wires < n - 1) {
            return -1;
        }
        
        vector<vector<int>> adj(n);
        for(auto &connection : connections) {
            adj[connection[0]].push_back(connection[1]);
            adj[connection[1]].push_back(connection[0]);
        }
        
        vector<bool> vis(n);
        auto dfs = [&](const auto &dfs, const int &node){
            if(vis[node]) {
                return ;
            }
            
            vis[node] = true;
            for(auto &neigh : adj[node]) {
                dfs(dfs, neigh);
            }
        };
        
        int components = 0;
        for(int i = 0; i < n; ++i) {
            if(!vis[i]) {
                dfs(dfs, i);
                ++components;
            }
        }
        
        return components - 1;
    }
};
