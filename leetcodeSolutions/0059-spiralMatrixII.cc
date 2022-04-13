class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
      //  similar as 0054-spiralMatrix.cc but here we can skip the bound check as we know that it will always be regular after every layer
      vector<vector<int>> matrix(n, vector<int>(n));
      
      int top = 0, right = n - 1, bottom = n - 1, left = 0;
      int cnt = 1;
      while(cnt <= n * n) {
        //  print the top row
        for(int col = left; col <= right; ++col) {
          matrix[top][col] = cnt++;
        }
        ++top;
        
        //  print the right col
        for(int row = top; row <= bottom; ++row) {
          matrix[row][right] = cnt++;
        }
        --right;
        
        //  print the bottom row
        for(int col = right; col >= left; --col) {
          matrix[bottom][col] = cnt++;
        }
        --bottom;
        
        //  print the left col
        for(int row = bottom; row >= top; --row){
          matrix[row][left] = cnt++;
        }
        ++left;
      }
      
      return matrix;
    }
};
