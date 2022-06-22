class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
      int rows = grid.size();
      if(!rows) {
        return 0;
      }
      int cols = grid[0].size();
      
      vector<vector<bool>> visited(rows, vector<bool>(cols));
      vector<pair<int, int>> delta{{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
      auto dfs = [&](const auto &dfs, const int &row, const int &col){
        if(row < 0 || row >= rows || col < 0 || col >= cols || visited[row][col] || !grid[row][col]) {
          return 0;
        }
        
        visited[row][col] = true;
        
        int curr_cnt = 1; //  current node is 1
        for(auto &[dx, dy]: delta) {
          curr_cnt += dfs(dfs, row + dx, col + dy);
        }
        
        return curr_cnt;
      };
      
      int ans = 0;
      for(int row = 0; row < rows; ++row) {
        for(int col = 0; col < cols; ++col) {
          ans = max(ans, dfs(dfs, row, col));
        }
      }

      return ans;
    }
};
