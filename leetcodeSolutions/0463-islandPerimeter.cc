class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
      int rows = grid.size();
      if(!rows) return 0;
      
      int cols = grid[0].size();
      
      int perimeter = 0;
      vector<vector<bool>> vis(rows, vector<bool>(cols, false));
      auto dfs = [&](const auto &dfs, const int &row, const int& col){
        if(row < 0 || row >= rows || col < 0 || col >= cols || !grid[row][col]) {
          ++perimeter;
          return;
        }
        
        if(vis[row][col] && grid[row][col]) return;
        
        vis[row][col] = true;
        
        vector<pair<int, int>> delta{{-1, 0}, {0, -1}, {0, 1}, {1, 0}};
        for(auto &[drow, dcol]: delta) {
          dfs(dfs, row + drow, col + dcol);
        }
      };
      
      for(int row = 0; row < rows; ++row) {
        for(int col = 0; col < cols; ++col) {
          //  finding the first island piece
          if(grid[row][col]) {
            dfs(dfs, row, col);
            
            //  acc. to question only 1 island is present
            return perimeter;
          }
        }
      }
      
      return perimeter;
    }
};
