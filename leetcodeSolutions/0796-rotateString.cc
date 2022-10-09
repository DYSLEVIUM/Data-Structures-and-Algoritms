// didn't want to write this so copied from template 
template <typename T> inline T mod_add(const T& a, const T&  b, const T& mod) { return a + b > mod ? a + b - mod : (a + b); }
template <typename T> inline T mod_sub(const T& a, const T&  b, const T& mod) { return a - b < 0 ? a - b + mod : (a - b); }
template <typename T> inline T mod_mul(const T& a, const T&  b, const T& mod) { return ((((a % mod) * (b % mod)) % mod) + mod) % mod; };
template <typename T> inline T bin_pow_m(T x, T n, const T& mod) {T res = 1; while (n) { if (n & 1) res = mod_mul(res, x, mod); x = mod_mul(x, x, mod); n >>= 1; } return res % mod; }
template <typename T> inline T mod_inverse(const T& a, const T& mod) { return bin_pow_m(a, mod - 2, mod); }
template <typename T> inline T mod_div(const T& a, const T& b, const T& mod) { return mod_mul(a, mod_inverse(b, mod), mod); }

class Solution {
public:
    bool rotateString(const string &s, const string &goal) {
        constexpr long long MAXN = 110, MOD = 1e9 + 7, CHAR_SET = 26;

        vector<long long> pow(MAXN);
        pow[0] = 1;
        for(long long i = 1; i < MAXN; ++i) {
            pow[i] = mod_mul(pow[i - 1], CHAR_SET, MOD);
        }

        auto hash = [&](const string &x){
            long long res = 0;
            for(long long i = 0; i < x.size(); ++i) {
                res = mod_add(res, mod_mul(pow[i], 1LL * (x[i] - 'a' + 1), MOD), MOD);
            }
            return res;
        };

        long long s_n = s.size();

        long long s_h = hash(s), goal_h = hash(goal);
        long long iter = 0;
        cout << goal_h << '\n';
        while(iter < s_n) {
            if(s_h == goal_h) {
                return true;
            }

            // rotate
            s_h = mod_sub(s_h, 1LL * (s[iter] - 'a' + 1), MOD);
            s_h = mod_div(s_h, CHAR_SET, MOD);
            s_h = mod_add(s_h, mod_mul(pow[s_n - 1], 1LL * (s[iter] - 'a' + 1), MOD), MOD);

            ++iter;
        }

        return false;
    }
};
