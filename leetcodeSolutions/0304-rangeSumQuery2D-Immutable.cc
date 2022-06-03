class NumMatrix {
public:
    NumMatrix(vector<vector<int>>& matrix) {
        int rows = matrix.size();
        if(!rows) {
            return;
        }
        
        int cols = matrix[0].size();
        
        m_rows = rows + 1, m_cols = cols + 1;
        m_pref.resize(rows + 1, vector<int>(cols + 1));
        
        //  row prefix
        for(int row = 1; row < rows + 1; ++row) {
            for(int col = 1; col < cols + 1; ++col) {
                m_pref[row][col] = matrix[row - 1][col - 1];
                m_pref[row][col] += m_pref[row][col - 1];
            }
        }
        
        //  col prefix
        for(int col = 1; col < cols + 1; ++col) {
            for(int row = 1; row < rows + 1; ++row) {
                m_pref[row][col] += m_pref[row - 1][col];
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int total_sum = m_pref[row2 + 1][col2 + 1];
        
        int extra_top_sum = m_pref[row1][col2 + 1];
        int extra_left_sum = m_pref[row2 + 1][col1];
        
        int double_sub = m_pref[row1][col1];
        
        return total_sum - (extra_top_sum + extra_left_sum) + double_sub;
    }
    
private:
    int m_rows{0}, m_cols{0};
    vector<vector<int>> m_pref;
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */
