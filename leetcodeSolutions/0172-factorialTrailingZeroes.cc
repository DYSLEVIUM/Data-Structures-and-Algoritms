class Solution {
public:
    int trailingZeroes(int n) {
      int cnt = 0;
      
      int divisor = 5;
      while(divisor <= n) {
        cnt += n / divisor;
        divisor *= 5;
      }
      
      return cnt;
    }
};
