#pragma GCC optimize("O3", "unroll-loops")

auto _ = [](){
    return cin.tie(nullptr)->sync_with_stdio(false);
}();

class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        const int n = nums.size();

        unordered_map<int, int> mp;

        int ans = 0;
        for(int le = 0, ri = 0; ri < n; ++ri) {
            ++mp[nums[ri]];

            while(mp[nums[ri]] > k) {
                --mp[nums[le++]];
            }

            ans = max(ans, ri - le + 1);
        }

        return ans;
    }
};
