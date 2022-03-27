class Solution {
public:
    int maxValueOfCoins(vector<vector<int>>& piles, int k) {
      int n = piles.size();
      vector<vector<int>> dp(n + 1, vector<int>(k + 1, 0));
      
      //  prefix sum for each piles
      for(int i = 0; i < n; ++i) {
        for(int j = 1; j < piles[i].size(); ++j) {
          piles[i][j] += piles[i][j - 1];
        }
      }
      
      for(int i = 1; i < n + 1; ++i) {
        for(int j = 1; j < k + 1; ++j) {  // calculate max total value to pick  j coins using i piles.
          for(int x = 0; x <= piles[i - 1].size() && x <= j; ++x) { // check for all combinations of coins that sum upto j coins. We can pick x coins from this pile and j - x coins from previous piles(dp[i - 1][j - x]) i. e.,(j - x) + x = j coins in total
            dp[i][j] = max(dp[i][j], dp[i - 1][j - x] + (x - 1 >= 0 ? piles[i - 1][x - 1] : 0));
          }
        }
      }
      
      return dp[n][k];
    }
  
//   int maxValueOfCoins(vector<vector<int>>& piles, int k) {
//       int n = piles.size();
//       vector<vector<int>> dp(n + 1);
      
//       for(int i = 0; i < n; ++i) {
//         dp[i] = vector<int>(k + 1, -1);
//       }  
    
//       auto recur = [&piles, &n, &dp](const auto& recur, const int& idx, const int& k){
//         if(idx == n) return 0;
        
//         if(dp[idx][k] != -1) return dp[idx][k];

//         int maxi = 0, sum = 0;
//         for(int j = 0; j < piles[idx].size(); ++j) {
//           sum += piles[idx][j];
//           if(k -(j + 1) >= 0) maxi = max({maxi, sum + recur(recur, idx + 1, k - (j + 1)), recur(recur, idx + 1, k)});
//         }
        
//         return dp[idx][k] = maxi;
//       };
    
//       return recur(recur, 0, k);
//     }
};
