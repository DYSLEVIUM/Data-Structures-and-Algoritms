class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int rows = grid.size(), cols = rows ? grid[0].size() : 0;
        int cnt = 0;
        for(int row = 0; row < rows; ++row) {
            for(int col = 0; col < cols; ++col) {
                cnt += grid[row][col] < 0;
            }
        }
        return cnt;
    }
};
