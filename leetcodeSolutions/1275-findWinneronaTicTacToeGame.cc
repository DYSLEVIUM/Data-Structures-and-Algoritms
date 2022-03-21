class Solution {
public:
    string tictactoe(vector<vector<int>>& moves) {
      vector<vector<char>> grid(3, vector<char>(3, ' '));
      auto check = [&grid](const char& player){
        //  check rows
        for(int row = 0; row < 3; ++row) {
          int cnt = 0;
          for(int col = 0; col < 3; ++col) {
            cnt += grid[row][col] == player;
          }
          
          if(cnt == 3) return true;
        }
        
        //  check columns
        for(int col = 0; col < 3; ++col) {
          int cnt = 0;
          for(int row = 0; row < 3; ++row) {
            cnt += grid[row][col] == player;
          }
          
          if(cnt == 3) return true;
        } 
        
        //  check principle diagonal
        int cnt = 0;
        for(int i = 0; i < 3; ++i) cnt += grid[i][i] == player;
        if(cnt == 3) return true;
        
        //  check non-principle diagonal
        cnt = 0;
        int j = 2;
        for(int i = 0; i < 3; ++i) cnt += grid[i][j--] == player;
        if(cnt == 3) return true;

        return false;
      };
      
      auto change_turn = [](const char& curr_player){ return 'A' ^ 'B' ^ curr_player; };

      char curr_player = 'A';
      for(auto& move: moves) {
        grid[move[0]][move[1]] = curr_player;
        if(check(curr_player)) return (string("") + curr_player) ;
        curr_player = change_turn(curr_player);
      }

      for(int row = 0; row < 3; ++row) {
        for(int col = 0; col < 3; ++col) {
          if(grid[row][col] == ' ') return "Pending";
        }
      }
      
      return "Draw";
    }
};
