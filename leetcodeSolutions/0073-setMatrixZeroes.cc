class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
      int rows = matrix.size(), cols = matrix[0].size();
      auto set_row_col_before_zero = [&matrix](const int& row_m, const int& col_m){
        for(int col = 0; col < col_m; ++col) matrix[row_m][col] = 0;
        for(int row = 0; row < row_m; ++row) matrix[row][col_m] = 0;
      };
      
      vector<pair<int, int>> points;
      
      for(int row = 0; row < rows; ++row)
        for(int col = 0; col < cols; ++col)
          if(!matrix[row][col]) {
            set_row_col_before_zero(row, col);
            points.push_back({row, col});
          }
    
      auto set_row_col_after_zero = [&matrix, &rows, &cols](const int& row_m, const int& col_m){
        for(int col = col_m + 1; col < cols; ++col) matrix[row_m][col] = 0;
        for(int row = row_m + 1; row < rows; ++row) matrix[row][col_m] = 0;
      };

      for(auto& [row, col]: points) set_row_col_after_zero(row, col);
    }
};
