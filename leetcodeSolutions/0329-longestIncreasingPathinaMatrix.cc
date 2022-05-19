class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
      //  dp solution
      int rows = matrix.size();
      if(!rows) return 0;
      
      int cols = matrix[0].size();
      
      vector<vector<int>> dp(rows, vector<int>(cols));
      auto dfs = [&](const auto& dfs, const int &row, const int &col) {
        if(dp[row][col]) return dp[row][col];
        
        vector<pair<int, int>> delta = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
        for (auto &[dy, dx] : delta) {
          int new_row = row + dy, new_col = col + dx;
            
          if(new_row < 0 || new_row >= rows || new_col < 0 || new_col >= cols) continue;
          if(matrix[new_row][new_col] <= matrix[row][col]) continue;
            
          dp[row][col] = max(dp[row][col], dfs(dfs, new_row, new_col));
        }
        return ++dp[row][col];
      };
      
      int maxx = INT_MIN;
      for(int row = 0; row < rows; ++row) {
        for(int col = 0; col < cols; ++col) {
          maxx = max(maxx, dfs(dfs, row, col));
        }
      }
      
      return maxx;
    }
};
