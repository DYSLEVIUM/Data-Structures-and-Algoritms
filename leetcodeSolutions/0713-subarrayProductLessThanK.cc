#pragma GCC optimize("O3", "unroll-loops")

auto _ = [](){
    return cin.tie(nullptr)->sync_with_stdio(false);
}();

class Solution {
public:
    int numSubarrayProductLessThanK(const vector<int> & nums, const int & k) {
        int n = nums.size();

        if(k <= 1) {
            return 0;
        }

        int ans = 0, product = 1;
        for(int le = 0, ri = 0; ri < n; ++ri) {
            product *= nums[ri];
            while(product >= k) {
                product /= nums[le++];
            }
            ans += ri - le + 1;
        }

        return ans;
    }
};
