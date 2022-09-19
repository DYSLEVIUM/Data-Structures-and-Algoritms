class Solution {
public:
    int climbStairs(int n) {
      vector<int> dp(2, 1);
      for(int i = 2; i < n + 1; ++i) {
        dp[1] += dp[0];
        dp[0] = dp[1] - dp[0];
      }
      return dp[1];
    }
};
