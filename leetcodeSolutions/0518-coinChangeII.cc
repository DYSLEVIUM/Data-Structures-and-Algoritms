class Solution {
public:
    int change(int amount, vector<int>& coins) {
      int n = coins.size();
      vector<int> prev(amount + 1), curr(amount + 1);
      for(int i = 0; i < n + 1; ++i) {
        for(int j = 0; j < amount + 1; ++j) {
          if(!i || !j) {
            if(!i) {
              curr[j] = 0;
            }
            
            if(!j) {
              curr[j] = 1;
            }
          } else {
            curr[j] = prev[j];
            
            if(j - coins[i - 1] >= 0) {
              curr[j] += curr[j - coins[i - 1]];
            }
          }
        }
        
        prev = curr;
      }
      
      return curr[amount];
    }
};
