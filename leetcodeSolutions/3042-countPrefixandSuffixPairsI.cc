#pragma GCC optimize("O3", "unroll-loops")

auto _ = [](){
    return cin.tie(nullptr)->sync_with_stdio(false);
}();

class Solution {
public:
    int countPrefixSuffixPairs(const vector<string> & words) {
        auto isPrefixAndSuffix = [](const string & s1, const string & s2){
            const int n1 = s1.size(), n2 = s2.size();
            if(n1 > n2) {
                return false;
            }

            for(int le = 0, ri = n2 - n1; le < n1; ++le, ++ri) {
                if(s1[le] != s2[le] || s1[le] != s2[ri]) {
                    return false;
                }
            }
            return true;
        };

        const int n = words.size();

        int ans = 0;
        for(int i = 0; i < n; ++i) {
            for(int j = i + 1; j < n; ++j) {
                ans += isPrefixAndSuffix(words[i], words[j]);
            }
        }

        return ans;
    }
};
