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
#define MOD (ll)(1e9 + 7)

#define fo(i, n) for (ll i = 0; i < (ll)n; ++i)
#define Fo(i, k, n) for (ll i = k; k < (ll)n ? i < (ll)n : i > (ll)n; k < (ll)n ? ++i : --i)
#define all(x) x.begin(), x.end()
#define tr(it, a) for (auto it = a.begin(); it != a.end(); ++it)
#define ps(x, y) std::fixed << std::setprecision(y) << x
#define setbits(x) __builtin_popcountll(x)
#define zerobits(x) __builtin_ctzll(x)

std::mt19937_64 rng(std::chrono::high_resolution_clock::now().time_since_epoch().count());

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

#ifdef DYSLEVIUM
  freopen("input.in", "r", stdin);
  freopen("output.out", "w", stdout);
  freopen("error.err", "w", stderr);
#endif
}

inline void solve();

int main(int argc, char* argv[]) {
  setup();

  ll t = 1;
  // std::cin >> t;

  while (t--)
    solve();

  return 0;
}

using namespace std;

//  Compile and run: g++ -std=c++17 -g -Wshadow -Wall main.cc -D DYSLEVIUM -o a -Ofast -Wno-unused-result && ./a

inline void solve() {
  //  given a and b, find the minimum number of bits to filp to make a = b
  {
    ll a = 11, b = 15;
    ll temp = a ^ b;  // (1011 ^ 1111)

    ll ans = 0;
    while (temp) {
      ans += (temp & 1);
      temp >>= 1;
    }

    cout << ans << '\n';
  }

  //  remove the last set bit
  {
    ll n = 13;  //  given 1101 => 1100
    cout << (n & (n - 1)) << '\n';
  }

  //  xor swapping
  {
    ll a = 10, b = 15;
    a = a ^ b;
    b = a ^ b;
    a = a ^ b;
    cout << a << ' ' << b << '\n';
  }

  //  extract the ith bit
  {
    ll a = 13;  // 1101
    ll i = 2;   //  0 based indexing

    ll mask = 1 << i;
    cout << (mask & a) << '\n';
  }

  //  change the ith bit
  {
    ll a = 13;  //  1101
    ll i = 2;

    ll mask = 1 << i;

    cout << (mask ^ a) << '\n';
  }

  //  clearing ith bit
  {
    ll a = 13;  // 1101
    ll i = 2;

    ll mask = ~(1 << i);

    deb(mask);

    cout << (mask & a) << '\n';
  }

  //  find the righmost set bit
  {
    ll a = 12;  //  1100

    ll mask = a & ~(a - 1); //  1100 & ~(1011) => 1100 & 0100

    ll iter = 0;
    while (mask) {
      if (mask & 1) break;
      ++iter;
      mask >>= 1;
    }

    cout << iter << '\n';
  }
}
