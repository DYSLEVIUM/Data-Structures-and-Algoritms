class Solution {
public:
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
      const int MOD = 1e9 + 7;
      vector<pair<int, int>> delta{{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
      
      auto is_out_of_bounds = [&](const int &row, const int & col){
        return row < 0 || row >= m || col < 0 || col >= n;
      };
      
//       using VI = vector<int>;
//       vector<vector<VI>> dp(maxMove + 1, vector<VI>(m, VI(n, -1)));
      
//       auto recur = [&](const auto& recur, const int &moves_left, const int &row, const int &col) {
//         if(is_out_of_bounds(row, col)) {
//           return 1;
//         }
        
//         if(!moves_left) {
//           return 0;
//         }
        
//         if(dp[moves_left][row][col] != -1) {
//           return dp[moves_left][row][col];
//         }
        
//         int val = 0;
//         for(auto &[dx, dy]: delta) {
//           val = (val + recur(recur, moves_left - 1, row + dx, col + dy)) % MOD;
//         }
        
//         return dp[moves_left][row][col] = val;
//       };
//       return recur(recur, maxMove, startRow, startColumn);
      
      vector<vector<int>> prev(m, vector<int>(n));
      prev[startRow][startColumn] = 1;
      int cnt = 0;
      
      for(int i = 0; i < maxMove; ++i) {
        vector<vector<int>> curr(m, vector<int>(n));
        
        for(int row = 0; row < m; ++row) {
          for(int col = 0; col < n; ++col) {            
            if (row == m - 1) cnt = (cnt + prev[row][col]) % MOD;
            if (col == n - 1) cnt = (cnt + prev[row][col]) % MOD;
            if (row == 0) cnt = (cnt + prev[row][col]) % MOD;
            if (col == 0) cnt = (cnt + prev[row][col]) % MOD;
            
            for(auto &[dx, dy]: delta) {
              int new_row = row + dx, new_col = col + dy;
              
              if(!is_out_of_bounds(new_row, new_col)) {
                curr[row][col] = (curr[row][col] + prev[new_row][new_col]) % MOD;
              }
            }
          }
        }
        prev = curr;
      }
      
      return cnt;
    }
};
