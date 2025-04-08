#pragma GCC optimize("O3", "unroll-loops")

auto _ = [](){
    return cin.tie(nullptr)->sync_with_stdio(false);
}();

class Solution {
public:
    int minimumOperations(const vector<int> & nums) {
        static constinit const int MAX_N = 100;

        const int n = nums.size();

        array<int, MAX_N + 1> se;
        for(int i = n - 1; i >= 0; --i) {
            const int key = nums[i];
            if(se[key]++) {
                return i / 3 + 1;
            }
        }

        return 0;
    }
};
