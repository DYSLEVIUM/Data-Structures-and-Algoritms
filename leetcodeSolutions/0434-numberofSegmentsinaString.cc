class Solution {
public:
    int countSegments(string s) {
      s += ' ';
      s.insert(0, " ");
      int n = s.size();
      
      int ans = 0;
      for(int i = 0; i < n; ++i){
        if(s[i] == ' ') {
          int j = i + 1;
          while(j < n && s[j] != ' '){
            ++j;
          }
          
          if(j - i != 1) ++ans; //  there is no +1 as we are taking the inclusive distance
          
          i = j - 1;
        }
      }
      
      return ans;
    }
};
