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
  std::cin >> t;

  while (t--) solve();

  return 0;
}

using namespace std;

//  Compile and run: g++ -std=c++17 -g -Wshadow -Wall main.cc -D DYSLEVIUM -o a -Ofast -Wno-unused-result && ./a

inline void solve() {
  //  hash(s) = s[0] + s[1]*p + s[2]*p^2 + s[3]*p^3 + ... s[n-1]*p^(n-1) mod m

  //  where, m and p are some positive numbers. It is called a polynomial rolling hash function

  //  It is reasonable to make p a prime number roughly equal to the number of characters in the input alphabet. For example, if the input is composed of only lowercase letters of the English alphabet, p=31 is a good choice. If the input may contain both uppercase and lowercase letters, then p=53 is a possible choice. The code in this article will use p=31

  //  Obviously m should be a large number since the probability of two random strings colliding is about ≈1m. Sometimes m=264 is chosen, since then the integer overflows of 64-bit integers work exactly like the modulo operation. However, there exists a method, which generates colliding strings (which work independently from the choice of p). So in practice, m=264 is not recommended. A good choice for m is some large prime number. The code in this article will just use m=109+9. This is a large number, but still small enough so that we can perform multiplication of two values using 64-bit integers.

  auto computeHash = [](string const& s) {
    //  better to randomize the base so as to prevent from being hacked in contests
    const ll p = 31;
    const ll m = 1e9 + 7;

    ll hash = 0;
    ll p_pow = 1;

    for (char c : s) {
      hash = (hash + (c - 'a' + 1) * p_pow) % m;
      p_pow = (p_pow * p) % m;
    }

    return hash;
  };

  deb(computeHash("asdsdads"));
  deb(computeHash("asdsdads"));

  //  search for duplicate strings in an array of strings
  auto groupIdenticalStrings = [&computeHash](vector<string> const& s) {
    ll n = s.size();
    vpl hashes(n);

    fo(i, n) hashes[i] = {computeHash(s[i]), i};

    sort(all(hashes));

    vvl groups;
    fo(i, n) {
      if (i == 0 || hashes[i].first != hashes[i - 1].first)
        groups.eb();

      groups.back().push_back(hashes[i].second);
    }

    return groups;
  };

  vector<string> s{"abs", "abs", "sgsag", "sgsag", "wrqsfa", "wrqsfa", "qweqw", "wqrqwr", "wrqsfa", "wrqsfa", "wrqsfa", "wrqsfa"};

  auto grps = groupIdenticalStrings(s);

  tr(it, grps) {
    tr(it2, (*it)) {
      cout << *it2 << ' ';
    }

    cout << '\n';
  }

  auto countDistinctSubstrings = [](string const& s) {
    ll n = s.size();

    const ll p = 31;
    const ll m = 1e9 + 7;

    //  precompiuting powers
    vl p_pow(n);
    p_pow[0] = 1;
    Fo(i, 1, n) p_pow[i] = (p_pow[i - 1] * p) % m;

    //  prefix hashes
    vl hashes(n + 1);
    hashes[0] = 0;
    fo(i, n) hashes[i + 1] = (hashes[i] + (s[i] - 'a' + 1) * p_pow[i]) % m;

    ll cnt = 0;

    Fo(l, 1, n + 1) {
      set<ll> hashSet;

      fo(i, n - l + 1) {
        ll curr_hash = (hashes[i - 1] + m - hashes[i]) % m;
        curr_hash = (curr_hash * p_pow[n - i - 1]) % m;
        hashSet.insert(curr_hash);
      }

      cnt += hashSet.size();
    }

    return cnt;
  };

  cout << countDistinctSubstrings("agsdgreergewsgwsedsgeagewgeg");
}
