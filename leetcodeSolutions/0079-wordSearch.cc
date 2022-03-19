class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
      int rows = board.size(), cols = board[0].size();
      vector<int> delta{-1, 1, 0, 0}; //  this was causing issue, as in every stack frame of the dfs call, we were making a vector
      auto dfs = [&](const auto& dfs, const int& row, const int& col, const int& idx = 0) -> bool {
        if(idx == word.length()) return true;
        if(row < 0 || row >= rows || col < 0 || col >= cols || word[idx] != board[row][col]) return false;

        board[row][col] = '#';
        for(int i = 0; i < 4; ++i) if(dfs(dfs, row + delta[i], col + delta[3 - i], idx + 1)) return true;
        
        board[row][col] = word[idx];  //  backtracking
        return false;
      };
      
      for(int row = 0; row < rows; ++row)
        for(int col = 0; col < cols; ++col)
          if(dfs(dfs, row, col, 0)) return true;
      
      return false;
    }
};
