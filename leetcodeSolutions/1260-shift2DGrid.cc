class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        //  we will store both the number in the same index by offsetting the bits
        
        int rows = grid.size(), cols = grid[0].size();
        int cells = rows * cols;
        k %= (cells);
      
        constexpr int min_possible = -1000;
        constexpr int max_possible = 1000;

        //  adding offset because the range is from -1000 to 1000
        for(auto &row: grid) {
            for(auto &cell: row) {
                cell += abs(min_possible);
            }
        }
    
        //  range becomes 0 to max_possible + abs(min_possible)
        int maxx = ceil(log2(abs(min_possible) + max_possible));
        //  we will to imagine the array as a 1-D array
        for(int prev_idx = 0; prev_idx < cells; ++prev_idx) {
            //  getting the row major index after k offset
            int new_idx = (prev_idx + k) % cells;
            
            //  after grid[i][j] is changed to a big value, we need to restore the original value for further computation, (NOTE: x & (2^(ceil(log2(x))) - 1) = x)
            int mask = (1 << maxx) - 1;
            
            //  here, if we remove the mask, we will lose the previous value that was stored in the grid
            grid[new_idx / cols][new_idx % cols] |= (grid[prev_idx / cols][prev_idx % cols] & mask) << maxx;
        }
        
        //  getting back the numbers
        for(auto &row: grid) {
            for(auto &cell: row) {
                cell = (cell >> maxx) - abs(min_possible);
            }
        }
        
        return grid;
    }
};
