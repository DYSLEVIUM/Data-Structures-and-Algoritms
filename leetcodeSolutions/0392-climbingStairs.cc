class Solution {
public:
    bool isSubsequence(string s, string t) {
      if(s.size() > t.size()){
          return false;
      }
      
      int ptr_s = 0, ptr_t = 0;
      while(ptr_s != s.size()){
        if(ptr_t >= t.size()) {
            return false;
        }
          
        if(s[ptr_s] != t[ptr_t]) {
            ++ptr_t;
        } else{
            ++ptr_s, ++ptr_t;
        }
      }
        
      return true;
    }
};
