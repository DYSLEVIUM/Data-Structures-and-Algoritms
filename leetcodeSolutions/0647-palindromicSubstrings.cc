class Solution {
public:
    int countSubstrings(string s) {
      //  can be achieved in O(n) with Manacher's algorithm
      int n = s.length();
      int cnt = 0;
      
      auto expand = [&](int le, int ri){
        while(le >= 0 && ri < n && s[le] == s[ri]) {
          --le, ++ri, ++cnt;
        }
        ++le, --ri;
      };
      
      for(int i = 0; i < n; ++i) {
        //  for odd length
        expand(i, i);
        //  for even length
        expand(i, i + 1);
      }
      
      return cnt;
    }
};
