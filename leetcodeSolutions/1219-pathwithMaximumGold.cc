class Solution {
public:
    int getMaximumGold(vector<vector<int>>& grid) {
        int rows = grid.size(), cols = rows ? grid[0].size() : 0;
        
        vector<pair<int, int>> deltas{{-1, 0}, {0, -1}, {0, 1}, {1, 0}};
        auto dfs = [&](const auto & dfs, const int & row, const int & col){
            if(row < 0 || row == rows || col < 0 || col == cols|| !grid[row][col]) return 0;

            int temp = grid[row][col];
            int res = 0;

            grid[row][col] = 0;
            for(auto &[dx, dy] : deltas) res = max(res, dfs(dfs, row + dx, col + dy));
            grid[row][col] = temp; // backtracking

            return res + temp;
        };

        int ans = 0;
        for(int row = 0; row < rows; ++row) {
            for(int col = 0; col < cols; ++col) ans = max(ans, dfs(dfs, row, col));
        }
        return ans;
    }
};
