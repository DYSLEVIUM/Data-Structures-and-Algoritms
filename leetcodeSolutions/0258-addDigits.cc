class Solution {
public:
    int addDigits(int num) {
      if(num == 0) return 0;
      if(floor(log10(num) + 1) == 1) return num;
      
      int new_num = 0;
      while(num){
        new_num += (num % 10);
        num /= 10;
      }
      
      return addDigits(new_num);
    }
};
