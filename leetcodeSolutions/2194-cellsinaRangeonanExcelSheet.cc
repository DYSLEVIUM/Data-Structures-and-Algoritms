class Solution {
public:
    vector<string> cellsInRange(string s) {
      char start_col = s[0], end_col = s[3];
      int start_row = s[1] - '0', end_row = s[4] - '0';

      vector<string> ans;
      for(char ch = start_col; ch <= end_col; ++ch){
        for(int num = start_row; num <= end_row; ++num){
          ans.push_back(ch + to_string(num));
        }
      }
      
      return ans;
    }
};
