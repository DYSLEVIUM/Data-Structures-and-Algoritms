class Solution {
public:
    int minimumSum(int num) {
      vector<int> digits;
      while(num){
        digits.push_back(num % 10);
        num /= 10;
      }
      sort(digits.begin(), digits.end());
      
      int num_1 = digits[0] * 10 + digits[2];
      int num_2 = digits[1] * 10 + digits[3];

      return num_1 + num_2;
    }
};
