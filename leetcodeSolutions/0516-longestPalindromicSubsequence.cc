class Solution {
public:
    int longestPalindromeSubseq(string s) {
      string t = s;
      reverse(t.begin(), t.end());
      
      auto lcs = [](const string& x, const string& y){
        int n1 = x.length(), n2 = y.length();
        vector<vector<int>> dp(n1 + 1, vector<int>(n2 + 1));
        
        for(int i = 1; i < n1 + 1; ++i) {
          for(int j = 1; j < n2 + 1; ++j) {
            if(x[i - 1] == y[j - 1]) {
              dp[i][j] = 1 + dp[i - 1][j - 1];
            } else {
              dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
          }
        }
      
        return dp[n1][n2];
      };
      
      return lcs(s, t);
    }
};
