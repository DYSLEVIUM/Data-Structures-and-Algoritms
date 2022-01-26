class Solution {
public:
    bool isPalindrome(string s) {
      auto sanitize_string = [](const string& str){
        string new_str = "";
        
        for(auto& letter:str){
          if((letter>='A' && letter<='Z')||(letter>='a' && letter<='z')||(letter>='0' && letter<='9')){
            if(letter>='A' && letter<='Z') new_str += letter-'A'+'a';
            else new_str+=letter;
          }
        }
        
        return new_str;
      };
      
      s = sanitize_string(s);
      
      cout<<s;
      
      int n = s.size();
      for(int i=0;i<n/2;++i){
        if(s[i]!=s[n-i-1]) return false;
      }
      
      return true;
    }
};
