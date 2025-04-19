#pragma GCC optimize("O3", "unroll-loops")

auto _ = [](){
    return cin.tie(nullptr)->sync_with_stdio(false);
}();

class Solution {
public:
    long long countFairPairs(vector<int> & nums, const int & lower, const int & upper) {
        const int n = nums.size();

        sort(nums.begin(), nums.end());

        long long cnt = 0;
        for(int i = 0; i < n; ++i) {
            int new_lo = lower - nums[i], new_up = upper - nums[i];

            int hi = lower_bound(nums.begin() + i + 1, nums.end(), new_up + 1) - nums.begin();
            int lo = lower_bound(nums.begin() + i + 1, nums.end(), new_lo) - nums.begin();

            cnt += 1 * (hi - lo);
        }

        return cnt;
    }
};
