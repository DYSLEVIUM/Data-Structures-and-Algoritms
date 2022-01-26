class Solution {
public:
    int titleToNumber(string columnTitle) {
      //  this can be thought of as 26 base numbers, where the numbers are A, B, ..., Z
      int n = columnTitle.length();
      
      int ans = 0;
      
      for(int i=0;i<n;++i){
        ans+=(pow(26,n-i-1)*(columnTitle[i]-'A'+1));
      }
      
      return ans;
    }
};
