class Solution {
public:
    double knightProbability(int n, int k, int row, int column) {
        vector<pair<int, int>> deltas{{-1, -2}, {-2, -1}, {-2, 1}, {-1, 2}, {1, -2}, {2, -1}, {2, 1}, {1, 2}};

        vector<vector<double>> prev(n, vector<double>(n));
        prev[row][column] = 1;
        while(k) {
            vector<vector<double>> curr(n, vector<double>(n));
            for(int r = 0; r < n; ++r) {
                for(int c = 0; c < n; ++c) {
                    for(auto & [dr, dc] : deltas) {
                        int new_r = r + dr, new_c = c + dc;
                        if(new_r >= 0 && new_r < n && new_c >= 0 && new_c < n) curr[new_r][new_c] += prev[r][c] / 8; 
                    }
                }
            }
            --k;
            prev = curr;
        }

        double ans = 0;
        for(auto & row : prev) {
            for(auto & x : row) ans += x;
        }
        return ans;
    }
};

class Solution1 {
public:
    double knightProbability(int n, int k, int row, int column) {
        vector<pair<int, int>> deltas{{-1, -2}, {-2, -1}, {-2, 1}, {-1, 2}, {1, -2}, {2, -1}, {2, 1}, {1, 2}};
        vector<vector<vector<double>>> dp(n, vector<vector<double>>(n, vector<double>(k + 1, -1)));
        auto dfs = [&](const auto & dfs, const int & row, const int & col, const int & k_left) -> double {
            if(row < 0 || row >= n || col < 0 || col >= n) return 0;
            
            if(!k_left) return 1;

            if(dp[row][col][k_left] != -1) return dp[row][col][k_left];

            double cnt = 0;
            for(auto & [dr, dc] : deltas) cnt += dfs(dfs, row + dr, col + dc, k_left - 1);
            return dp[row][col][k_left] = cnt / 8; // probability for current state
        };
        return dfs(dfs, row, column, k);
    }
};
