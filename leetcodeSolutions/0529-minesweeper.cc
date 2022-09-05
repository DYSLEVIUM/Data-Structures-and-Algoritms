class Solution {
public:
    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
      int rows = board.size(), cols = rows ? board[0].size() : 0;
      
      vector<vector<int>> vis(rows, vector<int>(cols));
      auto check = [&](const int &row, const int &col){
        return row >= 0 && row < rows && col >= 0 && col < cols && !vis[row][col];
      };
      
      vector<pair<int, int>> deltas{{-1, -1}, {0, -1}, {1, -1},
                                    {-1, 0}, {1, 0},
                                    {-1, 1}, {0, 1}, {1, 1}};
      
      auto dfs = [&](const auto &dfs, const int &row, const int &col){
        if(!check(row, col)) {
          return ;
        }
        
        vis[row][col] = 1;
        
        int cnt = 0;      
        for(auto &[dx, dy] : deltas) {
          int new_row = row + dx, new_col = col + dy;
          cnt += check(new_row, new_col) && board[new_row][new_col] == 'M';
        } 

        if(cnt) {
          board[row][col] = cnt + '0';
        } else {
          for(auto &[dx, dy] : deltas) {
            dfs(dfs, row + dx, col + dy);
          }
          board[row][col] = 'B';
        }
      };
      
      int row = click[0], col = click[1];
      if(board[row][col] == 'M') {
        board[row][col] = 'X';
      } else {
        dfs(dfs, row, col);
      }
      
      return board;
    }
};
