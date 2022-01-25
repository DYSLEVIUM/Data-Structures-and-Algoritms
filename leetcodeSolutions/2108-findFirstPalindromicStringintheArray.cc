class Solution {
public:
    string firstPalindrome(vector<string>& words) {
      auto checkPalindrome = [](const string& word){
        int n = word.length();
        for(int i=0;i<n/2;++i){
          if(word[i] != word[n-i-1]) return false; 
        }
        return true;
      };
      
      for(auto& word:words){
        if(checkPalindrome(word)) return word;
      }
      
      return "";
    }
};
