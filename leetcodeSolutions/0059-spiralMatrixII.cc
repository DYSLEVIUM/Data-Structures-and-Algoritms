class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
      int top = 0, left = 0, right = n - 1, bottom = n - 1;
      vector<vector<int>> ans(n, vector<int>(n));
      
      int ptr = 1;
      while(ptr + 1 != n * n){
        for(int i = left; i <= right; ++i) ans[top][i] = ptr++;
        ++top;
        
        //  checking this condition again as only a single row matrix can exist itself
        if(top > bottom) break;
        
        for(int i = top; i <= bottom; ++i) ans[i][right] = ptr++;
        --right;
        
        //  checking this condition again as only a single column matrix can exist itself
        if(left > right) break;
        
        for(int i = right; i >= left; --i) ans[bottom][i] = ptr++;
        --bottom;
        
        for(int i = bottom; i >= top; --i) ans[i][left] = ptr++;
        ++left;
      }
      
      return ans;
    }
};
