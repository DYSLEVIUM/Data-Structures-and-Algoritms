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

//  Kosaraju's Algorithm to find strongly connected components
inline void solve() {
  //  get the topological order
  //  transpose the graph so that the connected components are stuck inside a cycle and can't go outside the connected componnet
  //  apply dfs on the topological ordering

  vvl adjL;
  adjL.eb(vl{1});
  adjL.eb(vl{2, 3});
  adjL.eb(vl{0});
  adjL.eb(vl{4});
  adjL.eb(vl{});

  auto topologicalSort = [](const vvl& gr) {
    vector<bool> visited(gr.size(), false);
    vl order;

    auto dfs = [&visited, &order, &gr](const ll& node, const auto& dfs) -> void {
      visited[node] = true;

      for (auto neighbour : gr[node]) {
        if (!visited[node]) dfs(neighbour, dfs);
      }

      order.eb(node);
    };

    fo(i, gr.size()) {
      if (!visited[i]) dfs(i, dfs);
    }

    reverse(all(order));

    return order;
  };

  vl topologicalOrder = topologicalSort(adjL);

  reverse(all(topologicalOrder));

  //  transpose the graph
  vvl transpose(adjL.size());

  fo(i, adjL.size()) {
    fo(j, adjL[i].size()) {
      transpose[adjL[i][j]].eb(i);
    }
  }

  //  dfs on the topological ordering on the transpose of the graph
  vector<bool> visited(transpose.size(), false);

  vvl ans;
  auto dfs = [&visited, &transpose, &ans](const ll& node, vl& scc, const auto& dfs) -> void {
    visited[node] = true;

    scc.eb(node);

    for (auto neighbour : transpose[node]) {
      if (!visited[neighbour]) {
        dfs(neighbour, scc, dfs);
      }
    }
  };

  fo(i, topologicalOrder.size()) {
    if (!visited[topologicalOrder[i]]) {
      vl scc;
      dfs(topologicalOrder[i], scc, dfs);
      ans.eb(scc);
    }
  }

  cout << "Strongly Connected Components: " << ans.size() << '\n';

  fo(i, ans.size()) {
    fo(j, ans[i].size()) {
      cout << ans[i][j] << ' ';
    }
    cout << '\n';
  }
}
