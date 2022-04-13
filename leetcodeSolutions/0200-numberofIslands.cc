class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
      int rows = grid.size(), cols = grid[0].size();
      vector<int> dx{0, -1, 1, 0}, dy{-1, 0, 0, 1};
      
      vector<vector<bool>> vis(rows, vector<bool>(cols, false));
      auto dfs = [&grid, &rows, &cols, &dx, &dy, &vis](const auto &dfs, const int &row, const int &col){
        if(row < 0 || row == rows || col < 0 || col == cols || vis[row][col] || !(grid[row][col] - '0')) return;
        
        vis[row][col] = true;
        for(int i = 0; i < dx.size(); ++i) dfs(dfs, row + dx[i], col + dy[i]);
      };
      
      int ans = 0;
      for(int row = 0; row < rows; ++row) {
        for(int col = 0; col < cols; ++col) {
          if(!vis[row][col] && (grid[row][col] - '0')) {
            ++ans;
            dfs(dfs, row, col);
          }
        }
      }
      
      return ans;
    }
};
