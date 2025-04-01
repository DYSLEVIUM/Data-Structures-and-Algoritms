#pragma GCC optimize("O3", "unroll-loops")

auto _ = [](){
    return cin.tie(nullptr)->sync_with_stdio(false);
}();

class Solution {
public:
    long long mostPoints(vector<vector<int>>& questions) {
        const int n = questions.size();

        vector<long long> dp(n + 1);
        for(int i = n - 1; i >= 0; --i) {
            long long not_take = dp[i + 1]; // not take

            long long take = questions[i][0];
            int next = i + questions[i][1] + 1;
            if(next < n) {
                take += dp[next];
            }

            dp[i] = max(not_take, take);
        }

        return dp[0];
    }
};
