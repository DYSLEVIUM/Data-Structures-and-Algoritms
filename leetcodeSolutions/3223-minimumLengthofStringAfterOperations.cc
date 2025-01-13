#pragma GCC optimize("O3", "unroll-loops")

auto _ = [](){
    return cin.tie(nullptr)->sync_with_stdio(false);
}();

class Solution {
public:
    int minimumLength(string s) {
        static constinit const int CHAR_SET = 26;

        array<int, CHAR_SET> fa{};
        for(const char & ch : s) {
            ++fa[ch - 'a'];
        }

        int ans = 0;
        for(int i = 0; i < CHAR_SET; ++i) {
            // if we have character and; if odd, remove all but one, else remove all but two
            ans += !!fa[i] * (1 + !(fa[i] & 1));
        }

        return ans;
    }
};
