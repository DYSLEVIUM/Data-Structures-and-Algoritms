#define _USE_MATH_DEFINES
#pragma GCC optimize("Ofast,fast-math,unroll-loops")

#include <algorithm>
#include <bitset>
#include <chrono>
#include <cmath>
#include <cstring>
#include <ctime>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

typedef long long ll;
typedef long double ld;
typedef std::pair<int, int> pii;
typedef std::pair<long, long> pl;
typedef std::vector<int> vi;
typedef std::vector<ll> vl;
typedef std::vector<pii> vpii;
typedef std::vector<pl> vpl;
typedef std::vector<vi> vvi;
typedef std::vector<vl> vvl;
typedef std::map<int, int> mii;
typedef std::priority_queue<int> pqd;
typedef std::priority_queue<int, vi, std::greater<int>> pqi;

#define pb push_back
#define eb emplace_back
#define F first
#define S second
#define MOD (long long)(1e9 + 7)
#define PI 3.14159265358979323846
#define INF __builtin_inff()

#define fo(i, n) for (ll i = 0; i < n; ++i)
#define Fo(i, k, n) for (ll i = k; k < n ? i < n : i > n; k < n ? ++i : --i)
#define allC(x) x.begin(), x.end()
#define clr(x) memset(x, 0, sizeof(x))
#define deb(x) std::cout << '\n' \
                         << #x << " = " << x << '\n'
#define sortall(x) sort(x.begin(), x.end())
#define tr(it, a) for (auto it = a.begin(); it != a.end(); ++it)
#define ps(x, y) std::fixed << std::setprecision(y) << x
#define setbits(x) __builtin_popcountll(x)
#define zerobits(x) __builtin_ctzll(x)
#define mk(arr, n, type) type* arr = new type[n]

std::mt19937_64 rng(
    std::chrono::high_resolution_clock::now().time_since_epoch().count());

inline void setup() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(NULL);
  std::cout.tie(NULL);

#ifdef LOCAL_PROJECT  // run with -DLOCAL_PROJECT during compilation
  freopen("input.txt", "r", stdin);
  // freopen("output.txt", "w", stdout);
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
//  Compile and run: g++ -g -Wshadow -Wall practice.cpp -DLOCAL_PROJECT -o a -Ofast -Wno-unused-result && ./a

inline void solve() {
  vvl adjList;  //	graph as adjency List

  //	building the graph
  adjList.emplace_back(vi{1, 4});
  adjList.emplace_back(vi{0, 2, 4});
  adjList.emplace_back(vi{1, 3});
  adjList.emplace_back(vi{2, 4});
  adjList.emplace_back(vi{0, 1, 3});
  adjList.emplace_back(vi{});

  auto topSort = [](vvl& graph) {
    ll n = graph.size();             //  number of nodes
    vector<bool> visited(n, false);  //  all nodes are initially not visited
    vl ordering(n, -1);

    ll i = n - 1;  //  index of ordering array

    auto dfs = [](ll at, vector<bool>& visited, vl& ordering, ll& i, vvl& graph, auto&& dfs) -> void {
      visited[at] = true;

      vl edges = graph[at];

      tr(edge, edges) {
        if (!visited[*edge]) {
          dfs(*edge, visited, ordering, i, graph, dfs);
        }
      }
      ordering[i--] = at;
    };

    fo(j, n) {
      if (!visited[j]) {
        dfs(j, visited, ordering, i, graph, dfs);
      }
    }

    return ordering;
  };

  //  the Single Source Shortest Path (SSSP) problem can be solved efficiently on a DAG in O(V+E) time. This is due to the fact that the nodes can be ordered in a topological ordering and processed sequentially

  //  initially the distances are infinite, and at each iteration we compute the minimum distance to that node and if we get a minimum, we replace it

  auto sssp = [&topSort](auto gr, ll start) {
    auto topSortSequence = topSort(gr);

    vl dist(topSortSequence.size(), __LONG_LONG_MAX__);  //  distance vector to keep the distance from start node to current node and initializing it with infinity

    dist[start] = 0;

    fo(i, topSortSequence.size()) {
      ll nodeIndex = topSortSequence[i];

      //  this condition is necessary so that we start from the startNode
      if (dist[nodeIndex] != __LONG_LONG_MAX__) {
        vl adjEdges = gr[nodeIndex];

        if (!adjEdges.empty()) {
          tr(edge, adjEdges) {
            ll newDist = dist[nodeIndex] + edge->weight;

            dist[edge->to] = min(dist[edge->to], newDist);
          }
        }
      }
    }

    return dist;
  };

  //  similar to the SSSP we can compute the Longest Path on DAG in O(V+E) by negating each edge's weight, then find the shortest path and negate the result
}
