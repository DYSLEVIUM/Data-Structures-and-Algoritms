class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
      int n1 = s1.length(), n2 = s2.length();
      
      if(n1 + n2 != s3.size()) {
        return false;
      }
      
      if(n1 < n2) {
        swap(s1, s2);
        swap(n1, n2);
      }
      
      vector<bool> dp(n2 + 1);
      for(int i = 0; i < n1 + 1; ++i) {
        for(int j = 0; j < n2 + 1; ++j) {
          if(i == 0 || j == 0) {
            if(i) {
              dp[j] = dp[j] && s1[i - 1] == s3[i + j - 1];
            } else if(j) {
              dp[j] = dp[j - 1] && s2[j - 1] == s3[i + j - 1];
            }
            if(!i && !j) {
              dp[j] = true;
            }
          } else {
            dp[j] = (dp[j] && s1[i - 1] == s3[i + j - 1]) || (dp[j - 1] && s2[j - 1] == s3[i + j - 1]);
          }
        }
      }
      
      return dp[n2];
    }
};
