class Solution {
public:
    int minSteps(string s, string t) {
      const int N = 26;
      
      int *fa_s = new int[N]{0}, *fa_t = new int[N]{0};
      for(char& ch: s) ++fa_s[ch - 'a'];
      for(char& ch: t) ++fa_t[ch - 'a'];
      
      int ans = 0;
      for(int i = 0; i < N; ++i) ans += abs(fa_s[i] - fa_t[i]);
      
      return ans;
    }
};
