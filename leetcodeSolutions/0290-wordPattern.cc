class Solution {
public:
    bool wordPattern(string pattern, string s) {
      vector<string> words;
      string curr_word = "";
      for(char& ch: s){
        if(ch == ' '){
          words.push_back(curr_word);
          curr_word = "";
        }else curr_word += ch;
      }
      words.push_back(curr_word);
      
      if(words.size() != pattern.length()) return false;
      
      unordered_map<char, string> mp;
      unordered_set<string> se;
      int ptr = 0;
      for(string& word:words){
        if(mp.find(pattern[ptr]) != mp.end()){
            if(mp[pattern[ptr]] != word) return false;
          }else {
            if(se.find(word) != se.end()) return false;
            se.insert(word);
            mp[pattern[ptr]] = word;
          }
          ++ptr;
      }
      
      return true;
    }
};
