class Solution {
public:
    int minCut(string s) {
      int n = s.length();
      
      vector<vector<int>> pal_dp(n, vector<int>(n, -1));
      auto is_pal = [&](const int &st, const int &ed){
        int st_c = st, ed_c = ed;
        
        if(pal_dp[st][ed] != -1) {
          return !!pal_dp[st][ed];
        }
        
        bool not_pal = false;
        while(st_c < ed_c) {
          if(s[st_c++] != s[ed_c--]) {
            not_pal = true;
            break;
          }
        }

        pal_dp[st][ed] = !not_pal;
        
        return !!pal_dp[st][ed];
      };
      
      vector<int> mcm_dp(n, -1);
      auto mcm = [&](const auto &mcm, const int &idx){
        if(idx == n) {
          return 0;
        }
        
        if(mcm_dp[idx] != -1) {
          return mcm_dp[idx];
        }
        
        int minn = 0x3f3f3f3f;
        for(int i = idx; i < n; ++i) {
          if(is_pal(idx, i)) {
            minn = min(minn, 1 + mcm(mcm, i + 1));
          }
        }
        
        return mcm_dp[idx] = minn;
      };
      
      // required paritions is 1 less than the total segments
      return mcm(mcm, 0) - 1;
    }
};
