class Solution {
public:
    void solve(vector<vector<char>>& board) {
      int rows = board.size(), cols = rows ? board[0].size() : 0;
      
      vector<vector<bool>> vis(rows, vector<bool>(cols));
      queue<pair<int, int>> qu;
      for(int row = 0; row < rows; ++row) {
        for(int col = 0; col < cols; ++col) {
          if(board[row][col] == 'O') {
            if(row == 0 || row == rows - 1 || col == 0 || col == cols - 1) {
              qu.push({row, col});
              vis[row][col] = 1;
            }
          } else {
            vis[row][col] = 1;
          }
        }
      }
      
      vector<pair<int, int>> deltas{{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
      while(!qu.empty()) {
        auto [row, col] = qu.front();
        qu.pop();
        
        for(auto &[dx, dy] : deltas) {
          int new_row = row + dx, new_col = col + dy;
          
          if(new_row < 0 || new_row >= rows || new_col < 0 || new_col >= cols || vis[new_row][new_col]) {
            continue;           
          }
          
          qu.push({new_row, new_col});
          vis[new_row][new_col] = 1;
        }
      }
      
      for(int row = 0; row < rows; ++row) {
        for(int col = 0; col < cols; ++col) {
          
          if(!vis[row][col] && board[row][col] == 'O') {
            board[row][col] = 'X';
          }
        }
      }
    }
};
