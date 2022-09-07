class Solution {
public:
    vector<string> letterCasePermutation(string s) {
      int n = s.length();
      
      unordered_set<string> ans;
      auto recur = [&](const auto &recur, const int &idx, const string &curr_str){
        if(idx == n) {
          ans.insert(curr_str);
          return ;
        }
        
        // no change
        recur(recur, idx + 1, curr_str + s[idx]);
        
        // making uppercase
        if(s[idx] >= 'a' && s[idx] <= 'z') {
          recur(recur, idx + 1, curr_str + char(s[idx] - 'a' + 'A'));        
        }
        
        // making lowercase
        if(s[idx] >= 'A' && s[idx] <= 'Z') {
          recur(recur, idx + 1, curr_str + char(s[idx] - 'A' + 'a'));        
        }
      };
      recur(recur, 0, "");
      
      return vector<string>(ans.begin(), ans.end());
    }
};
