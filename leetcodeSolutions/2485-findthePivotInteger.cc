# pragma GCC optimize("O3", "unroll-loops")

auto _ = [](){
    return cin.tie(nullptr)->sync_with_stdio(false);
}();

class Solution {
public:
    int pivotInteger(const int & n) {
        double x = sqrt((n * n + n) / 2);
        return x - floor(x) ? -1 : x;
    }
};
