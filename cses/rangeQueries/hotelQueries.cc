/*
  DYSLEVIUM's template
  Date: 25/March/2022
  Time: 09:54:55
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
// modified custom hash to used with templates from https://codeforces.com/blog/entry/62393
template<typename T>
class custom_hash {
 public:
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
constexpr long double EPS(1e-9);
constexpr long long MOD(1e9 + 7);  //  or (119 << 23) + 1; primitive_root = 3; // = 998244353
constexpr long double PI(3.14159265358979323846);

// macros
#define pb push_back
#define F first
#define S second
#define fo(i, n) for (ll i = 0; i < (ll)n; ++i)
#define Fo(i, k, n) for (ll i = k; k < (ll)n ? i < (ll)n : i > (ll)n; k < (ll)n ? ++i : --i)
#define all(x) x.begin(), x.end()
#define ps(x, y) std::fixed << std::setprecision(y) << x
#define set_bits(x) __builtin_popcountll(x)
#define zero_bits(x) __builtin_ctzll(x)
#define mk(arr, n, type) type* arr = new type[n]

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
template<typename T> std::ostream& operator<<(std::ostream &os, const std::vector<T> &v) { for (auto &it : v) os << it << ' '; return os; }

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
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
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
    std::cerr << "Time: " << duration.count();
  #endif

  return 0;
}

using namespace std;

// clang-format on
void solve() {
  ll n, m;
  cin >> n >> m;

  vl h(n);
  cin >> h;

  vl seg_tree(4 * n, LONG_LONG_MIN);

  auto calc = [](const ll& x, const ll& y) { return max(x, y); };

  auto build = [&h, &seg_tree, &calc](const auto& build, const auto& idx,
                                      const ll& lo, const ll& hi) {
    if (lo == hi) {
      seg_tree[idx] = h[lo];
      return;
    }

    ll mid = lo + (hi - lo) / 2;

    build(build, 2 * idx + 1, lo, mid);
    build(build, 2 * idx + 2, mid + 1, hi);

    seg_tree[idx] = calc(seg_tree[2 * idx + 1], seg_tree[2 * idx + 2]);
  };

  auto update = [&seg_tree, &calc](const auto& update, const ll& idx,
                                   const ll& id, const ll& val, const ll& a,
                                   const ll& b, const ll& lo, const ll& hi) {
    if (lo == hi) {
      seg_tree[idx] = val;
      return;
    }

    ll mid = lo + (hi - lo) / 2;
    if (id <= mid)
      update(update, 2 * idx + 1, id, val, a, b, lo, mid);
    else
      update(update, 2 * idx + 2, id, val, a, b, mid + 1, hi);

    seg_tree[idx] = calc(seg_tree[2 * idx + 1], seg_tree[2 * idx + 2]);
  };

  vl ans;
  auto query = [&n, &h, &seg_tree, &calc, &update, &ans](
                   const auto& query, const ll& idx, const ll& lo, const ll& hi,
                   const ll& r) {
    if (lo == hi) {
      ans.push_back(lo + 1);
      update(update, 0, lo, seg_tree[idx] - r, 0, n - 1, 0, n - 1);
      return;
    }

    ll mid = lo + (hi - lo) / 2;

    if (seg_tree[2 * idx + 1] >= r) {
      query(query, 2 * idx + 1, lo, mid, r);
    } else {
      query(query, 2 * idx + 2, mid + 1, hi, r);
    }

    seg_tree[idx] = calc(seg_tree[2 * idx + 1], seg_tree[2 * idx + 2]);
    return;
  };

  build(build, 0, 0, n - 1);

  while (m--) {
    ll r;
    cin >> r;

    if (seg_tree[0] < r)
      ans.pb(0);
    else
      query(query, 0, 0, n - 1, r);
  }

  cout << ans;
}
