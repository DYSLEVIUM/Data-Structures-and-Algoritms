class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int rows = grid.size(), cols = rows ? grid[0].size() : 0;
        
        int total = 0;
        for(auto & row : grid) {
            for(auto & cell : row) {
                total += cell;
            }
        }

        vector<pair<int, int>> deltas{{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
        auto dfs = [&](const auto & dfs, const int & row, const int & col){
            if(row < 0 || col < 0 || row >= rows || col >= cols || !grid[row][col]) {
                return 0;
            }
            grid[row][col] = 0;

            int cnt = 1; // 1 for current
            for(auto & [dx, dy] : deltas) {
                cnt += dfs(dfs, row + dx, col + dy);
            }

            return cnt;
        };

        int ans = 0;
        for(int col = 0; col < cols; ++col) {
            ans += dfs(dfs, 0, col) + dfs(dfs, rows - 1, col);
        }

        for(int row = 0; row < rows; ++row) {
            ans += dfs(dfs, row, 0) + dfs(dfs, row, cols - 1);
        }

        return total - ans;
    }
};
