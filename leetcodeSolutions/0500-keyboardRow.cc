class Solution {
public:
    vector<string> findWords(vector<string>& words) {
      vector<string> rows{"qwertyuiopQWERTYUIOP", "asdfghjklASDFGHJKL", "zxcvbnmZXCVBNM"};
      
      auto check = [](const string &word, const string &row){
        for(char ch: word) {
          if(row.find(ch) == string::npos) return false;
        }
        return true;
      };
      
      vector<string> ans;
      for(string &word: words) {
        for(int i = 0; i < rows.size(); ++i) {
          if(check(word, rows[i])) {
            ans.push_back(word);
            break;
          }
        }
      }
      
      return ans;
    }
};
