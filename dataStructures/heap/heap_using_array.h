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
#define PI 3.14159265358979323846

std::mt19937_64 RNG(std::chrono::high_resolution_clock::now().time_since_epoch().count());  // generator for shuffle and other generator which require random numbers

// macro functions
#define fo(i, n) for (ll i = 0; i < (ll)n; ++i)
#define Fo(i, k, n) for (ll i = k; k < (ll)n ? i < (ll)n : i > (ll)n; k < (ll)n ? ++i : --i)
#define all(x) x.begin(), x.end()
#define tr(it, a) for (auto it = a.begin(); it != a.end(); ++it)
#define ps(x, y) std::fixed << std::setprecision(y) << x
#define setbits(x) __builtin_popcountll(x)
#define zerobits(x) __builtin_ctzll(x)
#define mod_add(a, b) ((((a % MOD) + (b % MOD)) % MOD) + MOD) % MOD
#define mod_sub(a, b) ((((a % MOD) - (b % MOD)) % MOD) + MOD) % MOD
#define mod_mul(a, b) ((((a % MOD) * (b % MOD)) % MOD) + MOD) % MOD

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

//  it must be a complete binary tree, i.e., left child should be filled before the right child
template <typename T, typename __comp = std::less<T>>
class Heap {
 private:
  uint64_t _size;
  vector<T> _data;
  __comp cmp = __comp{};

  uint64_t parent(const uint64_t& i) const { return i >> 1; };
  uint64_t left_child(const uint64_t& i) const { return (i << 1) + 1; };
  uint64_t right_child(const uint64_t& i) const { return (i << 1) + 2; };
  bool node_exists(const uint64_t& i) const { return i < this->_size; };

  //  we always heapify the subtrees, this is different from the create_heap where on insertion, we used to heap up (for n nodes, we have to bubble up with height of log n, so time complexity is O(n log n)) and on deletion we used to heap down
  void heapify(const uint16_t& idx) {  //  heap down implementation
    if (idx >= this->_size) return;

    uint64_t left_idx = left_child(idx);
    uint64_t right_idx = right_child(idx);

    //  first on the leaf nodes
    heapify(left_idx);
    heapify(right_idx);

    if (node_exists(left_idx) && cmp(this->_data[idx], this->_data[left_idx])) {
      swap(this->_data[left_idx], this->_data[idx]);
      heapify(left_idx);
    }

    if (node_exists(right_idx) && cmp(this->_data[idx], this->_data[right_idx])) {
      swap(this->_data[right_idx], this->_data[idx]);
      heapify(right_idx);
    }
  };

 public:
  Heap() : _size(0){};

  bool is_empty() const { return this->_size == 0; };

  uint64_t size() const { return this->_size; };

  T top() const { return this->_data[0]; };

  void push(const T& da) {
    //  making space to insert
    if (this->_size + 1 >= this->_data.size()) this->_data.push_back(-1);

    this->_data[this->_size++] = da;

    this->heapify(0);
  };

  void pop() {
    if (!this->_size) return;

    //  putting the last element at top
    swap(this->_data[0], this->_data[--this->_size]);

    this->_data.pop_back();  //  deleting the node

    this->heapify(0);
  };
};

inline void solve() {
  vl a{1, 2, 3, 5, 7};

  Heap<ll> max_heap;

  fo(i, a.size()) max_heap.push(a[i]);

  // max_heap.pop();

  cout << max_heap.top() << '\n';
}
