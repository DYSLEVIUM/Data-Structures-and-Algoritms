#pragma GCC optimize("O3", "unroll-loops")

auto _ = [](){
    return cin.tie(nullptr)->sync_with_stdio(false);
}();

class Solution {
public:
    int maxUniqueSplit(string & s) {
        static const int INF = 0x3f3f3f3f;

        const int n = s.size();

        unordered_set<string> se;
        auto recur = [&](const auto & recur, const int & start){
            if(start == n) {
                return 0;
            }

            int maxx = -INF;
            for(int end = start + 1; end <= n; ++end) {
                string substr = s.substr(start, end - start);
                if(se.count(substr)) {
                    continue;
                }

                se.insert(substr);
                maxx = max(maxx, 1 + recur(recur, end));
                se.erase(substr);
            }

            return maxx;
        };

        return recur(recur, 0);
    }
};
