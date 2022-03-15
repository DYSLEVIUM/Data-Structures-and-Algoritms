class Solution {
public:
    int firstUniqChar(string s) {
      constexpr int N = 26;
      int *fa = new int[N]{0};
      
      for(char& ch: s) ++fa[ch - 'a'];

      int ptr = 0;
      for(char& ch: s) {
        if(fa[ch - 'a'] == 1) return ptr;
        ++ptr;
      }
      
      delete[] fa;
      return -1;
    }
};
