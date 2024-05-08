#pragma GCC optimize("O3", "unroll-loops")

auto _ = [](){
    return cin.tie(nullptr)->sync_with_stdio(false);
}();

class Solution {
public:
    vector<string> findRelativeRanks(const vector<int> & score) {
        const int n = score.size();

        vector<pair<int, int>> se(n);
        for(int i = 0; i < n; ++i) {
            se[i] = { score[i], i };
        }
        sort(se.rbegin(), se.rend());

        vector<string> ans(n);
        for(int i = 0; i < n; ++i) {
            string curr;
            if(i < 3) {
                switch(i) {
                    case 0: curr = "Gold Medal";
                            break;
                    case 1: curr = "Silver Medal";
                            break;
                    case 2: curr = "Bronze Medal";
                            break;
                }
            } else {
                curr = to_string(i + 1);
            }
            ans[se[i].second] = curr;
        }

        return ans;
    }
};
