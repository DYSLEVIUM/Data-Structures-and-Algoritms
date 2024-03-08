#pragma GCC optimize("O3", "unroll-loops")

auto _ = [](){
    return cin.tie(nullptr)->sync_with_stdio(false);
}();

class Solution {
public:
    int maxFrequencyElements(const vector<int> & nums) {
        constinit static const int MAXN = 100;

        array<int, MAXN + 1> fa;

        int cnt = 0, maxx = 0;
        for(const int & num : nums) {
            ++fa[num];
            if(maxx < fa[num]) {
                cnt = 0;
                maxx = fa[num];
            }

            cnt += maxx == fa[num];
        }

        return maxx * cnt;
    }
};
