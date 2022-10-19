class Solution {
public:
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int k) {
        int rows = mat.size(), cols = rows ? mat[0].size() : 0;

        vector<vector<int>> pref(rows + k, vector<int>(cols + k));
        for(int row = 0; row < rows; ++row) {
            for(int col = 0; col < cols; ++col) pref[row][col] = mat[row][col];
        }

        // row prefix
        for(int row = 0; row < rows + k; ++row) {
            for(int col = 1; col < cols + k; ++col) pref[row][col] += pref[row][col - 1];
        }

        // col prefix
        for(int col = 0; col < cols + k; ++col) {
            for(int row = 1; row < rows + k; ++row) pref[row][col] += pref[row - 1][col];
        }

        auto get_sum = [&](const int &row, const int &col) {
            if(row < 0 || row >= rows + k || col < 0 || col >= cols + k) return 0;
            return pref[row][col];
        };
        
        vector<vector<int>> ans(rows, vector<int>(cols));
        for(int row = 0; row < rows; ++row) {
            for(int col = 0; col < cols; ++col) {
                // using inclusion-exclusion principle
                ans[row][col] = get_sum(row + k , col + k) - get_sum(row + k, col - k - 1) - get_sum(row - k - 1, col + k) + get_sum(row - k - 1, col - k - 1);
            }
        }
        return ans;
    }
};
