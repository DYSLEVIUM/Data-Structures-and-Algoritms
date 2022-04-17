class Solution {
public:
    string digitSum(string s, int k) {
      int n = s.length();
      if(n <= k) return s;
      
      auto get_sum = [](string s){
        int val = 0;
        while(!s.empty()) {
          val += s.back() - '0';
          s.pop_back();
        }
        
        return to_string(val);
      };
      
      string new_str = "";
      int i = 0;
      while(i < n) {
        new_str += get_sum(s.substr(i, min(k, n - i)));
        i += k;
      }
      
      return digitSum(new_str, k);
    }
};
