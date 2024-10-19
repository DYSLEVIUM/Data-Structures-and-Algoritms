#pragma GCC optimize("O3", "unroll-loops")

auto _ = [](){
    return cin.tie(nullptr)->sync_with_stdio(false);
}();

class Solution {
public:
    int maxVowels(string & s, const int & k) {
        static const unordered_set<char> VOWELS{'a', 'e', 'i', 'o', 'u'};

        const int n = s.size();

        int cnt = 0;
        for(int i = 0; i < k; ++i) {
            cnt += VOWELS.count(s[i]);
        }

        int maxx = cnt;
        for(int i = k; i < n; ++i) {
            cnt += VOWELS.count(s[i]) - VOWELS.count(s[i - k]);
            maxx = max(maxx, cnt);
        }

        return maxx;
    }
};
