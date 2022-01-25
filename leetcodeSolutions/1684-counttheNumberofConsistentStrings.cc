class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
      vector<bool> has_letter(26);
      
      for(auto& letter:allowed) has_letter[letter-'a'] = true;
      
      auto includes = [&has_letter](const string& word){
        int cnt = 0;
        for(auto& letter: word){
          if (has_letter[letter-'a']) ++cnt;
        }
        
        return cnt == word.length();
      };
      
      int ans = 0;
      for(auto& word: words) ans += includes(word);
      
      return ans;
    }
};
