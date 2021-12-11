class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        
        const auto is_valid_board = [&n](const vector<string>& board, const int& row, const int& col){
            int temp_row, temp_col;

            temp_row = row - 1;
            temp_col = col;
            //  column up check
            while(temp_row >= 0){
                if(board[temp_row--][col] == 'Q') return false;
            }

            temp_row = row - 1;
            temp_col = col - 1;
            //  diagonal up-left check
            while(temp_row >= 0 && temp_col >= 0){
                if(board[temp_row--][temp_col--] == 'Q') return false;
            }

            temp_row = row - 1;
            temp_col = col + 1;
            //  diagonal up-right check
            while(temp_row >= 0 && temp_col<n){
                if(board[temp_row--][temp_col++] == 'Q') return false;
            }

            return true;
        };
        
        auto n_queens = [&n, &ans, &is_valid_board](const auto& n_queens, vector<string>& curr_board, const int& curr_row){
            if(curr_row == n){
                ans.push_back(curr_board);
                return;
            }
            
            for(int j = 0; j < n; ++j){
                curr_board[curr_row][j] = 'Q';

                if(is_valid_board(curr_board, curr_row, j)) n_queens(n_queens, curr_board, curr_row + 1);

                curr_board[curr_row][j] = '.'; //  backtracking
            }
        };
        
        vector<string> board(n, string(n, '.'));

        n_queens(n_queens, board, 0);
        
        return ans;
    }
};
