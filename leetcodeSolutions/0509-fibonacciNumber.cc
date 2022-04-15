class Solution {
public:
    int fib(int n) {
      if(n < 2) return n;
      
      int prev_prev = 0, prev = 1;
      n -= 1;
      while(n--) {
        int temp  = prev_prev + prev;
        prev_prev = prev;
        prev = temp;
      }
      
      return prev;
    }
};
