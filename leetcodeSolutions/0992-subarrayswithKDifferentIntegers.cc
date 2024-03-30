#pragma GCC optimize("O3", "unroll-loops")

auto _ = [](){
    return cin.tie(nullptr)->sync_with_stdio(false);
}();

class Solution {
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        int n = nums.size();

        auto slidingWindowAtMost = [&nums, &n](const int & k){
            unordered_map<int, int> mp;

            int ans = 0;
            for(int le = 0, ri = 0; ri < n; ++ri) {
                ++mp[nums[ri]];

                while(le < n && mp.size() > k) {
                    --mp[nums[le]];

                    if(mp[nums[le]] == 0) {
                        mp.erase(nums[le]);
                    }

                    ++le;
                }
                
                ans += ri - le + 1;
            }

            return ans;
        };

        return slidingWindowAtMost(k) - slidingWindowAtMost(k - 1);
    }
};
