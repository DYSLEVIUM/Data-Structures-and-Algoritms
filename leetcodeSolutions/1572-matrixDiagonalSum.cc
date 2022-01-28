class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
      int right_diagonal = 0, left_diagonal = 0;
      int n = mat.size();
      
      for(int row=0;row<n;++row){
        for(int col=0;col<n;++col){
          right_diagonal += row == col ? mat[row][col] : 0;
          left_diagonal += row + col == n - 1 ? mat[row][col] : 0;
        }
      }
      
      return right_diagonal + left_diagonal - (n & 1 ? mat[n/2][n/2] : 0);
    }
};
