class Solution {
public:
    int largestIsland(vector<vector<int>>& grid) {
      int rows = grid.size();
      if(!rows) {
        return 0;
      }
      int cols = grid[0].size();
      
      vector<vector<pair<int, int>>> parent(rows, vector<pair<int, int>>(cols, {-1, -1}));
      map<pair<int, int>, int> root_node_cnt;
      vector<pair<int, int>> delta{{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
      auto dfs = [&](const auto &dfs, const int &row, const int &col, const pair<int, int> &root){
        if(row < 0 || row >= rows || col < 0 || col >= cols || parent[row][col].first != -1 || !grid[row][col]) {
          return;
        }
        
        parent[row][col] = root;
        ++root_node_cnt[root];
        for(auto &[dx, dy]: delta) {
          dfs(dfs, row + dx, col + dy, root);
        }
      };
      
      for(int row = 0; row < rows; ++row) {
        for(int col = 0; col < cols; ++col) {
          dfs(dfs, row, col, {row, col});
        }
      }
      
      auto get_neighbour = [&](const int &row, const int &col){
        set<pair<int, int>> se;
        
        int res = 0;
        for(auto &[dx, dy]: delta) {
          int new_row = row + dx, new_col = col + dy;
          if(new_row < 0 || new_row >= rows || new_col < 0 || new_col >= cols || se.find(parent[new_row][new_col]) != se.end()) {
            continue;
          }
          se.insert(parent[new_row][new_col]);
          res += root_node_cnt[parent[new_row][new_col]];
        }
        
        return res;
      };
      
      int ans = INT_MIN;
      for(int row = 0; row < rows; ++row) {
        for(int col = 0; col < cols; ++col) {
          int curr_ans;
          if(!grid[row][col]) {
            curr_ans = 1 + get_neighbour(row, col);
          } else {
            curr_ans = root_node_cnt[{row, col}];
          }
          ans = max(ans, curr_ans);
        }
      }
      
      return ans;
    }
};
