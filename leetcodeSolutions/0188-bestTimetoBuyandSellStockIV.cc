class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
      int n = prices.size();
      vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(k + 1, vector<int>(2, -1)));
      auto recur = [&](const auto recur, const int idx, const int &k, const bool &is_holding){
        if(idx == n) {
          return 0;
        }
        
        if(!k) {
          return 0;
        }
        
        if(dp[idx][k][is_holding] != -1) {
          return dp[idx][k][is_holding];
        }
        
        int skip = recur(recur, idx + 1, k, is_holding);
        int other;
        
        if(is_holding) {
          // sell
          other = prices[idx] + recur(recur, idx + 1, k - 1, !is_holding);
        } else {
          // buy
          other = -prices[idx] + recur(recur, idx + 1, k, !is_holding);
        }
        
        
        return dp[idx][k][is_holding] = max(skip, other);
      };
      
      return recur(recur, 0, k, 0);
    }
};
