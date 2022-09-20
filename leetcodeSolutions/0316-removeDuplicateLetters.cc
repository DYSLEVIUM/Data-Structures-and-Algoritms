class Solution {
public:
    string removeDuplicateLetters(string s) {
      constexpr static int CHAR_SET = 256;
      static_assert(CHAR_SET == 256);
      
      int n = s.size();

      vector<int> fa(CHAR_SET);
      vector<int> vis(CHAR_SET);

      for(auto &ch : s) {
        ++fa[ch];
      }
      
      string ans;
      for(auto &ch : s) {
        --fa[ch];
        if(vis[ch]) {
          continue;
        }
        
        while(!ans.empty() && ans.back() > ch && fa[ans.back()] != 0) {
          vis[ans.back()] = 0;
          ans.pop_back();
        }
        
        vis[ch] = 1;
        ans += ch;
      } 
      
      return ans;
    }
};
