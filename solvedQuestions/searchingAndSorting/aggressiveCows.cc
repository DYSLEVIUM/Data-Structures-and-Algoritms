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
constexpr ll MOD(1e9 + 7);  //  or (119 << 23) + 1; primitive_root = 3; // = 998244353
constexpr ld PI(3.14159265358979323846);

// clang-format off

template <typename T> constexpr T mod_add(const T& a, const T&  b, const T& mod) { return a + b > mod ? a + b - mod : (a + b); }
template <typename T> constexpr T mod_sub(const T& a, const T&  b, const T& mod) { return a - b < 0 ? a - b + mod : (a - b); }
template <typename T> constexpr T mod_mul(const T& a, const T&  b, const T& mod) { return ((((a % mod) * (b % mod)) % mod) + mod) % mod; };

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
template <typename T> inline T bin_pow_m(T x, T n, const T& mod) {T res = 1; while (n) { if (n & 1) res = mod_mul(res, x, mod); x = mod_mul(x, x, mod); n >>= 1; } return res % mod; }
template <typename T> inline T mod_inverse(const T& a, const T& mod) { return bin_pow_m(a, mod - 2, mod); }
template <typename T> inline T mod_div(const T& a, const T& b, const T& mod) { return (mod_mul(a, mod_inverse(b, mod), mod) + mod) % mod; }

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
      std::cout << "----------\n" ;
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

// Compile and run: g++ -std=c++20 -g -Wshadow -Wall main.cc -D DYSLEVIUM -o a.exe -Ofast -Wno-unused-result && ./a.exe

// clang-format on

inline void solve() {
  ll n, c;
  cin >> n >> c;

  vl barn(n);
  cin >> barn;

  sort(all(barn));

  auto is_possible = [&n, &c, &barn](const ll& x) {
    ll prev = barn[0];
    ll te_c = c - 1;

    Fo(i, 1, n) {
      if (barn[i] - prev >= x) {
        prev = barn[i];
        --te_c;
      }
    }

    return te_c <= 0;
  };

  ll lo = 1, hi = 1e9;
  ll ans = 1;
  while (lo <= hi) {
    ll mid = lo + (hi - lo) / 2;

    if (is_possible(mid)) {
      ans = mid;
      lo = mid + 1;
    } else
      hi = mid - 1;
  }

  cout << ans << '\n';
}
