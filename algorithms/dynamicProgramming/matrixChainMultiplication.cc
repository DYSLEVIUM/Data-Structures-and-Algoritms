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
#define PI 3.14159265358979323846

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
  std::cin.tie(NULL);
  std::cout.tie(NULL);

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

  while (t--) solve();

  return 0;
}

using namespace std;

//  Compile and run: g++ -std=c++17 -g -Wshadow -Wall main.cc -D DYSLEVIUM -o a -Ofast -Wno-unused-result && ./a

inline void solve() {
  vl p{40, 20, 30, 10, 30};

  vvl dp(p.size(), vl(p.size(), LONG_LONG_MAX));
  auto matrixChainRecur = [&dp](vl& a, ll i, ll j, auto&& matrixChainRecur) {
    if (dp[i][j] != LONG_LONG_MAX) return dp[i][j];

    if (i == j) return (ll)0;

    Fo(k, i, j) {
      dp[i][j] = min(dp[i][j], matrixChainRecur(a, i, k, matrixChainRecur) + matrixChainRecur(a, k + 1, j, matrixChainRecur) + a[i - 1] * a[k] * a[j]);
    }

    return dp[i][j];
  };

  cout << "Recur: " << matrixChainRecur(p, 1, p.size() - 1, matrixChainRecur) << '\n';

  auto matrixChainMulIter = [](vl& a) {
    vvl dp(a.size(), vl(a.size(), LONG_LONG_MAX));

    //  cost is zero when multiplying one matrix
    fo(i, a.size()) dp[i][i] = 0;

    Fo(len, 2, a.size()) {  //  chain length
      Fo(i, 1, a.size() - len + 1) {
        ll j = i + len - 1;
        Fo(k, i, j) {
          dp[i][j] = min(dp[i][j], dp[i][k] + dp[k + 1][j] + a[i - 1] * a[k] * a[j]);
        }
      }
    }

    return dp[1][a.size() - 1];
  };

  cout << "Iter: " << matrixChainMulIter(p) << '\n';
}
