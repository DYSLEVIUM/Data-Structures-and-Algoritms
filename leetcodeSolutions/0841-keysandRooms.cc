class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
      int n = rooms.size();
      
      vector<bool> visited(n, false);
      auto dfs = [&visited, &rooms](const auto& dfs, const int& node){
        if(visited[node]) return;
        
        visited[node] = true;
        
        for(auto& key: rooms[node]) dfs(dfs, key);
      };
      
      dfs(dfs, 0);
      
      for(auto node_visited: visited) if(!node_visited) return false;
      
      return true;
    }
};
