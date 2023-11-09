// template <typename T> inline T mod_add(const T& a, const T&  b, const T& mod) { return a + b > mod ? a + b - mod : (a + b); }
// template <typename T> inline T mod_sub(const T& a, const T&  b, const T& mod) { return a - b < 0 ? a - b + mod : (a - b); }
// template <typename T> inline T mod_mul(const T& a, const T&  b, const T& mod) { return ((((a % mod) * (b % mod)) % mod) + mod) % mod; };
// template <typename T> inline T bin_pow_m(T x, T n, const T& mod) {T res = 1; while (n) { if (n & 1) res = mod_mul(res, x, mod); x = mod_mul(x, x, mod); n >>= 1; } return res % mod; }
// template <typename T> inline T mod_inverse(const T& a, const T& mod) { return bin_pow_m(a, mod - 2, mod); }
// template <typename T> inline T mod_div(const T& a, const T& b, const T& mod) { return mod_mul(a, mod_inverse(b, mod), mod); }

// class Solution {
// public:
//     int countHomogenous(string s) {
//         constinit static const long MOD = 1e9+7;

//         int n = s.size();

//         int ans = 0;
//         for(int i = 0; i < n; ++i) {
//             int j = i;
//             while(j < n && s[i] == s[j]) {
//                 ++j;
//             }
            
//             long cnt = j - i;
//             long res = mod_div(mod_mul(cnt, cnt + 1, MOD), 2L, MOD);
//             ans = mod_add(ans * 1L, res, MOD);
            
//             i = j - 1;
//         }

//         return ans;
//     }
// };

class Solution {
public:
    int countHomogenous(string s) {
        constinit static const long MOD = 1e9+7;

        int n = s.size();

        int streak = 0, ans = 0;
        for(int i = 0; i < n; ++i) {
            if(!i || s[i] == s[i - 1]) {
                ++streak;
            } else {
                streak = 1;
            }

            ans += streak;
            ans %= MOD;
        }

        return ans;
    }
};
