class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int rows = dungeon.size(), cols = rows ? dungeon[0].size() : 0;
        
        vector<vector<int>> dp(rows + 1, vector<int>(cols + 1, INT_MAX));
        
        // these cells are out of bounds, and we need optimally 1 at this position
        dp[rows- 1][cols] = dp[rows][cols - 1] = 1;
        
        for(int row = rows - 1; row >= 0; --row) {
            for(int col = cols - 1; col >= 0; --col) {
                int need = min(dp[row + 1][col], dp[row][col + 1]) - dungeon[row][col];
                // here we are calculating need, istead of health
                dp[row][col] = need <= 0 ? 1 : need;
            }
        }
        
        return dp[0][0];
    }
};
