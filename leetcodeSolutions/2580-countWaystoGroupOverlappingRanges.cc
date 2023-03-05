template <typename T> inline T mod_add(const T& a, const T&  b, const T& mod) { return a + b > mod ? a + b - mod : (a + b); }
template <typename T> inline T mod_sub(const T& a, const T&  b, const T& mod) { return a - b < 0 ? a - b + mod : (a - b); }
template <typename T> inline T mod_mul(const T& a, const T&  b, const T& mod) { return ((((a % mod) * (b % mod)) % mod) + mod) % mod; };
template <typename T> inline T bin_pow(T x, T n) {T res = 1; while (n) { if (n & 1) res *= x; x *= x; n >>= 1; } return res; }
template <typename T> inline T bin_pow_m(T x, T n, const T& mod) {T res = 1; while (n) { if (n & 1) res = mod_mul(res, x, mod); x = mod_mul(x, x, mod); n >>= 1; } return res % mod; }
template <typename T> inline T mod_inverse(const T& a, const T& mod) { return bin_pow_m(a, mod - 2, mod); }
template <typename T> inline T mod_div(const T& a, const T& b, const T& mod) { return mod_mul(a, mod_inverse(b, mod), mod); }

class Solution {
public:
    int countWays(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        
        int ans = 0;
        for(int i=0;i<intervals.size();++i){
            int start = intervals[i][0];
            int end = intervals[i][1];

            int j = i+1;
            while(j<intervals.size() && intervals[j][0]<=end){
                end = max(end, intervals[j][1]);
                ++j;
            }
            
            i = j-1;
            ++ans;
        }
        
        return bin_pow_m<long long>(2LL, ans, 1e9 + 7);
    }
};
