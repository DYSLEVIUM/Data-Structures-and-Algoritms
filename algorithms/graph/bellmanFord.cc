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
  //  Bellman Ford Algorithm is a SSSP algorithm. It means that it can find the shortest path from one node to any other node.

  //  Time Complexity is O(EV). It is better to use Dijkstra's algorithm which is much faster which is O((E+V)log(V)) when using a binary heap priority queue.

  //  Bellman Ford is used over Dijkstra's algorithm when the edge weights are negative in which Dijkstra's algorithm doesn't work as it is greedy and it will be stuck in an infinite loop as it will be finding better and better paths.

  //  Bellman Ford can detect negative cycles(cycles where the net weight is negative) and determine where they occur. Negative cycles arises in many scenarios. One of the scenarios is when performing an arbitrage between two or more markets.

  //  first is the node, second is the weight
  vector<vpl> adjList;  //	graph as adjency List

  //	building the graph
  adjList.emplace_back(vpl{{1, 5}});
  adjList.emplace_back(vpl{{2, 20}, {5, 30}, {6, 60}});
  adjList.emplace_back(vpl{{3, 10}, {4, 75}});
  adjList.emplace_back(vpl{{2, -15}});
  adjList.emplace_back(vpl{{9, 100}});
  adjList.emplace_back(vpl{{8, 50}, {6, 5}, {4, 25}});
  adjList.emplace_back(vpl{{7, -50}});
  adjList.emplace_back(vpl{{8, -10}});
  adjList.emplace_back(vpl{});
  adjList.emplace_back(vpl{});

  auto bellmanFord = [](const vector<vpl>& gr, const ll& start) {
    //  initially the nodes can't be reached
    vl dist(gr.size(), __LONG_LONG_MAX__);
    dist[start] = 0;

    //  for each vertex, apply relaxation for all the edges
    //  we relax for all the edges and assume there is no cycle, i.e., v - 1 edges
    fo(i, gr.size() - 1) {
      tr(edge, gr[i]) {
        if (dist[i] + edge->second < dist[edge->first]) dist[edge->first] = dist[i] + edge->second;
      }
    }

    //  run the algorithm a second time to detect which nodes are part of a negative cycle. A negative cycle has occurred if we can find a better path beyond the optimal solution
    fo(i, gr.size() - 1) {
      tr(edge, gr[i]) {
        if (dist[i] + edge->second < dist[edge->first]) dist[edge->first] = __LONG_LONG_MAX__ + 1;
      }
    }

    return dist;
  };

  auto aa = bellmanFord(adjList, 0);

  tr(it, aa) deb(*it);
}
