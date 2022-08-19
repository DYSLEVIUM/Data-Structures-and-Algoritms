class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
      int o_r = mat.size(), o_c = o_r ? mat[0].size() : 0;
      if(o_r * o_c != r * c) {
        return mat;
      }
      
      int iter = 0;
      vector<vector<int>> out(r, vector<int>(c));
      for(int i = 0; i < r; ++i) {
        for(int j = 0; j < c; ++j) {
          int c_r = iter / o_c, c_c = iter % o_c;
          
          out[i][j] = mat[c_r][c_c];
          
          ++iter;
        }
      }
      
      return out;
    }
};
