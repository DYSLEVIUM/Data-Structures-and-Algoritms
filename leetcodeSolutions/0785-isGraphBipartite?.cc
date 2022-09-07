class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
      int n = graph.size();
      
      // -1 -> not colored
      // 0  -> color 1
      // 1  -> color 2
      vector<int> color(n, -1);
      auto dfs = [&](const auto &dfs, const int &node, const int &par_col){
        if(color[node] != -1) {
          if(color[node] == par_col) {
            return false;
          }
          return true;
        }
        
        color[node] = par_col ^ 0 ^ 1;
        for(auto &neigh : graph[node]) {
          if(!dfs(dfs, neigh, color[node])) {
            return false;
          }
        }
        return true;
      };
      
      for(int i = 0; i < n; ++i) {
        if(color[i] == -1) {
          if(!dfs(dfs, i, 1)) {
            return false;
          }
        }
      }
      
      return true;
    }
};
