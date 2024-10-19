#pragma GCC optimize("O3", "unroll-loops")

auto _ = [](){
    return cin.tie(nullptr)->sync_with_stdio(false);
}();

class Solution {
public:
    const char findKthBit(const int & n, const int & k) {
        if(n == 1) {
            return '0';
        }

        int len = (1 << n) - 1;
        int mid_pos = (len >> 1) + 1;
        if(k == mid_pos) {
            return '1';
        }

        if(k < mid_pos) {
            return findKthBit(n - 1, k);
        }

        return findKthBit(n - 1, len - k + 1) ^ '0' ^ '1';
    }
};
