class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
      sort(g.begin(), g.end());      
      sort(s.begin(), s.end());

      int ans = 0;
      int g_ptr = 0, s_ptr = 0;
      while(g_ptr < g.size() && s_ptr < s.size()) {
        if(s[s_ptr] >= g[g_ptr]) {
          ++ans, ++s_ptr, ++g_ptr;
        } else {
          ++s_ptr;
        }
      }
      
      return ans;
    }
};
