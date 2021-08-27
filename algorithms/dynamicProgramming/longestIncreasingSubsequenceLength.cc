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
  //  Time : O(n^2)
  //  Space : O(n)
  vl arr{5, 8, 7, 1, 9};

  vl lis(arr.size());

  //  initializing to 1 as every element is itself a increasing subsequence of length 1
  fo(i, arr.size()) lis[i] = 1;

  Fo(i, 1, arr.size()) {
    fo(j, i) {
      if (arr[i] > arr[j] && lis[i] < lis[j] + 1) {
        lis[i] = lis[j] + 1;
      }
    }
  }

  ll ans = -__LONG_LONG_MAX__;
  fo(i, arr.size()) ans = max(ans, lis[i]);

  cout << ans << '\n';
  
  //  ---------------------------------------------------------------------------
  //  adding at least one element in array
  //  Time : O(n*log n)
  //  Space : O(n)
  lisArr.eb(arr[0]);

  Fo(i, 1, arr.size()) {
    if (lisArr.back() < arr[i])
      lisArr.eb(arr[i]);
    else {
      ll idx = lower_bound(all(lisArr), arr[i]) - lisArr.begin();

      //  updating the lisArray to update it with smallest element so that we increase the probability of getting a better length
      lisArr[idx] = arr[i];
    }
  }

  cout << lisArr.size();
}
