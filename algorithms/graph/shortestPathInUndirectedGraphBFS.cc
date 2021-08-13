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
  std::cerr << "Time: " << duration.count();
#endif

  return 0;
}

using namespace std;

//  Compile and run: g++ -std=c++17 -g -Wshadow -Wall main.cc -D DYSLEVIUM -o a -Ofast -Wno-unused-result && ./a

inline void solve() {
  vvl adjList;  //  graph as adjency list

  //	building the cyclic graph
  adjList.emplace_back(vl{1, 3});
  adjList.emplace_back(vl{0, 2, 3});
  adjList.emplace_back(vl{1, 6});
  adjList.emplace_back(vl{0, 4});
  adjList.emplace_back(vl{3, 5});
  adjList.emplace_back(vl{4, 6});
  adjList.emplace_back(vl{2, 5, 7, 8});
  adjList.emplace_back(vl{6, 8});
  adjList.emplace_back(vl{6, 7});

  auto findShortestPath = [](const vvl& gr, const ll& stNode, const ll& endNode) {
    vl prev = [](const vvl& gr, const ll& stNode) {
      vector<bool> visited(gr.size(), false);

      queue<ll> qu;
      qu.push(stNode);

      visited[stNode] = true;

      vl prev(gr.size(), -1);

      while (!qu.empty()) {
        ll node = qu.front();
        qu.pop();

        for (auto neighbour : gr[node]) {
          if (!visited[neighbour]) {
            visited[neighbour] = true;
            prev[neighbour] = node;
            qu.push(neighbour);
          }
        }
      }

      return prev;
    }(gr, stNode);  //  get previous of every Node

    return [&prev](const vvl& gr, const ll& stNode, const ll& endNode) {
      vl path;

      ll currNode = endNode;

      while (currNode != prev[stNode]) {
        path.eb(currNode);
        if (prev[currNode] == -1) break;
        currNode = prev[currNode];
      }

      reverse(all(path));  //  stack can be used, so as to not reverse

      if (path[0] == stNode) return path;
      return vl(0);
    }(gr, stNode, endNode);  //  reconstruct path
  };

  auto path = findShortestPath(adjList, 0, 5);

  for (auto x : path) cout << x << "->";
}
