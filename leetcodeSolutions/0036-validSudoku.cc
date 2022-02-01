class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
      int rows = 9, cols = 9;
      
      //  check row
      for(int row=0;row<rows;++row){
        set<int> row_nums;
        for(int col=0;col<cols;++col) {
          if(board[row][col] == '.') continue;
          if(row_nums.find(board[row][col]-'0')!=row_nums.end()) return false;
          row_nums.insert(board[row][col]-'0');
        }
      }
      
      // check column
      for(int col=0;col<cols;++col){
        set<int> col_nums;
        for(int row=0;row<rows;++row) {
          if(board[row][col] == '.') continue;
          if(col_nums.find(board[row][col]-'0')!=col_nums.end()) return false;
          col_nums.insert(board[row][col]-'0');
        }
      }
      
      //  check small box
      for(int row=0;row<rows;row+=3){
        for(int col=0;col<cols;col+=3){
          set<int> box_nums;
          for(int i=row;i<row+3;++i){
            for(int j=col;j<col+3;++j){
              if(board[i][j] == '.') continue;
              if(box_nums.find(board[i][j]-'0')!=box_nums.end()) return false;
              box_nums.insert(board[i][j]-'0');
            }
          }
        }
      }
      
      return true;
    }
};
