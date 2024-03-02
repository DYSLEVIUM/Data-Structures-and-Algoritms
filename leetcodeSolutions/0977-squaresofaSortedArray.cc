#pragma GCC optimize("O3", "unroll-loops")

auto _ = [](){
    return cin.tie(nullptr)->sync_with_stdio(false);
}();

class Solution {
public:
    vector<int> sortedSquares(const vector<int> & nums) {
        const int n = nums.size();

        vector<int> ans(n);

        int ptr = n;
        int st = 0, ed = n - 1;
        while(ptr--) {
            if(abs(nums[st]) >= abs(nums[ed])) {
                ans[ptr] = nums[st] * nums[st++];
            } else {
                ans[ptr] = nums[ed] * nums[ed--];
            }
        }

        return ans;
    }
};
