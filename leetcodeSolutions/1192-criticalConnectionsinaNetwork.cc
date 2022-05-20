class Solution {
public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
      vector<vector<int>> gr(n);
      for(auto &connection: connections){
        int u = connection[0], v = connection[1];
        
        gr[u].push_back(v);
        gr[v].push_back(u);
      }
      
      auto tarjan_bridge = [&n](const vector<vector<int>> &gr){
        vector<vector<int>> bridges;
        
        vector<int> disc(n, -1), parent(n, -1), low_link(n);
        int time = 0;
        auto dfs = [&](const auto &dfs, const int &u) -> void {
          disc[u] = low_link[u] = time++;
           
          for(const int &v: gr[u]) {
            if(disc[v] == -1) {
              parent[v] = u;
              dfs(dfs, v);
              low_link[u] = min(low_link[u], low_link[v]);
              
              if(low_link[v] > disc[u]) bridges.push_back({u, v});
            } else if (v != parent[u]) {
              low_link[u] = min(low_link[u], disc[v]);
            }
          }
        };
        
        for(int i = 0; i < n; ++i) {
          if(disc[i] == -1) dfs(dfs, i);
        }
        
        return bridges;
      };
      
      return tarjan_bridge(gr);
    }
};
