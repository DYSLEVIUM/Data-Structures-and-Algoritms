class Solution {
public:
    vector<int> findBall(vector<vector<int>>& grid) {
        int rows = grid.size(), cols = rows ? grid[0].size() : 0;

        vector<vector<int>> dp(rows, vector<int>(cols, -2)); // -1 represents not reachable, -2 represents not cached
        auto dfs = [&](const auto & dfs, const int & row, const int & col){
            if(row == rows) return col;

            if(dp[row][col] != -2) return dp[row][col];

            if(col + 1 < cols && grid[row][col] == 1 && grid[row][col + 1] == 1) return dp[row][col] = dfs(dfs, row + 1, col + 1);
            if(col - 1 >= 0 && grid[row][col] == -1 && grid[row][col - 1] == -1) return dp[row][col] = dfs(dfs, row + 1, col - 1);
            
            return dp[row][col] = -1;
        };

        vector<int> ans(cols);
        for(int i = 0; i < cols; ++i) ans[i] = dfs(dfs, 0, i);
        return ans;
    }
};
