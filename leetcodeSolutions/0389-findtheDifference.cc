class Solution {
public:
    char findTheDifference(string s, string t) {
      constexpr int N = 26;
      int *fa_s = new int[N] , *fa_t = new int[N];

      for(char& ch: s) ++fa_s[ch - 'a'];
      for(char& ch: t) ++fa_t[ch - 'a'];

      for(int i = 0; i < N; ++i) if(fa_s[i] != fa_t[i]) return i + 'a';
      delete[] fa_s, fa_t;
      return '#';
    }
};
