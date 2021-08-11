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
#define MOD (ll)(1e9 + 7)

#define fo(i, n) for (ll i = 0; i < (ll)n; ++i)
#define Fo(i, k, n) for (ll i = k; k < (ll)n ? i < (ll)n : i > (ll)n; k < (ll)n ? ++i : --i)
#define all(x) x.begin(), x.end()
#define tr(it, a) for (auto it = a.begin(); it != a.end(); ++it)
#define ps(x, y) std::fixed << std::setprecision(y) << x
#define setbits(x) __builtin_popcountll(x)
#define zerobits(x) __builtin_ctzll(x)

std::mt19937_64 rng(std::chrono::high_resolution_clock::now().time_since_epoch().count());

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

  ll t = 1;
  // std::cin >> t;

  while (t--)
    solve();

  return 0;
}

using namespace std;

//  Compile and run: g++ -std=c++17 -g -Wshadow -Wall main.cc -D DYSLEVIUM -o a -Ofast -Wno-unused-result && ./a

inline void solve() {
  vvl adjList1;  //  graph as adjency list

  //	building the cyclic graph
  adjList1.emplace_back(vl{1, 2});
  adjList1.emplace_back(vl{2});
  adjList1.emplace_back(vl{3, 0});
  adjList1.emplace_back(vl{3});

  vvl adjList2;  //  graph as adjency list

  //	building the cyclic graph
  adjList2.emplace_back(vl{1, 2});
  adjList2.emplace_back(vl{2});
  adjList2.emplace_back(vl{3});
  adjList2.emplace_back(vl{});

  auto isCyclic = [](const vvl& gr) {
    vector<bool> visited(gr.size(), false);
    vector<bool> reStack(gr.size(), false);

    auto dfs = [&gr, &visited, &reStack](const ll& vertex, const auto& dfs) -> bool {
      if (visited[vertex]) {
        reStack[vertex] = false;
      } else {
        visited[vertex] = true;
        reStack[vertex] = true;

        fo(i, gr[vertex].size()) {
          if (!visited[gr[vertex][i]] && dfs(i, dfs))
            return true;
          else if (reStack[gr[vertex][i]])
            return true;
        }
      }
      return false;
    };

    fo(i, gr.size()) {
      if (dfs(i, dfs)) return true;
    }

    return false;
  };

  cout << isCyclic(adjList1) << '\n';
  cout << isCyclic(adjList2) << '\n';
}
