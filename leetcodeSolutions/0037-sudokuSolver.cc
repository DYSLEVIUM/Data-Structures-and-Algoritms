class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        int N = 9;
        auto is_valid = [&](const int &x, const int &y, const int &val){
            int row, col;
            
            //  row
            row = x, col = 0;
            while(col < N) {
                if(board[row][col] - '0' == val) return false;
                ++col;
            }
            
            //  col
            row = 0, col = y;
            while(row < N) {
                if(board[row][col] - '0' == val) return false;
                ++row;
            }
            
            //  small cell
            row = x - (x % 3);
            col = y - (y % 3);
            
            for(int i = row; i < row + 3; ++i) {
                for(int j = col; j < col + 3; ++j) {
                    if(board[i][j] - '0' == val) {
                        return false;
                    }
                }
            }
            
            return true;
        };
        
        auto solve = [&](const auto &solve, const int &row, const int &col) -> bool {
            if(col == N) {
                return solve(solve, row + 1, 0);
            }
            
            if(row == N) {
                return true;
            }
            
            if(board[row][col] != '.') {
                return solve(solve, row, col + 1);
            }
            
            for(int i = 1; i <=9; ++i) {
                if(is_valid(row, col, i)) {
                    board[row][col] = i + '0';
                    
                    if(solve(solve, row, col + 1)) {
                        return true;
                    }
                    
                    board[row][col] = '.';
                }
            }
            
            return false;
        };
        
        solve(solve, 0, 0);
    }
};
