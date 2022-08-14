class Solution {
public:
    vector<vector<int>> largestLocal(vector<vector<int>>& grid) {
      int n = grid.size();
      
      auto get_max = [&grid](const int &row, const int &col){
        int maxx = INT_MIN;
        
        for(int i = row - 1; i <= row + 1; ++i) {
          for(int j = col - 1; j <= col + 1; ++j) {
            maxx = max(maxx, grid[i][j]);
          }
        }
        
        return maxx;
      };
      
      vector<vector<int>> ans;
      for(int row = 1; row < n - 1; ++row) {
        vector<int> curr_ans;
        for(int col = 1; col < n - 1; ++col) {
          curr_ans.push_back(get_max(row, col));    
        }
        
        ans.push_back(curr_ans);
      }
      
      return ans;
    }
};
