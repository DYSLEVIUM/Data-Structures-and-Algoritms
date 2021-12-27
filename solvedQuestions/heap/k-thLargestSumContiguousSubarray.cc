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
typedef std::unordered_map<ll, ll> mll;
typedef std::priority_queue<ll> pqd;
typedef std::priority_queue<ll, vl, std::greater<ll>> pqi;

// clang-format off
#define pb push_back
#define eb emplace_back
#define F first
#define S second
#define MOD (ll)(1e9 + 7)
#define PI 3.14159265358979323846

std::mt19937_64 RNG(std::chrono::high_resolution_clock::now().time_since_epoch().count());  // generator for shuffle and other generator which require random numbers

// macro functions
#define fo(i, n) for (ll i = 0; i < (ll)n; ++i)
#define Fo(i, k, n) for (ll i = k; k < (ll)n ? i < (ll)n : i > (ll)n; k < (ll)n ? ++i : --i)
#define all(x) x.begin(), x.end()
#define tr(it, a) for (auto it = a.begin(); it != a.end(); ++it)
#define ps(x, y) std::fixed << std::setprecision(y) << x
#define setbits(x) __builtin_popcountll(x)
#define zerobits(x) __builtin_ctzll(x)
#define mod_add(a, b) ((((a % MOD) + (b % MOD)) % MOD) + MOD) % MOD
#define mod_sub(a, b) ((((a % MOD) - (b % MOD)) % MOD) + MOD) % MOD
#define mod_mul(a, b) ((((a % MOD) * (b % MOD)) % MOD) + MOD) % MOD

// template functions
template <typename T>using ordered_set = __gnu_pbds::tree<T, __gnu_pbds::null_type, std::less<T>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update>;  // find_by_order, order_of_key
template <typename T>inline T gcd(const T& a, const T& b) {if (b) return gcd(b, a % b);return a;}
template <typename T>inline T binPow(T x, T n) {T res = 1;while (n) {if (n & 1) res *= x;x *= x;n >>= 1;}return res;}
template <typename T>inline T binPowM(T x, T n) {T res = 1;while (n) {if (n & 1) res = modMul(res, x);x = modMul(x, x);n >>= 1;}return res % MOD;}
template <typename T>inline T modInverse(const T& a) {return binPowIter(a, MOD - 2);}
template <typename T>inline T modDiv(const T& a, const T& b) {return (modMul(a, modInverse(b)) + MOD) % MOD;}

// debuging
#ifdef DYSLEVIUM
#define deb(x) std::cerr << #x << " = " << x << '\n'
#else
#define deb(x)
#endif

// initial setup
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
  auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(endTime - startTime);

  #ifdef DYSLEVIUM
    std::cerr << "\nTime: " << duration.count();
  #endif

  return 0;
}

using namespace std;

// Compile and run: g++ -std=c++17 -g -Wshadow -Wall main.cc -D DYSLEVIUM -o a.exe -Ofast -Wno-unused-result && ./a.exe

// clang-format on

inline void solve() {
  vl ar{10, -10, 20, -40};
  ll n = ar.size();
  ll k = 6;

  vl pre(n + 1);
  pre[0] = 0;
  pre[1] = ar[0];
  Fo(i, 2, n + 1) pre[i] = pre[i - 1] + ar[i - 1];

  priority_queue<ll, vl, greater<ll>> min_heap;

  Fo(i, 1, n + 1) {
    Fo(j, i, n + 1) {
      ll x = pre[j] - pre[i - 1];

      min_heap.push(x);

      if (min_heap.size() > k) min_heap.pop();
    }
  }

  cout << min_heap.top() << '\n';
}
