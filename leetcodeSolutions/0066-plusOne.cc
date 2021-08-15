class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
      reverse(digits.begin(), digits.end());
      
      int carry = 1;
      
      for(int i=0;i<digits.size();++i){
        digits[i]+=carry;
        
        carry = digits[i]/10;
        digits[i]%=10;
      }
      
      if(carry){
        digits.emplace_back(1);
      }
      
      reverse(digits.begin(), digits.end());
      
      return digits;
    }
};
