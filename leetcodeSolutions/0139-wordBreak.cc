class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
      int n = s.length();
      unordered_set<string> dict(wordDict.begin(), wordDict.end());
  
      vector<vector<bool>> is_present(n, vector<bool>(n));
      for(int i = 0; i < n; ++i) {
        string curr_str = "";
        for(int j = i; j < n; ++j) {
          curr_str += s[j];
          is_present[i][j] = dict.count(curr_str);
        }
      }
      
      vector<int> dp(n, -1);
      auto mcm = [&](const auto &mcm, const int &idx){
        if(idx == n) {
          return true;
        }
        
        if(dp[idx] != -1) {
          return !!dp[idx];
        }
        
        bool is_possible = false;
        for(int i = idx; i < n; ++i) {
          if(is_present[idx][i]) {
            is_possible |= mcm(mcm, i + 1);
          }
        }
        dp[idx] = is_possible;
        
        return !!dp[idx];
      };
      
      return mcm(mcm, 0);
    }
};
