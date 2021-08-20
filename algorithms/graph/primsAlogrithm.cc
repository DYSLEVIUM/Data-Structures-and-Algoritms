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

inline void solve() {
  //  a tree with n nodes and n-1 edges; every node should be reachable from every other node; and has the minimum total weight associated with it is called an Minimum Spanning Tree (MST) (the graph has to be a weighted graph)

  //  brute force implementation
  vector<vpl> adjList;

  //  graph with first as node and second as edge weight
  adjList.eb(vpl{pl{1, 2}, pl{3, 6}});
  adjList.eb(vpl{pl{0, 2}, pl{2, 3}, pl{3, 8}, pl{4, 5}});
  adjList.eb(vpl{pl{1, 3}, pl{4, 7}});
  adjList.eb(vpl{pl{0, 6}, pl{1, 8}});
  adjList.eb(vpl{pl{1, 5}, pl{2, 7}});

  vl parent(adjList.size(), -1);
  vl key(adjList.size(), LONG_LONG_MAX);
  vl mstSet(adjList.size(), false);

  //  we take node 0 always
  key[0] = 0;
  parent[0] = -1;

  ll nodes = adjList.size() - 1;  //  n-1 nodes

  while (nodes--) {
    ll mini = LONG_LONG_MAX;
    ll u;

    fo(v, adjList.size()) {
      if (mstSet[v] == false && key[v] < mini) {  //  if not a part of MST and is the node with the least value
        mini = key[v];
        u = v;
      }
    }

    //  marking that node as part of the mst set
    mstSet[u] = true;

    for (auto neighbour : adjList[u]) {
      ll v = neighbour.F;
      ll weight = neighbour.S;

      if (mstSet[v] == false && weight < key[v]) {  //  if node v is not part of the MST and the weight associated is less
        parent[v] = u;
        key[v] = weight;
      }
    }
  }

  Fo(i, 1, adjList.size()) cout << parent[i] << " -> " << i << " \n";

  cout << '\n';

  //  reset
  fill(all(parent), -1);
  fill(all(key), LONG_LONG_MAX);
  fill(all(mstSet), false);

  nodes = adjList.size() - 1;  //  n-1 nodes

  //  efficient algorithm

  priority_queue<pl, vpl, greater<pl>> minHeap;

  //  we take node 0 always
  key[0] = 0;
  parent[0] = -1;
  minHeap.push({0, 0});

  while (nodes--) {
    ll u = minHeap.top().S;
    minHeap.pop();

    //  marking that node as part of the mst set
    mstSet[u] = true;

    for (auto neighbour : adjList[u]) {
      ll v = neighbour.F;
      ll weight = neighbour.S;

      if (mstSet[v] == false && weight < key[v]) {  //  if node v is not part of the MST and the weight associated is less
        parent[v] = u;
        key[v] = weight;
        minHeap.push({key[v], v});
      }
    }
  }

  Fo(i, 1, adjList.size()) cout << parent[i] << " -> " << i << " \n";
}
