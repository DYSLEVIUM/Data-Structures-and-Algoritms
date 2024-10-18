#pragma GCC optimize("O3", "unroll-loops")

auto _ = [](){
    return cin.tie(nullptr)->sync_with_stdio(false);
}();

class Solution {
public:
    int countMaxOrSubsets(vector<int>& nums) {
        static const int INF = 0x3f3f3f3f;

        const int n = nums.size(), maxx = accumulate(nums.begin(), nums.end(), 0, bit_or());

        vector<unordered_map<int, int>> dp(n);
        auto recur = [&](const auto & recur, const int & idx, const int & mask, const int & orr) -> int {
            if(idx == n) {
                return maxx == orr;
            }

            if(dp[idx].count(mask)) {
                return dp[idx][mask];
            }

            int take = recur(recur, idx + 1, mask | (1 << idx), orr | nums[idx]);
            int not_take = recur(recur, idx + 1, mask, orr);

            return dp[idx][mask] = take + not_take;
        };

        return recur(recur, 0, 0, 0);
    }
};
