static constexpr long long CHAR_SET = 26, MAXN = 1001, MOD = 1e9 + 7;

constexpr auto mod_add(const long long &x, const long long &y) {
    return x + y > MOD ? x + y - MOD : x + y;
};

constexpr auto mod_sub(const long long &x, const long long &y) {
    return x - y < 0 ? x - y + MOD : x - y;
};

constexpr auto mod_mul(const long long &x, const long long &y) {
    return ((x % MOD) * (y % MOD)) % MOD;
};

constexpr auto bin_pow_m(long long x, long long n) {
    long long res = 1;
    while (n) { 
        if (n & 1){
            res = mod_mul(res, x);
        }
        x = mod_mul(x, x);
        n >>= 1;
    }
    return res % MOD; 
};

constexpr auto mod_inv(const long long &x) {
    return bin_pow_m(x, MOD - 2);
};

constexpr auto mod_div(const long long &x, const long long &y) {
    return mod_mul(x, mod_inv(y));
};

constexpr auto get_pow() {
    array<long long, MAXN> pow{0};
    pow[0] = 1;
    for(long long i = 1; i < MAXN; ++i) {
        pow[i] = mod_mul(pow[i - 1], CHAR_SET);
    }
    return pow;
};

class Solution {
public:
    string removeOccurrences(string s, string part) {
        static constexpr auto pow = get_pow();

        auto hash = [&](const string &x){
            long long res = 0;
            for(long long i = 0; auto &ch : x) {
                res = mod_add(res, mod_mul(pow[i++], (ch - 'a' + 1)));
            }
            return res;
        };

        long long p_n = part.size();
        auto part_hash = hash(part);
        auto recur = [&](const auto &recur, const string &x) -> string {
            int x_n = x.size();

            string new_str = x;

            // hash of part.size() - 1 window
            long long curr_val = hash(x.substr(0, p_n - 1));
            for(int i = p_n - 1; i < x_n; ++i) {
                curr_val = mod_add(curr_val, mod_mul(pow[p_n - 1], x[i] - 'a' + 1));

                if(curr_val == part_hash) {
                    new_str = x.substr(0, i + 1 - p_n);
                    new_str += x.substr(i + 1, x_n - i - 1);
                    break;
                }

                curr_val = mod_sub(curr_val, x[i - p_n + 1] - 'a' + 1);
                curr_val = mod_div(curr_val, CHAR_SET);
            }

            // contains more part
            if(new_str.find(part) != string::npos) {
                return recur(recur, new_str);
            }

            return new_str;
        };

        return recur(recur, s);
    }
};
