class Solution {
public:
    int numberOfPaths(vector<vector<int>>& grid, int k) {
        constexpr int MOD = 1e9 + 7;
        static_assert(MOD == 1e9 + 7);

        int rows = grid.size(), cols = rows ? grid[0].size() : 0;

        vector<vector<vector<int>>> dp(rows, vector<vector<int>>(cols, vector<int>(k + 1, -1)));
        auto recur = [&](const auto &recur, const int &row, const int &col, const int &tot) -> int {
            if(row == rows - 1 && col == cols - 1) {
                return (tot + grid[row][col]) % k == 0;
            }

            if(row == rows || col == cols) {
                return 0;
            }

            int new_tot = tot + grid[row][col];
            new_tot %= k;

            if(dp[row][col][new_tot] != -1) {
                return dp[row][col][new_tot];
            }

            return dp[row][col][new_tot] = (recur(recur, row + 1, col, new_tot) + recur(recur, row, col + 1, new_tot)) % MOD;
        };

        return recur(recur, 0, 0, 0);
    }
};
