class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
      int pref_len = pref.length();
      int cnt = 0;
      for(auto& word: words){
        int word_len = word.length();
        if(pref_len > word_len) continue;
        
        int same_char = 0;
        for(int i = 0; i < pref_len; ++i) same_char += pref[i] == word[i];
        
        cnt += same_char == pref_len;
      }
      
      return cnt;
    }
};
