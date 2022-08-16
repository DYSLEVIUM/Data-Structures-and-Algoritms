class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
      constexpr int INF = 0x3f3f3f3f;
      int n = coins.size();
      
      vector<int> curr(amount + 1, INF), prev(amount + 1, INF);
      for(int i = 0; i < n + 1; ++i) {
        for(int j = 0; j < amount + 1; ++j) {
          if(!i || !j) {
            if(!j) {
              curr[j] = 0;
            }
            continue;
          }
          
          if(j - coins[i - 1] >= 0) {
            curr[j] = min(prev[j], 1 + curr[j - coins[i - 1]]);
          } else {
            curr[j] = prev[j];
          }
        }
        
        prev = curr;
      }
      
      return prev[amount] == INF ? -1 : prev[amount];
    }
};
