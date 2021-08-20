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

template <typename T>
class DSU {
 private:
  vector<T> rank;
  vector<T> parent;

 public:
  // store other info as required
  DSU(const size_t& n) {
    this->rank.resize(n);
    fill(all(this->rank), 0);

    this->parent.resize(n);
    iota(all(this->parent), 0);
  }

  T find(const T& node) {
    //  path compression
    return this->parent[node] = (this->parent[node] == node ? node : this->find(this->parent[node]));
  }

  void merge(T node1, T node2) {
    node1 = this->find(node1);
    node2 = this->find(node2);

    //  both the nodes are present in the same set
    if (node1 == node2) return;

    //  either of the node can be the parent, so rank will increase
    if (this->rank[node1] == this->rank[node2]) ++(this->rank[node1]);

    //  higher rank will be the parent (union by rank to reduce complexity)
    this->rank[node1] < this->rank[node2] ? this->parent[node1] = node2 : this->parent[node2] = node1;
  }
};

template <typename T>
class Node {
 public:
  T weight;
  T from;
  T to;

  Node(T u, T v, T wt) : from(u), to(v), weight(wt) {}
};

//  Kruskal's algorithm to find the MST
inline void solve() {
  ll totalNodes = 6;
  vector<Node<int>> graph;

  graph.eb(Node(1, 2, 2));
  graph.eb(Node(1, 4, 1));
  graph.eb(Node(1, 5, 4));
  graph.eb(Node(2, 3, 3));
  graph.eb(Node(2, 4, 3));
  graph.eb(Node(2, 6, 7));
  graph.eb(Node(3, 6, 8));
  graph.eb(Node(4, 3, 5));
  graph.eb(Node(4, 5, 9));

  //  sorting so that we can greedily choose the shortest edge
  sort(all(graph), [](const Node<int>& a, const Node<int>& b) {
    return a.weight < b.weight;
  });

  DSU<int> d(totalNodes + 1);

  // tr(it, graph) cout << it->from << "->" << it->to << "=>" << it->weight << '\n';

  vpl mst;
  ll totalCost = 0;

  tr(it, graph) {
    //  if they both don't belong to the same component then we can add them so as to not form a cycle
    if (d.find(it->from) != d.find(it->to)) {
      totalCost += it->weight;
      mst.eb(it->from, it->to);
      d.merge(it->from, it->to);
    }
  }

  sort(all(mst));  //  just for display purpose

  cout << "MST with cost " << totalCost << '\n';
  for (auto& [u, v] : mst) cout << u << " -> " << v << '\n';
}
