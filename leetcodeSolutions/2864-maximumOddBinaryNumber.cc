#pragma GCC optimize("O3", "unroll-loops")

auto _ = [](){
    return cin.tie(nullptr)->sync_with_stdio(false);
}();

class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        int n = s.size();

        int cnt1 = 0;
        for(const char & ch : s) {
            cnt1 += ch == '1';
        }

        int i = 0;
        while(i < n - 1) {
            s[i++] = i < cnt1 - 1 ? '1' :'0';
        }

        s[n - 1] = '1'; // no need to check if at least one '1' exist, as it is stated in the question

        return s;
    }
};
