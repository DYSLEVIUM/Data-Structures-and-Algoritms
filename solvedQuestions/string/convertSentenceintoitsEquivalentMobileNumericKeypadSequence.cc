#define _USE_MATH_DEFINES
#pragma GCC optimize("Ofast,fast-math,unroll-loops")

#ifdef DYSLEVIUM
#include "dyslevium.h"
#else
#include <bits/stdc++.h>
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

std::mt19937_64 RNG(std::chrono::high_resolution_clock::now().time_since_epoch().count());

//  macro functions
#define fo(i, n) for (ll i = 0; i < (ll)n; ++i)
#define Fo(i, k, n) for (ll i = k; k < (ll)n ? i < (ll)n : i > (ll)n; k < (ll)n ? ++i : --i)
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
inline T modInverse(const T& a) { return binPowIter(a, MOD - 2); }
template <typename T>
inline T modDiv(const T& a, const T& b) { return (modMul(a, modInverse(b)) + MOD) % MOD; }

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
  std::cout.tie(nullptr);
  std::cerr.tie(nullptr);

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
  std::cin >> t;

  while (t--) solve();

  auto endTime = std::chrono::high_resolution_clock::now();

  auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(endTime - startTime);

#ifdef DYSLEVIUM
  std::cerr << "\nTime: " << duration.count();
#endif

  return 0;
}

using namespace std;

//  Compile and run: g++ -std=c++17 -g -Wshadow -Wall main.cc -D DYSLEVIUM -o a -Ofast -Wno-unused-result && ./a

inline void solve() {
  string imp = "HELLO WORLD";

  unordered_map<char, string> mp;
  mp[' '] = "0";
  mp['A'] = "2";
  mp['B'] = "22";
  mp['C'] = "222";
  mp['D'] = "3";
  mp['E'] = "33";
  mp['F'] = "333";
  mp['G'] = "4";
  mp['H'] = "44";
  mp['I'] = "444";
  mp['J'] = "5";
  mp['K'] = "55";
  mp['L'] = "555";
  mp['M'] = "6";
  mp['N'] = "66";
  mp['O'] = "666";
  mp['P'] = "7";
  mp['Q'] = "77";
  mp['R'] = "777";
  mp['S'] = "7777";
  mp['T'] = "8";
  mp['U'] = "88";
  mp['V'] = "888";
  mp['W'] = "9";
  mp['X'] = "99";
  mp['Y'] = "999";
  mp['Z'] = "9999";

  string opt = "";

  for (auto x : imp) opt += mp[x];

  cout << opt;
}
