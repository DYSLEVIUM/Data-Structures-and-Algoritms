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

const size_t MXN = 1e5;
ll n;

vector<int> lazy(4 * MXN);
vector<pair<int, int>> seg(4 * MXN);

pair<int, int> combine(pair<int, int> x, pair<int, int> y) {
  return {x.first + y.first, x.second + y.second};
}

void pushdown(ll lo, ll hi, ll id) {
  if (lazy[id] & 1) {
    seg[id] = {seg[id].second, seg[id].first};
    if (lo != hi) {
      lazy[id << 1] += lazy[id];
      lazy[id << 1 | 1] += lazy[id];
    }
  }
  lazy[id] = 0;
}

void build(int lo = 0, int hi = n - 1, int id = 1) {
  if (lo == hi) {
    seg[id] = {0, 1};
    return;
  }
  int mid = (lo + hi) / 2;
  build(lo, mid, id << 1);
  build(mid + 1, hi, id << 1 | 1);
  seg[id] = combine(seg[id << 1], seg[id << 1 | 1]);
}

void update(int l, int r, int lo = 0, int hi = n - 1, int id = 1) {
  pushdown(lo, hi, id);

  if (hi < l || lo > r) return;
  if (l <= lo && hi <= r) {
    seg[id] = {seg[id].second, seg[id].first};
    if (lo != hi) {
      lazy[id << 1]++;
      ;
      lazy[id << 1 | 1]++;
    }
    return;
  }

  int mid = (lo + hi) / 2;
  update(l, r, lo, mid, id << 1);
  update(l, r, mid + 1, hi, id << 1 | 1);
  seg[id] = combine(seg[id << 1], seg[id << 1 | 1]);
}

int query(int l, int r, int lo = 0, int hi = n - 1, int id = 1) {
  pushdown(lo, hi, id);
  if (hi < l || lo > r) return 0;
  if (l <= lo && hi <= r) {
    return seg[id].first;
  }

  int mid = (lo + hi) / 2;
  return query(l, r, lo, mid, id << 1) + query(l, r, mid + 1, hi, id << 1 | 1);
}

inline void solve() {
  ll q;
  cin >> n >> q;

  build();

  while (q--) {
    ll t, a, b;
    cin >> t >> a >> b;

    if (t) {
      cout << query(a, b) << '\n';
    } else {
      update(a, b);
    }
  }
}
