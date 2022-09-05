class Solution {
public:
    string longestWord(vector<string>& words) {
      unordered_set<string> se(words.begin(), words.end());
      auto check = [&](string word){
        while(!word.empty()) {
          if(!se.count(word)) {
            return false;
          }
          word.pop_back();
        }
        return true;
      };
      
      string ans = "";
      for(auto &word : words) {
        if(check(word)) {
          int curr = word.length();
          if(curr > ans.length()) {
            ans = word;
          } else if(curr == ans.length() && word < ans) {
            ans = word;
          }
        }
      }
      
      return ans;
    }
};
