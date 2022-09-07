class Solution {
public:
    int orderOfLargestPlusSign(int n, vector<vector<int>>& mines) {
      unordered_set<int> mines_set;
      for(auto &mine : mines) {
        mines_set.insert(mine[0] * n + mine[1]);
      }
      
      // final state will be, consecutive 1's from all direction which is minimal
      vector<vector<int>> dp(n, vector<int>(n, INT_MAX));
      int ans = INT_MIN;
      
      // row
      for(int row = 0; row < n; ++row) {
        int cnt = 0;
        // prefix
        for(int col = 0; col < n; ++col) {
          cnt = mines_set.count(row * n + col) ? 0 : cnt + 1;
          dp[row][col] = cnt;
        }
        
        cnt = 0;
        // suffix
        for(int col = n - 1; col >= 0; --col) {
          cnt = mines_set.count(row * n + col) ? 0 : cnt + 1;
          dp[row][col] = min(dp[row][col], cnt);
        }
      }
      
      // cols
      for(int col = 0; col < n; ++col) {
        int cnt = 0;
        // prefix
        for(int row = 0; row < n; ++row) {
          cnt = mines_set.count(row * n + col) ? 0 : cnt + 1;
          dp[row][col] = min(dp[row][col], cnt);
        }
        
        cnt = 0;
        // suffix
        for(int row = n - 1; row >= 0; --row) {
          cnt = mines_set.count(row * n + col) ? 0 : cnt + 1;
          dp[row][col] = min(dp[row][col], cnt);
          
          ans = max(ans, dp[row][col]);
        }
      }
      
      return ans;
    }
};
