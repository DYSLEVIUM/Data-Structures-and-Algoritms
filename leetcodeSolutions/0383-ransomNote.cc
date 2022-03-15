class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
      constexpr int N = 26;
      int *fa_r = new int[N]{0}, *fa_m = new int[N]{0};
      
      for(char& ch: ransomNote) ++fa_r[ch - 'a'];
      for(char& ch: magazine) ++fa_m[ch - 'a'];
      
      bool is_possible = true;
      for(int i = 0; i < N; ++i) if(fa_r[i] > fa_m[i]) is_possible = false;
      
      delete[] fa_r, fa_m;
      return is_possible;
    }
};
