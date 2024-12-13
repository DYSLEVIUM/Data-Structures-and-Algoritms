#pragma GCC optimize("O3", "unroll-loops")

auto _ = [](){
    return cin.tie(nullptr)->sync_with_stdio(false);
}();

class Solution {
public:
    long long findScore(vector<int>& nums) {
        const int n = nums.size();

        vector<int> idx(n);
        iota(idx.begin(), idx.end(), 1);
        ranges::stable_sort(idx.begin(), idx.end(), [&](const int & lhs, const int & rhs){
            return nums[lhs - 1] < nums[rhs - 1];
        });

        long long score = 0;
        vector<bool> marked(n + 1);
        for(const int & id: idx) {
            if(marked[id]) {
                continue;
            }

            score += 1LL * nums[id - 1];
            marked[id] = marked[id - 1] = marked[id + 1] = true;
        }

        return score;
    }
};
