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

class Solution1 {
public:
    int pivotInteger(const int & n) {
        unsigned long long total = n * (n + 1) / 2;
        unsigned long long sum = 0;
        for(int i = 1; i <= n; ++i) {
            sum += i;
            unsigned long long other = total - sum + i;
            if (sum == other) {
                return i;
            }
        }

        return -1;
    }
};
