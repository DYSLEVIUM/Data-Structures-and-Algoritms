#pragma GCC optimize("O3", "unroll-loops")

class Solution {
public:
    int findJudge(const int & n, const vector<vector<int>> & trust) {
        cin.tie(nullptr)->sync_with_stdio(false);

        pair<int, int> edge[n + 1]; // in-edge, out-edge
        for(const auto & tru: trust) {
            const int a = tru[0], b = tru[1];
            ++edge[a].second, ++edge[b].first;
        }

        for(int i = 1; i <= n; ++i) {
            if(edge[i].first == n - 1 && edge[i].second == 0) {
                return i;
            }
        }

        return -1;
    }
};
