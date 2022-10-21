class Solution {
public:
    int closedIsland(vector<vector<int>>& grid) {
        int rows = grid.size(), cols = rows ? grid[0].size() : 0;

        vector<pair<int, int>> deltas{{-1, 0}, {0, -1}, {0, 1}, {1, 0}};
        auto dfs = [&](const auto & dfs, const int & row, const int & col) {
            if(row < 0 || row == rows || col < 0 || col == cols || grid[row][col]) return ;

            grid[row][col] = 1;

            for(auto & [dx, dy] : deltas) dfs(dfs, row + dx, col + dy);
        };
        
        // first col
        for(int row = 0; row < rows; ++row) {
            if(!grid[row][0]) dfs(dfs, row, 0);
        }

        // last col
        for(int row = 0; row < rows; ++row) {
            if(!grid[row][cols - 1]) dfs(dfs, row, cols - 1);
        }
        
        // first row
        for(int col = 0; col < cols; ++col) {
            if(!grid[0][col]) dfs(dfs, 0, col);
        }
        
        // last col
        for(int col = 0; col < cols; ++col) {
            if(!grid[rows - 1][col]) dfs(dfs, rows - 1, col);
        }

        int cnt = 0;
        for(int row = 0; row < rows; ++row) {
            for(int col = 0; col < cols; ++col) {
                if(!grid[row][col]) dfs(dfs, row, col), ++cnt;
            }
        }
        return cnt;
    }
};
