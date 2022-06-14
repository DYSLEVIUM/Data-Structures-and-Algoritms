class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int rows = matrix.size();
        if(!rows) return 0;
        int cols = matrix[0].size();
        
        int side = 0;
        
        // vector<vector<int>> dp(rows + 1, vector<int>(cols + 1));
        // for(int row = 1; row < rows + 1; ++row) {
        //     for(int col = 1; col < cols + 1; ++col) {
        //         if(matrix[row - 1][col - 1] - '0') {
        //             dp[row][col] = 1 + min({dp[row - 1][col - 1], dp[row - 1][col], dp[row][col - 1]});
        //             side = max(side, dp[row][col]);
        //         }
        //     }
        // }
        
        vector<int> pre(cols + 1), curr(cols + 1);
        for(int row = 1; row < rows + 1; ++row) {
            for(int col = 1; col < cols + 1; ++col) {
                if(matrix[row - 1][col - 1] - '0') {
                    curr[col] = 1 + min({pre[col - 1], pre[col], curr[col - 1]});
                    side = max(side, curr[col]);
                } else {
                    //  this is necessary, as we are reusing it for next iteration and we can't leave the value as it is
                    curr[col] = 0;
                }
            }
            pre = curr;
        }     
        return side * side;
    }
};
