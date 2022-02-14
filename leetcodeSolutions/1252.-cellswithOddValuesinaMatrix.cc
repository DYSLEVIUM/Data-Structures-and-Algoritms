class Solution {
public:
    int oddCells(int m, int n, vector<vector<int>>& indices) {
      vector<vector<int>> mat(m, vector<int>(n, 0));
      
      for(vector<int>& index: indices){
        for(int col = 0; col < n; ++col)++mat[index[0]][col];
        for(int row = 0; row < m; ++row)++mat[row][index[1]];
      }
      
      int ans = 0;
      
      for(int row = 0; row < m; ++row)
        for(int col = 0; col < n; ++col) ans += mat[row][col]&1; 
      
      return ans;
    }
};
