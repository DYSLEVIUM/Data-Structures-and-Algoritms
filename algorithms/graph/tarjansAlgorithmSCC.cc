#pragma GCC optimize("Ofast,fast-math,unroll-loops")
#ifdef DYSLEVIUM
#include "dyslevium.h"
#else
#include <bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#endif

typedef long long ll;
typedef long double ld;
typedef std::pair<ll, ll> pl;
typedef std::vector<ll> vl;
typedef std::vector<pl> vpl;
typedef std::vector<vl> vvl;
typedef std::unordered_map<ll, ll> mll;
typedef std::priority_queue<ll> pqd;
typedef std::priority_queue<ll, vl, std::greater<ll>> pqi;

// clang-format off
#define pb push_back
#define eb emplace_back
#define F first
#define S second
#define MOD (ll)(1e9 + 7)

std::mt19937_64 RNG(std::chrono::high_resolution_clock::now().time_since_epoch().count());  // generator for shuffle and other generator which require random numbers

// macro functions
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

// template functions
template <typename T>using ordered_set = __gnu_pbds::tree<T, __gnu_pbds::null_type, std::less<T>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update>;  // find_by_order, order_of_key
template <typename T>inline T gcd(const T& a, const T& b) {if (b) return gcd(b, a % b);return a;}
template <typename T>inline T binPow(T x, T n) {T res = 1;while (n) {if (n & 1) res *= x;x *= x;n >>= 1;}return res;}
template <typename T>inline T binPowM(T x, T n) {T res = 1;while (n) {if (n & 1) res = modMul(res, x);x = modMul(x, x);n >>= 1;}return res % MOD;}
template <typename T>inline T modInverse(const T& a) {return binPowIter(a, MOD - 2);}
template <typename T>inline T modDiv(const T& a, const T& b) {return (modMul(a, modInverse(b)) + MOD) % MOD;}

// debuging
#ifdef DYSLEVIUM
#define deb(x) std::cerr << #x << " = " << x << '\n'
#else
#define deb(x)
#endif

// initial setup
inline void setup() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

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

// Compile and run: g++ -std=c++17 -g -Wshadow -Wall main.cc -D DYSLEVIUM -o a.exe -Ofast -Wno-unused-result && ./a.exe

// clang-format on

inline void solve() {
  //  tarjan's algorithm to find Strongly Connected Components O(V+E)

  /*
    Types of edges:
      1. Tree Edge: (U, V) => U is parent and V is child
      2. Forward Edge: (U, V) => U is ancestor and V is descendent
      3. Back Edge: (U, V) => U is the descendant and V is the ancestor
      4. Cross Edge: (U, V) => U and V don't have ancestor-descendant relationship
  */

  //  we will have a tuple for every node, where first will be discovery time and the second will be low-link time

  //  the low_link time will be the lowest time that can be reached from that node's low-link

  //  if low_link[u] = disc[u], that node will be the head node

  // if on DFS call we reach a back-edge, that means there is a cycle in that component and hence will be part of a SCC, low_link[u] = min(low_link[u], disc[v])

  //  if on DFS call we reach a cross-edge, we do nothing

  //  else low_link[u] = min(low_link[u], low_link[v])

  /*
    differentiate between back-edge and cross-edge:
    • stack is required to keep track of nodes present in SCC
    • is edge is pointing to a visited node already in stack, then it is a back edge else it is a cross edge
  */

  //  TLDR; if SCC is formed as a node then the graph will always be a DAG

  // why cross-edge is not considered for SCC ? ; consider two SCCs, and a cross-edge from SCC2 to SCC1, where SCC1 is already visited and SCC2 is being visited; so if there are two cross edge, i.e., (SCC1, SCC2) and (SCC2, SCC1) edges exist, then there will be a cycle and both of them will be present in the same SCC, hence only one SCC is possible which is a contradiction that we have two SCCs, so only one edge is possible between SCC1 and SCC2 which means we cannot go from each node in SCC1 to each node in SCC2;

  const ll N = 7;

  vvl adj(N);

  adj[0].pb(1);
  adj[1].pb(2);
  adj[1].pb(3);
  adj[3].pb(4);
  adj[4].pb(0);
  adj[4].pb(5);
  adj[4].pb(6);
  adj[5].pb(6);
  adj[6].pb(5);

  vvl SCC;

  auto find_SCC_tarjan = [&SCC](vvl gr) {
    vl disc(N, -1);  //  -1 represents not visited
    vl low_link(N);

    vector<bool> present_in_stack(N, false);

    stack<ll> st;

    ll time = 0;

    auto dfs = [&](const auto& dfs, const ll u) -> void {
      disc[u] = low_link[u] = time;
      ++time;
      st.push(u);
      present_in_stack[u] = true;

      for (auto v : gr[u]) {
        if (disc[v] == -1) {  //  if v is not visited
          dfs(dfs, v);
          low_link[u] = min(low_link[u], low_link[v]);
        }
        //  differentiate between back-edge and cross-edge
        else if (present_in_stack[v])  //  back-edge
          low_link[u] = min(low_link[u], disc[v]);

        //  nothing to do for cross-edge
      }

      //  if u is head node of SCC
      if (low_link[u] == disc[u]) {
        vl current_SCC;

        while (st.top() != u) {
          current_SCC.pb(st.top());
          present_in_stack[st.top()] = false;
          st.pop();
        }

        current_SCC.pb(st.top());
        present_in_stack[st.top()];
        st.pop();

        SCC.pb(current_SCC);
      }
    };

    fo(i, N) if (disc[i] == -1) dfs(dfs, i);
  };

  find_SCC_tarjan(adj);

  fo(i, SCC.size()) {
    cout << "SCC " << i + 1 << ": ";
    fo(j, SCC[i].size()) cout << SCC[i][j] << ' ';
    cout << '\n';
  }
}
