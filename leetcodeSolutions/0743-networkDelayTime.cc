class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
      vector<vector<pair<int, int>>> gr(n);
      for(auto &time: times) {
        int u = time[0], v = time[1], w = time[2];
        --u, --v;
        
        gr[u].push_back({v, w});
      }
      
      //  dijkstra
      vector<int> dist(n, INT_MAX);
      dist[--k] = 0;
      
      queue<pair<int, int>> qu;
      qu.push({k, 0});
      
      while(!qu.empty()) {
        auto [node, curr_dist] = qu.front();
        qu.pop();

        for(auto &neighbour: gr[node]) {
          int new_dist = curr_dist + neighbour.second;
          if(new_dist < dist[neighbour.first]) {
            dist[neighbour.first] = new_dist;
            qu.push({neighbour.first, new_dist});
          }
        }
      }
      
      int ans = INT_MIN;
      for(int i = 0; i < dist.size(); ++i) ans = max(ans, dist[i]);
      
      return (ans == INT_MAX) ? -1 : ans;
    }
};
