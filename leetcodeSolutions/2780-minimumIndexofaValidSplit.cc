#pragma GCC optimize("O3", "unroll-loops")

auto _ = [](){
    return cin.tie(nullptr)->sync_with_stdio(false);
}();

class Solution {
public:
    int minimumIndex(const vector<int> & nums) {
        int n = nums.size();

        auto moore = [&](){
            int dom = nums[0], cnt = 0;
            for(int i = 0; i < n; ++i) {
                cnt += 2 * (nums[i] == dom) - 1; // scaling from [0, 1] to [-1, 1]
                if(cnt) {
                    continue;    
                }

                dom = nums[i], cnt = 1;
            }

            // no need to check if it is valid, as it is given in the problem
            return dom;
        };

        int dom = moore(), tot = 0;
        for(int i = 0; i < n; ++i) {
            tot += nums[i] == dom;
        }

        int cnt = 0;
        for(int i = 1; i < n + 1; ++i) {
            cnt += nums[i - 1] == dom;

            bool le = cnt > i / 2;
            bool ri = tot - cnt > (n - i) / 2;
            if(le && ri) {
                return i - 1;
            }
        }

        return -1;
    }
};
