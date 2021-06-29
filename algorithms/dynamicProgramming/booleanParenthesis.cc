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
  string s = "T|T&F^T";

  vector<vvl> dp(s.length() + 1, vvl(s.length() + 1, vl(2, -1)));

  //  number of ways to evaluate expression to true
  auto booleanParenthesis = [&dp](const string& x, ll i, ll j, bool isTrue, auto&& booleanParenthesis) {
    if (dp[i][j][isTrue] != -1) return dp[i][j][isTrue];

    if (i > j) return (ll)0;

    if (i == j) {
      if (isTrue)
        return (x[i] == 'T' ? (ll)1 : (ll)0);
      else
        return (x[i] == 'F' ? (ll)1 : (ll)0);
    }

    ll ans = 0;

    Fo(k, i + 1, j) {
      ll leftTrue = booleanParenthesis(x, i, k - 1, true, booleanParenthesis);
      ll leftFalse = booleanParenthesis(x, i, k - 1, false, booleanParenthesis);

      ll rightTrue = booleanParenthesis(x, k + 1, j, true, booleanParenthesis);
      ll rightFalse = booleanParenthesis(x, k + 1, j, false, booleanParenthesis);

      // and
      if (x[k] == '&') {  //  and
        if (isTrue)
          ans += leftTrue * rightTrue;
        else
          ans += leftTrue * rightFalse + leftFalse * rightTrue + leftFalse * rightFalse;
      } else if (x[k] == '|') {  //  or
        if (isTrue)
          ans += leftTrue * rightTrue + leftTrue * rightFalse + leftFalse * rightTrue;
        else
          ans += leftFalse * rightFalse;
      } else {  //  xor
        if (isTrue)
          ans += leftFalse * rightTrue + leftTrue * rightFalse;
        else
          ans += leftTrue * rightTrue + leftFalse * rightFalse;
      }

      ++k;  //  k should always be at operator
    }

    return dp[i][j][isTrue] = ans;
  };

  cout << booleanParenthesis(s, 0, s.length() - 1, true, booleanParenthesis);
}
