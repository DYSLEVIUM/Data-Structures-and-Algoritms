class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        cin.tie(nullptr)->sync_with_stdio(false);

        int rows = mat.size(), cols = mat[0].size();

        vector<int> row_cache(rows, 0), col_cache(cols, 0);
        for(int i = 0; i < rows; ++i) {
            for(int j = 0; j < cols; ++j) {
                if(mat[i][j]) {
                    ++row_cache[i], ++col_cache[j];
                }
            }
        }

        int ans = 0;
        for(int i = 0; i < rows; ++i) {
            for(int j = 0; j < cols; ++j) {
                ans += mat[i][j] && row_cache[i] == 1 && col_cache[j] == 1;
            }
        }

        return ans;
    }
};
