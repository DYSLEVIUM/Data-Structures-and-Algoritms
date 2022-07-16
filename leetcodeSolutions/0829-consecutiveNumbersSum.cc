class Solution {
public:
    int consecutiveNumbersSum(int n) {
      //  n = (1 + 2 + ... + x) + (x * offset); x belongs to natural numbers(N)
      //  n - (x * (x + 1) / 2) = x * offset; offset belongs to N0
      //  (n - (x * (x + 1) / 2)) % x = 0 && n >= (x * (x + 1) / 2)
      
      int ans = 0;
      for(int x = 1 ; n >= x * (x + 1) / 2; ++x) {
        ans += (n - x * (x + 1) / 2) % x == 0;
      }
      
      return ans;
    }
};
