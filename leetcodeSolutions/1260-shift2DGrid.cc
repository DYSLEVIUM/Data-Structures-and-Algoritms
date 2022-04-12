class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        //  we will store both the number in the same index by offsetting the bits
        
        int rows = grid.size(), cols = grid[0].size();
        int cells = rows * cols;
        k %= (cells);
        
        //  adding offset because the range is from -1000 to 1000
        for(auto &row: grid) {
            for(auto &cell: row) {
                cell += 1000;
            }
        }
        
        //  we will to imagine the array as a 1-D array
        for(int prev_idx = 0; prev_idx < cells; ++prev_idx) {
            //  getting the row major index after k offset
            int new_idx = (prev_idx + k) % cells;
            
            //  after grid[i][j] is changed to a big value, we need to restore the original value for further computation, (NOTE: x & (2^(ceil(log2(x))) - 1) = x)
            int mask = (1 << 11) - 1;
            
            //  here, if we remove the mask, we will lose the previous value that was stored in the grid
            grid[new_idx / cols][new_idx % cols] |= (grid[prev_idx / cols][prev_idx % cols] & mask) << 11;
        }
        
        //  getting back the numbers
        for(auto &row: grid) {
            for(auto &cell: row) {
                cell = (cell >> 11) - 1000;
            }
        }
        
        return grid;
    }
};
