class Solution {
public:
    string greatestLetter(string s) {
      const int CHAR_SET = 26;
      bool *lower = new bool[CHAR_SET];
      bool *upper = new bool[CHAR_SET];
      
      for(int i = CHAR_SET - 1; i >= 0; --i) {
        lower[i] = upper[i] = false;
      }
      
      for(char &ch: s) {
        if(ch >= 'a' && ch <= 'z') {
          lower[ch - 'a'] = true;
        } else if(ch >= 'A' && ch <= 'Z') {
          upper[ch - 'A'] = true;
        }
      }
      
      for(int i = CHAR_SET - 1; i >= 0; --i) {
        if(lower[i] && upper[i]) {
          string ans = "";
          ans += char(i + 'A');
          return ans;
        }
      }
      
      return "";
    }
};
