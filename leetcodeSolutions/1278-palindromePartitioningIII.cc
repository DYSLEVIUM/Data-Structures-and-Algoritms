class Solution {
public:
    int palindromePartition(string s, int k) {
      constexpr int INF = 0x3f3f3f3f;
      int n = s.length();
      auto min_changes = [&](const int &st, const int &ed){
        int st_c = st, ed_c = ed;
        int cnt = 0;
        while(st_c < ed_c) {
          cnt += s[st_c++] != s[ed_c--];
        }
        
        return cnt;
      };
      
      vector<vector<int>> dp(n, vector<int>(k, -1));
      // make k - 1 cuts for k segments
      auto mcm = [&](const auto &mcm, const int &idx, const int &cnt){
        if(idx == n) {
          return INF;
        }
        
        if(cnt == k - 1) {
          return min_changes(idx, n - 1);
        }
        
        if(dp[idx][cnt] != -1) {
          return dp[idx][cnt];  
        }
        
        int minn = INF;
        for(int i = idx; i < n; ++i) {
          int cost = min_changes(idx, i);
          minn = min(minn, cost + mcm(mcm, i + 1, cnt + 1));
        }
        
        return dp[idx][cnt] = minn;
      };
      
      return mcm(mcm, 0, 0);
    }
};
