class Solution {
public:
    vector<int> executeInstructions(int n, vector<int>& startPos, string s) {
      int str_len = s.length();
      vector<int> ans(str_len);
      
      for(int start_ptr=0;start_ptr<str_len;++start_ptr){
        int row = startPos[0], col = startPos[1], cnt = 0;
        
        for(int i=start_ptr;i<str_len;++i){
          if(s[i]=='L' && col-1>=0) --col;
          else if(s[i]=='R' && col+1<n) ++col;          
          else if(s[i]=='U' && row-1>=0) --row;
          else if(s[i]=='D' && row+1<n) ++row;
          else break;
          ++cnt;
        }
        
        ans[start_ptr] = cnt;
      }
      
      return ans;
    }
};
