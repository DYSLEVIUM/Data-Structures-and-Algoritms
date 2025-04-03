#pragma GCC optimize("O3", "unroll-loops")

auto _ = [](){
    return cin.tie(nullptr)->sync_with_stdio(false);
}();

class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        static constinit const int INF = 0x3f3f3f3f;

        const int n = nums.size();

        vector<int> prefix_max(n + 1), suffix_max(n + 1);
        prefix_max[0] = suffix_max[n] = -INF;
        for(int i = 0; i < n; ++i) {
            prefix_max[i + 1] = max(prefix_max[i], nums[i]);

            int inv = n - 1 - i;
            suffix_max[inv] = max(suffix_max[inv + 1], nums[inv]);
        }

        long long maxx = 0;
        for(int j = 1; j < n - 1; ++j) {
            long long curr = 1LL * (prefix_max[j] - nums[j]) * suffix_max[j + 1];
            maxx = max(maxx, curr);
        }

        return maxx;
    }
};
