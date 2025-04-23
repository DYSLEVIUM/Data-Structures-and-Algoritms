// The rand7() API is already defined for you.
// int rand7();
// @return a random integer in the range 1 to 7

#pragma GCC optimize("O3", "unroll-loops")

auto _ = [](){
    return cin.tie(nullptr)->sync_with_stdio(false);
}();

class Solution {
public:
    int rand10() {
        static constinit const int N = 7;

        int row, col, idx;
        do {
            row = rand7(), col = rand7();
            idx = (row - 1) * N + col;
        } while(idx > 40);

        return (idx - 1) % 10 + 1;
    }
};
