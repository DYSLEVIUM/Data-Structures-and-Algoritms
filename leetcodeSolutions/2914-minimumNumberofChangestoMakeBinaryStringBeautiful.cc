#pragma GCC optimize("O3", "unroll-loops")

auto _ = [](){
    return cin.tie(nullptr)->sync_with_stdio(false);
}();

class Solution {
public:
    int minChanges(string & s) {
        const int n = s.size();

        int cnt = 0;
        for(int i = 0; i < n; ++i) {
            cnt += s[i] != s[++i];
        }

        return cnt;
    }
};
