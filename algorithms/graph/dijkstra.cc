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
  freopen("output.txt", "w", stdout);
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
  //  dijkstra's algorithm is a SSSP algorithm for graphs with non-negative edge weights. The time complexity is typically O(E*log(V))

  //  ?algorithm
  /*
    Lazy Dijkstra
      Maintain a 'dist' array where the distance to every node is positive infinity. Mark the distance to the start node 's' to be 0.

      Maintain a PQ of of (nodeIndex, distance) pairs which tell us which node to visit next based on sorted min value.

      Insert (s, 0) into the PQ and loop while PQ is not empty pulling out the next most promising (nodeIndex, distance) pair.

      Iterate over all the edges outwards from the current node and relax each edge appending a new (nodeIndex, distance) key-value pair to the PQ for every relaxation.

      This is the lazy version of the algorithm which inserts duplicate key-value pairs (inserting: O(log(n)), updating: O(n)). The eager version of this uses indexed PQ(inserting: O(log(n)), updating: O(log(n))) which avoids duplicate key-value pairs
  */

  //  first is the node, second is the weight
  vector<vpl> adjList;  //	graph as adjency List

  //	building the graph
  adjList.emplace_back(vpl{{1, 4}, {4, 1}});
  adjList.emplace_back(vpl{{0, 1}, {2, 1}, {4, 6}});
  adjList.emplace_back(vpl{{1, 1}, {3, 1}});
  adjList.emplace_back(vpl{{2, 2}, {4, 1}});
  adjList.emplace_back(vpl{{0, 6}, {1, 0}, {3, 4}});
  adjList.emplace_back(vpl{});

  auto dijkstra = [](vector<vpl>& gr, ll start) {
    vector<bool> visited(gr.size(), false);
    vl dist(gr.size(), __LONG_LONG_MAX__);

    vl prev(gr.size(), -1);  //  this vector is used to calcultate the optimal path

    dist[start] = 0;

    priority_queue<pl, vector<pl>, greater<pl>> pq;
    pq.emplace(0, start);

    while (!pq.empty()) {
      ll minDist = pq.top().first;
      ll idx = pq.top().second;
      pq.pop();

      //  using visited so that each node is processed once
      visited[idx] = true;

      if (dist[idx] < minDist) continue;  //optimization, if we already have a minimum distance, we skip the below, which ignores the stale pairs in PQ

      tr(edge, gr[idx]) {
        if (visited[edge->first]) continue;
        ll newDist = dist[idx] + edge->second;

        if (newDist < dist[edge->first]) {
          prev[edge->first] = idx;
          dist[edge->first] = newDist;
          pq.emplace(newDist, edge->first);
        }
      }
    }

    return pair<vl, vl>{dist, prev};
  };

  auto findShortestPath = [&dijkstra](vector<vpl>& gr, ll start, ll end) {
    pair<vl, vl> res = dijkstra(gr, start);

    vl path;

    //  unreachable node
    if (res.first[end] == __LONG_LONG_MAX__) return path;

    while (res.second[end] != -1) {
      path.push_back(res.second[end]);
      end = res.second[end];
    }

    reverse(allC(path));

    return path;
  };

  auto x = findShortestPath(adjList, 2, 0);

  tr(it, x) deb(*it);
}
