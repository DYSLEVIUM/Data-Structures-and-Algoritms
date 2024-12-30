#pragma GCC optimize("O3", "unroll-loops")

auto _ = [](){
    return cin.tie(nullptr)->sync_with_stdio(false);
}();

class Solution {
public:
    int countGoodStrings(const int & low, const int & high, const int & zero, const int & one) {
        constinit static const int MOD = 1e9 + 7;

        const int zero_str = string(zero, '0').size(), one_str = string(one, '1').size();
        auto countGoodStrings = [&](const int & end){
            vector<int> dp(end + 1);
            for(int i = 1; i < end + 1; ++i) {
                dp[i] += i - zero_str < 0 ? 0 : (1 + dp[i - zero_str]) % MOD;
                dp[i] += i - one_str < 0 ? 0 : (1 + dp[i - one_str]) % MOD;
                dp[i] %= MOD;
            }
            
            return dp[end];
        };

        return (MOD + (countGoodStrings(high) % MOD) - (countGoodStrings(low - 1) % MOD)) % MOD;
    }
};
