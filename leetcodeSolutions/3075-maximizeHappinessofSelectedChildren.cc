#pragma GCC optimize("O3", "unroll-loops")

auto _ = [](){
    return cin.tie(nullptr)->sync_with_stdio(false);
}();

class Solution {
public:
    long long maximumHappinessSum(vector<int> & happiness, const int & k) {
        sort(happiness.rbegin(), happiness.rend());

        long long sum = 0;
        for(int i = 0; i < k; ++i) {
            sum += max(0L, 1L * happiness[i] - i);
        }

        return sum;
    }
};
