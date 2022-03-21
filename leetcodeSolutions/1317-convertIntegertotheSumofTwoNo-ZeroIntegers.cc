class Solution {
public:
    vector<int> getNoZeroIntegers(int n) {
      auto contains_zero = [](int num){
        while(num){
          if(num % 10 == 0) return true;
          num /= 10;
        }
        return false;
      };

      for(int i = 1; i <= n; ++i) {
        if(!contains_zero(i) && !contains_zero(n - i)) return {i, n - i};
      }
      
      return {0, 0};
    }
};
