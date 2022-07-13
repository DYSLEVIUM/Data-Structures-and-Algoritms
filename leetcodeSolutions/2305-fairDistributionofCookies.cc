class Solution {
public:
    int distributeCookies(vector<int>& cookies, int k) {
      int n = cookies.size();
      const int mask_u = 1 << n;
      
      //  storing the sum of each subset
      vector<int> sum(mask_u);
      for(int mask = 0; mask < mask_u; ++mask) {
        int total = 0;
        for(int i = 0; i < n; ++i) {
          if(mask & (1 << i)) {
            total += cookies[i];
          }
        }
        
        sum[mask] = total;
      }
      
      //  time: O(k * (3 ^ n))
      //  space: O(2 ^ n) (with space optimization)
      //  dp[i][mask] denotes if we have in total i children and mask is the configuration of the cookies what will be the optimal answer for that. Then we simply iterate on all possible submask of the current mask and check if we parition the current mask into submask and the rest i - 1 children have (mask ^ submask) cookies what will be the optimal answer.
      vector<int> prev(mask_u, INT_MAX), curr(mask_u, INT_MAX);
      prev[0] = 0;
      for(int person = 1; person < k + 1; ++person) {
        //  this is O(3 ^ n), see: https://cp-algorithms.com/algebra/all-submasks.html#iterating-through-all-masks-with-their-submasks-complexity-o3n
        //  total submasks = 2^k, k is enabled bits,
        //  we have a total of nCk masks with enabled bits
        //  \sum_{k=0}^n \binom{n}{k} \cdot 2^k
        {
          for(int mask = 0; mask < mask_u; ++mask) {
            int best = INT_MAX;

            //  submask = all the subsets of the set formed by the set bits present in the binary representation of mask, e.g., for 5("101") => {"101", "100", "001", "000"}
            for(int submask = mask; submask; submask = mask & (submask - 1)) {
              //  get the maxx of the current_set and the best from previous
              int maxx = max(sum[submask], prev[mask ^ submask]);
              best = min(best, maxx);
            }

            curr[mask] = best;
          }
        }
        
        prev = curr;
      }
      
      return curr[mask_u - 1];
    }
};
