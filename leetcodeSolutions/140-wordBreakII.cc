class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
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
      
      vector<string> ans;
      auto mcm = [&](const auto &mcm, const int &idx, const string &curr_ans){
        if(idx == n) {
          string temp = curr_ans;
          temp.pop_back();
          ans.push_back(temp);
          return true;
        }
        
        bool is_possible = false;
        for(int i = idx; i < n; ++i) {
          if(is_present[idx][i]) {
            is_possible |= mcm(mcm, i + 1, curr_ans + s.substr(idx, i - idx + 1) + " ");
          }
        }
        
        return is_possible;
      };
      mcm(mcm, 0, "");
      
      return ans; 
    }
};
