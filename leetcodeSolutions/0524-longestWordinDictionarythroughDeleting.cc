class Solution {
public:
    string findLongestWord(string s, vector<string>& dictionary) {
      const int n1 = s.length();
      auto check = [&](const string &word){
        int n2 = word.length();
        int p1 = 0, p2 = 0;
        while(p1 < n1 && p2 < n2) {
          if(s[p1] == word[p2]) {
            ++p1, ++p2;
          } else {
            ++p1;
          }
        }
        return p2 == n2;
      };
      
      string ans = "";
      for(auto &word : dictionary) {
        if(check(word)) {
          int curr = word.length();
          if(curr > ans.length()) {
            ans = word; // longest word
          } else if(curr == ans.length() && word < ans) {
            ans = word; // lexicographically smaller string
          }
        }
      }
      
      return ans;
    }
};
