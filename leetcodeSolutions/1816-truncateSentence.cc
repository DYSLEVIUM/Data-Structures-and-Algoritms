class Solution {
public:
    string truncateSentence(string s, int k) {
      string ans = "";
      
      int n = s.length();
      for(int i=0;i<n;++i){
        if(s[i]==' ') --k;
        if(k==0) break;
        ans+=s[i];
      }
      
      return ans;
    }
};
