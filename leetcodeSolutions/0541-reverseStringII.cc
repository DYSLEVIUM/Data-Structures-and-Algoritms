class Solution {
public:
    string reverseStr(string s, int k) {
      int n = s.length();
      
      int iter = 0;
      while(iter < n) {
        reverse(s.begin() + iter, (iter + k < n) ? s.begin() + iter + k : s.end());
        iter += 2 * k;
      }
      
      return s;
    }
};
