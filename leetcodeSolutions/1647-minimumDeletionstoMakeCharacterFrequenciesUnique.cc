class Solution {
public:
    int minDeletions(string s) {
      const int CHAR_SET = 26;
      int *fa = new int[CHAR_SET]{0};
      
      for(char &ch: s) {
        ++fa[ch - 'a'];
      }
      
      sort(fa, fa + CHAR_SET);
      
      unordered_set<int> se;
      int cnt = 0;
      for(int i = 0; i < CHAR_SET; ++i) {
        if(fa[i]) {
          while(se.find(fa[i]) != se.end()) {
            ++cnt, --fa[i];
          }
        }
        
        //  don't insert 0
        if(fa[i]) {
          se.insert(fa[i]);
        }
      }
      
      return cnt;
    }
};
