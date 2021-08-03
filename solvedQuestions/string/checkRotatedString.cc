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

  ll t = 1;
  // std::cin >> t;

  while (t--)
    solve();

  return 0;
}

using namespace std;

//  Compile and run: g++ -std=c++17 -g -Wshadow -Wall main.cc -D DYSLEVIUM -o a -Ofast -Wno-unused-result && ./a

inline void solve() {
  string s1 = "ABACD", s2 = "CDABA";

  auto checkIfRotated = [](const string& a, const string& b) {
    if (a.length() != b.length()) return false;
    string temp = a + a;
    return (temp.find(b) != string::npos);
  };

  cout << (checkIfRotated(s1, s2) ? "YES" : "NO") << '\n';

  //  queue method
  auto checkIfRotated2 = [](const string& a, const string& b) {
    if (a.length() != b.length()) return false;

    queue<char> q1, q2;

    fo(i, a.length()) q1.push(a[i]), q2.push(b[i]);

    ll cnt = b.size();
    while (cnt--) {
      char fr = q1.front();
      q1.pop();
      q1.push(fr);

      if (q1 == q2) return true;
    }

    return false;
  };

  cout << (checkIfRotated2(s1, s2) ? "YES" : "NO") << '\n';
}
