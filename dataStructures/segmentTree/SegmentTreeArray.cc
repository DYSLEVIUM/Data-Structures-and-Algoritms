#define _USE_MATH_DEFINES
#pragma GCC optimize("Ofast,fast-math,unroll-loops")

#ifdef DYSLEVIUM
#include "dyslevium.h"
#else
#include <bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#endif

typedef long long ll;
typedef long double ld;
typedef std::pair<ll, ll> pl;
typedef std::vector<ll> vl;
typedef std::vector<pl> vpl;
typedef std::vector<vl> vvl;
typedef std::map<ll, ll> mll;
typedef std::priority_queue<ll> pqd;
typedef std::priority_queue<ll, vl, std::greater<ll>> pqi;

#define pb push_back
#define eb emplace_back
#define F first
#define S second
#define MOD (ll)(1e9 + 7)

std::mt19937_64 RNG(
    std::chrono::high_resolution_clock::now().time_since_epoch().count());

//  macro functions
#define fo(i, n) for (ll i = 0; i < (ll)n; ++i)
#define Fo(i, k, n) \
  for (ll i = k; k < (ll)n ? i < (ll)n : i > (ll)n; k < (ll)n ? ++i : --i)
#define all(x) x.begin(), x.end()
#define tr(it, a) for (auto it = a.begin(); it != a.end(); ++it)
#define ps(x, y) std::fixed << std::setprecision(y) << x
#define setbits(x) __builtin_popcountll(x)
#define zerobits(x) __builtin_ctzll(x)
#define modAdd(a, b) ((((a % MOD) + (b % MOD)) % MOD) + MOD) % MOD
#define modSub(a, b) ((((a % MOD) - (b % MOD)) % MOD) + MOD) % MOD
#define modMul(a, b) ((((a % MOD) * (b % MOD)) % MOD) + MOD) % MOD

//  template functions
template <typename T>
using ordered_set = __gnu_pbds::tree<T, __gnu_pbds::null_type, std::less<T>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update>;  // find_by_order, order_of_key
template <typename T>
inline T gcd(const T& a, const T& b) {
  if (b) return gcd(b, a % b);
  return a;
}
template <typename T>
inline T binPowIter(T x, T n) {
  T res = 1;
  while (n) {
    if (n & 1) res = modMul(res, x);
    x = modMul(x, x);
    n >>= 1;
  }
  return res % MOD;
}
template <typename T>
inline T modInverse(const T& a) {
  return binPowIter(a, MOD - 2);
}
template <typename T>
inline T modDiv(const T& a, const T& b) {
  return (modMul(a, modInverse(b)) + MOD) % MOD;
}

//  debuging
#ifdef DYSLEVIUM
#define deb(x) std::cerr << #x << " = " << x << '\n'
#else
#define deb(x)
#endif

//  initial setup
inline void setup() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

#ifdef DYSLEVIUM
  freopen("input.in", "r", stdin);
  freopen("output.out", "w", stdout);
  freopen("error.err", "w", stderr);
#endif
}

inline void solve();

int main(int argc, char* argv[]) {
  setup();

  auto startTime = std::chrono::high_resolution_clock::now();

  ll t = 1;
  // std::cin >> t;

  while (t--) solve();

  auto endTime = std::chrono::high_resolution_clock::now();

  auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(
      endTime - startTime);

#ifdef DYSLEVIUM
  std::cerr << "\nTime: " << duration.count();
#endif

  return 0;
}

using namespace std;

//  Compile and run: g++ -std=c++17 -g -Wshadow -Wall main.cc -D DYSLEVIUM -o a.exe -Ofast -Wno-unused-result && ./a.exe

inline void solve() {
  ll sz = 1e6;

  //  input array
  vl ar(sz);

  vl tree(4 * sz);
  auto build = [&tree, &ar](const ll vertex, const ll& startIdx, const ll& endIdx, const auto& build) -> void {
    if (startIdx == endIdx) {
      tree[vertex] = a[startIdx];
    } else {
      ll tm = (startIdx + endIdx) / 2;

      build(vertex * 2, startIdx, tm, build);
      build(vertex * 2 + 1, tm + 1, endIdx, build);

      tree[vertex] = tree[vertex * 2] + tree[vertex * 2 + 1];
    }
  };

  auto update = [&tree, &ar](const ll& vertex, const ll& startIdx, const ll& endIdx, const ll& pos, const ll& new_val, const auto& update) -> void {
    if (startIdx == endIdx)
      tree[vertex] = new_val;
    else {
      ll tm = (startIdx + endIdx) / 2;

      if (pos <= tm)
        update(vertex * 2, startIdx, tm, pos, new_val, update);
      else
        update(vertex * 2 + 1, tm + 1, endIdx, pos, new_val, update);

      tree[vertex] = tree[vertex * 2] + tree[vertex * 2 + 1];
    }
  };

  //! incomplete implementation, query is missing

  build(1, 0, sz - 1, build);   //  start vertex from 1
}
