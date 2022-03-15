class Solution {
public:
    string addStrings(string num1, string num2) {
      reverse(num1.begin(), num1.end());
      reverse(num2.begin(), num2.end());

      string ans = "";      
      int ptr_1 = 0, ptr_2 = 0, carry = 0;
      
      while(ptr_1 < num1.length() && ptr_2 < num2.length()){
        int digi_1 = num1[ptr_1++] - '0';
        int digi_2 = num2[ptr_2++] - '0';

        ans += to_string((digi_1 + digi_2 + carry) % 10);
        carry = (digi_1 + digi_2 + carry) / 10;
      }

      while(ptr_1 < num1.length()){
        int digi = num1[ptr_1++] - '0';
        ans += to_string((digi + carry) % 10);
        carry = (digi + carry) / 10;
      }
      
      while(ptr_2 < num2.length()){
        int digi = num2[ptr_2++] - '0';
        ans += to_string((digi + carry) % 10);
        carry = (digi + carry) / 10;
      }
      
      if(carry) ans += to_string(carry);
      
      reverse(ans.begin(), ans.end());
      return ans;      
    }
};
