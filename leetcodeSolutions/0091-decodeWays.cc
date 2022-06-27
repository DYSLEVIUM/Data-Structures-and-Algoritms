class Solution {
public:
    int numDecodings(const string &s) {
      int n = s.size();
      int curr = 0, next = 1, next_next = 0;
      for(int i = n - 1; i >= 0; --i) {
        if(s[i] != '0') {
          curr += next;
        }
        if(i + 1 < s.size() && (s[i] == '1' || s[i] == '2' && s[i + 1] <= '6')) {
          curr += next_next;
        }
        
        next_next = next;
        next = curr;
        curr = 0;
      }
      
      return next;
    }
};
