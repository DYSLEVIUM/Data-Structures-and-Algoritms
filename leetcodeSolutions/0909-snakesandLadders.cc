class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {
      int n = board.size(), last_cell = n * n;

      unordered_map<int, int> snakes_ladders_mapper;
      bool is_left_to_right = true;
      for(int row = n - 1; row >= 0; --row) {
        for(int col = 0; col < n; ++col) {
          if(board[row][col] != -1) {
            int curr_val = (n - 1 - row) * n + (is_left_to_right ? col : n - 1 - col);
            snakes_ladders_mapper[curr_val + 1] = board[row][col];
          }
        }
        is_left_to_right = !is_left_to_right;
      }
      
      int cnt = 0;
      vector<bool> vis(last_cell + 1);
      vis[1] = true;
      
      queue<int> qu;
      qu.push(1);
      while(!qu.empty()) {
        int sz = qu.size();
        while(sz--) {
          auto fr = qu.front();
          qu.pop();
          
          if(fr == last_cell) {
            return cnt;
          }
          
          for(int i = 1; i < 7; ++i) {
            int new_cell = fr + i;
            if(snakes_ladders_mapper.count(new_cell)) {
              new_cell = snakes_ladders_mapper[new_cell];
            }
            
            if(new_cell > last_cell || vis[new_cell]) {
              continue;
            }
            vis[new_cell] = true;
            qu.push(new_cell);
          }
        }
        ++cnt;
      }
      return -1;
    }
};
