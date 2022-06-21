class Solution {
public:
    int strStr(string haystack, string needle) {
//       if(needle.size() == 0) return 0;
      
//       if(needle.size() > haystack.size()) return -1;
      
//       if(needle.size() == haystack.size()){
//         if(needle == haystack) return 0;
//         else return -1;
//       }
      
//       for(int i = 0; i < haystack.size() - needle.size() + 1; ++i){
//         for(int j = 0; j < needle.size(); ++j){
//           if(haystack[i + j] != needle[j]) break;
//           else{
//             if(j == needle.size() - 1) return i;
//           }
//         }
//       }
      
//       return -1;
        
      auto prefix_function = [](const string &str){
        int n = str.length();
        vector<int> lps(n);
        for(int i = 1; i < n; ++i) {
          int j = lps[i - 1];
          while(j > 0 && str[i] != str[j]) {
            j = lps[j - 1];
          }
          if(str[i] == str[j]) {
            ++j;
          }
          
          lps[i] = j;
        }
        return lps;
      };
      
      vector<int> lps = prefix_function(needle);
      
      int j = 0;
      for(int i = 0; i < haystack.size(); ++i) {
        if(haystack[i] == needle[j]) {
          ++j;
        } else {
          if(j) {
            j = lps[j - 1];
            --i;  //  while we don't get a match
          }
        }
        
        if(j == needle.size()) {
          return i - needle.size() + 1;
        }
      }
      
      return -1;
    }
};
