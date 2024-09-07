#pragma GCC optimize("O3", "unroll-loops")

auto _ = [](){
    return cin.tie(nullptr)->sync_with_stdio(false);
}();

class Solution {
public:
    vector<int> getFinalState(const vector<int> & nums, int k, const int & multiplier) {
        const int n = nums.size();

        using PII = pair<int, int>;

        priority_queue<PII, vector<PII>, greater<PII>> min_heap;
        for(int i = 0; const int & num : nums) {
            min_heap.push({num, i++});
        }

        while(k--){
            const auto & [val, idx] = min_heap.top();
            min_heap.push({val * multiplier, idx});

            min_heap.pop();
        }

        vector<int> result(n);
        while(!min_heap.empty()) {
            const auto & [val, idx] = min_heap.top();
            result[idx] = val;

            min_heap.pop();
        }

        return result;
    }
};
