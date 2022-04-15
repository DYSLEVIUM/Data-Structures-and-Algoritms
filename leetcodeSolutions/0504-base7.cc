class Solution {
public:
    string convertToBase7(int num) {
      if(!num) return "0";
      
      string ans = "";
      bool is_neg = false;
      
      if(num < 0) {
        num *= -1;
        is_neg = true;
      }
      
      while(num) {
        ans += to_string(num % 7);
        num /= 7;
      }
      reverse(ans.begin(), ans.end());
      
      return is_neg ? '-' + ans : ans;
    }
};
