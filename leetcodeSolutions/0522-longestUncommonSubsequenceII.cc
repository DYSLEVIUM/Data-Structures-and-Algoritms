class Solution {
public:
    int findLUSlength(vector<string>& strs) {
      int n = strs.size();
      
      // if s is a subsequence of t
      auto lcs = [](const string &s, const string &t){
        if(s.length() > t.length()) {
          return false;
        }

        int cnt = 0;
        for(auto &ch : t) {
          if(cnt < s.size() && s[cnt] == ch) {
            ++cnt;
          }
        }
        return cnt == s.size();
      };
      
      int maxx = -1;
      for(int i = 0; i < n; ++i) {
        int j = 0;
        while(j < n) {
          if(i != j) {
            if(lcs(strs[i], strs[j])) {
              break;
            }
          }
          ++j;
        }
        
        // strs[i] is a uncommon subsequence
        if(j == n) {
          maxx = max(maxx, (int)strs[i].size());
        }
      }
      
      return maxx;
    }
};
