class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) {
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
        
        string lcs_string = "";
        int x_ptr = n1, y_ptr = n2;
        
        while(x_ptr > 0 && y_ptr > 0) {
          if(x[x_ptr - 1] == y[y_ptr - 1]) {
            lcs_string += x[x_ptr - 1];
            --x_ptr, --y_ptr;
          } else {
            if(dp[x_ptr - 1][y_ptr] > dp[x_ptr][y_ptr - 1]) {
              lcs_string += x[x_ptr - 1];
              --x_ptr;
            } else {
              lcs_string += y[y_ptr - 1];
              --y_ptr;
            }
          }
        }
        
        while(x_ptr > 0) {
          lcs_string += x[x_ptr - 1];
          --x_ptr;
        }
        
        while(y_ptr > 0) {
          lcs_string += y[y_ptr - 1];
          --y_ptr;
        }
        
        reverse(lcs_string.begin(), lcs_string.end());
        return lcs_string;
      };
      
      return lcs(str1, str2);
    }
};
