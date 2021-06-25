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
  string a = "aggtab";
  string b = "axtxayb";

  auto lcs = [](string x, string y) {
    vvl dp(x.length() + 1, vl(y.length() + 1));

    fo(i, x.length() + 1) {
      fo(j, y.length() + 1) {
        if (i == 0 || j == 0) {
          dp[i][j] = 0;
        } else {
          if (x[i - 1] == y[j - 1]) {
            dp[i][j] = 1 + dp[i - 1][j - 1];
          } else {
            dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
          }
        }
      }
    }

    return dp[x.length()][y.length()];
  };

  cout << a.length() + b.length() - lcs(a, b) << '\n';
  
  //  alternate
  string a = "aggtab";
  string b = "axtxayb";

  auto superSeq = [](string x, string y) {
    vvl dp(x.length() + 1, vl(y.length() + 1));

    fo(i, x.length() + 1) {
      fo(j, y.length() + 1) {
        if (i == 0 || j == 0) {
          if (i == 0)
            dp[i][j] = j;
          else
            dp[i][j] = i;
        } else {
          if (x[i - 1] == y[j - 1])
            dp[i][j] = 1 + dp[i - 1][j - 1];
          else
            dp[i][j] = 1 + min(dp[i - 1][j], dp[i][j - 1]);
        }
      }
    }

    return dp[x.length()][y.length()];
  };

  cout << superSeq(a, b);
}
