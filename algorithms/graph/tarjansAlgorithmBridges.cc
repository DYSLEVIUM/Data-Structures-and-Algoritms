#pragma GCC optimize("Ofast,fast-math,unroll-loops")
#ifdef DYSLEVIUM
#include "dyslevium.h"
#else
#include <bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#endif

typedef long long ll;
typedef long double ld;
typedef std::pair<ll, ll> pl;
typedef std::vector<ll> vl;
typedef std::vector<pl> vpl;
typedef std::vector<vl> vvl;
typedef std::unordered_map<ll, ll> mll;
typedef std::priority_queue<ll> pqd;
typedef std::priority_queue<ll, vl, std::greater<ll>> pqi;

// clang-format off
#define pb push_back
#define eb emplace_back
#define F first
#define S second
#define MOD (ll)(1e9 + 7)

std::mt19937_64 RNG(std::chrono::high_resolution_clock::now().time_since_epoch().count());  // generator for shuffle and other generator which require random numbers

// macro functions
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

// template functions
template <typename T>using ordered_set = __gnu_pbds::tree<T, __gnu_pbds::null_type, std::less<T>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update>;  // find_by_order, order_of_key
template <typename T>inline T gcd(const T& a, const T& b) {if (b) return gcd(b, a % b);return a;}
template <typename T>inline T binPow(T x, T n) {T res = 1;while (n) {if (n & 1) res *= x;x *= x;n >>= 1;}return res;}
template <typename T>inline T binPowM(T x, T n) {T res = 1;while (n) {if (n & 1) res = modMul(res, x);x = modMul(x, x);n >>= 1;}return res % MOD;}
template <typename T>inline T modInverse(const T& a) {return binPowIter(a, MOD - 2);}
template <typename T>inline T modDiv(const T& a, const T& b) {return (modMul(a, modInverse(b)) + MOD) % MOD;}

// debuging
#ifdef DYSLEVIUM
#define deb(x) std::cerr << #x << " = " << x << '\n'
#else
#define deb(x)
#endif

// initial setup
inline void setup() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

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

// Compile and run: g++ -std=c++17 -g -Wshadow -Wall main.cc -D DYSLEVIUM -o a.exe -Ofast -Wno-unused-result && ./a.exe

// clang-format on

inline void solve() {
  //  a bridge is an edge, removing which increases the number of components

  //  tarjan's algorithm to find bridges in a graph O(V+E)

  //  if there is no back edge from a subgraph to a nodes ancestor or parent (across the edge being checked) then the edge will be a bridge, here we don't consider child to parent edge as we assume this to be removed

  const ll N = 5;

  vvl adj(N);

  adj[0].pb(2);
  adj[2].pb(0);
  adj[0].pb(3);
  adj[3].pb(0);
  adj[1].pb(0);
  adj[0].pb(1);
  adj[2].pb(1);
  adj[1].pb(2);
  adj[3].pb(4);
  adj[4].pb(3);

  vpl bridges;

  auto find_bridges_tarjan = [&bridges, &N](const vvl& gr) {
    vl disc(N, -1);  //  -1 represents node not visited
    vl low_link(N);
    vl parent(N, -1);  //  -1 represents no parent

    ll time = 0;

    auto dfs = [&](const auto& dfs, const ll& u) -> void {
      disc[u] = low_link[u] = time++;

      for (auto v : gr[u]) {
        if (disc[v] == -1) {  //  if node is not visited
          parent[v] = u;
          dfs(dfs, v);
          low_link[u] = min(low_link[u], low_link[v]);

          if (low_link[v] > disc[u]) bridges.pb({u, v});
        }
        //  ignore the child to parent edge
        else if (v != parent[u])
          low_link[u] = min(low_link[u], disc[v]);
      }
    };

    fo(i, N) if (disc[i] == -1) dfs(dfs, i);
  };

  find_bridges_tarjan(adj);

  cout << "Bridges are: \n";

  for (auto [u, v] : bridges) cout << u << " -> " << v << '\n';
}
