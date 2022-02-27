class Solution {
public:
    bool isAnagram(string s, string t) {
      int *fa_s = new int[26];
      int *fa_t = new int[26];

      for(char& ch: s) ++fa_s[ch - 'a'];
      for(char& ch: t) ++fa_t[ch - 'a'];
    
      for(int i = 0; i < 26; ++i) if(fa_s[i] != fa_t[i]) return false;
      
      delete[] fa_s;
      delete[] fa_t;
      fa_s = fa_t = nullptr;
      
      return true;
    }
};
