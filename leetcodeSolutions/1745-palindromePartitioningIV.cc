class Solution {
public:
    bool checkPartitioning(string s) {
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
      
      vector<vector<int>> dp(n, vector<int>(3, -1));
      // to make 3 substring, we need 2 cuts
      auto mcm = [&](const auto &mcm, const int &idx, const int &cnt)->bool{
        if(idx == n) {
          return false;
        }
        
        if(cnt == 2) {
          return is_pal(idx, n - 1);
        }
        
        if(dp[idx][cnt] != -1) {
          return !!dp[idx][cnt];
        }
        
        bool is_possible = false;
        for(int i = idx; i < n; ++i) {
          if(is_pal(idx, i)) {
            is_possible = is_possible || mcm(mcm, i + 1, cnt + 1);
          }
        }
        
        return dp[idx][cnt] = is_possible;
      };
      
      return mcm(mcm, 0, 0);
    }
};
