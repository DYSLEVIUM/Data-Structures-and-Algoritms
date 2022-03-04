class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
      constexpr int n = 100;
      
      vector<vector<double>> dp(n + 1, vector<double>(n + 1));
      dp[0][0] = poured;
    
      //  simulating the process
      for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++) {
          // If the glass >= 1
          if (dp[i][j] >= 1) {
            // split  (dp[i][j] - 1) into next level
            dp[i + 1][j] += (dp[i][j] - 1) / 2.0;
            dp[i + 1][j + 1] += (dp[i][j] - 1) / 2.0;
            dp[i][j] = 1;
          }
        }
      }
      
      return dp[query_row][query_glass];
    }
};
