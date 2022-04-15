class Solution {
public:
    bool detectCapitalUse(string word) {
      int n = word.length();
      int cnt = 0;
      for(int i = 1; i < n; ++i) {
        cnt += (word[i] >= 'a' && word[i] <= 'z'); 
      }
      
      if(word[0] >= 'A' && word[0] <= 'Z') {
        if(cnt == n - 1 || cnt == 0) return true;
      } else {
        if(cnt == n - 1) return true;
      }
      
      return false;
    }
};
