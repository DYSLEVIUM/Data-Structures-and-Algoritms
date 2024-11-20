#pragma GCC optimize("O3", "unroll-loops")

auto _ = [](){
    return cin.tie(nullptr)->sync_with_stdio(false);
}();

class Solution {
public:
    int takeCharacters(string s, int k) {
        static constinit const int CHAR_SET = 3;
        static constinit const int INF = 0x3f3f3f3f;

        const int n = s.size();

        array<int, CHAR_SET> fa;
        for(int i = 0; i < n; ++i) {
            ++fa[s[i] - 'a'];
        }

        for(int i = 0; i < CHAR_SET; ++i) {
            if(fa[i] < k) {
                return -1;
            }
        }

        array<int, CHAR_SET> window;
        auto is_invalid_window = [&](){
            for(int i = 0; i < CHAR_SET; ++i) {
                if(fa[i] - window[i] < k) { // outside has less elements
                    return true;
                }
            }
            return false;
        };

        int maxx = -INF;
        for(int le = 0, ri = 0; ri < n; ++ri) {
            ++window[s[ri] - 'a'];
            while(le <= ri && is_invalid_window()) {
                --window[s[le++] - 'a'];
            }

            maxx = max(maxx, ri - le + 1);
        }

        return n - maxx;
    }
};
