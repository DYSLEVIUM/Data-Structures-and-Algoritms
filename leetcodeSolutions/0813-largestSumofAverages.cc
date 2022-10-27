class Solution {
public:
    double largestSumOfAverages(vector<int>& nums, int k) {
        static constexpr int INF = 0x3f3f3f3f;
        int n = nums.size();

        vector<vector<double>> dp(n + 1, vector<double>(k + 1, -1));
        auto dfs = [&](const auto & dfs, const int & idx, const int & k_left) -> double {
            if(idx == n) return 0;
            if(!k_left) return -INF;

            if(dp[idx][k_left] != -1) return dp[idx][k_left];

            double maxx = -INF, sum = 0;
            for(int i = idx; i < n; ++i) {
                sum += nums[i];
                double avg = sum / (i - idx + 1);
                maxx = max(maxx, avg + dfs(dfs, i + 1, k_left - 1));
            }
            return dp[idx][k_left] = maxx;
        };

        return dfs(dfs, 0, k);
    }
};
