class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        int rows = matrix.size(), cols = rows ? matrix[0].size() : 0;

        vector<int> minn(rows, INT_MAX);
        for(int row = 0; row < rows; ++row) {
            for(int col = 0; col < cols; ++col) {
                minn[row] = min(minn[row], matrix[row][col]);
            }
            cout << minn[row] << '\n';
        }

        vector<int> maxx(cols, INT_MIN);
        for(int col = 0; col < cols; ++col) {
            for(int row = 0; row < rows; ++row) {
                maxx[col] = max(maxx[col], matrix[row][col]);
            }
            cout << maxx[col] << '\n';
        }

        vector<int> ans;
        for(int row = 0; row < rows; ++row) {
            for(int col = 0; col < cols; ++col) {
                if(matrix[row][col] == minn[row] && matrix[row][col] == maxx[col]) {
                    ans.push_back(matrix[row][col]);
                }
            }
        }
  
        return ans; 
    }
};
