/*
  DYSLEVIUM's template
  Date: 23/February/2022
  Time: 17:28:22
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
template <typename T>
class TreeNode {
 public:
  T data;
  vector<TreeNode<T>*> children;

  explicit TreeNode(T da) : data(da) {}
};

inline void solve() {
  constexpr ll MAX_N = 8;
  static_assert(MAX_N == 8);  //  making it compile time

  TreeNode<ll>* root = new TreeNode<ll>(0);
  TreeNode<ll>* root_2 = new TreeNode<ll>(1);
  TreeNode<ll>* root_3 = new TreeNode<ll>(2);

  root->children.pb(root_2);
  root->children.pb(root_3);

  root_2->children.pb(new TreeNode<ll>(3));
  root_2->children.pb(new TreeNode<ll>(4));

  root_3->children.pb(new TreeNode<ll>(5));
  root_3->children.pb(new TreeNode<ll>(6));

  //  basically flattening a tree

  //  euler tour can be of different types
  auto euler_tour = [](const TreeNode<ll>* const root) {
    vl euler;

    // type 1
    auto dfs_1 = [&euler](const auto& dfs_1,
                          const TreeNode<ll>* const node) -> void {
      euler.pb(node->data);
      for (auto& child : node->children) {
        dfs_1(dfs_1, child);
        euler.pb(node->data);
      }
    };
    dfs_1(dfs_1, root);

    // type 2
    // auto dfs_2 = [&euler](const auto& dfs_2,
    //                       const TreeNode<ll>* const node) -> void {
    //   euler.pb(node->data);
    //   for (auto& child : node->children) {
    //     dfs_2(dfs_2, child);
    //   }
    //   euler.pb(node->data);
    // };
    // dfs_2(dfs_2, root);

    return euler;
  };
  auto euler = euler_tour(root);
  cout << euler << '\n';

  //  we can use this type 2 euler tour to get if a node is in the subtree of
  //  another node in O(n) using in-time and out-time
  // auto euler_tour_1 = [&MAX_N](const TreeNode<ll>* const root) {
  //   vl in(MAX_N), out(MAX_N);
  //   ll cnt = 0;
  //   auto dfs_1 = [&in, &out, &cnt](const auto& dfs_1,
  //                                  const TreeNode<ll>* const node) -> void {
  //     in[node->data] = cnt++;
  //     for (auto& child : node->children) dfs_1(dfs_1, child);
  //     out[node->data] = cnt++;
  //   };

  //   dfs_1(dfs_1, root);
  //   return pair<vl, vl>{in, out};
  // };

  // auto euler_1 = euler_tour_1(root);
  // cout << euler_1.F << '\n';
  // cout << euler_1.S << '\n';

  //  we can use type 1 to get LCA in O(1) with pre-computation O(nlog n)
  //  we modify the tree a little, we increase the values of the nodes with
  //  level order (done using bfs)
  // so now the euler tour of type 1 will be as follows: ...B..A..C..., here A<B
  // and A<C, as we went in level order and assigned them new values of
  // increasing value on each level, where A will be the LCA of B and C
  //  finally, we can perform RMQ with sparse table to find the minimum in O(1)
}
