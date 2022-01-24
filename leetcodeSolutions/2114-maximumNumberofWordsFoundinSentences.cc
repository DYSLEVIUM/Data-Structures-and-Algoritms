class Solution {
public:
    int mostWordsFound(vector<string>& sentences) {
      int maxi = INT_MIN;
      
      for(auto& str: sentences){
        int cnt = 0;
        for(auto& ch:str){
          cnt += ch==' ';
        }
        
        maxi = max(maxi, cnt+1);
      }
      
      return maxi;
    }
};
