class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
      int n = isConnected.size();
      vector<int> visited(n, false);
  
      auto dfs = [&n, &visited, &isConnected](const auto& dfs, const int& node){
        if(visited[node]) return;
        visited[node] = true;
        
        for(int i=0;i<n;++i){
          if(isConnected[node][i]) dfs(dfs, i);
        }
      };
      
      int connected_components = 0;
      
      for(int i=0;i<n;++i){
        if(!visited[i]) {
          ++connected_components;
          dfs(dfs, i);
        }
      }
      
      return connected_components;
    }
};
