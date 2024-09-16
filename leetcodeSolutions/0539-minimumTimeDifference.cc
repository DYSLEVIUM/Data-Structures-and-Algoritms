#pragma GCC optimize("O3", "unroll-loops")

auto _ = [](){
    return cin.tie(nullptr)->sync_with_stdio(false);
}();

class Solution {
public:
    int findMinDifference(vector<string> & timePoints) {
        constinit static const int TOTAL_MINUTES = 60 * 24;

        int n = timePoints.size();

        auto normalize = [](string & time){
            return stoi(time.substr(0, 2)) * 60 + stoi(time.substr(3));
        };

        sort(timePoints.begin(), timePoints.end());

        int minn = TOTAL_MINUTES;
        for(int i = 1; i < n; ++i) {
            int prev = normalize(timePoints[i - 1]), curr = normalize(timePoints[i]);
            minn = min(minn, curr - prev);
        }

        // edge case, last with first
        minn = min(minn, TOTAL_MINUTES - (normalize(timePoints[n - 1]) - normalize(timePoints[0])));

        return minn;
    }
};
