class Solution {
public:
    int longestCycle(vector<int>& edges) {
      int n = edges.size();
      
      int maxx = -1;
      
      vector<bool> vis(n);
      auto dfs = [&](const auto &dfs, const int &node, vector<int> &curr_stack){
        if(node == -1) {
          return;
        }
        if(vis[node]) {
          int cnt = -1; // to detect 1->2->3, 4->3
          for(int i = 0; i < curr_stack.size(); ++i) {
            if(curr_stack[i] == node) {
              cnt = i;
              break;
            }
          }
          
          if(cnt == -1) {
            return;
          }
          
          int cycle_size = curr_stack.size() - cnt;
          maxx = max(maxx, cycle_size);
          
          return;
        }
        
        vis[node] = true;
        
        curr_stack.push_back(node);
        dfs(dfs, edges[node], curr_stack);
      };
      
      
      for(int i = 0; i < n; ++i) {
        if(vis[i]) {
          continue;
        }
        vector<int> curr_stack;
        dfs(dfs, i, curr_stack);
      }
      
      return maxx;
    }
};
