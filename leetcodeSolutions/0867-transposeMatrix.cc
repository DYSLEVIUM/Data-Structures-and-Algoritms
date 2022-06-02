class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& matrix) {
        int rows = matrix.size();
        if(!rows) return {};
        
        int cols = matrix[0].size();
        
        vector<vector<int>> t_matrix(cols, vector<int>(rows));
        for(int row = 0; row < rows; ++row) {
            for(int col = 0; col < cols; ++col) {
                t_matrix[col][row] = matrix[row][col];
            }
        }
        
        return t_matrix;
    }
};
