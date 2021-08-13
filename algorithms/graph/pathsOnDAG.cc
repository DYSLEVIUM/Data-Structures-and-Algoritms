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

// inline void solve1() {
//   vvl adjList;  //	graph as adjency List

//   //	building the graph
//   adjList.emplace_back(vl{1, 4});
//   adjList.emplace_back(vl{0, 2, 4});
//   adjList.emplace_back(vl{1, 3});
//   adjList.emplace_back(vl{2, 4});
//   adjList.emplace_back(vl{0, 1, 3});
//   adjList.emplace_back(vl{});

//   auto topSort = [](vvl& graph) {
//     ll n = graph.size();             //  number of nodes
//     vector<bool> visited(n, false);  //  all nodes are initially not visited
//     vl ordering(n, -1);

//     ll i = n - 1;  //  index of ordering array

//     auto dfs = [](ll at, vector<bool>& visited, vl& ordering, ll& i, vvl& graph, auto&& dfs) -> void {
//       visited[at] = true;

//       vl edges = graph[at];

//       tr(edge, edges) {
//         if (!visited[*edge]) {
//           dfs(*edge, visited, ordering, i, graph, dfs);
//         }
//       }
//       ordering[i--] = at;
//     };

//     fo(j, n) {
//       if (!visited[j]) {
//         dfs(j, visited, ordering, i, graph, dfs);
//       }
//     }

//     return ordering;
//   };

//   //  the Single Source Shortest Path (SSSP) problem can be solved efficiently on a DAG in O(V+E) time. This is due to the fact that the nodes can be ordered in a topological ordering and processed sequentially

//   //  initially the distances are infinite, and at each iteration we compute the minimum distance to that node and if we get a minimum, we replace it

//   auto sssp = [&topSort](auto gr, ll start) {
//     auto topSortSequence = topSort(gr);

//     vl dist(topSortSequence.size(), __LONG_LONG_MAX__);  //  distance vector to keep the distance from start node to current node and initializing it with infinity

//     dist[start] = 0;

//     fo(i, topSortSequence.size()) {
//       ll nodeIndex = topSortSequence[i];

//       //  this condition is necessary so that we start from the startNode
//       if (dist[nodeIndex] != __LONG_LONG_MAX__) {
//         vl adjEdges = gr[nodeIndex];

//         if (!adjEdges.empty()) {
//           tr(edge, adjEdges) {
//             ll newDist = dist[nodeIndex] + edge->weight;

//             dist[edge->to] = min(dist[edge->to], newDist);
//           }
//         }
//       }
//     }

//     return dist;
//   };

//   auto path = sssp(adjList, 0);

//   //  similar to the SSSP we can compute the Longest Path on DAG in O(V+E) by negating each edge's weight, then find the shortest path and negate the result
// }

inline void solve() {
  vector<vpl> adjList;

  //  graph with first as node and second as edge weight
  adjList.eb(vpl{pl{1, 2}, pl{4, 1}});
  adjList.eb(vpl{pl{2, 3}});
  adjList.eb(vpl{pl{3, 6}});
  adjList.eb(vpl{});
  adjList.eb(vpl{pl{2, 2}, pl{5, 4}});
  adjList.eb(vpl{pl{3, 1}});

  auto sssp = [](const vector<vpl>& gr, const ll& stNode, const ll& endNode) {
    auto topSortSequence = [&gr]() {
      vector<bool> visited(gr.size(), false);
      vl ordering;

      auto dfs = [&gr, &visited, &ordering](const ll& node, const auto& dfs) -> void {
        visited[node] = true;

        for (auto neighbour : gr[node]) {
          if (!visited[neighbour.first]) dfs(neighbour.first, dfs);
        }

        ordering.eb(node);
      };

      fo(i, gr.size()) {
        if (!visited[i]) dfs(i, dfs);
      }

      reverse(all(ordering));

      return ordering;
    }();

    vl dist(gr.size(), LONG_LONG_MAX);  //  infinite distance

    dist[stNode] = 0;  //  starting node

    fo(i, topSortSequence.size()) {
      ll node = topSortSequence[i];

      if (dist[node] != LONG_LONG_MAX) {
        for (auto neighbour : gr[node]) {
          dist[neighbour.first] = min(dist[neighbour.first], dist[node] + neighbour.second);  //  minimum of previous distance and previous + this node
        }
      }
    }

    return dist[endNode];
  };

  cout << sssp(adjList, 0, 1) << '\n';
}
