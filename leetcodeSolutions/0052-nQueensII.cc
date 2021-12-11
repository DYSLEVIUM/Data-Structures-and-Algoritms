class Solution {
public:
    int totalNQueens(int n) {
        int ans = 0;
        
        const auto is_valid_board = [&n](const vector<vector<bool>>& board, const int& row, const int& col){
            int temp_row, temp_col;

            temp_row = row - 1;
            temp_col = col;
            //  column up check
            while(temp_row >= 0){
                if(board[temp_row--][col] == 1) return false;
            }

            temp_row = row - 1;
            temp_col = col - 1;
            //  diagonal up-left check
            while(temp_row >= 0 && temp_col >= 0){
                if(board[temp_row--][temp_col--] == 1) return false;
            }

            temp_row = row - 1;
            temp_col = col + 1;
            //  diagonal up-right check
            while(temp_row >= 0 && temp_col<n){
                if(board[temp_row--][temp_col++] == 1) return false;
            }

            return true;
        };
        
        auto n_queens = [&n, &ans, &is_valid_board](const auto& n_queens, vector<vector<bool>>& curr_board, const int& curr_row){
            if(curr_row == n){
                ++ans;
                return;
            }
            
            for(int j = 0; j < n; ++j){
                curr_board[curr_row][j] = 1;

                if(is_valid_board(curr_board, curr_row, j)) n_queens(n_queens, curr_board, curr_row + 1);

                curr_board[curr_row][j] = 0; //  backtracking
            }
        };
        
        vector<vector<bool>> board(n, vector<bool>(n, 0));

        n_queens(n_queens, board, 0);
        
        return ans;
    }
};
