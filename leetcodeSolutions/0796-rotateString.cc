#pragma GCC optimize("O3", "unroll-loops")

auto _ = [](){
    return cin.tie(nullptr)->sync_with_stdio(false);
}();

static const constexpr int MOD(1e9 + 7);

template <typename T> inline constexpr T mod_add(const T& a, const T&  b, const T& mod = MOD) { return a + b >= mod ? a + b - mod : a + b; }
template <typename T> inline constexpr T mod_sub(const T& a, const T&  b, const T& mod = MOD) { return a - b < 0 ? mod_add(a - b, mod) : a - b; }
template <typename T> inline constexpr T mod_mul(const T& a, const T&  b, const T& mod = MOD) { return ((((a % mod) * (b % mod)) % mod) + mod) % mod; };
template <typename T> inline constexpr T bin_pow(T x, T n) {T res = 1; while (n) { if (n & 1) res *= x; x *= x; n >>= 1; } return res; }
template <typename T> inline constexpr T bin_pow_m(T x, T n, const T& mod = MOD) {T res = 1; while (n) { if (n & 1) res = mod_mul(res, x, mod); x = mod_mul(x, x, mod); n >>= 1; } return res % mod; }
template <typename T> inline constexpr T mod_inverse(const T& a, const T& mod = MOD) { return bin_pow_m(a, mod - 2, mod); }
template <typename T> inline constexpr T mod_div(const T& a, const T& b, const T& mod = MOD) { return mod_mul(a, mod_inverse(b, mod), mod); }

static const constexpr int MAX_N = 100, CHAR_SET = 26;
consteval array<int, MAX_N + 1> generate_pow() {
    array<int, MAX_N + 1> pows;
    pows[0] = 1;
    for(int i = 1; i < MAX_N + 1; ++i) {
        pows[i] = mod_mul(1LL * pows[i - 1], 1LL * CHAR_SET);
    }
    return pows;
}

class Solution {
public:
    bool rotateString(string & s, string & goal) {
        static const constexpr auto pows = generate_pow();

        const int n1 = s.size(), n2 = goal.size();
        if(n1 != n2) {
            return false;
        }

        auto hash = [](string & s) {
            long long res = 0;
            for(int i = 0; const char & ch: s) {
                long long ch_val = ch - 'a' + 1;
                res = mod_add(res, mod_mul(1LL * pows[i++], ch_val));
            }

            return res;
        };

        long long s_h = hash(s), g_h = hash(goal);
        for(int i = 0; i < n1; ++i) {
            if(s_h == g_h) {
                return true;
            }

            long long ch_val = s[i] - 'a' + 1;

            s_h = mod_sub(s_h, ch_val);
            s_h = mod_div(s_h, 1LL * CHAR_SET);
            s_h = mod_add(s_h, mod_mul(1LL * pows[n1 - 1], ch_val));
        }

        return false;
    }
};
