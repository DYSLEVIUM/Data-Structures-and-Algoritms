class Solution {
public:
    string reverseWords(string s) {
      int n = s.length();
      reverse(s.begin(), s.end());
      
      int ptr_1 = 0, ptr_2 = 0;
      while(ptr_2 < n) {
        if(s[ptr_2] == ' ') {
          reverse(s.begin() + ptr_1, s.begin() + ptr_2);
          ptr_1 = ptr_2 + 1;
        }
        ++ptr_2;
      }
      reverse(s.begin() + ptr_1, s.end());
      
      auto remove_whitespace = [](string &s){
        int ptr_1 = 0;
        //  white space from the front
        while(s[ptr_1] == ' ') ++ptr_1;
        s = s.substr(ptr_1, s.length() - ptr_1);
        
        //  white space from the back
        ptr_1 = s.length() - 1;
        while(s[ptr_1] == ' ') --ptr_1;
        s = s.substr(0, ptr_1 + 1);
        
        //  white space in between
        ptr_1 = 0;
        while(ptr_1 < s.length()){
          if(s[ptr_1] == ' ' && ptr_1 + 1 < s.length() && s[ptr_1 + 1] == ' ') {
            s.erase(s.begin() + ptr_1 + 1);
          } else {
            ++ptr_1;
          }
        }
      };
      remove_whitespace(s);
      
      return s;
    }
};
