class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        static constexpr int N = 9;

        // check row
        for(int row = 0; row < N; ++row) {
            vector<int> vis(N + 1);
            for(int col = 0; col < N; ++col) {
                if(board[row][col] == '.') continue;
                if(vis[board[row][col] - '0']) return false;
                vis[board[row][col] - '0'] = 1;
            }
        }

        // check col
        for(int col = 0; col < N; ++col) {
            vector<int> vis(N + 1);
            for(int row = 0; row < N; ++row) {
                if(board[row][col] == '.') continue;
                if(vis[board[row][col] - '0']) return false;
                vis[board[row][col] - '0'] = 1;
            }
        }

        // check small-box
        for(int row = 0; row < N; row += 3) {
            for(int col = 0; col < N; col += 3) {
                vector<int> vis(N + 1);
                for(int irow = row; irow < row + 3; ++irow) {
                    for(int icol = col; icol < col + 3; ++icol) {
                        if(board[irow][icol] == '.') continue;
                        if(vis[board[irow][icol] - '0']) return false;
                        vis[board[irow][icol] - '0'] = 1;
                    }
                }
            }
        }

        return true;
    }
};
