/*
    DYSLEVIUM's template
    Date: 18/April/2025
    Time: 15:41:18
*/

// clang-format off

// headers
#ifdef DYSLEVIUM
    #include "dyslevium.h"
#else
    // optimizations done at compile time
    #pragma GCC optimize("Ofast,fast-math,unroll-loops")
    #pragma GCC target("avx,avx2,fma,bmi,bmi2,lzcnt,popcnt")

    #include <bits/stdc++.h>

    #include <ext/pb_ds/assoc_container.hpp>
    #include <ext/pb_ds/tree_policy.hpp>
#endif

// custom functions
std::mt19937_64 RNG(std::chrono::high_resolution_clock::now().time_since_epoch().count());	// generator for shuffle and other generator which require random numbers

// modified custom hash to be used with templates from https://codeforces.com/blog/entry/62393
template <typename T>
struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(T x) const {
        static const uint64_t FIXED_RANDOM = RNG();
        return splitmix64(std::hash<T>()(x) + FIXED_RANDOM);
    }
};

// aliases
using ll = long long;
using ld = long double;
using pl = std::pair<ll, ll>;
using vl = std::vector<ll>;
using vvl = std::vector<vl>;
using vpl = std::vector<pl>;

#ifndef DYSLEVIUM
    template <typename T>
    using pbds_ordered_set = __gnu_pbds::tree<T, __gnu_pbds::null_type, std::less<T>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update>;  // find_by_order, order_of_key

    template <typename T1, typename T2>
    using pbds_unordered_map = __gnu_pbds::gp_hash_table<T1, T2, custom_hash<T1>>; // 4x - 10x faster than stl unordered_map
#endif
// constants
static const constexpr long double EPS(1e-9);
static const constexpr int MOD(1e9 + 7);  //  or (119 << 23) + 1; primitive_root = 3; // = 998244353
static const constexpr long long INF(0x3f3f3f3f3f3f3f3f);
static const constexpr long double PI(3.14159265358979323846);

// macros
#define pb push_back
#define eb emplace_back
#define F first
#define S second
#define fo(i, n) for (ll i = 0; i < (ll)n; ++i)
#define Fo(i, k, n) for (ll i = k; k < (ll)n ? i < (ll)n : i > (ll)n; k < (ll)n ? ++i : --i)
#define tr(it, cont) for (auto it = cont.begin(); it != cont.end(); ++it)
#define all(x) x.begin(), x.end()
#define ps(x) std::fixed << std::setprecision(x)
#define set_bits(x) __builtin_popcountll(x)
#define zero_bits(x) __builtin_ctzll(x)
#define mk(arr, n, type) type* arr = new type[n]
#define low(x) char(x | ' ')
#define upp(x) char(x & '_')
#define sz(x) x.size()

// template functions
template <typename T> inline constexpr T mod_add(const T& a, const T&  b, const T& mod = MOD) { return a + b >= mod ? a + b - mod : a + b; }
template <typename T> inline constexpr T mod_sub(const T& a, const T&  b, const T& mod = MOD) { return a - b < 0 ? mod_add(a - b, mod) : a - b; }
template <typename T> inline constexpr T mod_mul(const T& a, const T&  b, const T& mod = MOD) { return ((((a % mod) * (b % mod)) % mod) + mod) % mod; };
template <typename T> inline constexpr T bin_pow(T x, T n) {T res = 1; while (n) { if (n & 1) res *= x; x *= x; n >>= 1; } return res; }
template <typename T> inline constexpr T bin_pow_m(T x, T n, const T& mod = MOD) {T res = 1; while (n) { if (n & 1) res = mod_mul(res, x, mod); x = mod_mul(x, x, mod); n >>= 1; } return res % mod; }
template <typename T> inline constexpr T mod_inverse(const T& a, const T& mod = MOD) { return bin_pow_m(a, mod - 2, mod); }
template <typename T> inline constexpr T mod_div(const T& a, const T& b, const T& mod = MOD) { return mod_mul(a, mod_inverse(b, mod), mod); }

// operator overloading
template <typename T> std::istream& operator>>(std::istream &is, std::vector<T> &v) { for (auto &it : v) is >> it; return is; }
template <typename T> std::ostream& operator<<(std::ostream &os, const std::vector<T> &v) { for (const auto &it : v) os << it << ' '; return os; }

template <typename T1, typename T2> std::istream& operator>>(std::istream &is, std::pair<T1, T2> &p) { is >> p.first >> p.second; return is; }
template <typename T1, typename T2> std::ostream& operator<<(std::ostream &os, const std::pair<T1, T2> &p) { os << p.first << ' ' << p.second; return os; }

// debugging
#ifdef DYSLEVIUM
    #define deb(x) std::cerr << #x << " = " << x << '\n'
#else
    #define deb(x)
#endif

inline void solve();

inline void setup(){
    // std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr)->sync_with_stdio(false);

    #ifndef ONLINE_JUDGE  // runs automatically for supported online judges
        freopen("input.in", "r", stdin);
        freopen("output.out", "w", stdout);
        freopen("error.err", "w", stderr);
    #endif
}

int main(int argc, char* argv[]) {
    setup();

    auto startTime = std::chrono::high_resolution_clock::now();

    ll t = 1;
    // std::cin >> t;

    while (t--) solve();

    auto endTime = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(endTime - startTime);

    #ifdef DYSLEVIUM
        std::cerr << "\nTime: " << duration.count() << "ms";
    #endif

    return 0;
}

using namespace std;

// clang-format on

inline void solve() {
    ll r, c;
    cin >> r >> c;

    vector<vector<char>> gr(r, vector<char>(c));
    cin >> gr;

    vvl md(r, vl(c, INF));
    vvl hd(r, vl(c, INF));

    queue<pl> qu;
    fo(i, r) {
        fo(j, c) {
            if (gr[i][j] == 'M') {
                qu.push({i, j});
            }
        }
    }

    unordered_map<char, pl> dm;
    dm['U'] = {-1, 0};
    dm['D'] = {1, 0};
    dm['L'] = {0, -1};
    dm['R'] = {0, 1};

    vvl vis(r, vl(c));
    auto is_valid = [&](const ll& i, const ll& j) {
        return !(i < 0 || j < 0 || i >= r || j >= c || gr[i][j] == '#' ||
                 vis[i][j]);
    };

    ll t = 0;
    while (!qu.empty()) {
        ll sz = sz(qu);
        while (sz--) {
            auto [i, j] = qu.front();
            qu.pop();

            if (vis[i][j]) {
                continue;
            }

            md[i][j] = t;
            vis[i][j] = 1;
            for (const auto& [_, d] : dm) {
                auto& [dr, dc] = d;

                ll nr = i + dr, nc = j + dc;
                if (!is_valid(nr, nc)) {
                    continue;
                }

                qu.push({nr, nc});
            }
        }

        ++t;
    }

    qu = {};
    fo(i, r) {
        fo(j, c) {
            if (gr[i][j] == 'A') {
                qu.push({i, j});
                break;
            }
        }

        if (!qu.empty()) {
            break;
        }
    }

    t = 0;
    vis = vvl(r, vl(c));
    while (!qu.empty()) {
        ll sz = sz(qu);
        while (sz--) {
            auto [i, j] = qu.front();
            qu.pop();

            if (vis[i][j]) {
                continue;
            }

            hd[i][j] = t;
            vis[i][j] = 1;

            for (const auto& [_, d] : dm) {
                auto& [dr, dc] = d;

                ll nr = i + dr, nc = j + dc;
                if (!is_valid(nr, nc)) {
                    continue;
                }

                qu.push({nr, nc});
            }
        }

        ++t;
    }

    // find along border, what are valid points
    bool ok = false;
    pl ed = {-1, -1};
    fo(i, r) {
        fo(j, c) {
            if (!(i == 0 || j == 0 || i == r - 1 || j == c - 1)) {
                continue;
            }

            if (hd[i][j] < md[i][j]) {
                ed = {i, j};
                ok = true;
                break;
            }
        }

        if (ok) {
            break;
        }
    }

    if (!ok) {
        cout << "NO";
        return;
    }

    ll dis = hd[ed.F][ed.S];
    cout << "YES\n" << dis << '\n';

    vis = vvl(r, vl(c));

    unordered_map<char, char> dmi;
    dmi['U'] = 'D';
    dmi['D'] = 'U';
    dmi['L'] = 'R';
    dmi['R'] = 'L';

    vector<char> p(dis);
    while (dis--) {
        auto& [i, j] = ed;

        pair<char, pl> minn;
        for (const auto& d : dm) {
            const auto& [dr, dc] = d.S;

            ll nr = i + dr, nc = j + dc;
            if (!is_valid(nr, nc)) {
                continue;
            }

            if (hd[nr][nc] < md[nr][nc] &&
                hd[nr][nc] < hd[i + minn.S.F][j + minn.S.S]) {
                minn = d;
            }
        }

        i += minn.S.F, j += minn.S.S;

        p[dis] = dmi[minn.F];
    }

    fo(i, sz(p)) cout << p[i];
}
