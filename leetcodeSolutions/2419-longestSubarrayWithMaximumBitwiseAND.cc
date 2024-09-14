#pragma GCC optimize("O3", "unroll-loops")

auto _ = [](){
    return cin.tie(nullptr)->sync_with_stdio(false);
}();

class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n = nums.size();

        int maxx = *max_element(nums.begin(), nums.end());

        int ans = -0x3f3f3f3f;
        for(int le = 0; le < n; ++le) {
            if(nums[le] != maxx) {
                continue;
            }

            int ri = le;
            while(ri < n && nums[ri] == maxx) {
                ++ri;
            }

            ans = max(ans, ri - le);
            le = ri;
        }

        return ans;
    }
};
