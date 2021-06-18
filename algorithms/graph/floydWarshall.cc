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
#define all(x) x.begin(), x.end()
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
  //  the Floyd-Warshall algorithm is an All-Pairs Shortest Path (APSP) algorithm. This means it can find the shortest path between all pairs of nodes. The time complexity to run FW is O(V^2)

  //  here 1e9+7 is infinity

  //  graph as adjency matrix
  vvl adjMat(7, vl(7, (1e9 + 7)));

  fo(i, adjMat.size()) {
    fo(j, adjMat.size()) {
      //  distance from the node to itself is 0
      if (i == j) adjMat[i][j] = 0;
    }
  }

  adjMat[0][1] = 2;
  adjMat[0][2] = 5;
  adjMat[0][6] = 10;
  adjMat[1][2] = 2;
  adjMat[1][4] = 11;
  adjMat[2][6] = 2;
  adjMat[6][5] = 11;
  adjMat[4][5] = 1;
  adjMat[5][4] = 2;

  //  this table will contain the APSP solution
  vvl dp(adjMat.size(), vl(adjMat.size()));

  //  this matrix is used to reconstruct the shortest path and is intially unreachable
  vvl next(adjMat.size(), vl(adjMat.size(), (1e9 + 7)));

  //  doing a deep copy of the input matrix and setup the next matrix for path reconstruction
  fo(i, adjMat.size()) {
    fo(j, adjMat.size()) {
      dp[i][j] = adjMat[i][j];

      //  if there is edge between node i and j, go to j by default
      if (adjMat[i][j] != (1e9 + 7)) {
        next[i][j] = j;
      }
    }
  }

  bool haveSolved = false;

  auto floydWarshall = [&haveSolved, &dp, &adjMat, &next]() {
    if (haveSolved) return;

    //  execute FW all pairs shortest path algorithm
    fo(k, adjMat.size()) {
      fo(i, adjMat.size()) {
        fo(j, adjMat.size()) {
          //  if better path from i->k->j exists then change
          if (dp[i][k] + dp[k][j] < dp[i][j]) {
            dp[i][j] = dp[i][k] + dp[k][j];
            next[i][j] = next[i][k];
          }
        }
      }
    }

    //  detect and propagate negative cycles
    //  to detect negative cycle, re-run the FW algorithm, and if we find a better path yet again, that is a negative cycle
    fo(k, adjMat.size()) {
      fo(i, adjMat.size()) {
        fo(j, adjMat.size()) {
          //  if better path from i->k->j exists it means there is negative cycle
          if (dp[i][k] + dp[k][j] < dp[i][j]) {
            //  shortest path is -infinity
            dp[i][j] = -(1e9 + 7);
            next[i][j] = -1;
          }
        }
      }
    }

    haveSolved = true;
  };

  floydWarshall();

  auto reconstructPath = [&haveSolved, &floydWarshall, &dp, &next](ll start, ll end, bool& hasNegativeCycle) {
    if (!haveSolved) floydWarshall();
    vl path;

    //  if the node can't be reached, then it is infinity
    if (dp[start][end] == (1e9 + 7)) return path;

    while (start != end) {
      //  negative cycle

      if (start == -1) {
        hasNegativeCycle = true;
        return vl(0);
      }

      path.eb(start);
      start = next[start][end];
    }

    //  checking if last node has a negative cycle
    if (next[start][end] == -1) {
      hasNegativeCycle = true;
      return vl(0);
    }

    path.eb(end);

    return path;
  };

  //  reconstructing all paths
  fo(i, adjMat.size()) {
    fo(j, adjMat.size()) {
      bool hasNegativeCycle = false;

      auto path = reconstructPath(i, j, hasNegativeCycle);

      string str;

      if (hasNegativeCycle) {
        //  alt+236 on the numpad gives infinity 🤷‍♂️
        str = "HAS AN ∞ NUMBER of SOLUTIONS! (negative cycle case)";
      } else if (path.empty()) {
        str = "DOES NOT EXIST!";
      } else {
        tr(it, path) {
          str += to_string(*it) + " -> ";
        }

        //  removing the last arrow
        str.pop_back();
        str.pop_back();
        str.pop_back();
        str.pop_back();

        str = "is: [" + str + "]";
      }

      cout << "The shortest path from node " << i << " to " << j << " " << str << '\n';
    }
  }
}
