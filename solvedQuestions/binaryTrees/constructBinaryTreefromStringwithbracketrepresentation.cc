// pragmas
#pragma GCC optimize("Ofast,fast-math,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

// headers
#ifdef DYSLEVIUM
#include "dyslevium.h"
#else
#include <bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#endif

//  custom functions
class custom_hash {
 public:
  static uint64_t splitmix64(uint64_t x) {
    x += 0x9e3779b97f4a7c15;
    x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
    x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
    return x ^ (x >> 31);
  }

  size_t operator()(uint64_t x) const {
    static const uint64_t FIXED_RANDOM = std::chrono::high_resolution_clock::now().time_since_epoch().count();
    return splitmix64(x + FIXED_RANDOM);
  }
};

std::mt19937_64 RNG(std::chrono::high_resolution_clock::now().time_since_epoch().count());  // generator for shuffle and other generator which require random numbers

//  aliases
using ll = long long;
using ld = long double;
using pl = std::pair<ll, ll>;
using vl = std::vector<ll>;
using vpl = std::vector<pl>;
using mll = __gnu_pbds::gp_hash_table<ll, ll, custom_hash>;

//  constants
constexpr ll INF(2e18);
constexpr ld EPS(1e-9);
constexpr ll MOD(1e9 + 7);  //  998244853
constexpr ld PI(3.14159265358979323846);

// clang-format off

template <typename T> constexpr T mod_add(T a, T b) { return ((((a % MOD) + (b % MOD)) % MOD) + MOD) % MOD; }
template <typename T> constexpr T mod_sub(T a, T b) { return ((((a % MOD) - (b % MOD)) % MOD) + MOD) % MOD; }
template <typename T> constexpr T mod_mul(T a, T b) { return ((((a % MOD) * (b % MOD)) % MOD) + MOD) % MOD; };

//  macros
#define pb push_back
#define F first
#define S second
#define fo(i, n) for (ll i = 0; i < (ll)n; ++i)
#define Fo(i, k, n) for (ll i = k; k < (ll)n ? i < (ll)n : i > (ll)n; k < (ll)n ? ++i : --i)
#define all(x) x.begin(), x.end()
#define tr(it, a) for (auto& it : a)
#define ps(x, y) std::fixed << std::setprecision(y) << x
#define set_bits(x) __builtin_popcountll(x)
#define zero_bits(x) __builtin_ctzll(x)

// template functions
template <typename T> using ordered_set = __gnu_pbds::tree<T, __gnu_pbds::null_type, std::less<T>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update>;  // find_by_order, order_of_key
template <typename T> inline T bin_pow(T x, T n) {T res = 1; while (n) { if (n & 1) res *= x; x *= x; n >>= 1; } return res; }
template <typename T> inline T bin_pow_m(T x, T n) {T res = 1; while (n) { if (n & 1) res = modMul(res, x); x = modMul(x, x); n >>= 1; }return res % MOD; }
template <typename T> inline T mod_inverse(const T& a) { return binPowIter(a, MOD - 2); }
template <typename T> inline T mod_div(const T& a, const T& b) { return (modMul(a, modInverse(b)) + MOD) % MOD; }

//  operator overloading
template<typename T> std::istream& operator>>(std::istream &istream, std::vector<T> &v){ for (auto &it : v) std::cin >> it; return istream; }
template<typename T> std::ostream& operator<<(std::ostream &ostream, const std::vector<T> &v) { for (auto &it : v) std::cout << it << ' '; return ostream; }

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
  std::cin >> t;

  while (t--) {
    solve();
    #ifdef DYSLEVIUM
      std::cout << "\n----------\n" ;
    #endif
  }

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

class Node {
 public:
  ll data;
  Node *left, *right;

  Node(ll val) : data(val), left(nullptr), right(nullptr){};
};

inline void solve() {
  string s = "4(2(3)(1))(6(5))";

  auto build_tree = [](const auto& build_tree, const string& te) -> Node* {
    //  only one node left
    if (te.length() == 1) return new Node(te[0] - '0');

    Node* root = new Node(te[0] - '0');

    string new_str = te.substr(2);  //  removing the root and the first open bracket

    stack<char> st;
    st.push('(');  //  inserting the first '('

    string left_str = "";
    bool ok = false;
    ll i = 0;
    while (1) {
      left_str += new_str[i];
      if (new_str[i] == ')') {
        while (st.top() != '(') {
          st.pop();
        }
        st.pop();

        if (st.empty()) ok = true;
      } else
        st.push(new_str[i]);

      if (ok) break;

      ++i;
    }
    left_str.pop_back();  //  removing the last open bracket

    string right_str = "";
    if (i + 2 < new_str.length()) {  //  checking if there is a right subtree
      right_str = new_str.substr(i + 2);
      right_str.pop_back();
    }

    if (left_str.length() > 0) root->left = build_tree(build_tree, left_str);     //  if left subtree exists (it always does, as we are filling the nodes in complete binary tree way)
    if (right_str.length() > 0) root->right = build_tree(build_tree, right_str);  //  if left subtree exists

    return root;
  };

  Node* root = build_tree(build_tree, s);

  auto in_order = [](const auto& in_order, const Node* const node) {
    if (!node) return;

    in_order(in_order, node->left);
    cout << node->data << ' ';
    in_order(in_order, node->right);
  };

  in_order(in_order, root);
}