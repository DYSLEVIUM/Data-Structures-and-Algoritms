class Solution {
public:
    int minimumNumbers(int num, int k) {
      if(num == 0) return 0;
      
      //  A1 + A2 + ... + An = sum
      //  A1 + A2 + ... + An = n * k + 10 * (a1 + a2 + .. + an), where (a1 + a2 + .. + an) can be any number
      int rem = num % 10;
      for(int i = 1; i < 10 + 1; ++i) {
        int prod = i * k;
        if(prod > num) {
          break;
        }
        if(prod % 10 == rem) {
          return i;
        }  
      }
      
      return -1;
    }
};
