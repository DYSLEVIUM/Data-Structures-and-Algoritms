class Solution {
public:
    int matrixScore(vector<vector<int>>& grid) {
        int rows = grid.size(), cols = rows ? grid[0].size() : 0;
        
        auto flip_row = [&](const int &row){
            for(int col = 0; col < cols; ++col) {
                grid[row][col] = !grid[row][col];
            }
        };
        for(int row = 0; row < rows; ++row) {
            if(!grid[row][0]) {
                flip_row(row);
            }
        }

        auto flip_col = [&](const int &col){
            for(int row = 0; row < rows; ++row) {
                grid[row][col] = !grid[row][col];
            }
        };
        for(int col = 0; col < cols; ++col) {
            int cnt_1 = 0;
            for(int row = 0; row < rows; ++row) {
                cnt_1 += grid[row][col] == 1;
            }
            
            int cnt_0 = rows - cnt_1;
            
            if(cnt_1 < cnt_0) {
                flip_col(col);
            }
        }
        
        int ans = 0;
        for(int row = 0; row < rows; ++row) {
            int curr_ans = 0;
            for(int col = cols - 1; col >= 0; --col) {
                if(grid[row][col]) {
                    curr_ans |= (1 << (cols - 1 - col));
                }
            }
            
            ans += curr_ans;
        }
        
        return ans;
    }
};
