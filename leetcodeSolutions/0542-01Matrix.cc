class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        static constexpr int INF = 0x3f3f3f3f;
        int rows = mat.size(), cols = rows ? mat[0].size() : 0;

        vector<vector<int>> dp(rows, vector<int>(cols, INF));
        // coming from top and bottom
        for(int row = 0; row < rows; ++row) {
            for(int col = 0; col < cols; ++col) {
                if(!mat[row][col]) dp[row][col] = 0;
                else {
                    if(row > 0) dp[row][col] = min(dp[row][col], dp[row - 1][col] + 1);
                    if(col > 0) dp[row][col] = min(dp[row][col], dp[row][col - 1] + 1);
                }
            }
        }

        // coming from top and bottom
        for(int row = rows - 1; row >= 0; --row) {
            for(int col = cols - 1; col >= 0; --col) {
                if(row < rows - 1) dp[row][col] = min(dp[row][col], dp[row + 1][col] + 1);
                if(col < cols - 1) dp[row][col] = min(dp[row][col], dp[row][col + 1] + 1);
            }
        }
        
        return dp;
    }
};
