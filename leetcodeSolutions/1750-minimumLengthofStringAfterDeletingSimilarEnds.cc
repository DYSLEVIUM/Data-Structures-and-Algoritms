#pragma GCC optimize("O3", "unroll-loops")

auto _ = [](){
    return cin.tie(nullptr)->sync_with_stdio(false);
}();

class Solution {
public:
    int minimumLength(string s) {
        int n = s.length();

        int p1 = 0, p2 = n - 1;
        while(p1 < p2 && s[p1] == s[p2]) {
            char ref = s[p1];
            
            while(p1 <= p2 && s[p1] == ref) {
                ++p1;
            }

            while(p1 < p2 && s[p2] == ref) {
                --p2;
            }
        }

        return p2 - p1 + 1;
    }
};
