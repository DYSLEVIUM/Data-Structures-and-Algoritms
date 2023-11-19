class Solution {
public:
    vector<vector<int>> onesMinusZeros(vector<vector<int>>& grid) {
        cin.tie(nullptr)->sync_with_stdio(false);
        
        int m = grid.size(), n = grid[0].size();

        vector<vector<int>> ans(m, vector<int>(n));

        for(int i = 0; i < m; ++i) {
            int cnt = 0;
            for(int j = 0; j < n; ++j) {
                cnt += grid[i][j] ? 1 : -1;
            }

            for(int j = 0; j < n; ++j) {
                ans[i][j] = cnt;
            }
        }

        for(int i = 0; i < n; ++i) {
            int cnt = 0;
            for(int j = 0; j < m; ++j) {
                cnt += grid[j][i] ? 1 : -1;
            }

            for(int j = 0; j < m; ++j) {
                ans[j][i] += cnt;
            }
        }

        return ans;
    }
};
