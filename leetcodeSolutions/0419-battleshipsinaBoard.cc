class Solution {
public:
    int countBattleships(vector<vector<char>>& board) {
        int rows = board.size(), cols = rows ? board[0].size() : 0;
        
        vector<vector<int>> vis(rows, vector<int>(cols));

        auto dfs = [&](const auto &dfs, const int &row, const int &col){
            if(row < 0 || row == rows || col < 0 || col == cols || vis[row][col] || board[row][col] == '.') {
                return ;
            }

            vis[row][col] = 1;

            dfs(dfs, row + 1, col), dfs(dfs, row, col + 1);
        };

        int cnt = 0;
        for(int row = 0; row < rows; ++row) {
            for(int col = 0; col < cols; ++col) {
                if(!vis[row][col] && board[row][col] != '.') {
                    ++cnt;
                    dfs(dfs, row, col);
                }
            }
        }

        return cnt;
    }
};
