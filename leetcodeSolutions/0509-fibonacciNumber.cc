class Solution {
public:
    int fib(int n) {
      if(n < 2) {
        return n;
      }

      int dp[2] = {0, 1};
      for(int i = 2; i < n + 1; ++i) {
        dp[1] += dp[0];
        dp[0] = dp[1] - dp[0];
      }
      
      return dp[1];
    }
};
