/*
  DYSLEVIUM's template
  Date: 24/February/2022
  Time: 10:51:40
*/

// headers
#ifdef DYSLEVIUM
#include "dyslevium.h"
#else
// optimizations done at compile time
// #pragma GCC optimize("Ofast,fast-math,unroll-loops")
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
class SegmentTree {
 public:
  SegmentTree(const size_t& st_idx, const size_t& ed_idx, const vl& arr,
              const vl& val)
      : left_most(st_idx), right_most(ed_idx) {
    if (left_most == right_most) {
      value_ = val[arr[left_most]];

      left_tree = right_tree = nullptr;
    } else {
      size_t mid = left_most + (right_most - left_most) / 2;

      left_tree = new SegmentTree(left_most, mid, arr, val);
      right_tree = new SegmentTree(mid + 1, right_most, arr, val);

      recalculate();
    }
  };

  void point_update(const size_t& idx, const ll& val) {
    if (left_most == right_most) {
      value_ = val;
      return;
    } else if (idx <= left_tree->right_most)
      left_tree->point_update(idx, val);
    else
      right_tree->point_update(idx, val);
    recalculate();
  }

  ll range_query(const size_t& l, const size_t& r) {
    if (l > right_most || r < left_most) return 0;

    if (l <= left_most && r >= right_most) return value_;

    return left_tree->range_query(l, r) + right_tree->range_query(l, r);
  }

  ~SegmentTree() {
    delete left_tree;
    delete right_tree;
    left_tree = right_tree = nullptr;
  }

 private:
  size_t left_most, right_most;

  ll value_;

  SegmentTree *left_tree, *right_tree;

  void recalculate() { value_ = left_tree->value_ + right_tree->value_; }
};

inline void solve() {
  ll n, q;
  cin >> n >> q;

  vl val(n);
  cin >> val;

  vvl gr(n);
  fo(i, n - 1) {
    ll a, b;
    cin >> a >> b;

    --a, --b;

    gr[a].pb(b);
    gr[b].pb(a);
  }

  //  find the euler tour of the tree rooted at 0
  vl euler;
  vl in(n), out(n);
  ll cnt = 0;
  auto dfs = [&val, &gr, &euler, &in, &out, &cnt](
                 const auto& dfs, const ll& node, const ll& parent) -> void {
    euler.pb(node);
    in[node] = cnt++;
    for (auto& child : gr[node]) {
      if (child != parent) dfs(dfs, child, node);
    }
    out[node] = cnt++;
    euler.pb(node);
  };
  dfs(dfs, 0, -1);

  ll euler_sz = euler.size();

  //  make a segment tree on the euler tour
  SegmentTree seg_tree(0, euler_sz - 1, euler, val);

  while (q--) {
    ll type;
    cin >> type;

    ll s;
    cin >> s;
    --s;

    if (type == 1) {
      ll x;
      cin >> x;

      seg_tree.point_update(in[s], x);
      seg_tree.point_update(out[s], x);
    } else
      cout << seg_tree.range_query(in[s], out[s]) / 2 << '\n';
  }
}
