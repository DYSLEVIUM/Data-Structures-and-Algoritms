#pragma GCC optimize("O3", "unroll-loops")

auto _ = [](){
    return cin.tie(nullptr)->sync_with_stdio(false);
}();

class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        const int n = nums.size();

        long long maxx = 0;
        for(int i = 0; i < n; ++i) {
            for(int j = i + 1; j < n; ++j) {
                for(int k = j + 1; k < n; ++k) {
                    maxx = max(maxx, 1LL * (nums[i] - nums[j]) * nums[k]);
                }
            }
        }

        return maxx;
    }
};
