#pragma GCC optimize("O3", "unroll-loops")

auto _ = [](){
    return cin.tie(nullptr)->sync_with_stdio(false);
}();

class Solution {
public:
    vector<int> resultsArray(const vector<vector<int>> & queries, const int & k) {
        const int n = queries.size();

        vector<int> results(n, -1);

        using PII = pair<int, int>;

        const auto distance = [](const PII & coord){
            return abs(coord.first) + abs(coord.second);
        };

        const auto cmp = [&distance](const PII & lhs, const PII & rhs){
            return distance(lhs) < distance(rhs);
        };

        priority_queue<PII, vector<PII>, decltype(cmp)> min_heap(cmp);

        for(size_t i = 0; const auto & query: queries) {
            min_heap.push({query[0], query[1]});
            if(min_heap.size() > k) {
                min_heap.pop();
            }

            results[i++] = min_heap.size() == k ? 
                            distance(min_heap.top()) : -1;
        }

        return results;
    }
};
