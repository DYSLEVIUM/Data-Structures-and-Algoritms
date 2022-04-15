class Solution {
public:
    string reverseStr(string s, int k) {
      int n = s.length();
      
      int iter = 0;
      while(iter < n) {
        if(iter + k >= n) {
          reverse(s.begin() + iter, s.end());
        } else {
          reverse(s.begin() + iter, s.begin() + iter + k);
        }

        iter += 2 * k;
      }
      
      return s;
    }
};
