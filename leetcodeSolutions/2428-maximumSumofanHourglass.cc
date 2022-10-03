class Solution {
public:
    int maxSum(vector<vector<int>>& grid) {
        int rows = grid.size(), cols = rows ? grid[0].size() : 0;
        
        vector<pair<int, int>> deltas{{-1, -1}, {-1, 0}, {-1, 1}, {0, 0}, {1, -1}, {1, 0}, {1, 1}};
        int ans = INT_MIN;
        for(int row = 1; row < rows - 1; ++row) {
            for(int col = 1; col < cols - 1; ++col) {
                int sum = 0;
                for(auto &[dr, dc] : deltas) {
                    sum += grid[row + dr][col + dc];
                }
                ans = max(ans, sum);
            }
        }

        return ans;
    }
};

