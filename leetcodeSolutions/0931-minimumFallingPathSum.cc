class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
      constexpr int INF = 0x3f3f3f;
      int rows = matrix.size(), cols = rows ? matrix[0].size() : 0;
      
      vector<int> prev(cols + 2);
      for(int row = 0; row < rows; ++row) {
        vector<int> curr(cols + 2, INF);
        for(int col = 1; col < cols + 1; ++col) {
          curr[col] = matrix[row][col - 1] + min({prev[col - 1], prev[col], prev[col + 1]});
        }
        prev = curr;
      }
      
      return *min_element(prev.begin(), prev.end());
    }
};
