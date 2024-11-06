#pragma GCC optimize("O3", "unroll-loops")

auto _ = [](){
    return cin.tie(nullptr)->sync_with_stdio(false);
}();

class Solution {
public:
    bool canSortArray(vector<int>& nums) {
        static constinit const int INF = 0x3f3f3f3f;

        const int n = nums.size();

        auto get_bits = [](const int & num){
            return __builtin_popcount(num);
        };

        int prev = -INF;
        for(int i = 0; i < n; ++i) {
            int maxx = nums[i], minn = nums[i];
            int seg_bits = get_bits(nums[i]);

            int j = i + 1;
            while(j < n && seg_bits == get_bits(nums[j])) {
                minn = min(minn, nums[j]);
                maxx = max(maxx, nums[j]);

                ++j;
            }

            if(prev > minn) {
                return false;
            }
            prev = maxx;
            
            i = j - 1;
        }

        return true;
    }
};
