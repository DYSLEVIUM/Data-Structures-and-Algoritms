/*
    DYSLEVIUM's template
    Date: 09/May/2023
    Time: 18:56:46
*/

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

// clang-format off
// custom functions
std::mt19937_64 RNG(std::chrono::high_resolution_clock::now().time_since_epoch().count());	// generator for shuffle and other generator which require random numbers
// modified custom hash to be used with templates from https://codeforces.com/blog/entry/62393
template<typename T>
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
template <typename key, typename value> using pbds_unordered_map = __gnu_pbds::gp_hash_table<key, value, custom_hash<key>>; // 3x - 6x faster than stl unordered_map
template <typename T> using pbds_set = __gnu_pbds::tree<T, __gnu_pbds::null_type, std::less<T>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update>; // find_by_order, order_of_key

// constants
static constexpr long double EPS(1e-9);
static constexpr long long MOD(1e9 + 7);  //  or (119 << 23) + 1; primitive_root = 3; // = 998244353
static constexpr long long INF(0x3f3f3f3f3f3f3f3f);
static constexpr long double PI(3.14159265358979323846);

// macros
#define pb push_back
#define eb emplace_back
#define F first
#define S second
#define fo(i, n) for (ll i = 0; i < (ll)n; ++i)
#define Fo(i, k, n) for (ll i = k; k < (ll)n ? i < (ll)n : i > (ll)n; k < (ll)n ? ++i : --i)
#define tr(it, cont) for (auto it = cont.begin(); it != cont.end(); ++it)
#define all(x) x.begin(), x.end()
#define ps(x, y) std::fixed << std::setprecision(y) << x
#define set_bits(x) __builtin_popcountll(x)
#define zero_bits(x) __builtin_ctzll(x)
#define mk(arr, n, type) type* arr = new type[n]
#define low(x) char(x | ' ')
#define upp(x) char(x & '_')

// template functions
template <typename T> inline T mod_add(const T& a, const T&  b, const T& mod) { return a + b > mod ? a + b - mod : (a + b); }
template <typename T> inline T mod_sub(const T& a, const T&  b, const T& mod) { return a - b < 0 ? a - b + mod : (a - b); }
template <typename T> inline T mod_mul(const T& a, const T&  b, const T& mod) { return ((((a % mod) * (b % mod)) % mod) + mod) % mod; };
template <typename T> inline T bin_pow(T x, T n) {T res = 1; while (n) { if (n & 1) res *= x; x *= x; n >>= 1; } return res; }
template <typename T> inline T bin_pow_m(T x, T n, const T& mod) {T res = 1; while (n) { if (n & 1) res = mod_mul(res, x, mod); x = mod_mul(x, x, mod); n >>= 1; } return res % mod; }
template <typename T> inline T mod_inverse(const T& a, const T& mod) { return bin_pow_m(a, mod - 2, mod); }
template <typename T> inline T mod_div(const T& a, const T& b, const T& mod) { return mod_mul(a, mod_inverse(b, mod), mod); }

// operator overloading
template<typename T> std::istream& operator>>(std::istream &is, std::vector<T> &v){ for (auto &it : v) is >> it; return is; }
template<typename T> std::ostream& operator<<(std::ostream &os, const std::vector<T> &v) { for (const auto &it : v) os << it << ' '; return os; }

template<typename T_1, typename T_2> std::istream& operator>>(std::istream &is, std::pair<T_1, T_2> &p){ is >> p.first >> p.second; return is; }
template<typename T_1, typename T_2> std::ostream& operator<<(std::ostream &os, const std::pair<T_1, T_2> &p) { os << p.first << ' ' << p.second; return os; }

// debuging
#ifdef DYSLEVIUM
    #define deb(x) std::cerr << #x << " = " << x << '\n'
#else
    #define deb(x)
#endif

inline void solve();

inline void setup(){
    // std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr)->sync_with_stdio(false);
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
        std::cerr << "\nTime: " << duration.count();
    #endif

    return 0;
}

using namespace std;

// clang-format on
inline void solve() {
    ll n;
    cin >> n;

    vpl time(2 * n);
    fo(i, 2 * n) {
        cin >> time[i].F >> time[i + 1].F;
        time[i].S = 1;
        time[i + 1].S = -1;
        ++i;
    }

    sort(all(time));

    // line-sweep algorithm
    ll ans = -0x3f3f3f3f, curr = 0;
    fo(i, 2 * n) {
        curr += time[i].S;
        ans = max(ans, curr);
    }

    cout << ans;
}
