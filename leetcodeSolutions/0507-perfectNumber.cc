class Solution {
public:
    bool checkPerfectNumber(int num) {
      int sum = -num;
      int sq = sqrt(num);
      for(int i = 1; i <= sq; ++i) {
        if(num % i == 0) {
          sum += i;
          if(num / i != i) sum += (num / i);
        }
      }
      
      return sum == num;
    }
};
