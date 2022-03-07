class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
      int rows = grid.size(), cols = grid[0].size();
      
      vector<vector<int>> min_path(rows, vector<int>(cols));
      
      //  initialization
      min_path[0][0] = grid[0][0];
      for(int col = 1; col < cols; ++col) min_path[0][col] = min_path[0][col - 1] + grid[0][col];
      for(int row = 1; row < rows; ++row) min_path[row][0] = min_path[row - 1][0] + grid[row][0];
      
      for(int row = 1; row < rows; ++row){
        for(int col = 1; col < cols; ++col){
            min_path[row][col] = grid[row][col] + min(min_path[row - 1][col], min_path[row][col - 1]);
          }
        }
      
      return min_path[rows - 1][cols - 1];
    }
};
