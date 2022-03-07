class Solution {
public:
    int countOrders(int n) {
      const int MOD = 1e9 + 7;
      auto mod_mul = [&MOD](const long& a, const long& b){
        return ((a % MOD) * (b % MOD)) % MOD;
      };
      
      //  using probability
      //  probability = favourable event / total outcomes ; here total outcomes = (2^N)!
      //  here, favourable event = probability * total outcomes
      //  also, probability of pickup appearing before delivery is 1/2
      //  now, probability of pickup appearing before delivery for n elements is (1/2)^N
      int ans = 1;
      
      auto bin_pow_m = [&MOD, &mod_mul](long a, long b){
        long res = 1;
        while(b){
          if(b & 1) res = mod_mul(res, a);
          a = mod_mul(a, a);
          b >>= 1;
        }
        return res % MOD;
      };
      
      for(int i = 1; i <= 2 * n; ++i){
        ans = mod_mul(ans, i);
        if(i % 2 == 0) ans = mod_mul(ans, bin_pow_m(2, MOD - 2)); //  multiplying with modular inverse
      }
      
      return ans;
      
      //  using spaces in between orders
//       vector<int> dp(n + 1);
//       dp[0] = 1;
      
//       //  let dp[i-1] be previous valid state, so in state i, we have 2 * i + 1 spaces
//       //  first permutate all pickups => n! ways
//       //  keep the deliveries in the gaps that start to appear => 1 * 3 * 5 * ... * (2*n - 1);
//       for(int i = 1; i <= n; ++i) {
//         dp[i] = mod_mul(dp[i - 1], i);
//         dp[i] = mod_mul(dp[i], (2 * i - 1));
//       }
      
//       return dp[n];

      //  bottom up approach
//       vector<vector<int>> dp(n + 1, vector<int>(n + 1));
//       for(int unpicked = 0; unpicked <= n; ++unpicked){
//         for(int undelivered = 0; undelivered <= n; ++undelivered){
//           if(!unpicked && !undelivered) {
//             dp[unpicked][undelivered] = 1;  //  1 way to order 0 order
//             continue;
//           }
          
//           if(unpicked > 0) dp[unpicked][undelivered] += mod_mul(unpicked, dp[unpicked - 1][undelivered]);
//           dp[unpicked][undelivered] %= MOD;
          
//           if(undelivered > unpicked) dp[unpicked][undelivered] += mod_mul(undelivered - unpicked, dp[unpicked][undelivered - 1]);
//           dp[unpicked][undelivered] %= MOD;
//         }
//       }
      
//       return dp[n][n];
      
      //  top down approach
//       vector<vector<int>> dp(n + 1, vector<int>(n + 1));
//       auto get_total_ways = [&mod_mul, &dp](const auto& get_total_ways, const int& unpicked, const int& undelivered){
//         if(!unpicked && !undelivered) return 1; //  this path is a valid solution
      //  We can't pick or deliver more than N items
      //  Number of deliveries can't exceed number of pickups 
      //  as we can only deliver after a pickup.
//         if(unpicked < 0 || undelivered < 0 || undelivered < unpicked) return 0; //  no solution is possible
        
//         if(dp[unpicked][undelivered]) return dp[unpicked][undelivered];
        
//         long long ans = 0;
        
//         ans += mod_mul(unpicked, get_total_ways(get_total_ways, unpicked - 1, undelivered));  //  total ways to select 2 elements from unpicked
//         ans %= MOD;
        
//         ans += mod_mul((undelivered - unpicked), get_total_ways(get_total_ways, unpicked, undelivered - 1));  //  total ways to select picked items from undelivered
//         ans %= MOD;
        
//         return dp[unpicked][undelivered] = ans;
//       };
      
//       return get_total_ways(get_total_ways, n, n);
    }
};
