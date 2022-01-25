class Solution {
public:
    string removeOuterParentheses(string s) {
      auto remove_outer = [](const string& str){
        int n = str.length();
        return str.substr(1,n-2);
      };
      
      int n = s.length();
      
      int open = 0;
      
      string ans ="";
      string te = "";
      for(int i=0;i<n;++i){
        te+=s[i];
        
        if(s[i]=='(') ++open;
        else --open;
        
        if(!open){
          ans+=remove_outer(te);
          te = "";
        }
      }
      
      return ans;
    }
};
