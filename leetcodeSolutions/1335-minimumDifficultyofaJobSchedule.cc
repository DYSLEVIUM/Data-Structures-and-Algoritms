class Solution {
public:
    int minDifficulty(vector<int>& jobDifficulty, int d) {
        static constexpr int INF = 0x3f3f3f3f;
        int n = jobDifficulty.size();

        vector<vector<int>> dp(n, vector<int>(d + 1, -1));
        auto recur = [&](const auto &recur, const int &idx, const int &parti){
            if(n - idx < parti || parti < 0) {
                return INF;
            }

            if(idx == n) {
                if(parti > 0) {
                    return INF;
                }
                return 0;
            }

            if(dp[idx][parti] != -1) {
                return dp[idx][parti];
            }

            int res = INF, maxx = -INF;
            for(int i = idx; i < n; ++i) {
                maxx = max(maxx, jobDifficulty[i]);
                res = min(res, maxx + recur(recur, i + 1, parti - 1));
            }

            return dp[idx][parti] = res;
        };
        int ans = recur(recur, 0, d);

        return ans == INF ? -1 : ans;
    }
};
