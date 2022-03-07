class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
      int rows = obstacleGrid.size(), cols = obstacleGrid[0].size();
      
      if(obstacleGrid[rows - 1][cols - 1] || obstacleGrid[0][0]) return 0;  //  edge cases
      
      vector<vector<int>> unique_path(rows, vector<int>(cols));
      unique_path[0][0] = 1;
      
      for(int row = 0; row < rows; ++row){
        for(int col = 0; col < cols; ++col){
          if(row == 0 && col == 0) unique_path[row][col] = 1;
          else if(!obstacleGrid[row][col]){
            unique_path[row][col] = (row - 1 < 0 ? 0 : unique_path[row - 1][col]) + (col - 1 < 0 ? 0 : unique_path[row][col - 1]);
          }
        }
      }
      
      return unique_path[rows - 1][cols - 1];
    }
};
