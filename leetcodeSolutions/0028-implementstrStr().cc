class Solution {
public:
    int strStr(string haystack, string needle) {
      //  BETTER USE KMP
      if(needle.size()==0) return 0;
      
      if(needle.size()>haystack.size()) return -1;
      
      if(needle.size()==haystack.size()){
        if(needle==haystack) return 0;
        else return -1;
      }
      
      for(int i=0;i<haystack.size()-needle.size()+1;++i){
        for(int j=0;j<needle.size();++j){
          if(haystack[i+j]!=needle[j]) break;
          else{
            if(j==needle.size()-1) return i;
          }
        }
      }
      
      return -1;
    }
};
