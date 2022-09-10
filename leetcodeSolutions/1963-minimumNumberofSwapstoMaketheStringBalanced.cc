class Solution {
public:
    int minSwaps(string s) {
      int n = s.length();
      
      int ptr = n - 1;
      while(ptr >= 0 && s[ptr] != '[') {
        --ptr;
      }
      
      int open = 0, close = 0, cnt = 0;
      for(int i = 0; i < n; ++i) {
        open += s[i] == '[';
        close += s[i] == ']';
        
        if(close > open) {
          ++cnt, --close, ++open;
          swap(s[i], s[ptr--]);
          while(ptr >= 0 && s[ptr] != '[') {
            --ptr;
          }
        }
      }
      
      return cnt;
    }
};
