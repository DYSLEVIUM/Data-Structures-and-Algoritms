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

//  Compile and run: g++ -std=c++17 -g -Wshadow -Wall main.cc -D DYSLEVIUM -o a -Ofast -Wno-unused-result && ./a

inline void solve() {
  //  search index of element in a bitonic array
  vl arr{1, 3, 8, 12, 4, 2};
  ll key = 4;

  //  peak element will act as divider where, on one half the array is increasing and on the other it will be decreasing

  //  binary search on answer
  ll lo = 0;
  ll hi = arr.size() - 1;

  ll div = -1;

  while (lo <= hi) {
    bool ok = false;
    ll mid = lo + (hi - lo) / 2;

    if (mid > 0 && mid < arr.size() - 1) {
      if (arr[mid] > arr[mid - 1] && arr[mid] > arr[mid + 1]) {
        div = mid;
        ok = true;
      }
      //  going to the more probable side to get the answer
      else if (arr[mid - 1] > arr[mid])
        hi = mid - 1;
      else
        lo = mid + 1;
    } else if (mid == 0) {  //  edge conditions
      if (arr[0] > arr[1])
        div = 0;
      else
        div = 1;

      ok = true;
    } else {
      if (arr[arr.size() - 1] > arr[arr.size() - 2])
        div = arr.size() - 1;
      else
        div = arr.size() - 2;

      ok = true;
    }

    if (ok) break;
  }

  auto bsI = [](const vl& ar, const ll& key, ll lo, ll hi) {
    while (lo <= hi) {
      ll mid = lo + (hi - lo) / 2;

      if (ar[mid] == key)
        return true;
      else if (ar[mid] > key)
        hi = mid - 1;
      else
        lo = mid + 1;
    }

    return false;
  };

  auto bsD = [](const vl& ar, const ll& key, ll lo, ll hi) {
    while (lo <= hi) {
      ll mid = lo + (hi - lo) / 2;

      if (ar[mid] == key)
        return true;
      else if (ar[mid] > key)
        lo = mid + 1;
      else
        hi = mid - 1;
    }

    return false;
  };

  //  now we do a binary search on both the sides
  if (bsI(arr, key, 0, div) || bsD(arr, key, div + 1, arr.size() - 1))
    cout << "Yes\n";
  else
    cout << "No\n";
}
