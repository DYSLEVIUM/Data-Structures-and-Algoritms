#pragma GCC optimize("O3", "unroll-loops")

auto _ = [](){
    return cin.tie(nullptr)->sync_with_stdio(false);
}();

class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        const int n = nums.size();
        const long total = accumulate(nums.begin(), nums.end(), 0LL);
        
        long sum = 0;
        int ways = 0;
        for(int i = 0; i < n - 1; ++i) {
            sum += nums[i];
            ways += (sum << 1) >= total;
        }

        return ways;
    }
};
