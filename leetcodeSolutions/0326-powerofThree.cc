class Solution {
public:
    bool isPowerOfThree(int n) {
      constexpr auto bin_pow = [](int base, int pow){
        int res = 1;
        while(pow){
          if(pow & 1) res *= base;
          if(pow != 1) base *= base;
          
          pow >>= 1;
        }
        
        return res;
      };
      static_assert(bin_pow(2, 4) == 16);
      
      constexpr auto log_change_base_from_10 = [](const int& new_base, const int& x){
        return log10(x) * 1.00 / log10(new_base);
      };
      int max_num = bin_pow(3, log_change_base_from_10(3, INT_MAX));  //  this will contain all the powers of 3, i.e., 3^0, 3^1, ..., 3^log3(INT_MAX) till the valid max range
      return n > 0 && max_num % n == 0; //  n > 3, so that no other factor of 3 is valid so if n is power of 3, it has to divide max_num which contains all the powers of 3
    }
};
