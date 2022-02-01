class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
      int rows = matrix.size();
      int cols = matrix[0].size();
      
      //  swap rows
      for(int row=0;row<rows/2;++row) swap(matrix[row], matrix[rows-1-row]);
      
      //  swap mirror elements to diagonal
      for(int row=0;row<rows;++row){
        for(int col=0;col<row;++col){
          swap(matrix[row][col], matrix[col][row]);
        }
      }
    }
};
